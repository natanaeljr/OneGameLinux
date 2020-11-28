cmake_minimum_required(VERSION 3.5)
project(FirstGameLinux LANGUAGES CXX)

#########################################################################################
# Configuration
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
find_package(OpenGL REQUIRED)
find_package(glad 0.1.34 EXACT REQUIRED)
find_package(glfw3 3.3.2 EXACT REQUIRED)
find_package(spdlog 1.8.1 EXACT REQUIRED)

#########################################################################################
# Project
#########################################################################################
add_executable(main)
target_sources(main PRIVATE
    src/main.cpp
)
target_link_libraries(main PRIVATE
    glfw
    glad::glad
    OpenGL::GL
)
install(TARGETS main)
