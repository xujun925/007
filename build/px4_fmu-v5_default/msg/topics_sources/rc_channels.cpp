/****************************************************************************
 *
 *   Copyright (C) 2013-2016 PX4 Development Team. All rights reserved.
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
 * 3. Neither the name PX4 nor the names of its contributors may be
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

/* Auto-generated by genmsg_cpp from file rc_channels.msg */


#include <inttypes.h>
#include <px4_log.h>
#include <px4_defines.h>
#include <uORB/topics/rc_channels.h>
#include <drivers/drv_hrt.h>
#include <lib/drivers/device/Device.hpp>

constexpr char __orb_rc_channels_fields[] = "uint64_t timestamp;uint64_t timestamp_last_valid;float[18] channels;uint32_t frame_drop_count;uint8_t channel_count;int8_t[27] function;uint8_t rssi;bool signal_lost;uint8_t[6] _padding0;";

ORB_DEFINE(rc_channels, struct rc_channels_s, 122, __orb_rc_channels_fields);


void print_message(const rc_channels_s& message)
{

	PX4_INFO_RAW(" rc_channels_s\n");
	if (message.timestamp != 0) {
		PX4_INFO_RAW("\ttimestamp: %" PRIu64 "  (%.6f seconds ago)\n", message.timestamp, hrt_elapsed_time(&message.timestamp) / 1e6);
	} else {
		PX4_INFO_RAW("\n");
	}
	PX4_INFO_RAW("\ttimestamp_last_valid: %" PRIu64 "\n", message.timestamp_last_valid);
	PX4_INFO_RAW("\tchannels: [%.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f]\n", (double)message.channels[0], (double)message.channels[1], (double)message.channels[2], (double)message.channels[3], (double)message.channels[4], (double)message.channels[5], (double)message.channels[6], (double)message.channels[7], (double)message.channels[8], (double)message.channels[9], (double)message.channels[10], (double)message.channels[11], (double)message.channels[12], (double)message.channels[13], (double)message.channels[14], (double)message.channels[15], (double)message.channels[16], (double)message.channels[17]);
	PX4_INFO_RAW("\tframe_drop_count: %" PRIu32 "\n", message.frame_drop_count);
	PX4_INFO_RAW("\tchannel_count: %u\n", message.channel_count);
	PX4_INFO_RAW("\tfunction: [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", message.function[0], message.function[1], message.function[2], message.function[3], message.function[4], message.function[5], message.function[6], message.function[7], message.function[8], message.function[9], message.function[10], message.function[11], message.function[12], message.function[13], message.function[14], message.function[15], message.function[16], message.function[17], message.function[18], message.function[19], message.function[20], message.function[21], message.function[22], message.function[23], message.function[24], message.function[25], message.function[26]);
	PX4_INFO_RAW("\trssi: %u\n", message.rssi);
	PX4_INFO_RAW("\tsignal_lost: %s\n", (message.signal_lost ? "True" : "False"));
	
}
