cmake_minimum_required(VERSION 3.14)

add_executable(
        ${PROJECT_NAME}
        include/Objects/Object.hpp
        include/Objects/ObjectList.hpp
        src/Main.cpp include/Main.hpp
        src/RayTracerApp.cpp include/RayTracerApp.hpp
        src/Objects/Sphere.cpp include/Objects/Sphere.hpp
        src/RayTracerApp.cpp include/RayTracerApp.hpp
        src/Materials/IMaterial.cpp include/Materials/IMaterial.hpp
        src/Materials/Glass.cpp include/Materials/Glass.hpp
        src/Materials/VentaBlack.cpp include/Materials/VentaBlack.hpp)

if (UNIX)
    set(PTHREAD_LIB "pthread")
else ()
    set(PTHREAD_LIB "")
endif ()

target_include_directories(${PROJECT_NAME} PRIVATE include ../Engine/include)
target_link_libraries(${PROJECT_NAME} RayTracerEngine raylib ${PTHREAD_LIB})
