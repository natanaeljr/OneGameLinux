cmake_minimum_required(VERSION 3.5)
project(FirstGameLinux)

#########################################################################################
# Configuration
#########################################################################################
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type default to Debug")

#########################################################################################
# Dependencies
#########################################################################################
include(ExternalProject)
add_subdirectory(external)
list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/external")

#########################################################################################
# Project
#########################################################################################
message(STATUS "Adding sub-project: FirstGameLinux")
ExternalProject_Add(FirstGameLinux
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/FirstGameLinux
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/FirstGameLinux
    CMAKE_ARGS
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}
    DEPENDS
        glad_external
        glfw3_external
        spdlog_external)
