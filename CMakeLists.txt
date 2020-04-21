cmake_minimum_required(VERSION 3.14)
project(RayTracer VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_VERBOSE_MAKEFILE OFF) # Turn on to debug cmake/make

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON 17)

set(JSON_URL https://github.com/nlohmann/json/releases/download/v3.7.3/json.hpp)
set(JSON_TARGET ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/json/json.hpp)

if (NOT EXISTS ${JSON_TARGET})
    message(STATUS "Downloading JSON dependency")
    file(DOWNLOAD ${JSON_URL} ${JSON_TARGET})
    message(STATUS "Downloading JSON dependency -- done")
endif ()

set(OpenGL_GL_PREFERENCE LEGACY)
include(Dependencies/raygui/cmake/FindRaylib.cmake)

if (UNIX)
    add_compile_options(-Wall -Wextra -Weffc++)

    if (RAYTRACER_ERROR)
        add_compile_options(-Werror)
    endif ()
elseif (WIN32)
    add_compile_options(/wd4244 /wd4267)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(RAYTRACER_DEBUG=1)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_definitions(RAYTRACER_RELEASE=1)
endif ()

include_directories(Dependencies/json)
include_directories(Dependencies/raylib/src)
add_subdirectory(Engine)
add_subdirectory(RayTracer)

if (NOT APPLE)
    add_subdirectory(SceneEditor)
endif ()

if (RAYTRACER_TESTS)
    message(STATUS "Setting up tests")
    set(CMAKE_BUILD_TYPE Debug)

    add_subdirectory(Tests)

    message(STATUS "Setting up tests - done")
endif ()

file(COPY Resources DESTINATION ${CMAKE_BINARY_DIR})
message(STATUS "Resources files copied to ${CMAKE_BINARY_DIR}")

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
