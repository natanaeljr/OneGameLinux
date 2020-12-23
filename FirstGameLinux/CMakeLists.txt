cmake_minimum_required(VERSION 3.5)
project(FirstGameLinux LANGUAGES CXX)

# This project can be built as a standalone project on a system with the required
# libraries already installed, or it can be part of the Super-Project which builds all
# dependencies with the correct versions.
# For building it separately with the dependency builds from the Super-Project,
# the variable `CMAKE_PREFIX_PATH` must be set to the Super-Project's build/external dir.
# In Linux you can do it as:
#  cmake .. -DCMAKE_PREFIX_PATH=$(realpath ../../build/external)

#########################################################################################
# Configuration
#########################################################################################
# Default build type to Debug, for release use `cmake -DCMAKE_BUILD_TYPE=Release ..`
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type default to Debug" FORCE)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Turn on when having trouble building
set(CMAKE_VERBOSE_MAKEFILE OFF)
# Compilation Database for C++ language servers
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# For OpenGL prefer new GL Vendor Neutral Dispatch (GLVND) rather than legacy
set(OpenGL_GL_PREFERENCE "GLVND")

# Default compilation settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb -pg -fsanitize=undefined -Werror -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

#########################################################################################
# Dependencies
#########################################################################################
# OpenGL for graphics library
find_package(OpenGL REQUIRED)
# GLAD for opengl function loader
find_package(glad 0.1.34 EXACT REQUIRED)
# GLFW for desktop windowing and input
find_package(glfw3 3.3.2 EXACT REQUIRED)
# ImGui for graphical user interface
find_package(imgui 1.79 EXACT REQUIRED)
# SPDLog for fast C++ logging library
find_package(spdlog 1.8.1 EXACT REQUIRED)
# GSL for types and functions of C++ Core Guidelines
find_package(Microsoft.GSL 3.1.0 EXACT REQUIRED)

#########################################################################################
# Project
#########################################################################################
set(FIRSTGAME_OPENGL_LOADER_GLAD ON CACHE BOOL "OpenGL Loader GLAD")
add_subdirectory(FirstGame)

# Main target binary
add_executable(main)
target_sources(main PRIVATE
    src/main.cpp
)
target_link_libraries(main PRIVATE
    FirstGame
    imgui::imgui
    imgui::imgui_glfw
    imgui::imgui_opengl
    glfw
    glad::glad
    OpenGL::GL
    Microsoft.GSL::GSL
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
target_compile_definitions(main PRIVATE SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE)
endif()

install(TARGETS main)
