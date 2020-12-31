cmake_minimum_required(VERSION 3.5)
include(ExternalProject)

#########################################################################################
# GLFW3
#########################################################################################
# GLFW is multi-platform library for OpenGL, OpenGL ES and Vulkan development on desktop.
# Provides an API for creating windows, contexts and surfaces, receiving input and events.
# GLFW is licensed under the zlib/libpng license.
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
# Multi-Language GL/GLES/EGL/GLX/WGL Loader-Generator based on the official specs.
# GLAD is licensed under the MIT license.
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
# glbinding
#########################################################################################
# glbinding is a cross-platform C++ binding for the OpenGL API.
# glbinding leverages C++11 features like enum classes, lambdas, and variadic templates,
# instead of relying on macros.
# glbinding is licensed under the MIT license.
message(STATUS "Adding external library: glbinding")
ExternalProject_Add(glbinding_external
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/glbinding
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glbinding
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF
        -DOPTION_BUILD_TOOLS=OFF
        -DOPTION_BUILD_EXAMPLES=OFF
        -DOPTION_SELF_CONTAINED=ON
        -DOPTION_BUILD_OWN_KHR_HEADERS=ON)

#########################################################################################
# SPDLOG
#########################################################################################
# SPDLog is very fast, header-only or compiled, C++ logging library.
# SPDLog is licensed under the MIT license.
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
        -DSPDLOG_FMT_EXTERNAL=OFF
        -DSPDLOG_NO_EXCEPTIONS=ON)

#########################################################################################
# STB
#########################################################################################
# stb single-file public domain libraries for C/C++
# stb is licensed under the MIT license and Public Domain.
message(STATUS "Adding external library: STB")
ExternalProject_Add(stb_external
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/stb
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/stb
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DSTB_IMAGE=ON)

#########################################################################################
# Assimp
#########################################################################################
# Assimp is a library to import and export various 3d-model-formats including
# scene-post-processing to generate missing render data.
# Assimp is lisenced under modified 3-clause BSD License.
message(STATUS "Adding external library: Assimp")
ExternalProject_Add(assimp_external
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/assimp
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assimp
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF
        -DASSIMP_BUILD_ZLIB=ON
        -DASSIMP_BUILD_TESTS=OFF
        -DASSIMP_BUILD_ASSIMP_TOOLS=OFF)

#########################################################################################
# GLM
#########################################################################################
# OpenGL Mathematics (GLM) is a header only C++ mathematics library for
# graphics software based on the OpenGL Shading Language (GLSL) specifications.
# GLM is licensed under The Happy Bunny License (Modified MIT License) or MIT License.
message(STATUS "Adding external library: GLM")
ExternalProject_Add(glm_external
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/glm
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glm
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=OFF
        -DBUILD_STATIC_LIBS=ON
        -DGLM_TEST_ENABLE=OFF)

#########################################################################################
# ImGui
#########################################################################################
# Dear ImGui is a bloat-free graphical user interface library for C++.
# It outputs optimized vertex buffers that you can render anytime in your 3D-pipeline
# enabled application. It is fast, portable, renderer agnostic and self-contained.
# Dear ImGui is licensed under the MIT License.
message(STATUS "Adding external library: ImGui")
ExternalProject_Add(imgui_external
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/imgui
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
        -DBUILD_SHARED_LIBS=OFF
        -DIMGUI_PLATF_BACKEND=glfw
        -DIMGUI_RENDER_BACKEND=opengl
        -DIMGUI_OPENGL_LOADER=glbinding3
    DEPENDS
        glfw3_external
        glbinding_external)

#########################################################################################
# GSL
#########################################################################################
# The Guidelines Support Library (GSL) contains functions and types that are suggested
# for use by the C++ Core Guidelines maintained by the Standard C++ Foundation.
# This repo contains Microsoft's implementation of GSL.
# Microsoft GSL is licensed under the MIT License.
message(STATUS "Adding external library: GSL")
ExternalProject_Add(gsl_external
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gsl
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gsl
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
        -DBUILD_SHARED_LIBS=OFF
        -DGSL_TEST=OFF)

#########################################################################################
# EnTT
#########################################################################################
# EnTT is a header-only, tiny and easy to use library for game programming written in
# modern C++, mainly known for its innovative entity-component-system (ECS) model.
# EnTT is licensed under the MIT License.
message(STATUS "Adding external library: EnTT")
ExternalProject_Add(entt_external
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/entt
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/entt
    INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
        -DCMAKE_GENERATOR=${CMAKE_GENERATOR}
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
        -DBUILD_SHARED_LIBS=OFF
        -DBUILD_TESTING=OFF)
