// Consolidated defines - generated on 2025-12-17 18:43:32.042430


// ../inav/src/main/navigation/navigation_pos_estimator.c
#define resetTimer(tim, currentTimeUs) { (tim)->deltaTime = 0; (tim)->lastTriggeredTime = currentTimeUs; }
#define getTimerDeltaMicros(tim) ((tim)->deltaTime)
#define ACC_VIB_FACTOR_S 1.0f
#define ACC_VIB_FACTOR_E 3.0f


// ../inav/src/main/navigation/navigation_private.h
#define DISTANCE_BETWEEN_TWO_LONGITUDE_POINTS_AT_EQUATOR    1.113195f
#define MIN_POSITION_UPDATE_RATE_HZ         5
#define NAV_THROTTLE_CUTOFF_FREQENCY_HZ     4
#define NAV_FW_CONTROL_MONITORING_RATE      2
#define NAV_DTERM_CUT_HZ                    10.0f
#define NAV_VEL_Z_DERIVATIVE_CUT_HZ         5.0f
#define NAV_VEL_Z_ERROR_CUT_HZ              5.0f
#define NAV_ACCELERATION_XY_MAX             980.0f
#define INAV_SURFACE_MAX_DISTANCE           40
#define MC_POS_CONTROL_JERK_LIMIT_CMSSS     1700.0f
#define MC_LAND_CHECK_VEL_XY_MOVING         100.0f
#define MC_LAND_CHECK_VEL_Z_MOVING          100.0f
#define MC_LAND_THR_STABILISE_DELAY         1
#define MC_LAND_DESCEND_THROTTLE            40
#define MC_LAND_SAFE_SURFACE                5.0f
#define MAX_POSITION_UPDATE_INTERVAL_US     HZ2US(MIN_POSITION_UPDATE_RATE_HZ)


// ../inav/src/main/navigation/navigation_fixedwing.c
#define NAV_FW_BASE_PITCH_CUTOFF_FREQUENCY_HZ     2.0f
#define NAV_FW_BASE_ROLL_CUTOFF_FREQUENCY_HZ     10.0f
#define NAV_FW_THROTTLE_SPEED_BOOST_GAIN        1.5f
    #define TAN_15DEG    0.26795f


// ../inav/src/main/navigation/rth_trackback.h
#define NAV_RTH_TRACKBACK_POINTS                50
#define NAV_RTH_TRACKBACK_MIN_DIST_TO_START     50
#define NAV_RTH_TRACKBACK_MIN_XY_DIST_TO_SAVE   20
#define NAV_RTH_TRACKBACK_MIN_Z_DIST_TO_SAVE    10
#define NAV_RTH_TRACKBACK_MIN_TRIP_DIST_TO_SAVE 10


// ../inav/src/main/navigation/navigation_pos_estimator_private.h
#define INAV_GPS_DEFAULT_EPH                200.0f
#define INAV_GPS_DEFAULT_EPV                500.0f
#define INAV_GPS_ACCEPTANCE_EPE             500.0f
#define INAV_ACC_BIAS_ACCEPTANCE_VALUE      (GRAVITY_CMSS * 0.25f)
#define INAV_GPS_GLITCH_RADIUS              250.0f
#define INAV_GPS_GLITCH_ACCEL               1000.0f
#define INAV_POSITION_PUBLISH_RATE_HZ       50
#define INAV_PITOT_UPDATE_RATE              10
#define INAV_GPS_TIMEOUT_MS                 1500
#define INAV_BARO_TIMEOUT_MS                200
#define INAV_SURFACE_TIMEOUT_MS             400
#define INAV_FLOW_TIMEOUT_MS                200
#define CALIBRATING_GRAVITY_TIME_MS         2000
#define INAV_BARO_AVERAGE_HZ                1.0f
#define INAV_SURFACE_AVERAGE_HZ             1.0f
#define INAV_ACC_CLIPPING_RC_CONSTANT           (0.010f)
#define RANGEFINDER_RELIABILITY_RC_CONSTANT     (0.47802f)
#define RANGEFINDER_RELIABILITY_LIGHT_THRESHOLD (0.15f)
#define RANGEFINDER_RELIABILITY_LOW_THRESHOLD   (0.33f)
#define RANGEFINDER_RELIABILITY_HIGH_THRESHOLD  (0.75f)


// ../inav/src/main/navigation/navigation.c
#define MR_RTH_CLIMB_OVERSHOOT_CM   100
#define MR_RTH_CLIMB_MARGIN_MIN_CM  100
#define MR_RTH_CLIMB_MARGIN_PERCENT 15
#define MR_RTH_LAND_MARGIN_CM       2000
#define FW_RTH_CLIMB_OVERSHOOT_CM   100
#define FW_RTH_CLIMB_MARGIN_MIN_CM  100
#define FW_RTH_CLIMB_MARGIN_PERCENT 15
#define FW_LAND_LOITER_MIN_TIME 30000000
#define FW_LAND_LOITER_ALT_TOLERANCE 150


// ../inav/src/main/navigation/navigation_fw_launch.c
#define SWING_LAUNCH_MIN_ROTATION_RATE      DEGREES_TO_RADIANS(100)
#define LAUNCH_MOTOR_IDLE_SPINUP_TIME 1500
#if !defined(UNUSED)
#define UNUSED(x) ((void)(x))
#endif
#define FW_LAUNCH_MESSAGE_TEXT_WAIT_THROTTLE "RAISE THE THROTTLE"
#define FW_LAUNCH_MESSAGE_TEXT_WAIT_IDLE "WAITING FOR IDLE"
#define FW_LAUNCH_MESSAGE_TEXT_WAIT_DETECTION "READY TO LAUNCH"
#define FW_LAUNCH_MESSAGE_TEXT_IN_PROGRESS "MOVE THE STICKS TO ABORT"
#define FW_LAUNCH_MESSAGE_TEXT_FINISHING "FINISHING"


// ../inav/src/main/navigation/navigation.h
#if defined(USE_SAFE_HOME)
#define MAX_SAFE_HOMES 8
#endif
#ifdef USE_FW_AUTOLAND
#ifndef MAX_SAFE_HOMES
#define MAX_SAFE_HOMES 0
#endif
#define MAX_FW_LAND_APPOACH_SETTINGS (MAX_SAFE_HOMES + 9)
#endif
#if defined(USE_GEOZONE)
#define GEOZONE_SHAPE_CIRCULAR 0
#define GEOZONE_SHAPE_POLYGON  1
#define GEOZONE_TYPE_EXCLUSIVE 0
#define GEOZONE_TYPE_INCLUSIVE 1
#endif
#ifndef NAV_MAX_WAYPOINTS
#define NAV_MAX_WAYPOINTS 15
#endif
#define NAV_ACCEL_CUTOFF_FREQUENCY_HZ 2
#define RADAR_MAX_POIS 5


// ../inav/src/main/navigation/navigation_geozone.c
#ifdef USE_GEOZONE
#define MAX_VERTICES (MAX_VERTICES_IN_CONFIG + 1)
#define MAX_GEOZONES (MAX_GEOZONES_IN_CONFIG + 1)
#define MAX_DISTANCE_FLY_OVER_POINTS 50000
#define MAX_PATH_PONITS (2 + 2 * MAX_VERTICES)
#define POS_DETECTION_DISTANCE 7500
#define STICK_LOCK_MIN_TIME 2500
#define AVOID_TIMEOUT 30000
#define MAX_LOCAL_VERTICES 128
#define GEOZONE_INCLUSE_IGNORE_DISTANCE 2000 * 100
#define STICK_MOVE_THRESHOULD 40
#define MAX_RTH_WAYPOINTS (MAX_VERTICES / 2)
#define GEOZONE_INACTIVE INT8_MAX
#define RTH_OVERRIDE_TIMEOUT 1000
#define K_EPSILON 1e-8f
#define IS_IN_TOLERANCE_RANGE(a, b, t) (((a) > (b) - (t)) && ((a) < (b) + (t)))
#define CIRCLE_POLY_SIDES 6
#endif


// ../inav/src/main/sensors/pitotmeter.c
#ifdef USE_PITOT
#define PITOT_HARDWARE_TIMEOUT_MS   500
#ifdef USE_PITOT
#define PITOT_HARDWARE_DEFAULT    PITOT_AUTODETECT
#else
#define PITOT_HARDWARE_DEFAULT    PITOT_NONE
#endif
#endif


// ../inav/src/main/sensors/irlock.c
#define IRLOCK_TIMEOUT 100
#if defined(USE_IRLOCK)
#define X_TO_DISTANCE_FACTOR -0.0029387573f
#define X_TO_DISTANCE_OFFSET 0.4702011635f
#define Y_TO_DISTANCE_FACTOR -0.0030568431f
#define Y_TO_DISTANCE_OFFSET 0.3056843086f
#define LENS_X_CORRECTION 4.4301355e-6f
#define LENS_Y_CORRECTION 4.7933139e-6f
#endif


// ../inav/src/main/sensors/boardalignment.c
#if defined(UNIT_TEST)
#define SETTING_ALIGN_BOARD_ROLL_MIN -1800
#define SETTING_ALIGN_BOARD_ROLL_MAX 3600
#define SETTING_ALIGN_BOARD_PITCH_MIN -1800
#define SETTING_ALIGN_BOARD_PITCH_MAX 3600
#endif


// ../inav/src/main/sensors/gyro.c
#define MAX_GYRO_COUNT 1


// ../inav/src/main/sensors/opflow.c
#ifdef USE_OPFLOW
#define OPFLOW_SQUAL_THRESHOLD_HIGH     35
#define OPFLOW_SQUAL_THRESHOLD_LOW      10
#define OPFLOW_UPDATE_TIMEOUT_US        200000
#define OPFLOW_CALIBRATE_TIME_MS        30000
#endif


// ../inav/src/main/sensors/battery.c
#define ADCVREF 3300
#define VBATT_CELL_FULL_MAX_DIFF 10
#define VBATT_PRESENT_THRESHOLD 220
#define VBATT_STABLE_DELAY 40
#define VBATT_HYSTERESIS 10
#define VBATT_LPF_FREQ  1
#define AMPERAGE_LPF_FREQ  1
#define IMPEDANCE_STABLE_SAMPLE_COUNT_THRESH 10


// ../inav/src/main/sensors/battery.h
#ifndef VBAT_SCALE_DEFAULT
#define VBAT_SCALE_DEFAULT 1100
#endif
#ifndef CURRENT_METER_SCALE
#define CURRENT_METER_SCALE 400
#endif
#ifndef CURRENT_METER_OFFSET
#define CURRENT_METER_OFFSET 0
#endif
#ifndef MAX_BATTERY_PROFILE_COUNT
#define MAX_BATTERY_PROFILE_COUNT SETTING_CONSTANT_MAX_BATTERY_PROFILE_COUNT
#endif
#define currentBatteryProfileMutable ((batteryProfile_t*)currentBatteryProfile)


// ../inav/src/main/sensors/rangefinder.c
#define RANGEFINDER_HARDWARE_TIMEOUT_MS         500
#define RANGEFINDER_DYNAMIC_THRESHOLD           600
#define RANGEFINDER_DYNAMIC_FACTOR              75
#ifdef USE_RANGEFINDER
    #define DISTANCE_SAMPLES_MEDIAN 5
#endif


// ../inav/src/main/sensors/temperature.h
#define TEMPERATURE_LABEL_LEN 4
#define MAX_TEMP_SENSORS 8
#define TEMPERATURE_INVALID_VALUE -1250


// ../inav/src/main/sensors/pitotmeter.h
#define PITOT_MAX  PITOT_FAKE
#define PITOT_SAMPLE_COUNT_MAX   48


// ../inav/src/main/sensors/esc_sensor.c
#if defined(USE_ESC_SENSOR)
#define ESC_BOOTTIME_MS         5000
#define ESC_REQUEST_TIMEOUT_MS  50
#define ESC_SENSOR_BAUDRATE     115200
#define TELEMETRY_FRAME_SIZE    10
#endif


// ../inav/src/main/sensors/sensors.h
#define CALIBRATING_BARO_TIME_MS            2000
#define CALIBRATING_PITOT_TIME_MS           4000
#define CALIBRATING_GYRO_TIME_MS            2000
#define CALIBRATING_ACC_TIME_MS             500
#define CALIBRATING_GYRO_MORON_THRESHOLD    32


// ../inav/src/main/sensors/acceleration.h
#define GRAVITY_CMSS    980.665f
#define GRAVITY_MSS     9.80665f
#define ACC_CLIPPING_THRESHOLD_G        15.9f
#define ACC_VIBE_FLOOR_FILT_HZ          5.0f
#define ACC_VIBE_FILT_HZ                2.0f


// ../inav/src/main/sensors/diagnostics.h
#define HW_SENSOR_IS_HEALTHY(status)    (status == HW_SENSOR_NONE || status == HW_SENSOR_OK)


// ../inav/src/main/sensors/esc_sensor.h
#define ESC_DATA_MAX_AGE    10
#define ESC_DATA_INVALID    255
#define ERPM_PER_LSB        100.0f


// ../inav/src/main/sensors/temperature.c
#define MPU_TEMP_VALID_BIT 0
#define BARO_TEMP_VALID_BIT 1
#define MPU_TEMP_VALID (mpuBaroTempValid & (1 << MPU_TEMP_VALID_BIT))
#define BARO_TEMP_VALID (mpuBaroTempValid & (1 << BARO_TEMP_VALID_BIT))


// ../inav/src/main/programming/global_variables.h
#define MAX_GLOBAL_VARIABLES 8


// ../inav/src/main/programming/pid.h
#define MAX_PROGRAMMING_PID_COUNT 4


// ../inav/src/main/programming/logic_condition.h
#define MAX_LOGIC_CONDITIONS 64
#define LOGIC_CONDITION_GLOBAL_FLAG_DISABLE(mask) (logicConditionsGlobalFlags &= ~(mask))
#define LOGIC_CONDITION_GLOBAL_FLAG_ENABLE(mask) (logicConditionsGlobalFlags |= (mask))
#define LOGIC_CONDITION_GLOBAL_FLAG(mask) (logicConditionsGlobalFlags & (mask))


// ../inav/src/main/rx/rx.h
#define STICK_CHANNEL_COUNT 4
#define PWM_RANGE_MIN 1000
#define PWM_RANGE_MAX 2000
#define PWM_RANGE_MIDDLE (PWM_RANGE_MIN + ((PWM_RANGE_MAX - PWM_RANGE_MIN) / 2))
#define PWM_PULSE_MIN   750
#define PWM_PULSE_MAX   2250
#define MIDRC_MIN 1200
#define MIDRC_MAX 1700
#define RXFAIL_STEP_TO_CHANNEL_VALUE(step) (PWM_PULSE_MIN + 25 * step)
#define CHANNEL_VALUE_TO_RXFAIL_STEP(channelValue) ((constrain(channelValue, PWM_PULSE_MIN, PWM_PULSE_MAX) - PWM_PULSE_MIN) / 25)
#define MAX_RXFAIL_RANGE_STEP ((PWM_PULSE_MAX - PWM_PULSE_MIN) / 25)
#define DEFAULT_SERVO_MIN 1000
#define DEFAULT_SERVO_MIDDLE 1500
#define DEFAULT_SERVO_MAX 2000
#define DELAY_50_HZ (1000000 / 50)
#define DELAY_10_HZ (1000000 / 10)
#define DELAY_5_HZ (1000000 / 5)
#define RSSI_MAX_VALUE 1023
#define MAX_SUPPORTED_RC_CHANNEL_COUNT 34
#define NON_AUX_CHANNEL_COUNT 4
#define MAX_AUX_CHANNEL_COUNT (MAX_SUPPORTED_RC_CHANNEL_COUNT - NON_AUX_CHANNEL_COUNT)
#define MAX_MAPPABLE_RX_INPUTS 4
#define MAX_INVALID_RX_PULSE_TIME    300
#define RSSI_VISIBLE_VALUE_MIN 0
#define RSSI_VISIBLE_VALUE_MAX 100
#define RSSI_VISIBLE_FACTOR (RSSI_MAX_VALUE/(float)RSSI_VISIBLE_VALUE_MAX)
#define REMAPPABLE_CHANNEL_COUNT ARRAYLEN(((rxConfig_t *)0)->rcmap)


// ../inav/src/main/rx/crsf.c
#ifdef USE_SERIALRX_CRSF
#define CRSF_TIME_NEEDED_PER_FRAME_US   1750
#define CRSF_TIME_BETWEEN_FRAMES_US     6667
#define CRSF_DIGITAL_CHANNEL_MIN 172
#define CRSF_DIGITAL_CHANNEL_MAX 1811
#define CRSF_PAYLOAD_OFFSET offsetof(crsfFrameDef_t, type)
#define CRSF_POWER_COUNT 9
#endif


// ../inav/src/main/rx/rx.c
#define MSP_RSSI_TIMEOUT_US     1500000
#define RX_LQ_INTERVAL_MS       200
#define RX_LQ_TIMEOUT_MS        1000
#ifndef SERIALRX_PROVIDER
#define SERIALRX_PROVIDER 0
#endif
#ifndef DEFAULT_RX_TYPE
#define DEFAULT_RX_TYPE   RX_TYPE_NONE
#endif
#define RX_MIN_USEX 885
#define RSSI_SAMPLE_COUNT 16


// ../inav/src/main/rx/sbus_channels.h
#define SBUS_MAX_CHANNEL 34
#define SBUS_FLAG_CHANNEL_DG1       (1 << 0)
#define SBUS_FLAG_CHANNEL_DG2       (1 << 1)
#define SBUS_FLAG_SIGNAL_LOSS       (1 << 2)
#define SBUS_FLAG_FAILSAFE_ACTIVE   (1 << 3)
#define SBUS_CHANNEL_DATA_LENGTH sizeof(sbusChannels_t)
#define SBUS_FRAME_SIZE (SBUS_CHANNEL_DATA_LENGTH + 2)
#define SBUS_FRAME_BEGIN_BYTE   ((uint8_t)0x0F)
#define SBUS2_HIGHFRAME_BEGIN_BYTE ((uint8_t)0x2F)
#define SBUS_BAUDRATE       100000
#define SBUS_BAUDRATE_FAST  200000
#if !defined(SBUS_PORT_OPTIONS)
#define SBUS_PORT_OPTIONS (SERIAL_STOPBITS_2 | SERIAL_PARITY_EVEN)
#endif


// ../inav/src/main/rx/ibus.c
#ifdef USE_SERIALRX_IBUS
#define IBUS_MAX_CHANNEL 18
#define IBUS_MAX_SLOTS 14
#define IBUS_BUFFSIZE 32
#define IBUS_MODEL_IA6B 0
#define IBUS_MODEL_IA6 1
#define IBUS_FRAME_GAP 500
#define IBUS_TELEMETRY_PACKET_LENGTH (4)
#define IBUS_SERIAL_RX_PACKET_LENGTH (32)
#endif


// ../inav/src/main/rx/crsf.h
#define CRSF_BAUDRATE           420000
#define CRSF_PORT_OPTIONS       (SERIAL_STOPBITS_1 | SERIAL_PARITY_NO)
#define CRSF_PORT_MODE          MODE_RXTX
#define CRSF_MAX_CHANNEL        17
#define CRSF_TELEMETRY_SYNC_BYTE  0XC8


// ../inav/src/main/rx/ghst_protocol.h
#define GHST_RX_BAUDRATE                420000
#define GHST_TX_BAUDRATE_FAST           400000
#define GHST_TX_BAUDRATE_SLOW           115200
#define GHST_BYTE_TIME_FAST_US          ((1000000/GHST_TX_BAUDRATE_FAST)*10)
#define GHST_BYTE_TIME_SLOW_US          ((1000000/GHST_TX_BAUDRATE_SLOW)*10)
#define GHST_UART_WORDLENGTH            UART_WORDLENGTH_8B
#define GHST_UL_RC_CHANS_FRAME_COUNT    (GHST_UL_RC_CHANS_HS4_13TO16 - GHST_UL_RC_CHANS_HS4_5TO8 + 1)
#define GHST_UL_RC_TOTAL_FRAME_COUNT    (GHST_UL_RC_CHANS_HS4_LAST - GHST_UL_RC_CHANS_HS4_FIRST + 1)
#define GHST_UL_RC_CHANS_SIZE           12
#define GHST_RC_CTR_VAL_12BIT       0x7C0
#define GHST_RC_CTR_VAL_8BIT        0x7C
#define GHST_FRAME_SIZE             14
#define GHST_PAYLOAD_SIZE_MAX       14
#define GHST_FRAME_SIZE_MAX         24
#define GPS_FLAGS_FIX               0x01
#define GPS_FLAGS_FIX_HOME          0x02


// ../inav/src/main/rx/srxl2.c
#ifdef USE_SERIALRX_SRXL2
#ifndef SRXL2_DEBUG
#define SRXL2_DEBUG 0
#endif
#if SRXL2_DEBUG
#define DEBUG_PRINTF(...)
#else
#define DEBUG_PRINTF(...)
#endif
#define SRXL2_MAX_CHANNELS             32
#define SRXL2_FRAME_PERIOD_US   11000
#define SRXL2_CHANNEL_SHIFT            5
#define SRXL2_CHANNEL_CENTER           0x8000
#define SRXL2_PORT_BAUDRATE_DEFAULT    115200
#define SRXL2_PORT_BAUDRATE_HIGH       400000
#define SRXL2_PORT_OPTIONS             (SERIAL_STOPBITS_1 | SERIAL_PARITY_NO | SERIAL_BIDIR)
#define SRXL2_PORT_MODE                MODE_RXTX
#define SRXL2_REPLY_QUIESCENCE         (2 * 10 * 1000000 / SRXL2_PORT_BAUDRATE_DEFAULT)
#define SRXL2_ID                       0xA6
#define SRXL2_MAX_PACKET_LENGTH        80
#define SRXL2_DEVICE_ID_BROADCAST      0xFF
#define SRXL2_FRAME_TIMEOUT_US         50000
#define SRXL2_LISTEN_FOR_ACTIVITY_TIMEOUT_US 50000
#define SRXL2_SEND_HANDSHAKE_TIMEOUT_US 50000
#define SRXL2_LISTEN_FOR_HANDSHAKE_TIMEOUT_US 200000
#define SPEKTRUM_PULSE_OFFSET          988
#endif


// ../inav/src/main/rx/sumd.c
#ifdef USE_SERIALRX_SUMD
#define SUMD_SYNCBYTE 0xA8
#define SUMD_MAX_CHANNEL 16
#define SUMD_BUFFSIZE (SUMD_MAX_CHANNEL * 2 + 5)
#define SUMD_BAUDRATE 115200
#define CRC_POLYNOME 0x1021
#define SUMD_OFFSET_CHANNEL_1_HIGH 3
#define SUMD_OFFSET_CHANNEL_1_LOW 4
#define SUMD_BYTES_PER_CHANNEL 2
#define SUMD_FRAME_STATE_OK 0x01
#define SUMD_FRAME_STATE_FAILSAFE 0x81
#endif


// ../inav/src/main/rx/ghst.h
#define GHST_MAX_NUM_CHANNELS           16


// ../inav/src/main/rx/mavlink.c
#ifdef USE_SERIALRX_MAVLINK
#define MAVLINK_CHANNEL_COUNT 18
#endif


// ../inav/src/main/rx/mavlink.h
#define MAVLINK_COMM_NUM_BUFFERS 1


// ../inav/src/main/rx/fport2.c
#ifdef USE_SERIALRX_FPORT2
#define FPORT2_MIN_TELEMETRY_RESPONSE_DELAY_US 500
#define FPORT2_MAX_TELEMETRY_RESPONSE_DELAY_US 3000
#define FPORT2_OTA_MAX_RESPONSE_TIME_US_DEFAULT 200
#define FPORT2_OTA_MIN_RESPONSE_DELAY_US_DEFAULT 50
#define FPORT2_MAX_TELEMETRY_AGE_MS 500
#define FPORT2_FC_COMMON_ID 0x1B
#define FPORT2_FC_MSP_ID 0x0D
#define FPORT2_BAUDRATE 115200
#define FBUS_BAUDRATE 460800
#define FPORT2_PORT_OPTIONS (SERIAL_STOPBITS_1 | SERIAL_PARITY_NO)
#define FPORT2_RX_TIMEOUT 120
#define FPORT2_CONTROL_FRAME_LENGTH 24
#define FPORT2_OTA_DATA_FRAME_LENGTH 32
#define FPORT2_DOWNLINK_FRAME_LENGTH 8
#define FPORT2_UPLINK_FRAME_LENGTH 8
#define FPORT2_TELEMETRY_MAX_CONSECUTIVE_TELEMETRY_FRAMES 2
#define FPORT2_OTA_DATA_FRAME_BYTES 32
#define NUM_RX_BUFFERS 15
#endif


// ../inav/src/main/rx/jetiexbus.h
#define EXBUS_HEADER_LEN                6
#define EXBUS_CRC_LEN                   2
#define EXBUS_OVERHEAD                  (EXBUS_HEADER_LEN + EXBUS_CRC_LEN)
#define EXBUS_MAX_CHANNEL_FRAME_SIZE    (EXBUS_HEADER_LEN + JETIEXBUS_CHANNEL_COUNT*2 + EXBUS_CRC_LEN)
#define EXBUS_MAX_REQUEST_FRAME_SIZE    32
#define EXBUS_EX_REQUEST                (0x3A)


// ../inav/src/main/rx/sbus_channels.c
#ifdef USE_SERIAL_RX
#define SBUS_DIGITAL_CHANNEL_MIN 173
#define SBUS_DIGITAL_CHANNEL_MAX 1812
#endif


// ../inav/src/main/rx/spektrum.h
#define SPEKTRUM_MAX_SUPPORTED_CHANNEL_COUNT 12
#define SPEKTRUM_2048_CHANNEL_COUNT          12
#define SPEKTRUM_1024_CHANNEL_COUNT          7
#define SPEKTRUM_SAT_BIND_DISABLED           0
#define SPEKTRUM_SAT_BIND_MAX                10
#define SPEK_FRAME_SIZE                      16
#define SRXL_FRAME_OVERHEAD                   5
#define SRXL_FRAME_SIZE_MAX (SPEK_FRAME_SIZE + SRXL_FRAME_OVERHEAD)
#define SPEKTRUM_NEEDED_FRAME_INTERVAL 5000
#define SPEKTRUM_BAUDRATE 115200


// ../inav/src/main/rx/spektrum.c
#ifdef USE_SERIALRX_SPEKTRUM
#define SPEKTRUM_TELEMETRY_FRAME_DELAY_US 1000
#define SPEKTRUM_MAX_FADE_PER_SEC 40
#define SPEKTRUM_FADE_REPORTS_PER_SEC 2
#endif


// ../inav/src/main/rx/jetiexbus.c
#ifdef USE_SERIALRX_JETIEXBUS
#define JETIEXBUS_BAUDRATE 125000
#define JETIEXBUS_OPTIONS (SERIAL_STOPBITS_1 | SERIAL_PARITY_NO)
#define JETIEXBUS_MIN_FRAME_GAP     1000
#ifdef USE_34CHANNELS
#define JETIEXBUS_CHANNEL_COUNT 24
#else
#define JETIEXBUS_CHANNEL_COUNT 16
#endif
#define EXBUS_START_CHANNEL_FRAME       (0x3E)
#define EXBUS_START_REQUEST_FRAME       (0x3D)
#define EXBUS_JETIBOX_REQUEST           (0x3B)
#define EXBUS_CHANNELDATA               (0x3E03)
#define EXBUS_CHANNELDATA_DATA_REQUEST  (0x3E01)
#define EXBUS_TELEMETRY_REQUEST         (0x3D01)
#endif


// ../inav/src/main/rx/sbus.h
#define SBUS_DEFAULT_INTERFRAME_DELAY_US    3000
#define SBUS_BYTE_TIME_US(bytes)    MS2US(10 * 12 * bytes)


// ../inav/src/main/rx/fport.c
#if defined(USE_SERIAL_RX)
#define FPORT_TIME_NEEDED_PER_FRAME_US 3000
#define FPORT_MAX_TELEMETRY_RESPONSE_DELAY_US 2000
#define FPORT_MIN_TELEMETRY_RESPONSE_DELAY_US 500
#define FPORT_MAX_TELEMETRY_AGE_MS 500
#define FPORT_TELEMETRY_MAX_CONSECUTIVE_TELEMETRY_FRAMES 2
#define FPORT_FRAME_MARKER 0x7E
#define FPORT_ESCAPE_CHAR 0x7D
#define FPORT_ESCAPE_MASK 0x20
#define FPORT_BAUDRATE 115200
#define FPORT_PORT_OPTIONS (SERIAL_STOPBITS_1 | SERIAL_PARITY_NO)
#if defined(USE_SERIALRX_FPORT)
#define FPORT_REQUEST_FRAME_LENGTH sizeof(fportFrame_t)
#define FPORT_RESPONSE_FRAME_LENGTH (sizeof(uint8_t) + sizeof(smartPortPayload_t))
#define FPORT_FRAME_PAYLOAD_LENGTH_CONTROL (sizeof(uint8_t) + sizeof(fportControlData_t))
#define FPORT_FRAME_PAYLOAD_LENGTH_TELEMETRY_REQUEST (sizeof(uint8_t) + sizeof(smartPortPayload_t))
#define NUM_RX_BUFFERS 3
#define BUFFER_SIZE (FPORT_REQUEST_FRAME_LENGTH + 2 * sizeof(uint8_t))
#endif
#endif


// ../inav/src/main/rx/ghst.c
#ifdef USE_SERIALRX_GHST
#define GHST_PORT_OPTIONS               (SERIAL_STOPBITS_1 | SERIAL_PARITY_NO | SERIAL_BIDIR | SERIAL_BIDIR_PP)
#define GHST_PORT_MODE                  MODE_RXTX
#define GHST_MAX_FRAME_TIME_US          500
#define GHST_TIME_BETWEEN_FRAMES_US     4500
#define GHST_RX_TO_TELEMETRY_MIN_US     1000
#define GHST_RX_TO_TELEMETRY_MAX_US     2000
#define GHST_RC_FRAME_TIMEOUT_MS        300
#define GHST_RC_FRAME_COUNT_THRESHOLD   4
#define GHST_PAYLOAD_OFFSET offsetof(ghstFrameDef_t, type)
#define GHST_FRAME_LENGTH_ADDRESS       1
#define GHST_FRAME_LENGTH_FRAMELENGTH   1
#define GHST_FRAME_LENGTH_TYPE_CRC      1
#endif


// ../inav/src/main/rx/srxl2_types.h
#define PACKED __attribute__((packed))
#define SRXL_BIND_OPT_NONE              (0x00)
#define SRXL_BIND_OPT_TELEM_TX_ENABLE   (0x01)
#define SRXL_BIND_OPT_BIND_TX_ENABLE    (0x02)


// ../inav/src/main/telemetry/crsf.c
#if defined(USE_TELEMETRY) && defined(USE_SERIALRX_CRSF) && defined(USE_TELEMETRY_CRSF)
#define CRSF_CYCLETIME_US                   100000
#define CRSF_DEVICEINFO_VERSION             0x01
#define CRSF_DEVICEINFO_PARAMETER_COUNT     0
#define CRSF_MSP_BUFFER_SIZE 96
#define CRSF_MSP_LENGTH_OFFSET 1
#define BV(x)  (1 << (x))
#endif


// ../inav/src/main/telemetry/telemetry.h
#define TELEMETRY_SHAREABLE_PORT_FUNCTIONS_MASK (FUNCTION_TELEMETRY_LTM | FUNCTION_TELEMETRY_IBUS)


// ../inav/src/main/telemetry/smartport.c
#if defined(USE_TELEMETRY) && defined(USE_TELEMETRY_SMARTPORT)
#define __USE_C99_MATH
#define SMARTPORT_BAUD 57600
#define SMARTPORT_UART_MODE MODE_RXTX
#define SMARTPORT_SERVICE_TIMEOUT_MS 1
#define SMARTPORT_MSP_PAYLOAD_SIZE (sizeof(smartPortPayload_t) - sizeof(uint8_t))
#endif


// ../inav/src/main/telemetry/hott.c
#if defined(USE_TELEMETRY) && defined(USE_TELEMETRY_HOTT)
#if defined (USE_HOTT_TEXTMODE) && defined (USE_CMS)
#define HOTT_TEXTMODE_TASK_PERIOD 1000
#define HOTT_TEXTMODE_RX_SCHEDULE 5000
#define HOTT_TEXTMODE_TX_DELAY_US 1000
#endif
#define HOTT_MESSAGE_PREPARATION_FREQUENCY_5_HZ ((1000 * 1000) / 5)
#define HOTT_RX_SCHEDULE 4000
#define HOTT_TX_SCHEDULE 5000
#define HOTT_TX_DELAY_US 2000
#define MILLISECONDS_IN_A_SECOND 1000
#define HOTT_BAUDRATE 19200
#define HOTT_INITIAL_PORT_MODE MODE_RXTX
#endif


// ../inav/src/main/telemetry/msp_shared.c
#if defined(USE_MSP_OVER_TELEMETRY)
#define TELEMETRY_MSP_VERSION    2
#define TELEMETRY_MSP_RES_ERROR (-10)
#endif


// ../inav/src/main/telemetry/crsf.h
#define CRSF_MSP_RX_BUF_SIZE 128
#define CRSF_MSP_TX_BUF_SIZE 128


// ../inav/src/main/telemetry/hott.h
#define HOTTV4_RXTX 4
#define HOTTV4_TEXT_MODE_REQUEST_ID       0x7f
#define HOTTV4_BINARY_MODE_REQUEST_ID     0x80
#define HOTTV4_BUTTON_DEC    0xB
#define HOTTV4_BUTTON_INC    0xD
#define HOTTV4_BUTTON_SET    0x9
#define HOTTV4_BUTTON_NIL    0xF
#define HOTTV4_BUTTON_NEXT   0xE
#define HOTTV4_BUTTON_PREV   0x7
#define HOTT_EAM_OFFSET_HEIGHT       500
#define HOTT_EAM_OFFSET_M2S           72
#define HOTT_EAM_OFFSET_M3S          120
#define HOTT_EAM_OFFSET_TEMPERATURE   20
#define HOTT_GPS_ALTITUDE_OFFSET 500
#define HOTT_TEXT_MODE_REQUEST_ID   0x7f
#define HOTT_BINARY_MODE_REQUEST_ID 0x80
#define HOTT_TELEMETRY_NO_SENSOR_ID     0x80
#define HOTT_TELEMETRY_VARIO_SENSOR_ID  0x89
#define HOTT_TELEMETRY_GPS_SENSOR_ID    0x8a
#define HOTT_TELEMETRY_AIRESC_SENSOR_ID 0x8c
#define HOTT_TELEMETRY_GAM_SENSOR_ID    0x8d
#define HOTT_TELEMETRY_EAM_SENSOR_ID    0x8e
#define HOTT_EAM_SENSOR_TEXT_ID  0xE0
#define HOTT_GPS_SENSOR_TEXT_ID  0xA0
#define HOTT_TEXTMODE_DISPLAY_ROWS          8
#define HOTT_TEXTMODE_DISPLAY_COLUMNS       21
#define HOTT_TEXTMODE_START                 0x7B
#define HOTT_TEXTMODE_STOP                  0x7D
#define HOTT_TEXTMODE_ESC                   0x01
#define HOTT_VARIO_MSG_TEXT_LEN 21


// ../inav/src/main/telemetry/ltm.c
#if defined(USE_TELEMETRY_LTM)
#define TELEMETRY_LTM_INITIAL_PORT_MODE MODE_TX
#define LTM_CYCLETIME   100
#define LTM_SCHEDULE_SIZE (1000/LTM_CYCLETIME)
#define LTM_BIT_AFRAME  (1 << 0)
#define LTM_BIT_GFRAME  (1 << 1)
#define LTM_BIT_SFRAME  (1 << 2)
#define LTM_BIT_OFRAME  (1 << 3)
#define LTM_BIT_NFRAME  (1 << 4)
#define LTM_BIT_XFRAME  (1 << 5)
#endif


// ../inav/src/main/telemetry/ltm.h
#define LTM_GFRAME_PAYLOAD_SIZE 14
#define LTM_AFRAME_PAYLOAD_SIZE  6
#define LTM_SFRAME_PAYLOAD_SIZE  7
#define LTM_OFRAME_PAYLOAD_SIZE 14
#define LTM_NFRAME_PAYLOAD_SIZE  6
#define LTM_XFRAME_PAYLOAD_SIZE  6
#define LTM_MAX_PAYLOAD_SIZE 14
#define LTM_MAX_MESSAGE_SIZE (LTM_MAX_PAYLOAD_SIZE+4)


// ../inav/src/main/telemetry/ibus_shared.h
#define IBUS_TASK_PERIOD_US (500)
#define IBUS_BAUDRATE      (115200)
#define IBUS_CYCLE_TIME_MS (8)
#define IBUS_CHECKSUM_SIZE (2)
#define IBUS_MIN_LEN       (2 + IBUS_CHECKSUM_SIZE)
#define IBUS_MAX_TX_LEN    (6)
#define IBUS_MAX_RX_LEN    (4)
#define IBUS_RX_BUF_LEN    (IBUS_MAX_RX_LEN)


// ../inav/src/main/telemetry/ibus_shared.c
#if defined(USE_TELEMETRY) && defined(USE_TELEMETRY_IBUS)
#define IBUS_TEMPERATURE_OFFSET (0x0190)
#endif


// ../inav/src/main/telemetry/sim.c
#if defined(USE_TELEMETRY) && defined(USE_TELEMETRY_SIM)
#define SIM_AT_COMMAND_MAX_SIZE 255
#define SIM_RESPONSE_BUFFER_SIZE 255
#define SIM_CYCLE_MS 5000
#define SIM_AT_COMMAND_DELAY_MS 3000
#define SIM_AT_COMMAND_DELAY_MIN_MS 500
#define SIM_STARTUP_DELAY_MS 10000
#define SIM_SMS_COMMAND_RTH "RTH"
#define SIM_LOW_ALT_WARNING_MODES (NAV_ALTHOLD_MODE | NAV_RTH_MODE | NAV_WP_MODE | FAILSAFE_MODE)
#define SIM_RESPONSE_CODE_OK    ('O' << 24 | 'K' << 16)
#define SIM_RESPONSE_CODE_ERROR ('E' << 24 | 'R' << 16 | 'R' << 8 | 'O')
#define SIM_RESPONSE_CODE_RING  ('R' << 24 | 'I' << 16 | 'N' << 8 | 'G')
#define SIM_RESPONSE_CODE_CLIP  ('C' << 24 | 'L' << 16 | 'I' << 8 | 'P')
#define SIM_RESPONSE_CODE_CREG  ('C' << 24 | 'R' << 16 | 'E' << 8 | 'G')
#define SIM_RESPONSE_CODE_CSQ   ('C' << 24 | 'S' << 16 | 'Q' << 8 | ':')
#define SIM_RESPONSE_CODE_CMT   ('C' << 24 | 'M' << 16 | 'T' << 8 | ':')
#endif


// ../inav/src/main/telemetry/mavlink.c
#if defined(USE_TELEMETRY) && defined(USE_TELEMETRY_MAVLINK)
#define MAVLINK_COMM_NUM_BUFFERS 1
#define TELEMETRY_MAVLINK_PORT_MODE     MODE_RXTX
#define TELEMETRY_MAVLINK_MAXRATE       50
#define TELEMETRY_MAVLINK_DELAY         ((1000 * 1000) / TELEMETRY_MAVLINK_MAXRATE)
#define RADIANS_TO_MAVLINK_RANGE(angle) (angle > M_PIf) ? angle - (2 * M_PIf) : angle
#define MAXSTREAMS (sizeof(mavRates) / sizeof(mavRates[0]))
#define GET_CHANNEL_VALUE(x) ((rxRuntimeConfig.channelCount >= (x + 1)) ? rxGetChannelValue(x) : 0)
#endif


// ../inav/src/main/telemetry/jetiexbus.h
#define JETI_EXBUS_TELEMETRY_FRAME_LEN  128


// ../inav/src/main/telemetry/sim.h
#define SIM_MIN_TRANSMIT_INTERVAL 10u
#define SIM_DEFAULT_TRANSMIT_INTERVAL 60u
#define SIM_N_TX_FLAGS 5
#define SIM_DEFAULT_TX_FLAGS "f"
#define SIM_PIN "0000"


// ../inav/src/main/telemetry/sbus2.h
#define SBUS2_TELEMETRY_PAYLOAD_SIZE 3
#define SBUS2_TELEMETRY_ITEM_SIZE   3
#define SBUS2_TELEMETRY_SLOTS       8
#define SBUS2_TELEMETRY_PAGES       4
#define SBUS2_DEADTIME              MS2US(2)
#define SBUS2_SLOT_TIME             650u
#define SBUS2_TRANSMIT_TIME         ((8 + 1 + 2 + 1 + 1) * 3 * 10)
#define SBUS2_SLOT_DELAY            200
#define SBUS2_SLOT_COUNT            (SBUS2_TELEMETRY_PAGES * SBUS2_TELEMETRY_SLOTS)


// ../inav/src/main/telemetry/jetiexbus.c
#if defined(USE_TELEMETRY_JETIEXBUS)
#define EXTEL_DATA_MSG      (0x40)
#define EXTEL_UNMASK_TYPE   (0x3F)
#define EXTEL_SYNC_LEN      1
#define EXTEL_CRC_LEN       1
#define EXTEL_HEADER_LEN    6
#define EXTEL_MAX_LEN       26
#define EXTEL_OVERHEAD      (EXTEL_SYNC_LEN + EXTEL_HEADER_LEN + EXTEL_CRC_LEN)
#define EXTEL_MAX_PAYLOAD   (EXTEL_MAX_LEN - EXTEL_OVERHEAD)
#define EXBUS_MAX_REQUEST_BUFFER_SIZE   (EXBUS_OVERHEAD + EXTEL_MAX_LEN)
#define DECIMAL_MASK(decimals) (decimals << 5)
#define JETI_EX_SENSOR_COUNT (ARRAYLEN(jetiExSensors))
#endif


// ../inav/src/main/telemetry/ghst.c
#ifdef USE_TELEMETRY_GHST
#define GHST_CYCLETIME_US                   100000
#define GHST_FRAME_PACK_PAYLOAD_SIZE        10
#define GHST_FRAME_GPS_PAYLOAD_SIZE         10
#define GHST_FRAME_LENGTH_CRC               1
#define GHST_FRAME_LENGTH_TYPE              1
#endif


// ../inav/src/main/telemetry/srxl.h
#define SPEKTRUM_SRXL_TEXTGEN_BUFFER_ROWS 9
#define SPEKTRUM_SRXL_TEXTGEN_BUFFER_COLS 12
#define SPEKTRUM_SRXL_TEXTGEN_CLEAR_SCREEN 255


// ../inav/src/main/telemetry/smartport.h
#define SMARTPORT_MSP_TX_BUF_SIZE 256
#define SMARTPORT_MSP_RX_BUF_SIZE 64


// ../inav/src/main/telemetry/srxl.c
#if defined(USE_TELEMETRY_SRXL)
#define SRXL_ADDRESS_FIRST          0xA5
#define SRXL_ADDRESS_SECOND         0x80
#define SRXL_PACKET_LENGTH          0x15
#define SRXL_FRAMETYPE_TELE_QOS     0x7F
#define SRXL_FRAMETYPE_TELE_RPM     0x7E
#define SRXL_FRAMETYPE_POWERBOX     0x0A
#define SRXL_FRAMETYPE_TELE_FP_MAH  0x34
#define TELE_DEVICE_VTX             0x0D
#define SRXL_FRAMETYPE_SID          0x00
#define SRXL_FRAMETYPE_GPS_LOC      0x16
#define SRXL_FRAMETYPE_GPS_STAT     0x17
#define STRU_TELE_QOS_EMPTY_FIELDS_COUNT 14
#define STRU_TELE_QOS_EMPTY_FIELDS_VALUE 0xff
#define STRU_TELE_RPM_EMPTY_FIELDS_COUNT 8
#define STRU_TELE_RPM_EMPTY_FIELDS_VALUE 0x00
#define SPEKTRUM_RPM_UNUSED 0xffff
#define SPEKTRUM_TEMP_UNUSED 0x7fff
#define MICROSEC_PER_MINUTE 60000000
#define SPEKTRUM_MIN_RPM 999
#define SPEKTRUM_MAX_RPM 60000000
#if defined(USE_GPS)
#define GPS_FLAGS_IS_NORTH_BIT              0x01
#define GPS_FLAGS_IS_EAST_BIT               0x02
#define GPS_FLAGS_LONGITUDE_GREATER_99_BIT  0x04
#define GPS_FLAGS_GPS_FIX_VALID_BIT         0x08
#define GPS_FLAGS_GPS_DATA_RECEIVED_BIT     0x10
#define GPS_FLAGS_3D_FIX_BIT                0x20
#define GPS_FLAGS_NEGATIVE_ALT_BIT          0x80
#define STRU_TELE_GPS_STAT_EMPTY_FIELDS_VALUE 0xff
#define STRU_TELE_GPS_STAT_EMPTY_FIELDS_COUNT 6
#define SPEKTRUM_TIME_UNKNOWN 0xFFFFFFFF
#endif
#define STRU_TELE_FP_EMPTY_FIELDS_COUNT 2
#define STRU_TELE_FP_EMPTY_FIELDS_VALUE 0xff
#define SPEKTRUM_AMPS_UNUSED 0x7fff
#define SPEKTRUM_AMPH_UNUSED 0x7fff
#define FP_MAH_KEEPALIVE_TIME_OUT 2000000
#if defined (USE_SPEKTRUM_CMS_TELEMETRY) && defined (USE_CMS)
#define SPEKTRUM_SRXL_DEVICE_TEXTGEN (0x0C)
#define SPEKTRUM_SRXL_DEVICE_TEXTGEN_ROWS (9)
#define SPEKTRUM_SRXL_DEVICE_TEXTGEN_COLS (13)
#define STRU_TELE_VTX_EMPTY_COUNT 7
#define STRU_TELE_VTX_EMPTY_VALUE 0xff
#define VTX_KEEPALIVE_TIME_OUT 2000000
#endif
#define SRXL_SCHEDULE_MANDATORY_COUNT  2
#define SRXL_FP_MAH_COUNT   1
#if defined(USE_GPS)
#define SRXL_GPS_LOC_COUNT  1
#define SRXL_GPS_STAT_COUNT 1
#else
#define SRXL_GPS_LOC_COUNT  0
#define SRXL_GPS_STAT_COUNT 0
#endif
#if defined (USE_SPEKTRUM_CMS_TELEMETRY) && defined (USE_CMS)
#define SRXL_SCHEDULE_CMS_COUNT  1
#else
#define SRXL_SCHEDULE_CMS_COUNT  0
#endif
#if defined(USE_SPEKTRUM_VTX_TELEMETRY) && defined(USE_SPEKTRUM_VTX_CONTROL) && defined(USE_VTX_COMMON)
#define SRXL_VTX_TM_COUNT        1
#else
#define SRXL_VTX_TM_COUNT        0
#endif
#define SRXL_SCHEDULE_USER_COUNT (SRXL_FP_MAH_COUNT + SRXL_SCHEDULE_CMS_COUNT + SRXL_VTX_TM_COUNT + SRXL_GPS_LOC_COUNT + SRXL_GPS_STAT_COUNT)
#define SRXL_SCHEDULE_COUNT_MAX  (SRXL_SCHEDULE_MANDATORY_COUNT + 1)
#define SRXL_TOTAL_COUNT         (SRXL_SCHEDULE_MANDATORY_COUNT + SRXL_SCHEDULE_USER_COUNT)
#endif


// ../inav/src/main/io/gps.h
#define GPS_DBHZ_MIN 0
#define GPS_DBHZ_MAX 55
#define LAT 0
#define LON 1
#define GPS_DEGREES_DIVIDER 10000000L
#define SBAS_MODE_MAX SBAS_GAGAN
#define GPS_BAUDRATE_MAX GPS_BAUDRATE_9600
#define HDOP_SCALE (100)


// ../inav/src/main/io/vtx_msp.h
#ifndef _VTX_MSP_H
#define _VTX_MSP_H
#define VTX_MSP_TIMEOUT         250
#define VTX_MSP_BAND_COUNT      5
#define VTX_MSP_CHANNEL_COUNT   8
#define VTX_MSP_POWER_COUNT     4
#endif


// ../inav/src/main/io/gimbal_serial.h
#ifdef USE_SERIAL_GIMBAL
#define HTKATTITUDE_SYNC0  0xA5
#define HTKATTITUDE_SYNC1  0x5A
#define HEADTRACKER_PAYLOAD_SIZE (sizeof(gimbalHtkAttitudePkt_t) - 4)
#endif


// ../inav/src/main/io/osd_dji_hd.c
#if defined(USE_DJI_HD_OSD)
#define RC_RX_LINK_LOST_MSG "!RC RX LINK LOST!"
#define OSD_MESSAGE_LENGTH 28
#define OSD_ALTERNATING_CHOICES(ms, num_choices) ((millis() / ms) % num_choices)
#define _CONST_STR_SIZE(s) ((sizeof(s)/sizeof(s[0]))-1)
#define OSD_MESSAGE_STR(x) ({ \
    STATIC_ASSERT(_CONST_STR_SIZE(x) <= OSD_MESSAGE_LENGTH, message_string_ ## __COUNTER__ ## _too_long); \
    x; \
})
#define RSSI_BOUNDARY(PERCENT) (RSSI_MAX_VALUE / 100 * PERCENT)
#endif


// ../inav/src/main/io/displayport_msp.c
#ifdef USE_MSP_DISPLAYPORT
#define MSP_OSD_MAX_STRING_LENGTH 30
#endif


// ../inav/src/main/io/serial_4way.c
#ifdef  USE_SERIAL_4WAY_BLHELI_INTERFACE
#if defined(USE_HAL_DRIVER)
#define Bit_RESET GPIO_PIN_RESET
#elif defined(AT32F43x)
#define Bit_RESET 0U
#endif
#define USE_TXRX_LED
#ifdef  USE_TXRX_LED
#define RX_LED_OFF LED0_OFF
#define RX_LED_ON LED0_ON
#ifdef  LED1
#define TX_LED_OFF LED1_OFF
#define TX_LED_ON LED1_ON
#else
#define TX_LED_OFF LED0_OFF
#define TX_LED_ON LED0_ON
#endif
#else
#define RX_LED_OFF
#define RX_LED_ON
#define TX_LED_OFF
#define TX_LED_ON
#endif
#define SERIAL_4WAY_INTERFACE_NAME_STR "m4wFCIntf"
#define SERIAL_4WAY_VER_MAIN 20
#define SERIAL_4WAY_VER_SUB_1 (uint8_t) 0
#define SERIAL_4WAY_VER_SUB_2 (uint8_t) 05
#define SERIAL_4WAY_PROTOCOL_VER 107
#define SERIAL_4WAY_VERSION (uint16_t) ((SERIAL_4WAY_VER_MAIN * 1000) + (SERIAL_4WAY_VER_SUB_1 * 100) + SERIAL_4WAY_VER_SUB_2)
#define SERIAL_4WAY_VERSION_HI (uint8_t) (SERIAL_4WAY_VERSION / 100)
#define SERIAL_4WAY_VERSION_LO (uint8_t) (SERIAL_4WAY_VERSION % 100)
#define DeviceInfoSize 4
#define SET_DISCONNECTED DeviceInfo.words[0] = 0
#define INTF_MODE_IDX 3
#define cmd_Remote_Escape 0x2E
#define cmd_Local_Escape  0x2F
#define cmd_InterfaceTestAlive 0x30
#define cmd_ProtocolGetVersion 0x31
#define cmd_InterfaceGetName 0x32
#define cmd_InterfaceGetVersion 0x33
#define cmd_InterfaceExit 0x34
#define cmd_DeviceReset 0x35
#define cmd_DeviceInitFlash 0x37
#define cmd_DeviceEraseAll 0x38
#define cmd_DevicePageErase 0x39
#define cmd_DeviceRead 0x3A
#define cmd_DeviceWrite 0x3B
#define cmd_DeviceC2CK_LOW 0x3C
#define cmd_DeviceReadEEprom 0x3D
#define cmd_DeviceWriteEEprom 0x3E
#define cmd_InterfaceSetMode 0x3F
#define cmd_DeviceVerify 0x40
#define ACK_OK                  0x00
#define ACK_I_INVALID_CMD       0x02
#define ACK_I_INVALID_CRC       0x03
#define ACK_I_VERIFY_ERROR      0x04
#define ACK_I_INVALID_CHANNEL   0x08
#define ACK_I_INVALID_PARAM     0x09
#define ACK_D_GENERAL_ERROR     0x0F
#define ATMEL_DEVICE_MATCH ((pDeviceInfo->words[0] == 0x9307) || (pDeviceInfo->words[0] == 0x930A) || \
        (pDeviceInfo->words[0] == 0x930F) || (pDeviceInfo->words[0] == 0x940B))
#define SILABS_DEVICE_MATCH ((pDeviceInfo->words[0] == 0xF310)||(pDeviceInfo->words[0] == 0xF330) || \
        (pDeviceInfo->words[0] == 0xF410) || (pDeviceInfo->words[0] == 0xF390) || \
        (pDeviceInfo->words[0] == 0xF850) || (pDeviceInfo->words[0] == 0xE8B1) || \
        (pDeviceInfo->words[0] == 0xE8B2))
#define ARM_DEVICE_MATCH ((pDeviceInfo->bytes[1] > 0x00) && (pDeviceInfo->bytes[1] < 0x90) && (pDeviceInfo->bytes[0] == 0x06))
#endif


// ../inav/src/main/io/vtx_tramp.c
#if defined(USE_VTX_TRAMP) && defined(USE_VTX_CONTROL)
#define VTX_PKT_SIZE                16
#define VTX_PROTO_STATE_TIMEOUT_MS  1000
#define VTX_STATUS_INTERVAL_MS      2000
#define VTX_UPDATE_REQ_NONE         0x00
#define VTX_UPDATE_REQ_FREQUENCY    0x01
#define VTX_UPDATE_REQ_POWER        0x02
#define VTX_UPDATE_REQ_PITMODE      0x04
#endif


// ../inav/src/main/io/serial_4way_impl.h
#define ESC_IS_HI  isEscHi(selected_esc)
#define ESC_IS_LO  isEscLo(selected_esc)
#define ESC_SET_HI setEscHi(selected_esc)
#define ESC_SET_LO setEscLo(selected_esc)
#define ESC_INPUT  setEscInput(selected_esc)
#define ESC_OUTPUT setEscOutput(selected_esc)


// ../inav/src/main/io/serial.h
#define FUNCTION_VTX_MSP FUNCTION_MSP_OSD


// ../inav/src/main/io/rcdevice.h
#define RCDEVICE_PROTOCOL_HEADER                                    0xCC
#define RCDEVICE_PROTOCOL_MAX_PACKET_SIZE                           64
#define RCDEVICE_PROTOCOL_MAX_DATA_SIZE                             20
#define RCDEVICE_PROTOCOL_COMMAND_GET_DEVICE_INFO                   0x00
#define RCDEVICE_PROTOCOL_COMMAND_CAMERA_CONTROL                    0x01
#define RCDEVICE_PROTOCOL_COMMAND_5KEY_SIMULATION_PRESS             0x02
#define RCDEVICE_PROTOCOL_COMMAND_5KEY_SIMULATION_RELEASE           0x03
#define RCDEVICE_PROTOCOL_COMMAND_5KEY_CONNECTION                   0x04
#define RCSPLIT_PACKET_HEADER           0x55
#define RCSPLIT_PACKET_CMD_CTRL  0x01
#define RCSPLIT_PACKET_TAIL     0xaa
#define MAX_WAITING_RESPONSES 2


// ../inav/src/main/io/osd_common.c
#if defined(USE_OSD)
#define CANVAS_DEFAULT_GRID_ELEMENT_WIDTH OSD_CHAR_WIDTH
#define CANVAS_DEFAULT_GRID_ELEMENT_HEIGHT OSD_CHAR_HEIGHT
#endif


// ../inav/src/main/io/servo_sbus.c
#if defined(USE_SERVO_SBUS)
#define SERVO_SBUS_UART_BAUD            100000
#define SERVO_SBUS_OPTIONS              (SBUS_PORT_OPTIONS | SERIAL_INVERTED | SERIAL_UNIDIR)
#endif


// ../inav/src/main/io/vtx_msp.c
#if defined(USE_VTX_MSP) && defined(USE_VTX_CONTROL) && defined(USE_VTX_COMMON)
#define VTX_MSP_MIN_BAND           (1)
#define VTX_MSP_MAX_BAND           (VTX_MSP_MIN_BAND + VTX_MSP_BAND_COUNT - 1)
#define VTX_MSP_MIN_CHANNEL        (1)
#define VTX_MSP_MAX_CHANNEL        (VTX_MSP_MIN_CHANNEL + VTX_MSP_CHANNEL_COUNT -1)
#define VTX_UPDATE_REQ_NONE         0x00
#define VTX_UPDATE_REQ_FREQUENCY    0x01
#define VTX_UPDATE_REQ_POWER        0x02
#define VTX_UPDATE_REQ_PIT_MODE     0x04
#endif


// ../inav/src/main/io/frsky_osd.c
#if defined(USE_OSD) && defined(USE_FRSKYOSD)
#define FRSKY_OSD_DEFAULT_BAUDRATE_INDEX BAUD_115200
#define FRSKY_OSD_SUPPORTED_API_VERSION 2
#define FRSKY_OSD_PREAMBLE_BYTE_0 '$'
#define FRSKY_OSD_PREAMBLE_BYTE_1 'A'
#define FRSKY_OSD_GRID_BUFFER_CHAR_BITS 9
#define FRSKY_OSD_GRID_BUFFER_CHAR_MASK ((1 << FRSKY_OSD_GRID_BUFFER_CHAR_BITS) - 1)
#define FRSKY_OSD_GRID_BUFFER_ENCODE(chr, attr) ((chr & FRSKY_OSD_GRID_BUFFER_CHAR_MASK) | (attr << FRSKY_OSD_GRID_BUFFER_CHAR_BITS))
#define FRSKY_OSD_CHAR_ATTRIBUTE_COLOR_INVERSE (1 << 0)
#define FRSKY_OSD_CHAR_ATTRIBUTE_SOLID_BACKGROUND (1 << 1)
#define FRSKY_OSD_CHAR_DATA_BYTES 54
#define FRSKY_OSD_CHAR_METADATA_BYTES 10
#define FRSKY_OSD_CHAR_TOTAL_BYTES (FRSKY_OSD_CHAR_DATA_BYTES + FRSKY_OSD_CHAR_METADATA_BYTES)
#define FRSKY_OSD_SEND_BUFFER_SIZE 192
#define FRSKY_OSD_RECV_BUFFER_SIZE 128
#define FRSKY_OSD_CMD_RESPONSE_ERROR 0
#define FRSKY_OSD_INFO_INTERVAL_MS 100
#define FRSKY_OSD_INFO_READY_INTERVAL_MS 5000
#define FRSKY_OSD_TRACE(fmt, ...)
#define FRSKY_OSD_DEBUG(fmt, ...) LOG_DEBUG(OSD, "FrSky OSD: " fmt,  ##__VA_ARGS__)
#define FRSKY_OSD_ERROR(fmt, ...) LOG_ERROR(OSD, "FrSky OSD: " fmt,  ##__VA_ARGS__)
#define FRSKY_OSD_ASSERT(x)
#endif


// ../inav/src/main/io/rangefinder_nanoradar.c
#if defined(USE_RANGEFINDER_NANORADAR)
#define NANORADAR_HDR 0xAA
#define NANORADAR_END 0x55
#define NANORADAR_COMMAND_TARGET_INFO 0x70C
#define NANORADAR_PACKET_SIZE    sizeof(nanoradarPacket_t)
#define NANORADAR_TIMEOUT_MS     2000
#endif


// ../inav/src/main/io/vtx_control.h
#define MAX_CHANNEL_ACTIVATION_CONDITION_COUNT  10


// ../inav/src/main/io/osd.c
#ifdef USE_OSD
#define VIDEO_BUFFER_CHARS_PAL    480
#define VIDEO_BUFFER_CHARS_HDZERO 900
#define VIDEO_BUFFER_CHARS_DJIWTF 1320
#define GFORCE_FILTER_TC 0.2
#define OSD_STATS_SINGLE_PAGE_MIN_ROWS 18
#define IS_HI(X)  (rxGetChannelValue(X) > 1750)
#define IS_LO(X)  (rxGetChannelValue(X) < 1250)
#define IS_MID(X) (rxGetChannelValue(X) > 1250 && rxGetChannelValue(X) < 1750)
#define OSD_RESUME_UPDATES_STICK_COMMAND (checkStickPosition(THR_HI) || checkStickPosition(PIT_HI))
#define STATS_PAGE2 (checkStickPosition(ROL_HI))
#define STATS_PAGE1 (checkStickPosition(ROL_LO))
#define SPLASH_SCREEN_DISPLAY_TIME 4000
#define STATS_SCREEN_DISPLAY_TIME 60000
#define EFFICIENCY_UPDATE_INTERVAL (5 * 1000)
#define OSD_MESSAGE_LENGTH 28
#define OSD_ALTERNATING_CHOICES(ms, num_choices) ((millis() / ms) % num_choices)
#define _CONST_STR_SIZE(s) ((sizeof(s)/sizeof(s[0]))-1)
#define OSD_MESSAGE_STR(x) ({ \
    STATIC_ASSERT(_CONST_STR_SIZE(x) <= OSD_MESSAGE_LENGTH, message_string_ ## __COUNTER__ ## _too_long); \
    x; \
})
#define OSD_CHR_IS_NUM(c) (c >= '0' && c <= '9')
#define OSD_CENTER_LEN(x) ((osdDisplayPort->cols - x) / 2)
#define OSD_CENTER_S(s) OSD_CENTER_LEN(strlen(s))
#define OSD_MIN_FONT_VERSION 3
#if defined(USE_CANVAS)
#else
#define osdDisplayHasCanvas false
#endif
#define AH_MAX_PITCH_DEFAULT 20
#define DRAW_FREQ_DENOM     4
#define STATS_FREQ_DENOM    50
#define WARNING_REDISPLAY_DURATION 5000;
#endif


// ../inav/src/main/io/osd_canvas.c
#if defined(USE_CANVAS)
#define AHI_MIN_DRAW_INTERVAL_MS 50
#define AHI_MAX_DRAW_INTERVAL_MS 1000
#define AHI_CROSSHAIR_MARGIN 6
#define SIDEBAR_REDRAW_INTERVAL_MS 100
#define WIDGET_SIDEBAR_LEFT_INSTANCE 0
#define WIDGET_SIDEBAR_RIGHT_INSTANCE 1
#define OSD_CANVAS_VARIO_ARROWS_PER_SLOT 2.0f
#endif


// ../inav/src/main/io/serial.c
#define BAUD_RATE_COUNT ARRAYLEN(baudRates)
#define ALL_TELEMETRY_FUNCTIONS_MASK (FUNCTION_TELEMETRY_HOTT | FUNCTION_TELEMETRY_SMARTPORT | FUNCTION_TELEMETRY_LTM | FUNCTION_TELEMETRY_MAVLINK | FUNCTION_TELEMETRY_IBUS)
#define ALL_FUNCTIONS_SHARABLE_WITH_MSP (FUNCTION_BLACKBOX | ALL_TELEMETRY_FUNCTIONS_MASK | FUNCTION_LOG)


// ../inav/src/main/io/gps_ublox.h
#define GPS_CFG_CMD_TIMEOUT_MS              500
#define GPS_VERSION_RETRY_TIMES             3
#ifndef UBLOX_MAX_SIGNALS
#define UBLOX_MAX_SIGNALS                   64
#endif
#define MAX_UBLOX_PAYLOAD_SIZE              ((UBLOX_MAX_SIGNALS * 16) + 8)
#define UBLOX_BUFFER_SIZE                   MAX_UBLOX_PAYLOAD_SIZE
#define UBLOX_SBAS_MESSAGE_LENGTH           16
#define GPS_CAPA_INTERVAL                   5000
#define UBX_DYNMODEL_PORTABLE   0
#define UBX_DYNMODEL_STATIONARY 2
#define UBX_DYNMODEL_PEDESTRIAN 3
#define UBX_DYNMODEL_AUTOMOVITE 4
#define UBX_DYNMODEL_SEA        5
#define UBX_DYNMODEL_AIR_1G     6
#define UBX_DYNMODEL_AIR_2G     7
#define UBX_DYNMODEL_AIR_4G     8
#define UBX_DYNMODEL_WRIST      9
#define UBX_DYNMODEL_BIKE       10
#define UBX_DYNMODEL_MOWER      11
#define UBX_DYNMODEL_ESCOOTER   12
#define UBX_FIXMODE_2D_ONLY 1
#define UBX_FIXMODE_3D_ONLY 2
#define UBX_FIXMODE_AUTO    3
#define UBX_VALID_GPS_DATE(valid) (valid & 1 << 0)
#define UBX_VALID_GPS_TIME(valid) (valid & 1 << 1)
#define UBX_VALID_GPS_DATE_TIME(valid) (UBX_VALID_GPS_DATE(valid) && UBX_VALID_GPS_TIME(valid))
#define UBX_HW_VERSION_UNKNOWN  0
#define UBX_HW_VERSION_UBLOX5   500
#define UBX_HW_VERSION_UBLOX6   600
#define UBX_HW_VERSION_UBLOX7   700
#define UBX_HW_VERSION_UBLOX8   800
#define UBX_HW_VERSION_UBLOX9   900
#define UBX_HW_VERSION_UBLOX10  1000
#define UBLOX_CFG_MSGOUT_NAV_POSLLH_UART1   0x2091002a
#define UBLOX_CFG_MSGOUT_NAV_SAT_UART1      0x20910016
#define UBLOX_CFG_MSGOUT_NAV_SIG_UART1      0x20910346
#define UBLOX_CFG_MSGOUT_NAV_STATUS_UART1   0x2091001b
#define UBLOX_CFG_MSGOUT_NAV_VELNED_UART1   0x20910043
#define UBLOX_CFG_MSGOUT_NAV_TIMEUTC_UART1  0x2091005c
#define UBLOX_CFG_MSGOUT_NAV_PVT_UART1      0x20910007
#define UBLOX_CFG_MSGOUT_NMEA_ID_GGA_UART1  0x209100bb
#define UBLOX_CFG_MSGOUT_NMEA_ID_GLL_UART1  0x209100ca
#define UBLOX_CFG_MSGOUT_NMEA_ID_GSA_UART1  0x209100c0
#define UBLOX_CFG_MSGOUT_NMEA_ID_RMC_UART1  0x209100ac
#define UBLOX_CFG_MSGOUT_NMEA_ID_VTG_UART1  0x209100b1
#define UBLOX_CFG_NAVSPG_FIXMODE            0x20110011
#define UBLOX_CFG_NAVSPG_DYNMODEL           0x20110021
#define UBLOX_CFG_RATE_MEAS                 0x30210001
#define UBLOX_CFG_RATE_NAV                  0x30210002
#define UBLOX_CFG_RATE_TIMEREF              0x30210002
#define UBLOX_CFG_SIGNAL_SBAS_ENA       0x10310020
#define UBLOX_CFG_SIGNAL_SBAS_L1CA_ENA  0x10310005
#define UBLOX_CFG_SIGNAL_GAL_ENA        0x10310021
#define UBLOX_CFG_SIGNAL_GAL_E1_ENA     0x10310007
#define UBLOX_CFG_SIGNAL_BDS_ENA        0x10310022
#define UBLOX_CFG_SIGNAL_BDS_B1_ENA     0x1031000d
#define UBLOX_CFG_SIGNAL_BDS_B1C_ENA    0x1031000f
#define UBLOX_CFG_QZSS_ENA              0x10310024
#define UBLOX_CFG_QZSS_L1CA_ENA         0x10310012
#define UBLOX_CFG_QZSS_L1S_ENA          0x10310014
#define UBLOX_CFG_GLO_ENA               0x10310025
#define UBLOX_CFG_GLO_L1_ENA            0x10310018
#define UBLOX_CFG_SBAS_PRNSCANMASK      0x50360006
#define UBLOX_SBAS_ALL                  0x0000000000000000
#define UBLOX_SBAS_PRN120               0x0000000000000001
#define UBLOX_SBAS_PRN121               0x0000000000000002
#define UBLOX_SBAS_PRN122               0x0000000000000004
#define UBLOX_SBAS_PRN123               0x0000000000000008
#define UBLOX_SBAS_PRN124               0x0000000000000010
#define UBLOX_SBAS_PRN125               0x0000000000000020
#define UBLOX_SBAS_PRN126               0x0000000000000040
#define UBLOX_SBAS_PRN127               0x0000000000000080
#define UBLOX_SBAS_PRN128               0x0000000000000100
#define UBLOX_SBAS_PRN129               0x0000000000000200
#define UBLOX_SBAS_PRN130               0x0000000000000400
#define UBLOX_SBAS_PRN131               0x0000000000000800
#define UBLOX_SBAS_PRN132               0x0000000000001000
#define UBLOX_SBAS_PRN133               0x0000000000002000
#define UBLOX_SBAS_PRN134               0x0000000000004000
#define UBLOX_SBAS_PRN135               0x0000000000008000
#define UBLOX_SBAS_PRN136               0x0000000000010000
#define UBLOX_SBAS_PRN137               0x0000000000020000
#define UBLOX_SBAS_PRN138               0x0000000000040000
#define UBLOX_SBAS_PRN139               0x0000000000080000
#define UBLOX_SBAS_PRN140               0x0000000000100000
#define UBLOX_SBAS_PRN141               0x0000000000200000
#define UBLOX_SBAS_PRN142               0x0000000000400000
#define UBLOX_SBAS_PRN143               0x0000000000800000
#define UBLOX_SBAS_PRN144               0x0000000001000000
#define UBLOX_SBAS_PRN145               0x0000000002000000
#define UBLOX_SBAS_PRN146               0x0000000004000000
#define UBLOX_SBAS_PRN147               0x0000000008000000
#define UBLOX_SBAS_PRN148               0x0000000010000000
#define UBLOX_SBAS_PRN149               0x0000000020000000
#define UBLOX_SBAS_PRN150               0x0000000040000000
#define UBLOX_SBAS_PRN151               0x0000000080000000
#define UBLOX_SBAS_PRN152               0x0000000100000000
#define UBLOX_SBAS_PRN153               0x0000000200000000
#define UBLOX_SBAS_PRN154               0x0000000400000000
#define UBLOX_SBAS_PRN155               0x0000000800000000
#define UBLOX_SBAS_PRN156               0x0000001000000000
#define UBLOX_SBAS_PRN157               0x0000002000000000
#define UBLOX_SBAS_PRN158               0x0000004000000000
#define UBLOX_SIG_HEALTH_MASK   (BIT(0) | BIT(1))
#define UBLOX_SIG_PRSMOOTHED    (BIT(2))
#define UBLOX_SIG_PRUSED        (BIT(3))
#define UBLOX_SIG_CRUSED        (BIT(4))
#define UBLOX_SIG_DOUSED        (BIT(5))
#define UBLOX_SIG_PRCORRUSED    (BIT(6))
#define UBLOX_SIG_CRCORRUSED    (BIT(7))
#define UBLOX_SIG_DOCORRUSED    (BIT(8))
#define UBLOX_SIG_AUTHSTATUS    (BIT(9))
#define MAX_GNSS 7
#define MAX_GNSS_SIZE_BYTES (sizeof(ubx_gnss_msg_t) + sizeof(ubx_gnss_element_t)*MAX_GNSS)
#define MAX_CONFIG_SET_VAL_VALUES   32
#define UBX_MON_GNSS_GPS_MASK       (1 << 0)
#define UBX_MON_GNSS_GLONASS_MASK   (1 << 1)
#define UBX_MON_GNSS_BEIDOU_MASK    (1 << 2)
#define UBX_MON_GNSS_GALILEO_MASK   (1 << 3)


// ../inav/src/main/io/opflow_cxof.c
#if defined(USE_OPFLOW_CXOF)
#define CXOF_PACKET_SIZE    9
#endif


// ../inav/src/main/io/dashboard.c
#ifdef USE_DASHBOARD
#define MICROSECONDS_IN_A_SECOND (1000 * 1000)
#define DASHBOARD_UPDATE_FREQUENCY (MICROSECONDS_IN_A_SECOND / 5)
#define PAGE_CYCLE_FREQUENCY (MICROSECONDS_IN_A_SECOND * 5)
#define PAGE_TITLE_LINE_COUNT 1
#define HALF_SCREEN_CHARACTER_COLUMN_COUNT (SCREEN_CHARACTER_COLUMN_COUNT / 2)
#define IS_SCREEN_CHARACTER_COLUMN_COUNT_ODD (SCREEN_CHARACTER_COLUMN_COUNT & 1)
#define TICKER_CHARACTER_COUNT (sizeof(tickerCharacters) / sizeof(char))
#endif


// ../inav/src/main/io/osd_common.h
#define OSD_VARIO_CM_S_PER_ARROW 50
#define OSD_VARIO_HEIGHT_ROWS 5
#define OSD_THROTTLE_GAUGE_HEIGHT_ROWS 5
#define OSD_AHI_HEIGHT 9
#define OSD_AHI_WIDTH 11
#define OSD_AHI_PREV_SIZE (OSD_AHI_WIDTH > OSD_AHI_HEIGHT ? OSD_AHI_WIDTH : OSD_AHI_HEIGHT)
#define OSD_AHI_H_SYM_COUNT 9
#define OSD_AHI_V_SYM_COUNT 6
#define OSD_HEADING_GRAPH_WIDTH 9
#define OSD_HEADING_GRAPH_DECIDEGREES_PER_CHAR 225
#define OSD_AH_SIDEBAR_WIDTH_POS 7
#define OSD_AH_SIDEBAR_HEIGHT_POS 3
#define OSD_DRAW_POINT_GRID(_x, _y) (&(osdDrawPoint_t){ .type = OSD_DRAW_POINT_TYPE_GRID, .grid = {.gx = (_x), .gy = (_y)}})
#define OSD_DRAW_POINT_PIXEL(_x, _y) (&(osdDrawPoint_t){ .type = OSD_DRAW_POINT_TYPE_PIXEL, .pixel = {.px = (_x), .py = (_y)}})


// ../inav/src/main/io/vtx_string.c
#define VTX_STRING_5G8_BAND_COUNT  5
#define VTX_STRING_5G8_CHAN_COUNT  8
#define VTX_STRING_5G8_POWER_COUNT 5
#define VTX_STRING_1G3_BAND_COUNT  2
#define VTX_STRING_1G3_CHAN_COUNT  8
#define VTX_STRING_1G3_POWER_COUNT 3


// ../inav/src/main/io/osd_dji_hd.h
#if defined(USE_DJI_HD_OSD)
#define DJI_API_VERSION_MAJOR           1
#define DJI_API_VERSION_MINOR           42
#define DJI_MSP_API_VERSION             1
#define DJI_MSP_FC_VARIANT              2
#define DJI_MSP_FC_VERSION              3
#define DJI_MSP_NAME                    10
#define DJI_MSP_OSD_CONFIG              84
#define DJI_MSP_FILTER_CONFIG           92
#define DJI_MSP_PID_ADVANCED            94
#define DJI_MSP_STATUS                  101
#define DJI_MSP_RC                      105
#define DJI_MSP_RAW_GPS                 106
#define DJI_MSP_COMP_GPS                107
#define DJI_MSP_ATTITUDE                108
#define DJI_MSP_ALTITUDE                109
#define DJI_MSP_ANALOG                  110
#define DJI_MSP_RC_TUNING               111
#define DJI_MSP_PID                     112
#define DJI_MSP_BATTERY_STATE           130
#define DJI_MSP_ESC_SENSOR_DATA         134
#define DJI_MSP_STATUS_EX               150
#define DJI_MSP_RTC                     247
#define DJI_MSP_SET_FILTER_CONFIG       93
#define DJI_MSP_SET_PID_ADVANCED        95
#define DJI_MSP_SET_PID                 202
#define DJI_MSP_SET_RC_TUNING           204
#define DJI_CRAFT_NAME_LENGTH           24
#define DJI_ALTERNATING_DURATION_LONG   (djiOsdConfig()->craftNameAlternatingDuration * 100)
#define DJI_ALTERNATING_DURATION_SHORT  1000
#define DJI_MSP_BAUDRATE                    115200
#define DJI_ARMING_DISABLE_FLAGS_COUNT      25
#define DJI_OSD_WARNING_COUNT               16
#define DJI_OSD_TIMER_COUNT                 2
#define DJI_OSD_FLAGS_OSD_FEATURE           (1 << 0)
#define EFFICIENCY_UPDATE_INTERVAL          (5 * 1000)
#endif


// ../inav/src/main/io/vtx_ffpv24g.h
#define VTX_FFPV_BAND_COUNT         2
#define VTX_FFPV_CHANNEL_COUNT      8
#define VTX_FFPV_POWER_COUNT        4


// ../inav/src/main/io/ledstrip.h
#define LED_MAX_STRIP_LENGTH           128
#define LED_CONFIGURABLE_COLOR_COUNT   16
#define LED_MODE_COUNT                  6
#define LED_DIRECTION_COUNT             6
#define LED_BASEFUNCTION_COUNT          8
#define LED_OVERLAY_COUNT               7
#define LED_SPECIAL_COLOR_COUNT         9
#define LED_FUNCTION_OFFSET             8
#define LED_OVERLAY_OFFSET             16
#define LED_POS_BITCNT                  8
#define LED_FUNCTION_BITCNT             8
#define LED_OVERLAY_BITCNT              8
#define LED_COLOR_BITCNT                4
#define LED_DIRECTION_BITCNT            6
#define LED_PARAMS_BITCNT               6
#define LED_FLAG_OVERLAY_MASK ((1 << LED_OVERLAY_BITCNT) - 1)
#define LED_MOV_FUNCTION(func) ((func) << LED_FUNCTION_OFFSET)
#define LED_MOV_OVERLAY(overlay) ((overlay) << LED_OVERLAY_OFFSET)
#define LED_FUNCTION_MASK LED_MOV_FUNCTION(((1 << LED_FUNCTION_BITCNT) - 1))
#define LED_OVERLAY_MASK LED_MOV_OVERLAY(LED_FLAG_OVERLAY_MASK)
#define LED_FLAG_OVERLAY(id) (1 << (id))
#define LED_FLAG_DIRECTION(id) (1 << (id))
#define LED_X_BIT_OFFSET 4
#define LED_Y_BIT_OFFSET 0
#define LED_XY_MASK      0x0F
#define CALCULATE_LED_XY(x, y) ((((x) & LED_XY_MASK) << LED_X_BIT_OFFSET) | (((y) & LED_XY_MASK) << LED_Y_BIT_OFFSET))
#define DEFINE_LED(ledConfigPtr, x, y, col, dir, func, ol, params) { \
  (ledConfigPtr)->led_position = CALCULATE_LED_XY(x, y); \
  (ledConfigPtr)->led_color = (col); \
  (ledConfigPtr)->led_direction = (dir); \
  (ledConfigPtr)->led_function = (func); \
  (ledConfigPtr)->led_overlay = (ol); \
  (ledConfigPtr)->led_params = (params); }


// ../inav/src/main/io/beeper.c
#define MAX_MULTI_BEEPS 20
#define BEEPER_COMMAND_REPEAT 0xFE
#define BEEPER_COMMAND_STOP   0xFF
#define BEEPER_CONFIRMATION_BEEP_DURATION 2
#define BEEPER_CONFIRMATION_BEEP_GAP_DURATION 20
#define BEEPER_ENTRY(a,b,c,d) a,b,c,d
#define BEEPER_TABLE_ENTRY_COUNT (sizeof(beeperTable) / sizeof(beeperTableEntry_t))


// ../inav/src/main/io/vtx_tramp.h
#define VTX_TRAMP_5G8_BAND_COUNT        5
#define VTX_TRAMP_5G8_CHANNEL_COUNT     8
#define VTX_TRAMP_5G8_MAX_POWER_COUNT   5
#define VTX_TRAMP_5G8_DEFAULT_POWER     1
#define VTX_TRAMP_5G8_MIN_FREQUENCY_MHZ 5000
#define VTX_TRAMP_5G8_MAX_FREQUENCY_MHZ 5999
#define VTX_TRAMP_1G3_BAND_COUNT        2
#define VTX_TRAMP_1G3_CHANNEL_COUNT     8
#define VTX_TRAMP_1G3_MAX_POWER_COUNT   3
#define VTX_TRAMP_1G3_DEFAULT_POWER     1
#define VTX_TRAMP_1G3_MIN_FREQUENCY_MHZ 1000
#define VTX_TRAMP_1G3_MAX_FREQUENCY_MHZ 1399


// ../inav/src/main/io/osd_hud.c
#ifdef USE_OSD
#define HUD_DRAWN_MAXCHARS 54
#endif


// ../inav/src/main/io/serial_4way.h
#define USE_SERIAL_4WAY_BLHELI_BOOTLOADER
#define USE_SERIAL_4WAY_SK_BOOTLOADER
#define imC2 0
#define imSIL_BLB 1
#define imATM_BLB 2
#define imSK 3
#define imARM_BLB 4


// ../inav/src/main/io/smartport_master.c
#if defined(USE_SMARTPORT_MASTER)
#define SMARTPORT_BAUD 57600
#define SMARTPORT_UART_MODE MODE_RXTX
#define SMARTPORT_PHYID_MAX 0x1B
#define SMARTPORT_PHYID_COUNT (SMARTPORT_PHYID_MAX + 1)
#define SMARTPORT_POLLING_INTERVAL 12
#define SMARTPORT_FRAME_START 0x7E
#define SMARTPORT_BYTESTUFFING_MARKER 0x7D
#define SMARTPORT_BYTESTUFFING_XOR_VALUE 0x20
#define SMARTPORT_SENSOR_DATA_TIMEOUT (500*1000)
#define SMARTPORT_FORWARD_REQUESTS_MAX 10
#endif


// ../inav/src/main/io/piniobox.h
#define BOX_PERMANENT_ID_USER1      47
#define BOX_PERMANENT_ID_USER2      48
#define BOX_PERMANENT_ID_USER3      57
#define BOX_PERMANENT_ID_USER4      58
#define BOX_PERMANENT_ID_NONE       255


// ../inav/src/main/io/rcdevice.c
#ifdef USE_RCDEVICE
#define RCDEVICE_INIT_DEVICE_ATTEMPTS 6
#define RCDEVICE_INIT_DEVICE_ATTEMPT_INTERVAL 1000
#endif


// ../inav/src/main/io/vtx_smartaudio.c
#if defined(USE_VTX_SMARTAUDIO) && defined(USE_VTX_CONTROL)
#define SMARTAUDIO_CMD_TIMEOUT       120
#define SMARTAUDIO_POLLING_INTERVAL  150
#define SMARTAUDIO_POLLING_WINDOW   1000
#define SACMD(cmd) (((cmd) << 1) | 1)
#define SA_IS_PITMODE(n) ((n) & SA_MODE_GET_PITMODE)
#define SA_IS_PIRMODE(n) (((n) & SA_MODE_GET_PITMODE) && ((n) & SA_MODE_GET_IN_RANGE_PITMODE))
#define SA_IS_PORMODE(n) (((n) & SA_MODE_GET_PITMODE) && ((n) & SA_MODE_GET_OUT_RANGE_PITMODE))
#define SA_DEVICE_CHVAL_TO_BAND(val) ((val) / (uint8_t)8)
#define SA_DEVICE_CHVAL_TO_CHANNEL(val) ((val) % (uint8_t)8)
#define SA_BANDCHAN_TO_DEVICE_CHVAL(band, channel) ((band) * (uint8_t)8 + (channel))
#define SA_MAX_RCVLEN 21
#define POLYGEN 0xd5
#define SMARTBAUD_MIN 4800
#define SMARTBAUD_MAX 4950
#define SA_QSIZE 6
#define SA_INITPHASE_START         0
#define SA_INITPHASE_WAIT_SETTINGS 1
#define SA_INITPHASE_WAIT_PITFREQ  2
#define SA_INITPHASE_DONE          3
#endif


// ../inav/src/main/io/gps_ublox.c
#if defined(USE_GPS) && defined(USE_GPS_PROTO_UBLOX)
#define SBASMASK1_BASE 120
#define SBASMASK1_BITS(prn) (1 << (prn-SBASMASK1_BASE))
#define GNSSID_SBAS 1
#define GNSSID_GALILEO 2
#define GNSSID_BEIDOU   3
#define GNSSID_GZSS     5
#define GNSSID_GLONASS  6
#endif


// ../inav/src/main/io/rangefinder_benewake.c
#if defined(USE_RANGEFINDER_BENEWAKE)
#define BENEWAKE_PACKET_SIZE    sizeof(tfminiPacket_t)
#define BENEWAKE_MIN_QUALITY    0
#define BENEWAKE_TIMEOUT_MS     200
#endif


// ../inav/src/main/io/adsb.h
#define ADSB_CALL_SIGN_MAX_LENGTH 9
#define ADSB_MAX_SECONDS_KEEP_INACTIVE_PLANE_IN_LIST 10


// ../inav/src/main/io/vtx_ffpv24g.c
#if defined(USE_VTX_FFPV) && defined(USE_VTX_CONTROL)
#define VTX_FFPV_CMD_TIMEOUT_MS     250
#define VTX_FFPV_HEARTBEAT_MS       1000
#define VTX_FFPV_MIN_BAND           (1)
#define VTX_FFPV_MAX_BAND           (VTX_FFPV_MIN_BAND + VTX_FFPV_BAND_COUNT - 1)
#define VTX_FFPV_MIN_CHANNEL        (1)
#define VTX_FFPV_MAX_CHANNEL        (VTX_FFPV_MIN_CHANNEL + VTX_FFPV_CHANNEL_COUNT -1)
#define VTX_UPDATE_REQ_NONE         0x00
#define VTX_UPDATE_REQ_FREQUENCY    0x01
#define VTX_UPDATE_REQ_POWER        0x02
#endif


// ../inav/src/main/io/rcdevice_cam.h
#define FIVE_KEY_CABLE_JOYSTICK_MIN 1080
#define FIVE_KEY_CABLE_JOYSTICK_MAX 1920
#define FIVE_KEY_CABLE_JOYSTICK_MID_START 1350
#define FIVE_KEY_CABLE_JOYSTICK_MID_END 1650


// ../inav/src/main/io/servo_sbus.h
#define SERVO_SBUS_MAX_SERVOS   18


// ../inav/src/main/io/osd.h
#ifndef OSD_ALTERNATE_LAYOUT_COUNT
#define OSD_ALTERNATE_LAYOUT_COUNT 3
#endif
#define OSD_LAYOUT_COUNT (OSD_ALTERNATE_LAYOUT_COUNT + 1)
#define OSD_VISIBLE_FLAG    0x2000
#define OSD_VISIBLE(x)      ((x) & OSD_VISIBLE_FLAG)
#define OSD_POS(x,y)        (((x) & 0x3F) | (((y) & 0x3F) << 6))
#define OSD_X(x)            ((x) & 0x3F)
#define OSD_Y(x)            (((x) >> 6) & 0x3F)
#define OSD_POS_MAX         0xFFF
#define OSD_VISIBLE_FLAG_SD 0x0800
#define OSD_POS_SD(x,y)     (((x) & 0x1F) | (((y) & 0x1F) << 5))
#define OSD_POS_MAX_CLI     (OSD_POS_MAX | OSD_VISIBLE_FLAG)
#define OSD_HOMING_LIM_H1 6
#define OSD_HOMING_LIM_H2 16
#define OSD_HOMING_LIM_H3 38
#define OSD_HOMING_LIM_V1 5
#define OSD_HOMING_LIM_V2 10
#define OSD_HOMING_LIM_V3 15
#define OSD_MSG_RC_RX_LINK_LOST     "!RC RX LINK LOST!"
#define OSD_MSG_TURN_ARM_SW_OFF     "TURN ARM SWITCH OFF"
#define OSD_MSG_DISABLED_BY_FS      "DISABLED BY FAILSAFE"
#define OSD_MSG_AIRCRAFT_UNLEVEL    "AIRCRAFT IS NOT LEVEL"
#define OSD_MSG_SENSORS_CAL         "SENSORS CALIBRATING"
#define OSD_MSG_SYS_OVERLOADED      "SYSTEM OVERLOADED"
#define OSD_MSG_WAITING_GPS_FIX     "WAITING FOR GPS FIX"
#define OSD_MSG_DISABLE_NAV_FIRST   "DISABLE NAVIGATION FIRST"
#define OSD_MSG_JUMP_WP_MISCONFIG   "JUMP WAYPOINT MISCONFIGURED"
#define OSD_MSG_MAG_NOT_CAL         "COMPASS NOT CALIBRATED"
#define OSD_MSG_ACC_NOT_CAL         "ACCELEROMETER NOT CALIBRATED"
#define OSD_MSG_DISARM_1ST          "DISABLE ARM SWITCH FIRST"
#define OSD_MSG_GYRO_FAILURE        "GYRO FAILURE"
#define OSD_MSG_ACC_FAIL            "ACCELEROMETER FAILURE"
#define OSD_MSG_MAG_FAIL            "COMPASS FAILURE"
#define OSD_MSG_BARO_FAIL           "BAROMETER FAILURE"
#define OSD_MSG_GPS_FAIL            "GPS FAILURE"
#define OSD_MSG_RANGEFINDER_FAIL    "RANGE FINDER FAILURE"
#define OSD_MSG_PITOT_FAIL          "PITOT METER FAILURE"
#define OSD_MSG_HW_FAIL             "HARDWARE FAILURE"
#define OSD_MSG_FS_EN               "FAILSAFE MODE ENABLED"
#define OSD_MSG_NO_RC_LINK          "NO RC LINK"
#define OSD_MSG_THROTTLE_NOT_LOW    "THROTTLE IS NOT LOW"
#define OSD_MSG_ROLLPITCH_OFFCENTER "ROLLPITCH NOT CENTERED"
#define OSD_MSG_AUTOTRIM_ACTIVE     "AUTOTRIM IS ACTIVE"
#define OSD_MSG_NOT_ENOUGH_MEMORY   "NOT ENOUGH MEMORY"
#define OSD_MSG_INVALID_SETTING     "INVALID SETTING"
#define OSD_MSG_CLI_ACTIVE          "CLI IS ACTIVE"
#define OSD_MSG_PWM_INIT_ERROR      "PWM INIT ERROR"
#define OSD_MSG_NO_PREARM           "NO PREARM"
#define OSD_MSG_DSHOT_BEEPER        "MOTOR BEEPER ACTIVE"
#define OSD_MSG_RTH_FS              "(RTH)"
#define OSD_MSG_EMERG_LANDING_FS    "(EMERGENCY LANDING)"
#define OSD_MSG_MOVE_EXIT_FS        "!MOVE STICKS TO EXIT FS!"
#define OSD_MSG_STARTING_RTH        "STARTING RTH"
#define OSD_MSG_RTH_CLIMB           "ADJUSTING RTH ALTITUDE"
#define OSD_MSG_RTH_TRACKBACK       "RTH BACK TRACKING"
#define OSD_MSG_HEADING_HOME        "EN ROUTE TO HOME"
#define OSD_MSG_RTH_LINEAR_DESCENT  "BEGIN LINEAR DESCENT"
#define OSD_MSG_WP_FINISHED         "WP END>HOLDING POSITION"
#define OSD_MSG_WP_LANDED           "WP END>LANDED"
#define OSD_MSG_PREPARE_NEXT_WP     "PREPARING FOR NEXT WAYPOINT"
#define OSD_MSG_ADJUSTING_WP_ALT    "ADJUSTING WP ALTITUDE"
#define OSD_MSG_MISSION_PLANNER     "(WP MISSION PLANNER)"
#define OSD_MSG_WP_RTH_CANCEL       "CANCEL WP TO EXIT RTH"
#define OSD_MSG_WP_MISSION_LOADED   "* MISSION LOADED *"
#define OSD_MSG_EMERG_LANDING       "EMERGENCY LANDING"
#define OSD_MSG_LANDING             "LANDING"
#define OSD_MSG_LOITERING_HOME      "LOITERING AROUND HOME"
#define OSD_MSG_HOVERING            "HOVERING"
#define OSD_MSG_LANDED              "LANDED"
#define OSD_MSG_PREPARING_LAND      "PREPARING TO LAND"
#define OSD_MSG_AUTOLAUNCH          "AUTOLAUNCH"
#define OSD_MSG_AUTOLAUNCH_MANUAL   "AUTOLAUNCH (MANUAL)"
#define OSD_MSG_ALTITUDE_HOLD       "(ALTITUDE HOLD)"
#define OSD_MSG_AUTOTRIM            "(AUTOTRIM)"
#define OSD_MSG_AUTOTUNE            "(AUTOTUNE)"
#define OSD_MSG_AUTOTUNE_ACRO       "SWITCH TO ACRO"
#define OSD_MSG_AUTOLEVEL           "(AUTO LEVEL TRIM)"
#define OSD_MSG_HEADFREE            "(HEADFREE)"
#define OSD_MSG_NAV_SOARING         "(SOARING)"
#define OSD_MSG_UNABLE_ARM          "UNABLE TO ARM"
#define OSD_MSG_SAVING_SETTNGS      "** SAVING SETTINGS **"
#define OSD_MSG_SETTINGS_SAVED      "** SETTINGS SAVED **"
#define OSD_MSG_ANGLEHOLD_ROLL      "(ANGLEHOLD ROLL)"
#define OSD_MSG_ANGLEHOLD_PITCH     "(ANGLEHOLD PITCH)"
#define OSD_MSG_ANGLEHOLD_LEVEL     "(ANGLEHOLD LEVEL)"
#define OSD_MSG_MOVE_STICKS         "MOVE STICKS TO ABORT"
#ifdef USE_DEV_TOOLS
#define OSD_MSG_GRD_TEST_MODE       "GRD TEST > MOTORS DISABLED"
#endif
#if defined(USE_SAFE_HOME)
#define OSD_MSG_DIVERT_SAFEHOME     "DIVERTING TO SAFEHOME"
#define OSD_MSG_LOITERING_SAFEHOME  "LOITERING AROUND SAFEHOME"
#endif
#if defined(USE_GEOZONE)
#define OSD_MSG_NFZ                 "NO FLY ZONE"
#define OSD_MSG_LEAVING_FZ          "LEAVING FZ IN %s"
#define OSD_MSG_OUTSIDE_FZ          "OUTSIDE FZ"
#define OSD_MSG_ENTERING_NFZ        "ENTERING NFZ IN %s %s"
#define OSD_MSG_AVOIDING_FB         "AVOIDING FENCE BREACH"
#define OSD_MSG_RETURN_TO_ZONE      "RETURN TO FZ"
#define OSD_MSG_FLYOUT_NFZ          "FLY OUT NFZ"
#define OSD_MSG_AVOIDING_ALT_BREACH "REACHED ZONE ALTITUDE LIMIT"
#define OSD_MSG_AVOID_ZONES_RTH     "AVOIDING NO FLY ZONES"
#define OSD_MSG_GEOZONE_ACTION      "PERFORM ACTION IN %s %s"
#endif
#define OSD_SWITCH_INDICATOR_NAME_LENGTH 4


// ../inav/src/main/io/ledstrip.c
#ifdef USE_LED_STRIP
#define LED_STRIP_HZ(hz) ((int32_t)((1000 * 1000) / (hz)))
#define LED_STRIP_MS(ms) ((int32_t)(1000 * (ms)))
#define HSV(color) (hsv[COLOR_ ## color])
#define CHUNK_BUFFER_SIZE 11
#define INDICATOR_DEADBAND 25
#define ROTATION_SEQUENCE_LED_COUNT 6
#define ROTATION_SEQUENCE_LED_WIDTH 2
#endif


// ../inav/src/main/io/gimbal_serial.c
#ifdef USE_SERIAL_GIMBAL
#define GIMBAL_SERIAL_BUFFER_SIZE 512
#endif


// ../inav/src/main/io/rcdevice_cam.c
#ifdef USE_RCDEVICE
#define IS_HI(X) (rxGetChannelValue(X) > FIVE_KEY_CABLE_JOYSTICK_MAX)
#define IS_LO(X) (rxGetChannelValue(X) < FIVE_KEY_CABLE_JOYSTICK_MIN)
#define IS_MID(X) (rxGetChannelValue(X) > FIVE_KEY_CABLE_JOYSTICK_MID_START && rxGetChannelValue(X) < FIVE_KEY_CABLE_JOYSTICK_MID_END)
#endif


// ../inav/src/main/io/vtx_smartaudio.h
#define VTX_SMARTAUDIO_MIN_BAND 1
#define VTX_SMARTAUDIO_MAX_BAND 5
#define VTX_SMARTAUDIO_MIN_CHANNEL 1
#define VTX_SMARTAUDIO_MAX_CHANNEL 8
#define VTX_SMARTAUDIO_BAND_COUNT (VTX_SMARTAUDIO_MAX_BAND - VTX_SMARTAUDIO_MIN_BAND + 1)
#define VTX_SMARTAUDIO_CHANNEL_COUNT (VTX_SMARTAUDIO_MAX_CHANNEL - VTX_SMARTAUDIO_MIN_CHANNEL + 1)
#define VTX_SMARTAUDIO_MAX_POWER_COUNT 8
#define VTX_SMARTAUDIO_DEFAULT_POWER_COUNT 4
#define VTX_SMARTAUDIO_DEFAULT_POWER 1
#define VTX_SMARTAUDIO_MIN_FREQUENCY_MHZ 5000
#define VTX_SMARTAUDIO_MAX_FREQUENCY_MHZ 5999
#define SA_MODE_GET_FREQ_BY_FREQ            1
#define SA_MODE_GET_PITMODE                 2
#define SA_MODE_GET_IN_RANGE_PITMODE        4
#define SA_MODE_GET_OUT_RANGE_PITMODE       8
#define SA_MODE_GET_UNLOCK                 16
#define SA_MODE_GET_DEFERRED_FREQ          32
#define SA_MODE_SET_IN_RANGE_PITMODE        1
#define SA_MODE_SET_OUT_RANGE_PITMODE       2
#define SA_MODE_CLR_PITMODE                 4
#define SA_MODE_SET_UNLOCK                  8
#define SA_MODE_SET_LOCK                    0
#define SA_MODE_SET_DEFERRED_FREQ          16
#define SA_FREQ_GETPIT                      (1 << 14)
#define SA_FREQ_SETPIT                      (1 << 15)
#define SA_FREQ_MASK                        (~(SA_FREQ_GETPIT|SA_FREQ_SETPIT))


// ../inav/src/main/io/gps_private.h
#ifdef USE_GPS
#define GPS_HDOP_TO_EPH_MULTIPLIER      2
#define GPS_TIMEOUT             (1000)
#define GPS_SHORT_TIMEOUT       (500)
#define GPS_BAUD_CHANGE_DELAY   (100)
#define GPS_INIT_DELAY          (500)
#define GPS_BOOT_DELAY          (3000)
#endif


// ../inav/src/main/io/displayport_msp_osd.h
#define DISPLAYPORT_MSP_ATTR_FONTPAGE   0
#define DISPLAYPORT_MSP_ATTR_BLINK      6
#define DISPLAYPORT_MSP_ATTR_VERSION    7
#define DISPLAYPORT_MSP_ATTR_FONTPAGE_MASK   0x3
#define DISPLAYPORT_MSP_ATTR_BLINK_MASK      (1 << DISPLAYPORT_MSP_ATTR_BLINK)
#define DISPLAYPORT_MSP_ATTR_VERSION_MASK    (1 << DISPLAYPORT_MSP_ATTR_VERSION)
#define getAttrPage(attr) (attr & DISPLAYPORT_MSP_ATTR_FONTPAGE_MASK)
#define getAttrBlink(attr) ((attr & DISPLAYPORT_MSP_ATTR_BLINK_MASK) >> DISPLAYPORT_MSP_ATTR_BLINK)
#define getAttrVersion(attr) ((attr & DISPLAYPORT_MSP_ATTR_VERSION_MASK) >> DISPLAYPORT_MSP_ATTR_VERSION)


// ../inav/src/main/io/serial_4way_avrootloader.c
#ifdef  USE_SERIAL_4WAY_BLHELI_INTERFACE
#if defined(USE_SERIAL_4WAY_BLHELI_BOOTLOADER) && !defined(USE_FAKE_ESC)
#define RestartBootloader   0
#define ExitBootloader      1
#define CMD_RUN             0x00
#define CMD_PROG_FLASH      0x01
#define CMD_ERASE_FLASH     0x02
#define CMD_READ_FLASH_SIL  0x03
#define CMD_VERIFY_FLASH    0x03
#define CMD_VERIFY_FLASH_ARM 0x04
#define CMD_READ_EEPROM     0x04
#define CMD_PROG_EEPROM     0x05
#define CMD_READ_SRAM       0x06
#define CMD_READ_FLASH_ATM  0x07
#define CMD_KEEP_ALIVE      0xFD
#define CMD_SET_ADDRESS     0xFF
#define CMD_SET_BUFFER      0xFE
#define CMD_BOOTINIT        0x07
#define CMD_BOOTSIGN        0x08
#define START_BIT_TIMEOUT_MS 2
#define BIT_TIME (52)
#define BIT_TIME_HALVE      (BIT_TIME >> 1)
#define BIT_TIME_3_4        (BIT_TIME_HALVE + (BIT_TIME_HALVE >> 1))
#define START_BIT_TIME      (BIT_TIME_3_4)
    #define BootMsgLen 4
    #define DevSignHi (BootMsgLen)
    #define DevSignLo (BootMsgLen+1)
#endif
#if defined(USE_SERIAL_4WAY_BLHELI_BOOTLOADER) && defined(USE_FAKE_ESC)
#define FAKE_PAGE_SIZE 512
#define FAKE_FLASH_SIZE 16385
#endif
#endif


// ../inav/src/main/io/rangefinder_usd1_v0.c
#if defined(USE_RANGEFINDER_USD1_V0)
#define USD1_HDR_V0 72
#define USD1_PACKET_SIZE 3
#define USD1_KEEP_DATA_TIMEOUT 2000
#endif


// ../inav/src/main/io/displayport_msp_osd.c
#if defined(USE_OSD) && defined(USE_MSP_OSD)
#define FONT_VERSION 3
#define DRAW_FREQ_DENOM 4
#define TX_BUFFER_SIZE 1024
#define VTX_TIMEOUT 1000
#define PAL_COLS 30
#define PAL_ROWS 16
#define NTSC_COLS 30
#define NTSC_ROWS 13
#define HDZERO_COLS 50
#define HDZERO_ROWS 18
#define AVATAR_COLS 53
#define AVATAR_ROWS 20
#define DJI_COLS 60
#define DJI_ROWS 22
#define COLS DJI_COLS
#define ROWS DJI_ROWS
#define SCREENSIZE (ROWS*COLS)
#if defined(USE_OSD) && defined(USE_DJI_HD_OSD)
#else
#define fixDjiBrokenO4ProcessMspCommand processMspCommand
#endif
#endif


// ../inav/src/main/io/flashfs.h
#define FLASHFS_WRITE_BUFFER_SIZE 128
#define FLASHFS_WRITE_BUFFER_USABLE (FLASHFS_WRITE_BUFFER_SIZE - 1)
#define FLASHFS_WRITE_BUFFER_AUTO_FLUSH_LEN 64


// ../inav/src/main/io/serial_4way_stk500v2.c
#ifdef  USE_SERIAL_4WAY_BLHELI_INTERFACE
#ifdef USE_SERIAL_4WAY_SK_BOOTLOADER
#define BIT_LO_US (32)
#define BIT_HI_US (2*BIT_LO_US)
#define STK_BIT_TIMEOUT 250
#define STK_WAIT_TICKS (1000 / STK_BIT_TIMEOUT)
#define STK_WAITCYLCES (STK_WAIT_TICKS * 35)
#define STK_WAITCYLCES_START (STK_WAIT_TICKS / 2)
#define STK_WAITCYLCES_EXT (STK_WAIT_TICKS * 5000)
#define  WaitPinLo  while (ESC_IS_HI) {if (micros() > timeout_timer) goto timeout;}
#define  WaitPinHi  while (ESC_IS_LO) {if (micros() > timeout_timer) goto timeout;}
#define MESSAGE_START           0x1B
#define TOKEN                   0x0E
#define CMD_SIGN_ON             0x01
#define CMD_LOAD_ADDRESS        0x06
#define CMD_CHIP_ERASE_ISP      0x12
#define CMD_PROGRAM_FLASH_ISP   0x13
#define CMD_READ_FLASH_ISP      0x14
#define CMD_PROGRAM_EEPROM_ISP  0x15
#define CMD_READ_EEPROM_ISP     0x16
#define CMD_READ_SIGNATURE_ISP  0x1B
#define CMD_SPI_MULTI           0x1D
#define STATUS_CMD_OK           0x00
#define CmdFlashEepromRead 0xA0
#define EnterIspCmd1 0xAC
#define EnterIspCmd2 0x53
#define signature_r  0x30
#define delay_us(x) delayMicroseconds(x)
#define IRQ_OFF
#define IRQ_ON
#endif
#endif


// ../inav/src/main/io/dji_osd_symbols.h
#define DJI_SYM_NONE                    0x00
#define DJI_SYM_END_OF_FONT             0xFF
#define DJI_SYM_BLANK                   0x20
#define DJI_SYM_HYPHEN                  0x2D
#define DJI_SYM_BBLOG                   0x10
#define DJI_SYM_HOMEFLAG                0x11
#define DJI_SYM_RPM                     0x12
#define DJI_SYM_ROLL                    0x14
#define DJI_SYM_PITCH                   0x15
#define DJI_SYM_TEMPERATURE             0x7A
#define DJI_SYM_MAX                     0x24
#define DJI_SYM_LAT                     0x89
#define DJI_SYM_LON                     0x98
#define DJI_SYM_ALTITUDE                0x7F
#define DJI_SYM_TOTAL_DISTANCE          0x71
#define DJI_SYM_OVER_HOME               0x05
#define DJI_SYM_RSSI                    0x01
#define DJI_SYM_LINK_QUALITY            0x7B
#define DJI_SYM_THR                     0x04
#define DJI_SYM_M                       0x0C
#define DJI_SYM_KM                      0x7D
#define DJI_SYM_C                       0x0E
#define DJI_SYM_FT                      0x0F
#define DJI_SYM_MILES                   0x7E
#define DJI_SYM_F                       0x0D
#define DJI_SYM_HEADING_N               0x18
#define DJI_SYM_HEADING_S               0x19
#define DJI_SYM_HEADING_E               0x1A
#define DJI_SYM_HEADING_W               0x1B
#define DJI_SYM_HEADING_DIVIDED_LINE    0x1C
#define DJI_SYM_HEADING_LINE            0x1D
#define DJI_SYM_AH_CENTER_LINE          0x72
#define DJI_SYM_AH_CENTER               0x73
#define DJI_SYM_AH_CENTER_LINE_RIGHT    0x74
#define DJI_SYM_AH_RIGHT                0x02
#define DJI_SYM_AH_LEFT                 0x03
#define DJI_SYM_AH_DECORATION           0x13
#define DJI_SYM_SAT_L                   0x1E
#define DJI_SYM_SAT_R                   0x1F
#define DJI_SYM_ARROW_SOUTH             0x60
#define DJI_SYM_ARROW_2                 0x61
#define DJI_SYM_ARROW_3                 0x62
#define DJI_SYM_ARROW_4                 0x63
#define DJI_SYM_ARROW_EAST              0x64
#define DJI_SYM_ARROW_6                 0x65
#define DJI_SYM_ARROW_7                 0x66
#define DJI_SYM_ARROW_8                 0x67
#define DJI_SYM_ARROW_NORTH             0x68
#define DJI_SYM_ARROW_10                0x69
#define DJI_SYM_ARROW_11                0x6A
#define DJI_SYM_ARROW_12                0x6B
#define DJI_SYM_ARROW_WEST              0x6C
#define DJI_SYM_ARROW_14                0x6D
#define DJI_SYM_ARROW_15                0x6E
#define DJI_SYM_ARROW_16                0x6F
#define DJI_SYM_ARROW_SMALL_UP          0x75
#define DJI_SYM_ARROW_SMALL_DOWN        0x76
#define DJI_SYM_ARROW_SMALL_RIGHT       0x77
#define DJI_SYM_ARROW_SMALL_LEFT        0x78
#define DJI_SYM_AH_BAR9_0               0x80
#define DJI_SYM_AH_BAR9_1               0x81
#define DJI_SYM_AH_BAR9_2               0x82
#define DJI_SYM_AH_BAR9_3               0x83
#define DJI_SYM_AH_BAR9_4               0x84
#define DJI_SYM_AH_BAR9_5               0x85
#define DJI_SYM_AH_BAR9_6               0x86
#define DJI_SYM_AH_BAR9_7               0x87
#define DJI_SYM_AH_BAR9_8               0x88
#define DJI_SYM_PB_START                0x8A
#define DJI_SYM_PB_FULL                 0x8B
#define DJI_SYM_PB_HALF                 0x8C
#define DJI_SYM_PB_EMPTY                0x8D
#define DJI_SYM_PB_END                  0x8E
#define DJI_SYM_PB_CLOSE                0x8F
#define DJI_SYM_BATT_FULL               0x90
#define DJI_SYM_BATT_5                  0x91
#define DJI_SYM_BATT_4                  0x92
#define DJI_SYM_BATT_3                  0x93
#define DJI_SYM_BATT_2                  0x94
#define DJI_SYM_BATT_1                  0x95
#define DJI_SYM_BATT_EMPTY              0x96
#define DJI_SYM_MAIN_BATT               0x97
#define DJI_SYM_VOLT                    0x06
#define DJI_SYM_AMP                     0x9A
#define DJI_SYM_MAH                     0x07
#define DJI_SYM_WATT                    0x57
#define DJI_SYM_ON_M                    0x9B
#define DJI_SYM_FLY_M                   0x9C
#define DJI_SYM_SPEED                   0x70
#define DJI_SYM_KPH                     0x9E
#define DJI_SYM_MPH                     0x9D
#define DJI_SYM_MPS                     0x9F
#define DJI_SYM_FTPS                    0x99
#define DJI_SYM_CURSOR                  DJI_SYM_AH_LEFT
#define DJI_SYM_STICK_OVERLAY_SPRITE_HIGH 0x08
#define DJI_SYM_STICK_OVERLAY_SPRITE_MID  0x09
#define DJI_SYM_STICK_OVERLAY_SPRITE_LOW  0x0A
#define DJI_SYM_STICK_OVERLAY_CENTER      0x0B
#define DJI_SYM_STICK_OVERLAY_VERTICAL    0x16
#define DJI_SYM_STICK_OVERLAY_HORIZONTAL  0x17
#define DJI_SYM_GPS_DEGREE              DJI_SYM_STICK_OVERLAY_SPRITE_HIGH
#define DJI_SYM_GPS_MINUTE              0x27
#define DJI_SYM_GPS_SECOND              0x22


// ../inav/src/main/io/displayport_msp_dji_compat.h
#if defined(USE_OSD) && defined(USE_MSP_DISPLAYPORT) && !defined(DISABLE_MSP_DJI_COMPAT)
#define isDJICompatibleVideoSystem(osdConfigPtr) (osdConfigPtr->video_system == VIDEO_SYSTEM_DJICOMPAT || osdConfigPtr->video_system == VIDEO_SYSTEM_DJICOMPAT_HD)
#else
#define getDJICharacter(x, page) (x)
#ifdef OSD_UNIT_TEST
#define isDJICompatibleVideoSystem(osdConfigPtr) (true)
#else
#define isDJICompatibleVideoSystem(osdConfigPtr) (false)
#endif
#endif


// ../inav/src/main/io/serial_4way_avrootloader.h
#define brSUCCESS           0x30
#define brERRORVERIFY       0xC0
#define brERRORCOMMAND      0xC1
#define brERRORCRC          0xC2
#define brNONE              0xFF


// ../inav/src/main/io/osd/custom_elements.h
#define OSD_CUSTOM_ELEMENT_TEXT_SIZE 16
#define CUSTOM_ELEMENTS_PARTS 3
#define MAX_CUSTOM_ELEMENTS 8


// ../inav/src/main/io/asyncfatfs/fat_standard.h
#define MBR_PARTITION_TYPE_FAT16     0x06
#define MBR_PARTITION_TYPE_FAT32     0x0B
#define MBR_PARTITION_TYPE_FAT32_LBA 0x0C
#define MBR_PARTITION_TYPE_FAT16_LBA 0x0E
#define FAT_VOLUME_ID_SIGNATURE_1 0x55
#define FAT_VOLUME_ID_SIGNATURE_2 0xAA
#define FAT_DIRECTORY_ENTRY_SIZE 32
#define FAT_SMALLEST_LEGAL_CLUSTER_NUMBER 2
#define FAT_MAXIMUM_FILESIZE 0xFFFFFFFF
#define FAT12_MAX_CLUSTERS 4084
#define FAT16_MAX_CLUSTERS 65524
#define FAT_FILE_ATTRIBUTE_READ_ONLY 0x01
#define FAT_FILE_ATTRIBUTE_HIDDEN    0x02
#define FAT_FILE_ATTRIBUTE_SYSTEM    0x04
#define FAT_FILE_ATTRIBUTE_VOLUME_ID 0x08
#define FAT_FILE_ATTRIBUTE_DIRECTORY 0x10
#define FAT_FILE_ATTRIBUTE_ARCHIVE   0x20
#define FAT_FILENAME_LENGTH 11
#define FAT_DELETED_FILE_MARKER 0xE5
#define FAT_MAKE_DATE(year, month, day)     (day | (month << 5) | ((year - 1980) << 9))
#define FAT_MAKE_TIME(hour, minute, second) ((second / 2) | (minute << 5) | (hour << 11))


// ../inav/src/main/io/asyncfatfs/asyncfatfs.c
#ifdef AFATFS_DEBUG
    #define ONLY_EXPOSE_FOR_TESTING
#else
    #define ONLY_EXPOSE_FOR_TESTING static
#endif
#define AFATFS_NUM_CACHE_SECTORS 8
#define AFATFS_SECTOR_SIZE  512
#define AFATFS_NUM_FATS     2
#define AFATFS_MAX_OPEN_FILES 3
#define AFATFS_DEFAULT_FILE_DATE FAT_MAKE_DATE(2015, 12, 01)
#define AFATFS_DEFAULT_FILE_TIME FAT_MAKE_TIME(00, 00, 00)
#define AFATFS_MIN_MULTIPLE_BLOCK_WRITE_COUNT 4
#define AFATFS_FILES_PER_DIRECTORY_SECTOR (AFATFS_SECTOR_SIZE / sizeof(fatDirectoryEntry_t))
#define AFATFS_FAT32_FAT_ENTRIES_PER_SECTOR  (AFATFS_SECTOR_SIZE / sizeof(uint32_t))
#define AFATFS_FAT16_FAT_ENTRIES_PER_SECTOR (AFATFS_SECTOR_SIZE / sizeof(uint16_t))
#define AFATFS_FILE_MODE_READ             1
#define AFATFS_FILE_MODE_WRITE            2
#define AFATFS_FILE_MODE_APPEND           4
#define AFATFS_FILE_MODE_CONTIGUOUS       8
#define AFATFS_FILE_MODE_CREATE           16
#define AFATFS_FILE_MODE_RETAIN_DIRECTORY 32
#define AFATFS_CACHE_READ         1
#define AFATFS_CACHE_WRITE        2
#define AFATFS_CACHE_LOCK         4
#define AFATFS_CACHE_DISCARDABLE  8
#define AFATFS_CACHE_RETAIN       16
#define AFATFS_USE_FREEFILE
#define AFATFS_FREEFILE_LEAVE_CLUSTERS 100
#define AFATFS_FREESPACE_FILENAME "FREESPAC.E"
#define AFATFS_INTROSPEC_LOG_FILENAME "ASYNCFAT.LOG"
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))


// ../inav/src/main/flight/servos.h
#define MAX_SUPPORTED_SERVOS 18
#define SERVO_PLANE_INDEX_MIN SERVO_ELEVATOR
#define SERVO_PLANE_INDEX_MAX SERVO_RUDDER
#define SERVO_DUALCOPTER_INDEX_MIN SERVO_DUALCOPTER_LEFT
#define SERVO_DUALCOPTER_INDEX_MAX SERVO_DUALCOPTER_RIGHT
#define SERVO_SINGLECOPTER_INDEX_MIN SERVO_SINGLECOPTER_1
#define SERVO_SINGLECOPTER_INDEX_MAX SERVO_SINGLECOPTER_4
#define SERVO_FLAPPERONS_MIN SERVO_FLAPPERON_1
#define SERVO_FLAPPERONS_MAX SERVO_FLAPPERON_2
#define FLAPERON_THROW_DEFAULT 200
#define FLAPERON_THROW_MIN 50
#define FLAPERON_THROW_MAX 450
#define MAX_SERVO_RULES (2 * MAX_SUPPORTED_SERVOS)
#define MAX_SERVO_SPEED UINT8_MAX
#define SERVO_OUTPUT_MAX 2500
#define SERVO_OUTPUT_MIN 500
#define MAX_SERVO_RULES_SWITCH_CARRY (MAX_SERVO_RULES / 2)


// ../inav/src/main/flight/dynamic_gyro_notch.h
#define DYNAMIC_NOTCH_DEFAULT_CENTER_HZ 350
#define DYN_NOTCH_PEAK_COUNT 3


// ../inav/src/main/flight/gyroanalyse.c
#ifdef USE_DYNAMIC_FILTERS
#define FFT_BIN_COUNT             (FFT_WINDOW_SIZE / 2)
#define DYN_NOTCH_SMOOTH_FREQ_HZ  25
#define FFT_SAMPLING_DENOMINATOR 2
#endif


// ../inav/src/main/flight/mixer.c
#define MAX_THROTTLE 2000
#define MAX_THROTTLE_ROVER 1850
#define CRASH_OVER_AFTER_CRASH_FLIP_STICK_MIN 0.15f
    #define THROTTLE_CLIPPING_FACTOR    0.33f


// ../inav/src/main/flight/mixer_profile.h
#ifndef MAX_MIXER_PROFILE_COUNT
#define MAX_MIXER_PROFILE_COUNT 2
#endif
#define mixerConfig() (&(mixerProfiles(systemConfig()->current_mixer_profile_index)->mixer_config))
#define mixerConfigMutable() ((mixerConfig_t *) mixerConfig())
#define primaryMotorMixer(_index) (&(mixerProfiles(systemConfig()->current_mixer_profile_index)->MotorMixers)[_index])
#define primaryMotorMixerMutable(_index) ((motorMixer_t *)primaryMotorMixer(_index))
#define customServoMixers(_index) (&(mixerProfiles(systemConfig()->current_mixer_profile_index)->ServoMixers)[_index])
#define customServoMixersMutable(_index) ((servoMixer_t *)customServoMixers(_index))
#define primaryMotorMixer_CopyArray() (mixerProfiles_CopyArray_by_index(systemConfig()->current_mixer_profile_index)->MotorMixers)
#define customServoMixers_CopyArray() (mixerProfiles_CopyArray_by_index(systemConfig()->current_mixer_profile_index)->ServoMixers)
#define mixerConfigByIndex(index) (&(mixerProfiles(index)->mixer_config))
#define mixerMotorMixersByIndex(index) (mixerProfiles(index)->MotorMixers)
#define mixerServoMixersByIndex(index) (mixerProfiles(index)->ServoMixers)


// ../inav/src/main/flight/rpm_filter.c
#ifdef USE_RPM_FILTER
#define HZ_TO_RPM 1/60.0f
#define RPM_FILTER_RPM_LPF_HZ 150
#define RPM_FILTER_HARMONICS 3
#endif


// ../inav/src/main/flight/pid_autotune.c
#define AUTOTUNE_FIXED_WING_MIN_FF              10
#define AUTOTUNE_FIXED_WING_MAX_FF              255
#define AUTOTUNE_FIXED_WING_MIN_ROLL_PITCH_RATE 40
#define AUTOTUNE_FIXED_WING_MIN_YAW_RATE        10
#define AUTOTUNE_FIXED_WING_MAX_RATE            720
#define AUTOTUNE_FIXED_WING_CONVERGENCE_RATE    10
#define AUTOTUNE_FIXED_WING_SAMPLE_INTERVAL     20
#define AUTOTUNE_FIXED_WING_SAMPLES             1000
#define AUTOTUNE_FIXED_WING_MIN_SAMPLES         250
#define AUTOTUNE_SAVE_PERIOD        5000


// ../inav/src/main/flight/rpm_filter.h
#define RPM_FILTER_UPDATE_RATE_HZ 500
#define RPM_FILTER_UPDATE_RATE_US (1000000.0f / RPM_FILTER_UPDATE_RATE_HZ)


// ../inav/src/main/flight/secondary_dynamic_gyro_notch.c
#ifdef USE_DYNAMIC_FILTERS
#define SECONDARY_DYNAMIC_NOTCH_DEFAULT_CENTER_HZ 150
#endif


// ../inav/src/main/flight/pid.c
#define D_BOOST_GYRO_LPF_HZ 80
#define D_BOOST_LPF_HZ 7
#define FIXED_WING_LEVEL_TRIM_MAX_ANGLE 10.0f
#define FIXED_WING_LEVEL_TRIM_DIVIDER 50.0f
#define FIXED_WING_LEVEL_TRIM_MULTIPLIER 1.0f / FIXED_WING_LEVEL_TRIM_DIVIDER
#define FIXED_WING_LEVEL_TRIM_CONTROLLER_LIMIT FIXED_WING_LEVEL_TRIM_DIVIDER * FIXED_WING_LEVEL_TRIM_MAX_ANGLE


// ../inav/src/main/flight/kalman.h
#define MAX_KALMAN_WINDOW_SIZE 64
#define VARIANCE_SCALE 0.67f


// ../inav/src/main/flight/power_limits.c
#if defined(USE_POWER_LIMITS)
#define LIMITING_THR_FILTER_TCONST 50
#endif


// ../inav/src/main/flight/gyroanalyse.h
#ifdef USE_DYNAMIC_FILTERS
#define FFT_WINDOW_SIZE 64
#endif


// ../inav/src/main/flight/servos.c
#define GET_RX_CHANNEL_INPUT(x) (rxGetChannelValue(x) - PWM_RANGE_MIDDLE)
#define SERVO_AUTOTRIM_TIMER_MS     2000
#define SERVO_AUTOTRIM_FILTER_CUTOFF    1
#define SERVO_AUTOTRIM_CENTER_MIN       1300
#define SERVO_AUTOTRIM_CENTER_MAX       1700
#define SERVO_AUTOTRIM_UPDATE_SIZE      5
#define SERVO_AUTOTRIM_ATTITUDE_LIMIT   50


// ../inav/src/main/flight/smith_predictor.h
#define MAX_SMITH_SAMPLES 64


// ../inav/src/main/flight/imu.c
#define SPIN_RATE_LIMIT             20
#define MAX_ACC_NEARNESS            0.2
#define MAX_MAG_NEARNESS            0.25
#define COS10DEG 0.985f
#define COS20DEG 0.940f
#define IMU_ROTATION_LPF         3


// ../inav/src/main/flight/pid.h
#define GYRO_SATURATION_LIMIT       1800
#define PID_SUM_LIMIT_MIN           100
#define PID_SUM_LIMIT_MAX           1000
#define PID_SUM_LIMIT_DEFAULT       500
#define PID_SUM_LIMIT_YAW_DEFAULT   400
#define HEADING_HOLD_RATE_LIMIT_MIN 10
#define HEADING_HOLD_RATE_LIMIT_MAX 250
#define HEADING_HOLD_RATE_LIMIT_DEFAULT 90
#define AXIS_ACCEL_MIN_LIMIT        50
#define HEADING_HOLD_ERROR_LPF_FREQ 2
#define FP_PID_RATE_FF_MULTIPLIER   31.0f
#define FP_PID_RATE_P_MULTIPLIER    31.0f
#define FP_PID_RATE_I_MULTIPLIER    4.0f
#define FP_PID_RATE_D_MULTIPLIER    1905.0f
#define FP_PID_RATE_D_FF_MULTIPLIER   7270.0f
#define FP_PID_LEVEL_P_MULTIPLIER   1.0f / 6.56f
#define FP_PID_YAWHOLD_P_MULTIPLIER 80.0f
#define MC_ITERM_RELAX_SETPOINT_THRESHOLD 40.0f
#define MC_ITERM_RELAX_CUTOFF_DEFAULT 15
#define ANTI_GRAVITY_THROTTLE_FILTER_CUTOFF 15
#define FIXED_WING_LEVEL_TRIM_DEADBAND_DEFAULT 5
#define TASK_AUX_RATE_HZ   100


// ../inav/src/main/flight/mixer.h
#if defined(TARGET_MOTOR_COUNT)
#define MAX_SUPPORTED_MOTORS TARGET_MOTOR_COUNT
#else
#define MAX_SUPPORTED_MOTORS 12
#endif
#define DSHOT_DISARM_COMMAND      0
#define DSHOT_MIN_THROTTLE       48
#define DSHOT_MAX_THROTTLE     2047
#define DSHOT_3D_DEADBAND_LOW  1047
#define DSHOT_3D_DEADBAND_HIGH 1048


// ../inav/src/main/flight/failsafe.h
#define FAILSAFE_POWER_ON_DELAY_US (1000 * 1000 * 5)
#define MILLIS_PER_TENTH_SECOND         100
#define MILLIS_PER_SECOND              1000
#define PERIOD_OF_1_SECONDS               1 * MILLIS_PER_SECOND
#define PERIOD_OF_3_SECONDS               3 * MILLIS_PER_SECOND
#define PERIOD_OF_30_SECONDS             30 * MILLIS_PER_SECOND
#define PERIOD_RXDATA_FAILURE           200
#define PERIOD_RXDATA_RECOVERY          200


// ../inav/src/main/flight/ez_tune.c
#define EZ_TUNE_PID_RP_DEFAULT { 40, 75, 23, 100 }
#define EZ_TUNE_PID_YAW_DEFAULT { 45, 80, 0, 100 }
#define EZ_TUNE_YAW_SCALE 0.5f


// ../inav/src/main/flight/wind_estimator.c
#if defined(USE_WIND_ESTIMATOR)
#define WINDESTIMATOR_TIMEOUT       60*15
#define WINDESTIMATOR_ALTITUDE_SCALE WINDESTIMATOR_TIMEOUT/500.0f
#endif


// ../inav/src/main/flight/adaptive_filter.h
#define ADAPTIVE_FILTER_BUFFER_SIZE 64
#define ADAPTIVE_FILTER_RATE_HZ 100


// ../inav/src/main/fc/stats.h
#ifdef USE_STATS
#else
#define statsInit()     do {} while (0)
#define statsOnArm()    do {} while (0)
#define statsOnDisarm() do {} while (0)
#endif


// ../inav/src/main/fc/rc_modes.h
#define BOXID_NONE 255
#define MAX_MODE_ACTIVATION_CONDITION_COUNT 40
#define CHANNEL_RANGE_MIN 900
#define CHANNEL_RANGE_MAX 2100
#define CHANNEL_RANGE_STEP_WIDTH 25
#define MODE_STEP_TO_CHANNEL_VALUE(step) (CHANNEL_RANGE_MIN + CHANNEL_RANGE_STEP_WIDTH * step)
#define CHANNEL_VALUE_TO_STEP(channelValue) ((constrain(channelValue, CHANNEL_RANGE_MIN, CHANNEL_RANGE_MAX) - CHANNEL_RANGE_MIN) / CHANNEL_RANGE_STEP_WIDTH)
#define MIN_MODE_RANGE_STEP 0
#define MAX_MODE_RANGE_STEP ((CHANNEL_RANGE_MAX - CHANNEL_RANGE_MIN) / CHANNEL_RANGE_STEP_WIDTH)
#define IS_RANGE_USABLE(range) ((range)->startStep < (range)->endStep)


// ../inav/src/main/fc/fc_msp_box.c
#define BOX_SUFFIX ';'
#define BOX_SUFFIX_LEN 1
#define RESET_BOX_ID_COUNT activeBoxIdCount = 0
#define ADD_ACTIVE_BOX(box) activeBoxIds[activeBoxIdCount++] = box
#define IS_ENABLED(mask) ((mask) == 0 ? 0 : 1)
#define CHECK_ACTIVE_BOX(condition, index)    do { if (IS_ENABLED(condition)) { activeBoxes[index] = 1; } } while(0)


// ../inav/src/main/fc/stats.c
#ifdef USE_STATS
#define MIN_FLIGHT_TIME_TO_RECORD_STATS_S 10
#define MIN_FLIGHT_DISTANCE_M 30
#endif


// ../inav/src/main/fc/firmware_update.c
#ifdef MSP_FIRMWARE_UPDATE
#if defined(USE_SDCARD)
#define SD_BACKUP_FILE_BLOCK_READ_SIZE 512
#endif
#endif


// ../inav/src/main/fc/rc_smoothing.c
#define RC_INTERPOLATION_MIN_FREQUENCY 15
    #define RC_FILTER_SAMPLES_MEDIAN 9


// ../inav/src/main/fc/cli.c
#define SENSOR_NAMES_MASK (SENSOR_GYRO | SENSOR_ACC | SENSOR_BARO | SENSOR_MAG | SENSOR_RANGEFINDER | SENSOR_PITOT | SENSOR_OPFLOW)
#ifdef CLI_MINIMAL_VERBOSITY
#define cliPrintHashLine(str)
#endif
#ifndef SKIP_CLI_COMMAND_HELP
#define CLI_COMMAND_DEF(name, description, args, method) \
{ \
    name , \
    description , \
    args , \
    method \
}
#else
#define CLI_COMMAND_DEF(name, description, args, method) \
{ \
    name, \
    method \
}
#endif


// ../inav/src/main/fc/settings.h
#define SETTING_TYPE_OFFSET 0
#define SETTING_SECTION_OFFSET 3
#define SETTING_MODE_OFFSET 6
#define SETTING_TYPE_MASK (0x07)
#define SETTING_SECTION_MASK (0x38)
#define SETTING_MODE_MASK (0xC0)


// ../inav/src/main/fc/rc_adjustments.c
#define MARK_ADJUSTMENT_FUNCTION_AS_BUSY(adjustmentIndex) adjustmentStateMask |= (1 << adjustmentIndex)
#define MARK_ADJUSTMENT_FUNCTION_AS_READY(adjustmentIndex) adjustmentStateMask &= ~(1 << adjustmentIndex)
#define IS_ADJUSTMENT_FUNCTION_BUSY(adjustmentIndex) (adjustmentStateMask & (1 << adjustmentIndex))
#define ADJUSTMENT_FUNCTION_CONFIG_INDEX_OFFSET 1
#define RESET_FREQUENCY_2HZ (1000 / 2)


// ../inav/src/main/fc/rc_controls.h
#define CONTROL_DEADBAND           10


// ../inav/src/main/fc/multifunction.h
#ifdef USE_MULTI_FUNCTIONS
#define MULTI_FUNC_FLAG_DISABLE(mask) (multiFunctionFlags &= ~(mask))
#define MULTI_FUNC_FLAG_ENABLE(mask) (multiFunctionFlags |= (mask))
#define MULTI_FUNC_FLAG(mask) (multiFunctionFlags & (mask))
#endif


// ../inav/src/main/fc/rc_controls.c
#define AIRMODE_DEADBAND 25
#define MIN_RC_TICK_INTERVAL_MS             20
#define DEFAULT_RC_SWITCH_DISARM_DELAY_MS   250
#define DEFAULT_PREARM_TIMEOUT              10000


// ../inav/src/main/fc/rc_adjustments.h
#define ADJUSTMENT_INDEX_OFFSET 1
#ifndef MAX_SIMULTANEOUS_ADJUSTMENT_COUNT
#define MAX_SIMULTANEOUS_ADJUSTMENT_COUNT 4
#endif
#define MAX_ADJUSTMENT_RANGE_COUNT 20


// ../inav/src/main/fc/rc_curves.c
#define THROTTLE_LOOKUP_LENGTH 11


// ../inav/src/main/fc/firmware_update_common.h
#define FIRMWARE_UPDATE_FIRMWARE_FILENAME "firmware.upt"
#define FIRMWARE_UPDATE_BACKUP_FILENAME "firmware.bak"
#define FIRMWARE_UPDATE_META_FILENAME "update.mta"
#define FIRMWARE_UPDATE_METADATA_MAGIC 0xAABBCCDD
#define FIRMWARE_START_ADDRESS ((uint32_t)&__firmware_start)
#define FLASH_START_ADDRESS 0x08000000UL
#define FLASH_END (FLASH_START_ADDRESS + MCU_FLASH_SIZE * 1024)
#define CONFIG_START_ADDRESS ((uint32_t)&__config_start)
#define CONFIG_END_ADDRESS ((uint32_t)&__config_end)
#define AVAILABLE_FIRMWARE_SPACE (FLASH_END - FIRMWARE_START_ADDRESS)


// ../inav/src/main/fc/fc_core.c
#define EMERGENCY_ARMING_TIME_WINDOW_MS 10000
#define EMERGENCY_ARMING_COUNTER_STEP_MS 1000
#define EMERGENCY_ARMING_MIN_ARM_COUNT 10
#define EMERGENCY_INFLIGHT_REARM_TIME_WINDOW_MS 5000
#define TELEMETRY_FUNCTION_MASK (FUNCTION_TELEMETRY_HOTT | FUNCTION_TELEMETRY_SMARTPORT | FUNCTION_TELEMETRY_LTM | FUNCTION_TELEMETRY_MAVLINK | FUNCTION_TELEMETRY_IBUS)


// ../inav/src/main/fc/config.h
#define MAX_PROFILE_COUNT 3
#define ONESHOT_FEATURE_CHANGED_DELAY_ON_BOOT_MS 1500
#define MAX_NAME_LENGTH 16
#define TASK_GYRO_LOOPTIME 250


// ../inav/src/main/fc/runtime_config.h
#define ARMING_DISABLED_EMERGENCY_OVERRIDE  (ARMING_DISABLED_GEOZONE \
                                            | ARMING_DISABLED_NOT_LEVEL \
                                            | ARMING_DISABLED_NAVIGATION_UNSAFE \
                                            | ARMING_DISABLED_COMPASS_NOT_CALIBRATED \
                                            | ARMING_DISABLED_ACCELEROMETER_NOT_CALIBRATED \
                                            | ARMING_DISABLED_ARM_SWITCH \
                                            | ARMING_DISABLED_HARDWARE_FAILURE)
#define isArmingDisabled()          (armingFlags & (ARMING_DISABLED_ALL_FLAGS))
#define DISABLE_ARMING_FLAG(mask)   (armingFlags &= ~(mask))
#define ENABLE_ARMING_FLAG(mask)    (armingFlags |= (mask))
#define ARMING_FLAG(mask)           (armingFlags & (mask))
#define DISABLE_FLIGHT_MODE(mask) (flightModeFlags &= ~(mask))
#define ENABLE_FLIGHT_MODE(mask) (flightModeFlags |= (mask))
#define FLIGHT_MODE(mask) (flightModeFlags & (mask))
#define DISABLE_STATE(mask) (stateFlags &= ~(mask))
#define ENABLE_STATE(mask) (stateFlags |= (mask))
#define STATE(mask) (stateFlags & (mask))
#ifdef USE_SIMULATOR
#define SIMULATOR_MSP_VERSION  2
#define SIMULATOR_BARO_TEMP    25
#define SIMULATOR_FULL_BATTERY 126
#define SIMULATOR_HAS_OPTION(flag) ((simulatorData.flags & flag) != 0)
#endif


// ../inav/src/main/fc/config.c
#ifndef DEFAULT_FEATURES
#define DEFAULT_FEATURES 0
#endif
#define BRUSHED_MOTORS_PWM_RATE 16000
#define BRUSHLESS_MOTORS_PWM_RATE 400
#if !defined(VBAT_ADC_CHANNEL)
#define VBAT_ADC_CHANNEL ADC_CHN_NONE
#endif
#if !defined(RSSI_ADC_CHANNEL)
#define RSSI_ADC_CHANNEL ADC_CHN_NONE
#endif
#if !defined(CURRENT_METER_ADC_CHANNEL)
#define CURRENT_METER_ADC_CHANNEL ADC_CHN_NONE
#endif
#if !defined(AIRSPEED_ADC_CHANNEL)
#define AIRSPEED_ADC_CHANNEL ADC_CHN_NONE
#endif
#define SAVESTATE_NONE 0
#define SAVESTATE_SAVEONLY 1
#define SAVESTATE_SAVEANDNOTIFY 2
#ifdef SWAP_SERIAL_PORT_0_AND_1_DEFAULTS
#define FIRST_PORT_INDEX 1
#define SECOND_PORT_INDEX 0
#else
#define FIRST_PORT_INDEX 0
#define SECOND_PORT_INDEX 1
#endif


// ../inav/src/main/fc/control_profile.h
#define MAX_CONTROL_PROFILE_COUNT SETTING_CONSTANT_MAX_CONTROL_PROFILE_COUNT


// ../inav/src/main/drivers/timer_def.h
#define DEF_TIM_DMAMAP(variant, timch) CONCAT(DEF_TIM_DMAMAP__, PP_CALL(CONCAT(DEF_TIM_DMAMAP_VARIANT__, variant), CONCAT(DEF_TIM_DMA__, DEF_TIM_TCH2BTCH(timch)), DMA_VARIANT_MISSING, DMA_VARIANT_MISSING))
#define DEF_TIM_DMAMAP_VARIANT__0(_0, ...)                                                                      _0
#define DEF_TIM_DMAMAP_VARIANT__1(_0, _1, ...)                                                                  _1
#define DEF_TIM_DMAMAP_VARIANT__2(_0, _1, _2, ...)                                                              _2
#define DEF_TIM_DMAMAP_VARIANT__3(_0, _1, _2, _3, ...)                                                          _3
#define DEF_TIM_DMAMAP_VARIANT__4(_0, _1, _2, _3, _4, ...)                                                      _4
#define DEF_TIM_DMAMAP_VARIANT__5(_0, _1, _2, _3, _4, _5, ...)                                                  _5
#define DEF_TIM_DMAMAP_VARIANT__6(_0, _1, _2, _3, _4, _5, _6, ...)                                              _6
#define DEF_TIM_DMAMAP_VARIANT__7(_0, _1, _2, _3, _4, _5, _6, _7, ...)                                          _7
#define DEF_TIM_DMAMAP_VARIANT__8(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...)                                      _8
#define DEF_TIM_DMAMAP_VARIANT__9(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...)                                  _9
#define DEF_TIM_DMAMAP_VARIANT__10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...)                            _10
#define DEF_TIM_DMAMAP_VARIANT__11(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...)                       _11
#define DEF_TIM_DMAMAP_VARIANT__12(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...)                  _12
#define DEF_TIM_DMAMAP_VARIANT__13(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...)             _13
#define DEF_TIM_DMAMAP_VARIANT__14(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, ...)        _14
#define DEF_TIM_DMAMAP_VARIANT__15(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...)   _15
#define DEF_TIM_CHNL_CH1    0
#define DEF_TIM_CHNL_CH1N   0
#define DEF_TIM_CHNL_CH2    1
#define DEF_TIM_CHNL_CH2N   1
#define DEF_TIM_CHNL_CH3    2
#define DEF_TIM_CHNL_CH3N   2
#define DEF_TIM_CHNL_CH4    3
#define DEF_TIM_CHNL_CH4N   3
#define DEF_TIM_TCH2BTCH(timch) CONCAT(BTCH_, timch)
#if defined(AT32F43x)
#define BTCH_TMR1_CH1N BTCH_TMR1_CH1
#define BTCH_TMR1_CH2N BTCH_TMR1_CH2
#define BTCH_TMR1_CH3N BTCH_TMR1_CH3
#define BTCH_TMR8_CH1N BTCH_TMR8_CH1
#define BTCH_TMR8_CH2N BTCH_TMR8_CH2
#define BTCH_TMR8_CH3N BTCH_TMR8_CH3
#define BTCH_TMR20_CH1N BTCH_TMR20_CH1
#define BTCH_TMR20_CH2N BTCH_TMR20_CH2
#define BTCH_TMR20_CH3N BTCH_TMR20_CH3
#define BTCH_TMR15_CH1N BTCH_TMR15_CH1
#define BTCH_TMR16_CH1N BTCH_TMR16_CH1
#else
#define BTCH_TIM1_CH1N BTCH_TIM1_CH1
#define BTCH_TIM1_CH2N BTCH_TIM1_CH2
#define BTCH_TIM1_CH3N BTCH_TIM1_CH3
#define BTCH_TIM8_CH1N BTCH_TIM8_CH1
#define BTCH_TIM8_CH2N BTCH_TIM8_CH2
#define BTCH_TIM8_CH3N BTCH_TIM8_CH3
#define BTCH_TIM20_CH1N BTCH_TIM20_CH1
#define BTCH_TIM20_CH2N BTCH_TIM20_CH2
#define BTCH_TIM20_CH3N BTCH_TIM20_CH3
#define BTCH_TIM15_CH1N BTCH_TIM15_CH1
#define BTCH_TIM16_CH1N BTCH_TIM16_CH1
#endif
#define DEF_TIM_OUTPUT(ch)                      DEF_TIM_OUTPUT__ ## ch
#define DEF_TIM_OUTPUT__CH1                     (TIMER_OUTPUT_NONE)
#define DEF_TIM_OUTPUT__CH2                     (TIMER_OUTPUT_NONE)
#define DEF_TIM_OUTPUT__CH3                     (TIMER_OUTPUT_NONE)
#define DEF_TIM_OUTPUT__CH4                     (TIMER_OUTPUT_NONE)
#define DEF_TIM_OUTPUT__CH1N                    (TIMER_OUTPUT_N_CHANNEL)
#define DEF_TIM_OUTPUT__CH2N                    (TIMER_OUTPUT_N_CHANNEL)
#define DEF_TIM_OUTPUT__CH3N                    (TIMER_OUTPUT_N_CHANNEL)
#define DEF_TIM_OUTPUT__CH4N                    (TIMER_OUTPUT_N_CHANNEL)


// ../inav/src/main/drivers/io_types.h
#define IOTAG_NONE ((ioTag_t)0)
#define IO_NONE ((IO_t)0)


// ../inav/src/main/drivers/bus.c
#define BUSDEV_MAX_DEVICES 16


// ../inav/src/main/drivers/timer.h
#define CC_CHANNELS_PER_TIMER       4
#if defined(STM32F4)
#define HARDWARE_TIMER_DEFINITION_COUNT 14
#elif defined(STM32F7)
#define HARDWARE_TIMER_DEFINITION_COUNT 14
#elif defined(STM32H7)
#define HARDWARE_TIMER_DEFINITION_COUNT 14
#elif defined(AT32F43x)
#define HARDWARE_TIMER_DEFINITION_COUNT 15
#elif defined(SITL_BUILD)
#define HARDWARE_TIMER_DEFINITION_COUNT 0
#endif
#define TIM_USE_OUTPUT_AUTO (TIM_USE_MOTOR | TIM_USE_SERVO)
#define TIM_IS_MOTOR(flags) ((flags) & TIM_USE_MOTOR)
#define TIM_IS_SERVO(flags) ((flags) & TIM_USE_SERVO)
#define TIM_IS_LED(flags) ((flags) & TIM_USE_LED)
#define TIM_IS_MOTOR_ONLY(flags) (TIM_IS_MOTOR(flags) && !TIM_IS_SERVO(flags))
#define TIM_IS_SERVO_ONLY(flags) (!TIM_IS_MOTOR(flags) && TIM_IS_SERVO(flags))


// ../inav/src/main/drivers/serial_uart_stm32f7xx.c
#define UART_RX_BUFFER_SIZE UART1_RX_BUFFER_SIZE
#define UART_TX_BUFFER_SIZE UART1_TX_BUFFER_SIZE


// ../inav/src/main/drivers/bus_spi_at32f43x.c
#ifdef USE_SPI
#ifndef SPI1_SCK_PIN
#define SPI1_NSS_PIN    PA4
#define SPI1_SCK_PIN    PA5
#define SPI1_MISO_PIN   PA6
#define SPI1_MOSI_PIN   PA7
#endif
#ifndef SPI2_SCK_PIN
#define SPI2_NSS_PIN    PB12
#define SPI2_SCK_PIN    PB13
#define SPI2_MISO_PIN   PB14
#define SPI2_MOSI_PIN   PB15
#endif
#ifndef SPI3_SCK_PIN
#define SPI3_NSS_PIN    PA15
#define SPI3_SCK_PIN    PC10
#define SPI3_MISO_PIN   PC11
#define SPI3_MOSI_PIN   PC12
#endif
#ifndef SPI1_NSS_PIN
#define SPI1_NSS_PIN NONE
#endif
#ifndef SPI2_NSS_PIN
#define SPI2_NSS_PIN NONE
#endif
#ifndef SPI3_NSS_PIN
#define SPI3_NSS_PIN NONE
#endif
    #define BR_CLEAR_MASK 0xFFC7
#endif


// ../inav/src/main/drivers/io_def.h
#define DEFIO_TAG(pinid) CONCAT(DEFIO_TAG__, pinid)
#define DEFIO_TAG__NONE 0
#define DEFIO_TAG_E(pinid) CONCAT(DEFIO_TAG_E__, pinid)
#define DEFIO_TAG_E__NONE 0
#define DEFIO_REC(pinid) CONCAT(DEFIO_REC__, pinid)
#define DEFIO_REC__NONE NULL
#define DEFIO_IO(pinid) (IO_t)DEFIO_REC(pinid)
#define DEFIO_REC_INDEXED(idx) (ioRecs + (idx))
#define DEFIO_TAG_MAKE(gpioid, pin) ((((gpioid) + 1) << 4) | (pin))
#define DEFIO_TAG_ISEMPTY(tag) (!(tag))
#define DEFIO_TAG_GPIOID(tag) (((tag) >> 4) - 1)
#define DEFIO_TAG_PIN(tag) ((tag) & 0x0f)


// ../inav/src/main/drivers/serial_softserial.c
#if defined(USE_SOFTSERIAL1) || defined(USE_SOFTSERIAL2)
#define RX_TOTAL_BITS 10
#define TX_TOTAL_BITS 10
#if defined(USE_SOFTSERIAL1) && defined(USE_SOFTSERIAL2)
#define MAX_SOFTSERIAL_PORTS 2
#else
#define MAX_SOFTSERIAL_PORTS 1
#endif
#define ICPOLARITY_RISING true
#define ICPOLARITY_FALLING false
#define STOP_BIT_MASK (1 << 0)
#define START_BIT_MASK (1 << (RX_TOTAL_BITS - 1))
#endif


// ../inav/src/main/drivers/display.h
#define SW_BLINK_CYCLE_MS 500
#define getBlinkOnOff()  ( (millis() / SW_BLINK_CYCLE_MS) & 1 )
#define _TEXT_ATTRIBUTES_BLINK_BIT          (1 << 0)
#define _TEXT_ATTRIBUTES_INVERTED_BIT       (1 << 1)
#define _TEXT_ATTRIBUTES_SOLID_BG_BIT       (1 << 2)
#define TEXT_ATTRIBUTES_NONE                0
#define TEXT_ATTRIBUTES_ADD_BLINK(x)        ((x) |= _TEXT_ATTRIBUTES_BLINK_BIT)
#define TEXT_ATTRIBUTES_ADD_INVERTED(x)     ((x) |= _TEXT_ATTRIBUTES_INVERTED_BIT)
#define TEXT_ATTRIBUTES_ADD_SOLID_BG(x)     ((x) |= _TEXT_ATTRIBUTES_SOLID_BG_BIT)
#define TEXT_ATTRIBUTES_REMOVE_BLINK(x)     ((x) &= ~_TEXT_ATTRIBUTES_BLINK_BIT)
#define TEXT_ATTRIBUTES_REMOVE_INVERTED(x)  ((x) &= ~_TEXT_ATTRIBUTES_INVERTED_BIT)
#define TEXT_ATTRIBUTES_REMOVE_SOLID_BG(x)  ((x) &= ~_TEXT_ATTRIBUTES_SOLID_BG_BIT)
#define TEXT_ATTRIBUTES_HAVE_BLINK(x)       (x & _TEXT_ATTRIBUTES_BLINK_BIT)
#define TEXT_ATTRIBUTES_HAVE_INVERTED(x)    (x & _TEXT_ATTRIBUTES_INVERTED_BIT)
#define TEXT_ATTRIBUTES_HAVE_SOLID_BG(x)    (x & _TEXT_ATTRIBUTES_SOLID_BG_BIT)


// ../inav/src/main/drivers/vtx_common.h
#define VTX_SETTINGS_MIN_BAND       1
#define VTX_SETTINGS_MAX_BAND       5
#define VTX_SETTINGS_MIN_CHANNEL    1
#define VTX_SETTINGS_MAX_CHANNEL    8
#define VTX_SETTINGS_BAND_COUNT     (VTX_SETTINGS_MAX_BAND - VTX_SETTINGS_MIN_BAND + 1)
#define VTX_SETTINGS_CHANNEL_COUNT  (VTX_SETTINGS_MAX_CHANNEL - VTX_SETTINGS_MIN_CHANNEL + 1)
#define VTX_SETTINGS_DEFAULT_BAND               4
#define VTX_SETTINGS_DEFAULT_CHANNEL            1
#define VTX_SETTINGS_DEFAULT_PITMODE_CHANNEL    1
#define VTX_SETTINGS_DEFAULT_LOW_POWER_DISARM   0
#if defined(USE_VTX_SMARTAUDIO) || defined(USE_VTX_TRAMP) || defined(USE_VTX_MSP)
#define VTX_SETTINGS_POWER_COUNT        8
#define VTX_SETTINGS_DEFAULT_POWER      1
#define VTX_SETTINGS_MIN_POWER          0
#define VTX_SETTINGS_MIN_USER_FREQ      5000
#define VTX_SETTINGS_MAX_USER_FREQ      5999
#define VTX_SETTINGS_FREQCMD
#define VTX_SETTINGS_MAX_POWER          (VTX_SETTINGS_POWER_COUNT - VTX_SETTINGS_MIN_POWER)
#else
#define VTX_SETTINGS_DEFAULT_POWER      0
#endif
#define VTXCOMMON_MSP_BANDCHAN_CHKVAL ((uint16_t)((7 << 3) + 7))


// ../inav/src/main/drivers/timer_def_at32f43x.h
#define timerDMASafeType_t  uint32_t
#define DEF_TIM_DMAMAP__D(dma, stream, channel)         DMA_TAG(dma, stream, channel)
#define DEF_TIM_DMAMAP__NONE                            DMA_NONE
#define DEF_TIM(tim, ch, pin, usage, flags, dmavar)     {               \
     tim,                                                               \
     IO_TAG(pin),                                                       \
     DEF_TIM_CHNL_ ## ch,                                               \
     DEF_TIM_OUTPUT(ch) | flags,                                        \
     IOCFG_AF_PP,                                                       \
     DEF_TIM_AF(TCH_## tim ## _ ## ch, pin),                            \
     usage,                                                             \
     DEF_TIM_DMAMAP(dmavar, tim ## _ ## ch),                            \
     DEF_TIM_DMA_REQUEST(tim ## _ ## ch)                                \
  }
#define DEF_TIM_AF(timch, pin)        CONCAT(DEF_TIM_AF__, DEF_TIM_AF__ ## pin ## __ ## timch)
#define DEF_TIM_AF__D(af_n, tim_n)    GPIO_MUX_ ## af_n
#define DEF_TIM_DMA_REQUEST(timch) \
    CONCAT(DEF_TIM_DMA_REQ__, DEF_TIM_TCH2BTCH(timch))
#define DEF_TIM_DMA_FULL \
    D(1, 1, 0), D(1, 2, 0), D(1, 3, 0), D(1, 4, 0), D(1, 5, 0), D(1, 6, 0), D(1, 7, 0), \
    D(2, 1, 0), D(2, 2, 0), D(2, 3, 0), D(2, 4, 0), D(2, 5, 0), D(2, 6, 0), D(2, 7, 0)
#define DEF_TIM_DMA__BTCH_TMR1_CH1    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR1_CH2    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR1_CH3    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR1_CH4    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR2_CH1    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR2_CH2    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR2_CH3    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR2_CH4    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR3_CH1    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR3_CH2    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR3_CH3    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR3_CH4    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR4_CH1    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR4_CH2    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR4_CH3    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR4_CH4    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR5_CH1    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR5_CH2    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR5_CH3    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR5_CH4    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR8_CH1    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR8_CH2    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR8_CH3    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR8_CH4    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR15_CH1   DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR15_CH2   NONE
#define DEF_TIM_DMA__BTCH_TMR16_CH1   DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR17_CH1   DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR20_CH1   DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR20_CH2   DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR20_CH3   DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR20_CH4   DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR9_CH1    NONE
#define DEF_TIM_DMA__BTCH_TMR9_CH2    NONE
#define DEF_TIM_DMA__BTCH_TMR10_CH1   NONE
#define DEF_TIM_DMA__BTCH_TMR11_CH1   NONE
#define DEF_TIM_DMA__BTCH_TMR12_CH1   NONE
#define DEF_TIM_DMA__BTCH_TMR12_CH2   NONE
#define DEF_TIM_DMA__BTCH_TMR13_CH1   NONE
#define DEF_TIM_DMA__BTCH_TMR14_CH1   NONE
#define DEF_TIM_DMA__BTCH_TMR1_UP     DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR2_UP     DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR3_UP     DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR4_UP     DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR5_UP     DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR6_UP     DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR7_UP     DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR8_UP     DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR9_UP     DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR10_UP    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR11_UP    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR12_UP    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR13_UP    DEF_TIM_DMA_FULL
#define DEF_TIM_DMA__BTCH_TMR14_UP    DEF_TIM_DMA_FULL
#define DMA_REQUEST_NONE 255
#define DEF_TIM_DMA_REQ__BTCH_TMR1_CH1    DMAMUX_DMAREQ_ID_TMR1_CH1
#define DEF_TIM_DMA_REQ__BTCH_TMR1_CH2    DMAMUX_DMAREQ_ID_TMR1_CH2
#define DEF_TIM_DMA_REQ__BTCH_TMR1_CH3    DMAMUX_DMAREQ_ID_TMR1_CH3
#define DEF_TIM_DMA_REQ__BTCH_TMR1_CH4    DMAMUX_DMAREQ_ID_TMR1_CH4
#define DEF_TIM_DMA_REQ__BTCH_TMR2_CH1    DMAMUX_DMAREQ_ID_TMR2_CH1
#define DEF_TIM_DMA_REQ__BTCH_TMR2_CH2    DMAMUX_DMAREQ_ID_TMR2_CH2
#define DEF_TIM_DMA_REQ__BTCH_TMR2_CH3    DMAMUX_DMAREQ_ID_TMR2_CH3
#define DEF_TIM_DMA_REQ__BTCH_TMR2_CH4    DMAMUX_DMAREQ_ID_TMR2_CH4
#define DEF_TIM_DMA_REQ__BTCH_TMR3_CH1    DMAMUX_DMAREQ_ID_TMR3_CH1
#define DEF_TIM_DMA_REQ__BTCH_TMR3_CH2    DMAMUX_DMAREQ_ID_TMR3_CH2
#define DEF_TIM_DMA_REQ__BTCH_TMR3_CH3    DMAMUX_DMAREQ_ID_TMR3_CH3
#define DEF_TIM_DMA_REQ__BTCH_TMR3_CH4    DMAMUX_DMAREQ_ID_TMR3_CH4
#define DEF_TIM_DMA_REQ__BTCH_TMR4_CH1    DMAMUX_DMAREQ_ID_TMR4_CH1
#define DEF_TIM_DMA_REQ__BTCH_TMR4_CH2    DMAMUX_DMAREQ_ID_TMR4_CH2
#define DEF_TIM_DMA_REQ__BTCH_TMR4_CH3    DMAMUX_DMAREQ_ID_TMR4_CH3
#define DEF_TIM_DMA_REQ__BTCH_TMR4_CH4    DMAMUX_DMAREQ_ID_TMR4_CH4
#define DEF_TIM_DMA_REQ__BTCH_TMR5_CH1    DMAMUX_DMAREQ_ID_TMR5_CH1
#define DEF_TIM_DMA_REQ__BTCH_TMR5_CH2    DMAMUX_DMAREQ_ID_TMR5_CH2
#define DEF_TIM_DMA_REQ__BTCH_TMR5_CH3    DMAMUX_DMAREQ_ID_TMR5_CH3
#define DEF_TIM_DMA_REQ__BTCH_TMR5_CH4    DMAMUX_DMAREQ_ID_TMR5_CH4
#define DEF_TIM_DMA_REQ__BTCH_TMR8_CH1    DMAMUX_DMAREQ_ID_TMR8_CH1
#define DEF_TIM_DMA_REQ__BTCH_TMR8_CH2    DMAMUX_DMAREQ_ID_TMR8_CH2
#define DEF_TIM_DMA_REQ__BTCH_TMR8_CH3    DMAMUX_DMAREQ_ID_TMR8_CH3
#define DEF_TIM_DMA_REQ__BTCH_TMR8_CH4    DMAMUX_DMAREQ_ID_TMR8_CH4
#define DEF_TIM_DMA_REQ__BTCH_TMR20_CH1   DMAMUX_DMAREQ_ID_TMR20_CH1
#define DEF_TIM_DMA_REQ__BTCH_TMR20_CH2   DMAMUX_DMAREQ_ID_TMR20_CH2
#define DEF_TIM_DMA_REQ__BTCH_TMR20_CH3   DMAMUX_DMAREQ_ID_TMR20_CH3
#define DEF_TIM_DMA_REQ__BTCH_TMR20_CH4   DMAMUX_DMAREQ_ID_TMR20_CH4
#define DEF_TIM_DMA_REQ__BTCH_TMR1_UP     DMAMUX_DMAREQ_ID_TMR1_OVERFLOW
#define DEF_TIM_DMA_REQ__BTCH_TMR2_UP     DMAMUX_DMAREQ_ID_TMR2_OVERFLOW
#define DEF_TIM_DMA_REQ__BTCH_TMR3_UP     DMAMUX_DMAREQ_ID_TMR3_OVERFLOW
#define DEF_TIM_DMA_REQ__BTCH_TMR4_UP     DMAMUX_DMAREQ_ID_TMR4_OVERFLOW
#define DEF_TIM_DMA_REQ__BTCH_TMR5_UP     DMAMUX_DMAREQ_ID_TMR5_OVERFLOW
#define DEF_TIM_DMA_REQ__BTCH_TMR8_UP     DMAMUX_DMAREQ_ID_TMR8_OVERFLOW
#define DEF_TIM_DMA_REQ__BTCH_TMR20_UP    DMAMUX_DMAREQ_ID_TMR20_OVERFLOW
#define DEF_TIM_AF__PA0__TCH_TMR2_CH1     D(1, 2)
#define DEF_TIM_AF__PA1__TCH_TMR2_CH2     D(1, 2)
#define DEF_TIM_AF__PA2__TCH_TMR2_CH3     D(1, 2)
#define DEF_TIM_AF__PA3__TCH_TMR2_CH4     D(1, 2)
#define DEF_TIM_AF__PA5__TCH_TMR2_CH1     D(1, 2)
#define DEF_TIM_AF__PA7__TCH_TMR1_CH1N    D(1, 1)
#define DEF_TIM_AF__PA8__TCH_TMR1_CH1     D(1, 1)
#define DEF_TIM_AF__PA9__TCH_TMR1_CH2     D(1, 1)
#define DEF_TIM_AF__PA10__TCH_TMR1_CH3    D(1, 1)
#define DEF_TIM_AF__PA11__TCH_TMR1_CH4    D(1, 1)
#define DEF_TIM_AF__PA15__TCH_TMR2_CH1    D(1, 2)
#define DEF_TIM_AF__PA0__TCH_TMR5_CH1     D(2, 5)
#define DEF_TIM_AF__PA1__TCH_TMR5_CH2     D(2, 5)
#define DEF_TIM_AF__PA2__TCH_TMR5_CH3     D(2, 5)
#define DEF_TIM_AF__PA3__TCH_TMR5_CH4     D(2, 5)
#define DEF_TIM_AF__PA6__TCH_TMR3_CH1     D(2, 3)
#define DEF_TIM_AF__PA7__TCH_TMR3_CH2     D(2, 3)
#define DEF_TIM_AF__PA2__TCH_TMR9_CH1     D(3, 9)
#define DEF_TIM_AF__PA3__TCH_TMR9_CH2     D(3, 9)
#define DEF_TIM_AF__PA5__TCH_TMR8_CH1N    D(3, 8)
#define DEF_TIM_AF__PA7__TCH_TMR8_CH1N    D(3, 8)
#define DEF_TIM_AF__PA6__TCH_TMR13_CH1    D(9, 13)
#define DEF_TIM_AF__PA7__TCH_TMR14_CH1    D(9, 14)
#define DEF_TIM_AF__PB0__TCH_TMR1_CH2N    D(1, 1)
#define DEF_TIM_AF__PB1__TCH_TMR1_CH3N    D(1, 1)
#define DEF_TIM_AF__PB2__TCH_TMR2_CH4     D(1, 2)
#define DEF_TIM_AF__PB3__TCH_TMR2_CH2     D(1, 2)
#define DEF_TIM_AF__PB8__TCH_TMR2_CH1     D(1, 2)
#define DEF_TIM_AF__PB9__TCH_TMR2_CH2     D(1, 2)
#define DEF_TIM_AF__PB10__TCH_TMR2_CH3    D(1, 2)
#define DEF_TIM_AF__PB11__TCH_TMR2_CH4    D(1, 2)
#define DEF_TIM_AF__PB13__TCH_TMR1_CH1N   D(1, 1)
#define DEF_TIM_AF__PB14__TCH_TMR1_CH2N   D(1, 1)
#define DEF_TIM_AF__PB15__TCH_TMR1_CH3N   D(1, 1)
#define DEF_TIM_AF__PB0__TCH_TMR3_CH3     D(2, 3)
#define DEF_TIM_AF__PB1__TCH_TMR3_CH4     D(2, 3)
#define DEF_TIM_AF__PB2__TCH_TMR20_CH1    D(2, 20)
#define DEF_TIM_AF__PB4__TCH_TMR3_CH1     D(2, 3)
#define DEF_TIM_AF__PB5__TCH_TMR3_CH2     D(2, 3)
#define DEF_TIM_AF__PB6__TCH_TMR4_CH1     D(2, 4)
#define DEF_TIM_AF__PB7__TCH_TMR4_CH2     D(2, 4)
#define DEF_TIM_AF__PB8__TCH_TMR4_CH3     D(2, 4)
#define DEF_TIM_AF__PB9__TCH_TMR4_CH4     D(2, 4)
#define DEF_TIM_AF__PB11__TCH_TMR5_CH4     D(2, 5)
#define DEF_TIM_AF__PB12__TCH_TMR5_CH1     D(2, 5)
#define DEF_TIM_AF__PB0__TCH_TMR8_CH2N    D(3, 8)
#define DEF_TIM_AF__PB1__TCH_TMR8_CH3N    D(3, 8)
#define DEF_TIM_AF__PB8__TCH_TMR10_CH1    D(3, 10)
#define DEF_TIM_AF__PB9__TCH_TMR11_CH1    D(3, 11)
#define DEF_TIM_AF__PB14__TCH_TMR8_CH2N   D(3, 8)
#define DEF_TIM_AF__PB15__TCH_TMR8_CH3N   D(3, 8)
#define DEF_TIM_AF__PB14__TCH_TMR12_CH1   D(9, 12)
#define DEF_TIM_AF__PB15__TCH_TMR12_CH2   D(9, 12)
#define DEF_TIM_AF__PC2__TCH_TMR20_CH2    D(2, 20)
#define DEF_TIM_AF__PC6__TCH_TMR3_CH1     D(2, 3)
#define DEF_TIM_AF__PC7__TCH_TMR3_CH2     D(2, 3)
#define DEF_TIM_AF__PC8__TCH_TMR3_CH3     D(2, 3)
#define DEF_TIM_AF__PC9__TCH_TMR3_CH4     D(2, 3)
#define DEF_TIM_AF__PC10__TCH_TMR5_CH2    D(2, 5)
#define DEF_TIM_AF__PC11__TCH_TMR5_CH3    D(2, 5)
#define DEF_TIM_AF__PC4__TCH_TMR9_CH1     D(3, 9)
#define DEF_TIM_AF__PC5__TCH_TMR9_CH2     D(3, 9)
#define DEF_TIM_AF__PC6__TCH_TMR8_CH1     D(3, 8)
#define DEF_TIM_AF__PC7__TCH_TMR8_CH2     D(3, 8)
#define DEF_TIM_AF__PC8__TCH_TMR8_CH3     D(3, 8)
#define DEF_TIM_AF__PC9__TCH_TMR8_CH4     D(3, 8)
#define DEF_TIM_AF__PC12__TCH_TMR11_CH1   D(3, 11)
#define DEF_TIM_AF__PD12__TCH_TMR4_CH1    D(2, 4)
#define DEF_TIM_AF__PD13__TCH_TMR4_CH2    D(2, 4)
#define DEF_TIM_AF__PD14__TCH_TMR4_CH3    D(2, 4)
#define DEF_TIM_AF__PD15__TCH_TMR4_CH4    D(2, 4)
#define DEF_TIM_AF__PE8__TCH_TMR1_CH1N    D(1, 1)
#define DEF_TIM_AF__PE9__TCH_TMR1_CH1     D(1, 1)
#define DEF_TIM_AF__PE10__TCH_TMR1_CH2N   D(1, 1)
#define DEF_TIM_AF__PE11__TCH_TMR1_CH2    D(1, 1)
#define DEF_TIM_AF__PE12__TCH_TMR1_CH3N   D(1, 1)
#define DEF_TIM_AF__PE13__TCH_TMR1_CH3    D(1, 1)
#define DEF_TIM_AF__PE14__TCH_TMR1_CH4    D(1, 1)
#define DEF_TIM_AF__PE3__TCH_TMR3_CH1     D(3, 3)
#define DEF_TIM_AF__PE4__TCH_TMR3_CH2     D(3, 3)
#define DEF_TIM_AF__PE5__TCH_TMR3_CH3     D(3, 3)
#define DEF_TIM_AF__PE6__TCH_TMR3_CH4     D(3, 3)
#define DEF_TIM_AF__PE5__TCH_TMR9_CH1     D(3, 9)
#define DEF_TIM_AF__PE6__TCH_TMR9_CH2     D(3, 9)
#define DEF_TIM_AF__PE1__TCH_TMR20_CH4     D(6, 20)
#define DEF_TIM_AF__PE2__TCH_TMR20_CH1     D(6, 20)
#define DEF_TIM_AF__PE3__TCH_TMR20_CH2     D(6, 20)
#define DEF_TIM_AF__PE4__TCH_TMR20_CH1N     D(6, 20)
#define DEF_TIM_AF__PE5__TCH_TMR20_CH2N     D(6, 20)
#define DEF_TIM_AF__PE6__TCH_TMR20_CH3N     D(6, 20)
#define DEF_TIM_AF__PF2__TCH_TMR20_CH3      D(2, 20)
#define DEF_TIM_AF__PF3__TCH_TMR20_CH4      D(2, 20)
#define DEF_TIM_AF__PF4__TCH_TMR20_CH1N      D(2, 20)
#define DEF_TIM_AF__PF5__TCH_TMR20_CH2N     D(2, 20)
#define DEF_TIM_AF__PF6__TCH_TMR20_CH4      D(2, 20)
#define DEF_TIM_AF__PF10__TCH_TMR5_CH4      D(2, 5)
#define DEF_TIM_AF__PF12__TCH_TMR20_CH1     D(2, 20)
#define DEF_TIM_AF__PF13__TCH_TMR20_CH2     D(2, 20)
#define DEF_TIM_AF__PF14__TCH_TMR20_CH3     D(2, 20)
#define DEF_TIM_AF__PF15__TCH_TMR20_CH4     D(2, 20)
#define DEF_TIM_AF__PF6__TCH_TMR10_CH1    D(3, 10)
#define DEF_TIM_AF__PF7__TCH_TMR11_CH1    D(3, 11)
#define DEF_TIM_AF__PF8__TCH_TMR13_CH1    D(9, 13)
#define DEF_TIM_AF__PF9__TCH_TMR14_CH1    D(9, 14)
#define DEF_TIM_AF__PG0__TCH_TMR20_CH1N    D(2, 20)
#define DEF_TIM_AF__PG1__TCH_TMR20_CH2N    D(2, 20)
#define DEF_TIM_AF__PG2__TCH_TMR20_CH3N    D(2, 20)
#define DEF_TIM_AF__PH2__TCH_TMR5_CH1    D(2, 5)
#define DEF_TIM_AF__PH3__TCH_TMR5_CH2    D(2, 5)


// ../inav/src/main/drivers/adc_stm32f4xx.c
#if !defined(ADC1_DMA_STREAM)
#define ADC1_DMA_STREAM DMA2_Stream0
#endif


// ../inav/src/main/drivers/headtracker_common.h
#define MAX_HEADTRACKER_DATA_AGE_US HZ2US(25)
#define HEADTRACKER_RANGE_MIN   -2048
#define HEADTRACKER_RANGE_MAX   2047


// ../inav/src/main/drivers/adc.h
#if defined(USE_ADC_AVERAGING)
#if !defined(ADC_AVERAGE_N_SAMPLES)
#define ADC_AVERAGE_N_SAMPLES   20
#endif
#else
#define ADC_AVERAGE_N_SAMPLES   1
#endif


// ../inav/src/main/drivers/display_font_metadata.h
#define FONT_CHR_IS_METADATA(chr) ((chr)->data[0] == 'I' && \
    (chr)->data[1] == 'N' && \
    (chr)->data[2] == 'A' && \
    (chr)->data[3] == 'V')
#define FONT_METADATA_CHR_INDEX 255
#define FONT_METADATA_CHR_INDEX_2ND_PAGE 256


// ../inav/src/main/drivers/resource.h
#define RESOURCE_INDEX(x) (x + 1)


// ../inav/src/main/drivers/max7456.h
#ifndef MAX7456_WHITEBRIGHTNESS
  #define MAX7456_WHITEBRIGHTNESS 0x01
#endif
#ifndef MAX7456_BLACKBRIGHTNESS
  #define MAX7456_BLACKBRIGHTNESS 0x00
#endif
#define MAX7456_BWBRIGHTNESS ((MAX7456_BLACKBRIGHTNESS << 2) | MAX7456_WHITEBRIGHTNESS)
#define MAX7456_CHARS_PER_LINE          30
#define MAX7456_LINES_NTSC          13
#define MAX7456_LINES_PAL           16
#define MAX7456_BUFFER_CHARS_NTSC   (MAX7456_LINES_NTSC * MAX7456_CHARS_PER_LINE)
#define MAX7456_BUFFER_CHARS_PAL    (MAX7456_LINES_PAL * MAX7456_CHARS_PER_LINE)
#define MAX7456_MODE_INVERT   (1 << 3)
#define MAX7456_MODE_BLINK    (1 << 4)
#define MAX7456_MODE_SOLID_BG (1 << 5)


// ../inav/src/main/drivers/osd_symbols.h
#if defined(USE_OSD) || defined(OSD_UNIT_TEST)
#define SYM_RSSI                    0x01
#define SYM_LQ                      0x02
#define SYM_LAT                     0x03
#define SYM_LON                     0x04
#define SYM_AZIMUTH                 0x05
#define SYM_TELEMETRY_0             0x06
#define SYM_TELEMETRY_1             0x07
#define SYM_SAT_L                   0x08
#define SYM_SAT_R                   0x09
#define SYM_HOME_NEAR               0x0A
#define SYM_DEGREES                 0x0B
#define SYM_HEADING                 0x0C
#define SYM_SCALE                   0x0D
#define SYM_HDP_L                   0x0E
#define SYM_HDP_R                   0x0F
#define SYM_HOME                    0x10
#define SYM_2RSS                    0x11
#define SYM_DB                      0x12
#define SYM_DBM                     0x13
#define SYM_SNR                     0x14
#define SYM_AH_DECORATION_UP        0x15
#define SYM_AH_DECORATION_DOWN      0x16
#define SYM_DECORATION              0x17
#define SYM_VOLT                    0x1F
#define SYM_MAH                     0x99
#define SYM_AH_KM                   0x22
#define SYM_AH_MI                   0x24
#define SYM_VTX_POWER               0x27
#define SYM_AH_NM                   0x3F
#define SYM_MAH_NM_0                0x60
#define SYM_MAH_NM_1                0x61
#define SYM_MAH_KM_0                0x6B
#define SYM_MAH_KM_1                0x6C
#define SYM_MILLIOHM                0x62
#define SYM_BATT_FULL               0x63
#define SYM_BATT_5                  0x64
#define SYM_BATT_4                  0x65
#define SYM_BATT_3                  0x66
#define SYM_BATT_2                  0x67
#define SYM_BATT_1                  0x68
#define SYM_BATT_EMPTY              0x69
#define SYM_AMP                     0x6A
#define SYM_WH                      0x6D
#define SYM_WH_KM                   0x6E
#define SYM_WH_MI                   0x6F
#define SYM_WH_NM                   0x70
#define SYM_WATT                    0x71
#define SYM_MW                      0x72
#define SYM_KILOWATT                0x73
#define SYM_FT                      0x74
#define SYM_TRIP_DIST               0x75
#define SYM_TOTAL                   0x75
#define SYM_ALT_M                   0x76
#define SYM_ALT_KM                  0x77
#define SYM_ALT_FT                  0x78
#define SYM_ALT_KFT                 0x79
#define SYM_DIST_M                  0x7A
#define SYM_DIST_KM                 0x7E
#define SYM_DIST_FT                 0x7F
#define SYM_DIST_MI                 0x80
#define SYM_DIST_NM                 0x81
#define SYM_M                       0x82
#define SYM_KM                      0x83
#define SYM_MI                      0x84
#define SYM_NM                      0x85
#define SYM_WIND_HORIZONTAL         0x86
#define SYM_WIND_VERTICAL           0x87
#define SYM_3D_KMH                  0x88
#define SYM_3D_MPH                  0x89
#define SYM_3D_KT                   0x8A
#define SYM_RPM                     0x8B
#define SYM_AIR                     0x8C
#define SYM_FTS                     0x8D
#define SYM_100FTM                  0x8E
#define SYM_MS                      0x8F
#define SYM_KMH                     0x90
#define SYM_MPH                     0x91
#define SYM_KT                      0x92
#define SYM_MAH_MI_0                0x93
#define SYM_MAH_MI_1                0x94
#define SYM_THR                     0x95
#define SYM_TEMP_F                  0x96
#define SYM_TEMP_C                  0x97
#define SYM_BLANK                   0x20
#define SYM_ON_H                    0x9A
#define SYM_FLY_H                   0x9B
#define SYM_ON_M                    0x9E
#define SYM_FLY_M                   0x9F
#define SYM_GLIDESLOPE              0x9C
#define SYM_WAYPOINT                0x9D
#define SYM_CLOCK                   0xA0
#define SYM_ZERO_HALF_TRAILING_DOT  0xA1
#define SYM_ZERO_HALF_LEADING_DOT   0xB1
#define SYM_AUTO_THR0               0xAB
#define SYM_AUTO_THR1               0xAC
#define SYM_ROLL_LEFT               0xAD
#define SYM_ROLL_LEVEL              0xAE
#define SYM_ROLL_RIGHT              0xAF
#define SYM_PITCH_UP                0xB0
#define SYM_PITCH_DOWN              0xBB
#define SYM_GFORCE                  0xBC
#define SYM_GFORCE_X                0xBD
#define SYM_GFORCE_Y                0xBE
#define SYM_GFORCE_Z                0xBF
#define SYM_BARO_TEMP               0xC0
#define SYM_IMU_TEMP                0xC1
#define SYM_TEMP                    0xC2
#define SYM_TEMP_SENSOR_FIRST       0xC2
#define SYM_ESC_TEMP                0xC3
#define SYM_TEMP_SENSOR_LAST        0xC7
#define TEMP_SENSOR_SYM_COUNT       (SYM_TEMP_SENSOR_LAST - SYM_TEMP_SENSOR_FIRST + 1)
#define SYM_HEADING_N               0xC8
#define SYM_HEADING_S               0xC9
#define SYM_HEADING_E               0xCA
#define SYM_HEADING_W               0xCB
#define SYM_HEADING_DIVIDED_LINE    0xCC
#define SYM_HEADING_LINE            0xCD
#define SYM_MAX                     0xCE
#define SYM_PROFILE                 0xCF
#define SYM_SWITCH_INDICATOR_LOW    0xD0
#define SYM_SWITCH_INDICATOR_MID    0xD1
#define SYM_SWITCH_INDICATOR_HIGH   0xD2
#define SYM_AH                      0xD3
#define SYM_GLIDE_DIST              0xD4
#define SYM_GLIDE_MINS              0xD5
#define SYM_AH_V_FT_0               0xD6
#define SYM_AH_V_FT_1               0xD7
#define SYM_AH_V_M_0                0xD8
#define SYM_AH_V_M_1                0xD9
#define SYM_FLIGHT_MINS_REMAINING   0xDA
#define SYM_FLIGHT_HOURS_REMAINING  0xDB
#define SYM_GROUND_COURSE           0xDC
#define SYM_ALERT                   0xDD
#define SYM_MIN_GROUND_SPEED        0xDE
#define SYM_TERRAIN_FOLLOWING       0xFB
#define SYM_CROSS_TRACK_ERROR       0xFC
#define SYM_ADSB                    0xFD
#define SYM_BLACKBOX                0xFE
#define SYM_LOGO_START              0x101
#define SYM_LOGO_WIDTH              10
#define SYM_LOGO_HEIGHT             4
#define SYM_AH_LEFT                 0x12C
#define SYM_AH_RIGHT                0x12D
#define SYM_AH_DECORATION_MIN       0x12E
#define SYM_AH_DECORATION           0x131
#define SYM_AH_DECORATION_MAX       0x133
#define SYM_AH_DECORATION_COUNT (SYM_AH_DECORATION_MAX - SYM_AH_DECORATION_MIN + 1)
#define SYM_AH_CH_LEFT              0x13A
#define SYM_AH_CH_RIGHT             0x13B
#define SYM_ARROW_UP                0x13C
#define SYM_ARROW_2                 0x13D
#define SYM_ARROW_3                 0x13E
#define SYM_ARROW_4                 0x13F
#define SYM_ARROW_RIGHT             0x140
#define SYM_ARROW_6                 0x141
#define SYM_ARROW_7                 0x142
#define SYM_ARROW_8                 0x143
#define SYM_ARROW_DOWN              0x144
#define SYM_ARROW_10                0x145
#define SYM_ARROW_11                0x146
#define SYM_ARROW_12                0x147
#define SYM_ARROW_LEFT              0x148
#define SYM_ARROW_14                0x149
#define SYM_ARROW_15                0x14A
#define SYM_ARROW_16                0x14B
#define SYM_AH_H_START              0x14C
#define SYM_AH_V_START              0x15A
#define SYM_VARIO_UP_2A             0x155
#define SYM_VARIO_UP_1A             0x156
#define SYM_VARIO_DOWN_1A           0x157
#define SYM_VARIO_DOWN_2A           0x158
#define SYM_ALT                     0x159
#define SYM_HUD_SIGNAL_0            0x160
#define SYM_HUD_SIGNAL_1            0x161
#define SYM_HUD_SIGNAL_2            0x162
#define SYM_HUD_SIGNAL_3            0x163
#define SYM_HUD_SIGNAL_4            0x164
#define SYM_HOME_DIST               0x165
#define SYM_AH_CH_CENTER            0x166
#define SYM_FLIGHT_DIST_REMAINING   0x167
#define SYM_ODOMETER                0x168
#define SYM_RX_BAND                 0x169
#define SYM_RX_MODE                 0x16A
#define SYM_THR_GAUGE_EMPTY         0x16B
#define SYM_THR_GAUGE_HALF          0x16C
#define SYM_THR_GAUGE_FULL          0x16D
#define SYM_AH_CH_TYPE3             0x190
#define SYM_AH_CH_TYPE4             0x193
#define SYM_AH_CH_TYPE5             0x196
#define SYM_AH_CH_TYPE6             0x199
#define SYM_AH_CH_TYPE7             0x19C
#define SYM_AH_CH_TYPE8             0x19F
#define SYM_AH_CH_AIRCRAFT0         0x1A2
#define SYM_AH_CH_AIRCRAFT1         0x1A3
#define SYM_AH_CH_AIRCRAFT2         0x1A4
#define SYM_AH_CH_AIRCRAFT3         0x1A5
#define SYM_AH_CH_AIRCRAFT4         0x1A6
#define SYM_HUD_ARROWS_L1           0x1AE
#define SYM_HUD_ARROWS_L2           0x1AF
#define SYM_HUD_ARROWS_L3           0x1B0
#define SYM_HUD_ARROWS_R1           0x1B1
#define SYM_HUD_ARROWS_R2           0x1B2
#define SYM_HUD_ARROWS_R3           0x1B3
#define SYM_HUD_ARROWS_U1           0x1B4
#define SYM_HUD_ARROWS_U2           0x1B5
#define SYM_HUD_ARROWS_U3           0x1B6
#define SYM_HUD_ARROWS_D1           0x1B7
#define SYM_HUD_ARROWS_D2           0x1B8
#define SYM_HUD_ARROWS_D3           0x1B9
#define SYM_HUD_CARDINAL            0x1BA
#define SYM_SERVO_PAN_IS_CENTRED    0x1C6
#define SYM_SERVO_PAN_IS_OFFSET_L   0x1C7
#define SYM_SERVO_PAN_IS_OFFSET_R   0x1C8
#define SYM_PILOT_LOGO_SML_L        0x1D5
#define SYM_PILOT_LOGO_SML_C        0x1D6
#define SYM_PILOT_LOGO_SML_R        0x1D7
#define SYM_PILOT_LOGO_LRG_START    0x1D8
#else
#define TEMP_SENSOR_SYM_COUNT       0
#endif


// ../inav/src/main/drivers/bus_spi_hal_ll.c
#ifndef SPI1_SCK_PIN
#define SPI1_NSS_PIN    PA4
#define SPI1_SCK_PIN    PA5
#define SPI1_MISO_PIN   PA6
#define SPI1_MOSI_PIN   PA7
#endif
#ifndef SPI2_SCK_PIN
#define SPI2_NSS_PIN    PB12
#define SPI2_SCK_PIN    PB13
#define SPI2_MISO_PIN   PB14
#define SPI2_MOSI_PIN   PB15
#endif
#ifndef SPI3_SCK_PIN
#define SPI3_NSS_PIN    PA15
#define SPI3_SCK_PIN    PB3
#define SPI3_MISO_PIN   PB4
#define SPI3_MOSI_PIN   PB5
#endif
#ifndef SPI4_SCK_PIN
#define SPI4_NSS_PIN    PA15
#define SPI4_SCK_PIN    PB3
#define SPI4_MISO_PIN   PB4
#define SPI4_MOSI_PIN   PB5
#endif
#ifndef SPI1_NSS_PIN
#define SPI1_NSS_PIN NONE
#endif
#ifndef SPI2_NSS_PIN
#define SPI2_NSS_PIN NONE
#endif
#ifndef SPI3_NSS_PIN
#define SPI3_NSS_PIN NONE
#endif
#ifndef SPI4_NSS_PIN
#define SPI4_NSS_PIN NONE
#endif


// ../inav/src/main/drivers/flash_m25p16.h
#define M25P16_PAGESIZE 256


// ../inav/src/main/drivers/light_ws2811strip.h
#define WS2811_LED_STRIP_LENGTH 128
#define WS2811_BITS_PER_LED 24
#define WS2811_DELAY_BUFFER_LENGTH 42
#define WS2811_DATA_BUFFER_SIZE (WS2811_BITS_PER_LED * WS2811_LED_STRIP_LENGTH)
#define WS2811_DMA_BUFFER_SIZE (WS2811_DELAY_BUFFER_LENGTH + WS2811_DATA_BUFFER_SIZE + 1)
#define WS2811_TIMER_HZ         2400000
#define WS2811_CARRIER_HZ       800000


// ../inav/src/main/drivers/timer_impl.h
#if defined(AT32F43x)
#define IMPL_TIM_IT_UPDATE_INTERRUPT      TMR_OVF_INT
#define TIM_IT_CCx(chIdx)                 (TMR_C1_INT << (chIdx))
#define _TIM_IRQ_HANDLER2(name, i, j)                                   \
    void name(void)                                                     \
    {                                                                   \
        impl_timerCaptureCompareHandler(TMR ## i, timerCtx[i - 1]); \
        impl_timerCaptureCompareHandler(TMR ## j, timerCtx[j - 1]); \
    } struct dummy
#define _TIM_IRQ_HANDLER(name, i)                                       \
    void name(void)                                                     \
    {                                                                   \
        impl_timerCaptureCompareHandler(TMR ## i, timerCtx[i - 1]); \
    } struct dummy
#else
#if defined(USE_HAL_DRIVER)
# define IMPL_TIM_IT_UPDATE_INTERRUPT      TIM_IT_UPDATE
# define TIM_IT_CCx(chIdx)                 (TIM_IT_CC1 << (chIdx))
#else
#define IMPL_TIM_IT_UPDATE_INTERRUPT      TIM_IT_Update
#define TIM_IT_CCx(chIdx)                 (TIM_IT_CC1 << (chIdx))
#endif
#define _TIM_IRQ_HANDLER2(name, i, j)                                   \
    void name(void)                                                     \
    {                                                                   \
        impl_timerCaptureCompareHandler(TIM ## i, timerCtx[i - 1]); \
        impl_timerCaptureCompareHandler(TIM ## j, timerCtx[j - 1]); \
    } struct dummy
#define _TIM_IRQ_HANDLER(name, i)                                       \
    void name(void)                                                     \
    {                                                                   \
        impl_timerCaptureCompareHandler(TIM ## i, timerCtx[i - 1]); \
    } struct dummy
#endif


// ../inav/src/main/drivers/display.c
#define DISPLAY_MAX_STRING_SIZE 30


// ../inav/src/main/drivers/irlock.c
#define IRLOCK_OBJECT_SYNC ((uint16_t)0xaa55)
#define IRLOCK_FRAME_SYNC ((uint32_t)(IRLOCK_OBJECT_SYNC | (IRLOCK_OBJECT_SYNC << 16)))


// ../inav/src/main/drivers/lights_io.c
#ifdef USE_LIGHTS
#ifndef LIGHTS_OUTPUT_MODE
    #define LIGHTS_OUTPUT_MODE IOCFG_OUT_PP
#endif
#endif


// ../inav/src/main/drivers/pwm_output.h
#if defined(WS2811_PIN)
#define MAX_PWM_OUTPUTS (MAX_PWM_OUTPUT_PORTS + 1)
#else
#define MAX_PWM_OUTPUTS (MAX_PWM_OUTPUT_PORTS)
#endif


// ../inav/src/main/drivers/stack_check.c
#define STACK_FILL_CHAR 0xa5


// ../inav/src/main/drivers/dma.h
#define DMA_TAG(dma, stream, channel)   ( (((dma) & 0x03) << 12) | (((stream) & 0x0F) << 8) | (((channel) & 0xFF) << 0) )
#define DMA_NONE                        (0)
#define DMATAG_GET_DMA(x)               ( ((x) >> 12) & 0x03 )
#define DMATAG_GET_STREAM(x)            ( ((x) >> 8)  & 0x0F )
#define DMATAG_GET_CHANNEL(x)           ( ((x) >> 0)  & 0xFF )
#if defined(AT32F43x)
    #define DMA_IT_TCIF                         ((uint32_t)0x00000002)
    #define DMA_IT_HTIF                         ((uint32_t)0x00000004)
    #define DMA_IT_DMEIF                        ((uint32_t)0x00000008)
#else
    #define DMA_IT_TCIF                         ((uint32_t)0x00000020)
    #define DMA_IT_HTIF                         ((uint32_t)0x00000010)
    #define DMA_IT_TEIF                         ((uint32_t)0x00000008)
    #define DMA_IT_DMEIF                        ((uint32_t)0x00000004)
    #define DMA_IT_FEIF                         ((uint32_t)0x00000001)
#endif
#if defined(STM32F4) || defined(STM32F7) || defined(STM32H7)
#define DEFINE_DMA_CHANNEL(d, s, f) { \
                                        .tag = DMA_TAG(d, s, 0), \
                                        .dma = DMA##d, \
                                        .ref = DMA##d##_Stream##s, \
                                        .irqHandlerCallback = NULL, \
                                        .flagsShift = f, \
                                        .irqNumber = DMA##d##_Stream##s##_IRQn, \
                                        .userParam = 0 \
                                    }
#define DEFINE_DMA_IRQ_HANDLER(d, s, i) void DMA ## d ## _Stream ## s ## _IRQHandler(void) {\
                                                                if (dmaDescriptors[i].irqHandlerCallback)\
                                                                    dmaDescriptors[i].irqHandlerCallback(&dmaDescriptors[i]);\
                                                            }
#define DMA_CLEAR_FLAG(d, flag) if (d->flagsShift > 31) d->dma->HIFCR = (flag << (d->flagsShift - 32)); else d->dma->LIFCR = (flag << d->flagsShift)
#define DMA_GET_FLAG_STATUS(d, flag) (d->flagsShift > 31 ? d->dma->HISR & (flag << (d->flagsShift - 32)): d->dma->LISR & (flag << d->flagsShift))
#elif defined(AT32F43x)
#define DEFINE_DMA_CHANNEL(d, s, f) { \
                                        .tag = DMA_TAG(d, s, 0), \
                                        .dma = DMA##d, \
                                        .ref = DMA##d##_CHANNEL##s, \
                                        .irqHandlerCallback = NULL, \
                                        .flagsShift = f, \
                                        .irqNumber = DMA##d##_Channel##s##_IRQn, \
                                        .userParam = 0, \
                                        .dmaMuxref = (dmamux_channel_type *)DMA##d ## MUX_CHANNEL ##s \
                                    }
#define DEFINE_DMA_IRQ_HANDLER(d, s, i) void DMA ## d ## _Channel ## s ## _IRQHandler(void) {\
                                                                if (dmaDescriptors[i].irqHandlerCallback)\
                                                                    dmaDescriptors[i].irqHandlerCallback(&dmaDescriptors[i]);\
                                                            }
#define DMA_CLEAR_FLAG(d, flag) d->dma->clr = (flag << d->flagsShift)
#define DMA_GET_FLAG_STATUS(d, flag) (d->dma->sts & (flag << d->flagsShift))
#endif


// ../inav/src/main/drivers/bus_i2c_stm32f40x.c
#ifndef SOFT_I2C
#define GPIO_AF_I2C GPIO_AF_I2C1
#ifdef STM32F4
#if defined(USE_I2C_PULLUP)
#define IOCFG_I2C IO_CONFIG(GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_OD, GPIO_PuPd_UP)
#else
#define IOCFG_I2C IOCFG_AF_OD
#endif
#ifndef I2C1_SCL
#define I2C1_SCL PB8
#endif
#ifndef I2C1_SDA
#define I2C1_SDA PB9
#endif
#else
#ifndef I2C1_SCL
#define I2C1_SCL PB6
#endif
#ifndef I2C1_SDA
#define I2C1_SDA PB7
#endif
#define IOCFG_I2C   IO_CONFIG(GPIO_Mode_AF_OD, GPIO_Speed_50MHz)
#endif
#ifndef I2C2_SCL
#define I2C2_SCL PB10
#endif
#ifndef I2C2_SDA
#define I2C2_SDA PB11
#endif
#ifdef STM32F4
#ifndef I2C3_SCL
#define I2C3_SCL PA8
#endif
#ifndef I2C3_SDA
#define I2C3_SDA PB4
#endif
#endif
#endif


// ../inav/src/main/drivers/serial_uart_at32f43x.c
#define UART_RX_BUFFER_SIZE UART1_RX_BUFFER_SIZE
#define UART_TX_BUFFER_SIZE UART1_RX_BUFFER_SIZE


// ../inav/src/main/drivers/display_ug2864hsweg01.c
#ifdef USE_OLED_UG2864
#define INVERSE_CHAR_FORMAT 0x7f
#define NORMAL_CHAR_FORMAT  0x00
#endif


// ../inav/src/main/drivers/bus_i2c.h
#define I2C_TIMEOUT                  (10000)


// ../inav/src/main/drivers/pwm_output.c
#if !defined(SITL_BUILD)
#define MULTISHOT_5US_PW    (MULTISHOT_TIMER_HZ * 5 / 1000000.0f)
#define MULTISHOT_20US_MULT (MULTISHOT_TIMER_HZ * 20 / 1000000.0f / 1000.0f)
#ifdef USE_DSHOT
#define MOTOR_DSHOT600_HZ     12000000
#define MOTOR_DSHOT300_HZ     6000000
#define MOTOR_DSHOT150_HZ     3000000
#define DSHOT_MOTOR_BIT_0       7
#define DSHOT_MOTOR_BIT_1       14
#define DSHOT_MOTOR_BITLENGTH   20
#define DSHOT_DMA_BUFFER_SIZE   18
#define MAX_DMA_TIMERS          8
#define DSHOT_COMMAND_DELAY_US 1000
#define DSHOT_COMMAND_INTERVAL_US 10000
#define DSHOT_COMMAND_QUEUE_LENGTH 8
#define DHSOT_COMMAND_QUEUE_SIZE   DSHOT_COMMAND_QUEUE_LENGTH * sizeof(dshotCommands_e)
#endif
#endif


// ../inav/src/main/drivers/i2c_application.h
#ifndef __I2C_APPLICATION_H
#define __I2C_APPLICATION_H
#define I2C_EVENT_CHECK_NONE             ((uint32_t)0x00000000)
#define I2C_EVENT_CHECK_ACKFAIL          ((uint32_t)0x00000001)
#define I2C_EVENT_CHECK_STOP             ((uint32_t)0x00000002)
#endif


// ../inav/src/main/drivers/pinio.c
#ifdef USE_PINIO
#if defined(PINIO1_PIN)
#if !defined(PINIO1_FLAGS)
#define PINIO1_FLAGS 0
#endif
#endif
#if defined(PINIO2_PIN)
#if !defined(PINIO2_FLAGS)
#define PINIO2_FLAGS 0
#endif
#endif
#if defined(PINIO3_PIN)
#if !defined(PINIO3_FLAGS)
#define PINIO3_FLAGS 0
#endif
#endif
#if defined(PINIO4_PIN)
#if !defined(PINIO4_FLAGS)
#define PINIO4_FLAGS 0
#endif
#endif
#endif


// ../inav/src/main/drivers/light_ws2811strip.c
#ifdef USE_LED_STRIP
#define WS2811_PERIOD (WS2811_TIMER_HZ / WS2811_CARRIER_HZ)
#define WS2811_BIT_COMPARE_1 ((WS2811_PERIOD * 2) / 3)
#define WS2811_BIT_COMPARE_0 (WS2811_PERIOD / 3)
#endif


// ../inav/src/main/drivers/flash_w25n.c
#if defined(USE_FLASH_W25N01G) || defined(USE_FLASH_W25N02K)
#define W25N_PAGE_SIZE       2048
#define W25N_PAGES_PER_BLOCK 64
#define W25N01GV_BLOCKS_PER_DIE  1024
#define W25N02KV_BLOCKS_PER_DIE   2048
#define W25N_BB_MARKER_BLOCKS      1
#define W25N_BB_REPLACEMENT_BLOCKS 20
#define W25N_BB_MANAGEMENT_BLOCKS  (W25N_BB_REPLACEMENT_BLOCKS + W25N_BB_MARKER_BLOCKS)
#define W25N_BB_REPLACEMENT_START_BLOCK (W25N_BLOCKS_PER_DIE - W25N_BB_REPLACEMENT_BLOCKS)
#define W25N_BB_MANAGEMENT_START_BLOCK  (W25N_BLOCKS_PER_DIE - W25N_BB_MANAGEMENT_BLOCKS)
#define W25N_BB_MARKER_BLOCK            (W25N_BB_REPLACEMENT_START_BLOCK - W25N_BB_MARKER_BLOCKS)
#define W25N_INSTRUCTION_RDID                       0x9F
#define W25N_INSTRUCTION_DEVICE_RESET               0xFF
#define W25N_INSTRUCTION_READ_STATUS_REG            0x05
#define W25N_INSTRUCTION_READ_STATUS_ALTERNATE_REG  0x0F
#define W25N_INSTRUCTION_WRITE_STATUS_REG           0x01
#define W25N_INSTRUCTION_WRITE_STATUS_ALTERNATE_REG 0x1F
#define W25N_INSTRUCTION_WRITE_ENABLE               0x06
#define W25N_INSTRUCTION_DIE_SELECT                 0xC2
#define W25N_INSTRUCTION_BLOCK_ERASE                0xD8
#define W25N_INSTRUCTION_READ_BBM_LUT               0xA5
#define W25N_INSTRUCTION_BB_MANAGEMENT              0xA1
#define W25N_INSTRUCTION_PROGRAM_DATA_LOAD          0x02
#define W25N_INSTRUCTION_RANDOM_PROGRAM_DATA_LOAD   0x84
#define W25N_INSTRUCTION_PROGRAM_EXECUTE            0x10
#define W25N_INSTRUCTION_PAGE_DATA_READ             0x13
#define W25N_INSTRUCTION_READ_DATA                  0x03
#define W25N_INSTRUCTION_FAST_READ                  0x1B
#define W25N_INSTRUCTION_FAST_READ_QUAD_OUTPUT      0x6B
#define W25N_PROT_REG 0xA0
#define W25N_CONF_REG 0xB0
#define W25N_STAT_REG 0xC0
#define W25N_PROT_CLEAR                (0)
#define W25N_PROT_SRP1_ENABLE          (1 << 0)
#define W25N_PROT_WP_E_ENABLE          (1 << 1)
#define W25N_PROT_TB_ENABLE            (1 << 2)
#define W25N_PROT_PB0_ENABLE           (1 << 3)
#define W25N_PROT_PB1_ENABLE           (1 << 4)
#define W25N_PROT_PB2_ENABLE           (1 << 5)
#define W25N_PROT_PB3_ENABLE           (1 << 6)
#define W25N_PROT_SRP2_ENABLE          (1 << 7)
#define W25N_CONFIG_ECC_ENABLE         (1 << 4)
#define W25N_CONFIG_BUFFER_READ_MODE   (1 << 3)
#define W25N_STATUS_BBM_LUT_FULL       (1 << 6)
#define W25N_STATUS_FLAG_ECC_POS       4
#define W25N_STATUS_FLAG_ECC_MASK      ((1 << 5)|(1 << 4))
#define W25N_STATUS_FLAG_ECC(status)   (((status) & W25N_STATUS_FLAG_ECC_MASK) >> 4)
#define W25N_STATUS_PROGRAM_FAIL       (1 << 3)
#define W25N_STATUS_ERASE_FAIL         (1 << 2)
#define W25N_STATUS_FLAG_WRITE_ENABLED (1 << 1)
#define W25N_STATUS_FLAG_BUSY          (1 << 0)
#define W25N_BBLUT_TABLE_ENTRY_COUNT    20
#define W25N_BBLUT_TABLE_ENTRY_SIZE     4
#define W25N_BBLUT_STATUS_ENABLED (1 << 15)
#define W25N_BBLUT_STATUS_INVALID (1 << 14)
#define W25N_BBLUT_STATUS_MASK    (W25N_BBLUT_STATUS_ENABLED | W25N_BBLUT_STATUS_INVALID)
#define W25N_LINEAR_TO_COLUMN(laddr) ((laddr) % W25N_PAGE_SIZE)
#define W25N_LINEAR_TO_PAGE(laddr) ((laddr) / W25N_PAGE_SIZE)
#define W25N_LINEAR_TO_BLOCK(laddr) (W25N_LINEAR_TO_PAGE(laddr) / W25N_PAGES_PER_BLOCK)
#define W25N_BLOCK_TO_PAGE(block) ((block) * W25N_PAGES_PER_BLOCK)
#define W25N_BLOCK_TO_LINEAR(block) (W25N_BLOCK_TO_PAGE(block) * W25N_PAGE_SIZE)
#define W25N_TIMEOUT_PAGE_READ_MS        2
#define W25N_TIMEOUT_PAGE_PROGRAM_MS     2
#define W25N_TIMEOUT_BLOCK_ERASE_MS      15
#define W25N_TIMEOUT_RESET_MS            500
#define W28N_STATUS_REGISTER_SIZE        8
#define W28N_STATUS_PAGE_ADDRESS_SIZE    16
#define W28N_STATUS_COLUMN_ADDRESS_SIZE  16
#define JEDEC_ID_WINBOND_W25N01GV 0xEFAA21
#define JEDEC_ID_WINBOND_W25N02KV 0xEFAA22
#endif


// ../inav/src/main/drivers/pinio.h
#define PINIO_COUNT             4
#define PINIO_FLAGS_INVERTED    0x80


// ../inav/src/main/drivers/irlock.h
#if defined(USE_IRLOCK)
#define IRLOCK_RES_X 320
#define IRLOCK_RES_Y 200
#endif


// ../inav/src/main/drivers/usb_msc_at32f43x.c
#if defined(USE_USB_MSC)
#define DEBOUNCE_TIME_MS 20
#endif


// ../inav/src/main/drivers/bus_quadspi.h
#ifdef USE_QUADSPI
#define QUADSPI_IO_AF_BK_IO_CFG           IO_CONFIG(GPIO_MODE_AF_PP, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_NOPULL)
#define QUADSPI_IO_AF_CLK_CFG             IO_CONFIG(GPIO_MODE_AF_PP, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_NOPULL)
#define QUADSPI_IO_AF_BK_CS_CFG           IO_CONFIG(GPIO_MODE_AF_PP, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_PULLUP)
#define QUADSPI_IO_BK_CS_CFG              IO_CONFIG(GPIO_MODE_OUTPUT_PP, GPIO_SPEED_FREQ_HIGH, GPIO_PULLUP)
#define QUADSPIDEV_COUNT 1
#define QUADSPI_CFG_TO_DEV(x)   ((x) - 1)
#define QUADSPI_DEV_TO_CFG(x)   ((x) + 1)
#define QUADSPI_BK1_CS_MASK         ((1 << 1) | (1 << 0))
#define QUADSPI_BK1_CS_NONE         ((0 << 1) | (0 << 0))
#define QUADSPI_BK1_CS_HARDWARE     ((0 << 1) | (1 << 0))
#define QUADSPI_BK1_CS_SOFTWARE     ((1 << 1) | (0 << 0))
#define QUADSPI_BK2_CS_MASK         ((1 << 3) | (1 << 2))
#define QUADSPI_BK2_CS_NONE         ((0 << 3) | (0 << 2))
#define QUADSPI_BK2_CS_HARDWARE     ((0 << 3) | (1 << 2))
#define QUADSPI_BK2_CS_SOFTWARE     ((1 << 3) | (0 << 2))
#define QUADSPI_CS_MODE_MASK         (1 << 4)
#define QUADSPI_CS_MODE_SEPARATE    (0 << 4)
#define QUADSPI_CS_MODE_LINKED      (1 << 4)
#endif


// ../inav/src/main/drivers/max7456.c
#ifdef USE_MAX7456
#if defined(MAX7456_USE_BOUNDS_CHECKS)
#define BOUNDS_CHECK_FAILED() __asm("BKPT #0")
#else
#define BOUNDS_CHECK_FAILED() do {} while(0)
#endif
#define VIDEO_BUFFER_DISABLE        0x01
#define MAX7456_RESET               0x02
#define VERTICAL_SYNC_NEXT_VSYNC    0x04
#define OSD_ENABLE                  0x08
#define SYNC_MODE_AUTO              0x00
#define SYNC_MODE_INTERNAL          0x30
#define SYNC_MODE_EXTERNAL          0x20
#define VIDEO_MODE_PAL              0x40
#define VIDEO_MODE_NTSC             0x00
#define VIDEO_MODE_MASK             0x40
#define VIDEO_MODE_IS_PAL(val)      (((val) & VIDEO_MODE_MASK) == VIDEO_MODE_PAL)
#define VIDEO_MODE_IS_NTSC(val)     (((val) & VIDEO_MODE_MASK) == VIDEO_MODE_NTSC)
#define VIDEO_SIGNAL_DEBOUNCE_MS    100
#define BLINK_DUTY_CYCLE_50_50 0x00
#define BLINK_DUTY_CYCLE_33_66 0x01
#define BLINK_DUTY_CYCLE_25_75 0x02
#define BLINK_DUTY_CYCLE_75_25 0x03
#define BLINK_TIME_0 0x00
#define BLINK_TIME_1 0x04
#define BLINK_TIME_2 0x08
#define BLINK_TIME_3 0x0C
#define BACKGROUND_BRIGHTNESS_0  (0x00 << 4)
#define BACKGROUND_BRIGHTNESS_7  (0x01 << 4)
#define BACKGROUND_BRIGHTNESS_14 (0x02 << 4)
#define BACKGROUND_BRIGHTNESS_21 (0x03 << 4)
#define BACKGROUND_BRIGHTNESS_28 (0x04 << 4)
#define BACKGROUND_BRIGHTNESS_35 (0x05 << 4)
#define BACKGROUND_BRIGHTNESS_42 (0x06 << 4)
#define BACKGROUND_BRIGHTNESS_49 (0x07 << 4)
#define BACKGROUND_MODE_GRAY    0x80
#define STAT_PAL      0x01
#define STAT_NTSC     0x02
#define STAT_LOS      0x04
#define STAT_NVR_BUSY 0x20
#define STAT_IS_PAL(val)  ((val) & STAT_PAL)
#define STAT_IS_NTSC(val) ((val) & STAT_NTSC)
#define STAT_IS_LOS(val)  ((val) & STAT_LOS)
#define VIN_IS_PAL(val)  (!STAT_IS_LOS(val) && STAT_IS_PAL(val))
#define VIN_IS_NTSC(val)  (!STAT_IS_LOS(val) && STAT_IS_NTSC(val))
#define VIN_IS_NTSC_alt(val)  (!STAT_IS_LOS(val) && !STAT_IS_PAL(val))
#define MAX7456_SIGNAL_CHECK_INTERVAL_MS 1000
#define DMM_8BIT_MODE (1 << 6)
#define DMM_BLINK (1 << 4)
#define DMM_INVERT_PIXEL_COLOR (1 << 3)
#define DMM_CLEAR_DISPLAY (1 << 2)
#define DMM_CLEAR_DISPLAY_VERT (DMM_CLEAR_DISPLAY | 1 << 1)
#define DMM_AUTOINCREMENT (1 << 0)
#define DMM_IS_8BIT_MODE(val) (val & DMM_8BIT_MODE)
#define DMM_CHAR_MODE_MASK (MAX7456_MODE_INVERT | MAX7456_MODE_BLINK | MAX7456_MODE_SOLID_BG)
#define DMAH_8_BIT_DMDI_IS_CHAR_ATTR (1 << 1)
#define END_STRING 0xff
#define MAX7456ADD_READ         0x80
#define MAX7456ADD_VM0          0x00
#define MAX7456ADD_VM1          0x01
#define MAX7456ADD_HOS          0x02
#define MAX7456ADD_VOS          0x03
#define MAX7456ADD_DMM          0x04
#define MAX7456ADD_DMAH         0x05
#define MAX7456ADD_DMAL         0x06
#define MAX7456ADD_DMDI         0x07
#define MAX7456ADD_CMM          0x08
#define MAX7456ADD_CMAH         0x09
#define MAX7456ADD_CMAL         0x0a
#define MAX7456ADD_CMDI         0x0b
#define MAX7456ADD_OSDM         0x0c
#define MAX7456ADD_RB0          0x10
#define MAX7456ADD_RB1          0x11
#define MAX7456ADD_RB2          0x12
#define MAX7456ADD_RB3          0x13
#define MAX7456ADD_RB4          0x14
#define MAX7456ADD_RB5          0x15
#define MAX7456ADD_RB6          0x16
#define MAX7456ADD_RB7          0x17
#define MAX7456ADD_RB8          0x18
#define MAX7456ADD_RB9          0x19
#define MAX7456ADD_RB10         0x1a
#define MAX7456ADD_RB11         0x1b
#define MAX7456ADD_RB12         0x1c
#define MAX7456ADD_RB13         0x1d
#define MAX7456ADD_RB14         0x1e
#define MAX7456ADD_RB15         0x1f
#define MAX7456ADD_OSDBL        0x6c
#define MAX7456ADD_STAT         0xA0
#define MAX7456ADD_CMDO         0xC0
#define NVM_RAM_SIZE            54
#define READ_NVR                0x50
#define WRITE_NVR               0xA0
#define MAX_SYNC_WAIT_MS        1500
#define MAX_RESET_TIMEOUT_MS    50
#define MAKE_CHAR_MODE_U8(c, m) ((((uint16_t)c) << 8) | m)
#define MAKE_CHAR_MODE(c, m)    (MAKE_CHAR_MODE_U8(c, m) | (c > 255 ? CHAR_MODE_EXT : 0))
#define CHAR_BLANK              MAKE_CHAR_MODE(0x20, 0)
#define CHAR_BYTE(x)            (x >> 8)
#define MODE_BYTE(x)            (x & 0xFF)
#define CHAR_IS_BLANK(x)        ((CHAR_BYTE(x) == 0x20 || CHAR_BYTE(x) == 0x00) && !CHAR_MODE_IS_EXT(MODE_BYTE(x)))
#define CHAR_MODE_EXT           (1 << 2)
#define CHAR_MODE_IS_EXT(m)     ((m) & CHAR_MODE_EXT)
#define MAX_CHARS2UPDATE        10
#define BYTES_PER_CHAR2UPDATE   (7 * 2)
#endif


// ../inav/src/main/drivers/sound_beeper.h
#ifdef BEEPER
#define BEEP_TOGGLE              systemBeepToggle()
#define BEEP_OFF                 systemBeep(false)
#define BEEP_ON                  systemBeep(true)
#else
#define BEEP_TOGGLE do {} while (0)
#define BEEP_OFF    do {} while (0)
#define BEEP_ON     do {} while (0)
#endif


// ../inav/src/main/drivers/flash.h
#define FLASH_PARTITION_SECTOR_COUNT(partition) (partition->endSector + 1 - partition->startSector)


// ../inav/src/main/drivers/serial_uart_stm32f4xx.c
#define UART_RX_BUFFER_SIZE UART1_RX_BUFFER_SIZE
#define UART_TX_BUFFER_SIZE UART1_RX_BUFFER_SIZE


// ../inav/src/main/drivers/rcc.c
#define RCC_BIT_CMD(ptr, mask, state)       do { if (state != DISABLE) { ptr |= mask; } else { ptr &= ~mask; } } while(0)


// ../inav/src/main/drivers/adc.c
#if defined(USE_ADC) && !defined(SITL_BUILD)
#ifndef ADC_INSTANCE
#define ADC_INSTANCE                ADC1
#endif
#ifndef ADC_CHANNEL_1_INSTANCE
#define ADC_CHANNEL_1_INSTANCE  ADC_INSTANCE
#endif
#ifndef ADC_CHANNEL_2_INSTANCE
#define ADC_CHANNEL_2_INSTANCE  ADC_INSTANCE
#endif
#ifndef ADC_CHANNEL_3_INSTANCE
#define ADC_CHANNEL_3_INSTANCE  ADC_INSTANCE
#endif
#ifndef ADC_CHANNEL_4_INSTANCE
#define ADC_CHANNEL_4_INSTANCE  ADC_INSTANCE
#endif
#ifndef ADC_CHANNEL_5_INSTANCE
#define ADC_CHANNEL_5_INSTANCE  ADC_INSTANCE
#endif
#ifndef ADC_CHANNEL_6_INSTANCE
#define ADC_CHANNEL_6_INSTANCE  ADC_INSTANCE
#endif
#endif


// ../inav/src/main/drivers/adc_at32f43x.c
#if !defined(ADC1_DMA_STREAM)
#define ADC1_DMA_STREAM DMA2_CHANNEL1
#endif


// ../inav/src/main/drivers/timer_stm32h7xx.c
#if defined(STM32H743xx) || defined(STM32H750xx) || defined(STM32H723xx) || defined(STM32H725xx)
#define PERIPH_PRESCALER(bus) ((RCC->D2CFGR & RCC_D2CFGR_D2PPRE ## bus) >> RCC_D2CFGR_D2PPRE ## bus ## _Pos)
#elif defined(STM32H7A3xx) || defined(STM32H7A3xxQ)
#define PERIPH_PRESCALER(bus) ((RCC->CDCFGR2 & RCC_CDCFGR2_CDPPRE ## bus) >> RCC_CDCFGR2_CDPPRE ## bus ## _Pos)
#endif


// ../inav/src/main/drivers/timer_def_stm32h7xx.h
#define timerDMASafeType_t  uint32_t
#define DEF_TIM_DMAMAP__D(dma, stream, request) DMA_TAG(dma, stream, request)
#define DEF_TIM_DMAMAP__NONE                    DMA_NONE
#define DEF_TIM(tim, ch, pin, usage, flags, dmavar) {   \
    tim,                                                \
    IO_TAG(pin),                                        \
    DEF_TIM_CHNL_ ## ch,                                \
    DEF_TIM_OUTPUT(ch) | flags,                         \
    IOCFG_AF_PP,                                        \
    DEF_TIM_AF(TCH_## tim ## _ ## ch, pin),             \
    usage,                                              \
    DEF_TIM_DMAMAP(dmavar, tim ## _ ## ch)              \
}
#define DEF_TIM_AF(timch, pin)        CONCAT(DEF_TIM_AF__, DEF_TIM_AF__ ## pin ## __ ## timch)
#define DEF_TIM_AF__D(af_n, tim_n)    GPIO_AF ## af_n ## _TIM ## tim_n
#define DEF_TIM_DMA_FULL(req) \
    D(1, 0, req), D(1, 1, req), D(1, 2, req), D(1, 3, req), D(1, 4, req), D(1, 5, req), D(1, 6, req), D(1, 7, req), \
    D(2, 0, req), D(2, 1, req), D(2, 2, req), D(2, 3, req), D(2, 4, req), D(2, 5, req), D(2, 6, req), D(2, 7, req)
#define DEF_TIM_DMA__BTCH_TIM1_CH1    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM1_CH1)
#define DEF_TIM_DMA__BTCH_TIM1_CH2    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM1_CH2)
#define DEF_TIM_DMA__BTCH_TIM1_CH3    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM1_CH3)
#define DEF_TIM_DMA__BTCH_TIM1_CH4    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM1_CH4)
#define DEF_TIM_DMA__BTCH_TIM2_CH1    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM2_CH1)
#define DEF_TIM_DMA__BTCH_TIM2_CH2    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM2_CH2)
#define DEF_TIM_DMA__BTCH_TIM2_CH3    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM2_CH3)
#define DEF_TIM_DMA__BTCH_TIM2_CH4    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM2_CH4)
#define DEF_TIM_DMA__BTCH_TIM3_CH1    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM3_CH1)
#define DEF_TIM_DMA__BTCH_TIM3_CH2    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM3_CH2)
#define DEF_TIM_DMA__BTCH_TIM3_CH3    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM3_CH3)
#define DEF_TIM_DMA__BTCH_TIM3_CH4    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM3_CH4)
#define DEF_TIM_DMA__BTCH_TIM4_CH1    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM4_CH1)
#define DEF_TIM_DMA__BTCH_TIM4_CH2    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM4_CH2)
#define DEF_TIM_DMA__BTCH_TIM4_CH3    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM4_CH3)
#ifdef USE_DSHOT_DMAR
#define DEF_TIM_DMA__BTCH_TIM4_CH4    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM4_UP)
#else
#define DEF_TIM_DMA__BTCH_TIM4_CH4    NONE
#endif
#define DEF_TIM_DMA__BTCH_TIM5_CH1    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM5_CH1)
#define DEF_TIM_DMA__BTCH_TIM5_CH2    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM5_CH2)
#define DEF_TIM_DMA__BTCH_TIM5_CH3    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM5_CH3)
#define DEF_TIM_DMA__BTCH_TIM5_CH4    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM5_CH4)
#define DEF_TIM_DMA__BTCH_TIM8_CH1    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM8_CH1)
#define DEF_TIM_DMA__BTCH_TIM8_CH2    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM8_CH2)
#define DEF_TIM_DMA__BTCH_TIM8_CH3    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM8_CH3)
#define DEF_TIM_DMA__BTCH_TIM8_CH4    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM8_CH4)
#define DEF_TIM_DMA__BTCH_TIM12_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM12_CH2   NONE
#define DEF_TIM_DMA__BTCH_TIM13_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM14_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM15_CH1   DEF_TIM_DMA_FULL(DMA_REQUEST_TIM15_CH1)
#define DEF_TIM_DMA__BTCH_TIM15_CH2   NONE
#define DEF_TIM_DMA__BTCH_TIM16_CH1   DEF_TIM_DMA_FULL(DMA_REQUEST_TIM16_CH1)
#define DEF_TIM_DMA__BTCH_TIM16_CH1N  NONE
#define DEF_TIM_DMA__BTCH_TIM17_CH1   DEF_TIM_DMA_FULL(DMA_REQUEST_TIM17_CH1)
#define DEF_TIM_DMA__BTCH_TIM17_CH1N  NONE
#define DEF_TIM_DMA__BTCH_TIM1_UP     DEF_TIM_DMA_FULL(DMA_REQUEST_TIM1_UP)
#define DEF_TIM_DMA__BTCH_TIM2_UP     DEF_TIM_DMA_FULL(DMA_REQUEST_TIM2_UP)
#define DEF_TIM_DMA__BTCH_TIM3_UP     DEF_TIM_DMA_FULL(DMA_REQUEST_TIM3_UP)
#define DEF_TIM_DMA__BTCH_TIM4_UP     DEF_TIM_DMA_FULL(DMA_REQUEST_TIM4_UP)
#define DEF_TIM_DMA__BTCH_TIM5_UP     DEF_TIM_DMA_FULL(DMA_REQUEST_TIM5_UP)
#define DEF_TIM_DMA__BTCH_TIM6_UP     DEF_TIM_DMA_FULL(DMA_REQUEST_TIM6_UP)
#define DEF_TIM_DMA__BTCH_TIM7_UP     DEF_TIM_DMA_FULL(DMA_REQUEST_TIM7_UP)
#define DEF_TIM_DMA__BTCH_TIM8_UP     DEF_TIM_DMA_FULL(DMA_REQUEST_TIM8_UP)
#define DEF_TIM_DMA__BTCH_TIM12_UP    NONE
#define DEF_TIM_DMA__BTCH_TIM13_UP    NONE
#define DEF_TIM_DMA__BTCH_TIM14_UP    NONE
#define DEF_TIM_DMA__BTCH_TIM15_UP    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM15_UP)
#define DEF_TIM_DMA__BTCH_TIM16_UP    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM16_UP)
#define DEF_TIM_DMA__BTCH_TIM17_UP    DEF_TIM_DMA_FULL(DMA_REQUEST_TIM17_UP)
#define DEF_TIM_AF__PA0__TCH_TIM2_CH1     D(1, 2)
#define DEF_TIM_AF__PA1__TCH_TIM2_CH2     D(1, 2)
#define DEF_TIM_AF__PA2__TCH_TIM2_CH3     D(1, 2)
#define DEF_TIM_AF__PA3__TCH_TIM2_CH4     D(1, 2)
#define DEF_TIM_AF__PA5__TCH_TIM2_CH1     D(1, 2)
#define DEF_TIM_AF__PA7__TCH_TIM1_CH1N    D(1, 1)
#define DEF_TIM_AF__PA8__TCH_TIM1_CH1     D(1, 1)
#define DEF_TIM_AF__PA9__TCH_TIM1_CH2     D(1, 1)
#define DEF_TIM_AF__PA10__TCH_TIM1_CH3    D(1, 1)
#define DEF_TIM_AF__PA11__TCH_TIM1_CH4    D(1, 1)
#define DEF_TIM_AF__PA15__TCH_TIM2_CH1    D(1, 2)
#define DEF_TIM_AF__PA0__TCH_TIM5_CH1     D(2, 5)
#define DEF_TIM_AF__PA1__TCH_TIM5_CH2     D(2, 5)
#define DEF_TIM_AF__PA2__TCH_TIM5_CH3     D(2, 5)
#define DEF_TIM_AF__PA3__TCH_TIM5_CH4     D(2, 5)
#define DEF_TIM_AF__PA6__TCH_TIM3_CH1     D(2, 3)
#define DEF_TIM_AF__PA7__TCH_TIM3_CH2     D(2, 3)
#define DEF_TIM_AF__PA5__TCH_TIM8_CH1N    D(3, 8)
#define DEF_TIM_AF__PA7__TCH_TIM8_CH1N    D(3, 8)
#define DEF_TIM_AF__PA6__TCH_TIM13_CH1    D(9, 13)
#define DEF_TIM_AF__PA7__TCH_TIM14_CH1    D(9, 14)
#define DEF_TIM_AF__PA1__TCH_TIM15_CH1N   D(4, 15)
#define DEF_TIM_AF__PA2__TCH_TIM15_CH1    D(4, 15)
#define DEF_TIM_AF__PA3__TCH_TIM15_CH2    D(4, 15)
#define DEF_TIM_AF__PB0__TCH_TIM1_CH2N    D(1, 1)
#define DEF_TIM_AF__PB1__TCH_TIM1_CH3N    D(1, 1)
#define DEF_TIM_AF__PB3__TCH_TIM2_CH2     D(1, 2)
#define DEF_TIM_AF__PB6__TCH_TIM16_CH1N   D(1, 16)
#define DEF_TIM_AF__PB7__TCH_TIM17_CH1N   D(1, 17)
#define DEF_TIM_AF__PB8__TCH_TIM16_CH1    D(1, 16)
#define DEF_TIM_AF__PB9__TCH_TIM17_CH1    D(1, 17)
#define DEF_TIM_AF__PB10__TCH_TIM2_CH3    D(1, 2)
#define DEF_TIM_AF__PB11__TCH_TIM2_CH4    D(1, 2)
#define DEF_TIM_AF__PB13__TCH_TIM1_CH1N   D(1, 1)
#define DEF_TIM_AF__PB14__TCH_TIM1_CH2N   D(1, 1)
#define DEF_TIM_AF__PB15__TCH_TIM1_CH3N   D(1, 1)
#define DEF_TIM_AF__PB0__TCH_TIM3_CH3     D(2, 3)
#define DEF_TIM_AF__PB1__TCH_TIM3_CH4     D(2, 3)
#define DEF_TIM_AF__PB4__TCH_TIM3_CH1     D(2, 3)
#define DEF_TIM_AF__PB5__TCH_TIM3_CH2     D(2, 3)
#define DEF_TIM_AF__PB6__TCH_TIM4_CH1     D(2, 4)
#define DEF_TIM_AF__PB7__TCH_TIM4_CH2     D(2, 4)
#define DEF_TIM_AF__PB8__TCH_TIM4_CH3     D(2, 4)
#define DEF_TIM_AF__PB9__TCH_TIM4_CH4     D(2, 4)
#define DEF_TIM_AF__PB14__TCH_TIM12_CH1   D(2, 12)
#define DEF_TIM_AF__PB15__TCH_TIM12_CH2   D(2, 12)
#define DEF_TIM_AF__PC6__TCH_TIM3_CH1     D(2, 3)
#define DEF_TIM_AF__PC7__TCH_TIM3_CH2     D(2, 3)
#define DEF_TIM_AF__PC8__TCH_TIM3_CH3     D(2, 3)
#define DEF_TIM_AF__PC9__TCH_TIM3_CH4     D(2, 3)
#define DEF_TIM_AF__PC6__TCH_TIM8_CH1     D(3, 8)
#define DEF_TIM_AF__PC7__TCH_TIM8_CH2     D(3, 8)
#define DEF_TIM_AF__PC8__TCH_TIM8_CH3     D(3, 8)
#define DEF_TIM_AF__PC9__TCH_TIM8_CH4     D(3, 8)
#define DEF_TIM_AF__PD12__TCH_TIM4_CH1    D(2, 4)
#define DEF_TIM_AF__PD13__TCH_TIM4_CH2    D(2, 4)
#define DEF_TIM_AF__PD14__TCH_TIM4_CH3    D(2, 4)
#define DEF_TIM_AF__PD15__TCH_TIM4_CH4    D(2, 4)
#define DEF_TIM_AF__PE8__TCH_TIM1_CH1N    D(1, 1)
#define DEF_TIM_AF__PE9__TCH_TIM1_CH1     D(1, 1)
#define DEF_TIM_AF__PE10__TCH_TIM1_CH2N   D(1, 1)
#define DEF_TIM_AF__PE11__TCH_TIM1_CH2    D(1, 1)
#define DEF_TIM_AF__PE12__TCH_TIM1_CH3N   D(1, 1)
#define DEF_TIM_AF__PE13__TCH_TIM1_CH3    D(1, 1)
#define DEF_TIM_AF__PE14__TCH_TIM1_CH4    D(1, 1)
#define DEF_TIM_AF__PE4__TCH_TIM15_CH1N   D(4, 15)
#define DEF_TIM_AF__PE5__TCH_TIM15_CH1    D(4, 15)
#define DEF_TIM_AF__PE6__TCH_TIM15_CH2    D(4, 15)
#define DEF_TIM_AF__PF6__TCH_TIM16_CH1    D(1, 16)
#define DEF_TIM_AF__PF7__TCH_TIM17_CH1    D(1, 17)
#define DEF_TIM_AF__PF8__TCH_TIM16_CH1N   D(1, 16)
#define DEF_TIM_AF__PF9__TCH_TIM17_CH1N   D(1, 17)
#define DEF_TIM_AF__PF8__TCH_TIM13_CH1N   D(9, 13)
#define DEF_TIM_AF__PF9__TCH_TIM14_CH1N   D(9, 14)
#define DEF_TIM_AF__PH6__TCH_TIM12_CH1    D(2, 12)
#define DEF_TIM_AF__PH9__TCH_TIM12_CH2    D(2, 12)
#define DEF_TIM_AF__PH10__TCH_TIM5_CH1    D(2, 5)
#define DEF_TIM_AF__PH11__TCH_TIM5_CH2    D(2, 5)
#define DEF_TIM_AF__PH12__TCH_TIM5_CH3    D(2, 5)
#define DEF_TIM_AF__PH13__TCH_TIM8_CH1N   D(3, 8)
#define DEF_TIM_AF__PH14__TCH_TIM8_CH2N   D(3, 8)
#define DEF_TIM_AF__PH15__TCH_TIM8_CH3N   D(3, 8)
#define DEF_TIM_AF__PI0__TCH_TIM5_CH4     D(2, 5)
#define DEF_TIM_AF__PI2__TCH_TIM8_CH4     D(3, 8)
#define DEF_TIM_AF__PI5__TCH_TIM8_CH1     D(3, 8)
#define DEF_TIM_AF__PI6__TCH_TIM8_CH2     D(3, 8)
#define DEF_TIM_AF__PI7__TCH_TIM8_CH3     D(3, 8)


// ../inav/src/main/drivers/io_pcf8574.c
#define PCF8574_WRITE_ADDRESS 0x40
#define PCF8574_READ_ADDRESS 0x41


// ../inav/src/main/drivers/serial_softserial.h
#define SOFTSERIAL_BUFFER_SIZE 256


// ../inav/src/main/drivers/i2c_application.c
#define DMA_GET_REQUEST(DMA_CHANNEL) \
(((uint32_t)(DMA_CHANNEL) == ((uint32_t)hi2c->dma_tx_channel)) ? I2C_DMA_REQUEST_TX : I2C_DMA_REQUEST_RX)
#define DMA_GET_TC_FLAG(DMA_CHANNEL) \
(((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL1))? DMA1_FDT1_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL2))? DMA1_FDT2_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL3))? DMA1_FDT3_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL4))? DMA1_FDT4_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL5))? DMA1_FDT5_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL6))? DMA1_FDT6_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL7))? DMA1_FDT7_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL1))? DMA2_FDT1_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL2))? DMA2_FDT2_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL3))? DMA2_FDT3_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL4))? DMA2_FDT4_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL5))? DMA2_FDT5_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL6))? DMA2_FDT6_FLAG : \
                                                         DMA2_FDT7_FLAG)
#define DMA_GET_HT_FLAG(DMA_CHANNEL) \
(((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL1))? DMA1_HDT1_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL2))? DMA1_HDT2_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL3))? DMA1_HDT3_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL4))? DMA1_HDT4_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL5))? DMA1_HDT5_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL6))? DMA1_HDT6_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL7))? DMA1_HDT7_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL1))? DMA2_HDT1_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL2))? DMA2_HDT2_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL3))? DMA2_HDT3_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL4))? DMA2_HDT4_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL5))? DMA2_HDT5_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL6))? DMA2_HDT6_FLAG : \
                                                         DMA2_HDT7_FLAG)
#define DMA_GET_TERR_FLAG(DMA_CHANNEL) \
(((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL1))? DMA1_DTERR1_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL2))? DMA1_DTERR2_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL3))? DMA1_DTERR3_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL4))? DMA1_DTERR4_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL5))? DMA1_DTERR5_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL6))? DMA1_DTERR6_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA1_CHANNEL7))? DMA1_DTERR7_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL1))? DMA2_DTERR1_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL2))? DMA2_DTERR2_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL3))? DMA2_DTERR3_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL4))? DMA2_DTERR4_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL5))? DMA2_DTERR5_FLAG : \
 ((uint32_t)(DMA_CHANNEL) == ((uint32_t)DMA2_CHANNEL6))? DMA2_DTERR6_FLAG : \
                                                         DMA2_DTERR7_FLAG)
#define I2C_START                        0
#define I2C_END                          1


// ../inav/src/main/drivers/bus_busdev_i2c.c
#if defined(USE_I2C)
#if !defined(UNUSED)
#define UNUSED(x) ((void)(x))
#endif
#endif


// ../inav/src/main/drivers/serial_usb_vcp_at32f43x.h
#define APP_TX_DATA_SIZE 2048
#define APP_TX_BLOCK_SIZE 512
#define  CDC_POLLING_INTERVAL 50
#define APP_RX_DATA_SIZE  2048


// ../inav/src/main/drivers/bus_spi.h
#if defined(STM32F4)
#define SPI_IO_AF_CFG           IO_CONFIG(GPIO_Mode_AF,  GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL)
#define SPI_IO_AF_SCK_CFG       IO_CONFIG(GPIO_Mode_AF,  GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_DOWN)
#define SPI_IO_AF_MISO_CFG      IO_CONFIG(GPIO_Mode_AF,  GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP)
#define SPI_IO_CS_CFG           IO_CONFIG(GPIO_Mode_OUT, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL)
#elif defined(STM32F7) || defined(STM32H7)
#define SPI_IO_AF_CFG           IO_CONFIG(GPIO_MODE_AF_PP, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_NOPULL)
#define SPI_IO_AF_SCK_CFG_HIGH  IO_CONFIG(GPIO_MODE_AF_PP, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_PULLUP)
#define SPI_IO_AF_SCK_CFG_LOW   IO_CONFIG(GPIO_MODE_AF_PP, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_PULLDOWN)
#define SPI_IO_AF_MISO_CFG      IO_CONFIG(GPIO_MODE_AF_PP, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_PULLUP)
#define SPI_IO_CS_CFG           IO_CONFIG(GPIO_MODE_OUTPUT_PP, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_NOPULL)
#elif defined(AT32F43x)
#define SPI_IO_AF_CFG           IO_CONFIG(GPIO_MODE_MUX,  GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_NONE)
#define SPI_IO_AF_SCK_CFG       IO_CONFIG(GPIO_MODE_MUX,  GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_DOWN)
#define SPI_IO_AF_MISO_CFG      IO_CONFIG(GPIO_MODE_MUX,  GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_UP)
#define SPI_IO_CS_CFG           IO_CONFIG(GPIO_MODE_OUTPUT, GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_NONE)
#endif
#if defined(STM32F4)
#define SPIDEV_COUNT 3
#elif defined(STM32F7) || defined(STM32H7)|| defined(AT32F43x)
#define SPIDEV_COUNT 4
#else
#define SPIDEV_COUNT 4
#endif


// ../inav/src/main/drivers/serial_usb_vcp.c
#ifdef USE_VCP
#define USB_TIMEOUT  50
#endif


// ../inav/src/main/drivers/rcc_at32f43x_periph.h
#ifndef MAIN_DRIVERS_RCC_AT32F43X_PERIPH_H_
#define MAIN_DRIVERS_RCC_AT32F43X_PERIPH_H_
#define   CRM_AHB1_GPIOA_PER_MASK                  ((uint32_t)0x00000001)
#define   CRM_AHB1_GPIOB_PER_MASK                  ((uint32_t)0x00000002)
#define   CRM_AHB1_GPIOC_PER_MASK                  ((uint32_t)0x00000004)
#define   CRM_AHB1_GPIOD_PER_MASK                  ((uint32_t)0x00000008)
#define   CRM_AHB1_GPIOE_PER_MASK                  ((uint32_t)0x00000010)
#define   CRM_AHB1_GPIOF_PER_MASK                  ((uint32_t)0x00000020)
#define   CRM_AHB1_GPIOG_PER_MASK                  ((uint32_t)0x00000040)
#define   CRM_AHB1_GPIOH_PER_MASK                  ((uint32_t)0x00000080)
#define   CRM_AHB1_CRC_PER_MASK                    ((uint32_t)0x00001000)
#define   CRM_AHB1_EDMA_PER_MASK                   ((uint32_t)0x00200000)
#define   CRM_AHB1_DMA1_PER_MASK                   ((uint32_t)0x00400000)
#define   CRM_AHB1_DMA2_PER_MASK                   ((uint32_t)0x01000000)
#define   CRM_AHB1_EMAC_PER_MASK                   ((uint32_t)0x02000000)
#define   CRM_AHB1_EMACTX_PER_MASK                 ((uint32_t)0x04000000)
#define   CRM_AHB1_EMACRX_PER_MASK                 ((uint32_t)0x08000000)
#define   CRM_AHB1_EMACPTP_PER_MASK                ((uint32_t)0x10000000)
#define   CRM_AHB1_OTGFS2_PER_MASK                 ((uint32_t)0x20000000)
#define   CRM_AHB2_DVP_PER_MASK                    ((uint32_t)0x00000001)
#define   CRM_AHB2_OTGFS1_PER_MASK                 ((uint32_t)0x00000080)
#define   CRM_AHB2_SDIO1_PER_MASK                  ((uint32_t)0x00008000)
#define   CRM_AHB3_XMC_PER_MASK                    ((uint32_t)0x00000001)
#define   CRM_AHB3_QSPI1_PER_MASK                  ((uint32_t)0x00000002)
#define   CRM_AHB3_QSPI2_PER_MASK                  ((uint32_t)0x00004000)
#define   CRM_AHB3_SDIO2_PER_MASK                  ((uint32_t)0x00008000)
#define   CRM_APB1_TMR2_PER_MASK                   ((uint32_t)0x00000001)
#define   CRM_APB1_TMR3_PER_MASK                   ((uint32_t)0x00000002)
#define   CRM_APB1_TMR4_PER_MASK                   ((uint32_t)0x00000004)
#define   CRM_APB1_TMR5_PER_MASK                   ((uint32_t)0x00000008)
#define   CRM_APB1_TMR6_PER_MASK                   ((uint32_t)0x00000010)
#define   CRM_APB1_TMR7_PER_MASK                   ((uint32_t)0x00000020)
#define   CRM_APB1_TMR12_PER_MASK                  ((uint32_t)0x00000040)
#define   CRM_APB1_TMR13_PER_MASK                  ((uint32_t)0x00000080)
#define   CRM_APB1_TMR14_PER_MASK                  ((uint32_t)0x00000100)
#define   CRM_APB1_WWDT_PER_MASK                   ((uint32_t)0x00000800)
#define   CRM_APB1_SPI2_PER_MASK                   ((uint32_t)0x00004000)
#define   CRM_APB1_SPI3_PER_MASK                   ((uint32_t)0x00008000)
#define   CRM_APB1_USART2_PER_MASK                 ((uint32_t)0x00020000)
#define   CRM_APB1_USART3_PER_MASK                 ((uint32_t)0x00040000)
#define   CRM_APB1_UART4_PER_MASK                  ((uint32_t)0x00080000)
#define   CRM_APB1_UART5_PER_MASK                  ((uint32_t)0x00100000)
#define   CRM_APB1_I2C1_PER_MASK                   ((uint32_t)0x00200000)
#define   CRM_APB1_I2C2_PER_MASK                   ((uint32_t)0x00400000)
#define   CRM_APB1_I2C3_PER_MASK                   ((uint32_t)0x00800000)
#define   CRM_APB1_CAN1_PER_MASK                   ((uint32_t)0x02000000)
#define   CRM_APB1_CAN2_PER_MASK                   ((uint32_t)0x04000000)
#define   CRM_APB1_PWC_PER_MASK                    ((uint32_t)0x10000000)
#define   CRM_APB1_DAC_PER_MASK                    ((uint32_t)0x20000000)
#define   CRM_APB1_UART7_PER_MASK                  ((uint32_t)0x40000000)
#define   CRM_APB1_UART8_PER_MASK                  ((uint32_t)0x80000000)
#define   CRM_APB2_TMR1_PER_MASK                   ((uint32_t)0x00000001)
#define   CRM_APB2_TMR8_PER_MASK                   ((uint32_t)0x00000002)
#define   CRM_APB2_USART1_PER_MASK                 ((uint32_t)0x00000010)
#define   CRM_APB2_USART6_PER_MASK                 ((uint32_t)0x00000020)
#define   CRM_APB2_ADC1_PER_MASK                   ((uint32_t)0x00000100)
#define   CRM_APB2_ADC2_PER_MASK                   ((uint32_t)0x00000200)
#define   CRM_APB2_ADC3_PER_MASK                   ((uint32_t)0x00000400)
#define   CRM_APB2_SPI1_PER_MASK                   ((uint32_t)0x00001000)
#define   CRM_APB2_SPI4_PER_MASK                   ((uint32_t)0x00002000)
#define   CRM_APB2_SCFG_PER_MASK                   ((uint32_t)0x00004000)
#define   CRM_APB2_TMR9_PER_MASK                   ((uint32_t)0x00010000)
#define   CRM_APB2_TMR10_PER_MASK                  ((uint32_t)0x00020000)
#define   CRM_APB2_TMR11_PER_MASK                  ((uint32_t)0x00040000)
#define   CRM_APB2_TMR20_PER_MASK                  ((uint32_t)0x00100000)
#define   CRM_APB2_ACC_PER_MASK                    ((uint32_t)0x20000000)
#endif


// ../inav/src/main/drivers/timer_def_stm32f4xx.h
#define timerDMASafeType_t  uint32_t
#define DEF_TIM_DMAMAP__D(dma, stream, channel)         DMA_TAG(dma, stream, channel)
#define DEF_TIM_DMAMAP__NONE                            DMA_NONE
#define DEF_TIM(tim, ch, pin, usage, flags, dmavar)     { tim, IO_TAG(pin), DEF_TIM_CHNL_ ## ch, DEF_TIM_OUTPUT(ch) | flags, IOCFG_AF_PP, GPIO_AF_ ## tim, usage, DEF_TIM_DMAMAP(dmavar, tim ## _ ## ch) }
#define DEF_TIM_AF(timch, pin)                  CONCAT(DEF_TIM_AF__, DEF_TIM_AF__ ## pin ## __ ## timch)
#define DEF_TIM_AF__D(af_n)                     GPIO_AF_ ## af_n
#define DEF_TIM_DMA__BTCH_TIM1_CH1    D(2, 6, 0),D(2, 1, 6),D(2, 3, 6)
#define DEF_TIM_DMA__BTCH_TIM1_CH2    D(2, 6, 0),D(2, 2, 6)
#define DEF_TIM_DMA__BTCH_TIM1_CH3    D(2, 6, 0),D(2, 6, 6)
#define DEF_TIM_DMA__BTCH_TIM1_CH4    D(2, 4, 6)
#define DEF_TIM_DMA__BTCH_TIM2_CH1    D(1, 5, 3)
#define DEF_TIM_DMA__BTCH_TIM2_CH2    D(1, 6, 3)
#define DEF_TIM_DMA__BTCH_TIM2_CH3    D(1, 1, 3)
#define DEF_TIM_DMA__BTCH_TIM2_CH4    D(1, 7, 3),D(1, 6, 3)
#define DEF_TIM_DMA__BTCH_TIM3_CH1    D(1, 4, 5)
#define DEF_TIM_DMA__BTCH_TIM3_CH2    D(1, 5, 5)
#define DEF_TIM_DMA__BTCH_TIM3_CH3    D(1, 7, 5)
#define DEF_TIM_DMA__BTCH_TIM3_CH4    D(1, 2, 5)
#define DEF_TIM_DMA__BTCH_TIM4_CH1    D(1, 0, 2)
#define DEF_TIM_DMA__BTCH_TIM4_CH2    D(1, 3, 2)
#define DEF_TIM_DMA__BTCH_TIM4_CH3    D(1, 7, 2)
#define DEF_TIM_DMA__BTCH_TIM5_CH1    D(1, 2, 6)
#define DEF_TIM_DMA__BTCH_TIM5_CH2    D(1, 4, 6)
#define DEF_TIM_DMA__BTCH_TIM5_CH3    D(1, 0, 6)
#define DEF_TIM_DMA__BTCH_TIM5_CH4    D(1, 1, 6),D(1, 3, 6)
#define DEF_TIM_DMA__BTCH_TIM8_CH1    D(2, 2, 0),D(2, 2, 7)
#define DEF_TIM_DMA__BTCH_TIM8_CH2    D(2, 2, 0),D(2, 3, 7)
#define DEF_TIM_DMA__BTCH_TIM8_CH3    D(2, 2, 0),D(2, 4, 7)
#define DEF_TIM_DMA__BTCH_TIM8_CH4    D(2, 7, 7)
#define DEF_TIM_DMA__BTCH_TIM4_CH4    NONE
#define DEF_TIM_DMA__BTCH_TIM9_CH1    NONE
#define DEF_TIM_DMA__BTCH_TIM9_CH2    NONE
#define DEF_TIM_DMA__BTCH_TIM10_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM11_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM12_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM12_CH2   NONE
#define DEF_TIM_DMA__BTCH_TIM13_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM14_CH1   NONE


// ../inav/src/main/drivers/nvic.h
#define NVIC_PRIO_MAX                       1
#define NVIC_PRIO_I2C_ER                    2
#define NVIC_PRIO_I2C_EV                    2
#define NVIC_PRIO_TIMER                     3
#define NVIC_PRIO_TIMER_DMA                 3
#define NVIC_PRIO_SDIO                      3
#define NVIC_PRIO_USB                       5
#define NVIC_PRIO_SERIALUART                5
#define NVIC_PRIO_VCP                       7
#if defined(AT32F43x)
    #define NVIC_PRIORITY_GROUPING NVIC_PRIORITY_GROUP_4
#else
    #ifdef USE_HAL_DRIVER
        #define NVIC_PRIORITY_GROUPING NVIC_PRIORITYGROUP_4
    #else
        #define NVIC_PRIORITY_GROUPING NVIC_PriorityGroup_4
#endif
#endif


// ../inav/src/main/drivers/usb_msc_f4xx.c
#if defined(USE_USB_MSC)
#define DEBOUNCE_TIME_MS 20
#endif


// ../inav/src/main/drivers/rcc.h
#define RCC_ENCODE(reg, mask) (((reg) << 5) | LOG2_32BIT(mask))
#ifdef AT32F43x
#define RCC_AHB1(periph) RCC_ENCODE(RCC_AHB1,   CRM_AHB1_ ## periph ## _PER_MASK)
#define RCC_AHB2(periph) RCC_ENCODE(RCC_AHB2,   CRM_AHB2_ ## periph ## _PER_MASK)
#define RCC_AHB3(periph) RCC_ENCODE(RCC_AHB3,   CRM_AHB3_ ## periph ## _PER_MASK)
#define RCC_APB1(periph) RCC_ENCODE(RCC_APB1, 	CRM_APB1_ ## periph ## _PER_MASK)
#define RCC_APB2(periph) RCC_ENCODE(RCC_APB2, 	CRM_APB2_ ## periph ## _PER_MASK)
#else
#define RCC_AHB(periph) RCC_ENCODE(RCC_AHB, RCC_AHBENR_ ## periph ## EN)
#define RCC_AHB1(periph) RCC_ENCODE(RCC_AHB1, RCC_AHB1ENR_ ## periph ## EN)
#define RCC_APB1(periph) RCC_ENCODE(RCC_APB1, RCC_APB1ENR_ ## periph ## EN)
#define RCC_APB2(periph) RCC_ENCODE(RCC_APB2, RCC_APB2ENR_ ## periph ## EN)
#endif
#ifdef STM32H7
#define RCC_AHB2(periph) RCC_ENCODE(RCC_AHB2, RCC_AHB2ENR_ ## periph ## EN)
#define RCC_AHB3(periph) RCC_ENCODE(RCC_AHB3, RCC_AHB3ENR_ ## periph ## EN)
#define RCC_AHB4(periph) RCC_ENCODE(RCC_AHB4, RCC_AHB4ENR_ ## periph ## EN)
#define RCC_APB1L(periph) RCC_ENCODE(RCC_APB1L, RCC_APB1LENR_ ## periph ## EN)
#define RCC_APB1H(periph) RCC_ENCODE(RCC_APB1H, RCC_APB1HENR_ ## periph ## EN)
#define RCC_APB3(periph) RCC_ENCODE(RCC_APB3, RCC_APB3ENR_ ## periph ## EN)
#define RCC_APB4(periph) RCC_ENCODE(RCC_APB4, RCC_APB4ENR_ ## periph ## EN)
#endif


// ../inav/src/main/drivers/system.c
#if defined(STM32F4) || defined(STM32F7) || defined(STM32H7)||defined(AT32F43x)
#define DWT_LAR_UNLOCK_VALUE 0xC5ACCE55
#endif
#define SHORT_FLASH_DURATION 50
#define CODE_FLASH_DURATION 250


// ../inav/src/main/drivers/bus_i2c_hal.c
#if !defined(SOFT_I2C) && defined(USE_I2C)
#define CLOCKSPEED 800000
#if defined(USE_I2C_PULLUP)
#define IOCFG_I2C IO_CONFIG(GPIO_MODE_AF_OD, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_PULLUP)
#else
#define IOCFG_I2C IOCFG_AF_OD
#endif
#ifndef I2C1_SCL
#define I2C1_SCL PB6
#endif
#ifndef I2C1_SDA
#define I2C1_SDA PB7
#endif
#ifndef I2C2_SCL
#define I2C2_SCL PB10
#endif
#ifndef I2C2_SDA
#define I2C2_SDA PB11
#endif
#ifndef I2C3_SCL
#define I2C3_SCL PA8
#endif
#ifndef I2C3_SDA
#define I2C3_SDA PB4
#endif
#if defined(USE_I2C_DEVICE_4)
#ifndef I2C4_SCL
#define I2C4_SCL PD12
#endif
#ifndef I2C4_SDA
#define I2C4_SDA PD13
#endif
#endif
#define I2C_DEFAULT_TIMEOUT     (I2C_TIMEOUT / 1000)
#define TIMINGR(presc, scldel, sdadel, sclh, scll) \
    ((presc << 28)|(scldel << 20)|(sdadel << 16)|(sclh << 8)|(scll << 0))
#endif


// ../inav/src/main/drivers/sdio.h
#define SDIO_CFG_TO_DEV(x) ((x) - 1)
#define SDIO_DEV_TO_CFG(x) ((x) + 1)
#define SDIODEV_COUNT 2


// ../inav/src/main/drivers/io_impl.h
#define IO_GPIOBYTAG(tag) IO_GPIO(IOGetByTag(tag))
#define IO_PINBYTAG(tag) IO_Pin(IOGetByTag(tag))


// ../inav/src/main/drivers/osd.h
#define OSD_CHAR_WIDTH 12
#define OSD_CHAR_HEIGHT 18
#define OSD_CHAR_BITS_PER_PIXEL 2
#define OSD_CHAR_VISIBLE_BYTES (OSD_CHAR_WIDTH * OSD_CHAR_HEIGHT * OSD_CHAR_BITS_PER_PIXEL / 8)
#define OSD_CHAR_BYTES 64
#define OSD_CHARACTER_COLOR_BLACK 0
#define OSD_CHARACTER_COLOR_TRANSPARENT 1
#define OSD_CHARACTER_COLOR_WHITE 2
#define OSD_CHARACTER_GRID_MAX_WIDTH 30
#define OSD_CHARACTER_GRID_MAX_HEIGHT 16
#define OSD_CHARACTER_GRID_BUFFER_SIZE (OSD_CHARACTER_GRID_MAX_WIDTH * OSD_CHARACTER_GRID_MAX_HEIGHT)


// ../inav/src/main/drivers/bus.h
#define BUS_SPI1    SPIDEV_1
#define BUS_SPI2    SPIDEV_2
#define BUS_SPI3    SPIDEV_3
#define BUS_SPI4    SPIDEV_4
#define BUS_I2C1            I2CDEV_1
#define BUS_I2C2            I2CDEV_2
#define BUS_I2C3            I2CDEV_3
#define BUS_I2C4            I2CDEV_4
#define BUS_I2C_EMULATED    I2CINVALID
#define BUS_SCRATCHPAD_MEMORY_SIZE      (20)
#ifdef __APPLE__
#define BUSDEV_REGISTER_ATTRIBUTES __attribute__ ((section("__DATA,__busdev_registry"), used, aligned(4)))
#else
#define BUSDEV_REGISTER_ATTRIBUTES __attribute__ ((section(".busdev_registry"), used, aligned(4)))
#endif
#ifdef USE_SPI
#define BUSDEV_REGISTER_SPI_F(_name, _devHw, _spiBus, _csnPin, _irqPin, _tag, _flags, _param)   \
    extern const busDeviceDescriptor_t _name ## _registry;                                      \
    static busDevice_t _name ## _memory;                                                        \
    const busDeviceDescriptor_t _name ## _registry BUSDEV_REGISTER_ATTRIBUTES = {               \
        .devicePtr = (void *) & _name ## _memory,                                               \
        .busType = BUSTYPE_SPI,                                                                 \
        .devHwType = _devHw,                                                                    \
        .flags = _flags,                                                                        \
        .tag = _tag,                                                                            \
        .param = _param,                                                                        \
        .busdev.spi = {                                                                         \
            .spiBus = _spiBus,                                                                  \
            .csnPin = IO_TAG(_csnPin)                                                           \
        },                                                                                      \
        .irqPin = IO_TAG(_irqPin)                                                               \
    };                                                                                          \
    struct _dummy                                                                               \

#define BUSDEV_REGISTER_SPI(_name, _devHw, _spiBus, _csnPin, _irqPin, _flags, _param)           \
    BUSDEV_REGISTER_SPI_F(_name, _devHw, _spiBus, _csnPin, _irqPin, 0, _flags, _param)
#define BUSDEV_REGISTER_SPI_TAG(_name, _devHw, _spiBus, _csnPin, _irqPin, _tag, _flags, _param) \
    BUSDEV_REGISTER_SPI_F(_name, _devHw, _spiBus, _csnPin, _irqPin, _tag, _flags, _param)
#else
#define BUSDEV_REGISTER_SPI(_name, _devHw, _spiBus, _csnPin, _irqPin, _flags, _param)
#define BUSDEV_REGISTER_SPI_TAG(_name, _devHw, _spiBus, _csnPin, _irqPin, _tag, _flags, _param)
#endif
#ifdef USE_I2C
#define BUSDEV_REGISTER_I2C_F(_name, _devHw, _i2cBus, _devAddr, _irqPin, _tag, _flags, _param)  \
    extern const busDeviceDescriptor_t _name ## _registry;                                      \
    static busDevice_t _name ## _memory;                                                        \
    const busDeviceDescriptor_t _name ## _registry BUSDEV_REGISTER_ATTRIBUTES = {               \
        .devicePtr = (void *) & _name ## _memory,                                               \
        .busType = BUSTYPE_I2C,                                                                 \
        .devHwType = _devHw,                                                                    \
        .flags = _flags,                                                                        \
        .tag = _tag,                                                                            \
        .param = _param,                                                                        \
        .busdev.i2c = {                                                                         \
            .i2cBus = _i2cBus,                                                                  \
            .address = _devAddr                                                                 \
        },                                                                                      \
        .irqPin = IO_TAG(_irqPin)                                                               \
    };                                                                                          \
    struct _dummy                                                                               \

#define BUSDEV_REGISTER_I2C(_name, _devHw, _i2cBus, _devAddr, _irqPin, _flags, _param)          \
    BUSDEV_REGISTER_I2C_F(_name, _devHw, _i2cBus, _devAddr, _irqPin, 0, _flags, _param)
#define BUSDEV_REGISTER_I2C_TAG(_name, _devHw, _i2cBus, _devAddr, _irqPin, _tag, _flags, _param)\
    BUSDEV_REGISTER_I2C_F(_name, _devHw, _i2cBus, _devAddr, _irqPin, _tag, _flags, _param)
#else
#define BUSDEV_REGISTER_I2C(_name, _devHw, _i2cBus, _devAddr, _irqPin, _flags, _param)
#define BUSDEV_REGISTER_I2C_TAG(_name, _devHw, _i2cBus, _devAddr, _irqPin, _tag, _flags, _param)
#endif


// ../inav/src/main/drivers/flash_m25p16.c
#ifdef USE_FLASH_M25P16
#define M25P16_INSTRUCTION_RDID             0x9F
#define M25P16_INSTRUCTION_READ_BYTES       0x03
#define M25P16_INSTRUCTION_QUAD_READ        0x6B
#define M25P16_INSTRUCTION_READ_STATUS_REG  0x05
#define M25P16_INSTRUCTION_WRITE_STATUS_REG 0x01
#define M25P16_INSTRUCTION_WRITE_ENABLE     0x06
#define M25P16_INSTRUCTION_WRITE_DISABLE    0x04
#define M25P16_INSTRUCTION_PAGE_PROGRAM     0x02
#define M25P16_INSTRUCTION_QPAGE_PROGRAM    0x32
#define M25P16_INSTRUCTION_SECTOR_ERASE     0xD8
#define M25P16_INSTRUCTION_BULK_ERASE       0xC7
#define M25P16_STATUS_FLAG_WRITE_IN_PROGRESS 0x01
#define M25P16_STATUS_FLAG_WRITE_ENABLED     0x02
#define W25Q256_INSTRUCTION_ENTER_4BYTE_ADDRESS_MODE 0xB7
#define M25P16_FAST_READ_DUMMY_CYCLES       8
#define DEFAULT_TIMEOUT_MILLIS       6
#define SECTOR_ERASE_TIMEOUT_MILLIS  5000
#define BULK_ERASE_TIMEOUT_MILLIS    21000
#endif


// ../inav/src/main/drivers/1-wire.h
#ifdef USE_1WIRE
#define OW_STATUS_1WB_POS 0
#define OW_STATUS_PPD_POS 1
#define OW_STATUS_SD_POS 2
#define OW_STATUS_LL_POS 3
#define OW_STATUS_RST_POS 4
#define OW_STATUS_SBR_POS 5
#define OW_STATUS_TSB_POS 6
#define OW_STATUS_DIR_POS 7
#define OW_BUS_BUSY(status) (status & (1 << OW_STATUS_1WB_POS))
#define OW_DEVICE_PRESENT(status) (status & (1 << OW_STATUS_PPD_POS))
#define OW_RESET(status) (status & (1 << OW_STATUS_RST_POS))
#define OW_LOGIC_LEVEL(status) (status & (1 << OW_STATUS_LL_POS))
#define OW_SHORT_DETECTED(status) (status & (1 << OW_STATUS_SD_POS))
#define OW_SBR_VALUE(status) ((status >> OW_STATUS_SBR_POS) & 1)
#define OW_TSB_VALUE(status) ((status >> OW_STATUS_TSB_POS) & 1)
#define OW_DIR_VALUE(status) ((status >> OW_STATUS_DIR_POS) & 1)
#define OW_TRIPLET_FIRST_BIT(tripletResult) (tripletResult & (1 << 0))
#define OW_TRIPLET_SECOND_BIT(tripletResult) (tripletResult & (1 << 1))
#define OW_TRIPLET_DIRECTION_BIT(tripletResult) (tripletResult & (1 << 2))
#define OW_SINGLE_BIT_WRITE0 0
#define OW_SINGLE_BIT_WRITE1_READ (1<<7)
#endif


// ../inav/src/main/drivers/adc_impl.h
#if defined(STM32F4) || defined(STM32F7) || defined(AT32F43x)
#define ADC_TAG_MAP_COUNT 16
#elif defined(STM32H7)
#define ADC_TAG_MAP_COUNT 28
#else
#define ADC_TAG_MAP_COUNT 10
#endif
#if defined(STM32H7)
#define ADC_VALUES_ALIGNMENT(def) DMA_RAM def __attribute__ ((aligned (32)))
#else
#define ADC_VALUES_ALIGNMENT(def) def
#endif


// ../inav/src/main/drivers/persistent.c
#define PERSISTENT_OBJECT_MAGIC_VALUE (('i' << 24)|('N' << 16)|('a' << 8)|('v' << 0))


// ../inav/src/main/drivers/serial_tcp.h
#define TCP_BASE_PORT_DEFAULT 5760
#define TCP_BUFFER_SIZE 2048
#define TCP_MAX_PACKET_SIZE 65535


// ../inav/src/main/drivers/timer_def_stm32f7xx.h
#define timerDMASafeType_t  uint32_t
#define DEF_TIM_DMAMAP__D(dma, stream, channel)         DMA_TAG(dma, stream, channel)
#define DEF_TIM_DMAMAP__NONE                            DMA_NONE
#define DEF_TIM(tim, ch, pin, usage, flags, dmavar)     { tim, IO_TAG(pin), DEF_TIM_CHNL_ ## ch, DEF_TIM_OUTPUT(ch) | flags, IOCFG_AF_PP, DEF_TIM_AF(TCH_## tim ## _ ## ch, pin), usage, DEF_TIM_DMAMAP(dmavar, tim ## _ ## ch) }
#define DEF_TIM_AF(timch, pin)        CONCAT(DEF_TIM_AF__, DEF_TIM_AF__ ## pin ## __ ## timch)
#define DEF_TIM_AF__D(af_n, tim_n)    GPIO_AF ## af_n ## _TIM ## tim_n
#define DEF_TIM_DMA__BTCH_TIM1_CH1    D(2, 6, 0),D(2, 1, 6),D(2, 3, 6)
#define DEF_TIM_DMA__BTCH_TIM1_CH2    D(2, 6, 0),D(2, 2, 6)
#define DEF_TIM_DMA__BTCH_TIM1_CH3    D(2, 6, 0),D(2, 6, 6)
#define DEF_TIM_DMA__BTCH_TIM1_CH4    D(2, 4, 6)
#define DEF_TIM_DMA__BTCH_TIM2_CH1    D(1, 5, 3)
#define DEF_TIM_DMA__BTCH_TIM2_CH2    D(1, 6, 3)
#define DEF_TIM_DMA__BTCH_TIM2_CH3    D(1, 1, 3)
#define DEF_TIM_DMA__BTCH_TIM2_CH4    D(1, 7, 3),D(1, 6, 3)
#define DEF_TIM_DMA__BTCH_TIM3_CH1    D(1, 4, 5)
#define DEF_TIM_DMA__BTCH_TIM3_CH2    D(1, 5, 5)
#define DEF_TIM_DMA__BTCH_TIM3_CH3    D(1, 7, 5)
#define DEF_TIM_DMA__BTCH_TIM3_CH4    D(1, 2, 5)
#define DEF_TIM_DMA__BTCH_TIM4_CH1    D(1, 0, 2)
#define DEF_TIM_DMA__BTCH_TIM4_CH2    D(1, 3, 2)
#define DEF_TIM_DMA__BTCH_TIM4_CH3    D(1, 7, 2)
#define DEF_TIM_DMA__BTCH_TIM5_CH1    D(1, 2, 6)
#define DEF_TIM_DMA__BTCH_TIM5_CH2    D(1, 4, 6)
#define DEF_TIM_DMA__BTCH_TIM5_CH3    D(1, 0, 6)
#define DEF_TIM_DMA__BTCH_TIM5_CH4    D(1, 1, 6),D(1, 3, 6)
#define DEF_TIM_DMA__BTCH_TIM8_CH1    D(2, 2, 7),D(2, 2, 0)
#define DEF_TIM_DMA__BTCH_TIM8_CH2    D(2, 3, 7),D(2, 2, 0)
#define DEF_TIM_DMA__BTCH_TIM8_CH3    D(2, 4, 7),D(2, 2, 0)
#define DEF_TIM_DMA__BTCH_TIM8_CH4    D(2, 7, 7)
#define DEF_TIM_DMA__BTCH_TIM4_CH4    NONE
#define DEF_TIM_DMA__BTCH_TIM9_CH1    NONE
#define DEF_TIM_DMA__BTCH_TIM9_CH2    NONE
#define DEF_TIM_DMA__BTCH_TIM10_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM11_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM12_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM12_CH2   NONE
#define DEF_TIM_DMA__BTCH_TIM13_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM14_CH1   NONE
#define DEF_TIM_DMA__BTCH_TIM1_UP     D(2, 5, 6)
#define DEF_TIM_DMA__BTCH_TIM2_UP     D(1, 7, 3)
#define DEF_TIM_DMA__BTCH_TIM3_UP     D(1, 2, 5)
#define DEF_TIM_DMA__BTCH_TIM4_UP     D(1, 6, 2)
#define DEF_TIM_DMA__BTCH_TIM5_UP     D(1, 0, 6)
#define DEF_TIM_DMA__BTCH_TIM6_UP     D(1, 1, 7)
#define DEF_TIM_DMA__BTCH_TIM7_UP     D(1, 4, 1)
#define DEF_TIM_DMA__BTCH_TIM8_UP     D(2, 1, 7)
#define DEF_TIM_DMA__BTCH_TIM9_UP     NONE
#define DEF_TIM_DMA__BTCH_TIM10_UP    NONE
#define DEF_TIM_DMA__BTCH_TIM11_UP    NONE
#define DEF_TIM_DMA__BTCH_TIM12_UP    NONE
#define DEF_TIM_DMA__BTCH_TIM13_UP    NONE
#define DEF_TIM_DMA__BTCH_TIM14_UP    NONE
#define DEF_TIM_AF__PA0__TCH_TIM2_CH1     D(1, 2)
#define DEF_TIM_AF__PA1__TCH_TIM2_CH2     D(1, 2)
#define DEF_TIM_AF__PA2__TCH_TIM2_CH3     D(1, 2)
#define DEF_TIM_AF__PA3__TCH_TIM2_CH4     D(1, 2)
#define DEF_TIM_AF__PA5__TCH_TIM2_CH1     D(1, 2)
#define DEF_TIM_AF__PA7__TCH_TIM1_CH1N    D(1, 1)
#define DEF_TIM_AF__PA8__TCH_TIM1_CH1     D(1, 1)
#define DEF_TIM_AF__PA9__TCH_TIM1_CH2     D(1, 1)
#define DEF_TIM_AF__PA10__TCH_TIM1_CH3    D(1, 1)
#define DEF_TIM_AF__PA11__TCH_TIM1_CH1N   D(1, 1)
#define DEF_TIM_AF__PA15__TCH_TIM2_CH1    D(1, 2)
#define DEF_TIM_AF__PA0__TCH_TIM5_CH1     D(2, 5)
#define DEF_TIM_AF__PA1__TCH_TIM5_CH2     D(2, 5)
#define DEF_TIM_AF__PA2__TCH_TIM5_CH3     D(2, 5)
#define DEF_TIM_AF__PA3__TCH_TIM5_CH4     D(2, 5)
#define DEF_TIM_AF__PA6__TCH_TIM3_CH1     D(2, 3)
#define DEF_TIM_AF__PA7__TCH_TIM3_CH2     D(2, 3)
#define DEF_TIM_AF__PA2__TCH_TIM9_CH1     D(3, 9)
#define DEF_TIM_AF__PA3__TCH_TIM9_CH2     D(3, 9)
#define DEF_TIM_AF__PA5__TCH_TIM8_CH1N    D(3, 8)
#define DEF_TIM_AF__PA7__TCH_TIM8_CH1N    D(3, 8)
#define DEF_TIM_AF__PA6__TCH_TIM13_CH1    D(9, 13)
#define DEF_TIM_AF__PA7__TCH_TIM14_CH1    D(9, 14)
#define DEF_TIM_AF__PB0__TCH_TIM1_CH2N    D(1, 1)
#define DEF_TIM_AF__PB1__TCH_TIM1_CH3N    D(1, 1)
#define DEF_TIM_AF__PB3__TCH_TIM2_CH2     D(1, 2)
#define DEF_TIM_AF__PB10__TCH_TIM2_CH3    D(1, 2)
#define DEF_TIM_AF__PB11__TCH_TIM2_CH4    D(1, 2)
#define DEF_TIM_AF__PB13__TCH_TIM1_CH1N   D(1, 1)
#define DEF_TIM_AF__PB14__TCH_TIM1_CH2N   D(1, 1)
#define DEF_TIM_AF__PB15__TCH_TIM1_CH3N   D(1, 1)
#define DEF_TIM_AF__PB0__TCH_TIM3_CH3     D(2, 3)
#define DEF_TIM_AF__PB1__TCH_TIM3_CH4     D(2, 3)
#define DEF_TIM_AF__PB4__TCH_TIM3_CH1     D(2, 3)
#define DEF_TIM_AF__PB5__TCH_TIM3_CH2     D(2, 3)
#define DEF_TIM_AF__PB6__TCH_TIM4_CH1     D(2, 4)
#define DEF_TIM_AF__PB7__TCH_TIM4_CH2     D(2, 4)
#define DEF_TIM_AF__PB8__TCH_TIM4_CH3     D(2, 4)
#define DEF_TIM_AF__PB9__TCH_TIM4_CH4     D(2, 4)
#define DEF_TIM_AF__PB0__TCH_TIM8_CH2N    D(3, 8)
#define DEF_TIM_AF__PB1__TCH_TIM8_CH3N    D(3, 8)
#define DEF_TIM_AF__PB8__TCH_TIM10_CH1    D(3, 10)
#define DEF_TIM_AF__PB9__TCH_TIM11_CH1    D(3, 11)
#define DEF_TIM_AF__PB14__TCH_TIM8_CH2N   D(3, 8)
#define DEF_TIM_AF__PB15__TCH_TIM8_CH3N   D(3, 8)
#define DEF_TIM_AF__PB14__TCH_TIM12_CH1   D(9, 12)
#define DEF_TIM_AF__PB15__TCH_TIM12_CH2   D(9, 12)
#define DEF_TIM_AF__PC6__TCH_TIM3_CH1     D(2, 3)
#define DEF_TIM_AF__PC7__TCH_TIM3_CH2     D(2, 3)
#define DEF_TIM_AF__PC8__TCH_TIM3_CH3     D(2, 3)
#define DEF_TIM_AF__PC9__TCH_TIM3_CH4     D(2, 3)
#define DEF_TIM_AF__PC6__TCH_TIM8_CH1     D(3, 8)
#define DEF_TIM_AF__PC7__TCH_TIM8_CH2     D(3, 8)
#define DEF_TIM_AF__PC8__TCH_TIM8_CH3     D(3, 8)
#define DEF_TIM_AF__PC9__TCH_TIM8_CH4     D(3, 8)
#define DEF_TIM_AF__PD12__TCH_TIM4_CH1    D(2, 4)
#define DEF_TIM_AF__PD13__TCH_TIM4_CH2    D(2, 4)
#define DEF_TIM_AF__PD14__TCH_TIM4_CH3    D(2, 4)
#define DEF_TIM_AF__PD15__TCH_TIM4_CH4    D(2, 4)
#define DEF_TIM_AF__PE8__TCH_TIM1_CH1N    D(1, 1)
#define DEF_TIM_AF__PE9__TCH_TIM1_CH1     D(1, 1)
#define DEF_TIM_AF__PE10__TCH_TIM1_CH2N   D(1, 1)
#define DEF_TIM_AF__PE11__TCH_TIM1_CH2    D(1, 1)
#define DEF_TIM_AF__PE12__TCH_TIM1_CH3N   D(1, 1)
#define DEF_TIM_AF__PE13__TCH_TIM1_CH3    D(1, 1)
#define DEF_TIM_AF__PE14__TCH_TIM1_CH4    D(1, 1)
#define DEF_TIM_AF__PE5__TCH_TIM9_CH1     D(3, 9)
#define DEF_TIM_AF__PE6__TCH_TIM9_CH2     D(3, 9)
#define DEF_TIM_AF__PF6__TCH_TIM10_CH1    D(3, 10)
#define DEF_TIM_AF__PF7__TCH_TIM11_CH1    D(3, 11)
#define DEF_TIM_AF__PH10__TCH_TIM5_CH1    D(2, 5)
#define DEF_TIM_AF__PH11__TCH_TIM5_CH2    D(2, 5)
#define DEF_TIM_AF__PH12__TCH_TIM5_CH3    D(2, 5)
#define DEF_TIM_AF__PH13__TCH_TIM8_CH1N   D(3, 8)
#define DEF_TIM_AF__PH14__TCH_TIM8_CH2N   D(3, 8)
#define DEF_TIM_AF__PH15__TCH_TIM8_CH3N   D(3, 8)
#define DEF_TIM_AF__PH6__TCH_TIM12_CH1    D(9, 12)
#define DEF_TIM_AF__PH9__TCH_TIM12_CH2    D(9, 12)
#define DEF_TIM_AF__PI0__TCH_TIM5_CH4     D(2, 5)
#define DEF_TIM_AF__PI2__TCH_TIM8_CH4     D(3, 8)
#define DEF_TIM_AF__PI5__TCH_TIM8_CH1     D(3, 8)
#define DEF_TIM_AF__PI6__TCH_TIM8_CH2     D(3, 8)
#define DEF_TIM_AF__PI7__TCH_TIM8_CH3     D(3, 8)


// ../inav/src/main/drivers/bus_i2c_at32f43x.c
#if !defined(SOFT_I2C) && defined(USE_I2C)
#define CLOCKSPEED 800000
#define I2Cx_ADDRESS                     0x00
#define UNSTICK_CLK_US 10
#define UNSTICK_CLK_STRETCH (500/UNSTICK_CLK_US)
#if defined(USE_I2C_PULLUP)
#define IOCFG_I2C IOCFG_AF_OD_UP
#else
#define IOCFG_I2C IOCFG_AF_OD
#endif
#ifndef I2C1_SCL
#define I2C1_SCL PA9
#endif
#ifndef I2C1_SDA
#define I2C1_SDA PA10
#endif
#ifndef I2C2_SCL
#define I2C2_SCL PD12
#endif
#ifndef I2C2_SDA
#define I2C2_SDA PD13
#endif
#ifndef I2C3_SCL
#define I2C3_SCL PC0
#endif
#ifndef I2C3_SDA
#define I2C3_SDA PC1
#endif
#define I2C_DEFAULT_TIMEOUT     (I2C_TIMEOUT*288 / 1000  )
#define TIMINGR(presc, scldel, sdadel, sclh, scll) \
    ((presc << 28)|(scldel << 20)|(sdadel << 16)|(sclh << 8)|(scll << 0))
#endif


// ../inav/src/main/drivers/persistent.h
#define RESET_NONE                                      0
#define RESET_BOOTLOADER_REQUEST_ROM                    1
#define RESET_MSC_REQUEST                               2
#define RESET_BOOTLOADER_FIRMWARE_UPDATE                3
#define RESET_BOOTLOADER_FIRMWARE_ROLLBACK              4
#define RESET_BOOTLOADER_FIRMWARE_UPDATE_SUCCESS        5
#define RESET_BOOTLOADER_FIRMWARE_UPDATE_FAILED         6


// ../inav/src/main/drivers/gimbal_common.h
#ifdef USE_SERIAL_GIMBAL
#define GIMBAL_MODE_DEFAULT             GIMBAL_MODE_FOLLOW
#define GIMBAL_MODE_TILT_ROLL_LOCK      (GIMBAL_MODE_TILT_LOCK | GIMBAL_MODE_ROLL_LOCK)
#define GIMBAL_MODE_PAN_TILT_ROLL_LOCK  (GIMBAL_MODE_TILT_LOCK | GIMBAL_MODE_ROLL_LOCK | GIMBAL_MODE_PAN_LOCK)
#endif


// ../inav/src/main/drivers/usb_msc_h7xx.c
#if defined(USE_USB_MSC)
#define DEBOUNCE_TIME_MS 20
#endif


// ../inav/src/main/drivers/pwm_mapping.h
#if defined(TARGET_MOTOR_COUNT)
#define MAX_MOTORS  TARGET_MOTOR_COUNT
#else
#define MAX_MOTORS  12
#endif
#define MAX_SERVOS  18
#define PWM_TIMER_HZ    1000000
#define PULSE_1MS   (1000)
#define MAX_INPUTS  8


// ../inav/src/main/drivers/bus_quadspi_impl.h
#if defined(STM32H7)
#define MAX_QUADSPI_PIN_SEL 3
#endif


// ../inav/src/main/drivers/serial_uart.h
#define UART_AF(uart, af) CONCAT3(GPIO_AF, af, _ ## uart)
#define UART1_RX_BUFFER_SIZE    256
#define UART1_TX_BUFFER_SIZE    256
#define UART2_RX_BUFFER_SIZE    256
#define UART2_TX_BUFFER_SIZE    256
#define UART3_RX_BUFFER_SIZE    256
#define UART3_TX_BUFFER_SIZE    256
#define UART4_RX_BUFFER_SIZE    256
#define UART4_TX_BUFFER_SIZE    256
#define UART5_RX_BUFFER_SIZE    256
#define UART5_TX_BUFFER_SIZE    256
#define UART6_RX_BUFFER_SIZE    256
#define UART6_TX_BUFFER_SIZE    256
#define UART7_RX_BUFFER_SIZE    256
#define UART7_TX_BUFFER_SIZE    256
#define UART8_RX_BUFFER_SIZE    256
#define UART8_TX_BUFFER_SIZE    256


// ../inav/src/main/drivers/bus_i2c_soft.c
#ifdef SOFT_I2C
#define SCL_H         IOHi(scl)
#define SCL_L         IOLo(scl)
#define SDA_H         IOHi(sda)
#define SDA_L         IOLo(sda)
#define SCL_read      IORead(scl)
#define SDA_read      IORead(sda)
#endif


// ../inav/src/main/drivers/io.h
#define IO_TAG(pinid) DEFIO_TAG(pinid)
#if defined(STM32F7) || defined(STM32H7)
#define IO_CONFIG(mode, speed, pupd) ((mode) | ((speed) << 2) | ((pupd) << 5))
#define IOCFG_OUT_PP         IO_CONFIG(GPIO_MODE_OUTPUT_PP, GPIO_SPEED_FREQ_LOW,  GPIO_NOPULL)
#define IOCFG_OUT_PP_25      IO_CONFIG(GPIO_MODE_OUTPUT_PP, GPIO_SPEED_FREQ_HIGH, GPIO_NOPULL)
#define IOCFG_OUT_OD         IO_CONFIG(GPIO_MODE_OUTPUT_OD, GPIO_SPEED_FREQ_LOW,  GPIO_NOPULL)
#define IOCFG_AF_PP_FAST     IO_CONFIG(GPIO_MODE_AF_PP,     GPIO_SPEED_FREQ_VERY_HIGH, GPIO_PULLDOWN)
#define IOCFG_AF_PP          IO_CONFIG(GPIO_MODE_AF_PP,     GPIO_SPEED_FREQ_LOW,  GPIO_NOPULL)
#define IOCFG_AF_PP_PD       IO_CONFIG(GPIO_MODE_AF_PP,     GPIO_SPEED_FREQ_LOW,  GPIO_PULLDOWN)
#define IOCFG_AF_PP_UP       IO_CONFIG(GPIO_MODE_AF_PP,     GPIO_SPEED_FREQ_LOW,  GPIO_PULLUP)
#define IOCFG_AF_OD          IO_CONFIG(GPIO_MODE_AF_OD,     GPIO_SPEED_FREQ_LOW,  GPIO_NOPULL)
#define IOCFG_AF_OD_UP       IO_CONFIG(GPIO_MODE_AF_OD,     GPIO_SPEED_FREQ_LOW,  GPIO_PULLUP)
#define IOCFG_IPD            IO_CONFIG(GPIO_MODE_INPUT,     GPIO_SPEED_FREQ_LOW,  GPIO_PULLDOWN)
#define IOCFG_IPU            IO_CONFIG(GPIO_MODE_INPUT,      GPIO_SPEED_FREQ_LOW,  GPIO_PULLUP)
#define IOCFG_IN_FLOATING    IO_CONFIG(GPIO_MODE_INPUT,     GPIO_SPEED_FREQ_LOW,  GPIO_NOPULL)
#define IOCFG_IPU_25         IO_CONFIG(GPIO_MODE_INPUT,     GPIO_SPEED_FREQ_HIGH, GPIO_PULLUP)
#elif defined(STM32F4)
#define IO_CONFIG(mode, speed, otype, pupd) ((mode) | ((speed) << 2) | ((otype) << 4) | ((pupd) << 5))
#define IOCFG_OUT_PP         IO_CONFIG(GPIO_Mode_OUT, 0, GPIO_OType_PP, GPIO_PuPd_NOPULL)
#define IOCFG_OUT_PP_25      IO_CONFIG(GPIO_Mode_OUT, GPIO_Speed_25MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL)
#define IOCFG_OUT_OD         IO_CONFIG(GPIO_Mode_OUT, 0, GPIO_OType_OD, GPIO_PuPd_NOPULL)
#define IOCFG_AF_PP_FAST     IO_CONFIG(GPIO_Mode_AF,  GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_DOWN)
#define IOCFG_AF_PP          IO_CONFIG(GPIO_Mode_AF,  0, GPIO_OType_PP, GPIO_PuPd_NOPULL)
#define IOCFG_AF_PP_PD       IO_CONFIG(GPIO_Mode_AF,  0, GPIO_OType_PP, GPIO_PuPd_DOWN)
#define IOCFG_AF_PP_UP       IO_CONFIG(GPIO_Mode_AF,  0, GPIO_OType_PP, GPIO_PuPd_UP)
#define IOCFG_AF_OD          IO_CONFIG(GPIO_Mode_AF,  0, GPIO_OType_OD, GPIO_PuPd_NOPULL)
#define IOCFG_AF_OD_UP       IO_CONFIG(GPIO_Mode_AF,  0, GPIO_OType_OD, GPIO_PuPd_UP)
#define IOCFG_IPD            IO_CONFIG(GPIO_Mode_IN,  0, 0,             GPIO_PuPd_DOWN)
#define IOCFG_IPU            IO_CONFIG(GPIO_Mode_IN,  0, 0,             GPIO_PuPd_UP)
#define IOCFG_IN_FLOATING    IO_CONFIG(GPIO_Mode_IN,  0, 0,             GPIO_PuPd_NOPULL)
#define IOCFG_IPU_25         IO_CONFIG(GPIO_Mode_IN,  GPIO_Speed_25MHz, 0, GPIO_PuPd_UP)
#elif defined(AT32F43x)
#define IO_CONFIG(mode, speed, otype, pupd) ((mode) | ((speed) << 2) | ((otype) << 4) | ((pupd) << 5))
#define IOCFG_OUT_PP         IO_CONFIG(GPIO_MODE_OUTPUT, GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_NONE)
#define IOCFG_OUT_PP_25      IO_CONFIG(GPIO_MODE_OUTPUT, GPIO_DRIVE_STRENGTH_MODERATE, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_NONE)
#define IOCFG_OUT_OD         IO_CONFIG(GPIO_MODE_OUTPUT, GPIO_DRIVE_STRENGTH_MODERATE, GPIO_OUTPUT_OPEN_DRAIN, GPIO_PULL_NONE)
#define IOCFG_AF_PP_FAST     IO_CONFIG(GPIO_MODE_MUX,  GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_DOWN)
#define IOCFG_AF_PP          IO_CONFIG(GPIO_MODE_MUX,  GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_NONE)
#define IOCFG_AF_PP_PD       IO_CONFIG(GPIO_MODE_MUX,  GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_DOWN)
#define IOCFG_AF_PP_UP       IO_CONFIG(GPIO_MODE_MUX,  GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_UP)
#define IOCFG_AF_OD          IO_CONFIG(GPIO_MODE_MUX,  GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_OPEN_DRAIN, GPIO_PULL_NONE)
#define IOCFG_AF_OD_UP       IO_CONFIG(GPIO_MODE_MUX,  GPIO_DRIVE_STRENGTH_STRONGER, GPIO_OUTPUT_OPEN_DRAIN, GPIO_PULL_UP)
#define IOCFG_IPD            IO_CONFIG(GPIO_MODE_INPUT,  GPIO_DRIVE_STRENGTH_MODERATE, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_DOWN)
#define IOCFG_IPU            IO_CONFIG(GPIO_MODE_INPUT,  GPIO_DRIVE_STRENGTH_MODERATE, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_UP)
#define IOCFG_IN_FLOATING    IO_CONFIG(GPIO_MODE_INPUT,  GPIO_DRIVE_STRENGTH_MODERATE, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_NONE)
#define IOCFG_IPU_25         IO_CONFIG(GPIO_MODE_INPUT,  GPIO_DRIVE_STRENGTH_MODERATE, GPIO_OUTPUT_PUSH_PULL, GPIO_PULL_UP)
#elif defined(UNIT_TEST) || defined(SITL_BUILD)
# define IOCFG_OUT_PP         0
# define IOCFG_OUT_OD         0
# define IOCFG_AF_PP          0
# define IOCFG_AF_OD          0
# define IOCFG_AF_OD_UP       0
# define IOCFG_IPD            0
# define IOCFG_IPU            0
# define IOCFG_IN_FLOATING    0
#endif


// ../inav/src/main/drivers/serial_uart_stm32h7xx.c
#define UART_RX_BUFFER_SIZE UART1_RX_BUFFER_SIZE
#define UART_TX_BUFFER_SIZE UART1_TX_BUFFER_SIZE
#define UART_PIN_AF_HELPER(uart, pin)  CONCAT4(UART_PIN_AF_UART, uart, _, pin)
#ifdef USE_UART1
#define UART_PIN_AF_UART1_PA9       GPIO_AF7_USART1
#define UART_PIN_AF_UART1_PA10      GPIO_AF7_USART1
#define UART_PIN_AF_UART1_PB6       GPIO_AF7_USART1
#define UART_PIN_AF_UART1_PB7       GPIO_AF7_USART1
#define UART_PIN_AF_UART1_PB14      GPIO_AF4_USART1
#define UART_PIN_AF_UART1_PB15      GPIO_AF4_USART1
#endif
#ifdef USE_UART4
#define UART_PIN_AF_UART4_PA0       GPIO_AF8_UART4
#define UART_PIN_AF_UART4_PA1       GPIO_AF8_UART4
#define UART_PIN_AF_UART4_PA11      GPIO_AF6_UART4
#define UART_PIN_AF_UART4_PA12      GPIO_AF6_UART4
#define UART_PIN_AF_UART4_PB8       GPIO_AF8_UART4
#define UART_PIN_AF_UART4_PB9       GPIO_AF8_UART4
#define UART_PIN_AF_UART4_PC10      GPIO_AF8_UART4
#define UART_PIN_AF_UART4_PC11      GPIO_AF8_UART4
#define UART_PIN_AF_UART4_PD0       GPIO_AF8_UART4
#define UART_PIN_AF_UART4_PD1       GPIO_AF8_UART4
#endif
#ifdef USE_UART5
#define UART_PIN_AF_UART5_PB5       GPIO_AF14_UART5
#define UART_PIN_AF_UART5_PB6       GPIO_AF14_UART5
#define UART_PIN_AF_UART5_PB12      GPIO_AF14_UART5
#define UART_PIN_AF_UART5_PB13      GPIO_AF14_UART5
#define UART_PIN_AF_UART5_PD2       GPIO_AF8_UART5
#define UART_PIN_AF_UART5_PC12      GPIO_AF8_UART5
#endif
#ifdef USE_UART7
#define UART_PIN_AF_UART7_PA8       GPIO_AF11_UART7
#define UART_PIN_AF_UART7_PA15      GPIO_AF11_UART7
#define UART_PIN_AF_UART7_PB3       GPIO_AF11_UART7
#define UART_PIN_AF_UART7_PB4       GPIO_AF11_UART7
#define UART_PIN_AF_UART7_PE7       GPIO_AF7_UART7
#define UART_PIN_AF_UART7_PE8       GPIO_AF7_UART7
#define UART_PIN_AF_UART7_PF6       GPIO_AF7_UART7
#define UART_PIN_AF_UART7_PF7       GPIO_AF7_UART7
#endif


// ../inav/src/main/drivers/io_def_generated.h
#if defined(TARGET_IO_PORTA)
# define DEFIO_PORT_A_USED_MASK TARGET_IO_PORTA
# define DEFIO_PORT_A_USED_COUNT BITCOUNT(DEFIO_PORT_A_USED_MASK)
#else
# define DEFIO_PORT_A_USED_MASK 0
# define DEFIO_PORT_A_USED_COUNT 0
#endif
#define DEFIO_PORT_A_OFFSET (0)
#if defined(TARGET_IO_PORTB)
# define DEFIO_PORT_B_USED_MASK TARGET_IO_PORTB
# define DEFIO_PORT_B_USED_COUNT BITCOUNT(DEFIO_PORT_B_USED_MASK)
#else
# define DEFIO_PORT_B_USED_MASK 0
# define DEFIO_PORT_B_USED_COUNT 0
#endif
#define DEFIO_PORT_B_OFFSET (DEFIO_PORT_A_USED_COUNT)
#if defined(TARGET_IO_PORTC)
# define DEFIO_PORT_C_USED_MASK TARGET_IO_PORTC
# define DEFIO_PORT_C_USED_COUNT BITCOUNT(DEFIO_PORT_C_USED_MASK)
#else
# define DEFIO_PORT_C_USED_MASK 0
# define DEFIO_PORT_C_USED_COUNT 0
#endif
#define DEFIO_PORT_C_OFFSET (DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#if defined(TARGET_IO_PORTD)
# define DEFIO_PORT_D_USED_MASK TARGET_IO_PORTD
# define DEFIO_PORT_D_USED_COUNT BITCOUNT(DEFIO_PORT_D_USED_MASK)
#else
# define DEFIO_PORT_D_USED_MASK 0
# define DEFIO_PORT_D_USED_COUNT 0
#endif
#define DEFIO_PORT_D_OFFSET (DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#if defined(TARGET_IO_PORTE)
# define DEFIO_PORT_E_USED_MASK TARGET_IO_PORTE
# define DEFIO_PORT_E_USED_COUNT BITCOUNT(DEFIO_PORT_E_USED_MASK)
#else
# define DEFIO_PORT_E_USED_MASK 0
# define DEFIO_PORT_E_USED_COUNT 0
#endif
#define DEFIO_PORT_E_OFFSET (DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#if defined(TARGET_IO_PORTF)
# define DEFIO_PORT_F_USED_MASK TARGET_IO_PORTF
# define DEFIO_PORT_F_USED_COUNT BITCOUNT(DEFIO_PORT_F_USED_MASK)
#else
# define DEFIO_PORT_F_USED_MASK 0
# define DEFIO_PORT_F_USED_COUNT 0
#endif
#define DEFIO_PORT_F_OFFSET (DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#if defined(TARGET_IO_PORTG)
# define DEFIO_PORT_G_USED_MASK TARGET_IO_PORTG
# define DEFIO_PORT_G_USED_COUNT BITCOUNT(DEFIO_PORT_G_USED_MASK)
#else
# define DEFIO_PORT_G_USED_MASK 0
# define DEFIO_PORT_G_USED_COUNT 0
#endif
#define DEFIO_PORT_G_OFFSET (DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#if defined(TARGET_IO_PORTH)
# define DEFIO_PORT_H_USED_MASK TARGET_IO_PORTH
# define DEFIO_PORT_H_USED_COUNT BITCOUNT(DEFIO_PORT_H_USED_MASK)
#else
# define DEFIO_PORT_H_USED_MASK 0
# define DEFIO_PORT_H_USED_COUNT 0
#endif
#define DEFIO_PORT_H_OFFSET (DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#if defined(TARGET_IO_PORTI)
# define DEFIO_PORT_I_USED_MASK TARGET_IO_PORTI
# define DEFIO_PORT_I_USED_COUNT BITCOUNT(DEFIO_PORT_I_USED_MASK)
#else
# define DEFIO_PORT_I_USED_MASK 0
# define DEFIO_PORT_I_USED_COUNT 0
#endif
#define DEFIO_PORT_I_OFFSET (DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#define DEFIO_GPIOID__A 0
#define DEFIO_GPIOID__B 1
#define DEFIO_GPIOID__C 2
#define DEFIO_GPIOID__D 3
#define DEFIO_GPIOID__E 4
#define DEFIO_GPIOID__F 5
#define DEFIO_GPIOID__G 6
#define DEFIO_GPIOID__H 7
#define DEFIO_GPIOID__I 8
#if DEFIO_PORT_A_USED_MASK & BIT(0)
# define DEFIO_TAG__PA0 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 0)
# define DEFIO_TAG_E__PA0 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 0)
# define DEFIO_REC__PA0 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(0) - 1)) + 0)
#else
# define DEFIO_TAG__PA0 defio_error_PA0_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA0 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA0 defio_error_PA0_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(1)
# define DEFIO_TAG__PA1 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 1)
# define DEFIO_TAG_E__PA1 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 1)
# define DEFIO_REC__PA1 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(1) - 1)) + 0)
#else
# define DEFIO_TAG__PA1 defio_error_PA1_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA1 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA1 defio_error_PA1_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(2)
# define DEFIO_TAG__PA2 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 2)
# define DEFIO_TAG_E__PA2 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 2)
# define DEFIO_REC__PA2 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(2) - 1)) + 0)
#else
# define DEFIO_TAG__PA2 defio_error_PA2_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA2 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA2 defio_error_PA2_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(3)
# define DEFIO_TAG__PA3 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 3)
# define DEFIO_TAG_E__PA3 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 3)
# define DEFIO_REC__PA3 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(3) - 1)) + 0)
#else
# define DEFIO_TAG__PA3 defio_error_PA3_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA3 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA3 defio_error_PA3_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(4)
# define DEFIO_TAG__PA4 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 4)
# define DEFIO_TAG_E__PA4 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 4)
# define DEFIO_REC__PA4 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(4) - 1)) + 0)
#else
# define DEFIO_TAG__PA4 defio_error_PA4_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA4 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA4 defio_error_PA4_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(5)
# define DEFIO_TAG__PA5 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 5)
# define DEFIO_TAG_E__PA5 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 5)
# define DEFIO_REC__PA5 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(5) - 1)) + 0)
#else
# define DEFIO_TAG__PA5 defio_error_PA5_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA5 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA5 defio_error_PA5_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(6)
# define DEFIO_TAG__PA6 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 6)
# define DEFIO_TAG_E__PA6 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 6)
# define DEFIO_REC__PA6 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(6) - 1)) + 0)
#else
# define DEFIO_TAG__PA6 defio_error_PA6_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA6 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA6 defio_error_PA6_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(7)
# define DEFIO_TAG__PA7 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 7)
# define DEFIO_TAG_E__PA7 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 7)
# define DEFIO_REC__PA7 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(7) - 1)) + 0)
#else
# define DEFIO_TAG__PA7 defio_error_PA7_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA7 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA7 defio_error_PA7_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(8)
# define DEFIO_TAG__PA8 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 8)
# define DEFIO_TAG_E__PA8 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 8)
# define DEFIO_REC__PA8 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(8) - 1)) + 0)
#else
# define DEFIO_TAG__PA8 defio_error_PA8_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA8 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA8 defio_error_PA8_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(9)
# define DEFIO_TAG__PA9 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 9)
# define DEFIO_TAG_E__PA9 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 9)
# define DEFIO_REC__PA9 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(9) - 1)) + 0)
#else
# define DEFIO_TAG__PA9 defio_error_PA9_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA9 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA9 defio_error_PA9_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(10)
# define DEFIO_TAG__PA10 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 10)
# define DEFIO_TAG_E__PA10 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 10)
# define DEFIO_REC__PA10 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(10) - 1)) + 0)
#else
# define DEFIO_TAG__PA10 defio_error_PA10_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA10 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA10 defio_error_PA10_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(11)
# define DEFIO_TAG__PA11 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 11)
# define DEFIO_TAG_E__PA11 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 11)
# define DEFIO_REC__PA11 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(11) - 1)) + 0)
#else
# define DEFIO_TAG__PA11 defio_error_PA11_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA11 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA11 defio_error_PA11_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(12)
# define DEFIO_TAG__PA12 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 12)
# define DEFIO_TAG_E__PA12 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 12)
# define DEFIO_REC__PA12 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(12) - 1)) + 0)
#else
# define DEFIO_TAG__PA12 defio_error_PA12_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA12 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA12 defio_error_PA12_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(13)
# define DEFIO_TAG__PA13 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 13)
# define DEFIO_TAG_E__PA13 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 13)
# define DEFIO_REC__PA13 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(13) - 1)) + 0)
#else
# define DEFIO_TAG__PA13 defio_error_PA13_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA13 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA13 defio_error_PA13_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(14)
# define DEFIO_TAG__PA14 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 14)
# define DEFIO_TAG_E__PA14 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 14)
# define DEFIO_REC__PA14 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(14) - 1)) + 0)
#else
# define DEFIO_TAG__PA14 defio_error_PA14_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA14 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA14 defio_error_PA14_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_A_USED_MASK & BIT(15)
# define DEFIO_TAG__PA15 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 15)
# define DEFIO_TAG_E__PA15 DEFIO_TAG_MAKE(DEFIO_GPIOID__A, 15)
# define DEFIO_REC__PA15 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_A_USED_MASK & (BIT(15) - 1)) + 0)
#else
# define DEFIO_TAG__PA15 defio_error_PA15_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PA15 DEFIO_TAG_E__NONE
# define DEFIO_REC__PA15 defio_error_PA15_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(0)
# define DEFIO_TAG__PB0 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 0)
# define DEFIO_TAG_E__PB0 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 0)
# define DEFIO_REC__PB0 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(0) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB0 defio_error_PB0_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB0 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB0 defio_error_PB0_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(1)
# define DEFIO_TAG__PB1 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 1)
# define DEFIO_TAG_E__PB1 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 1)
# define DEFIO_REC__PB1 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(1) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB1 defio_error_PB1_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB1 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB1 defio_error_PB1_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(2)
# define DEFIO_TAG__PB2 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 2)
# define DEFIO_TAG_E__PB2 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 2)
# define DEFIO_REC__PB2 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(2) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB2 defio_error_PB2_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB2 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB2 defio_error_PB2_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(3)
# define DEFIO_TAG__PB3 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 3)
# define DEFIO_TAG_E__PB3 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 3)
# define DEFIO_REC__PB3 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(3) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB3 defio_error_PB3_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB3 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB3 defio_error_PB3_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(4)
# define DEFIO_TAG__PB4 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 4)
# define DEFIO_TAG_E__PB4 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 4)
# define DEFIO_REC__PB4 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(4) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB4 defio_error_PB4_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB4 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB4 defio_error_PB4_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(5)
# define DEFIO_TAG__PB5 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 5)
# define DEFIO_TAG_E__PB5 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 5)
# define DEFIO_REC__PB5 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(5) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB5 defio_error_PB5_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB5 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB5 defio_error_PB5_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(6)
# define DEFIO_TAG__PB6 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 6)
# define DEFIO_TAG_E__PB6 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 6)
# define DEFIO_REC__PB6 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(6) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB6 defio_error_PB6_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB6 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB6 defio_error_PB6_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(7)
# define DEFIO_TAG__PB7 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 7)
# define DEFIO_TAG_E__PB7 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 7)
# define DEFIO_REC__PB7 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(7) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB7 defio_error_PB7_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB7 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB7 defio_error_PB7_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(8)
# define DEFIO_TAG__PB8 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 8)
# define DEFIO_TAG_E__PB8 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 8)
# define DEFIO_REC__PB8 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(8) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB8 defio_error_PB8_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB8 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB8 defio_error_PB8_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(9)
# define DEFIO_TAG__PB9 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 9)
# define DEFIO_TAG_E__PB9 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 9)
# define DEFIO_REC__PB9 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(9) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB9 defio_error_PB9_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB9 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB9 defio_error_PB9_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(10)
# define DEFIO_TAG__PB10 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 10)
# define DEFIO_TAG_E__PB10 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 10)
# define DEFIO_REC__PB10 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(10) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB10 defio_error_PB10_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB10 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB10 defio_error_PB10_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(11)
# define DEFIO_TAG__PB11 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 11)
# define DEFIO_TAG_E__PB11 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 11)
# define DEFIO_REC__PB11 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(11) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB11 defio_error_PB11_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB11 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB11 defio_error_PB11_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(12)
# define DEFIO_TAG__PB12 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 12)
# define DEFIO_TAG_E__PB12 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 12)
# define DEFIO_REC__PB12 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(12) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB12 defio_error_PB12_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB12 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB12 defio_error_PB12_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(13)
# define DEFIO_TAG__PB13 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 13)
# define DEFIO_TAG_E__PB13 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 13)
# define DEFIO_REC__PB13 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(13) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB13 defio_error_PB13_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB13 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB13 defio_error_PB13_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(14)
# define DEFIO_TAG__PB14 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 14)
# define DEFIO_TAG_E__PB14 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 14)
# define DEFIO_REC__PB14 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(14) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB14 defio_error_PB14_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB14 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB14 defio_error_PB14_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_B_USED_MASK & BIT(15)
# define DEFIO_TAG__PB15 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 15)
# define DEFIO_TAG_E__PB15 DEFIO_TAG_MAKE(DEFIO_GPIOID__B, 15)
# define DEFIO_REC__PB15 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_B_USED_MASK & (BIT(15) - 1)) + DEFIO_PORT_A_USED_COUNT)
#else
# define DEFIO_TAG__PB15 defio_error_PB15_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PB15 DEFIO_TAG_E__NONE
# define DEFIO_REC__PB15 defio_error_PB15_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(0)
# define DEFIO_TAG__PC0 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 0)
# define DEFIO_TAG_E__PC0 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 0)
# define DEFIO_REC__PC0 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(0) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC0 defio_error_PC0_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC0 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC0 defio_error_PC0_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(1)
# define DEFIO_TAG__PC1 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 1)
# define DEFIO_TAG_E__PC1 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 1)
# define DEFIO_REC__PC1 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(1) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC1 defio_error_PC1_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC1 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC1 defio_error_PC1_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(2)
# define DEFIO_TAG__PC2 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 2)
# define DEFIO_TAG_E__PC2 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 2)
# define DEFIO_REC__PC2 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(2) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC2 defio_error_PC2_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC2 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC2 defio_error_PC2_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(3)
# define DEFIO_TAG__PC3 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 3)
# define DEFIO_TAG_E__PC3 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 3)
# define DEFIO_REC__PC3 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(3) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC3 defio_error_PC3_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC3 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC3 defio_error_PC3_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(4)
# define DEFIO_TAG__PC4 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 4)
# define DEFIO_TAG_E__PC4 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 4)
# define DEFIO_REC__PC4 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(4) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC4 defio_error_PC4_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC4 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC4 defio_error_PC4_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(5)
# define DEFIO_TAG__PC5 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 5)
# define DEFIO_TAG_E__PC5 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 5)
# define DEFIO_REC__PC5 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(5) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC5 defio_error_PC5_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC5 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC5 defio_error_PC5_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(6)
# define DEFIO_TAG__PC6 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 6)
# define DEFIO_TAG_E__PC6 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 6)
# define DEFIO_REC__PC6 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(6) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC6 defio_error_PC6_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC6 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC6 defio_error_PC6_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(7)
# define DEFIO_TAG__PC7 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 7)
# define DEFIO_TAG_E__PC7 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 7)
# define DEFIO_REC__PC7 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(7) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC7 defio_error_PC7_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC7 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC7 defio_error_PC7_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(8)
# define DEFIO_TAG__PC8 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 8)
# define DEFIO_TAG_E__PC8 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 8)
# define DEFIO_REC__PC8 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(8) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC8 defio_error_PC8_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC8 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC8 defio_error_PC8_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(9)
# define DEFIO_TAG__PC9 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 9)
# define DEFIO_TAG_E__PC9 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 9)
# define DEFIO_REC__PC9 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(9) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC9 defio_error_PC9_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC9 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC9 defio_error_PC9_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(10)
# define DEFIO_TAG__PC10 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 10)
# define DEFIO_TAG_E__PC10 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 10)
# define DEFIO_REC__PC10 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(10) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC10 defio_error_PC10_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC10 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC10 defio_error_PC10_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(11)
# define DEFIO_TAG__PC11 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 11)
# define DEFIO_TAG_E__PC11 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 11)
# define DEFIO_REC__PC11 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(11) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC11 defio_error_PC11_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC11 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC11 defio_error_PC11_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(12)
# define DEFIO_TAG__PC12 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 12)
# define DEFIO_TAG_E__PC12 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 12)
# define DEFIO_REC__PC12 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(12) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC12 defio_error_PC12_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC12 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC12 defio_error_PC12_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(13)
# define DEFIO_TAG__PC13 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 13)
# define DEFIO_TAG_E__PC13 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 13)
# define DEFIO_REC__PC13 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(13) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC13 defio_error_PC13_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC13 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC13 defio_error_PC13_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(14)
# define DEFIO_TAG__PC14 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 14)
# define DEFIO_TAG_E__PC14 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 14)
# define DEFIO_REC__PC14 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(14) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC14 defio_error_PC14_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC14 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC14 defio_error_PC14_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_C_USED_MASK & BIT(15)
# define DEFIO_TAG__PC15 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 15)
# define DEFIO_TAG_E__PC15 DEFIO_TAG_MAKE(DEFIO_GPIOID__C, 15)
# define DEFIO_REC__PC15 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_C_USED_MASK & (BIT(15) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT)
#else
# define DEFIO_TAG__PC15 defio_error_PC15_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PC15 DEFIO_TAG_E__NONE
# define DEFIO_REC__PC15 defio_error_PC15_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(0)
# define DEFIO_TAG__PD0 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 0)
# define DEFIO_TAG_E__PD0 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 0)
# define DEFIO_REC__PD0 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(0) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD0 defio_error_PD0_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD0 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD0 defio_error_PD0_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(1)
# define DEFIO_TAG__PD1 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 1)
# define DEFIO_TAG_E__PD1 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 1)
# define DEFIO_REC__PD1 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(1) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD1 defio_error_PD1_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD1 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD1 defio_error_PD1_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(2)
# define DEFIO_TAG__PD2 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 2)
# define DEFIO_TAG_E__PD2 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 2)
# define DEFIO_REC__PD2 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(2) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD2 defio_error_PD2_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD2 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD2 defio_error_PD2_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(3)
# define DEFIO_TAG__PD3 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 3)
# define DEFIO_TAG_E__PD3 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 3)
# define DEFIO_REC__PD3 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(3) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD3 defio_error_PD3_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD3 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD3 defio_error_PD3_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(4)
# define DEFIO_TAG__PD4 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 4)
# define DEFIO_TAG_E__PD4 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 4)
# define DEFIO_REC__PD4 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(4) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD4 defio_error_PD4_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD4 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD4 defio_error_PD4_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(5)
# define DEFIO_TAG__PD5 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 5)
# define DEFIO_TAG_E__PD5 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 5)
# define DEFIO_REC__PD5 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(5) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD5 defio_error_PD5_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD5 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD5 defio_error_PD5_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(6)
# define DEFIO_TAG__PD6 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 6)
# define DEFIO_TAG_E__PD6 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 6)
# define DEFIO_REC__PD6 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(6) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD6 defio_error_PD6_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD6 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD6 defio_error_PD6_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(7)
# define DEFIO_TAG__PD7 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 7)
# define DEFIO_TAG_E__PD7 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 7)
# define DEFIO_REC__PD7 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(7) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD7 defio_error_PD7_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD7 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD7 defio_error_PD7_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(8)
# define DEFIO_TAG__PD8 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 8)
# define DEFIO_TAG_E__PD8 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 8)
# define DEFIO_REC__PD8 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(8) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD8 defio_error_PD8_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD8 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD8 defio_error_PD8_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(9)
# define DEFIO_TAG__PD9 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 9)
# define DEFIO_TAG_E__PD9 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 9)
# define DEFIO_REC__PD9 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(9) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD9 defio_error_PD9_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD9 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD9 defio_error_PD9_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(10)
# define DEFIO_TAG__PD10 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 10)
# define DEFIO_TAG_E__PD10 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 10)
# define DEFIO_REC__PD10 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(10) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD10 defio_error_PD10_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD10 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD10 defio_error_PD10_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(11)
# define DEFIO_TAG__PD11 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 11)
# define DEFIO_TAG_E__PD11 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 11)
# define DEFIO_REC__PD11 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(11) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD11 defio_error_PD11_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD11 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD11 defio_error_PD11_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(12)
# define DEFIO_TAG__PD12 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 12)
# define DEFIO_TAG_E__PD12 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 12)
# define DEFIO_REC__PD12 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(12) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD12 defio_error_PD12_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD12 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD12 defio_error_PD12_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(13)
# define DEFIO_TAG__PD13 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 13)
# define DEFIO_TAG_E__PD13 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 13)
# define DEFIO_REC__PD13 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(13) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD13 defio_error_PD13_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD13 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD13 defio_error_PD13_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(14)
# define DEFIO_TAG__PD14 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 14)
# define DEFIO_TAG_E__PD14 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 14)
# define DEFIO_REC__PD14 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(14) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD14 defio_error_PD14_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD14 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD14 defio_error_PD14_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_D_USED_MASK & BIT(15)
# define DEFIO_TAG__PD15 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 15)
# define DEFIO_TAG_E__PD15 DEFIO_TAG_MAKE(DEFIO_GPIOID__D, 15)
# define DEFIO_REC__PD15 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_D_USED_MASK & (BIT(15) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT)
#else
# define DEFIO_TAG__PD15 defio_error_PD15_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PD15 DEFIO_TAG_E__NONE
# define DEFIO_REC__PD15 defio_error_PD15_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(0)
# define DEFIO_TAG__PE0 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 0)
# define DEFIO_TAG_E__PE0 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 0)
# define DEFIO_REC__PE0 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(0) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE0 defio_error_PE0_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE0 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE0 defio_error_PE0_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(1)
# define DEFIO_TAG__PE1 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 1)
# define DEFIO_TAG_E__PE1 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 1)
# define DEFIO_REC__PE1 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(1) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE1 defio_error_PE1_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE1 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE1 defio_error_PE1_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(2)
# define DEFIO_TAG__PE2 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 2)
# define DEFIO_TAG_E__PE2 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 2)
# define DEFIO_REC__PE2 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(2) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE2 defio_error_PE2_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE2 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE2 defio_error_PE2_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(3)
# define DEFIO_TAG__PE3 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 3)
# define DEFIO_TAG_E__PE3 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 3)
# define DEFIO_REC__PE3 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(3) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE3 defio_error_PE3_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE3 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE3 defio_error_PE3_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(4)
# define DEFIO_TAG__PE4 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 4)
# define DEFIO_TAG_E__PE4 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 4)
# define DEFIO_REC__PE4 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(4) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE4 defio_error_PE4_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE4 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE4 defio_error_PE4_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(5)
# define DEFIO_TAG__PE5 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 5)
# define DEFIO_TAG_E__PE5 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 5)
# define DEFIO_REC__PE5 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(5) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE5 defio_error_PE5_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE5 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE5 defio_error_PE5_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(6)
# define DEFIO_TAG__PE6 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 6)
# define DEFIO_TAG_E__PE6 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 6)
# define DEFIO_REC__PE6 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(6) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE6 defio_error_PE6_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE6 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE6 defio_error_PE6_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(7)
# define DEFIO_TAG__PE7 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 7)
# define DEFIO_TAG_E__PE7 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 7)
# define DEFIO_REC__PE7 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(7) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE7 defio_error_PE7_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE7 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE7 defio_error_PE7_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(8)
# define DEFIO_TAG__PE8 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 8)
# define DEFIO_TAG_E__PE8 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 8)
# define DEFIO_REC__PE8 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(8) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE8 defio_error_PE8_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE8 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE8 defio_error_PE8_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(9)
# define DEFIO_TAG__PE9 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 9)
# define DEFIO_TAG_E__PE9 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 9)
# define DEFIO_REC__PE9 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(9) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE9 defio_error_PE9_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE9 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE9 defio_error_PE9_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(10)
# define DEFIO_TAG__PE10 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 10)
# define DEFIO_TAG_E__PE10 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 10)
# define DEFIO_REC__PE10 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(10) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE10 defio_error_PE10_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE10 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE10 defio_error_PE10_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(11)
# define DEFIO_TAG__PE11 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 11)
# define DEFIO_TAG_E__PE11 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 11)
# define DEFIO_REC__PE11 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(11) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE11 defio_error_PE11_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE11 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE11 defio_error_PE11_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(12)
# define DEFIO_TAG__PE12 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 12)
# define DEFIO_TAG_E__PE12 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 12)
# define DEFIO_REC__PE12 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(12) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE12 defio_error_PE12_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE12 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE12 defio_error_PE12_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(13)
# define DEFIO_TAG__PE13 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 13)
# define DEFIO_TAG_E__PE13 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 13)
# define DEFIO_REC__PE13 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(13) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE13 defio_error_PE13_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE13 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE13 defio_error_PE13_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(14)
# define DEFIO_TAG__PE14 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 14)
# define DEFIO_TAG_E__PE14 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 14)
# define DEFIO_REC__PE14 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(14) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE14 defio_error_PE14_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE14 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE14 defio_error_PE14_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_E_USED_MASK & BIT(15)
# define DEFIO_TAG__PE15 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 15)
# define DEFIO_TAG_E__PE15 DEFIO_TAG_MAKE(DEFIO_GPIOID__E, 15)
# define DEFIO_REC__PE15 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_E_USED_MASK & (BIT(15) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT)
#else
# define DEFIO_TAG__PE15 defio_error_PE15_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PE15 DEFIO_TAG_E__NONE
# define DEFIO_REC__PE15 defio_error_PE15_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(0)
# define DEFIO_TAG__PF0 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 0)
# define DEFIO_TAG_E__PF0 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 0)
# define DEFIO_REC__PF0 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(0) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF0 defio_error_PF0_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF0 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF0 defio_error_PF0_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(1)
# define DEFIO_TAG__PF1 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 1)
# define DEFIO_TAG_E__PF1 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 1)
# define DEFIO_REC__PF1 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(1) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF1 defio_error_PF1_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF1 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF1 defio_error_PF1_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(2)
# define DEFIO_TAG__PF2 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 2)
# define DEFIO_TAG_E__PF2 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 2)
# define DEFIO_REC__PF2 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(2) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF2 defio_error_PF2_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF2 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF2 defio_error_PF2_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(3)
# define DEFIO_TAG__PF3 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 3)
# define DEFIO_TAG_E__PF3 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 3)
# define DEFIO_REC__PF3 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(3) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF3 defio_error_PF3_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF3 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF3 defio_error_PF3_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(4)
# define DEFIO_TAG__PF4 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 4)
# define DEFIO_TAG_E__PF4 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 4)
# define DEFIO_REC__PF4 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(4) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF4 defio_error_PF4_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF4 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF4 defio_error_PF4_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(5)
# define DEFIO_TAG__PF5 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 5)
# define DEFIO_TAG_E__PF5 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 5)
# define DEFIO_REC__PF5 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(5) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF5 defio_error_PF5_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF5 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF5 defio_error_PF5_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(6)
# define DEFIO_TAG__PF6 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 6)
# define DEFIO_TAG_E__PF6 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 6)
# define DEFIO_REC__PF6 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(6) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF6 defio_error_PF6_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF6 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF6 defio_error_PF6_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(7)
# define DEFIO_TAG__PF7 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 7)
# define DEFIO_TAG_E__PF7 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 7)
# define DEFIO_REC__PF7 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(7) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF7 defio_error_PF7_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF7 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF7 defio_error_PF7_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(8)
# define DEFIO_TAG__PF8 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 8)
# define DEFIO_TAG_E__PF8 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 8)
# define DEFIO_REC__PF8 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(8) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF8 defio_error_PF8_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF8 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF8 defio_error_PF8_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(9)
# define DEFIO_TAG__PF9 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 9)
# define DEFIO_TAG_E__PF9 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 9)
# define DEFIO_REC__PF9 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(9) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF9 defio_error_PF9_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF9 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF9 defio_error_PF9_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(10)
# define DEFIO_TAG__PF10 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 10)
# define DEFIO_TAG_E__PF10 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 10)
# define DEFIO_REC__PF10 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(10) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF10 defio_error_PF10_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF10 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF10 defio_error_PF10_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(11)
# define DEFIO_TAG__PF11 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 11)
# define DEFIO_TAG_E__PF11 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 11)
# define DEFIO_REC__PF11 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(11) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF11 defio_error_PF11_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF11 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF11 defio_error_PF11_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(12)
# define DEFIO_TAG__PF12 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 12)
# define DEFIO_TAG_E__PF12 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 12)
# define DEFIO_REC__PF12 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(12) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF12 defio_error_PF12_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF12 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF12 defio_error_PF12_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(13)
# define DEFIO_TAG__PF13 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 13)
# define DEFIO_TAG_E__PF13 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 13)
# define DEFIO_REC__PF13 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(13) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF13 defio_error_PF13_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF13 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF13 defio_error_PF13_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(14)
# define DEFIO_TAG__PF14 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 14)
# define DEFIO_TAG_E__PF14 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 14)
# define DEFIO_REC__PF14 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(14) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF14 defio_error_PF14_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF14 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF14 defio_error_PF14_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_F_USED_MASK & BIT(15)
# define DEFIO_TAG__PF15 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 15)
# define DEFIO_TAG_E__PF15 DEFIO_TAG_MAKE(DEFIO_GPIOID__F, 15)
# define DEFIO_REC__PF15 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_F_USED_MASK & (BIT(15) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT)
#else
# define DEFIO_TAG__PF15 defio_error_PF15_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PF15 DEFIO_TAG_E__NONE
# define DEFIO_REC__PF15 defio_error_PF15_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(0)
# define DEFIO_TAG__PG0 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 0)
# define DEFIO_TAG_E__PG0 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 0)
# define DEFIO_REC__PG0 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(0) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG0 defio_error_PG0_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG0 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG0 defio_error_PG0_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(1)
# define DEFIO_TAG__PG1 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 1)
# define DEFIO_TAG_E__PG1 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 1)
# define DEFIO_REC__PG1 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(1) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG1 defio_error_PG1_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG1 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG1 defio_error_PG1_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(2)
# define DEFIO_TAG__PG2 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 2)
# define DEFIO_TAG_E__PG2 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 2)
# define DEFIO_REC__PG2 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(2) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG2 defio_error_PG2_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG2 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG2 defio_error_PG2_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(3)
# define DEFIO_TAG__PG3 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 3)
# define DEFIO_TAG_E__PG3 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 3)
# define DEFIO_REC__PG3 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(3) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG3 defio_error_PG3_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG3 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG3 defio_error_PG3_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(4)
# define DEFIO_TAG__PG4 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 4)
# define DEFIO_TAG_E__PG4 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 4)
# define DEFIO_REC__PG4 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(4) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG4 defio_error_PG4_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG4 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG4 defio_error_PG4_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(5)
# define DEFIO_TAG__PG5 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 5)
# define DEFIO_TAG_E__PG5 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 5)
# define DEFIO_REC__PG5 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(5) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG5 defio_error_PG5_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG5 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG5 defio_error_PG5_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(6)
# define DEFIO_TAG__PG6 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 6)
# define DEFIO_TAG_E__PG6 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 6)
# define DEFIO_REC__PG6 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(6) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG6 defio_error_PG6_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG6 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG6 defio_error_PG6_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(7)
# define DEFIO_TAG__PG7 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 7)
# define DEFIO_TAG_E__PG7 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 7)
# define DEFIO_REC__PG7 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(7) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG7 defio_error_PG7_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG7 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG7 defio_error_PG7_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(8)
# define DEFIO_TAG__PG8 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 8)
# define DEFIO_TAG_E__PG8 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 8)
# define DEFIO_REC__PG8 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(8) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG8 defio_error_PG8_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG8 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG8 defio_error_PG8_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(9)
# define DEFIO_TAG__PG9 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 9)
# define DEFIO_TAG_E__PG9 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 9)
# define DEFIO_REC__PG9 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(9) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG9 defio_error_PG9_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG9 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG9 defio_error_PG9_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(10)
# define DEFIO_TAG__PG10 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 10)
# define DEFIO_TAG_E__PG10 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 10)
# define DEFIO_REC__PG10 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(10) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG10 defio_error_PG10_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG10 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG10 defio_error_PG10_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(11)
# define DEFIO_TAG__PG11 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 11)
# define DEFIO_TAG_E__PG11 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 11)
# define DEFIO_REC__PG11 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(11) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG11 defio_error_PG11_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG11 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG11 defio_error_PG11_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(12)
# define DEFIO_TAG__PG12 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 12)
# define DEFIO_TAG_E__PG12 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 12)
# define DEFIO_REC__PG12 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(12) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG12 defio_error_PG12_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG12 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG12 defio_error_PG12_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(13)
# define DEFIO_TAG__PG13 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 13)
# define DEFIO_TAG_E__PG13 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 13)
# define DEFIO_REC__PG13 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(13) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG13 defio_error_PG13_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG13 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG13 defio_error_PG13_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(14)
# define DEFIO_TAG__PG14 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 14)
# define DEFIO_TAG_E__PG14 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 14)
# define DEFIO_REC__PG14 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(14) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG14 defio_error_PG14_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG14 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG14 defio_error_PG14_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_G_USED_MASK & BIT(15)
# define DEFIO_TAG__PG15 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 15)
# define DEFIO_TAG_E__PG15 DEFIO_TAG_MAKE(DEFIO_GPIOID__G, 15)
# define DEFIO_REC__PG15 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_G_USED_MASK & (BIT(15) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT)
#else
# define DEFIO_TAG__PG15 defio_error_PG15_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PG15 DEFIO_TAG_E__NONE
# define DEFIO_REC__PG15 defio_error_PG15_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(0)
# define DEFIO_TAG__PH0 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 0)
# define DEFIO_TAG_E__PH0 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 0)
# define DEFIO_REC__PH0 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(0) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH0 defio_error_PH0_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH0 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH0 defio_error_PH0_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(1)
# define DEFIO_TAG__PH1 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 1)
# define DEFIO_TAG_E__PH1 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 1)
# define DEFIO_REC__PH1 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(1) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH1 defio_error_PH1_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH1 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH1 defio_error_PH1_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(2)
# define DEFIO_TAG__PH2 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 2)
# define DEFIO_TAG_E__PH2 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 2)
# define DEFIO_REC__PH2 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(2) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH2 defio_error_PH2_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH2 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH2 defio_error_PH2_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(3)
# define DEFIO_TAG__PH3 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 3)
# define DEFIO_TAG_E__PH3 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 3)
# define DEFIO_REC__PH3 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(3) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH3 defio_error_PH3_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH3 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH3 defio_error_PH3_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(4)
# define DEFIO_TAG__PH4 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 4)
# define DEFIO_TAG_E__PH4 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 4)
# define DEFIO_REC__PH4 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(4) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH4 defio_error_PH4_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH4 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH4 defio_error_PH4_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(5)
# define DEFIO_TAG__PH5 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 5)
# define DEFIO_TAG_E__PH5 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 5)
# define DEFIO_REC__PH5 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(5) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH5 defio_error_PH5_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH5 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH5 defio_error_PH5_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(6)
# define DEFIO_TAG__PH6 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 6)
# define DEFIO_TAG_E__PH6 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 6)
# define DEFIO_REC__PH6 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(6) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH6 defio_error_PH6_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH6 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH6 defio_error_PH6_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(7)
# define DEFIO_TAG__PH7 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 7)
# define DEFIO_TAG_E__PH7 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 7)
# define DEFIO_REC__PH7 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(7) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH7 defio_error_PH7_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH7 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH7 defio_error_PH7_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(8)
# define DEFIO_TAG__PH8 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 8)
# define DEFIO_TAG_E__PH8 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 8)
# define DEFIO_REC__PH8 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(8) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH8 defio_error_PH8_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH8 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH8 defio_error_PH8_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(9)
# define DEFIO_TAG__PH9 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 9)
# define DEFIO_TAG_E__PH9 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 9)
# define DEFIO_REC__PH9 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(9) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH9 defio_error_PH9_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH9 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH9 defio_error_PH9_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(10)
# define DEFIO_TAG__PH10 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 10)
# define DEFIO_TAG_E__PH10 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 10)
# define DEFIO_REC__PH10 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(10) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH10 defio_error_PH10_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH10 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH10 defio_error_PH10_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(11)
# define DEFIO_TAG__PH11 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 11)
# define DEFIO_TAG_E__PH11 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 11)
# define DEFIO_REC__PH11 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(11) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH11 defio_error_PH11_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH11 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH11 defio_error_PH11_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(12)
# define DEFIO_TAG__PH12 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 12)
# define DEFIO_TAG_E__PH12 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 12)
# define DEFIO_REC__PH12 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(12) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH12 defio_error_PH12_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH12 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH12 defio_error_PH12_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(13)
# define DEFIO_TAG__PH13 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 13)
# define DEFIO_TAG_E__PH13 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 13)
# define DEFIO_REC__PH13 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(13) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH13 defio_error_PH13_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH13 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH13 defio_error_PH13_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(14)
# define DEFIO_TAG__PH14 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 14)
# define DEFIO_TAG_E__PH14 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 14)
# define DEFIO_REC__PH14 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(14) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH14 defio_error_PH14_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH14 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH14 defio_error_PH14_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_H_USED_MASK & BIT(15)
# define DEFIO_TAG__PH15 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 15)
# define DEFIO_TAG_E__PH15 DEFIO_TAG_MAKE(DEFIO_GPIOID__H, 15)
# define DEFIO_REC__PH15 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_H_USED_MASK & (BIT(15) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT)
#else
# define DEFIO_TAG__PH15 defio_error_PH15_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PH15 DEFIO_TAG_E__NONE
# define DEFIO_REC__PH15 defio_error_PH15_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(0)
# define DEFIO_TAG__PI0 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 0)
# define DEFIO_TAG_E__PI0 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 0)
# define DEFIO_REC__PI0 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(0) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI0 defio_error_PI0_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI0 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI0 defio_error_PI0_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(1)
# define DEFIO_TAG__PI1 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 1)
# define DEFIO_TAG_E__PI1 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 1)
# define DEFIO_REC__PI1 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(1) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI1 defio_error_PI1_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI1 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI1 defio_error_PI1_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(2)
# define DEFIO_TAG__PI2 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 2)
# define DEFIO_TAG_E__PI2 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 2)
# define DEFIO_REC__PI2 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(2) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI2 defio_error_PI2_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI2 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI2 defio_error_PI2_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(3)
# define DEFIO_TAG__PI3 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 3)
# define DEFIO_TAG_E__PI3 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 3)
# define DEFIO_REC__PI3 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(3) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI3 defio_error_PI3_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI3 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI3 defio_error_PI3_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(4)
# define DEFIO_TAG__PI4 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 4)
# define DEFIO_TAG_E__PI4 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 4)
# define DEFIO_REC__PI4 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(4) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI4 defio_error_PI4_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI4 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI4 defio_error_PI4_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(5)
# define DEFIO_TAG__PI5 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 5)
# define DEFIO_TAG_E__PI5 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 5)
# define DEFIO_REC__PI5 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(5) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI5 defio_error_PI5_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI5 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI5 defio_error_PI5_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(6)
# define DEFIO_TAG__PI6 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 6)
# define DEFIO_TAG_E__PI6 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 6)
# define DEFIO_REC__PI6 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(6) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI6 defio_error_PI6_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI6 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI6 defio_error_PI6_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(7)
# define DEFIO_TAG__PI7 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 7)
# define DEFIO_TAG_E__PI7 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 7)
# define DEFIO_REC__PI7 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(7) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI7 defio_error_PI7_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI7 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI7 defio_error_PI7_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(8)
# define DEFIO_TAG__PI8 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 8)
# define DEFIO_TAG_E__PI8 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 8)
# define DEFIO_REC__PI8 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(8) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI8 defio_error_PI8_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI8 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI8 defio_error_PI8_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(9)
# define DEFIO_TAG__PI9 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 9)
# define DEFIO_TAG_E__PI9 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 9)
# define DEFIO_REC__PI9 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(9) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI9 defio_error_PI9_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI9 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI9 defio_error_PI9_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(10)
# define DEFIO_TAG__PI10 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 10)
# define DEFIO_TAG_E__PI10 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 10)
# define DEFIO_REC__PI10 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(10) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI10 defio_error_PI10_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI10 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI10 defio_error_PI10_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(11)
# define DEFIO_TAG__PI11 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 11)
# define DEFIO_TAG_E__PI11 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 11)
# define DEFIO_REC__PI11 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(11) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI11 defio_error_PI11_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI11 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI11 defio_error_PI11_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(12)
# define DEFIO_TAG__PI12 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 12)
# define DEFIO_TAG_E__PI12 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 12)
# define DEFIO_REC__PI12 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(12) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI12 defio_error_PI12_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI12 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI12 defio_error_PI12_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(13)
# define DEFIO_TAG__PI13 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 13)
# define DEFIO_TAG_E__PI13 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 13)
# define DEFIO_REC__PI13 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(13) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI13 defio_error_PI13_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI13 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI13 defio_error_PI13_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(14)
# define DEFIO_TAG__PI14 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 14)
# define DEFIO_TAG_E__PI14 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 14)
# define DEFIO_REC__PI14 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(14) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI14 defio_error_PI14_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI14 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI14 defio_error_PI14_is_not_supported_on_TARGET
#endif
#if DEFIO_PORT_I_USED_MASK & BIT(15)
# define DEFIO_TAG__PI15 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 15)
# define DEFIO_TAG_E__PI15 DEFIO_TAG_MAKE(DEFIO_GPIOID__I, 15)
# define DEFIO_REC__PI15 DEFIO_REC_INDEXED(BITCOUNT(DEFIO_PORT_I_USED_MASK & (BIT(15) - 1)) + DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT)
#else
# define DEFIO_TAG__PI15 defio_error_PI15_is_not_supported_on_TARGET
# define DEFIO_TAG_E__PI15 DEFIO_TAG_E__NONE
# define DEFIO_REC__PI15 defio_error_PI15_is_not_supported_on_TARGET
#endif
#define DEFIO_IO_USED_COUNT (DEFIO_PORT_A_USED_COUNT+DEFIO_PORT_B_USED_COUNT+DEFIO_PORT_C_USED_COUNT+DEFIO_PORT_D_USED_COUNT+DEFIO_PORT_E_USED_COUNT+DEFIO_PORT_F_USED_COUNT+DEFIO_PORT_G_USED_COUNT+DEFIO_PORT_H_USED_COUNT+DEFIO_PORT_I_USED_COUNT)
#if !defined DEFIO_PORT_USED_LIST && DEFIO_PORT_I_USED_COUNT > 0
# define DEFIO_PORT_USED_COUNT 9
# define DEFIO_PORT_USED_LIST DEFIO_PORT_A_USED_MASK,DEFIO_PORT_B_USED_MASK,DEFIO_PORT_C_USED_MASK,DEFIO_PORT_D_USED_MASK,DEFIO_PORT_E_USED_MASK,DEFIO_PORT_F_USED_MASK,DEFIO_PORT_G_USED_MASK,DEFIO_PORT_H_USED_MASK,DEFIO_PORT_I_USED_MASK
# define DEFIO_PORT_OFFSET_LIST DEFIO_PORT_A_OFFSET,DEFIO_PORT_B_OFFSET,DEFIO_PORT_C_OFFSET,DEFIO_PORT_D_OFFSET,DEFIO_PORT_E_OFFSET,DEFIO_PORT_F_OFFSET,DEFIO_PORT_G_OFFSET,DEFIO_PORT_H_OFFSET,DEFIO_PORT_I_OFFSET
#endif
#if !defined DEFIO_PORT_USED_LIST && DEFIO_PORT_H_USED_COUNT > 0
# define DEFIO_PORT_USED_COUNT 8
# define DEFIO_PORT_USED_LIST DEFIO_PORT_A_USED_MASK,DEFIO_PORT_B_USED_MASK,DEFIO_PORT_C_USED_MASK,DEFIO_PORT_D_USED_MASK,DEFIO_PORT_E_USED_MASK,DEFIO_PORT_F_USED_MASK,DEFIO_PORT_G_USED_MASK,DEFIO_PORT_H_USED_MASK
# define DEFIO_PORT_OFFSET_LIST DEFIO_PORT_A_OFFSET,DEFIO_PORT_B_OFFSET,DEFIO_PORT_C_OFFSET,DEFIO_PORT_D_OFFSET,DEFIO_PORT_E_OFFSET,DEFIO_PORT_F_OFFSET,DEFIO_PORT_G_OFFSET,DEFIO_PORT_H_OFFSET
#endif
#if !defined DEFIO_PORT_USED_LIST && DEFIO_PORT_G_USED_COUNT > 0
# define DEFIO_PORT_USED_COUNT 7
# define DEFIO_PORT_USED_LIST DEFIO_PORT_A_USED_MASK,DEFIO_PORT_B_USED_MASK,DEFIO_PORT_C_USED_MASK,DEFIO_PORT_D_USED_MASK,DEFIO_PORT_E_USED_MASK,DEFIO_PORT_F_USED_MASK,DEFIO_PORT_G_USED_MASK
# define DEFIO_PORT_OFFSET_LIST DEFIO_PORT_A_OFFSET,DEFIO_PORT_B_OFFSET,DEFIO_PORT_C_OFFSET,DEFIO_PORT_D_OFFSET,DEFIO_PORT_E_OFFSET,DEFIO_PORT_F_OFFSET,DEFIO_PORT_G_OFFSET
#endif
#if !defined DEFIO_PORT_USED_LIST && DEFIO_PORT_F_USED_COUNT > 0
# define DEFIO_PORT_USED_COUNT 6
# define DEFIO_PORT_USED_LIST DEFIO_PORT_A_USED_MASK,DEFIO_PORT_B_USED_MASK,DEFIO_PORT_C_USED_MASK,DEFIO_PORT_D_USED_MASK,DEFIO_PORT_E_USED_MASK,DEFIO_PORT_F_USED_MASK
# define DEFIO_PORT_OFFSET_LIST DEFIO_PORT_A_OFFSET,DEFIO_PORT_B_OFFSET,DEFIO_PORT_C_OFFSET,DEFIO_PORT_D_OFFSET,DEFIO_PORT_E_OFFSET,DEFIO_PORT_F_OFFSET
#endif
#if !defined DEFIO_PORT_USED_LIST && DEFIO_PORT_E_USED_COUNT > 0
# define DEFIO_PORT_USED_COUNT 5
# define DEFIO_PORT_USED_LIST DEFIO_PORT_A_USED_MASK,DEFIO_PORT_B_USED_MASK,DEFIO_PORT_C_USED_MASK,DEFIO_PORT_D_USED_MASK,DEFIO_PORT_E_USED_MASK
# define DEFIO_PORT_OFFSET_LIST DEFIO_PORT_A_OFFSET,DEFIO_PORT_B_OFFSET,DEFIO_PORT_C_OFFSET,DEFIO_PORT_D_OFFSET,DEFIO_PORT_E_OFFSET
#endif
#if !defined DEFIO_PORT_USED_LIST && DEFIO_PORT_D_USED_COUNT > 0
# define DEFIO_PORT_USED_COUNT 4
# define DEFIO_PORT_USED_LIST DEFIO_PORT_A_USED_MASK,DEFIO_PORT_B_USED_MASK,DEFIO_PORT_C_USED_MASK,DEFIO_PORT_D_USED_MASK
# define DEFIO_PORT_OFFSET_LIST DEFIO_PORT_A_OFFSET,DEFIO_PORT_B_OFFSET,DEFIO_PORT_C_OFFSET,DEFIO_PORT_D_OFFSET
#endif
#if !defined DEFIO_PORT_USED_LIST && DEFIO_PORT_C_USED_COUNT > 0
# define DEFIO_PORT_USED_COUNT 3
# define DEFIO_PORT_USED_LIST DEFIO_PORT_A_USED_MASK,DEFIO_PORT_B_USED_MASK,DEFIO_PORT_C_USED_MASK
# define DEFIO_PORT_OFFSET_LIST DEFIO_PORT_A_OFFSET,DEFIO_PORT_B_OFFSET,DEFIO_PORT_C_OFFSET
#endif
#if !defined DEFIO_PORT_USED_LIST && DEFIO_PORT_B_USED_COUNT > 0
# define DEFIO_PORT_USED_COUNT 2
# define DEFIO_PORT_USED_LIST DEFIO_PORT_A_USED_MASK,DEFIO_PORT_B_USED_MASK
# define DEFIO_PORT_OFFSET_LIST DEFIO_PORT_A_OFFSET,DEFIO_PORT_B_OFFSET
#endif
#if !defined DEFIO_PORT_USED_LIST && DEFIO_PORT_A_USED_COUNT > 0
# define DEFIO_PORT_USED_COUNT 1
# define DEFIO_PORT_USED_LIST DEFIO_PORT_A_USED_MASK
# define DEFIO_PORT_OFFSET_LIST DEFIO_PORT_A_OFFSET
#endif
#if !defined(DEFIO_PORT_USED_LIST)
# define DEFIO_PORT_USED_COUNT 0
# define DEFIO_PORT_USED_LIST
# define DEFIO_PORT_OFFSET_LIST
#endif


// ../inav/src/main/drivers/bus_spi.c
#ifdef USE_SPI
#ifndef SPI1_SCK_PIN
#define SPI1_NSS_PIN    PA4
#define SPI1_SCK_PIN    PA5
#define SPI1_MISO_PIN   PA6
#define SPI1_MOSI_PIN   PA7
#endif
#ifndef SPI2_SCK_PIN
#define SPI2_NSS_PIN    PB12
#define SPI2_SCK_PIN    PB13
#define SPI2_MISO_PIN   PB14
#define SPI2_MOSI_PIN   PB15
#endif
#ifndef SPI3_SCK_PIN
#define SPI3_NSS_PIN    PA15
#define SPI3_SCK_PIN    PB3
#define SPI3_MISO_PIN   PB4
#define SPI3_MOSI_PIN   PB5
#endif
#ifndef SPI1_NSS_PIN
#define SPI1_NSS_PIN NONE
#endif
#ifndef SPI2_NSS_PIN
#define SPI2_NSS_PIN NONE
#endif
#ifndef SPI3_NSS_PIN
#define SPI3_NSS_PIN NONE
#endif
#define BR_CLEAR_MASK 0xFFC7
#endif


// ../inav/src/main/drivers/serial_usb_vcp_at32f43x.c
#ifdef USE_VCP
#define USB_TIMEOUT  50
#endif


// ../inav/src/main/drivers/display_ug2864hsweg01.h
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define FONT_WIDTH 5
#define FONT_HEIGHT 7
#define HORIZONTAL_PADDING 1
#define VERTICAL_PADDING 1
#define CHARACTER_WIDTH_TOTAL (FONT_WIDTH + HORIZONTAL_PADDING)
#define CHARACTER_HEIGHT_TOTAL (FONT_HEIGHT + VERTICAL_PADDING)
#define SCREEN_CHARACTER_COLUMN_COUNT (SCREEN_WIDTH / CHARACTER_WIDTH_TOTAL)
#define SCREEN_CHARACTER_ROW_COUNT (SCREEN_HEIGHT / CHARACTER_HEIGHT_TOTAL)
#define VERTICAL_BARGRAPH_ZERO_CHARACTER (128 + 32)
#define VERTICAL_BARGRAPH_CHARACTER_COUNT 7


// ../inav/src/main/drivers/usb_msc_f7xx.c
#if defined(USE_USB_MSC)
#define DEBOUNCE_TIME_MS 20
#endif


// ../inav/src/main/drivers/exti.c
#if !defined(SITL_BUILD)
#define EXTI_IRQ_GROUPS 7
#if defined(STM32H7)
#define EXTI_REG_IMR (EXTI_D1->IMR1)
#define EXTI_REG_PR  (EXTI_D1->PR1)
#elif defined(AT32F43x)
#define EXTI_REG_IMR (EXINT->inten)
#define EXTI_REG_PR  (EXINT->intsts)
#else
#define EXTI_REG_IMR (EXTI->IMR)
#define EXTI_REG_PR  (EXTI->PR)
#endif
#define _EXTI_IRQ_HANDLER(name)                 \
    void name(void) {                           \
        EXTI_IRQHandler();                      \
    }                                           \
    struct dummy                                \

#endif


// ../inav/src/main/drivers/bus_quadspi_hal.c
#ifdef USE_QUADSPI
#define QUADSPI_DEFAULT_TIMEOUT 10
#endif


// ../inav/src/main/drivers/light_led.h
#define LED_NUMBER 3
#ifdef LED0
# define LED0_TOGGLE              ledToggle(0)
# define LED0_OFF                 ledSet(0, false)
# define LED0_ON                  ledSet(0, true)
#else
# define LED0_TOGGLE              do {} while (0)
# define LED0_OFF                 do {} while (0)
# define LED0_ON                  do {} while (0)
#endif
#ifdef LED1
# define LED1_TOGGLE              ledToggle(1)
# define LED1_OFF                 ledSet(1, false)
# define LED1_ON                  ledSet(1, true)
#else
# define LED1_TOGGLE              do {} while (0)
# define LED1_OFF                 do {} while (0)
# define LED1_ON                  do {} while (0)
#endif
#ifdef LED2
# define LED2_TOGGLE              ledToggle(2)
# define LED2_OFF                 ledSet(2, false)
# define LED2_ON                  ledSet(2, true)
#else
# define LED2_TOGGLE              do {} while (0)
# define LED2_OFF                 do {} while (0)
# define LED2_ON                  do {} while (0)
#endif


// ../inav/src/main/drivers/pitotmeter/pitotmeter_dlvr_l10d.c
#define DLVR_L10D_ADDR                 0x28
#define INCH_OF_H2O_TO_PASCAL   248.84f
#define INCH_H2O_TO_PASCAL(press) (INCH_OF_H2O_TO_PASCAL * (press))
#define RANGE_INCH_H2O      10
#define DLVR_OFFSET         8192.0f
#define DLVR_SCALE          16384.0f
#define DLVR_OFFSET_CORR    0.0f


// ../inav/src/main/drivers/pitotmeter/pitotmeter_msp.c
#if defined(USE_PITOT_MSP)
#define MSP_PITOT_TIMEOUT_MS      500
#endif


// ../inav/src/main/drivers/pitotmeter/pitotmeter_adc.c
#if defined(USE_ADC) && defined(USE_PITOT_ADC)
#define PITOT_ADC_VOLTAGE_SCALER        (2.0f / 1.0f)
#define PITOT_ADC_VOLTAGE_ZERO          (2.5f)
#define PITOT_ADC_VOLTAGE_TO_PRESSURE   (1000.0f)
#endif


// ../inav/src/main/drivers/pitotmeter/pitotmeter_ms4525.c
#define MS4525_ADDR                 0x28


// ../inav/src/main/drivers/compass/compass_msp.c
#if defined(USE_MAG_MSP)
#define MSP_MAG_TIMEOUT_MS      250
#endif


// ../inav/src/main/drivers/compass/compass_mag3110.c
#ifdef USE_MAG_MAG3110
#define MAG3110_MAG_I2C_ADDRESS     0x0E
#define MAG3110_MAG_REG_STATUS       0x00
#define MAG3110_MAG_REG_HXL          0x01
#define MAG3110_MAG_REG_HXH          0x02
#define MAG3110_MAG_REG_HYL          0x03
#define MAG3110_MAG_REG_HYH          0x04
#define MAG3110_MAG_REG_HZL          0x05
#define MAG3110_MAG_REG_HZH          0x06
#define MAG3110_MAG_REG_WHO_AM_I     0x07
#define MAG3110_MAG_REG_SYSMODE      0x08
#define MAG3110_MAG_REG_CTRL_REG1    0x10
#define MAG3110_MAG_REG_CTRL_REG2    0x11
#define BIT_STATUS_REG_DATA_READY               (1 << 3)
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_ist8310.c
#ifdef USE_MAG_IST8310
#define IST8310_ADDRESS 0x0C
#define IST8310_REG_DATA 0x03
#define IST8310_REG_WHOAMI 0x00
#define IST8310_REG_CNTRL1 0x0A
#define IST8310_REG_CNTRL2 0x0B
#define IST8310_REG_AVERAGE 0x41
#define IST8310_REG_PDCNTL 0x42
#define IST8310_ODR_SINGLE 0x01
#define IST8310_ODR_10_HZ 0x03
#define IST8310_ODR_20_HZ 0x05
#define IST8310_ODR_50_HZ 0x07
#define IST8310_ODR_100_HZ 0x06
#define IST8310_CHIP_ID 0x10
#define IST8310_AVG_16  0x24
#define IST8310_PULSE_DURATION_NORMAL 0xC0
#define IST8310_CNTRL2_RESET 0x01
#define IST8310_CNTRL2_DRPOL 0x04
#define IST8310_CNTRL2_DRENA 0x08
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_ist8308.c
#ifdef USE_MAG_IST8308
#define IST8308_ADDRESS                                 0x0C
#define IST8308_REG_WHOAMI                              0x00
#define     IST8308_CHIP_ID                             0x08
#define IST8308_REG_DATA                                0x11
#define IST8308_REG_CNTRL1                              0x30
#define     IST8308_NSF_DISABLE                         0x00
#define     IST8308_NSF_LOW                             0x20
#define     IST8308_NSF_MIDDLE                          0x40
#define     IST8308_NSF_HIGH                            0x60
#define IST8308_REG_CNTRL2                              0x31
#define     IST8308_OPMODE_STANDBY_MODE                 0x00
#define     IST8308_OPMODE_SINGLE_MODE                  0x01
#define     IST8308_OPMODE_CONTINUOS_MODE_10HZ          0x02
#define     IST8308_OPMODE_CONTINUOS_MODE_20HZ          0x04
#define     IST8308_OPMODE_CONTINUOS_MODE_50HZ          0x06
#define     IST8308_OPMODE_CONTINUOS_MODE_100HZ         0x08
#define     IST8308_OPMODE_CONTINUOS_MODE_200HZ         0x0A
#define     IST8308_OPMODE_CONTINUOS_MODE_8HZ           0x0B
#define     IST8308_OPMODE_CONTINUOS_MODE_1HZ           0x0C
#define     IST8308_OPMODE_CONTINUOS_MODE_0_5HZ         0x0D
#define     IST8308_OPMODE_SELF_TEST_MODE               0x10
#define IST8308_REG_CNTRL4                              0x34
#define     IST8308_SENSITIVITY_6_6                     0x00
#define     IST8308_SENSITIVITY_13_2                    0x01
#define IST8308_REG_OSR_CNTRL                           0x41
#define     IST8308_X_Z_SENSOR_OSR_1                    0x00
#define     IST8308_X_Z_SENSOR_OSR_2                    0x01
#define     IST8308_X_Z_SENSOR_OSR_4                    0x02
#define     IST8308_X_Z_SENSOR_OSR_8                    0x03
#define     IST8308_X_Z_SENSOR_OSR_16                   0x04
#define     IST8308_X_Z_SENSOR_OSR_32                   0x05
#define     IST8308_Y_SENSOR_OSR_1                      (0x00<<3)
#define     IST8308_Y_SENSOR_OSR_2                      (0x01<<3)
#define     IST8308_Y_SENSOR_OSR_4                      (0x02<<3)
#define     IST8308_Y_SENSOR_OSR_8                      (0x03<<3)
#define     IST8308_Y_SENSOR_OSR_16                     (0x04<<3)
#define     IST8308_Y_SENSOR_OSR_32                     (0x05<<3)
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_mpu9250.c
#if defined(USE_MAG_MPU9250) && defined(USE_IMU_MPU9250)
#define AK8963_MAG_I2C_ADDRESS          0x0C
#define AK8963_DEVICE_ID                0x48
#define AK8963_MAG_REG_WHO_AM_I         0x00
#define AK8963_MAG_REG_INFO             0x01
#define AK8963_MAG_REG_STATUS1          0x02
#define AK8963_MAG_REG_HXL              0x03
#define AK8963_MAG_REG_HXH              0x04
#define AK8963_MAG_REG_HYL              0x05
#define AK8963_MAG_REG_HYH              0x06
#define AK8963_MAG_REG_HZL              0x07
#define AK8963_MAG_REG_HZH              0x08
#define AK8963_MAG_REG_STATUS2          0x09
#define AK8963_MAG_REG_CNTL             0x0a
#define AK8963_MAG_REG_ASCT             0x0c
#define AK8963_MAG_REG_ASAX             0x10
#define AK8963_MAG_REG_ASAY             0x11
#define AK8963_MAG_REG_ASAZ             0x12
#define READ_FLAG                       0x80
#define STATUS1_DATA_READY              0x01
#define STATUS1_DATA_OVERRUN            0x02
#define STATUS2_MAG_SENSOR_OVERFLOW     0x08
#define CNTL_MODE_POWER_DOWN            0x00
#define CNTL_MODE_ONCE                  0x01
#define CNTL_MODE_CONT1                 0x02
#define CNTL_MODE_CONT2                 0x06
#define CNTL_MODE_SELF_TEST             0x08
#define CNTL_MODE_FUSE_ROM              0x0F
#define CNTL_BIT_14_BIT                 0x00
#define CNTL_BIT_16_BIT                 0x10
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_qmc5883l.c
#ifdef USE_MAG_QMC5883
#define QMC5883L_MAG_I2C_ADDRESS     0x0D
#define QMC5883L_REG_CONF1 0x09
#define QMC5883L_REG_CONF2 0x0A
#define QMC5883L_ODR_10HZ (0x00 << 2)
#define QMC5883L_ODR_50HZ  (0x01 << 2)
#define QMC5883L_ODR_100HZ (0x02 << 2)
#define QMC5883L_ODR_200HZ (0x03 << 2)
#define QMC5883L_MODE_STANDBY 0x00
#define QMC5883L_MODE_CONTINUOUS 0x01
#define QMC5883L_RNG_2G (0x00 << 4)
#define QMC5883L_RNG_8G (0x01 << 4)
#define QMC5883L_OSR_512 (0x00 << 6)
#define QMC5883L_OSR_256 (0x01 << 6)
#define QMC5883L_OSR_128	(0x10 << 6)
#define QMC5883L_OSR_64	(0x11	<< 6)
#define QMC5883L_RST 0x80
#define QMC5883L_REG_DATA_OUTPUT_X 0x00
#define QMC5883L_REG_STATUS 0x06
#define QMC5883L_REG_ID 0x0D
#define QMC5883_ID_VAL 0xFF
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_mlx90393.c
#ifdef USE_MAG_MLX90393
#define MLX90393_MEASURE_3D                         0b00001110
#define MLX90393_NOP                                0b00000000
#define MLX90393_START_BURST_MODE                   0b00010000
#define MLX90393_START_WAKE_UP_ON_CHANGE_MODE       0b00100000
#define MLX90393_START_SINGLE_MEASUREMENT_MODE      0b00110000
#define MLX90393_READ_MEASUREMENT                   0b01000000
#define MLX90393_READ_REGISTER                      0b01010000
#define MLX90393_WRITE_REGISTER                     0b01100000
#define MLX90393_EXIT_MODE                          0b10000000
#define MLX90393_MEMORY_RECALL                      0b11010000
#define MLX90393_MEMORY_STORE                       0b11100000
#define MLX90393_RESET                              0b11110000
#define MLX90393_BURST_MODE_FLAG                    0b10000000
#define MLX90393_WAKE_UP_ON_CHANGE_MODE_FLAG        0b01000000
#define MLX90393_SINGLE_MEASUREMENT_MODE_FLAG       0b00100000
#define MLX90393_ERROR_FLAG                         0b00010000
#define MLX90393_SINGLE_ERROR_DETECTION_FLAG        0b00001000
#define MLX90393_RESET_FLAG                         0b00000100
#define MLX90393_D1_FLAG                            0b00000010
#define MLX90393_D0_FLAG                            0b00000001
#define DETECTION_MAX_RETRY_COUNT   5
#define REG_BUF_LEN                 3
#define GAIN_SEL_HALLCONF_REG       0x0
#define GAIN_SEL_HALLCONF_REG_VALUE 0x007C
#define TCMP_EN_REG                 0x4
#define TCMP_EN_REG_VALUE           0x62C4
#define RES_XYZ_OSR_FLT_REG         0x8
#define RES_XYZ_OSR_FLT_REG_VALUE   0x001D
#endif


// ../inav/src/main/drivers/compass/compass_ak8975.c
#ifdef USE_MAG_AK8975
#define AK8975_MAG_I2C_ADDRESS      0x0C
#define AK8975_MAG_REG_WHO_AM_I     0x00
#define AK8975_MAG_REG_INFO         0x01
#define AK8975_MAG_REG_STATUS1      0x02
#define AK8975_MAG_REG_HXL          0x03
#define AK8975_MAG_REG_HXH          0x04
#define AK8975_MAG_REG_HYL          0x05
#define AK8975_MAG_REG_HYH          0x06
#define AK8975_MAG_REG_HZL          0x07
#define AK8975_MAG_REG_HZH          0x08
#define AK8975_MAG_REG_STATUS2      0x09
#define AK8975_MAG_REG_CNTL         0x0a
#define AK8975_MAG_REG_ASCT         0x0c
#define AK8975A_ASAX 0x10
#define AK8975A_ASAY 0x11
#define AK8975A_ASAZ 0x12
#define BIT_STATUS1_REG_DATA_READY              (1 << 0)
#define BIT_STATUS2_REG_DATA_ERROR              (1 << 2)
#define BIT_STATUS2_REG_MAG_SENSOR_OVERFLOW     (1 << 3)
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_lis3mdl.c
#ifdef USE_MAG_LIS3MDL
#define LIS3MDL_MAG_I2C_ADDRESS     0x1E
#define LIS3MDL_MAG_I2C_ADDRESS2    0x1C
#define LIS3MDL_DEVICE_ID           0x3D
#define LIS3MDL_REG_WHO_AM_I        0x0F
#define LIS3MDL_REG_CTRL_REG1       0x20
#define LIS3MDL_REG_CTRL_REG2       0x21
#define LIS3MDL_REG_CTRL_REG3       0x22
#define LIS3MDL_REG_CTRL_REG4       0x23
#define LIS3MDL_REG_CTRL_REG5       0x24
#define LIS3MDL_REG_STATUS_REG      0x27
#define LIS3MDL_REG_OUT_X_L         0x28
#define LIS3MDL_REG_OUT_X_H         0x29
#define LIS3MDL_REG_OUT_Y_L         0x2A
#define LIS3MDL_REG_OUT_Y_H         0x2B
#define LIS3MDL_REG_OUT_Z_L         0x2C
#define LIS3MDL_REG_OUT_Z_H         0x2D
#define LIS3MDL_TEMP_OUT_L          0x2E
#define LIS3MDL_TEMP_OUT_H          0x2F
#define LIS3MDL_INT_CFG             0x30
#define LIS3MDL_INT_SRC             0x31
#define LIS3MDL_THS_L               0x32
#define LIS3MDL_THS_H               0x33
#define LIS3MDL_TEMP_EN             0x80
#define LIS3MDL_OM_LOW_POWER        0x00
#define LIS3MDL_OM_MED_PROF         0x20
#define LIS3MDL_OM_HI_PROF          0x40
#define LIS3MDL_OM_ULTRA_HI_PROF    0x60
#define LIS3MDL_DO_0_625            0x00
#define LIS3MDL_DO_1_25             0x04
#define LIS3MDL_DO_2_5              0x08
#define LIS3MDL_DO_5                0x0C
#define LIS3MDL_DO_10               0x10
#define LIS3MDL_DO_20               0x14
#define LIS3MDL_DO_40               0x18
#define LIS3MDL_DO_80               0x1C
#define LIS3MDL_FAST_ODR            0x02
#define LIS3MDL_FS_4GAUSS           0x00
#define LIS3MDL_FS_8GAUSS           0x20
#define LIS3MDL_FS_12GAUSS          0x40
#define LIS3MDL_FS_16GAUSS          0x60
#define LIS3MDL_REBOOT              0x08
#define LIS3MDL_SOFT_RST            0x04
#define LIS3MDL_LP                  0x20
#define LIS3MDL_SIM                 0x04
#define LIS3MDL_MD_CONTINUOUS       0x00
#define LIS3MDL_MD_SINGLE           0x01
#define LIS3MDL_MD_POWERDOWN        0x03
#define LIS3MDL_ZOM_LP              0x00
#define LIS3MDL_ZOM_MP              0x04
#define LIS3MDL_ZOM_HP              0x08
#define LIS3MDL_ZOM_UHP             0x0C
#define LIS3MDL_BLE                 0x02
#define LIS3MDL_FAST_READ           0x80
#define LIS3MDL_BDU                 0x40
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_qmc5883p.c
#ifdef USE_MAG_QMC5883P
#define QMC5883P_MAG_I2C_ADDRESS     0x2C
#define QMC5883P_REG_ID 0x00
#define QMC5883P_ID_VAL 0x80
#define QMC5883P_REG_DATA_OUTPUT_X 0x01
#define QMC5883P_DATA_BYTES 6
#define QMC5883P_REG_CONF1 0x0A
#define QMC5883P_CONF1_MODE_SUSPEND    0x00
#define QMC5883P_CONF1_MODE_NORMAL     0x01
#define QMC5883P_CONF1_MODE_SINGLE     0x02
#define QMC5883P_CONF1_MODE_CONTINUOUS 0x03
#define QMC5883P_CONF1_ODR_10HZ  (0x00 << 2)
#define QMC5883P_CONF1_ODR_50HZ  (0x01 << 2)
#define QMC5883P_CONF1_ODR_100HZ (0x02 << 2)
#define QMC5883P_CONF1_ODR_200HZ (0x03 << 2)
#define QMC5883P_CONF1_OSR1_8 (0x00 << 4)
#define QMC5883P_CONF1_OSR1_4 (0x01 << 4)
#define QMC5883P_CONF1_OSR1_2 (0x02 << 4)
#define QMC5883P_CONF1_OSR1_1 (0x03 << 4)
#define QMC5883P_CONF1_OSR2_1 (0x00 << 6)
#define QMC5883P_CONF1_OSR2_2 (0x01 << 6)
#define QMC5883P_CONF1_OSR2_4 (0x02 << 6)
#define QMC5883P_CONF1_OSR2_8 (0x03 << 6)
#define QMC5883P_REG_CONF2 0x0B
#define QMC5883P_CONF2_SET_RESET_ON     0x00
#define QMC5883P_CONF2_SET_ON_RESET_OFF 0x01
#define QMC5883P_CONF2_SET_RESET_OFF    0x02
#define QMC5883P_CONF2_RNG_30G (0x00 << 2)
#define QMC5883P_CONF2_RNG_12G (0x01 << 2)
#define QMC5883P_CONF2_RNG_8G  (0x02 << 2)
#define QMC5883P_CONF2_RNG_2G  (0x03 << 2)
#define QMC5883P_CONF2_SELF_TEST 0x40
#define QMC5883P_CONF2_RESET 0x80
#define QMC5883P_REG_STATUS 0x09
#define QMC5883P_STATUS_DRDY_MASK 0x01
#define QMC5883P_STATUS_OVFL_MASK 0x02
#define QMC5883P_REG_DATA_SIGN 0x29
#define QMC5883P_DATA_SIGN_MAGIC_VALUE 0x06
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_ak8963.c
#ifdef USE_MAG_AK8963
#define AK8963_MAG_I2C_ADDRESS          0x0C
#define AK8963_DEVICE_ID                0x48
#define AK8963_MAG_REG_WHO_AM_I         0x00
#define AK8963_MAG_REG_INFO             0x01
#define AK8963_MAG_REG_STATUS1          0x02
#define AK8963_MAG_REG_HXL              0x03
#define AK8963_MAG_REG_HXH              0x04
#define AK8963_MAG_REG_HYL              0x05
#define AK8963_MAG_REG_HYH              0x06
#define AK8963_MAG_REG_HZL              0x07
#define AK8963_MAG_REG_HZH              0x08
#define AK8963_MAG_REG_STATUS2          0x09
#define AK8963_MAG_REG_CNTL             0x0a
#define AK8963_MAG_REG_ASCT             0x0c
#define AK8963_MAG_REG_ASAX             0x10
#define AK8963_MAG_REG_ASAY             0x11
#define AK8963_MAG_REG_ASAZ             0x12
#define READ_FLAG                       0x80
#define STATUS1_DATA_READY              0x01
#define STATUS1_DATA_OVERRUN            0x02
#define STATUS2_MAG_SENSOR_OVERFLOW     0x08
#define CNTL_MODE_POWER_DOWN            0x00
#define CNTL_MODE_ONCE                  0x01
#define CNTL_MODE_CONT1                 0x02
#define CNTL_MODE_CONT2                 0x06
#define CNTL_MODE_SELF_TEST             0x08
#define CNTL_MODE_FUSE_ROM              0x0F
#define CNTL_BIT_14_BIT                 0x00
#define CNTL_BIT_16_BIT                 0x10
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_vcm5883.c
#ifdef USE_MAG_VCM5883
#define VCM5883_REGISTER_ADDR_CNTL1 0x0B
#define VCM5883_REGISTER_ADDR_CNTL2 0x0A
#define VCM5883_REGISTER_ADDR_CHIPID 0x0C
#define VCM5883_REGISTER_ADDR_OUTPUT_X 0x00
#define VCM5883_INITIAL_CONFIG 0b0100
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_rm3100.c
#ifdef USE_MAG_RM3100
#define RM3100_REG_POLL        0x00
#define RM3100_REG_CMM         0x01
#define RM3100_REG_CCX1        0x04
#define RM3100_REG_CCX0        0x05
#define RM3100_REG_CCY1        0x06
#define RM3100_REG_CCY0        0x07
#define RM3100_REG_CCZ1        0x08
#define RM3100_REG_CCZ0        0x09
#define RM3100_REG_TMRC        0x0B
#define RM3100_REG_MX          0x24
#define RM3100_REG_MY          0x27
#define RM3100_REG_MZ          0x2A
#define RM3100_REG_BIST        0x33
#define RM3100_REG_STATUS      0x34
#define RM3100_REG_HSHAKE      0x35
#define RM3100_REG_REVID       0x36
#define RM3100_REVID           0x22
#define CCX_DEFAULT_MSB        0x00
#define CCX_DEFAULT_LSB        0xC8
#define CCY_DEFAULT_MSB        CCX_DEFAULT_MSB
#define CCY_DEFAULT_LSB        CCX_DEFAULT_LSB
#define CCZ_DEFAULT_MSB        CCX_DEFAULT_MSB
#define CCZ_DEFAULT_LSB        CCX_DEFAULT_LSB
#define CMM_DEFAULT            0x71
#define TMRC_DEFAULT           0x94
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/compass/compass_hmc5883l.c
#ifdef USE_MAG_HMC5883
#define MAG_ADDRESS             0x1E
#define MAG_DATA_REGISTER       0x03
#define MAG_DATA_REGISTER_SPI   (0x03 | 0x40)
#define HMC58X3_R_CONFA         0x00
#define HMC58X3_R_CONFB         0x01
#define HMC58X3_R_MODE          0x02
#define HMC58X3_X_SELF_TEST_GAUSS (+1.16f)
#define HMC58X3_Y_SELF_TEST_GAUSS (+1.16f)
#define HMC58X3_Z_SELF_TEST_GAUSS (+1.08f)
#define SELF_TEST_LOW_LIMIT  (243.0f / 390.0f)
#define SELF_TEST_HIGH_LIMIT (575.0f / 390.0f)
#define HMC_POS_BIAS 1
#define HMC_NEG_BIAS 2
#define INITIALISATION_MAX_READ_FAILURES 5
#define DETECTION_MAX_RETRY_COUNT   200
#endif


// ../inav/src/main/drivers/accgyro/accgyro_bmi160.c
#if defined(USE_IMU_BMI160)
#define BMI160_REG_CHIPID           0x00
#define BMI160_REG_PMU_STAT         0x03
#define BMI160_REG_GYR_DATA_X_LSB   0x0C
#define BMI160_REG_ACC_DATA_X_LSB   0x12
#define BMI160_REG_STATUS           0x1B
#define BMI160_REG_TEMPERATURE_0    0x20
#define BMI160_REG_ACC_CONF         0x40
#define BMI160_REG_ACC_RANGE        0x41
#define BMI160_REG_GYR_CONF         0x42
#define BMI160_REG_GYR_RANGE        0x43
#define BMI160_REG_INT_EN1          0x51
#define BMI160_REG_INT_OUT_CTRL     0x53
#define BMI160_REG_INT_MAP1         0x56
#define BMI160_REG_FOC_CONF         0x69
#define BMI160_REG_CONF             0x6A
#define BMI160_REG_OFFSET_0         0x77
#define BMI160_REG_CMD              0x7E
#define BMI160_PMU_CMD_PMU_ACC_NORMAL   0x11
#define BMI160_PMU_CMD_PMU_GYR_NORMAL   0x15
#define BMI160_INT_EN1_DRDY             0x10
#define BMI160_INT_OUT_CTRL_INT1_CONFIG 0x0A
#define BMI160_REG_INT_MAP1_INT1_DRDY   0x80
#define BMI160_CMD_START_FOC            0x03
#define BMI160_CMD_PROG_NVM             0xA0
#define BMI160_REG_STATUS_NVM_RDY       0x10
#define BMI160_REG_STATUS_FOC_RDY       0x08
#define BMI160_REG_CONF_NVM_PROG_EN     0x02
#define BMI160_BWP_NORMAL               0x20
#define BMI160_BWP_OSR2                 0x10
#define BMI160_BWP_OSR4                 0x00
#define BMI160_ODR_400_Hz               0x0A
#define BMI160_ODR_800_Hz               0x0B
#define BMI160_ODR_1600_Hz              0x0C
#define BMI160_ODR_3200_Hz              0x0D
#define BMI160_RANGE_2G                 0x03
#define BMI160_RANGE_4G                 0x05
#define BMI160_RANGE_8G                 0x08
#define BMI160_RANGE_16G                0x0C
#define BMI160_RANGE_125DPS             0x04
#define BMI160_RANGE_250DPS             0x03
#define BMI160_RANGE_500DPS             0x02
#define BMI160_RANGE_1000DPS            0x01
#define BMI160_RANGE_2000DPS            0x00
#endif


// ../inav/src/main/drivers/accgyro/accgyro_lsm6dxx.c
#if defined(USE_IMU_LSM6DXX)
#define LSM6DSO_CHIP_ID 0x6C
#define LSM6DSL_CHIP_ID 0x6A
#define LSM6DS3_CHIP_ID 0x69
#endif


// ../inav/src/main/drivers/accgyro/accgyro_bmi270.c
#if defined(USE_IMU_BMI270)
#define BMI270_CONFIG_SIZE 328
#define BMI270_CHIP_ID 0x24
#define BMI270_CMD_SOFTRESET 0xB6
#define BMI270_PWR_CONF_HP 0x00
#define BMI270_PWR_CTRL_GYR_EN 0x02
#define BMI270_PWR_CTRL_ACC_EN 0x04
#define BMI270_PWR_CTRL_TEMP_EN 0x08
#define BMI270_ACC_CONF_HP 0x80
#define BMI270_ACC_RANGE_8G 0x02
#define BMI270_ACC_RANGE_16G 0x03
#define BMI270_GYRO_CONF_NOISE_PERF 0x40
#define BMI270_GYRO_CONF_FILTER_PERF 0x80
#define BMI270_GYRO_RANGE_2000DPS 0x08
#define BMI270_INT_MAP_DATA_DRDY_INT1 0x04
#define BMI270_INT1_IO_CTRL_ACTIVE_HIGH 0x02
#define BMI270_INT1_IO_CTRL_OUTPUT_EN 0x08
#define BMI270_ODR_400 0x0A
#define BMI270_ODR_800 0x0B
#define BMI270_ODR_1600 0x0C
#define BMI270_ODR_3200 0x0D
#define BMI270_BWP_OSR4 0x00
#define BMI270_BWP_OSR2 0x10
#define BMI270_BWP_NORM 0x20
#endif


// ../inav/src/main/drivers/accgyro/accgyro_bmi088.c
#if defined(USE_IMU_BMI088)
#define REGA_CHIPID        0x00
#define REGA_ERR_REG       0x02
#define REGA_STATUS        0x03
#define REGA_X_LSB         0x12
#define REGA_INT_STATUS_1  0x1D
#define REGA_TEMP_LSB      0x22
#define REGA_TEMP_MSB      0x23
#define REGA_CONF          0x40
#define REGA_RANGE         0x41
#define REGA_PWR_CONF      0x7C
#define REGA_PWR_CTRL      0x7D
#define REGA_SOFTRESET     0x7E
#define REGA_FIFO_CONFIG0  0x48
#define REGA_FIFO_CONFIG1  0x49
#define REGA_FIFO_DOWNS    0x45
#define REGA_FIFO_DATA     0x26
#define REGA_FIFO_LEN0     0x24
#define REGA_FIFO_LEN1     0x25
#define REGG_CHIPID        0x00
#define REGG_RATE_X_LSB    0x02
#define REGG_INT_CTRL      0x15
#define REGG_INT_STATUS_1  0x0A
#define REGG_INT_STATUS_2  0x0B
#define REGG_INT_STATUS_3  0x0C
#define REGG_FIFO_STATUS   0x0E
#define REGG_RANGE         0x0F
#define REGG_BW            0x10
#define REGG_LPM1          0x11
#define REGG_RATE_HBW      0x13
#define REGG_BGW_SOFTRESET 0x14
#define REGG_FIFO_CONFIG_1 0x3E
#define REGG_FIFO_DATA     0x3F
#endif


// ../inav/src/main/drivers/accgyro/accgyro_mpu.h
#define MPU6000_WHO_AM_I_CONST              (0x68)
#define MPU6500_WHO_AM_I_CONST              (0x70)
#define MPU9250_WHO_AM_I_CONST              (0x71)
#define MPU9255_WHO_AM_I_CONST              (0x73)
#define ICM20601_WHO_AM_I_CONST             (0xAC)
#define ICM20602_WHO_AM_I_CONST             (0x12)
#define ICM20608G_WHO_AM_I_CONST            (0xAF)
#define ICM20689_WHO_AM_I_CONST             (0x98)
#define ICM42605_WHO_AM_I_CONST             (0x42)
#define ICM42688P_WHO_AM_I_CONST            (0x47)
#define MPU_RA_XG_OFFS_TC       0x00
#define MPU_RA_YG_OFFS_TC       0x01
#define MPU_RA_ZG_OFFS_TC       0x02
#define MPU_RA_X_FINE_GAIN      0x03
#define MPU_RA_Y_FINE_GAIN      0x04
#define MPU_RA_Z_FINE_GAIN      0x05
#define MPU_RA_XA_OFFS_H        0x06
#define MPU_RA_XA_OFFS_L_TC     0x07
#define MPU_RA_YA_OFFS_H        0x08
#define MPU_RA_YA_OFFS_L_TC     0x09
#define MPU_RA_ZA_OFFS_H        0x0A
#define MPU_RA_ZA_OFFS_L_TC     0x0B
#define MPU_RA_PRODUCT_ID       0x0C
#define MPU_RA_XG_OFFS_USRH     0x13
#define MPU_RA_XG_OFFS_USRL     0x14
#define MPU_RA_YG_OFFS_USRH     0x15
#define MPU_RA_YG_OFFS_USRL     0x16
#define MPU_RA_ZG_OFFS_USRH     0x17
#define MPU_RA_ZG_OFFS_USRL     0x18
#define MPU_RA_SMPLRT_DIV       0x19
#define MPU_RA_CONFIG           0x1A
#define MPU_RA_GYRO_CONFIG      0x1B
#define MPU_RA_ACCEL_CONFIG     0x1C
#define MPU_RA_FF_THR           0x1D
#define MPU_RA_FF_DUR           0x1E
#define MPU_RA_MOT_THR          0x1F
#define MPU_RA_MOT_DUR          0x20
#define MPU_RA_ZRMOT_THR        0x21
#define MPU_RA_ZRMOT_DUR        0x22
#define MPU_RA_FIFO_EN          0x23
#define MPU_RA_I2C_MST_CTRL     0x24
#define MPU_RA_I2C_SLV0_ADDR    0x25
#define MPU_RA_I2C_SLV0_REG     0x26
#define MPU_RA_I2C_SLV0_CTRL    0x27
#define MPU_RA_I2C_SLV1_ADDR    0x28
#define MPU_RA_I2C_SLV1_REG     0x29
#define MPU_RA_I2C_SLV1_CTRL    0x2A
#define MPU_RA_I2C_SLV2_ADDR    0x2B
#define MPU_RA_I2C_SLV2_REG     0x2C
#define MPU_RA_I2C_SLV2_CTRL    0x2D
#define MPU_RA_I2C_SLV3_ADDR    0x2E
#define MPU_RA_I2C_SLV3_REG     0x2F
#define MPU_RA_I2C_SLV3_CTRL    0x30
#define MPU_RA_I2C_SLV4_ADDR    0x31
#define MPU_RA_I2C_SLV4_REG     0x32
#define MPU_RA_I2C_SLV4_DO      0x33
#define MPU_RA_I2C_SLV4_CTRL    0x34
#define MPU_RA_I2C_SLV4_DI      0x35
#define MPU_RA_I2C_MST_STATUS   0x36
#define MPU_RA_INT_PIN_CFG      0x37
#define MPU_RA_INT_ENABLE       0x38
#define MPU_RA_DMP_INT_STATUS   0x39
#define MPU_RA_INT_STATUS       0x3A
#define MPU_RA_ACCEL_XOUT_H     0x3B
#define MPU_RA_ACCEL_XOUT_L     0x3C
#define MPU_RA_ACCEL_YOUT_H     0x3D
#define MPU_RA_ACCEL_YOUT_L     0x3E
#define MPU_RA_ACCEL_ZOUT_H     0x3F
#define MPU_RA_ACCEL_ZOUT_L     0x40
#define MPU_RA_TEMP_OUT_H       0x41
#define MPU_RA_TEMP_OUT_L       0x42
#define MPU_RA_GYRO_XOUT_H      0x43
#define MPU_RA_GYRO_XOUT_L      0x44
#define MPU_RA_GYRO_YOUT_H      0x45
#define MPU_RA_GYRO_YOUT_L      0x46
#define MPU_RA_GYRO_ZOUT_H      0x47
#define MPU_RA_GYRO_ZOUT_L      0x48
#define MPU_RA_EXT_SENS_DATA_00 0x49
#define MPU_RA_MOT_DETECT_STATUS    0x61
#define MPU_RA_I2C_SLV0_DO      0x63
#define MPU_RA_I2C_SLV1_DO      0x64
#define MPU_RA_I2C_SLV2_DO      0x65
#define MPU_RA_I2C_SLV3_DO      0x66
#define MPU_RA_I2C_MST_DELAY_CTRL   0x67
#define MPU_RA_SIGNAL_PATH_RESET    0x68
#define MPU_RA_MOT_DETECT_CTRL      0x69
#define MPU_RA_USER_CTRL        0x6A
#define MPU_RA_PWR_MGMT_1       0x6B
#define MPU_RA_PWR_MGMT_2       0x6C
#define MPU_RA_BANK_SEL         0x6D
#define MPU_RA_MEM_START_ADDR   0x6E
#define MPU_RA_MEM_R_W          0x6F
#define MPU_RA_DMP_CFG_1        0x70
#define MPU_RA_DMP_CFG_2        0x71
#define MPU_RA_FIFO_COUNTH      0x72
#define MPU_RA_FIFO_COUNTL      0x73
#define MPU_RA_FIFO_R_W         0x74
#define MPU_RA_WHO_AM_I         0x75
#define MPU_RF_DATA_RDY_EN (1 << 0)
#define MPU_DLPF_10HZ           0x05
#define MPU_DLPF_20HZ           0x04
#define MPU_DLPF_42HZ           0x03
#define MPU_DLPF_98HZ           0x02
#define MPU_DLPF_188HZ          0x01
#define MPU_DLPF_256HZ          0x00


// ../inav/src/main/drivers/accgyro/accgyro_mpu9250.c
#if defined(USE_IMU_MPU9250)
#define MPU9250_BIT_RESET                   (0x80)
#define MPU9250_BIT_INT_ANYRD_2CLEAR        (1 << 4)
#define MPU9250_BIT_BYPASS_EN               (1 << 0)
#define MPU9250_BIT_I2C_IF_DIS              (1 << 4)
#define MPU9250_BIT_RAW_RDY_EN              (0x01)
#endif


// ../inav/src/main/drivers/accgyro/accgyro_mpu6000.c
#if defined(USE_IMU_MPU6000)
#define BIT_H_RESET                 0x80
#define MPU_CLK_SEL_PLLGYROX        0x01
#define MPU_CLK_SEL_PLLGYROZ        0x03
#define BIT_I2C_IF_DIS              0x10
#define BIT_GYRO                    3
#define BIT_ACC                     2
#define BIT_TEMP                    1
#define MPU6000ES_REV_C4 0x14
#define MPU6000ES_REV_C5 0x15
#define MPU6000ES_REV_D6 0x16
#define MPU6000ES_REV_D7 0x17
#define MPU6000ES_REV_D8 0x18
#define MPU6000_REV_C4 0x54
#define MPU6000_REV_C5 0x55
#define MPU6000_REV_D6 0x56
#define MPU6000_REV_D7 0x57
#define MPU6000_REV_D8 0x58
#define MPU6000_REV_D9 0x59
#define MPU6000_REV_D10 0x5A
#endif


// ../inav/src/main/drivers/accgyro/accgyro_icm42605.c
#if defined(USE_IMU_ICM42605)
#define ICM42605_RA_PWR_MGMT0                       0x4E
#define ICM42605_PWR_MGMT0_ACCEL_MODE_LN            (3 << 0)
#define ICM42605_PWR_MGMT0_GYRO_MODE_LN             (3 << 2)
#define ICM42605_PWR_MGMT0_TEMP_DISABLE_OFF         (0 << 5)
#define ICM42605_PWR_MGMT0_TEMP_DISABLE_ON          (1 << 5)
#define ICM426XX_RA_REG_BANK_SEL                    0x76
#define ICM426XX_BANK_SELECT0                       0x00
#define ICM426XX_BANK_SELECT1                       0x01
#define ICM426XX_BANK_SELECT2                       0x02
#define ICM426XX_BANK_SELECT3                       0x03
#define ICM426XX_BANK_SELECT4                       0x04
#define ICM42605_RA_GYRO_CONFIG0                    0x4F
#define ICM42605_RA_ACCEL_CONFIG0                   0x50
#define ICM42605_RA_GYRO_ACCEL_CONFIG0              0x52
#define ICM42605_ACCEL_UI_FILT_BW_LOW_LATENCY       (15 << 4)
#define ICM42605_GYRO_UI_FILT_BW_LOW_LATENCY        (15 << 0)
#define ICM42605_RA_GYRO_DATA_X1                    0x25
#define ICM42605_RA_ACCEL_DATA_X1                   0x1F
#define ICM42605_RA_TEMP_DATA1                      0x1D
#define ICM42605_RA_INT_CONFIG                      0x14
#define ICM42605_INT1_MODE_PULSED                   (0 << 2)
#define ICM42605_INT1_MODE_LATCHED                  (1 << 2)
#define ICM42605_INT1_DRIVE_CIRCUIT_OD              (0 << 1)
#define ICM42605_INT1_DRIVE_CIRCUIT_PP              (1 << 1)
#define ICM42605_INT1_POLARITY_ACTIVE_LOW           (0 << 0)
#define ICM42605_INT1_POLARITY_ACTIVE_HIGH          (1 << 0)
#define ICM42605_RA_INT_CONFIG0                     0x63
#define ICM42605_UI_DRDY_INT_CLEAR_ON_SBR           ((0 << 5) || (0 << 4))
#define ICM42605_UI_DRDY_INT_CLEAR_ON_SBR_DUPLICATE ((0 << 5) || (0 << 4))
#define ICM42605_UI_DRDY_INT_CLEAR_ON_F1BR          ((1 << 5) || (0 << 4))
#define ICM42605_UI_DRDY_INT_CLEAR_ON_SBR_AND_F1BR  ((1 << 5) || (1 << 4))
#define ICM42605_RA_INT_CONFIG1                     0x64
#define ICM42605_INT_ASYNC_RESET_BIT                4
#define ICM42605_INT_TDEASSERT_DISABLE_BIT          5
#define ICM42605_INT_TDEASSERT_ENABLED              (0 << ICM42605_INT_TDEASSERT_DISABLE_BIT)
#define ICM42605_INT_TDEASSERT_DISABLED             (1 << ICM42605_INT_TDEASSERT_DISABLE_BIT)
#define ICM42605_INT_TPULSE_DURATION_BIT            6
#define ICM42605_INT_TPULSE_DURATION_100            (0 << ICM42605_INT_TPULSE_DURATION_BIT)
#define ICM42605_INT_TPULSE_DURATION_8              (1 << ICM42605_INT_TPULSE_DURATION_BIT)
#define ICM42605_RA_INT_SOURCE0                     0x65
#define ICM42605_UI_DRDY_INT1_EN_DISABLED           (0 << 3)
#define ICM42605_UI_DRDY_INT1_EN_ENABLED            (1 << 3)
#define ICM42605_INTF_CONFIG1                       0x4D
#define ICM42605_INTF_CONFIG1_AFSR_MASK             0xC0
#define ICM42605_INTF_CONFIG1_AFSR_DISABLE          0x40
#define ICM426XX_RA_GYRO_CONFIG_STATIC3             0x0C
#define ICM426XX_RA_GYRO_CONFIG_STATIC4             0x0D
#define ICM426XX_RA_GYRO_CONFIG_STATIC5             0x0E
#define ICM426XX_RA_ACCEL_CONFIG_STATIC2            0x03
#define ICM426XX_RA_ACCEL_CONFIG_STATIC3            0x04
#define ICM426XX_RA_ACCEL_CONFIG_STATIC4            0x05
#endif


// ../inav/src/main/drivers/accgyro/accgyro_icm20689.h
#define ICM20689_BIT_RESET                  (0x80)


// ../inav/src/main/drivers/accgyro/accgyro.h
#define GYRO_LPF_256HZ      0
#define GYRO_LPF_188HZ      1
#define GYRO_LPF_98HZ       2
#define GYRO_LPF_42HZ       3
#define GYRO_LPF_20HZ       4
#define GYRO_LPF_10HZ       5
#define GYRO_LPF_5HZ        6
#define GYRO_LPF_NONE       7


// ../inav/src/main/drivers/accgyro/accgyro_mpu6500.c
#if defined(USE_IMU_MPU6500)
#define MPU6500_BIT_RESET                   (0x80)
#define MPU6500_BIT_INT_ANYRD_2CLEAR        (1 << 4)
#define MPU6500_BIT_BYPASS_EN               (1 << 0)
#define MPU6500_BIT_I2C_IF_DIS              (1 << 4)
#define MPU6500_BIT_RAW_RDY_EN              (0x01)
#endif


// ../inav/src/main/drivers/barometer/barometer_spl06.h
#if !defined(SPL06_I2C_ADDR)
#define SPL06_I2C_ADDR                         0x76
#endif
#define SPL06_DEFAULT_CHIP_ID                  0x10
#define SPL06_PRESSURE_START_REG               0x00
#define SPL06_PRESSURE_LEN                     3
#define SPL06_PRESSURE_B2_REG                  0x00
#define SPL06_PRESSURE_B1_REG                  0x01
#define SPL06_PRESSURE_B0_REG                  0x02
#define SPL06_TEMPERATURE_START_REG            0x03
#define SPL06_TEMPERATURE_LEN                  3
#define SPL06_TEMPERATURE_B2_REG               0x03
#define SPL06_TEMPERATURE_B1_REG               0x04
#define SPL06_TEMPERATURE_B0_REG               0x05
#define SPL06_PRESSURE_CFG_REG                 0x06
#define SPL06_TEMPERATURE_CFG_REG              0x07
#define SPL06_MODE_AND_STATUS_REG              0x08
#define SPL06_INT_AND_FIFO_CFG_REG             0x09
#define SPL06_INT_STATUS_REG                   0x0A
#define SPL06_FIFO_STATUS_REG                  0x0B
#define SPL06_RST_REG                          0x0C
#define SPL06_CHIP_ID_REG                      0x0D
#define SPL06_CALIB_COEFFS_START               0x10
#define SPL06_CALIB_COEFFS_END                 0x21
#define SPL06_CALIB_COEFFS_LEN                 (SPL06_CALIB_COEFFS_END - SPL06_CALIB_COEFFS_START + 1)
#define SPL06_TEMP_USE_EXT_SENSOR              (1<<7)
#define SPL06_MEAS_PRESSURE                    (1<<0)
#define SPL06_MEAS_TEMPERATURE                 (1<<1)
#define SPL06_MEAS_CFG_CONTINUOUS              (1<<2)
#define SPL06_MEAS_CFG_PRESSURE_RDY            (1<<4)
#define SPL06_MEAS_CFG_TEMPERATURE_RDY         (1<<5)
#define SPL06_MEAS_CFG_SENSOR_RDY              (1<<6)
#define SPL06_MEAS_CFG_COEFFS_RDY              (1<<7)
#define SPL06_PRESSURE_RESULT_BIT_SHIFT        (1<<2)
#define SPL06_TEMPERATURE_RESULT_BIT_SHIFT     (1<<3)
#define SPL06_PRESSURE_OVERSAMPLING            8
#define SPL06_TEMPERATURE_OVERSAMPLING         8
#define SPL06_MEASUREMENT_TIME(oversampling)   ((2 + lrintf(oversampling * 1.6)) + 1)


// ../inav/src/main/drivers/barometer/barometer_bmp280.c
#if defined(USE_BARO_BMP280)
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/barometer/barometer_2smpb_02b.c
#if defined(USE_BARO) && defined(USE_BARO_B2SMPB)
#define BARO_2SMBP_I2C_ADDRESS 0x70
#define BARO_2SMBP_CHIP_ID 0x5C
#define REG_CHIP_ID 0xD1
#define REG_RESET 0xE0
#define REG_COE_PR11 0xA0
#define REG_COE_PR21 0xA3
#define REG_COE_PR31 0xA5
#define REG_COE_TEMP11 0xA7
#define REG_COE_TEMP21 0xA9
#define REG_COE_TEMP31 0xAB
#define REG_COE_PTAT11 0xAD
#define REG_COE_PTAT21 0xB1
#define REG_COE_PTAT31 0xB3
#define REG_IIR_CNT 0xF1
#define REG_DEVICE_STAT 0xF3
#define REG_CTRL_MEAS 0xF4
#define REG_IO_SETUP 0xF5
#define REG_PRESS_TXD2 0xF7
#define REG_CLT_MEAS_VAL_TAVG4X_PAVG32X_FORCED ((0x03 << 5) | (0x05 << 2) | 0x01)
#define REG_IIR_CNT_VAL_8X 0x03
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/barometer/barometer_msp.c
#if defined(USE_BARO_MSP)
#define MSP_BARO_TIMEOUT_MS      250
#endif


// ../inav/src/main/drivers/barometer/barometer_spl06.c
#if defined(USE_BARO_SPL06)
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/barometer/barometer_bmp085.c
#if defined(USE_BARO_BMP085)
#if !defined(BMP085_I2C_ADDR)
#define BMP085_I2C_ADDR         0x77
#endif
#define BMP085_CHIP_ID          0x55
#define BOSCH_PRESSURE_BMP085   85
#define BMP085_CHIP_ID_REG      0xD0
#define BMP085_VERSION_REG      0xD1
#define E_SENSOR_NOT_DETECTED   (char) 0
#define BMP085_PROM_START__ADDR 0xaa
#define BMP085_PROM_DATA__LEN   22
#define BMP085_T_MEASURE        0x2E
#define BMP085_P_MEASURE        0x34
#define BMP085_CTRL_MEAS_REG    0xF4
#define BMP085_ADC_OUT_MSB_REG  0xF6
#define BMP085_ADC_OUT_LSB_REG  0xF7
#define BMP085_CHIP_ID__POS     0
#define BMP085_CHIP_ID__MSK     0xFF
#define BMP085_CHIP_ID__LEN     8
#define BMP085_CHIP_ID__REG     BMP085_CHIP_ID_REG
#define BMP085_ML_VERSION__POS      0
#define BMP085_ML_VERSION__LEN      4
#define BMP085_ML_VERSION__MSK      0x0F
#define BMP085_ML_VERSION__REG      BMP085_VERSION_REG
#define BMP085_AL_VERSION__POS      4
#define BMP085_AL_VERSION__LEN      4
#define BMP085_AL_VERSION__MSK      0xF0
#define BMP085_AL_VERSION__REG      BMP085_VERSION_REG
#define BMP085_GET_BITSLICE(regvar, bitname) ((regvar & bitname##__MSK) >> bitname##__POS)
#define BMP085_SET_BITSLICE(regvar, bitname, val) ((regvar & ~bitname##__MSK) | ((val<<bitname##__POS)&bitname##__MSK))
#define SMD500_PARAM_MG      3038
#define SMD500_PARAM_MH     -7357
#define SMD500_PARAM_MI      3791
#define UT_DELAY    6000
#define UP_DELAY    27000
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/barometer/barometer_bmp280.h
#define BMP280_DEFAULT_CHIP_ID               (0x58)
#define BME280_DEFAULT_CHIP_ID               (0x60)
#define BMP280_CHIP_ID_REG                   (0xD0)
#define BMP280_RST_REG                       (0xE0)
#define BMP280_STAT_REG                      (0xF3)
#define BMP280_CTRL_MEAS_REG                 (0xF4)
#define BMP280_CONFIG_REG                    (0xF5)
#define BMP280_PRESSURE_MSB_REG              (0xF7)
#define BMP280_PRESSURE_LSB_REG              (0xF8)
#define BMP280_PRESSURE_XLSB_REG             (0xF9)
#define BMP280_TEMPERATURE_MSB_REG           (0xFA)
#define BMP280_TEMPERATURE_LSB_REG           (0xFB)
#define BMP280_TEMPERATURE_XLSB_REG          (0xFC)
#define BMP280_FORCED_MODE                   (0x01)
#define BMP280_TEMPERATURE_CALIB_DIG_T1_LSB_REG             (0x88)
#define BMP280_PRESSURE_TEMPERATURE_CALIB_DATA_LENGTH       (24)
#define BMP280_DATA_FRAME_SIZE               (6)
#define BMP280_OVERSAMP_SKIPPED          (0x00)
#define BMP280_OVERSAMP_1X               (0x01)
#define BMP280_OVERSAMP_2X               (0x02)
#define BMP280_OVERSAMP_4X               (0x03)
#define BMP280_OVERSAMP_8X               (0x04)
#define BMP280_OVERSAMP_16X              (0x05)
#define BMP280_FILTER_COEFF_OFF               (0x00)
#define BMP280_FILTER_COEFF_2                 (0x01)
#define BMP280_FILTER_COEFF_4                 (0x02)
#define BMP280_FILTER_COEFF_8                 (0x03)
#define BMP280_FILTER_COEFF_16                (0x04)
#define BMP280_PRESSURE_OSR              (BMP280_OVERSAMP_8X)
#define BMP280_TEMPERATURE_OSR           (BMP280_OVERSAMP_1X)
#define BMP280_MODE                      (BMP280_PRESSURE_OSR << 2 | BMP280_TEMPERATURE_OSR << 5 | BMP280_FORCED_MODE)
#define BMP280_FILTER                    (BMP280_FILTER_COEFF_8 << 2)
#define T_INIT_MAX                       (20)
#define T_MEASURE_PER_OSRS_MAX           (37)
#define T_SETUP_PRESSURE_MAX             (10)


// ../inav/src/main/drivers/barometer/barometer_bmp388.c
#if defined(USE_BARO) && (defined(USE_BARO_BMP388) || defined(USE_BARO_SPI_BMP388) || defined(USE_BARO_BMP390) || defined(USE_BARO_SPI_BMP390))
#if !defined(BMP388_I2C_ADDR)
#define BMP388_I2C_ADDR                                 (0x76)
#endif
#define BMP388_DEFAULT_CHIP_ID                          (0x50)
#define BMP390_DEFAULT_CHIP_ID                          (0x60)
#define BMP388_CMD_REG                                  (0x7E)
#define BMP388_RESERVED_UPPER_REG                       (0x7D)
#define BMP388_RESERVED_LOWER_REG                       (0x20)
#define BMP388_CONFIG_REG                               (0x1F)
#define BMP388_RESERVED_0x1E_REG                        (0x1E)
#define BMP388_ODR_REG                                  (0x1D)
#define BMP388_OSR_REG                                  (0x1C)
#define BMP388_PWR_CTRL_REG                             (0x1B)
#define BMP388_IF_CONFIG_REG                            (0x1A)
#define BMP388_INT_CTRL_REG                             (0x19)
#define BMP388_FIFO_CONFIG_2_REG                        (0x18)
#define BMP388_FIFO_CONFIG_1_REG                        (0x17)
#define BMP388_FIFO_WTM_1_REG                           (0x16)
#define BMP388_FIFO_WTM_0_REG                           (0x15)
#define BMP388_FIFO_DATA_REG                            (0x14)
#define BMP388_FIFO_LENGTH_1_REG                        (0x13)
#define BMP388_FIFO_LENGTH_0_REG                        (0x12)
#define BMP388_INT_STATUS_REG                           (0x11)
#define BMP388_EVENT_REG                                (0x10)
#define BMP388_SENSORTIME_3_REG                         (0x0F)
#define BMP388_SENSORTIME_2_REG                         (0x0E)
#define BMP388_SENSORTIME_1_REG                         (0x0D)
#define BMP388_SENSORTIME_0_REG                         (0x0C)
#define BMP388_RESERVED_0x0B_REG                        (0x0B)
#define BMP388_RESERVED_0x0A_REG                        (0x0A)
#define BMP388_DATA_5_REG                               (0x09)
#define BMP388_DATA_4_REG                               (0x08)
#define BMP388_DATA_3_REG                               (0x07)
#define BMP388_DATA_2_REG                               (0x06)
#define BMP388_DATA_1_REG                               (0x05)
#define BMP388_DATA_0_REG                               (0x04)
#define BMP388_STATUS_REG                               (0x03)
#define BMP388_ERR_REG                                  (0x02)
#define BMP388_RESERVED_0x01_REG                        (0x01)
#define BMP388_CHIP_ID_REG                              (0x00)
#define BMP388_PRESS_MSB_23_16_REG                      BMP388_DATA_2_REG
#define BMP388_PRESS_LSB_15_8_REG                       BMP388_DATA_1_REG
#define BMP388_PRESS_XLSB_7_0_REG                       BMP388_DATA_0_REG
#define BMP388_TEMP_MSB_23_16_REG                       BMP388_DATA_5_REG
#define BMP388_TEMP_LSB_15_8_REG                        BMP388_DATA_4_REG
#define BMP388_TEMP_XLSB_7_0_REG                        BMP388_DATA_3_REG
#define BMP388_DATA_FRAME_SIZE                          ((BMP388_DATA_5_REG - BMP388_DATA_0_REG) + 1)
#define BMP388_MODE_SLEEP                               (0x00)
#define BMP388_MODE_FORCED                              (0x01)
#define BMP388_MODE_NORMAL                              (0x02)
#define BMP388_CALIRATION_LOWER_REG                     (0x30)
#define BMP388_TRIMMING_NVM_PAR_T1_LSB_REG              (0x31)
#define BMP388_TRIMMING_NVM_PAR_P11_REG                 (0x45)
#define BMP388_CALIRATION_UPPER_REG                     (0x57)
#define BMP388_TRIMMING_DATA_LENGTH                     ((BMP388_TRIMMING_NVM_PAR_P11_REG - BMP388_TRIMMING_NVM_PAR_T1_LSB_REG) + 1)
#define BMP388_OVERSAMP_1X               (0x00)
#define BMP388_OVERSAMP_2X               (0x01)
#define BMP388_OVERSAMP_4X               (0x02)
#define BMP388_OVERSAMP_8X               (0x03)
#define BMP388_OVERSAMP_16X              (0x04)
#define BMP388_OVERSAMP_32X              (0x05)
#define BMP388_INT_OD_BIT                   0
#define BMP388_INT_LEVEL_BIT                1
#define BMP388_INT_LATCH_BIT                2
#define BMP388_INT_FWTM_EN_BIT              3
#define BMP388_INT_FFULL_EN_BIT             4
#define BMP388_INT_RESERVED_5_BIT           5
#define BMP388_INT_DRDY_EN_BIT              6
#define BMP388_INT_RESERVED_7_BIT           7
#define BMP388_OSR_P_BIT                    0
#define BMP388_OSR4_T_BIT                   3
#define BMP388_OSR_P_MASK                   (0x03)
#define BMP388_OSR4_T_MASK                  (0x38)
#define BMP388_PRESSURE_OSR              (BMP388_OVERSAMP_8X)
#define BMP388_TEMPERATURE_OSR           (BMP388_OVERSAMP_1X)
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/barometer/barometer_dps310.c
#if defined(USE_BARO) && defined(USE_BARO_DPS310)
#define DPS310_REG_PSR_B2           0x00
#define DPS310_REG_PSR_B1           0x01
#define DPS310_REG_PSR_B0           0x02
#define DPS310_REG_TMP_B2           0x03
#define DPS310_REG_TMP_B1           0x04
#define DPS310_REG_TMP_B0           0x05
#define DPS310_REG_PRS_CFG          0x06
#define DPS310_REG_TMP_CFG          0x07
#define DPS310_REG_MEAS_CFG         0x08
#define DPS310_REG_CFG_REG          0x09
#define DPS310_REG_RESET            0x0C
#define DPS310_REG_ID               0x0D
#define DPS310_REG_COEF             0x10
#define DPS310_REG_COEF_SRCE        0x28
#define DPS310_ID_REV_AND_PROD_ID       (0x10)
#define SPL07_003_CHIP_ID               (0x11)
#define DPS310_RESET_BIT_SOFT_RST       (0x09)
#define DPS310_MEAS_CFG_COEF_RDY        (1 << 7)
#define DPS310_MEAS_CFG_SENSOR_RDY      (1 << 6)
#define DPS310_MEAS_CFG_TMP_RDY         (1 << 5)
#define DPS310_MEAS_CFG_PRS_RDY         (1 << 4)
#define DPS310_MEAS_CFG_MEAS_CTRL_MASK  (0x7)
#define DPS310_MEAS_CFG_MEAS_CTRL_CONT  (0x7)
#define DPS310_MEAS_CFG_MEAS_TEMP_SING  (0x2)
#define DPS310_MEAS_CFG_MEAS_IDLE       (0x0)
#define DPS310_PRS_CFG_BIT_PM_RATE_32HZ (0x50)
#define DPS310_PRS_CFG_BIT_PM_PRC_16    (0x04)
#define DPS310_TMP_CFG_BIT_TMP_EXT          (0x80)
#define DPS310_TMP_CFG_BIT_TMP_RATE_32HZ    (0x50)
#define DPS310_TMP_CFG_BIT_TMP_PRC_16       (0x04)
#define DPS310_CFG_REG_BIT_P_SHIFT          (0x04)
#define DPS310_CFG_REG_BIT_T_SHIFT          (0x08)
#define DPS310_COEF_SRCE_BIT_TMP_COEF_SRCE  (0x80)
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/barometer/barometer_lps25h.c
#if defined(USE_BARO_LPS25H)
#define LPS25HB_WHO_AM_I_ADDR               0x0F
#define LPS25HB_RES_CONF_ADDR               0x10
#define LPS25HB_CTRL_REG1_ADDR              0x20
#define LPS25HB_CTRL_REG2_ADDR              0x21
#define LPS25HB_STATUS_REG_ADDR             0x27
#define LPS25HB_PRESS_POUT_XL_ADDR          0x28
#define LPS25HB_PRESS_OUT_L_ADDR            0x29
#define LPS25HB_PRESS_OUT_H_ADDR            0x2A
#define LPS25HB_TEMP_OUT_L_ADDR             0x2B
#define LPS25HB_TEMP_OUT_H_ADDR             0x2C
#define LPS25HB_I2C_MULTIPLEBYTE_CMD        0x80
#define LPS25HB_SPI_MULTIPLEBYTE_CMD        0x40
#define TEMPERATURE_READY_MASK              (1 << 0)
#define PRESSURE_READY_MASK                 (1 << 1)
#define I_AM_LPS25HB                        0xBD
#define LPS25HB_MODE_MASK                   0x80
#define LPS25HB_MODE_POWERDOWN              0x00
#define LPS25HB_MODE_ACTIVE                 0x80
#define LPS25HB_ODR_MASK                    0x70
#define LPS25HB_ODR_ONE_SHOT                0x00
#define LPS25HB_ODR_1Hz                     0x10
#define LPS25HB_ODR_7Hz                     0x20
#define LPS25HB_ODR_12_5Hz                  0x30
#define LPS25HB_ODR_25Hz                    0x40
#define LPS25HB_DIFF_EN_MASK                0x08
#define LPS25HB_DIFF_DISABLE                0x00
#define LPS25HB_DIFF_ENABLE                 0x08
#define LPS25HB_BDU_MASK                    0x04
#define LPS25HB_BDU_CONT                    0x00
#define LPS25HB_BDU_READ                    0x04
#define LPS25HB_RESET_MEMORY_MASK           0x80
#define LPS25HB_NORMAL_MODE                 0x00
#define LPS25HB_RESET_MEMORY                0x80
#define LPS25HB_P_RES_MASK                  0x03
#define LPS25HB_P_RES_AVG_8                 0x00
#define LPS25HB_P_RES_AVG_32                0x01
#define LPS25HB_P_RES_AVG_128               0x02
#define LPS25HB_P_RES_AVG_512               0x03
#define LPS25HB_T_RES_MASK                  0x0C
#define LPS25HB_T_RES_AVG_8                 0x00
#define LPS25HB_T_RES_AVG_16                0x04
#define LPS25HB_T_RES_AVG_32                0x08
#define LPS25HB_T_RES_AVG_64                0x0C
#define LPS25H_CHIP_ID                      0xBD
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/barometer/barometer_ms56xx.c
#if defined(USE_BARO_MS5607) || defined(USE_BARO_MS5611)
#define MS56XX_ADDR             0x77
#define CMD_RESET               0x1E
#define CMD_ADC_READ            0x00
#define CMD_ADC_CONV            0x40
#define CMD_ADC_D1              0x00
#define CMD_ADC_D2              0x10
#define CMD_ADC_256             0x00
#define CMD_ADC_512             0x02
#define CMD_ADC_1024            0x04
#define CMD_ADC_2048            0x06
#define CMD_ADC_4096            0x08
#define CMD_PROM_RD             0xA0
#define PROM_NB                 8
#define DETECTION_MAX_RETRY_COUNT   5
#endif


// ../inav/src/main/drivers/temperature/ds18b20.c
#define DS18B20_FAMILY_CODE 0x28
#define DS18B20_ALARM_SEARCH_CMD 0xEC
#define DS18B20_START_CONVERSION_CMD 0x44
#define DS18B20_WRITE_SCRATCHPAD_CMD 0x4E
#define DS18B20_READ_SCRATCHPAD_CMD 0xBE
#define DS18B20_COPY_SCRATCHPAD_CMD 0x48
#define DS18B20_RECALL_EEPROM_CMD 0xB8
#define DS18B20_READ_POWER_SUPPLY_CMD 0xB4


// ../inav/src/main/drivers/temperature/ds18b20.h
#if defined(USE_1WIRE) && defined(USE_TEMPERATURE_DS18B20)
#define USE_TEMPERATURE_SENSOR
#define DS18B20_DRIVER_AVAILABLE
#define DS18B20_CONFIG_9BIT 0x1F
#define DS18B20_CONFIG_10BIT 0x3F
#define DS18B20_CONFIG_11BIT 0x5F
#define DS18B20_CONFIG_12BIT 0x7F
#define DS18B20_9BIT_CONVERSION_TIME 94
#define DS18B20_10BIT_CONVERSION_TIME 188
#define DS18B20_11BIT_CONVERSION_TIME 375
#define DS18B20_12BIT_CONVERSION_TIME 750
#endif


// ../inav/src/main/drivers/temperature/lm75.h
#ifdef USE_TEMPERATURE_LM75
#define USE_TEMPERATURE_SENSOR
#endif


// ../inav/src/main/drivers/temperature/lm75.c
#define LM75_TEMPERATURE_REG_ADDR 0x0
#ifdef USE_TEMPERATURE_LM75
#define DETECTION_MAX_RETRY_COUNT 5
#endif


// ../inav/src/main/drivers/rangefinder/rangefinder_tof10120_i2c.h
#define RANGEFINDER_TOF10120_I2C_TASK_PERIOD_MS 100


// ../inav/src/main/drivers/rangefinder/rangefinder.h
#define RANGEFINDER_OUT_OF_RANGE        (-1)
#define RANGEFINDER_HARDWARE_FAILURE    (-2)
#define RANGEFINDER_NO_NEW_DATA         (-3)


// ../inav/src/main/drivers/rangefinder/rangefinder_vl53l0x.c
#if defined(USE_RANGEFINDER) && defined(USE_RANGEFINDER_VL53L0X)
#define VL53L0X_MAX_RANGE_CM                250
#define VL53L0X_DETECTION_CONE_DECIDEGREES  900
#define VL53L0X_I2C_ADDRESS     0x29
#define VL53L0X_REG_SYSRANGE_START                          0x00
#define VL53L0X_REG_SYSTEM_THRESH_HIGH                      0x0C
#define VL53L0X_REG_SYSTEM_THRESH_LOW                       0x0E
#define VL53L0X_REG_SYSTEM_SEQUENCE_CONFIG                  0x01
#define VL53L0X_REG_SYSTEM_RANGE_CONFIG                     0x09
#define VL53L0X_REG_SYSTEM_INTERMEASUREMENT_PERIOD          0x04
#define VL53L0X_REG_SYSTEM_INTERRUPT_CONFIG_GPIO            0x0A
#define VL53L0X_REG_GPIO_HV_MUX_ACTIVE_HIGH                 0x84
#define VL53L0X_REG_SYSTEM_INTERRUPT_CLEAR                  0x0B
#define VL53L0X_REG_RESULT_INTERRUPT_STATUS                 0x13
#define VL53L0X_REG_RESULT_RANGE_STATUS                     0x14
#define VL53L0X_REG_RESULT_CORE_PAGE  1
#define VL53L0X_REG_RESULT_CORE_AMBIENT_WINDOW_EVENTS_RTN   0xBC
#define VL53L0X_REG_RESULT_CORE_RANGING_TOTAL_EVENTS_RTN    0xC0
#define VL53L0X_REG_RESULT_CORE_AMBIENT_WINDOW_EVENTS_REF   0xD0
#define VL53L0X_REG_RESULT_CORE_RANGING_TOTAL_EVENTS_REF    0xD4
#define VL53L0X_REG_RESULT_PEAK_SIGNAL_RATE_REF             0xB6
#define VL53L0X_REG_ALGO_PART_TO_PART_RANGE_OFFSET_MM       0x28
#define VL53L0X_REG_I2C_SLAVE_DEVICE_ADDRESS                0x8a
#define VL53L0X_REG_MSRC_CONFIG_CONTROL                     0x60
#define VL53L0X_REG_PRE_RANGE_CONFIG_MIN_SNR                0x27
#define VL53L0X_REG_PRE_RANGE_CONFIG_VALID_PHASE_LOW        0x56
#define VL53L0X_REG_PRE_RANGE_CONFIG_VALID_PHASE_HIGH       0x57
#define VL53L0X_REG_PRE_RANGE_MIN_COUNT_RATE_RTN_LIMIT      0x64
#define VL53L0X_REG_FINAL_RANGE_CONFIG_MIN_SNR              0x67
#define VL53L0X_REG_FINAL_RANGE_CONFIG_VALID_PHASE_LOW      0x47
#define VL53L0X_REG_FINAL_RANGE_CONFIG_VALID_PHASE_HIGH     0x48
#define VL53L0X_REG_FINAL_RANGE_CONFIG_MIN_COUNT_RATE_RTN_LIMIT   0x44
#define VL53L0X_REG_PRE_RANGE_CONFIG_SIGMA_THRESH_HI        0x61
#define VL53L0X_REG_PRE_RANGE_CONFIG_SIGMA_THRESH_LO        0x62
#define VL53L0X_REG_PRE_RANGE_CONFIG_VCSEL_PERIOD           0x50
#define VL53L0X_REG_PRE_RANGE_CONFIG_TIMEOUT_MACROP_HI      0x51
#define VL53L0X_REG_PRE_RANGE_CONFIG_TIMEOUT_MACROP_LO      0x52
#define VL53L0X_REG_SYSTEM_HISTOGRAM_BIN                    0x81
#define VL53L0X_REG_HISTOGRAM_CONFIG_INITIAL_PHASE_SELECT   0x33
#define VL53L0X_REG_HISTOGRAM_CONFIG_READOUT_CTRL           0x55
#define VL53L0X_REG_FINAL_RANGE_CONFIG_VCSEL_PERIOD         0x70
#define VL53L0X_REG_FINAL_RANGE_CONFIG_TIMEOUT_MACROP_HI    0x71
#define VL53L0X_REG_FINAL_RANGE_CONFIG_TIMEOUT_MACROP_LO    0x72
#define VL53L0X_REG_CROSSTALK_COMPENSATION_PEAK_RATE_MCPS   0x20
#define VL53L0X_REG_MSRC_CONFIG_TIMEOUT_MACROP              0x46
#define VL53L0X_REG_SOFT_RESET_GO2_SOFT_RESET_N             0xbf
#define VL53L0X_REG_IDENTIFICATION_MODEL_ID                 0xc0
#define VL53L0X_REG_IDENTIFICATION_REVISION_ID              0xc2
#define VL53L0X_REG_OSC_CALIBRATE_VAL                       0xf8
#define VL53L0X_REG_GLOBAL_CONFIG_VCSEL_WIDTH               0x32
#define VL53L0X_REG_GLOBAL_CONFIG_SPAD_ENABLES_REF_0        0xB0
#define VL53L0X_REG_GLOBAL_CONFIG_SPAD_ENABLES_REF_1        0xB1
#define VL53L0X_REG_GLOBAL_CONFIG_SPAD_ENABLES_REF_2        0xB2
#define VL53L0X_REG_GLOBAL_CONFIG_SPAD_ENABLES_REF_3        0xB3
#define VL53L0X_REG_GLOBAL_CONFIG_SPAD_ENABLES_REF_4        0xB4
#define VL53L0X_REG_GLOBAL_CONFIG_SPAD_ENABLES_REF_5        0xB5
#define VL53L0X_REG_GLOBAL_CONFIG_REF_EN_START_SELECT       0xB6
#define VL53L0X_REG_DYNAMIC_SPAD_NUM_REQUESTED_REF_SPAD     0x4E
#define VL53L0X_REG_DYNAMIC_SPAD_REF_EN_START_OFFSET        0x4F
#define VL53L0X_REG_POWER_MANAGEMENT_GO1_POWER_FORCE        0x80
#define VL53L0X_REG_VHV_CONFIG_PAD_SCL_SDA__EXTSUP_HV       0x89
#define VL53L0X_REG_ALGO_PHASECAL_LIM                       0x30
#define VL53L0X_REG_ALGO_PHASECAL_CONFIG_TIMEOUT            0x30
#define setTimeout(timeout)                 {timeoutValueMs = timeout;}
#define getTimeout()                        (timeoutValueMs)
#define startTimeout()                      (timeoutStartMs = millis())
#define checkTimeoutExpired()               (timeoutValueMs > 0 && ((uint16_t)millis() - timeoutStartMs) > timeoutValueMs)
#define decodeVcselPeriod(reg_val)          (((reg_val) + 1) << 1)
#define encodeVcselPeriod(period_pclks)     (((period_pclks) >> 1) - 1)
#define calcMacroPeriod(vcsel_period_pclks) ((((uint32_t)2304 * (vcsel_period_pclks) * 1655) + 500) / 1000)
#endif


// ../inav/src/main/drivers/rangefinder/rangefinder_virtual.h
#define RANGEFINDER_VIRTUAL_MAX_RANGE_CM                250
#define RANGEFINDER_VIRTUAL_DETECTION_CONE_DECIDEGREES  900
#define RANGEFINDER_VIRTUAL_TASK_PERIOD_MS  30


// ../inav/src/main/drivers/rangefinder/rangefinder_vl53l0x.h
#define RANGEFINDER_VL53L0X_TASK_PERIOD_MS  33


// ../inav/src/main/drivers/rangefinder/rangefinder_vl53l1x.c
#if defined(USE_RANGEFINDER) && defined(USE_RANGEFINDER_VL53L1X)
#define VL53L1X_MAX_RANGE_CM                                (300)
#define VL53L1X_DETECTION_CONE_DECIDEGREES                  (270)
#define VL53L1X_TIMING_BUDGET                               (33)
#define VL53L1X_IMPLEMENTATION_VER_MAJOR       3
#define VL53L1X_IMPLEMENTATION_VER_MINOR       4
#define VL53L1X_IMPLEMENTATION_VER_SUB         0
#define VL53L1X_IMPLEMENTATION_VER_REVISION  0000
#define SOFT_RESET                                          0x0000
#define VL53L1_I2C_SLAVE__DEVICE_ADDRESS                    0x0001
#define VL53L1_VHV_CONFIG__TIMEOUT_MACROP_LOOP_BOUND        0x0008
#define ALGO__CROSSTALK_COMPENSATION_PLANE_OFFSET_KCPS      0x0016
#define ALGO__CROSSTALK_COMPENSATION_X_PLANE_GRADIENT_KCPS  0x0018
#define ALGO__CROSSTALK_COMPENSATION_Y_PLANE_GRADIENT_KCPS  0x001A
#define ALGO__PART_TO_PART_RANGE_OFFSET_MM                  0x001E
#define MM_CONFIG__INNER_OFFSET_MM                          0x0020
#define MM_CONFIG__OUTER_OFFSET_MM                          0x0022
#define GPIO_HV_MUX__CTRL                                   0x0030
#define GPIO__TIO_HV_STATUS                                 0x0031
#define SYSTEM__INTERRUPT_CONFIG_GPIO                       0x0046
#define PHASECAL_CONFIG__TIMEOUT_MACROP                     0x004B
#define RANGE_CONFIG__TIMEOUT_MACROP_A_HI                   0x005E
#define RANGE_CONFIG__VCSEL_PERIOD_A                        0x0060
#define RANGE_CONFIG__VCSEL_PERIOD_B                        0x0063
#define RANGE_CONFIG__TIMEOUT_MACROP_B_HI                   0x0061
#define RANGE_CONFIG__TIMEOUT_MACROP_B_LO                   0x0062
#define RANGE_CONFIG__SIGMA_THRESH                          0x0064
#define RANGE_CONFIG__MIN_COUNT_RATE_RTN_LIMIT_MCPS         0x0066
#define RANGE_CONFIG__VALID_PHASE_HIGH                      0x0069
#define VL53L1_SYSTEM__INTERMEASUREMENT_PERIOD              0x006C
#define SYSTEM__THRESH_HIGH                                 0x0072
#define SYSTEM__THRESH_LOW                                  0x0074
#define SD_CONFIG__WOI_SD0                                  0x0078
#define SD_CONFIG__INITIAL_PHASE_SD0                        0x007A
#define ROI_CONFIG__USER_ROI_CENTRE_SPAD                    0x007F
#define ROI_CONFIG__USER_ROI_REQUESTED_GLOBAL_XY_SIZE       0x0080
#define SYSTEM__SEQUENCE_CONFIG                             0x0081
#define VL53L1_SYSTEM__GROUPED_PARAMETER_HOLD               0x0082
#define SYSTEM__INTERRUPT_CLEAR                             0x0086
#define SYSTEM__MODE_START                                  0x0087
#define VL53L1_RESULT__RANGE_STATUS                         0x0089
#define VL53L1_RESULT__DSS_ACTUAL_EFFECTIVE_SPADS_SD0       0x008C
#define RESULT__AMBIENT_COUNT_RATE_MCPS_SD                  0x0090
#define VL53L1_RESULT__FINAL_CROSSTALK_CORRECTED_RANGE_MM_SD0               0x0096
#define VL53L1_RESULT__PEAK_SIGNAL_COUNT_RATE_CROSSTALK_CORRECTED_MCPS_SD0  0x0098
#define VL53L1_RESULT__OSC_CALIBRATE_VAL                    0x00DE
#define VL53L1_FIRMWARE__SYSTEM_STATUS                      0x00E5
#define VL53L1_IDENTIFICATION__MODEL_ID                     0x010F
#define VL53L1_ROI_CONFIG__MODE_ROI_CENTRE_SPAD             0x013E
#define ALGO__PART_TO_PART_RANGE_OFFSET_MM  0x001E
#define MM_CONFIG__INNER_OFFSET_MM          0x0020
#define MM_CONFIG__OUTER_OFFSET_MM          0x0022
#define VL53L1_ERROR_NONE                              ((VL53L1X_ERROR)  0)
#define VL53L1_ERROR_CALIBRATION_WARNING               ((VL53L1X_ERROR) - 1)
#define VL53L1_ERROR_MIN_CLIPPED                       ((VL53L1X_ERROR) - 2)
#define VL53L1_ERROR_UNDEFINED                         ((VL53L1X_ERROR) - 3)
#define VL53L1_ERROR_INVALID_PARAMS                    ((VL53L1X_ERROR) - 4)
#define VL53L1_ERROR_NOT_SUPPORTED                     ((VL53L1X_ERROR) - 5)
#define VL53L1_ERROR_RANGE_ERROR                       ((VL53L1X_ERROR) - 6)
#define VL53L1_ERROR_TIME_OUT                          ((VL53L1X_ERROR) - 7)
#define VL53L1_ERROR_MODE_NOT_SUPPORTED                ((VL53L1X_ERROR) - 8)
#define VL53L1_ERROR_BUFFER_TOO_SMALL                  ((VL53L1X_ERROR) - 9)
#define VL53L1_ERROR_COMMS_BUFFER_TOO_SMALL            ((VL53L1X_ERROR) - 10)
#define VL53L1_ERROR_GPIO_NOT_EXISTING                 ((VL53L1X_ERROR) - 11)
#define VL53L1_ERROR_GPIO_FUNCTIONALITY_NOT_SUPPORTED  ((VL53L1X_ERROR) - 12)
#define VL53L1_ERROR_CONTROL_INTERFACE                 ((VL53L1X_ERROR) - 13)
#define VL53L1_ERROR_INVALID_COMMAND                   ((VL53L1X_ERROR) - 14)
#define VL53L1_ERROR_DIVISION_BY_ZERO                  ((VL53L1X_ERROR) - 15)
#define VL53L1_ERROR_REF_SPAD_INIT                     ((VL53L1X_ERROR) - 16)
#define VL53L1_ERROR_GPH_SYNC_CHECK_FAIL               ((VL53L1X_ERROR) - 17)
#define VL53L1_ERROR_STREAM_COUNT_CHECK_FAIL           ((VL53L1X_ERROR) - 18)
#define VL53L1_ERROR_GPH_ID_CHECK_FAIL                 ((VL53L1X_ERROR) - 19)
#define VL53L1_ERROR_ZONE_STREAM_COUNT_CHECK_FAIL      ((VL53L1X_ERROR) - 20)
#define VL53L1_ERROR_ZONE_GPH_ID_CHECK_FAIL            ((VL53L1X_ERROR) - 21)
#define VL53L1_ERROR_XTALK_EXTRACTION_NO_SAMPLE_FAIL   ((VL53L1X_ERROR) - 22)
#define VL53L1_ERROR_XTALK_EXTRACTION_SIGMA_LIMIT_FAIL ((VL53L1X_ERROR) - 23)
#define VL53L1_ERROR_OFFSET_CAL_NO_SAMPLE_FAIL           ((VL53L1X_ERROR) - 24)
#define VL53L1_ERROR_OFFSET_CAL_NO_SPADS_ENABLED_FAIL    ((VL53L1X_ERROR) - 25)
#define VL53L1_ERROR_ZONE_CAL_NO_SAMPLE_FAIL             ((VL53L1X_ERROR) - 26)
#define VL53L1_ERROR_TUNING_PARM_KEY_MISMATCH             ((VL53L1X_ERROR) - 27)
#define VL53L1_WARNING_REF_SPAD_CHAR_NOT_ENOUGH_SPADS   ((VL53L1X_ERROR) - 28)
#define VL53L1_WARNING_REF_SPAD_CHAR_RATE_TOO_HIGH      ((VL53L1X_ERROR) - 29)
#define VL53L1_WARNING_REF_SPAD_CHAR_RATE_TOO_LOW       ((VL53L1X_ERROR) - 30)
#define VL53L1_WARNING_OFFSET_CAL_MISSING_SAMPLES       ((VL53L1X_ERROR) - 31)
#define VL53L1_WARNING_OFFSET_CAL_SIGMA_TOO_HIGH        ((VL53L1X_ERROR) - 32)
#define VL53L1_WARNING_OFFSET_CAL_RATE_TOO_HIGH         ((VL53L1X_ERROR) - 33)
#define VL53L1_WARNING_OFFSET_CAL_SPAD_COUNT_TOO_LOW    ((VL53L1X_ERROR) - 34)
#define VL53L1_WARNING_ZONE_CAL_MISSING_SAMPLES       ((VL53L1X_ERROR) - 35)
#define VL53L1_WARNING_ZONE_CAL_SIGMA_TOO_HIGH        ((VL53L1X_ERROR) - 36)
#define VL53L1_WARNING_ZONE_CAL_RATE_TOO_HIGH         ((VL53L1X_ERROR) - 37)
#define VL53L1_WARNING_XTALK_MISSING_SAMPLES             ((VL53L1X_ERROR) - 38)
#define VL53L1_WARNING_XTALK_NO_SAMPLES_FOR_GRADIENT     ((VL53L1X_ERROR) - 39)
#define VL53L1_WARNING_XTALK_SIGMA_LIMIT_FOR_GRADIENT    ((VL53L1X_ERROR) - 40)
#define VL53L1_ERROR_NOT_IMPLEMENTED                   ((VL53L1X_ERROR) - 41)
#define VL53L1_ERROR_PLATFORM_SPECIFIC_START           ((VL53L1X_ERROR) - 60)
#define _I2CWrite(dev, data, size) \
    (busWriteBuf(dev, 0xFF, data, size) ? 0 : -1)
#define _I2CRead(dev, data, size) \
    (busReadBuf(dev, 0xFF, data, size) ? 0 : -1)
#endif


// ../inav/src/main/drivers/rangefinder/rangefinder_us42.h
#define RANGEFINDER_US42_TASK_PERIOD_MS 100


// ../inav/src/main/drivers/rangefinder/rangefinder_vl53l1x.h
#define RANGEFINDER_VL53L1X_TASK_PERIOD_MS  (40)


// ../inav/src/main/drivers/rangefinder/rangefinder_srf10.h
#define RANGEFINDER_SRF10_TASK_PERIOD_MS 70


// ../inav/src/main/drivers/rangefinder/rangefinder_teraranger_evo.h
#define RANGEFINDER_TERA_EVO_TASK_PERIOD_MS 70
#define RANGEFINDER_TERA_EVO_MAX_RANGE_CM 600


// ../inav/src/main/drivers/rangefinder/rangefinder_srf10.c
#if defined(USE_RANGEFINDER) && defined(USE_RANGEFINDER_SRF10)
#define SRF10_MAX_RANGE_CM 600
#define SRF10_DETECTION_CONE_DECIDEGREES 500
#define SRF10_DETECTION_CONE_EXTENDED_DECIDEGREES 500
#define SRF10_MinimumFiringIntervalFor1100cmRangeMs 65
#define SRF10_MinimumFiringIntervalFor600cmRangeMs 40
#define SRF10_Address 0xE0
#define SRF10_AddressI2C (SRF10_Address>>1)
#define SRF10_READ_SoftwareRevision 0x00
#define SRF10_READ_Unused 0x01
#define SRF10_READ_Unused_ReturnValue 0x80
#define SRF10_READ_RangeHighByte 0x02
#define SRF10_READ_RangeLowByte 0x03
#define SRF10_WRITE_CommandRegister 0x00
#define SRF10_WRITE_MaxGainRegister 0x01
#define SRF10_WRITE_RangeRegister 0x02
#define SRF10_COMMAND_InitiateRangingInches 0x50
#define SRF10_COMMAND_InitiateRangingCm 0x51
#define SRF10_COMMAND_InitiateRangingMicroSeconds 0x53
#define SRF10_COMMAND_SetGain_40 0x00
#define SRF10_COMMAND_SetGain_100 0x06
#define SRF10_COMMAND_SetGain_200 0x09
#define SRF10_COMMAND_SetGain_300 0x0B
#define SRF10_COMMAND_SetGain_400 0x0D
#define SRF10_COMMAND_SetGain_500 0x0E
#define SRF10_COMMAND_SetGain_600 0x0F
#define SRF10_COMMAND_SetGain_700 0x10
#define SRF10_COMMAND_SetGain_Max 0x10
#define SRF10_COMMAND_ChangeAddress1 0xA0
#define SRF10_COMMAND_ChangeAddress2 0xAA
#define SRF10_COMMAND_ChangeAddress3 0xA5
#define SRF10_RangeValue43mm 0
#define SRF10_RangeValue86mm 1
#define SRF10_RangeValue1m 24
#define SRF10_RangeValue4m 93
#define SRF10_RangeValue6m 139
#define SRF10_RangeValue11m 0xFF
#endif


// ../inav/src/main/drivers/rangefinder/rangefinder_us42.c
#if defined(USE_RANGEFINDER) && defined(USE_RANGEFINDER_US42)
#define US42_MAX_RANGE_CM 400
#define US42_DETECTION_CONE_DECIDEGREES 250
#define US42_DETECTION_CONE_EXTENDED_DECIDEGREES 300
#define US42_MIN_PROBE_INTERVAL 50
#define US42_I2C_ADDRESS 0x70
#define US42_I2C_REGISTRY_BASE 0x00
#define US42_I2C_REGISTRY_PROBE 0x51
#define US42_I2C_REGISTRY_STATUS_OK 0x00
#define US42_I2C_REGISTRY_DISTANCE_HIGH 0x00
#define US42_I2C_REGISTRY_DISTANCE_LOW 0x01
#endif


// ../inav/src/main/drivers/rangefinder/rangefinder_tof10120_i2c.c
#if defined(USE_RANGEFINDER) && defined(USE_RANGEFINDER_TOF10120_I2C)
#define TOF10120_I2C_MAX_RANGE_CM 200
#define TOF10120_I2C_MAX_RANGE_MM TOF10120_I2C_MAX_RANGE_CM * 10
#define TOF10120_I2C_DETECTION_CONE_DECIDEGREES 300
#define TOF10120_I2C_DETECTION_CONE_EXTENDED_DECIDEGREES 450
#define TOF10120_I2C_ADDRESS 0x52
#define TOF10120_I2C_REGISTRY_DISTANCE 0x04
#define TOF10120_I2C_REGISTRY_RT_DISTANCE 0x00
#define TOF10120_I2C_REGISTRY_BUS_ADDR_CONFIG 0x0f
#define TOF10120_I2C_REGISTRY_SENDING_METHOD_CONFIG 0x09
#endif


// ../inav/src/main/drivers/rangefinder/rangefinder_teraranger_evo.c
#if defined(USE_RANGEFINDER) && defined(USE_RANGEFINDER_TERARANGER_EVO_I2C)
#define TERARANGER_EVO_DETECTION_CONE_DECIDEGREES             900
#define TERARANGER_EVO_DETECTION_CONE_EXTENDED_DECIDEGREES    900
#define TERARANGER_EVO_I2C_ADDRESS                    0x31
#define TERARANGER_EVO_I2C_REGISTRY_TRIGGER_READING   0x00
#define TERARANGER_EVO_I2C_REGISTRY_WHO_AM_I          0x01
#define TERARANGER_EVO_I2C_REGISTRY_CHANGE_BASE_ADDR  0xA2
#define TERARANGER_EVO_I2C_ANSWER_WHO_AM_I            0xA1
#define TERARANGER_EVO_VALUE_TOO_CLOSE                0x0000
#define TERARANGER_EVO_VALUE_OUT_OF_RANGE             0xffff
#endif


// ../inav/src/main/drivers/sdcard/sdcard.c
#if defined(USE_SDCARD)
#ifndef SDCARD_DETECT_PIN
#define SDCARD_DETECT_PIN           NONE
#endif
#endif


// ../inav/src/main/drivers/sdcard/sdmmc_sdio_f4xx.c
#ifdef USE_SDCARD_SDIO
#define DMA_CHANNEL_4                   ((uint32_t)0x08000000)
#define DMA_MEMORY_TO_PERIPH            ((uint32_t)DMA_SxCR_DIR_0)
#define DMA_PERIPH_TO_MEMORY            ((uint32_t)0x00)
#define DMA_MINC_ENABLE                 ((uint32_t)DMA_SxCR_MINC)
#define DMA_MDATAALIGN_WORD             ((uint32_t)DMA_SxCR_MSIZE_1)
#define DMA_PDATAALIGN_WORD             ((uint32_t)DMA_SxCR_PSIZE_1)
#define DMA_PRIORITY_MEDIUM             ((uint32_t)DMA_Priority_Medium)
#define DMA_PRIORITY_HIGH               ((uint32_t)DMA_Priority_High)
#define DMA_PRIORITY_VERY_HIGH          ((uint32_t)DMA_Priority_VeryHigh)
#define DMA_MBURST_INC4                 ((uint32_t)DMA_SxCR_MBURST_0)
#define DMA_PBURST_INC4                 ((uint32_t)DMA_SxCR_PBURST_0)
#define BLOCK_SIZE                      ((uint32_t)(512))
#define IFCR_CLEAR_MASK_STREAM3         (DMA_LIFCR_CTCIF3 | DMA_LIFCR_CHTIF3 | DMA_LIFCR_CTEIF3 | DMA_LIFCR_CDMEIF3 | DMA_LIFCR_CFEIF3)
#define IFCR_CLEAR_MASK_STREAM6         (DMA_HIFCR_CTCIF6 | DMA_HIFCR_CHTIF6 | DMA_HIFCR_CTEIF6 | DMA_HIFCR_CDMEIF6 | DMA_HIFCR_CFEIF6)
#define SDIO_ICR_STATIC_FLAGS          ((uint32_t)(SDIO_ICR_CCRCFAILC | SDIO_ICR_DCRCFAILC | SDIO_ICR_CTIMEOUTC |\
                                                    SDIO_ICR_DTIMEOUTC | SDIO_ICR_TXUNDERRC | SDIO_ICR_RXOVERRC  |\
                                                    SDIO_ICR_CMDRENDC  | SDIO_ICR_CMDSENTC  | SDIO_ICR_DATAENDC  |\
                                                    SDIO_ICR_DBCKENDC))
#define SD_SOFTWARE_COMMAND_TIMEOUT     ((uint32_t)0x00020000)
#define SD_OCR_ADDR_OUT_OF_RANGE        ((uint32_t)0x80000000)
#define SD_OCR_ADDR_MISALIGNED          ((uint32_t)0x40000000)
#define SD_OCR_BLOCK_LEN_ERR            ((uint32_t)0x20000000)
#define SD_OCR_ERASE_SEQ_ERR            ((uint32_t)0x10000000)
#define SD_OCR_BAD_ERASE_PARAM          ((uint32_t)0x08000000)
#define SD_OCR_WRITE_PROT_VIOLATION     ((uint32_t)0x04000000)
#define SD_OCR_LOCK_UNLOCK_FAILED       ((uint32_t)0x01000000)
#define SD_OCR_COM_CRC_FAILED           ((uint32_t)0x00800000)
#define SD_OCR_ILLEGAL_CMD              ((uint32_t)0x00400000)
#define SD_OCR_CARD_ECC_FAILED          ((uint32_t)0x00200000)
#define SD_OCR_CC_ERROR                 ((uint32_t)0x00100000)
#define SD_OCR_GENERAL_UNKNOWN_ERROR    ((uint32_t)0x00080000)
#define SD_OCR_STREAM_READ_UNDERRUN     ((uint32_t)0x00040000)
#define SD_OCR_STREAM_WRITE_OVERRUN     ((uint32_t)0x00020000)
#define SD_OCR_CID_CSD_OVERWRITE        ((uint32_t)0x00010000)
#define SD_OCR_WP_ERASE_SKIP            ((uint32_t)0x00008000)
#define SD_OCR_CARD_ECC_DISABLED        ((uint32_t)0x00004000)
#define SD_OCR_ERASE_RESET              ((uint32_t)0x00002000)
#define SD_OCR_AKE_SEQ_ERROR            ((uint32_t)0x00000008)
#define SD_OCR_ERRORBITS                ((uint32_t)0xFDFFE008)
#define SD_R6_GENERAL_UNKNOWN_ERROR     ((uint32_t)0x00002000)
#define SD_R6_ILLEGAL_CMD               ((uint32_t)0x00004000)
#define SD_R6_COM_CRC_FAILED            ((uint32_t)0x00008000)
#define SD_VOLTAGE_WINDOW_SD            ((uint32_t)0x80100000)
#define SD_RESP_HIGH_CAPACITY           ((uint32_t)0x40000000)
#define SD_RESP_STD_CAPACITY            ((uint32_t)0x00000000)
#define SD_CHECK_PATTERN                ((uint32_t)0x000001AA)
#define SD_MAX_VOLT_TRIAL               ((uint32_t)0x0000FFFF)
#define SD_ALLZERO                      ((uint32_t)0x00000000)
#define SD_WIDE_BUS_SUPPORT             ((uint32_t)0x00040000)
#define SD_SINGLE_BUS_SUPPORT           ((uint32_t)0x00010000)
#define SD_CARD_LOCKED                  ((uint32_t)0x02000000)
#define SD_0TO7BITS                     ((uint32_t)0x000000FF)
#define SD_8TO15BITS                    ((uint32_t)0x0000FF00)
#define SD_16TO23BITS                   ((uint32_t)0x00FF0000)
#define SD_24TO31BITS                   ((uint32_t)0xFF000000)
#define SD_MAX_DATA_LENGTH              ((uint32_t)0x01FFFFFF)
#define SD_CCCC_ERASE                   ((uint32_t)0x00000020)
#define SD_SDIO_SEND_IF_COND           ((uint32_t)SD_CMD_HS_SEND_EXT_CSD)
#define SD_BUS_WIDE_1B                  ((uint32_t)0x00000000)
#define SD_BUS_WIDE_4B                  SDIO_CLKCR_WIDBUS_0
#define SD_BUS_WIDE_8B                  SDIO_CLKCR_WIDBUS_1
#define SD_CMD_RESPONSE_SHORT           SDIO_CMD_WAITRESP_0
#define SD_CMD_RESPONSE_LONG            SDIO_CMD_WAITRESP
#define SD_DATABLOCK_SIZE_8B            (SDIO_DCTRL_DBLOCKSIZE_0|SDIO_DCTRL_DBLOCKSIZE_1)
#define SD_DATABLOCK_SIZE_64B           (SDIO_DCTRL_DBLOCKSIZE_1|SDIO_DCTRL_DBLOCKSIZE_2)
#define SD_DATABLOCK_SIZE_512B          (SDIO_DCTRL_DBLOCKSIZE_0|SDIO_DCTRL_DBLOCKSIZE_3)
#define CLKCR_CLEAR_MASK                ((uint32_t)(SDIO_CLKCR_CLKDIV  | SDIO_CLKCR_PWRSAV |\
                                                    SDIO_CLKCR_BYPASS  | SDIO_CLKCR_WIDBUS |\
                                                    SDIO_CLKCR_NEGEDGE | SDIO_CLKCR_HWFC_EN))
#define DCTRL_CLEAR_MASK                ((uint32_t)(SDIO_DCTRL_DTEN    | SDIO_DCTRL_DTDIR |\
                                                    SDIO_DCTRL_DTMODE  | SDIO_DCTRL_DBLOCKSIZE))
#define CMD_CLEAR_MASK                  ((uint32_t)(SDIO_CMD_CMDINDEX | SDIO_CMD_WAITRESP |\
                                                    SDIO_CMD_WAITINT  | SDIO_CMD_WAITPEND |\
                                                    SDIO_CMD_CPSMEN   | SDIO_CMD_SDIOSUSPEND))
#define SDIO_INIT_CLK_DIV              ((uint8_t)0x76)
#define SDIO_CLK_DIV                   ((uint8_t)0x00)
#define SD_CMD_GO_IDLE_STATE            ((uint8_t)0)
#define SD_CMD_SEND_OP_COND             ((uint8_t)1)
#define SD_CMD_ALL_SEND_CID             ((uint8_t)2)
#define SD_CMD_SET_REL_ADDR             ((uint8_t)3)
#define SD_CMD_HS_SWITCH                ((uint8_t)6)
#define SD_CMD_SEL_DESEL_CARD           ((uint8_t)7)
#define SD_CMD_HS_SEND_EXT_CSD          ((uint8_t)8)
#define SD_CMD_SEND_CSD                 ((uint8_t)9)
#define SD_CMD_SEND_CID                 ((uint8_t)10)
#define SD_CMD_STOP_TRANSMISSION        ((uint8_t)12)
#define SD_CMD_SEND_STATUS              ((uint8_t)13)
#define SD_CMD_SET_BLOCKLEN             ((uint8_t)16)
#define SD_CMD_READ_SINGLE_BLOCK        ((uint8_t)17)
#define SD_CMD_READ_MULT_BLOCK          ((uint8_t)18)
#define SD_CMD_WRITE_SINGLE_BLOCK       ((uint8_t)24)
#define SD_CMD_WRITE_MULT_BLOCK         ((uint8_t)25)
#define SD_CMD_SD_ERASE_GRP_START       ((uint8_t)32)
#define SD_CMD_SD_ERASE_GRP_END         ((uint8_t)33)
#define SD_CMD_ERASE                    ((uint8_t)38)
#define SD_CMD_FAST_IO                  ((uint8_t)39)
#define SD_CMD_APP_CMD                  ((uint8_t)55)
#define SD_CMD_APP_SD_SET_BUSWIDTH      ((uint8_t)6)
#define SD_CMD_SD_APP_STATUS            ((uint8_t)13)
#define SD_CMD_SD_APP_OP_COND           ((uint8_t)41)
#define SD_CMD_SD_APP_SEND_SCR          ((uint8_t)51)
#define SDIO_DIR_TX 1
#define SDIO_DIR_RX 0
#define SDIO_DMA_ST3 1
#define SDIO_DATA       IO_CONFIG(GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL)
#define SDIO_CMD        IO_CONFIG(GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL)
#define SDIO_CLK        IO_CONFIG(GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL)
#endif


// ../inav/src/main/drivers/sdcard/sdmmc_sdio_hal.c
#ifdef USE_SDCARD_SDIO
#define SDIO_PIN_D0  0
#define SDIO_PIN_D1  1
#define SDIO_PIN_D2  2
#define SDIO_PIN_D3  3
#define SDIO_PIN_CK  4
#define SDIO_PIN_CMD 5
#define SDIO_PIN_COUNT  6
#define SDIO_MAX_PINDEFS 2
#define IOCFG_SDMMC       IO_CONFIG(GPIO_MODE_AF_PP, GPIO_SPEED_FREQ_VERY_HIGH, GPIO_NOPULL)
#ifdef STM32F7
#define SDMMC_CLK_DIV SDMMC_TRANSFER_CLK_DIV
#else
#if defined(SDCARD_SDIO_NORMAL_SPEED)
#define SDMMC_CLK_DIV SDMMC_NSpeed_CLK_DIV
#else
#define SDMMC_CLK_DIV SDMMC_HSpeed_CLK_DIV
#endif
#endif
#define PINDEF(device, pin, afnum) { DEFIO_TAG_E(pin), GPIO_AF ## afnum ## _SDMMC ## device }
#endif


// ../inav/src/main/drivers/sdcard/sdmmc_sdio.h
#if defined(USE_SDCARD_SDIO)
#define SD_DATATIMEOUT                          ((uint32_t)100000000)
#endif


// ../inav/src/main/drivers/sdcard/sdcard_standard.c
#define MIN(a, b) ((a) < (b) ? (a) : (b))


// ../inav/src/main/drivers/sdcard/sdcard_standard.h
#define SDCARD_GET_CSD_FIELD(csd, version, fieldname) \
    readBitfield(csd.data, SDCARD_CSD_V ## version ## _ ## fieldname ## _OFFSET, SDCARD_CSD_V ## version ## _ ## fieldname ## _LEN)
#define SDCARD_CSD_V1_CSD_STRUCTURE_VER_OFFSET           0
#define SDCARD_CSD_V1_CSD_STRUCTURE_VER_LEN              2
#define SDCARD_CSD_V1_TAAC_OFFSET                        8
#define SDCARD_CSD_V1_TAAC_LEN                           8
#define SDCARD_CSD_V1_NSAC_OFFSET                        16
#define SDCARD_CSD_V1_NSAC_LEN                           8
#define SDCARD_CSD_V1_TRAN_SPEED_OFFSET                  24
#define SDCARD_CSD_V1_TRAN_SPEED_LEN                     8
#define SDCARD_CSD_V1_CCC_OFFSET                         32
#define SDCARD_CSD_V1_CCC_LEN                            12
#define SDCARD_CSD_V1_READ_BLOCK_LEN_OFFSET              44
#define SDCARD_CSD_V1_READ_BLOCK_LEN_LEN                 4
#define SDCARD_CSD_V1_READ_BLOCK_PARTIAL_ALLOWED_OFFSET  48
#define SDCARD_CSD_V1_READ_BLOCK_PARTIAL_ALLOWED_LEN     1
#define SDCARD_CSD_V1_WRITE_BLOCK_MISALIGN_OFFSET        49
#define SDCARD_CSD_V1_WRITE_BLOCK_MISALIGN_LEN           1
#define SDCARD_CSD_V1_READ_BLOCK_MISALIGN_OFFSET         50
#define SDCARD_CSD_V1_READ_BLOCK_MISALIGN_LEN            1
#define SDCARD_CSD_V1_DSR_IMPLEMENTED_OFFSET             51
#define SDCARD_CSD_V1_DSR_IMPLEMENTED_LEN                1
#define SDCARD_CSD_V1_CSIZE_OFFSET                       54
#define SDCARD_CSD_V1_CSIZE_LEN                          12
#define SDCARD_CSD_V1_VDD_READ_CURR_MIN_OFFSET           66
#define SDCARD_CSD_V1_VDD_READ_CURR_MIN_LEN              3
#define SDCARD_CSD_V1_VDD_READ_CURR_MAX_OFFSET           69
#define SDCARD_CSD_V1_VDD_READ_CURR_MAX_LEN              3
#define SDCARD_CSD_V1_VDD_WRITE_CURR_MIN_OFFSET          72
#define SDCARD_CSD_V1_VDD_WRITE_CURR_MIN_LEN             3
#define SDCARD_CSD_V1_VDD_WRITE_CURR_MAX_OFFSET          75
#define SDCARD_CSD_V1_VDD_WRITE_CURR_MAX_LEN             3
#define SDCARD_CSD_V1_CSIZE_MULT_OFFSET                  78
#define SDCARD_CSD_V1_CSIZE_MULT_LEN                     3
#define SDCARD_CSD_V1_ERASE_SINGLE_BLOCK_ALLOWED_OFFSET  81
#define SDCARD_CSD_V1_ERASE_SINGLE_BLOCK_ALLOWED_LEN     1
#define SDCARD_CSD_V1_SECTOR_SIZE_OFFSET                 82
#define SDCARD_CSD_V1_SECTOR_SIZE_LEN                    7
#define SDCARD_CSD_V1_WRITE_PROTECT_GROUP_SIZE_OFFSET    89
#define SDCARD_CSD_V1_WRITE_PROTECT_GROUP_SIZE_LEN       7
#define SDCARD_CSD_V1_WRITE_PROTECT_GROUP_ENABLE_OFFSET  96
#define SDCARD_CSD_V1_WRITE_PROTECT_GROUP_ENABLE_LEN     1
#define SDCARD_CSD_V1_R2W_FACTOR_OFFSET                  99
#define SDCARD_CSD_V1_R2W_FACTOR_LEN                     3
#define SDCARD_CSD_V1_WRITE_BLOCK_LEN_OFFSET             102
#define SDCARD_CSD_V1_WRITE_BLOCK_LEN_LEN                4
#define SDCARD_CSD_V1_WRITE_BLOCK_PARTIAL_ALLOWED_OFFSET 106
#define SDCARD_CSD_V1_WRITE_BLOCK_PARTIAL_ALLOWED_LEN    1
#define SDCARD_CSD_V1_FILE_FORMAT_GROUP_OFFSET           112
#define SDCARD_CSD_V1_FILE_FORMAT_GROUP_LEN              1
#define SDCARD_CSD_V1_COPY_OFFSET                        113
#define SDCARD_CSD_V1_COPY_LEN                           1
#define SDCARD_CSD_V1_PERMANENT_WRITE_PROTECT_OFFSET     114
#define SDCARD_CSD_V1_PERMANENT_WRITE_PROTECT_LEN        1
#define SDCARD_CSD_V1_TEMPORARY_WRITE_PROTECT_OFFSET     115
#define SDCARD_CSD_V1_TEMPORARY_WRITE_PROTECT_LEN        1
#define SDCARD_CSD_V1_FILE_FORMAT_OFFSET                 116
#define SDCARD_CSD_V1_FILE_FORMAT_LEN                    2
#define SDCARD_CSD_V1_CRC_OFFSET                         120
#define SDCARD_CSD_V1_CRC_LEN                            7
#define SDCARD_CSD_V1_TRAILER_OFFSET                     127
#define SDCARD_CSD_V1_TRAILER_LEN                        1
#define SDCARD_CSD_V2_CSD_STRUCTURE_VER_OFFSET           0
#define SDCARD_CSD_V2_CSD_STRUCTURE_VER_LEN              2
#define SDCARD_CSD_V2_TAAC_OFFSET                        8
#define SDCARD_CSD_V2_TAAC_LEN                           8
#define SDCARD_CSD_V2_NSAC_OFFSET                        16
#define SDCARD_CSD_V2_NSAC_LEN                           8
#define SDCARD_CSD_V2_TRAN_SPEED_OFFSET                  24
#define SDCARD_CSD_V2_TRAN_SPEED_LEN                     8
#define SDCARD_CSD_V2_CCC_OFFSET                         32
#define SDCARD_CSD_V2_CCC_LEN                            12
#define SDCARD_CSD_V2_READ_BLOCK_LEN_OFFSET              44
#define SDCARD_CSD_V2_READ_BLOCK_LEN_LEN                 4
#define SDCARD_CSD_V2_READ_BLOCK_PARTIAL_ALLOWED_OFFSET  48
#define SDCARD_CSD_V2_READ_BLOCK_PARTIAL_ALLOWED_LEN     1
#define SDCARD_CSD_V2_WRITE_BLOCK_MISALIGN_OFFSET        49
#define SDCARD_CSD_V2_WRITE_BLOCK_MISALIGN_LEN           1
#define SDCARD_CSD_V2_READ_BLOCK_MISALIGN_OFFSET         50
#define SDCARD_CSD_V2_READ_BLOCK_MISALIGN_LEN            1
#define SDCARD_CSD_V2_DSR_IMPLEMENTED_OFFSET             51
#define SDCARD_CSD_V2_DSR_IMPLEMENTED_LEN                1
#define SDCARD_CSD_V2_CSIZE_OFFSET                       58
#define SDCARD_CSD_V2_CSIZE_LEN                          22
#define SDCARD_CSD_V2_ERASE_SINGLE_BLOCK_ALLOWED_OFFSET  81
#define SDCARD_CSD_V2_ERASE_SINGLE_BLOCK_ALLOWED_LEN     1
#define SDCARD_CSD_V2_SECTOR_SIZE_OFFSET                 82
#define SDCARD_CSD_V2_SECTOR_SIZE_LEN                    7
#define SDCARD_CSD_V2_WRITE_PROTECT_GROUP_SIZE_OFFSET    89
#define SDCARD_CSD_V2_WRITE_PROTECT_GROUP_SIZE_LEN       7
#define SDCARD_CSD_V2_WRITE_PROTECT_GROUP_ENABLE_OFFSET  96
#define SDCARD_CSD_V2_WRITE_PROTECT_GROUP_ENABLE_LEN     1
#define SDCARD_CSD_V2_R2W_FACTOR_OFFSET                  99
#define SDCARD_CSD_V2_R2W_FACTOR_LEN                     3
#define SDCARD_CSD_V2_WRITE_BLOCK_LEN_OFFSET             102
#define SDCARD_CSD_V2_WRITE_BLOCK_LEN_LEN                4
#define SDCARD_CSD_V2_WRITE_BLOCK_PARTIAL_ALLOWED_OFFSET 106
#define SDCARD_CSD_V2_WRITE_BLOCK_PARTIAL_ALLOWED_LEN    1
#define SDCARD_CSD_V2_FILE_FORMAT_GROUP_OFFSET           112
#define SDCARD_CSD_V2_FILE_FORMAT_GROUP_LEN              1
#define SDCARD_CSD_V2_COPY_OFFSET                        113
#define SDCARD_CSD_V2_COPY_LEN                           1
#define SDCARD_CSD_V2_PERMANENT_WRITE_PROTECT_OFFSET     114
#define SDCARD_CSD_V2_PERMANENT_WRITE_PROTECT_LEN        1
#define SDCARD_CSD_V2_TEMPORARY_WRITE_PROTECT_OFFSET     115
#define SDCARD_CSD_V2_TEMPORARY_WRITE_PROTECT_LEN        1
#define SDCARD_CSD_V2_FILE_FORMAT_OFFSET                 116
#define SDCARD_CSD_V2_FILE_FORMAT_LEN                    2
#define SDCARD_CSD_V2_CRC_OFFSET                         120
#define SDCARD_CSD_V2_CRC_LEN                            7
#define SDCARD_CSD_V2_TRAILER_OFFSET                     127
#define SDCARD_CSD_V2_TRAILER_LEN                        1
#define SDCARD_SINGLE_BLOCK_READ_START_TOKEN    0xFE
#define SDCARD_SINGLE_BLOCK_WRITE_START_TOKEN   0xFE
#define SDCARD_MULTIPLE_BLOCK_WRITE_START_TOKEN 0xFC
#define SDCARD_MULTIPLE_BLOCK_WRITE_STOP_TOKEN  0xFD
#define SDCARD_BLOCK_SIZE 512
#define SDCARD_R1_STATUS_BIT_IDLE                 1
#define SDCARD_R1_STATUS_BIT_ERASE_RESET          2
#define SDCARD_R1_STATUS_BIT_ILLEGAL_COMMAND      4
#define SDCARD_R1_STATUS_BIT_COM_CRC_ERROR        8
#define SDCARD_R1_STATUS_BIT_ERASE_SEQUENCE_ERROR 16
#define SDCARD_R1_STATUS_BIT_ADDRESS_ERROR        32
#define SDCARD_R1_STATUS_BIT_PARAMETER_ERROR      64
#define SDCARD_CSD_STRUCTURE_VERSION_1      0
#define SDCARD_CSD_STRUCTURE_VERSION_2      1
#define SDCARD_VOLTAGE_ACCEPTED_2_7_to_3_6  0x01
#define SDCARD_VOLTAGE_ACCEPTED_LVR         0x02
#define SDCARD_COMMAND_GO_IDLE_STATE             0
#define SDCARD_COMMAND_SEND_OP_COND              1
#define SDCARD_COMMAND_SEND_IF_COND              8
#define SDCARD_COMMAND_SEND_CSD                  9
#define SDCARD_COMMAND_SEND_CID                  10
#define SDCARD_COMMAND_STOP_TRANSMISSION         12
#define SDCARD_COMMAND_SEND_STATUS               13
#define SDCARD_COMMAND_SET_BLOCKLEN              16
#define SDCARD_COMMAND_READ_SINGLE_BLOCK         17
#define SDCARD_COMMAND_READ_MULTIPLE_BLOCK       18
#define SDCARD_COMMAND_WRITE_BLOCK               24
#define SDCARD_COMMAND_WRITE_MULTIPLE_BLOCK      25
#define SDCARD_COMMAND_APP_CMD                   55
#define SDCARD_COMMAND_READ_OCR                  58
#define SDCARD_ACOMMAND_SEND_OP_COND             41
#define SDCARD_ACOMMAND_SET_WR_BLOCK_ERASE_COUNT 23
#define SDCARD_TIMEOUT_READ_MSEC   100
#define SDCARD_TIMEOUT_WRITE_MSEC  250


// ../inav/src/main/drivers/sdcard/sdcard_sdio.c
#ifdef USE_SDCARD_SDIO
#if !defined(SDCARD_SDIO_DMA)
#define SDCARD_SDIO_DMA         DMA_TAG(2,3,4)
#endif
#if defined(USE_SDCARD_SDIO_CACHE)
#define FATFS_BLOCK_CACHE_SIZE 16
#endif
#endif


// ../inav/src/main/drivers/sdcard/sdcard_impl.h
#define SDCARD_TIMEOUT_INIT_MILLIS                  200
#define SDCARD_MAX_CONSECUTIVE_FAILURES             8


// ../inav/src/main/drivers/sdcard/sdcard_spi.c
#ifdef USE_SDCARD_SPI
#define SDCARD_INIT_NUM_DUMMY_BYTES                 10
#define SDCARD_MAXIMUM_BYTE_DELAY_FOR_CMD_REPLY     8
#define SDCARD_IF_COND_CHECK_PATTERN                0xAB
#define SDCARD_BLOCK_CHUNK_SIZE     128
#ifndef SDCARD_BUS_SPEED
#define SDCARD_BUS_SPEED            BUS_SPEED_STANDARD
#endif
#endif


// ../inav/src/main/drivers/1-wire/ds2482.c
#define DS2482_STATUS_REG_ADDR 0xF0
#define DS2482_READ_DATA_REG_ADDR 0xE1
#define DS2482_CONFIG_REG_ADDR 0xC3
#define DS2482_CONFIG_REG_APU (1<<0)
#define DS2482_CONFIG_REG_SPU (1<<2)
#define DS2482_CONFIG_REG_WS (1<<3)
#define DS2482_STATUS_REG_1WB_POS 0
#define DS2482_STATUS_REG_PPD_POS 1
#define DS2482_STATUS_REG_SD_POS 2
#define DS2482_STATUS_REG_LL_POS 3
#define DS2482_STATUS_REG_RST_POS 4
#define DS2482_STATUS_REG_SBR_POS 5
#define DS2482_STATUS_REG_TSB_POS 6
#define DS2482_STATUS_REG_DIR_POS 7
#define DS2482_1WIRE_BUSY(status) (status & (1 << DS2482_STATUS_REG_1WB_POS))
#define DS2482_DEVICE_PRESENT(status) (status & (1 << DS2482_STATUS_REG_PPD_POS))
#define DS2482_RESET(status) (status & (1 << DS2482_STATUS_REG_RST_POS))
#define DS2482_LOGIC_LEVEL(status) (status & (1 << DS2482_STATUS_REG_LL_POS))
#define DS2482_SHORT_DETECTED(status) (status & (1 << DS2482_STATUS_REG_SD_POS))
#define DS2482_SBR_VALUE(status) ((status >> DS2482_STATUS_REG_SBR_POS) & 1)
#define DS2482_TSB_VALUE(status) ((status >> DS2482_STATUS_REG_TSB_POS) & 1)
#define DS2482_DIR_VALUE(status) ((status >> DS2482_STATUS_REG_DIR_POS) & 1)
#define DS2482_1WIRE_SINGLE_BIT_WRITE0 0
#define DS2482_1WIRE_SINGLE_BIT_WRITE1_READ (1<<7)
#define DS2482_CONFIG_WRITE_BYTE(config) (config | ((~config & 0xF) << 4))
#define DS2482_RESET_CMD 0xF0
#define DS2482_SET_READ_PTR_CMD 0xE1
#define DS2482_WRITE_CONFIG_CMD 0xD2
#define DS2482_1WIRE_RESET_CMD 0xB4
#define DS2482_1WIRE_SINGLE_BIT_CMD 0x87
#define DS2482_1WIRE_WRITE_BYTE_CMD 0xA5
#define DS2482_1WIRE_READ_BYTE_CMD 0x96
#define DS2482_1WIRE_TRIPLET_CMD 0x78
#define _1WIRE_SEARCH_ROM_CMD 0xF0
#define _1WIRE_READ_ROM_CMD 0x33
#define _1WIRE_MATCH_ROM_CMD 0x55
#define _1WIRE_SKIP_ROM_CMD 0xCC
#if defined(USE_1WIRE) && defined(USE_1WIRE_DS2482)
#define DETECTION_MAX_RETRY_COUNT 5
#endif


// ../inav/src/main/build/debug.h
#define DEBUG32_VALUE_COUNT 8
#define DEBUG_SET(mode, index, value) {if (debugMode == (mode)) {debug[(index)] = (value);}}
#define DEBUG_SECTION_TIMES
#ifdef DEBUG_SECTION_TIMES
#define TIME_SECTION_BEGIN(index) { \
    extern timeUs_t sectionTimes[2][4]; \
    sectionTimes[0][index] = micros(); \
}
#define TIME_SECTION_END(index) { \
    extern timeUs_t sectionTimes[2][4]; \
    sectionTimes[1][index] = micros(); \
    debug[index] = sectionTimes[1][index] - sectionTimes[0][index]; \
}
#else
#define TIME_SECTION_BEGIN(index) {}
#define TIME_SECTION_END(index) {}
#endif
#ifdef SITL_BUILD
#define SD(X) (X)
#else
#define SD(X)
#endif


// ../inav/src/main/build/atomic.h
#ifdef UNIT_TEST
#define ATOMIC_BLOCK(prio) {}
#else
#define ATOMIC_BLOCK(prio) for ( uint8_t __basepri_save __attribute__((__cleanup__(__basepriRestoreMem))) = __get_BASEPRI(), \
                                     __ToDo = __basepriSetMemRetVal((prio) << (8U - __NVIC_PRIO_BITS)); __ToDo ; __ToDo = 0 )
#endif


// ../inav/src/main/build/assert.h
#if defined(USE_ASSERT) && defined(USE_ASSERT_CHECK)
    #if defined(USE_ASSERT_FULL)
        #define ASSERT(expr)        if (expr) { } else assertFailed2(__FILE__, __LINE__)
    #else
        #define ASSERT(expr)        if (expr) { } else assertFailed1(__LINE__)
#endif
#else
    #define ASSERT(expr)        while (0) { }
#endif


// ../inav/src/main/build/build_config.h
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#ifdef UNIT_TEST
#define STATIC_UNIT_TESTED
#define STATIC_INLINE_UNIT_TESTED
#define INLINE_UNIT_TESTED
#define UNIT_TESTED
#else
#define STATIC_UNIT_TESTED static
#define STATIC_INLINE_UNIT_TESTED static inline
#define INLINE_UNIT_TESTED inline
#define UNIT_TESTED
#endif
#ifndef __CC_ARM
#define REQUIRE_CC_ARM_PRINTF_SUPPORT
#define REQUIRE_PRINTF_LONG_SUPPORT
#endif
#ifdef __APPLE__
#define FASTRAM                     __attribute__ ((section("__DATA,__.fastram_bss"), aligned(8)))
#else
#define FASTRAM                     __attribute__ ((section(".fastram_bss"), aligned(4)))
#endif
#if defined (STM32F4) || defined (STM32F7)
#define EXTENDED_FASTRAM FASTRAM
#else
#define EXTENDED_FASTRAM
#endif
#if defined (STM32H7)
#define DMA_RAM __attribute__ ((section(".DMA_RAM")))
#define SLOW_RAM __attribute__ ((section(".SLOW_RAM")))
#elif defined (AT32F43x)
#define DMA_RAM __attribute__ ((section(".DMA_RAM")))
#define SLOW_RAM __attribute__ ((section(".SLOW_RAM")))
#else
#define DMA_RAM
#define SLOW_RAM
#endif
#define STATIC_FASTRAM              static FASTRAM
#define STATIC_FASTRAM_UNIT_TESTED  STATIC_UNIT_TESTED FASTRAM


// ../inav/src/main/build/version.h
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define FC_VERSION_STRING STR(FC_VERSION_MAJOR) "." STR(FC_VERSION_MINOR) "." STR(FC_VERSION_PATCH_LEVEL)
#ifndef FC_VERSION_TYPE
#define FC_VERSION_TYPE ""
#endif
#define FC_FIRMWARE_NAME "INAV"
#define MW_VERSION              231
#define GIT_SHORT_REVISION_LENGTH   8
#define BUILD_DATE_LENGTH 11
#define BUILD_TIME_LENGTH 8


// ../inav/src/main/common/circular_queue.h
#ifndef INAV_CIRCULAR_QUEUE_H
#define INAV_CIRCULAR_QUEUE_H
#endif


// ../inav/src/main/common/gps_conversion.c
#ifdef USE_GPS
#define DIGIT_TO_VAL(_x)    (_x - '0')
#endif


// ../inav/src/main/common/color.h
#define RGB_COLOR_COMPONENT_COUNT (RGB_BLUE + 1)
#define HSV_HUE_MAX 359
#define HSV_SATURATION_MAX 255
#define HSV_VALUE_MAX 255
#define HSV_COLOR_COMPONENT_COUNT (HSV_VALUE + 1)


// ../inav/src/main/common/axis.h
#define XYZ_AXIS_COUNT 3
#define FLIGHT_DYNAMICS_INDEX_COUNT 3
#define ANGLE_INDEX_COUNT 2


// ../inav/src/main/common/log.c
#if defined(USE_LOG)
#define LOG_PREFIX                  "[%6d.%03d] "
#define LOG_PREFIX_FORMATTED_SIZE   13
#endif


// ../inav/src/main/common/typeconversion.h
#define FTOA_BUFFER_SIZE 13


// ../inav/src/main/common/utils.h
#define ARRAYLEN(x) (sizeof(x) / sizeof((x)[0]))
#define ARRAYEND(x) (&(x)[ARRAYLEN(x)])
#define ZERO_FARRAY(a) memset(a, 0, sizeof(a))
#define CONST_CAST(type, value) ((type)(value))
#define CONCAT_HELPER(x,y) x ## y
#define CONCAT(x,y) CONCAT_HELPER(x, y)
#define CONCAT3_HELPER(x, y, z) x ## y ## z
#define CONCAT3(x, y, z) CONCAT3_HELPER(x, y, z)
#define CONCAT4_HELPER(x, y, z, w) x ## y ## z ## w
#define CONCAT4(x, y, z, w) CONCAT4_HELPER(x, y, z, w)
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define EXPAND_I(x) x
#define EXPAND(x) EXPAND_I(x)
#define PP_CALL(macro, ...) macro(__VA_ARGS__)
#if !defined(UNUSED)
#define UNUSED(x) (void)(x)
#endif
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define BIT(x) (1 << (x))
#define GET_BIT(value, bit) ((value >> bit) & 1)
#define STATIC_ASSERT(condition, name) \
    typedef char assert_failed_ ## name [(condition) ? 1 : -1 ] __attribute__((unused))
#define BITCOUNT(x) (((BX_(x)+(BX_(x)>>4)) & 0x0F0F0F0F) % 255)
#define BX_(x) ((x) - (((x)>>1)&0x77777777) - (((x)>>2)&0x33333333) - (((x)>>3)&0x11111111))
#define LOG2_8BIT(v)  (8 - 90/(((v)/4+14)|1) - 2/((v)/2+1))
#define LOG2_16BIT(v) (8*((v)>255) + LOG2_8BIT((v) >>8*((v)>255)))
#define LOG2_32BIT(v) (16*((v)>65535L) + LOG2_16BIT((v)*1L >>16*((v)>65535L)))
#define LOG2_64BIT(v) \
    (32*((v)/2L>>31 > 0) \
     + LOG2_32BIT((v)*1L >>16*((v)/2L>>31 > 0) \
                         >>16*((v)/2L>>31 > 0)))
#define container_of(ptr, type, member)  ( __extension__ ({     \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );}))
#if defined(UNIT_TEST) || defined(SITL_BUILD)
#define memcpy_fn(destination, source, num) memcpy(destination, source, num)
#endif
#if __GNUC__ > 6
#define FALLTHROUGH __attribute__ ((fallthrough))
#else
#define FALLTHROUGH do {} while(0)
#endif
#define UNREACHABLE() __builtin_unreachable()
#define ALIGNED(x) __attribute__ ((aligned(x)))
#define PACKED __attribute__((packed))


// ../inav/src/main/common/olc.h
#define OLC_DEG_MULTIPLIER ((olc_coord_t)10000000LL)


// ../inav/src/main/common/bitarray.c
#define BITARRAY_BIT_OP(array, bit, op) ((array)[(bit) / (sizeof((array)[0]) * 8)] op (1 << ((bit) % (sizeof((array)[0]) * 8))))


// ../inav/src/main/common/log.h
#define LOG_LEVEL_ERROR 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_VERBOSE 3
#define LOG_LEVEL_DEBUG 4
#if defined(USE_LOG)
#define LOG_ERROR(topic, fmt, ...) _logf(LOG_TOPIC_ ## topic, LOG_LEVEL_ERROR, fmt, ##__VA_ARGS__)
#define LOG_BUFFER_ERROR(topic, buf, size) _logBufferHex(LOG_TOPIC_ ## topic, LOG_LEVEL_ERROR, buf, size)
#else
#define LOG_ERROR(...)
#define LOG_BUFFER_ERROR(...)
#endif
#if defined(USE_LOG)
#define LOG_WARNING(topic, fmt, ...) _logf(LOG_TOPIC_ ## topic, LOG_LEVEL_WARNING, fmt, ##__VA_ARGS__)
#define LOG_BUF_WARNING(topic, buf, size) _logBufferHex(LOG_TOPIC_ ## topic, LOG_LEVEL_WARNING, buf, size)
#else
#define LOG_WARNING(...)
#define LOG_BUF_WARNING(...)
#endif
#if defined(USE_LOG)
#define LOG_INFO(topic, fmt, ...) _logf(LOG_TOPIC_ ## topic, LOG_LEVEL_INFO, fmt, ##__VA_ARGS__)
#define LOG_BUF_INFO(topic, buf, size) _logBufferHex(LOG_TOPIC_ ## topic, LOG_LEVEL_INFO, buf, size)
#else
#define LOG_INFO(...)
#define LOG_BUF_INFO(...)
#endif
#if defined(USE_LOG)
#define LOG_VERBOSE(topic, fmt, ...) _logf(LOG_TOPIC_ ## topic, LOG_LEVEL_VERBOSE, fmt, ##__VA_ARGS__)
#define LOG_BUF_VERBOSE(topic, buf, size) _logBufferHex(LOG_TOPIC_ ## topic, LOG_LEVEL_VERBOSE, buf, size)
#else
#define LOG_VERBOSE(...)
#define LOG_BUF_VERBOSE(...)
#endif
#if defined(USE_LOG)
#define LOG_DEBUG(topic, fmt, ...) _logf(LOG_TOPIC_ ## topic, LOG_LEVEL_DEBUG, fmt, ##__VA_ARGS__)
#define LOG_BUF_DEBUG(topic, buf, size) _logBufferHex(LOG_TOPIC_ ## topic, LOG_LEVEL_DEBUG, buf, size)
#else
#define LOG_DEBUG(...)
#define LOG_BUF_DEBUG(...)
#endif


// ../inav/src/main/common/olc.c
#define SEPARATOR_CHAR '+'
#define SEPARATOR_POS 8
#define PADDING_CHAR '0'
#define ENCODING_BASE 20
#define PAIR_CODE_LEN 10u
#define CODE_LEN_MAX 15u
#define GRID_COLS 4
#define GRID_ROWS (ENCODING_BASE / GRID_COLS)
#define LAT_MAX (90 * OLC_DEG_MULTIPLIER)
#define LON_MAX (180 * OLC_DEG_MULTIPLIER)


// ../inav/src/main/common/bitarray.h
#define BITARRAY_DECLARE(name, bits) bitarrayElement_t name[(bits + 31) / 32]
#define BITARRAY_SET_ALL(array) bitArraySetAll(array, sizeof(array))
#define BITARRAY_CLR_ALL(array) bitArrayClrAll(array, sizeof(array))
#define BITARRAY_FIND_FIRST_SET(array, start_bit) bitArrayFindFirstSet(array, start_bit, sizeof(array))


// ../inav/src/main/common/printf.h
#ifndef __TFP_PRINTF__
#define __TFP_PRINTF__
#endif


// ../inav/src/main/common/maths.h
#ifndef sq
#define sq(x) ((x)*(x))
#endif
#define FAST_MATH
#define M_PIf   3.14159265358979323846f
#define M_LN2f  0.69314718055994530942f
#define M_Ef    2.71828182845904523536f
#define RAD (M_PIf / 180.0f)
#define DEGREES_TO_CENTIDEGREES(angle)      ((angle) * 100)
#define CENTIDEGREES_TO_DEGREES(angle)      ((angle) * 0.01f)
#define CENTIDEGREES_TO_DECIDEGREES(angle)  ((angle) / 10.0f)
#define DECIDEGREES_TO_CENTIDEGREES(angle)  ((angle) * 10)
#define DEGREES_TO_DECIDEGREES(angle)       ((angle) * 10)
#define DECIDEGREES_TO_DEGREES(angle)       ((angle) / 10.0f)
#define DEGREES_PER_DEKADEGREE              10
#define DEGREES_TO_DEKADEGREES(angle)       ((angle) / DEGREES_PER_DEKADEGREE)
#define DEKADEGREES_TO_DEGREES(angle)       ((angle) * DEGREES_PER_DEKADEGREE)
#define DEGREES_TO_RADIANS(angle)           ((angle) * RAD)
#define RADIANS_TO_DEGREES(angle)           ((angle) / RAD)
#define DECIDEGREES_TO_RADIANS(angle)       (((angle) / 10.0f) * RAD)
#define RADIANS_TO_DECIDEGREES(angle)       (((angle) * 10.0f) / RAD)
#define RADIANS_TO_CENTIDEGREES(angle)      (((angle) * 100.0f) / RAD)
#define CENTIDEGREES_TO_RADIANS(angle)      (((angle) * 0.01f) * RAD)
#define MILLIMETERS_TO_CENTIMETERS(mm)      (mm / 10.0f)
#define CENTIMETERS_TO_CENTIFEET(cm)        (cm / 0.3048f)
#define CENTIMETERS_TO_FEET(cm)             (cm / 30.48f)
#define CENTIMETERS_TO_METERS(cm)           (cm * 0.01f)
#define METERS_TO_CENTIMETERS(m)            (m * 100)
#define METERS_TO_KILOMETERS(m)             (m / 1000.0f)
#define METERS_TO_MILES(m)                  (m / 1609.344f)
#define METERS_TO_NAUTICALMILES(m)          (m / 1852.00f)
#define MWH_TO_WH(mWh)                      (mWh / 1000.0f)
#define CMSEC_TO_CENTIMPH(cms)              (cms * 2.2369363f)
#define CMSEC_TO_CENTIKPH(cms)              (cms * 3.6f)
#define CMSEC_TO_CENTIKNOTS(cms)            (cms * 1.943845f)
#define CMSEC_TO_MPH(cms)                   (CMSEC_TO_CENTIMPH(cms) / 100.0f)
#define CMSEC_TO_KPH(cms)                   (CMSEC_TO_CENTIKPH(cms) / 100.0f)
#define CMSEC_TO_KNOTS(cms)                 (CMSEC_TO_CENTIKNOTS(cms) / 100.0f)
#define KMH_TO_MS(kmh)                      (kmh / 3.6f)
#define C_TO_KELVIN(temp)                   (temp + 273.15f)
#define SSL_AIR_DENSITY		1.225f
#define SSL_AIR_PRESSURE	101325.01576f
#define SSL_AIR_TEMPERATURE	288.15f
#define _CHOOSE2(binoper, lexpr, lvar, rexpr, rvar) \
    ( __extension__ ({                              \
        __typeof__(lexpr) lvar = (lexpr);           \
        __typeof__(rexpr) rvar = (rexpr);           \
        lvar binoper rvar ? lvar : rvar;            \
    }))
#define _CHOOSE_VAR2(prefix, unique) prefix##unique
#define _CHOOSE_VAR(prefix, unique) _CHOOSE_VAR2(prefix, unique)
#define _CHOOSE(binoper, lexpr, rexpr)          \
    _CHOOSE2(                                   \
        binoper,                                \
        lexpr, _CHOOSE_VAR(_left, __COUNTER__), \
        rexpr, _CHOOSE_VAR(_right, __COUNTER__) \
        )
#define MIN(a, b) _CHOOSE(<, a, b)
#define MAX(a, b) _CHOOSE(>, a, b)
#define SIGN(a) ((a >= 0) ? 1 : -1)
#define _ABS_II(x, var)             \
    ( __extension__ ({              \
        __typeof__(x) var = (x);    \
        var < 0 ? -var : var;       \
    }))
#define _ABS_I(x, var) _ABS_II(x, var)
#define ABS(x) _ABS_I(x, _CHOOSE_VAR(_abs, __COUNTER__))
#define power3(x) ((x)*(x)*(x))
#if defined(FAST_MATH) || defined(VERY_FAST_MATH)
#define tan_approx(x)       (sin_approx(x) / cos_approx(x))
#define asin_approx(x)      (M_PIf / 2 - acos_approx(x))
#else
#define asin_approx(x)      asinf(x)
#define sin_approx(x)       sinf(x)
#define cos_approx(x)       cosf(x)
#define atan2_approx(y,x)   atan2f(y,x)
#define acos_approx(x)      acosf(x)
#define tan_approx(x)       tanf(x)
#endif
#define int16_val_big_endian(v, idx) ((int16_t)(((uint8_t)v[2 * idx] << 8) | v[2 * idx + 1]))
#define int16_val_little_endian(v, idx) ((int16_t)(((uint8_t)v[2 * idx + 1] << 8) | v[2 * idx]))


// ../inav/src/main/common/printf.c
#ifdef REQUIRE_PRINTF_LONG_SUPPORT
#define MAX UINT64_MAX
#else
#define MAX UINT32_MAX
#endif


// ../inav/src/main/common/time.c
#define REFERENCE_YEAR 2000
#define EPOCH_2000_OFFSET 946684800
#define MILLIS_PER_SECOND 1000


// ../inav/src/main/common/maths.c
#if defined(FAST_MATH) || defined(VERY_FAST_MATH)
#if defined(VERY_FAST_MATH)
#define sinPolyCoef3 -1.666568107e-1f
#define sinPolyCoef5  8.312366210e-3f
#define sinPolyCoef7 -1.849218155e-4f
#define sinPolyCoef9  0
#else
#define sinPolyCoef3 -1.666665710e-1f
#define sinPolyCoef5  8.333017292e-3f
#define sinPolyCoef7 -1.980661520e-4f
#define sinPolyCoef9  2.600054768e-6f
#endif
    #define atanPolyCoef1  3.14551665884836e-07f
    #define atanPolyCoef2  0.99997356613987f
    #define atanPolyCoef3  0.14744007058297684f
    #define atanPolyCoef4  0.3099814292351353f
    #define atanPolyCoef5  0.05030176425872175f
    #define atanPolyCoef6  0.1471039133652469f
    #define atanPolyCoef7  0.6444640676891548f
#endif
#define QMF_SORT(type,a,b) { if ((a)>(b)) QMF_SWAP(type, (a),(b)); }
#define QMF_SWAP(type,a,b) { type temp=(a);(a)=(b);(b)=temp; }


// ../inav/src/main/common/constants.h
#define FEET_PER_MILE                           5280
#define FEET_PER_NAUTICALMILE                   6076.118f
#define FEET_PER_KILOFEET                       1000
#define METERS_PER_KILOMETER                    1000
#define METERS_PER_MILE                         1609.344f
#define METERS_PER_FOOT                         3.28084f
#define METERS_PER_NAUTICALMILE                 1852.001f


// ../inav/src/main/common/time.h
#define TIMEDELTA_MAX INT32_MAX
#define TIMEDELTALARGE_MAX INT64_MAX
#define TIMEMS_MAX UINT32_MAX
#ifdef USE_64BIT_TIME
#define TIMEUS_MAX UINT64_MAX
#else
#define TIMEUS_MAX UINT32_MAX
#endif
#define MILLISECS_PER_SEC 1000
#define USECS_PER_SEC (1000 * 1000)
#define HZ2US(hz)   (1000000 / (hz))
#define HZ2MS(hz)   (1000 / (hz))
#define US2S(us)    ((us) * 1e-6f)
#define US2MS(us)   ((us) * 1e-3f)
#define MS2US(ms)   ((ms) * 1000)
#define MS2S(ms)    ((ms) * 1e-3f)
#define S2MS(s)     ((s) * MILLISECS_PER_SEC)
#define DS2MS(ds)   ((ds) * 100)
#define HZ2S(hz)    US2S(HZ2US(hz))
#define FORMATTED_DATE_TIME_BUFSIZE 30


// ../inav/src/main/common/typeconversion.c
#define white_space(c) ((c) == ' ' || (c) == '\t')
#define valid_digit(c) ((c) >= '0' && (c) <= '9')


// ../inav/src/main/common/filter.h
#define BIQUAD_BANDWIDTH 1.9f
#define BIQUAD_Q 1.0f / sqrtf(2.0f)


// ../inav/src/main/common/memory.c
#if !defined(DYNAMIC_HEAP_SIZE)
#define DYNAMIC_HEAP_SIZE   (2048)
#endif

