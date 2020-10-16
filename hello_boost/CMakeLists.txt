cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

add_executable(hello hello.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(hello
    PRIVATE Boost::boost
    PRIVATE Threads::Threads)
