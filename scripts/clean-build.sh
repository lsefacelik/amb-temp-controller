#!/usr/bin/env bash

#  
# This script is developed to clean project structure as follows:
#
# project
# ├── build
# ├── ... 
# ├── ...
# ├── ...
# ├── scripts
# │   ├── build.sh
# │   └── clean-build.sh
# ├── src
# │   ├── CMakeLists.txt
# │   └── multiply_test.cpp
# └── CMakeLists.txt
#
# !!! Please make necessary changes in case of structure differences 
#

set -euo pipefail

echo "Clean Started"

SCRIPT_DIR="$(dirname "$(realpath "$0")")"
PROJECT_DIR="$(dirname "${SCRIPT_DIR}")"
BUILD_DIR="${PROJECT_DIR}/build"
echo "Cleaning BUILD_DIR: ${BUILD_DIR}"

rm -rf "${BUILD_DIR}"

echo "Clean Finished"