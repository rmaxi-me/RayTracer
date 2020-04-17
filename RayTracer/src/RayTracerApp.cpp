/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Raylib.hpp"
#include "Engine/Ray/Ray.hpp"

#include "RayTracerApp.hpp"
#include "Objects/Object.hpp"
#include "Objects/ObjectList.hpp"
#include "Objects/Sphere.hpp"

RayTracerApp::RayTracerApp(int ac, char **av)
        : Application(ac, av)
{
}

void RayTracerApp::init()
{
    std::vector<std::shared_ptr<Object>> obj;
    obj.push_back(std::make_shared<Sphere>(raymath::Vector3(0, 0, -1), 0.5));

    m_list = std::make_shared<ObjectList>(ObjectList(obj));
}

void RayTracerApp::deinit()
{
}

void RayTracerApp::tick(float deltaTime)
{
    (void) deltaTime;
}

raymath::Vector3 linearInterpolation(const raylib::Ray &ray, const std::shared_ptr<Object> &list)
{
    raylib::RayHitInfo info;

    //check if any ray hit an object 0 and MAXFLOAT are value to stop the calcul if no object is found or an object is too close
    //When an obj is hit, RayHitInfo is Fill and the fct return True
    if (list->isHit(ray, 0.0f, std::numeric_limits<float>::max(), info)) {
        raymath::Vector3 plop = 0.5f * raymath::Vector3(info.normal.x() + 1, info.normal.y() + 1, info.normal.z() + 1);
        if (plop.z() > 1)
            return raymath::Vector3(plop.x(), plop.y(), 1.0f);
        return plop;
    } else {
        raymath::Vector3 vecteurUnitaire = normalize(ray.getDirection());
        float t = 0.5f * (vecteurUnitaire.y() + 1.0f);
        return (1.0f - t) * raymath::Vector3(1.0, 1.0, 1.0) + t * raymath::Vector3(0.5, 0.7, 1.0);
    }
}

void RayTracerApp::draw()
{
    const int nx = m_window->getWidth();
    const int ny = m_window->getHeight();
    const raymath::Vector3 l(-2, -1.5, -1);
    const raymath::Vector3 h(4, 0, 0);
    const raymath::Vector3 v(0, 3, 0);
    const raymath::Vector3 o(0, 0, 0);

    m_window->clear();
    BeginDrawing();
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            float Vu = (float) i / (float) (nx);
            float Vv = (float) j / (float) (ny);

            //Projection of the ray depending of the size of the screen
            raylib::Ray ray(o, l + Vu * h + Vv * v);

            raymath::Vector3 col = linearInterpolation(ray, m_list);
            DrawPixel(i, j, Color{static_cast<unsigned char>(col.x() * 255),
                                  static_cast<unsigned char>(col.y() * 255),
                                  static_cast<unsigned char>(col.z() * 255),
                                  255});
        }
    }
    EndDrawing();
}
