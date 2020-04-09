cmake_minimum_required(VERSION 3.14)

add_library(
        ${PROJECT_NAME}Engine
        src/ArgumentParser.cpp include/Engine/ArgumentParser.hpp
)

target_include_directories(${PROJECT_NAME}Engine PRIVATE include/Engine)
