#!/usr/bin/env bash

rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
cmake --build . --target run_all