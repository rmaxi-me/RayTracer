cmake_minimum_required(VERSION 3.14)

add_executable(
        ${PROJECT_NAME}
        src/Scene/Scene.cpp include/Scene/Scene.hpp
        src/Main.cpp
        src/RayTracerApp.cpp include/RayTracerApp.hpp
        include/Objects/ObjectList.hpp
        src/Objects/Object.cpp include/Objects/Object.hpp
        src/Objects/Sphere.cpp include/Objects/Sphere.hpp
        src/RayTracerApp.cpp include/RayTracerApp.hpp
        src/Materials/AMaterial.cpp include/Materials/AMaterial.hpp
        src/Materials/Glass.cpp include/Materials/Glass.hpp
        src/Materials/VentaBlack.cpp include/Materials/VentaBlack.hpp
        src/Materials/Normal.cpp include/Materials/Normal.hpp
        src/Materials/Metal.cpp include/Materials/Metal.hpp
        src/Materials/Light.cpp include/Materials/Light.hpp
        src/Camera/Camera.cpp include/Camera/Camera.hpp
)

if (UNIX)
    set(PTHREAD_LIB "pthread")
else ()
    set(PTHREAD_LIB "")
endif ()

target_include_directories(${PROJECT_NAME} PRIVATE include ../Engine/include)
target_link_libraries(${PROJECT_NAME} RayTracerEngine raylib ${PTHREAD_LIB})

if (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} stdc++fs)
endif ()
