#include <iostream>
#include <vector>
#include "Window/Window.hpp"
#include "Vector/Vector3.hpp"
#include "Ray/Ray.hpp"
#include "Objects/Sphere.hpp"

class hitable_list : public Object
{
public:
    hitable_list() {}
    hitable_list(std::vector<Object *> obj) : list(obj) {}
    virtual bool isHit(const raylib::Ray &r, float t_min, float t_max, raylib::RayHitInfo &rec)
    {
        raylib::RayHitInfo temp_rec;
        bool hit_anything = false;
        double closest_so_far = t_max;
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i]->isHit(r, t_min, closest_so_far, temp_rec))
            {
                // std::cout << list.size() << std::endl;

                hit_anything = true;
                closest_so_far = temp_rec.distance;
                rec = temp_rec;
            }
        }
        return hit_anything;
    }
    std::vector <Object *> list;
};

raymath::Vector3 linearInterpolation(raylib::Ray ray, Object *list)
{
    raylib::RayHitInfo info;
    if (list->isHit(ray, 0.0, MAXFLOAT, info))
    {
        raymath::Vector3 plop = 0.5f * raymath::Vector3(info.normal.x() + 1, info.normal.y() + 1, info.normal.z() + 1);
        plop *= 255.99;
        // std::cout << (int)plop.x() << " " << (int)plop.y() << " " << (int)plop.z() << std::endl;
        return  plop;
    }
    else
    {
        raymath::Vector3 vecteurUnitaire = normalize(ray.getDirection());
        float t = 0.5*(vecteurUnitaire.y() + 1.0);
        raymath::Vector3 plop = (1.0f - t) * raymath::Vector3(1.0, 1.0, 1.0) + t * raymath::Vector3(0.5, 0.7, 1.0);
        plop *= 255.99;
        // std::cout << (int)plop.x() << " " << (int)plop.y() << " " << (int)plop.z() << std::endl;
        // std::cout << 255 << " " << 255 << " " << 255 << std::endl;
        return raymath::Vector3(255, 255, 255);
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
    // obj.push_back(new Sphere(raymath::Vector3(0, 1.5, -1), 1));
    Object *list = new hitable_list(obj);
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
                DrawRectangle(i, j, 1, 1, Color{(int)(col.x()), (int)(col.y()), (int)(col.z()), 255});
                // DrawPixel(i, j, Color{(int)(col.x()), (int)(col.y()), (int)(col.z()), 255});
            }
        }
        EndDrawing();
    }
    return 0;
}
