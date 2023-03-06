#!/usr/bin/env bash

#  
# This script is developed to build project structure as follows:
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

echo "Build Started"

SCRIPT_DIR="$(dirname "$(realpath "$0")")"
PROJECT_DIR="$(dirname "${SCRIPT_DIR}")"
BUILD_DIR="${PROJECT_DIR}/build"
echo "SCRIPT_DIR: ${SCRIPT_DIR}"
echo "PROJECT_DIR: ${PROJECT_DIR}"
echo "BUILD_DIR: ${BUILD_DIR}"

mkdir -p "${BUILD_DIR}"

cmake -S "${PROJECT_DIR}" -B "${BUILD_DIR}" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake --build ${BUILD_DIR} -j4

# Run tests
cd ${BUILD_DIR}
GTEST_COLOR=1 ctest --verbose

echo "Build Finished"

