cmake_minimum_required(VERSION 3.14)

add_link_options(--coverage)
add_compile_options(--coverage)

add_executable(
        ${PROJECT_NAME}Tests
        src/TestsArgumentParser.cpp
        src/TestsVector2.cpp
        src/TestsVector3.cpp
)

target_include_directories(${PROJECT_NAME}Tests PRIVATE include ../Engine/include)
target_link_libraries(${PROJECT_NAME}Tests ${PROJECT_NAME}Engine criterion)
