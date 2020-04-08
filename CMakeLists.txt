cmake_minimum_required(VERSION 3.14)
project(RayTracer VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_VERBOSE_MAKEFILE OFF) # Turn on to debug cmake/make

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON 17)

set(OpenGL_GL_PREFERENCE LEGACY)
add_subdirectory(Dependencies/raylib/projects/CMake)

if (UNIX)
    add_compile_options(-Wall -Wextra -Weffc++)

    if (RAYTRACER_ERROR)
        add_compile_options(-Werror)
    endif ()
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(RAYTRACER_DEBUG=1)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_definitions(RAYTRACER_RELEASE=1)
endif ()

add_subdirectory(Engine)
add_subdirectory(RayTracer)

if (RAYTRACER_TESTS)
    set(CMAKE_BUILD_TYPE Debug)
    add_subdirectory(Tests)
endif ()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
