// Consolidated defines - generated on 2025-12-17 12:03:11.363937


// Essential constants sourced from inav/src
// ../inav/src/main/build/version.h
#define BUILD_DATE_LENGTH 11
#define BUILD_TIME_LENGTH 8
#define GIT_SHORT_REVISION_LENGTH 8
// ../inav/src/main/drivers/osd.h
#define OSD_CHAR_WIDTH 12
#define OSD_CHAR_HEIGHT 18
#define OSD_CHAR_BITS_PER_PIXEL 2
#define OSD_CHAR_VISIBLE_BYTES (OSD_CHAR_WIDTH * OSD_CHAR_HEIGHT * OSD_CHAR_BITS_PER_PIXEL / 8)
#define OSD_CHAR_BYTES 64
// ../inav/src/main/build/debug.h
#define DEBUG32_VALUE_COUNT 8
// helper used by several enums
#ifndef BIT
#define BIT(x) (1U << (x))
#endif

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
