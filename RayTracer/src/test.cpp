#include <iostream>
#include <vector>

#include "Window/Window.hpp"
#include "Vector/Vector3.hpp"
#include "Ray/Ray.hpp"
#include "Objects/Sphere.hpp"
#include "Objects/ObjectList.hpp"

raymath::Vector3 linearInterpolation(raylib::Ray ray, Object *list)
{
    raylib::RayHitInfo info;

    //check if any ray hit an object 0 and MAXFLOAT are value to stop the calcul if no object is found or an object is too close
    //When an obj is hit, RayHitInfo is Fill and the fct return True
    if (list->isHit(ray, 0.0f, MAXFLOAT, info))
    {
        raymath::Vector3 plop = 0.5f * raymath::Vector3(info.normal.x()+1, info.normal.y()+1, info.normal.z()+1);
        if (plop.z() > 1)
            return raymath::Vector3(plop.x(), plop.y(), 1.0f);
        return plop;
    }
    else
    {
        raymath::Vector3 vecteurUnitaire = normalize(ray.getDirection());
        float t = 0.5*(vecteurUnitaire.y() + 1.0);
        return (1.0f - t) * raymath::Vector3(1.0, 1.0, 1.0) + t * raymath::Vector3(0.5, 0.7, 1.0);
    }
}

int main(int argc, char const *argv[])
{
    int nx = 800;
    int ny = 600;

    raylib::Window window(nx, ny, "Test");

    window.changeClearColor(BLACK);

    raymath::Vector3 l(-2,-1.5,-1);
    raymath::Vector3 h(4,0,0);
    raymath::Vector3 v(0,3,0);
    raymath::Vector3 o(0,0,0);

    std::vector<Object *> obj;
    obj.push_back(new Sphere(raymath::Vector3(0, 0, -1), 0.5));
    Object *list = new ObjectList(obj);
    
    while(window.isOpen())
    {
        window.clear();
        BeginDrawing();

        for (int j = ny-1; j >= 0; j--)
        {
            for (int i = 0; i < nx; i++)
            {
                float Vu = (float)i / (float)(nx);
                float Vv = (float)j / (float)(ny);

                //Projection of the ray depending of the size of the screen
                raylib::Ray ray(o, l+Vu*h+Vv*v);

                raymath::Vector3 col = linearInterpolation(ray, list);
                DrawPixel(i, j, Color{(int)(col.x()*255.99), (int)(col.y()*255.99), (int)(col.z()*255), 255});
            }
        }
        EndDrawing();
    }
    return 0;
}