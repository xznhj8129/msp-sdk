#!/usr/bin/env bash
# msp_sdk monorepo orchestration.
#
#   build_all.sh generate   Regenerate include/ from INAV and publish artifacts
#                           into arduinolib/ and pythonlib/.
#   build_all.sh test       Run generator-independent checks: C/C++ header
#                           compile + demos, Python unit tests.
#                           (--with-arduino also builds the Arduino example via
#                           PlatformIO.)
#   build_all.sh package    Build release artifacts into dist/.
#   build_all.sh release    generate + test + package.
#
# Common options (generate/release):
#   --inav-dir PATH     INAV checkout to generate from. Default: the
#                       SDK-managed clone at ./inav (see generator/sync_inav.sh).
#   --inav-repo URL     Remote for the managed clone
#                       (default: https://github.com/xznhj8129/inav.git)
#   --inav-branch NAME  Branch for the managed clone (default: mavlink_multiport2)
#   --update-inav       Refresh the managed clone from the remote first
#   --verbose-defines   Verbose define resolution diagnostics
set -euo pipefail

SDK_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
INAV_DIR_ARG=""
WITH_ARDUINO=0
GEN_EXTRA=()
SYNC_EXTRA=()

usage() {
    sed -n '2,20p' "${BASH_SOURCE[0]}"
    exit "${1:-0}"
}

COMMAND="${1:-}"
[[ -n "${COMMAND}" ]] || usage 1
case "${COMMAND}" in -h|--help) usage 0 ;; esac
shift

while (($#)); do
    case "$1" in
        --inav-dir) INAV_DIR_ARG="$2"; shift 2 ;;
        --inav-repo) SYNC_EXTRA+=(--repo "$2"); shift 2 ;;
        --inav-branch) SYNC_EXTRA+=(--branch "$2"); shift 2 ;;
        --update-inav) SYNC_EXTRA+=(--update); shift ;;
        --verbose-defines) GEN_EXTRA+=(--verbose-defines); shift ;;
        --with-arduino) WITH_ARDUINO=1; shift ;;
        *) echo "Unknown argument: $1" >&2; usage 1 ;;
    esac
done

GENERATOR_DIR="${SDK_ROOT}/generator"
INCLUDE_DIR="${SDK_ROOT}/include"
ARDUINO_DIR="${SDK_ROOT}/arduinolib"
PYTHON_DIR="${SDK_ROOT}/pythonlib"
BUILD_DIR="${SDK_ROOT}/build"
DIST_DIR="${SDK_ROOT}/dist"

# Headers the C/Arduino consumers need, staged from the canonical snapshot.
GENERATED_HEADERS=(
    all_enums.h
    msp_messages.h
    msp_protocol.h
    msp_protocol_v2_common.h
    msp_protocol_v2_inav.h
    msp_protocol_v2_sensor.h
    msp_protocol_v2_sensor_msg.h
    msp_stub_types.h
    msp_types.h
)

cmd_generate() {
    local inav_dir
    if [[ -n "${INAV_DIR_ARG}" ]]; then
        inav_dir="$(cd "${INAV_DIR_ARG}" && pwd)"
    else
        "${GENERATOR_DIR}/sync_inav.sh" ${SYNC_EXTRA[@]+"${SYNC_EXTRA[@]}"}
        inav_dir="${SDK_ROOT}/inav"
    fi
    "${GENERATOR_DIR}/gen_all.sh" --inav-dir "${inav_dir}" ${GEN_EXTRA[@]+"${GEN_EXTRA[@]}"}

    echo "- Publishing generated headers into arduinolib/src/generated/"
    mkdir -p "${ARDUINO_DIR}/src/generated"
    for header in "${GENERATED_HEADERS[@]}"; do
        cp "${INCLUDE_DIR}/${header}" "${ARDUINO_DIR}/src/generated/${header}"
    done

    echo "- Publishing Python data into pythonlib/src/mspapi2/lib/"
    local pylib="${PYTHON_DIR}/src/mspapi2/lib"
    mkdir -p "${pylib}"
    cp "${INCLUDE_DIR}/msp_messages.json" "${pylib}/msp_messages.json"
    cp "${INCLUDE_DIR}/inav_enums.json" "${pylib}/inav_enums.json"
    cp "${GENERATOR_DIR}/inav_defines.py" "${pylib}/inav_defines.py"

    local version_triplet major minor patch
    version_triplet="$(sed -nE 's/^[[:space:]]*project\([[:space:]]*INAV[[:space:]]+VERSION[[:space:]]+([0-9]+)\.([0-9]+)\.([0-9]+).*/\1 \2 \3/p' "${inav_dir}/CMakeLists.txt" | head -n 1)"
    read -r major minor patch <<< "${version_triplet}"
    if [[ -z "${major}" ]]; then
        echo "Failed to parse INAV version from ${inav_dir}/CMakeLists.txt" >&2
        exit 1
    fi
    cat > "${pylib}/inav_version.py" <<PY
VERSION = "${major}.${minor}.${patch}"
MAJOR = ${major}
MINOR = ${minor}
PATCH = ${patch}
PY
    echo "  INAV snapshot version: ${major}.${minor}.${patch}"
}

cmd_test() {
    mkdir -p "${BUILD_DIR}/generator"
    echo "- Compiling public C/C++ headers"
    CCACHE_DISABLE=1 gcc -std=c11 -Wall -Wextra -Werror \
        -I "${INCLUDE_DIR}" "${GENERATOR_DIR}/test.c" \
        -o "${BUILD_DIR}/generator/msp_header_c_test"
    CCACHE_DISABLE=1 g++ -std=c++17 -Wall -Wextra -Werror \
        -I "${INCLUDE_DIR}" "${GENERATOR_DIR}/test.cpp" \
        -o "${BUILD_DIR}/generator/msp_header_demo"
    "${BUILD_DIR}/generator/msp_header_c_test"
    "${BUILD_DIR}/generator/msp_header_demo"

    echo "- Running Python unit tests"
    PYTHONPATH="${PYTHON_DIR}/src" python3 -m unittest discover \
        --start-directory "${PYTHON_DIR}/tests" \
        --pattern "test_*.py"

    if [[ "${WITH_ARDUINO}" -eq 1 ]]; then
        echo "- Building Arduino example (PlatformIO)"
        command -v pio >/dev/null || { echo "pio not found in PATH" >&2; exit 1; }
        pio run --project-dir "${ARDUINO_DIR}/tests/esp32"
    fi
}

cmd_package() {
    mkdir -p "${DIST_DIR}"

    echo "- Building Python package"
    local venv="${BUILD_DIR}/packaging-venv"
    if [[ ! -x "${venv}/bin/python" ]]; then
        python3 -m venv "${venv}"
        "${venv}/bin/pip" install --quiet build
    fi
    (cd "${PYTHON_DIR}" && "${venv}/bin/python" -m build --outdir "${DIST_DIR}" .)

    echo "- Building Arduino library archive"
    local version
    version="$(sed -nE 's/^version=(.*)/\1/p' "${ARDUINO_DIR}/library.properties")"
    (cd "${SDK_ROOT}" && zip -qr "${DIST_DIR}/msp-sdk-arduino-${version}.zip" \
        arduinolib \
        -x "arduinolib/tests/esp32/.pio/*" "*/__pycache__/*")

    echo "Artifacts in ${DIST_DIR}:"
    ls -1 "${DIST_DIR}"
}

case "${COMMAND}" in
    generate) cmd_generate ;;
    test)     cmd_test ;;
    package)  cmd_package ;;
    release)  cmd_generate; cmd_test; cmd_package ;;
    *) echo "Unknown command: ${COMMAND}" >&2; usage 1 ;;
esac
