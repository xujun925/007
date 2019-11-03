/****************************************************************************
 * examples/mld/mld_main.c
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
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

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <debug.h>

#include <arpa/inet.h>
#include <net/if.h>
#include <net/route.h>
#include <netinet/in.h>

#include "netutils/netlib.h"

#include "mld.h"

/****************************************************************************
 * Preprocessor Definitions
 ****************************************************************************/

/* Size of allocated I/O buffer for dumping /proc/net/mld */

#define IOBUFFERSIZE      512

/* procfs paths */

#define PROCFS_MLD_PATH   "/proc/net/mld"
#define PROCFS_ROUTE_PATH "/proc/net/route/ipv6"

#if !defined(CONFIG_DISABLE_MOUNTPOINT) && defined(CONFIG_FS_PROCFS) && \
    !defined(CONFIG_FS_PROCFS_EXCLUDE_NET)

#  ifdef CONFIG_NET_STATISTICS
#    define HAVE_PROC_NET_STATS
#  endif

#  ifdef CONFIG_NET_ROUTE
#    define HAVE_PROC_NET_ROUTE
#  endif
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

#ifdef CONFIG_EXAMPLES_MLD_INIT
static const uint16_t g_host_addr[8] =
{
  HTONS(0xfe80),
  HTONS(0),
  HTONS(0),
  HTONS(0),
  HTONS(0),
  HTONS(0x00ff),
  HTONS(0xfe00),
  HTONS(CONFIG_EXAMPLES_MLD_IPADDR)
};

static const uint16_t g_dr_addr[8] =
{
  HTONS(0xfe80),
  HTONS(0),
  HTONS(0),
  HTONS(0),
  HTONS(0),
  HTONS(0x00ff),
  HTONS(0xfe00),
  HTONS(CONFIG_EXAMPLES_MLD_DRIPADDR)
};

static const uint16_t g_netmask[8] =
{
  HTONS(0xfffff),
  HTONS(0xfffff),
  HTONS(0xfffff),
  HTONS(0xfffff),
  HTONS(0xfffff),
  HTONS(0xfffff),
  HTONS(0xfffff),
  HTONS(0)
};
#endif

static const uint16_t g_grp_addr[8] =
{
  HTONS(0xff02),
  HTONS(0),
  HTONS(0),
  HTONS(0),
  HTONS(0),
  HTONS(0),
  HTONS(0),
  HTONS(CONFIG_EXAMPLES_MLD_GRPADDR)
};

#ifdef CONFIG_NET_ROUTE
static const uint8_t g_garbage[] = "abcdefghijklmnopqrstuvwxyz"
                                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mld_catfile
 *
 * Description:
 *   Dump the contents of a file to the current NSH terminal.
 *
 * Input Paratemets:
 *   filepath - The path to the file to dump
 *   iobuffer - An I/O buffer to use for the data transfer
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

#if defined(HAVE_PROC_NET_STATS) || defined(HAVE_PROC_NET_ROUTE)
void mld_catfile(FAR const char *filepath, FAR char **iobuffer)
{
  int fd;

  /* Open the file for reading.
   * REVISIT: Assume procfs is mounted at /proc
   */

  fd = open(filepath, O_RDONLY);
  if (fd < 0)
    {
      fprintf(stderr, "Failed to open %s:  %d\n", filepath, errno);
      return;
    }

  if (*iobuffer == NULL)
    {
      *iobuffer = (FAR char *)malloc(IOBUFFERSIZE);
      if (*iobuffer == NULL)
        {
          (void)close(fd);
          fprintf(stderr, "Failed to allocation I/O buffer\n");
          return;
        }
    }

  /* And just dump it byte for byte into stdout */

  for (;;)
    {
      ssize_t nbytesread = read(fd, *iobuffer, IOBUFFERSIZE);

      /* Check for read errors */

      if (nbytesread < 0)
        {
          int errval = errno;

          if (errval == EINTR)
            {
              continue;
            }

          fprintf(stderr, "Read from %s failed:  %d\n", filepath, errval);
          return;
        }

      /* Check for data successfully read */

      else if (nbytesread > 0)
        {
          int nbyteswritten = 0;

          while (nbyteswritten < nbytesread)
            {
              ssize_t n = write(1, *iobuffer, nbytesread);
              if (n < 0)
                {
                  int errval = errno;

                  if (errval == EINTR)
                    {
                      continue;
                    }

                  fprintf(stderr, "Write to stdout failed:  %d\n", errval);
                  return;
                }
              else
                {
                  nbyteswritten += n;
                }
            }
        }

      /* Otherwise, it is the end of file */

      else
        {
          break;
        }
    }

  (void)close(fd);
}
#endif

#ifdef HAVE_PROC_NET_STATS
#  define mld_dumpstats(iobuffer) mld_catfile(PROCFS_MLD_PATH, iobuffer)
#else
#  define mld_dumpstats(iobuffer) mld_catfile(PROCFS_MLD_PATH, iobuffer)
#endif

#ifdef HAVE_PROC_NET_ROUTE
#  define mld_dumproute(iobuffer) mld_catfile(PROCFS_ROUTE_PATH, iobuffer)
#else
#  define mld_dumproute(iobuffer)
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * mld_main
 ****************************************************************************/

#ifdef BUILD_MODULE
int main(int argc, FAR char *argv[])
#else
int mld_main(int argc, char *argv[])
#endif
{
  FAR char *iobuffer = NULL;
  struct sockaddr_in6 host;
#ifdef CONFIG_NET_ROUTE
  struct sockaddr_in6 target;
  struct sockaddr_in6 router;
  struct sockaddr_in6 netmask;
#endif
  struct ipv6_mreq mrec;
  int nsec;
  int sockfd;
  int ret;

#ifdef CONFIG_EXAMPLES_MLD_INIT
#ifdef CONFIG_EXAMPLES_MLD_NOMAC
  uint8_t mac[IFHWADDRLEN];
#endif

  printf("Configuring Ethernet...\n");

#ifdef CONFIG_EXAMPLES_MLD_NOMAC
  /* Many embedded network interfaces must have a software assigned MAC */

  mac[0] = 0x00;
  mac[1] = 0xe0;
  mac[2] = 0xde;
  mac[3] = 0xad;
  mac[4] = 0xbe;
  mac[5] = 0xef;
  netlib_setmacaddr("eth0", mac);
#endif

  /* Set up our (fixed) host address */

  netlib_set_ipv6addr("eth0", (FAR const struct in6_addr *)g_host_addr);

  /* Set up the default router address */

  netlib_set_dripv6addr("eth0", (FAR const struct in6_addr *)g_dr_addr);

  /* Setup the subnet mask */

  netlib_set_ipv6netmask("eth0", (FAR const struct in6_addr *)g_netmask);

  /* Bring the network up */

  netlib_ifup("eth0");
#endif /* CONFIG_EXAMPLES_MLD_INIT */

  memset(&host, 0, sizeof(struct sockaddr_in6));
  host.sin6_family  = AF_INET6;
  sockfd            = socket(PF_INET6, SOCK_DGRAM, 0);
  if (sockfd < 0)
    {
      fprintf(stderr, "ERROR: socket() failed: %d\n", errno);
      return EXIT_FAILURE;
    }

  /* Join the group */

  printf("Join group...\n");
  mld_dumpstats(&iobuffer);

  memcpy(mrec.ipv6mr_multiaddr.s6_addr16, g_grp_addr, sizeof(struct in6_addr));
  mrec.ipv6mr_interface = if_nametoindex("eth0");

  ret = setsockopt(sockfd, SOL_IPV6, IPV6_JOIN_GROUP, (FAR void *)&mrec,
                   sizeof(struct ipv6_mreq));
  if (ret < 0)
    {
      fprintf(stderr, "ERROR: setsockopt() failed: %d\n", errno);
      ret = EXIT_FAILURE;
      goto errout_with_socket;
    }

  /* Wait a while.  Here is assume you are monitoring the network traffic
   * with a tool like WireShark.  This is what you should expect after the
   * join (assuming default values for MLD delay and count settings):
   *
   * 1. A outgoing Report message immediately upon joining.
   * 2. Another Report message after a delay of 1 second
   * 3. Thereafter, periodic Query messages separated by delays of
   *    125 seconds
   *
   * So the following delay is set so that we can verify all of the possible
   * timed events.
   */

  printf("Waiting 300 seconds...\n");
  mld_dumpstats(&iobuffer);

  for (nsec = 0; nsec < 300; nsec += 10)
    {
      sleep(10);
      printf("\nElapsed: %d sec\n", nsec + 10);
      mld_dumpstats(&iobuffer);
    }

#ifdef CONFIG_NET_ROUTE
  printf("\nSet up route for the multicast address...\n");
  mld_dumproute(&iobuffer);

  /* Set up a routing table entry for the address of the multicast group */

  memset(&target, 0, sizeof(struct sockaddr_in6));
  target.sin6_family  = AF_INET6;
  target.sin6_port    = HTONS(0x4321);
  memcpy(target.sin6_addr.s6_addr16, g_grp_addr, sizeof(struct in6_addr));

  memset(&netmask, 0, sizeof(struct sockaddr_in6));
  netmask.sin6_family  = AF_INET6;
  netmask.sin6_port    = HTONS(0x4321);
  memset(netmask.sin6_addr.s6_addr16, 0xff, sizeof(struct in6_addr));

  memset(&router, 0, sizeof(struct sockaddr_in6));
  router.sin6_family  = AF_INET6;
  router.sin6_port    = HTONS(0x4321);

  ret = netlib_get_ipv6addr("eth0", &router.sin6_addr);
  if (ret < 0)
    {
      fprintf(stderr, "ERROR: netlib_get_ipv6addr() failed: %d\n", ret);
    }
  else
    {
      ret = addroute(sockfd,
                     (FAR struct sockaddr_storage *)&target,
                     (FAR struct sockaddr_storage *)&netmask,
                     (FAR struct sockaddr_storage *)&router);
      if (ret < 0)
        {
          fprintf(stderr, "ERROR: addroute() failed: %d\n", errno);
        }
    }

  mld_dumproute(&iobuffer);

  if (ret >= 0)
    {
      /* Send a garbage packet */

      ret = sendto(sockfd, g_garbage, sizeof(g_garbage), 0,
                   (FAR struct sockaddr *)&target, sizeof(struct sockaddr_in6));
      if (ret < 0)
        {
          fprintf(stderr, "ERROR: sendto() failed: %d\n", errno);
        }
    }

  ret = delroute(sockfd,
                 (FAR struct sockaddr_storage *)&target,
                 (FAR struct sockaddr_storage *)&netmask);
  if (ret < 0)
    {
      fprintf(stderr, "ERROR: delroute() failed: %d\n", errno);
    }

  mld_dumproute(&iobuffer);

  /* Wait a while */

  printf("Wait a bit...\n");
  sleep(5);
  mld_dumpstats(&iobuffer);
#endif

  /* Leave the group */

  printf("Leave group...\n");
  ret = setsockopt(sockfd, SOL_IPV6, IPV6_LEAVE_GROUP, (FAR void *)&mrec,
                   sizeof(struct ipv6_mreq));
  if (ret < 0)
    {
      fprintf(stderr, "ERROR: setsockopt() failed: %d\n", errno);
      ret = EXIT_FAILURE;
      goto errout_with_socket;
    }

  /* Wait a while.  Here we should see a Done message sent immediately
   * when leaving the group.
   */

  mld_dumpstats(&iobuffer);
  printf("Wait a bit...\n");
  sleep(5);

  mld_dumpstats(&iobuffer);
  printf("Exiting...\n");
  ret = EXIT_SUCCESS;

errout_with_socket:
  close(sockfd);
  if (iobuffer != NULL)
    {
      free(iobuffer);
    }

  return ret;
}
