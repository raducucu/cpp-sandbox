cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(BoostPlayground)

add_subdirectory(boost)
add_subdirectory(gtest)

add_subdirectory(hello_gtest)
add_subdirectory(hello_boost)
