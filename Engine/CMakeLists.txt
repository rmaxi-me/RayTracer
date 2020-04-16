cmake_minimum_required(VERSION 3.14)

add_library(
        ${PROJECT_NAME}Engine
        include/Engine/Raylib.hpp include/Engine/Raymath.hpp
        src/Ray/Ray.cpp include/Engine/Ray/Ray.hpp
        src/Application.cpp include/Engine/Application.hpp
        src/ArgumentParser.cpp include/Engine/ArgumentParser.hpp
        src/Window/Window.cpp include/Engine/Window/Window.hpp
        src/Vector/Vector2.cpp include/Engine/Vector/Vector2.hpp
        src/Vector/Vector3.cpp include/Engine/Vector/Vector3.hpp
        src/Assets/Mesh.cpp include/Engine/Assets/Mesh.hpp
        src/Assets/Image.cpp include/Engine/Assets/Image.hpp
        src/Assets/Model.cpp include/Engine/Assets/Model.hpp
        src/Assets/Texture.cpp include/Engine/Assets/Texture.hpp
        src/Assets/Material.cpp include/Engine/Assets/Material.hpp
        include/Engine/ThreadPool.hpp include/Engine/OS.hpp)

target_include_directories(${PROJECT_NAME}Engine PRIVATE include)
