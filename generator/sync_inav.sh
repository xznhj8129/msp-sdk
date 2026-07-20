#!/usr/bin/env bash
# Manage the SDK-local INAV checkout used as the generation input.
#
# The checkout is a build input owned by the SDK: it is cloned from the
# network into <sdk>/inav (untracked) and is safe to delete or re-clone at
# any time. To generate from your own INAV working copy instead, pass
# --inav-dir to build_all.sh / gen_all.sh and this script is not used.
#
# Usage:
#   generator/sync_inav.sh [--repo URL] [--branch NAME] [--dir PATH] [--update]
#
#   --repo URL     Remote to clone from   (default: https://github.com/xznhj8129/inav.git)
#   --branch NAME  Branch to check out    (default: mavlink_multiport2)
#   --dir PATH     Checkout location      (default: <sdk>/inav)
#   --update       Fetch the branch and hard-reset the checkout to it
#                  (destructive to any local changes in the managed clone)
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SDK_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"

INAV_REPO="https://github.com/xznhj8129/inav.git"
INAV_BRANCH="mavlink_multiport2"
INAV_DIR="${SDK_ROOT}/inav"
UPDATE=0

while (($#)); do
    case "$1" in
        --repo)   INAV_REPO="$2"; shift 2 ;;
        --branch) INAV_BRANCH="$2"; shift 2 ;;
        --dir)    INAV_DIR="$2"; shift 2 ;;
        --update) UPDATE=1; shift ;;
        -h|--help) sed -n '2,19p' "${BASH_SOURCE[0]}"; exit 0 ;;
        *) echo "Unknown argument: $1" >&2; exit 2 ;;
    esac
done

if [[ ! -d "${INAV_DIR}/.git" ]]; then
    if [[ -e "${INAV_DIR}" ]]; then
        echo "error: ${INAV_DIR} exists but is not a git checkout; move it away first" >&2
        exit 1
    fi
    echo "Cloning ${INAV_REPO} (branch ${INAV_BRANCH}) into ${INAV_DIR}"
    git clone --depth 1 --branch "${INAV_BRANCH}" "${INAV_REPO}" "${INAV_DIR}"
elif [[ "${UPDATE}" -eq 1 ]]; then
    echo "Updating ${INAV_DIR} to ${INAV_REPO} branch ${INAV_BRANCH}"
    git -C "${INAV_DIR}" fetch --depth 1 origin "${INAV_BRANCH}"
    git -C "${INAV_DIR}" checkout -q -B "${INAV_BRANCH}" FETCH_HEAD
    git -C "${INAV_DIR}" reset --hard -q
    git -C "${INAV_DIR}" clean -fdxq
else
    echo "Using existing checkout ${INAV_DIR} (pass --update to refresh from the remote)"
fi

commit="$(git -C "${INAV_DIR}" rev-parse --short HEAD)"
echo "INAV source: ${INAV_DIR} @ ${commit} (repo=${INAV_REPO} branch=${INAV_BRANCH})"
