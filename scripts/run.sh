#!/usr/bin/env bash
set -e
mkdir -p build
cd build
cmake ..
make
./node ${1:-8000}
