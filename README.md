# cpp-sandbox
C++ Sandbox project

Quick setup for C++ apps. 
Includes boost and gtest.
Requires CMake.
Only tested on Linux.

## Generate
cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_EXPORT_COMPILE_COMMANDS=ON      

cmake -S . -B build/release -DCMAKE_BUILD_TYPE=RELEASE

## Build
cmake --build build/debug
cmake --build build/release

TODOs:
 - Test on Windows
