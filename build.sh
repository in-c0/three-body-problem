#!/bin/bash

# Navigate to the build directory
cd build

# Remove all files in the build directory
rm -rf *

# Navigate back to the root directory
cd ..

# Run CMake to configure the build system
cmake -B build

# Compile the build files
cmake --build build

# Run the tests
cd build
ctest
cd ..