#!/usr/bin/env bash
set -euo pipefail

INAV_DIR="${1:?Usage: include/sync.sh PATH_TO_INAV}"
INCLUDE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

cp "${INAV_DIR}/src/main/msp/msp_protocol.h" "${INCLUDE_DIR}/msp_protocol.h"
cp "${INAV_DIR}/src/main/msp/msp_protocol_v2_common.h" "${INCLUDE_DIR}/msp_protocol_v2_common.h"
cp "${INAV_DIR}/src/main/msp/msp_protocol_v2_inav.h" "${INCLUDE_DIR}/msp_protocol_v2_inav.h"
cp "${INAV_DIR}/src/main/msp/msp_protocol_v2_sensor.h" "${INCLUDE_DIR}/msp_protocol_v2_sensor.h"
cp "${INAV_DIR}/src/main/msp/msp_protocol_v2_sensor_msg.h" "${INCLUDE_DIR}/msp_protocol_v2_sensor_msg.h"

cp "${INAV_DIR}/docs/development/msp/msp_messages.json" "${INCLUDE_DIR}/msp_messages.json"
cp "${INAV_DIR}/docs/development/msp/inav_enums.json" "${INCLUDE_DIR}/inav_enums.json"

cp "${INAV_DIR}/src/main/common/bitarray.c" "${INCLUDE_DIR}/bitarray.c"
cp "${INAV_DIR}/src/main/common/bitarray.h" "${INCLUDE_DIR}/bitarray.h"
