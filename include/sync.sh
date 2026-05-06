#!/usr/bin/env bash
set -euo pipefail

INAV_SRC_PATH="${INAV_SRC_PATH:-${1:-}}"
: "${INAV_SRC_PATH:?Set INAV_SRC_PATH or pass it as first argument}"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

cp "${INAV_SRC_PATH}/src/main/msp/msp_protocol.h" "${SCRIPT_DIR}/msp_protocol.h"
cp "${INAV_SRC_PATH}/src/main/msp/msp_protocol_v2_common.h" "${SCRIPT_DIR}/msp_protocol_v2_common.h"
cp "${INAV_SRC_PATH}/src/main/msp/msp_protocol_v2_inav.h" "${SCRIPT_DIR}/msp_protocol_v2_inav.h"
cp "${INAV_SRC_PATH}/src/main/msp/msp_protocol_v2_sensor.h" "${SCRIPT_DIR}/msp_protocol_v2_sensor.h"
cp "${INAV_SRC_PATH}/src/main/msp/msp_protocol_v2_sensor_msg.h" "${SCRIPT_DIR}/msp_protocol_v2_sensor_msg.h"

cp "${INAV_SRC_PATH}/docs/development/msp/msp_messages.json" "${SCRIPT_DIR}/msp_messages.json"
cp "${INAV_SRC_PATH}/docs/development/msp/inav_enums.json" "${SCRIPT_DIR}/inav_enums.json"
cp "${INAV_SRC_PATH}/docs/development/msp/all_enums.h" "${SCRIPT_DIR}/all_enums.h"

cp "${INAV_SRC_PATH}/src/main/common/bitarray.c" "${SCRIPT_DIR}/bitarray.c"
cp "${INAV_SRC_PATH}/src/main/common/bitarray.h" "${SCRIPT_DIR}/bitarray.h"
