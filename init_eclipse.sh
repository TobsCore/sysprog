#!/bin/bash
cwd=$(pwd)

rm -rf cmake-build-debug/
mkdir cmake-build-debug/
cd cmake-build-debug/
cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug $cwd/src/
