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
elseif (WINDOWS)
    add_compile_options(/p:WarningLevel=1)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(RAYTRACER_DEBUG=1)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_definitions(RAYTRACER_RELEASE=1)
endif ()

include_directories(Dependencies/raylib/src)
add_subdirectory(Engine)
add_subdirectory(RayTracer)

if (RAYTRACER_TESTS)
    message(STATUS "Setting up tests")
    set(CMAKE_BUILD_TYPE Debug)

    #    add_subdirectory(Tests)

    message(STATUS "Setting up tests - done")
endif ()

set_target_properties(example PROPERTIES EXCLUDE_FROM_ALL 1 EXCLUDE_FROM_DEFAULT_BUILD 1)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
