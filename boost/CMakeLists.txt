include(ExternalProject)

SET(BOOST_ARCHIVE "boost_1_72_0.tar.gz")
message(STATUS "${BOOST_ARCHIVE}")

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/${BOOST_ARCHIVE}")
    set(BOOST_URL "file://${CMAKE_CURRENT_LIST_DIR}/${BOOST_ARCHIVE}")
else()
    string(REGEX MATCH "boost_([0-9]+)_([0-9]+)_([0-9]).tar.gz" _ ${BOOST_ARCHIVE})
    set(BOOST_URL "https://dl.bintray.com/boostorg/release/${CMAKE_MATCH_1}.${CMAKE_MATCH_2}.${CMAKE_MATCH_3}/source/${BOOST_ARCHIVE}")
endif()
message(STATUS "Using boost url: ${BOOST_URL}")

ExternalProject_Add(libboost_EP
    URL ${BOOST_URL}
    DOWNLOAD_DIR ${CMAKE_CURRENT_LIST_DIR}
    CONFIGURE_COMMAND <SOURCE_DIR>/bootstrap.sh --prefix=<INSTALL_DIR>
    BUILD_COMMAND <BINARY_DIR>/b2 --prefix=<INSTALL_DIR> headers
    INSTALL_COMMAND ""
    BUILD_IN_SOURCE 1
    )

ExternalProject_Get_Property(libboost_EP SOURCE_DIR)

add_library(_boost INTERFACE)
target_include_directories(_boost SYSTEM INTERFACE "${SOURCE_DIR}")
target_compile_definitions(_boost
    INTERFACE BOOST_SYSTEM_NO_DEPRECATED
    INTERFACE BOOST_ASIO_NO_DEPRECATED
)
add_dependencies(_boost  libboost_EP)
add_library(Boost::boost ALIAS _boost)
