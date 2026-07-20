#!/usr/bin/env bash
set -euo pipefail

GENERATOR_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SDK_ROOT="$(cd "${GENERATOR_DIR}/.." && pwd)"
INAV_DIR=""
VERBOSE_DEFINES=()

while (($#)); do
    case "$1" in
        --inav-dir)
            INAV_DIR="$2"
            shift 2
            ;;
        --verbose-defines)
            VERBOSE_DEFINES=(--verbose)
            shift
            ;;
        -h|--help)
            echo "Usage: ./generator/gen_all.sh [--inav-dir PATH] [--verbose-defines]"
            echo
            echo "Without --inav-dir, the SDK-managed INAV checkout at <sdk>/inav is"
            echo "used, cloning it from the network first if missing (see sync_inav.sh)."
            exit 0
            ;;
        *)
            echo "Unknown argument: $1" >&2
            exit 2
            ;;
    esac
done

if [[ -z "${INAV_DIR}" ]]; then
    INAV_DIR="${SDK_ROOT}/inav"
    if [[ ! -d "${INAV_DIR}/.git" ]]; then
        "${GENERATOR_DIR}/sync_inav.sh"
    fi
fi

INAV_DIR="$(cd "${INAV_DIR}" && pwd)"
INCLUDE_DIR="${SDK_ROOT}/include"
BUILD_DIR="${SDK_ROOT}/build/generator"

mkdir -p "${BUILD_DIR}"
export PYTHONPYCACHEPREFIX="${BUILD_DIR}/pycache"

echo "INAV directory: ${INAV_DIR}"
echo "- Syncing canonical MSP inputs into include/"
"${INCLUDE_DIR}/sync.sh" "${INAV_DIR}"

echo "- Collecting and parsing INAV defines"
python3 "${GENERATOR_DIR}/get_inav_defines.py" \
    --inav-root "${INAV_DIR}/src/main" \
    --output "${GENERATOR_DIR}/all_defines.h"
python3 "${GENERATOR_DIR}/bad_define_parse.py" \
    --input "${GENERATOR_DIR}/all_defines.h" \
    --output "${GENERATOR_DIR}/inav_defines.py" \
    "${VERBOSE_DEFINES[@]}"

echo "- Generating MSP enum and message headers"
python3 "${GENERATOR_DIR}/gen_all_enums.py" \
    "${INCLUDE_DIR}/inav_enums.json" \
    --schema "${INCLUDE_DIR}/msp_messages.json" \
    --include boxId_e \
    --out "${INCLUDE_DIR}/all_enums.h"
python3 "${GENERATOR_DIR}/gen_msp_header.py" \
    "${INCLUDE_DIR}/msp_messages.json" \
    --out "${INCLUDE_DIR}/msp_messages.h" \
    --needed-types "${BUILD_DIR}/needed_types.txt"

echo "- Checking generated Python"
python3 -m py_compile \
    "${GENERATOR_DIR}/get_inav_defines.py" \
    "${GENERATOR_DIR}/bad_define_parse.py" \
    "${GENERATOR_DIR}/gen_all_enums.py" \
    "${GENERATOR_DIR}/gen_msp_header.py" \
    "${GENERATOR_DIR}/inav_defines.py"
python3 -m unittest discover \
    --start-directory "${GENERATOR_DIR}" \
    --pattern "test_*.py"

echo "- Compiling public C/C++ headers"
CCACHE_DISABLE=1 gcc \
    -std=c11 \
    -Wall \
    -Wextra \
    -Werror \
    -I "${INCLUDE_DIR}" \
    "${GENERATOR_DIR}/test.c" \
    -o "${BUILD_DIR}/msp_header_c_test"
CCACHE_DISABLE=1 g++ \
    -std=c++17 \
    -Wall \
    -Wextra \
    -Werror \
    -I "${INCLUDE_DIR}" \
    "${GENERATOR_DIR}/test.cpp" \
    -o "${BUILD_DIR}/msp_header_demo"

echo "- Running public-header demo"
"${BUILD_DIR}/msp_header_c_test"
"${BUILD_DIR}/msp_header_demo"

echo "Done. Public generated files are in include/; test outputs are in build/generator/."
