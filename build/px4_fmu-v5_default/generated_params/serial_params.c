


/**
 * Baudrate for the GPS 1 Serial Port
 *
 * Configure the Baudrate for the GPS 1 Serial Port.
 *
 * Note: certain drivers such as the GPS can determine the Baudrate automatically.
 *
 * @value 0 Auto
 * @value 50 50 8N1
 * @value 75 75 8N1
 * @value 110 110 8N1
 * @value 134 134 8N1
 * @value 150 150 8N1
 * @value 200 200 8N1
 * @value 300 300 8N1
 * @value 600 600 8N1
 * @value 1200 1200 8N1
 * @value 1800 1800 8N1
 * @value 2400 2400 8N1
 * @value 4800 4800 8N1
 * @value 9600 9600 8N1
 * @value 19200 19200 8N1
 * @value 38400 38400 8N1
 * @value 57600 57600 8N1
 * @value 115200 115200 8N1
 * @value 230400 230400 8N1
 * @value 460800 460800 8N1
 * @value 500000 500000 8N1
 * @value 921600 921600 8N1
 * @value 1000000 1000000 8N1
 * @value 1500000 1500000 8N1
 * @value 2000000 2000000 8N1
 * @value 3000000 3000000 8N1
 * @group Serial
 * @reboot_required true
 */
PARAM_DEFINE_INT32(SER_GPS1_BAUD, 0);

/**
 * Baudrate for the TELEM 1 Serial Port
 *
 * Configure the Baudrate for the TELEM 1 Serial Port.
 *
 * Note: certain drivers such as the GPS can determine the Baudrate automatically.
 *
 * @value 0 Auto
 * @value 50 50 8N1
 * @value 75 75 8N1
 * @value 110 110 8N1
 * @value 134 134 8N1
 * @value 150 150 8N1
 * @value 200 200 8N1
 * @value 300 300 8N1
 * @value 600 600 8N1
 * @value 1200 1200 8N1
 * @value 1800 1800 8N1
 * @value 2400 2400 8N1
 * @value 4800 4800 8N1
 * @value 9600 9600 8N1
 * @value 19200 19200 8N1
 * @value 38400 38400 8N1
 * @value 57600 57600 8N1
 * @value 115200 115200 8N1
 * @value 230400 230400 8N1
 * @value 460800 460800 8N1
 * @value 500000 500000 8N1
 * @value 921600 921600 8N1
 * @value 1000000 1000000 8N1
 * @value 1500000 1500000 8N1
 * @value 2000000 2000000 8N1
 * @value 3000000 3000000 8N1
 * @group Serial
 * @reboot_required true
 */
PARAM_DEFINE_INT32(SER_TEL1_BAUD, 57600);

/**
 * Baudrate for the TELEM 2 Serial Port
 *
 * Configure the Baudrate for the TELEM 2 Serial Port.
 *
 * Note: certain drivers such as the GPS can determine the Baudrate automatically.
 *
 * @value 0 Auto
 * @value 50 50 8N1
 * @value 75 75 8N1
 * @value 110 110 8N1
 * @value 134 134 8N1
 * @value 150 150 8N1
 * @value 200 200 8N1
 * @value 300 300 8N1
 * @value 600 600 8N1
 * @value 1200 1200 8N1
 * @value 1800 1800 8N1
 * @value 2400 2400 8N1
 * @value 4800 4800 8N1
 * @value 9600 9600 8N1
 * @value 19200 19200 8N1
 * @value 38400 38400 8N1
 * @value 57600 57600 8N1
 * @value 115200 115200 8N1
 * @value 230400 230400 8N1
 * @value 460800 460800 8N1
 * @value 500000 500000 8N1
 * @value 921600 921600 8N1
 * @value 1000000 1000000 8N1
 * @value 1500000 1500000 8N1
 * @value 2000000 2000000 8N1
 * @value 3000000 3000000 8N1
 * @group Serial
 * @reboot_required true
 */
PARAM_DEFINE_INT32(SER_TEL2_BAUD, 921600);

/**
 * Baudrate for the TELEM/SERIAL 4 Serial Port
 *
 * Configure the Baudrate for the TELEM/SERIAL 4 Serial Port.
 *
 * Note: certain drivers such as the GPS can determine the Baudrate automatically.
 *
 * @value 0 Auto
 * @value 50 50 8N1
 * @value 75 75 8N1
 * @value 110 110 8N1
 * @value 134 134 8N1
 * @value 150 150 8N1
 * @value 200 200 8N1
 * @value 300 300 8N1
 * @value 600 600 8N1
 * @value 1200 1200 8N1
 * @value 1800 1800 8N1
 * @value 2400 2400 8N1
 * @value 4800 4800 8N1
 * @value 9600 9600 8N1
 * @value 19200 19200 8N1
 * @value 38400 38400 8N1
 * @value 57600 57600 8N1
 * @value 115200 115200 8N1
 * @value 230400 230400 8N1
 * @value 460800 460800 8N1
 * @value 500000 500000 8N1
 * @value 921600 921600 8N1
 * @value 1000000 1000000 8N1
 * @value 1500000 1500000 8N1
 * @value 2000000 2000000 8N1
 * @value 3000000 3000000 8N1
 * @group Serial
 * @reboot_required true
 */
PARAM_DEFINE_INT32(SER_TEL4_BAUD, 57600);


/**
 * Serial Configuration for Lanbao PSK-CM8JL65-CC5
 *
 * Configure on which serial port to run Lanbao PSK-CM8JL65-CC5.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group Sensors
 * @reboot_required true
 */
PARAM_DEFINE_INT32(SENS_CM8JL65_CFG, 0);

/**
 * Serial Configuration for LeddarOne Rangefinder
 *
 * Configure on which serial port to run LeddarOne Rangefinder.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group Sensors
 * @reboot_required true
 */
PARAM_DEFINE_INT32(SENS_LEDDAR1_CFG, 0);

/**
 * Serial Configuration for Lightware Laser Rangefinder
 *
 * Configure on which serial port to run Lightware Laser Rangefinder.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group Sensors
 * @reboot_required true
 */
PARAM_DEFINE_INT32(SENS_SF0X_CFG, 0);

/**
 * Serial Configuration for Benewake TFmini Rangefinder
 *
 * Configure on which serial port to run Benewake TFmini Rangefinder.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group Sensors
 * @reboot_required true
 */
PARAM_DEFINE_INT32(SENS_TFMINI_CFG, 0);

/**
 * Serial Configuration for uLanding Radar
 *
 * Configure on which serial port to run uLanding Radar.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group Sensors
 * @reboot_required true
 */
PARAM_DEFINE_INT32(SENS_ULAND_CFG, 0);

/**
 * Serial Configuration for DShot Driver
 *
 * Configure on which serial port to run DShot Driver.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group DShot
 * @reboot_required true
 */
PARAM_DEFINE_INT32(DSHOT_TEL_CFG, 0);

/**
 * Serial Configuration for Secondary GPS
 *
 * Configure on which serial port to run Secondary GPS.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group GPS
 * @reboot_required true
 */
PARAM_DEFINE_INT32(GPS_2_CONFIG, 0);

/**
 * Serial Configuration for Main GPS
 *
 * Configure on which serial port to run Main GPS.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group GPS
 * @reboot_required true
 */
PARAM_DEFINE_INT32(GPS_1_CONFIG, 201);

/**
 * Serial Configuration for Roboclaw Driver
 *
 * Configure on which serial port to run Roboclaw Driver.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group Roboclaw
 * @reboot_required true
 */
PARAM_DEFINE_INT32(RBCLW_SER_CFG, 0);

/**
 * Serial Configuration for FrSky Telemetry
 *
 * Configure on which serial port to run FrSky Telemetry.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group Telemetry
 * @reboot_required true
 */
PARAM_DEFINE_INT32(TEL_FRSKY_CONFIG, 0);

/**
 * Serial Configuration for HoTT Telemetry
 *
 * Configure on which serial port to run HoTT Telemetry.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group Telemetry
 * @reboot_required true
 */
PARAM_DEFINE_INT32(TEL_HOTT_CONFIG, 0);

/**
 * Serial Configuration for Iridium (with MAVLink)
 *
 * Configure on which serial port to run Iridium (with MAVLink).
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group Iridium SBD
 * @reboot_required true
 */
PARAM_DEFINE_INT32(ISBD_CONFIG, 0);

/**
 * Serial Configuration for MAVLink (instance 0)
 *
 * Configure on which serial port to run MAVLink.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group MAVLink
 * @reboot_required true
 */
PARAM_DEFINE_INT32(MAV_0_CONFIG, 101);

/**
 * Serial Configuration for MAVLink (instance 1)
 *
 * Configure on which serial port to run MAVLink.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group MAVLink
 * @reboot_required true
 */
PARAM_DEFINE_INT32(MAV_1_CONFIG, 0);

/**
 * Serial Configuration for MAVLink (instance 2)
 *
 * Configure on which serial port to run MAVLink.
 *
 * 
 *
 * @value 0 Disabled
 * @value 201 GPS 1
 * @value 101 TELEM 1
 * @value 102 TELEM 2
 * @value 104 TELEM/SERIAL 4
 * @group MAVLink
 * @reboot_required true
 */
PARAM_DEFINE_INT32(MAV_2_CONFIG, 0);




/**
 * Distance Sensor Rotation
 *
 * Distance Sensor Rotation as MAV_SENSOR_ORIENTATION enum
 * 
 *
 * @group Sensors
 * @value 0 ROTATION_FORWARD_FACING
 * @value 2 ROTATION_RIGHT_FACING
 * @value 6 ROTATION_LEFT_FACING
 * @value 24 ROTATION_UPWARD_FACING
 * @value 25 ROTATION_DOWNWARD_FACING
 * @value 12 ROTATION_BACKWARD_FACING
 * @reboot_required True
 */
PARAM_DEFINE_INT32(SENS_CM8JL65_R_0, 25);

/**
 * Minimum DShot Motor Output
 *
 * Minimum Output Value for DShot in percent. The value depends on the ESC. Make
 * sure to set this high enough so that the motors are always spinning while
 * armed.
 * 
 *
 * @group DShot
 * @decimal 2
 * @increment 0.01
 * @min 0
 * @max 1
 * @unit %
 */
PARAM_DEFINE_FLOAT(DSHOT_MIN, 0.055);

/**
 * Number of magnetic poles of the motors
 *
 * Specify the number of magnetic poles of the motors.
 * It is required to compute the RPM value from the eRPM returned with the ESC telemetry.
 * 
 * Either get the number from the motor spec sheet or count the magnets on the bell of the motor (not the stator magnets).
 * Typical motors for 5 inch props have 14 poles.
 * 
 *
 * @group DShot
 */
PARAM_DEFINE_INT32(MOT_POLE_COUNT, 14);

/**
 * Configure DShot
 *
 * This enables/disables DShot. The different modes define different
 * speeds, for example DShot150 = 150kb/s. Not all ESCs support all modes.
 * 
 * Note: this enables DShot on the FMU outputs. For boards with an IO it is the
 * AUX outputs.
 * 
 *
 * @group DShot
 * @value 0 Disable (use PWM/Oneshot)
 * @value 600 DShot600
 * @value 1200 DShot1200
 * @value 300 DShot300
 * @value 150 DShot150
 * @reboot_required True
 */
PARAM_DEFINE_INT32(DSHOT_CONFIG, 0);

/**
 * Enable MAVLink Message forwarding for instance 0
 *
 * If enabled, forward incoming MAVLink messages to other MAVLink ports if the
 * message is either broadcast or the target is not the autopilot.
 * 
 * This allows for example a GCS to talk to a camera that is connected to the
 * autopilot via MAVLink (on a different link than the GCS).
 * 
 *
 * @group MAVLink
 * @boolean
 * @reboot_required True
 */
PARAM_DEFINE_INT32(MAV_0_FORWARD, 1);

/**
 * Enable MAVLink Message forwarding for instance 1
 *
 * If enabled, forward incoming MAVLink messages to other MAVLink ports if the
 * message is either broadcast or the target is not the autopilot.
 * 
 * This allows for example a GCS to talk to a camera that is connected to the
 * autopilot via MAVLink (on a different link than the GCS).
 * 
 *
 * @group MAVLink
 * @boolean
 * @reboot_required True
 */
PARAM_DEFINE_INT32(MAV_1_FORWARD, 0);

/**
 * Enable MAVLink Message forwarding for instance 2
 *
 * If enabled, forward incoming MAVLink messages to other MAVLink ports if the
 * message is either broadcast or the target is not the autopilot.
 * 
 * This allows for example a GCS to talk to a camera that is connected to the
 * autopilot via MAVLink (on a different link than the GCS).
 * 
 *
 * @group MAVLink
 * @boolean
 * @reboot_required True
 */
PARAM_DEFINE_INT32(MAV_2_FORWARD, 0);

/**
 * MAVLink Mode for instance 0
 *
 * The MAVLink Mode defines the set of streamed messages (for example the
 * vehicle's attitude) and their sending rates.
 * 
 *
 * @group MAVLink
 * @value 0 Normal
 * @value 1 Custom
 * @value 2 Onboard
 * @value 3 OSD
 * @value 4 Magic
 * @value 5 Config
 * @value 7 Minimal
 * @value 8 External Vision
 * @reboot_required True
 */
PARAM_DEFINE_INT32(MAV_0_MODE, 0);

/**
 * MAVLink Mode for instance 1
 *
 * The MAVLink Mode defines the set of streamed messages (for example the
 * vehicle's attitude) and their sending rates.
 * 
 *
 * @group MAVLink
 * @value 0 Normal
 * @value 1 Custom
 * @value 2 Onboard
 * @value 3 OSD
 * @value 4 Magic
 * @value 5 Config
 * @value 7 Minimal
 * @value 8 External Vision
 * @reboot_required True
 */
PARAM_DEFINE_INT32(MAV_1_MODE, 2);

/**
 * MAVLink Mode for instance 2
 *
 * The MAVLink Mode defines the set of streamed messages (for example the
 * vehicle's attitude) and their sending rates.
 * 
 *
 * @group MAVLink
 * @value 0 Normal
 * @value 1 Custom
 * @value 2 Onboard
 * @value 3 OSD
 * @value 4 Magic
 * @value 5 Config
 * @value 7 Minimal
 * @value 8 External Vision
 * @reboot_required True
 */
PARAM_DEFINE_INT32(MAV_2_MODE, 0);

/**
 * Maximum MAVLink sending rate for instance 0
 *
 * Configure the maximum sending rate for the MAVLink streams in Bytes/sec.
 * If the configured streams exceed the maximum rate, the sending rate of
 * each stream is automatically decreased.
 * 
 * If this is set to 0 a value of half of the theoretical maximum bandwidth is used.
 * This corresponds to baudrate/20 Bytes/s (baudrate/10 = maximum data rate on 
 * 8N1-configured links).
 * 
 *
 * @group MAVLink
 * @min 0
 * @unit B/s
 * @reboot_required True
 */
PARAM_DEFINE_INT32(MAV_0_RATE, 1200);

/**
 * Maximum MAVLink sending rate for instance 1
 *
 * Configure the maximum sending rate for the MAVLink streams in Bytes/sec.
 * If the configured streams exceed the maximum rate, the sending rate of
 * each stream is automatically decreased.
 * 
 * If this is set to 0 a value of half of the theoretical maximum bandwidth is used.
 * This corresponds to baudrate/20 Bytes/s (baudrate/10 = maximum data rate on 
 * 8N1-configured links).
 * 
 *
 * @group MAVLink
 * @min 0
 * @unit B/s
 * @reboot_required True
 */
PARAM_DEFINE_INT32(MAV_1_RATE, 0);

/**
 * Maximum MAVLink sending rate for instance 2
 *
 * Configure the maximum sending rate for the MAVLink streams in Bytes/sec.
 * If the configured streams exceed the maximum rate, the sending rate of
 * each stream is automatically decreased.
 * 
 * If this is set to 0 a value of half of the theoretical maximum bandwidth is used.
 * This corresponds to baudrate/20 Bytes/s (baudrate/10 = maximum data rate on 
 * 8N1-configured links).
 * 
 *
 * @group MAVLink
 * @min 0
 * @unit B/s
 * @reboot_required True
 */
PARAM_DEFINE_INT32(MAV_2_RATE, 0);
