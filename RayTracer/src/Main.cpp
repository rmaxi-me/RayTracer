
#include <raylib.h>
#include <iostream>
#include <chrono>

#include "Main.hpp"

using namespace std::chrono_literals;

int main()
{
    InitWindow(1600, 900, "Raylib tests");

    auto before = std::chrono::system_clock::now();
    int frameCount = 0;

    while (!WindowShouldClose()) {
        ClearBackground(Color{0, 0, 0, 255});
        BeginDrawing();
        EndDrawing();

        auto now = std::chrono::system_clock::now();

        if (std::chrono::duration_cast<std::chrono::seconds>(now - before) >= 1s) {
            std::cout << frameCount << " fps" << std::endl;
            before = now;
            frameCount = 0;
        } else {
            ++frameCount;
        }
    }
    return 0;
}
