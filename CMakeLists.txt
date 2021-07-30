cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(sandbox)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (BOOST_RELEASE "1.76.0")

add_compile_options(
  -Wall
  -Wextra
  -Wconversion
  -Wsign-conversion
  $<$<CONFIG:DEBUG>:-g3>
  $<$<CONFIG:DEBUG>:-Og>
  $<$<CONFIG:RELEASE>:-O3>
)

add_executable(sandbox hello_gtest.cpp)

add_subdirectory(boost)
add_subdirectory(gtest)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(sandbox
    PRIVATE Boost::boost
    PRIVATE gtest::gtest
    PRIVATE Threads::Threads
    )
