cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

#########################################################################################
# GLFW3
#########################################################################################
message(STATUS "Adding external library: GLFW3")
ExternalProject_Add(glfw3_external
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/glfw3
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glfw3
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF
        -DGLFW_BUILD_DOCS=OFF
        -DGLFW_BUILD_TESTS=OFF
        -DGLFW_BUILD_EXAMPLES=OFF)

#########################################################################################
# GLAD
#########################################################################################
message(STATUS "Adding external library: GLAD")
ExternalProject_Add(glad_external
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/glad
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glad
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DGLAD_INSTALL=ON
        -DGLAD_PROFILE="core"
        -DGLAD_API="gl=3.3"
        -DGLAD_SPEC="gl"
        -DGLAD_GENERATOR="c"
        -DGLAD_EXTENSIONS=""
        -DGLAD_REPRODUCIBLE=ON)

#########################################################################################
# SPDLOG
#########################################################################################
message(STATUS "Adding external library: SPDLOG")
ExternalProject_Add(spdlog_external
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/spdlog
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/spdlog
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DSPDLOG_INSTALL=ON
        -DSPDLOG_BUILD_SHARED=OFF
        -DSPDLOG_BUILD_TESTS=OFF
        -DSPDLOG_BUILD_EXAMPLE=OFF
        -DSPDLOG_FMT_EXTERNAL=ON
        -DSPDLOG_NO_EXCEPTIONS=ON)
