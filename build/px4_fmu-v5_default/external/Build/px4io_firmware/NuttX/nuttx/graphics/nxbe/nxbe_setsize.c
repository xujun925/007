/****************************************************************************
 * graphics/nxbe/nxbe_setsize.c
 *
 *   Copyright (C) 2008-2009, 2011, 2019 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <assert.h>

#ifdef CONFIG_NX_RAMBACKED
#  include <debug.h>
#  include <string.h>
#ifdef CONFIG_BUILD_KERNEL
#  include <nuttx/pgalloc.h>
#else
#  include <nuttx/kmalloc.h>
#endif
#endif

#include <nuttx/nx/nxglib.h>

#include "nxbe.h"
#include "nxmu.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifndef MIN
#  define MIN(a,b) ((a < b) ? a : b)
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: nxbe_realloc
 *
 * Description:
 *   After the display size has changed, reallocate the pre-window frame
 *   buffer for the new framebuffer size.
 *
 *   REVISIT:  This currently takes a brute force force approach, allocating
 *   the new framebuffer while the old framebuffer is still in place.  There
 *   may be some clever way to do this reallocation in place.
 *
 ****************************************************************************/

#ifdef CONFIG_NX_RAMBACKED
static void nxbe_realloc(FAR struct nxbe_window_s *wnd,
                         FAR struct nxgl_rect_s *oldbounds)
{
  FAR nxgl_mxpixel_t *newfb;
  FAR uint8_t *src;
  FAR uint8_t *dest;
  nxgl_coord_t minheight;
  nxgl_coord_t newwidth;
  nxgl_coord_t newheight;
  nxgl_coord_t oldheight;
  nxgl_coord_t row;
  size_t newfbsize;
  unsigned int minstride;
  unsigned int newstride;
  unsigned int bpp;
#ifdef CONFIG_BUILD_KERNEL
  unsigned int newnpages;
#endif

  /* Allocate framebuffer memory if the per-window framebuffer feature has
   * been selected.
   *
   * REVISIT:  This initial state of the framebuffer is uninitialized and
   * not synchronized with the graphic device content.  It will take a full
   * screen update from the application to force the framebuffer and device
   * to be consistent.
   */

  if (NXBE_ISRAMBACKED(wnd))
    {
      oldheight       = oldbounds->pt2.y - oldbounds->pt1.y + 1;

      newwidth        = wnd->bounds.pt2.x - wnd->bounds.pt1.x + 1;
      newheight       = wnd->bounds.pt2.y - wnd->bounds.pt1.y + 1;
      bpp             = wnd->be->plane[0].pinfo.bpp;
      newstride       = (bpp * newwidth + 7) >> 3;
      newfbsize       = newstride * newheight;

#ifdef CONFIG_BUILD_KERNEL
      /* Re-allocate memory from the page pool. */

      /* Determine the number of pages to be allocated. */

      newnpages = (uint16_t)MM_NPAGES(newfbsize);

      /* Allocate the pages */

      newfb = (FAR nxgl_mxpixel_t *)mm_pgalloc(newnpages);
      if (newfb == NULL)
        {
          /* Fall back to no RAM back up */

          gerr("ERROR: mm_pgalloc() failed for fbsize=%lu, npages=%u\n",
               (unsigned long)newfbsize, npages);

          mm_pgfree(wnd->fbmem, wnd->npages);
          wnd->stride = 0;
          wnd->npages = 0;
          wnd->fbmem  = NULL;
          NXBE_CLRRAMBACKED(wnd);
          return;
        }
#else
      /* Re-allocate memory from the user space heap. */

      newfb = (FAR nxgl_mxpixel_t *)kumm_malloc(newfbsize);
      if (newfb == NULL)
        {
          /* Fall back to no RAM back up */

          gerr("ERROR: kumm_malloc() failed for fbsize=%lu\n",
               (unsigned long)newfbsize);

          kumm_free(wnd->fbmem);
          wnd->stride = 0;
          wnd->fbmem  = NULL;
          NXBE_CLRRAMBACKED(wnd);
          return;
        }
#endif

      /* Copy the content of the old framebuffer to the new frame buffer */

      minheight = MIN(oldheight, newheight);
      minstride = MIN(wnd->stride, newstride);

      /* Process each line one at a time */

      for (src  = (FAR uint8_t *)wnd->fbmem, dest = (FAR uint8_t *)newfb,
           row = 0;
           row < minheight;
           src += wnd->stride, dest += newstride, row++)
        {
          /* Copy valid row data */

          memcpy(dest, src, minstride);

          /* Pad any extra pixel data on the right (with zeroes?) */

          if (minstride < newstride)
            {
              memset(dest + minstride, 0, newstride - minstride);
            }
        }

      /* Pad any extra lines at the bottom (with zeroes?) */

      if (row < newheight)
        {
          size_t nbytes = newstride * (newheight - row);
          memset(dest, 0, nbytes);
        }

      /* Free the old framebuffer and configure for the new framebuffer */

#ifdef CONFIG_BUILD_KERNEL
      mm_pgfree(wnd->fbmem, wnd->npages);
      wnd->npages = newnpages;
#else
      kumm_free(wnd->fbmem);
#endif
      wnd->stride = newstride;
      wnd->fbmem  = newfb;
    }
}
#else
#  define nxbe_realloc(w,b)
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: nxbe_setsize
 *
 * Description:
 *   This function checks for intersections and redraws the display after
 *   a change in the size of a window.
 *
 ****************************************************************************/

void nxbe_setsize(FAR struct nxbe_window_s *wnd,
                  FAR const struct nxgl_size_s *size)
{
  struct nxgl_rect_s bounds;

  DEBUGASSERT(wnd != NULL && size != NULL);

  /* Save the 'before' size of the window's bounding box */

  nxgl_rectcopy(&bounds, &wnd->bounds);

  /* Add the window origin to the supplied size get the new window bounding
   * box
   */

  wnd->bounds.pt2.x = wnd->bounds.pt1.x + size->w - 1;
  wnd->bounds.pt2.y = wnd->bounds.pt1.y + size->h - 1;

  /* Clip the new bounding box so that lies within the background screen */

  nxgl_rectintersect(&wnd->bounds, &wnd->bounds, &wnd->be->bkgd.bounds);

  /* Re-allocate the per-window framebuffer memory for the new window size. */

  nxbe_realloc(wnd, &bounds);

  /* We need to update the larger of the two regions described by the
   * original bounding box and the new bounding box.   That will be the
   * union of the two bounding boxes.
   */

  nxgl_rectunion(&bounds, &bounds, &wnd->bounds);

  /* Report the new size/position */

  nxmu_reportposition(wnd);

  /* Then redraw this window AND all windows below it. Having resized the
   * window, we may have exposed previoulsy obscured portions of windows
   * below this one.
   */

  nxbe_redrawbelow(wnd->be, wnd, &bounds);
}