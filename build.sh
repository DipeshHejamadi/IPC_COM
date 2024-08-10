#!/bin/bash

# Check if the build directory already exists
if [ -d "build" ]; then
    echo "Build directory already exists. Removing it..."
    rm -rf build
fi

# Create the build directory
mkdir build

# Change to the build directory
cd build

# Run CMake to configure the project
cmake ..

# Build the project
make

echo "Build process completed."
