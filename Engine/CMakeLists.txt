cmake_minimum_required(VERSION 3.14)

add_library(
        ${PROJECT_NAME}Engine
        include/Engine/Raymath.hpp
        src/ArgumentParser.cpp include/Engine/ArgumentParser.hpp
        src/Application.cpp include/Engine/Application.hpp
        src/Vector/Vector2.cpp include/Engine/Vector/Vector2.hpp
        src/Vector/Vector3.cpp include/Engine/Vector/Vector3.hpp
        src/Window/Window.cpp include/Engine/Window/Window.hpp
        src/Assets/Image.cpp include/Engine/Assets/Image.hpp
        src/Assets/Texture.cpp include/Engine/Assets/Texture.hpp
)

target_include_directories(${PROJECT_NAME}Engine PRIVATE include/Engine)
