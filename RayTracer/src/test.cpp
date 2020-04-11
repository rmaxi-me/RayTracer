#include <iostream>
#include "Window/Window.hpp"
#include "Vector/Vector3.hpp"


int main(int argc, char const *argv[])
{
    int nx = 800;
    int ny = 600;

    Window window(800, 600, "Test");

    window.changeClearColor(BLACK);
    while(window.isOpen())
    {
        BeginDrawing();
        for (int j = ny-1; j >= 0; j--)
        {
            for (int i = 0; i < nx; i++)
            {
                raymath::Vector3 col(float(i) / float(nx) * 255.99, float(j) / float(ny) * 255.99, 0.2 * 255.99);
                // std::cout << (int)col.x() << " " << (int)col.y() << " " << (int)col.z() << std::endl;
                DrawPixel(i, j, Color{(int)col.x(), (int)col.y(), (int)col.z(), 255});
            }
        }
        EndDrawing();
        window.clear();
    }
    return 0;
}
