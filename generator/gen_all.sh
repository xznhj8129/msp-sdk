#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
MSP_JSON="$ROOT/../docs/msp_messages.json"
SRC_DEFINES="$ROOT/../all_defines.h"

echo "[1/5] Syncing all_enums.h/all_defines.h..."
python3 "$ROOT/get_all_inav_enums_h.py" --inav-root "$ROOT/../../inav/src/main"
cp "$SRC_DEFINES" "$ROOT/all_defines.h"

echo "[2/5] Generating MSP structs header..."
python3 "$ROOT/gen_msp_header.py" "$MSP_JSON" -o "$ROOT/msp_messages.h"

echo "[4/5] Sanity compile..."
CCACHE_DISABLE=1 g++ -std=c++17 -Wall -Wextra -I "$ROOT/include" -I "$ROOT/../../inav/src/main" -o "$ROOT/demo_min" "$ROOT/test.cpp"

echo "[5/5] Running demo..."
./demo_min

echo "Done. Outputs: all_enums.h, msp_messages.h, msp_types.h, demo_min"
rm all_defines.h