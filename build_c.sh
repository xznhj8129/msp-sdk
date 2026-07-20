#!/usr/bin/env bash
set -euo pipefail

SDK_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
exec "${SDK_ROOT}/generator/gen_all.sh" "$@"
