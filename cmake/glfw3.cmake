cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

#########################################################################################
# GLFW3
#########################################################################################

message(STATUS "GLFW3 external library")
set(GLFW3_SOURCE_DIR "" CACHE STRING "GLFW3 source directory")
set(GLFW3_PREFIX ${CMAKE_BINARY_DIR}/glfw3 CACHE STRING "GLFW3 output prefix")

# Build settings
set(BUILD_SHARED_LIBS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_EXAMPLES OFF)

# Configure and build
ExternalProject_Add(glfw3_external
    PREFIX ${GLFW3_PREFIX}
    SOURCE_DIR ${GLFW3_SOURCE_DIR}
    INSTALL_DIR ${GLFW3_PREFIX}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GLFW3_PREFIX}
        -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}
        -DGLFW_BUILD_DOCS=${GLFW_BUILD_DOCS}
        -DGLFW_BUILD_TESTS=${GLFW_BUILD_TESTS}
        -DGLFW_BUILD_EXAMPLES=${GLFW_BUILD_EXAMPLES}
    UPDATE_COMMAND "")

# Export target
add_library(glfw3 STATIC IMPORTED)
add_dependencies(glfw3 glfw3_external)
file(MAKE_DIRECTORY ${GLFW3_PREFIX}/include)
target_include_directories(glfw3 INTERFACE ${GLFW3_PREFIX}/include)
set_target_properties(glfw3 PROPERTIES IMPORTED_LOCATION ${GLFW3_PREFIX}/lib/libglfw3.a)
target_link_libraries(glfw3 INTERFACE
    X11
    Xrandr
    Xinerama
    Xxf86vm
    Xcursor
)
target_compile_definitions(glfw3 INTERFACE -DGLFW_STATIC)
