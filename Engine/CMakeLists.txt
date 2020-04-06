cmake_minimum_required(VERSION 3.14)
project(RayTracerEngine VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON 17)

add_library(
        ${PROJECT_NAME}
        src/Temp.cpp include/Temp.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
