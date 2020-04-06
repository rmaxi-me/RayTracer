cmake_minimum_required(VERSION 3.14)
project(RayTracerClient VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON 17)

add_executable(
        ${PROJECT_NAME}
        src/Main.cpp include/Main.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} RayTracerEngine raylib)
