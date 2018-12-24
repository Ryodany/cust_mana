#!/bin/bash
rm -rf build && mkdir build && cd build
CC="gcc34"
CXX="gcc34"
cmake ../gcc34_c++98_cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER="/usr/bin/gcc34" -DCMAKE_CXX_COMPILER="/usr/bin/g++34"
cmake --build . --config Release
