#!/bin/bash
cwd=$(pwd)

cd ../
rm -rf build_sysprog/
mkdir build_sysprog/
cd build_sysprog/
cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug $cwd
