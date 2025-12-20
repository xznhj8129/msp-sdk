// Fallback stub definitions for MSP support types not present in consolidated headers.
#pragma once
#include <stdint.h>

#ifndef BIT
#define BIT(x) (1U << (x))
#endif

#ifndef MSP_HAS_ESC_SENSOR_DATA_T
#define MSP_HAS_ESC_SENSOR_DATA_T
typedef struct __attribute__((packed)) {
    uint8_t dataAge;
    int16_t temperature;
    int16_t voltage;
    int32_t current;
    uint32_t rpm;
} escSensorData_t;
#endif

#ifndef MSP_HAS_LED_CONFIG_T
#define MSP_HAS_LED_CONFIG_T
typedef struct __attribute__((packed)) {
    uint8_t raw[6];
} ledConfig_t;
#endif

#ifndef MSP_HAS_FW_AUTOTUNE_RATE_ADJUSTMENT_E
#define MSP_HAS_FW_AUTOTUNE_RATE_ADJUSTMENT_E
typedef enum {
    FW_AUTOTUNE_RATE_ADJ_FIXED = 0,
    FW_AUTOTUNE_RATE_ADJ_LIMIT = 1,
    FW_AUTOTUNE_RATE_ADJ_AUTO = 2,
} fw_autotune_rate_adjustment_e;
#endif


#ifndef MSP_HAS_VARIES_T
#define MSP_HAS_VARIES_T
typedef uint8_t Varies;
#endif

#ifndef MSP_HAS_NAV_USER_CONTROL_MODE_E
#define MSP_HAS_NAV_USER_CONTROL_MODE_E
typedef uint8_t navUserControlMode_e;
#endif

#ifndef MSP_HAS_NAV_RTH_ALT_CONTROL_MODE_E
#define MSP_HAS_NAV_RTH_ALT_CONTROL_MODE_E
typedef uint8_t navRthAltControlMode_e;
#endif

#ifndef MSP_HAS_MIXER_PRESET_E
#define MSP_HAS_MIXER_PRESET_E
typedef uint16_t mixerPreset_e;
#endif

#ifndef MSP_HAS_BOXBITMASK_T
#define MSP_HAS_BOXBITMASK_T
#ifdef CHECKBOX_ITEM_COUNT
#define MSP_BOXBITMASK_WORDS ((CHECKBOX_ITEM_COUNT + 31) / 32)
#else
#define MSP_BOXBITMASK_WORDS ((60 + 31) / 32)
#endif
typedef struct {
    uint32_t bits[MSP_BOXBITMASK_WORDS];
} boxBitmask_t;
#undef MSP_BOXBITMASK_WORDS
#endif
