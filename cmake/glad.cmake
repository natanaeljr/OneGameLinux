cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

#########################################################################################
# GLAD
#########################################################################################
message(STATUS "GLAD external library")
set(GLAD_SOURCE_DIR "" CACHE STRING "GLAD source directory")
set(GLAD_PREFIX ${CMAKE_BINARY_DIR}/glad)

# Build settings
set(GLAD_PROFILE "core")
set(GLAD_API "gl=3.3")
set(GLAD_SPEC "gl")
set(GLAD_GENERATOR "c")
set(GLAD_EXTENSIONS "")
set(GLAD_REPRODUCIBLE ON)
set(GLAD_INSTALL ON)

# Configure and build
ExternalProject_Add(glad_external
    PREFIX ${GLAD_PREFIX}
    SOURCE_DIR ${GLAD_SOURCE_DIR}
    INSTALL_DIR ${GLAD_PREFIX}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GLAD_PREFIX} -DGLAD_INSTALL=${GLAD_INSTALL}
        -DGLAD_PROFILE=${GLAD_PROFILE}
        -DGLAD_API=${GLAD_API}
        -DGLAD_SPEC=${GLAD_SPEC}
        -DGLAD_GENERATOR=${GLAD_GENERATOR}
        -DGLAD_EXTENSIONS=${GLAD_EXTENSIONS}
        -DGLAD_REPRODUCIBLE=${GLAD_REPRODUCIBLE}
    UPDATE_COMMAND "")


# Export target
add_library(glad STATIC IMPORTED)
add_dependencies(glad glad_external)
file(MAKE_DIRECTORY ${GLAD_PREFIX}/include)
target_include_directories(glad INTERFACE ${GLAD_PREFIX}/include)
set_target_properties(glad PROPERTIES IMPORTED_LOCATION ${GLAD_PREFIX}/lib/libglad.a)
target_link_libraries(glad INTERFACE
    GL
    dl
    pthread
)
