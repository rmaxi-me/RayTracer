#include <iostream>
#include "Window/Window.hpp"
#include "Vector/Vector3.hpp"
#include "Ray/Ray.hpp"

int hitSphere(const raymath::Vector3& center, float Radius, const raylib::Ray &r)
{
    // equation is : t^2 dot(B,B) + 2t dot(B,A-C) + dot(A-C, A-C)-R^2
    // form of ax^2 + bx + c = 0
    // where a = dot(B,B)
    //       b = 2dot(B, A-C)
    //       c = dot(A-C, A-C)-R^2
    raymath::Vector3 oc = r.getOrigin() - center;
    float a = raymath::dotProduct(r.getDirection(), r.getDirection());
    float b = 2.0f * raymath::dotProduct(oc, r.getDirection());
    float c = raymath::dotProduct(oc, oc) - Radius*Radius;
    float discriminant = b*b - 4*a*c;
    return discriminant > 0;
}

raymath::Vector3 linearInterpolation(raylib::Ray ray)
{
    if (hitSphere(raymath::Vector3(0,0,-1), 0.5f, ray))
        return raymath::Vector3(1,0,0);

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

    raylib::Window window(nx, ny, "Test");

    window.changeClearColor(BLACK);

    raymath::Vector3 l(-2,-1,-1);
    raymath::Vector3 h(4,0,0);
    raymath::Vector3 v(0,3,0);
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
                DrawPixel(i, j, Color{(int)(col.x() * 255.99), (int)(col.y() * 255.99), (int)(col.z() * 255.99), 255});
            }
        }
        EndDrawing();
        window.clear();
    }
    return 0;
}
