#!/bin/bash

# Clean previous build
rm -rf build

# Create build directory
mkdir build

# Enter build directory
cd build

cmake -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=../board/toolchain/toolchain.cmake ..

ninja
