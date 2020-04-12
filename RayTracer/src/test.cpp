#include <iostream>
#include "Window/Window.hpp"
#include "Vector/Vector3.hpp"
#include "Ray/Ray.hpp"

raymath::Vector3 linearInterpolation(raylib::Ray ray)
{
    raymath::Vector3 vecteurUnitaire = normalize(ray.getDirection());
    
    //get a factor depending of the y direction of the ray (up/downess)
    //scale the unit vector to 0<x<1 from -1<x<1
    float t = 0.5*(vecteurUnitaire.y() + 1.0);

    //formula of the linear interpolarion got a gradient of color
    return (1.0f-t) * raymath::Vector3(0.0,1.0,1.0) + t*raymath::Vector3(1.0, 0.0, 1.0);
                            //blue green                        //purple
}

int main(int argc, char const *argv[])
{
    int nx = 800;
    int ny = 600;

    raylib::Window window(800, 600, "Test");

    window.changeClearColor(BLACK);

    raymath::Vector3 l(-2,-1,-1);
    raymath::Vector3 h(4,0,0);
    raymath::Vector3 v(0,2,0);
    raymath::Vector3 o(0,0,0);

    while(window.isOpen())
    {
        BeginDrawing();
        for (int j = ny-1; j >= 0; j--)
        {
            for (int i = 0; i < nx; i++)
            {
                float Vu = (float)i / (float)(nx);
                float Vv = (float)j / (float)(ny);

                //Projection of the ray depending of the size of the screen
                raylib::Ray ray(o, l+Vu*h+Vv*v);
                raymath::Vector3 col = linearInterpolation(ray);
                // raymath::Vector3 col(colo.x() * 255.99, colo.y() * 255.99, colo.z() * 255.99);
                // std::cout << col << std::endl;
                DrawPixel(i, j, Color{(int)(col.x() * 255.99), (int)(col.y() * 255.99), (int)(col.z() * 255.99), 255});
            }
        }
        EndDrawing();
        window.clear();
    }
    return 0;
}
