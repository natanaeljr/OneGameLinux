cmake_minimum_required(VERSION 3.10.2)
project(FirstGameLinux VERSION 0.1 LANGUAGES CXX)

#########################################################################################
# General
#########################################################################################
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb -pg -fsanitize=undefined -Werror -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(OpenGL_GL_PREFERENCE "GLVND")

#########################################################################################
# Dependencies
#########################################################################################
set(GLFW3_SOURCE_DIR "${CMAKE_SOURCE_DIR}/libs/glfw3" CACHE STRING "" FORCE)
include(cmake/glfw3.cmake)

set(GLAD_SOURCE_DIR "${CMAKE_SOURCE_DIR}/libs/glad" CACHE STRING "" FORCE)
include(cmake/glad.cmake)

#########################################################################################
# Project
#########################################################################################
add_executable(main)
target_sources(main PRIVATE
  src/main.cpp
)
target_link_libraries(main PRIVATE
  glfw3  
  glad
)
