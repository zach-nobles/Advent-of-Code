#!/bin/bash
set -e

# Run CMake and build the project
echo $'\n[BUILDING]'
cmake -B ../build .
echo $'\n[MAKING]'
cmake --build ../build

# Run the generated executable
../build/AdventOfCode
