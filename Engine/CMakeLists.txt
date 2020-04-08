cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON 17)

add_library(
        ${PROJECT_NAME}Engine
        src/Temp.cpp include/Temp.hpp
)

target_include_directories(${PROJECT_NAME}Engine PRIVATE include)
