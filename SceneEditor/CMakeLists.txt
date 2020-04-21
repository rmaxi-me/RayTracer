cmake_minimum_required(VERSION 3.14)

add_executable(
        ${PROJECT_NAME}Editor
        src/Main.cpp
        src/SceneEditorApp.cpp include/SceneEditorApp.hpp
        include/Raygui.hpp)

target_include_directories(${PROJECT_NAME}Editor PRIVATE include ../Engine/include ../Dependencies/raygui/src)
target_link_libraries(${PROJECT_NAME}Editor RayTracerEngine raylib)
