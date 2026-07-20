// MSP wire support types which are not represented by inav_enums.json.
#pragma once
#include <stdint.h>

#ifndef BIT
#define BIT(x) (1U << (x))
#endif

#if defined(_MSC_VER)
#pragma pack(push, 1)
#define MSP_SUPPORT_PACKED
#else
#define MSP_SUPPORT_PACKED __attribute__((packed))
#endif

#ifndef MSP_HAS_ESC_SENSOR_DATA_T
#define MSP_HAS_ESC_SENSOR_DATA_T
typedef struct MSP_SUPPORT_PACKED {
    uint8_t dataAge;
    uint8_t _paddingAfterDataAge;
    int16_t temperature;
    int16_t voltage;
    uint8_t _paddingBeforeCurrent[2];
    int32_t current;
    uint32_t rpm;
} escSensorData_t;
#endif

#ifndef MSP_HAS_LED_CONFIG_T
#define MSP_HAS_LED_CONFIG_T
typedef struct MSP_SUPPORT_PACKED {
    uint8_t raw[6];
} ledConfig_t;
#endif

#ifndef MSP_HAS_VARIES_T
#define MSP_HAS_VARIES_T
typedef uint8_t Varies;
#endif

#ifndef MSP_HAS_DRONECAN_NODE_STATUS_T
#define MSP_HAS_DRONECAN_NODE_STATUS_T
typedef struct MSP_SUPPORT_PACKED {
    uint8_t nodeID;
    uint8_t health;
    uint8_t mode;
    uint32_t last_seen_ms;
} dronecanNodeStatus_t;
#endif

#ifndef MSP_HAS_BOXBITMASK_T
#define MSP_HAS_BOXBITMASK_T
#define MSP_BOXBITMASK_WORDS ((CHECKBOX_ITEM_COUNT + 31) / 32)
typedef struct {
    uint32_t bits[MSP_BOXBITMASK_WORDS];
} boxBitmask_t;
#undef MSP_BOXBITMASK_WORDS
#endif

#if defined(_MSC_VER)
#pragma pack(pop)
#endif
#undef MSP_SUPPORT_PACKED
