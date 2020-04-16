cmake_minimum_required(VERSION 3.14)

add_executable(
        ${PROJECT_NAME}
        src/Main.cpp include/Main.hpp
        src/RayTracerApp.cpp include/RayTracerApp.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include ../Engine/include)
target_link_libraries(${PROJECT_NAME} RayTracerEngine raylib pthread)
