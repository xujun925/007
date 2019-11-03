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

/* Auto-generated by genmsg_cpp from file vehicle_attitude_setpoint.msg */


#include <inttypes.h>
#include <px4_log.h>
#include <px4_defines.h>
#include <uORB/topics/vehicle_attitude_setpoint.h>
#include <drivers/drv_hrt.h>
#include <lib/drivers/device/Device.hpp>

constexpr char __orb_vehicle_attitude_setpoint_fields[] = "uint64_t timestamp;float roll_body;float pitch_body;float yaw_body;float yaw_sp_move_rate;float[4] q_d;float[3] thrust_body;bool q_d_valid;bool roll_reset_integral;bool pitch_reset_integral;bool yaw_reset_integral;bool fw_control_yaw;uint8_t apply_flaps;uint8_t[6] _padding0;";

ORB_DEFINE(vehicle_attitude_setpoint, struct vehicle_attitude_setpoint_s, 58, __orb_vehicle_attitude_setpoint_fields);
ORB_DEFINE(mc_virtual_attitude_setpoint, struct vehicle_attitude_setpoint_s, 58, __orb_vehicle_attitude_setpoint_fields);
ORB_DEFINE(fw_virtual_attitude_setpoint, struct vehicle_attitude_setpoint_s, 58, __orb_vehicle_attitude_setpoint_fields);


void print_message(const vehicle_attitude_setpoint_s& message)
{

	PX4_INFO_RAW(" vehicle_attitude_setpoint_s\n");
	if (message.timestamp != 0) {
		PX4_INFO_RAW("\ttimestamp: %" PRIu64 "  (%.6f seconds ago)\n", message.timestamp, hrt_elapsed_time(&message.timestamp) / 1e6);
	} else {
		PX4_INFO_RAW("\n");
	}
	PX4_INFO_RAW("\troll_body: %.4f\n", (double)message.roll_body);
	PX4_INFO_RAW("\tpitch_body: %.4f\n", (double)message.pitch_body);
	PX4_INFO_RAW("\tyaw_body: %.4f\n", (double)message.yaw_body);
	PX4_INFO_RAW("\tyaw_sp_move_rate: %.4f\n", (double)message.yaw_sp_move_rate);
	PX4_INFO_RAW("\tq_d: [%.4f, %.4f, %.4f, %.4f]\n", (double)message.q_d[0], (double)message.q_d[1], (double)message.q_d[2], (double)message.q_d[3]);
	PX4_INFO_RAW("\tthrust_body: [%.4f, %.4f, %.4f]\n", (double)message.thrust_body[0], (double)message.thrust_body[1], (double)message.thrust_body[2]);
	PX4_INFO_RAW("\tq_d_valid: %s\n", (message.q_d_valid ? "True" : "False"));
	PX4_INFO_RAW("\troll_reset_integral: %s\n", (message.roll_reset_integral ? "True" : "False"));
	PX4_INFO_RAW("\tpitch_reset_integral: %s\n", (message.pitch_reset_integral ? "True" : "False"));
	PX4_INFO_RAW("\tyaw_reset_integral: %s\n", (message.yaw_reset_integral ? "True" : "False"));
	PX4_INFO_RAW("\tfw_control_yaw: %s\n", (message.fw_control_yaw ? "True" : "False"));
	PX4_INFO_RAW("\tapply_flaps: %u\n", message.apply_flaps);
	
}
