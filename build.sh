#!/bin/bash

# Exit if any command fails
set -e

# Configuration
BUILD_DIR="build"
EXEC="tp04"

echo "Building Parachute project with ..."

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

cmake .. 

make 

echo "Build complete. Executable is : $BUILD_DIR/$EXEC"
