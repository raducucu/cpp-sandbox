include(ExternalProject)

# set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  # SOURCE_DIR        "${CMAKE_BINARY_DIR}/googletest-src"
  # BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
  # CONFIGURE_COMMAND ""
  # BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
  BUILD_IN_SOURCE 1
)
ExternalProject_Get_Property(googletest SOURCE_DIR)
ExternalProject_Get_Property(googletest BINARY_DIR)

message(STATUS "${SOURCE_DIR} ${BINARY_DIR}")

add_library(_gtest INTERFACE)
target_include_directories(_gtest SYSTEM INTERFACE "${SOURCE_DIR}/googletest/include/")
# target_link_libraries(_gtest INTERFACE "${SOURCE_DIR}/lib/libgtest.a" "${SOURCE_DIR}/lib/libgtest_main.a" )
target_link_libraries(_gtest INTERFACE "${SOURCE_DIR}/lib/libgtest.a")
# add_dependencies(_gtest Threads::Threads)
add_dependencies(_gtest googletest)

add_library(gtest::gtest ALIAS _gtest)


