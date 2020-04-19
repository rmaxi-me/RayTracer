/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <random>

#include "Engine/Raylib.hpp"
#include "Engine/Ray/Ray.hpp"

#include "RayTracerApp.hpp"
#include "Materials/IMaterial.hpp"
#include "Objects/Object.hpp"
#include "Objects/ObjectList.hpp"
#include "Objects/Sphere.hpp"
#include "Scene/Scene.hpp"

RayTracerApp::RayTracerApp(int ac, char **av)
        : Application(ac, av)
{
}

void RayTracerApp::init()
{
    auto scene = Scene::fromFile(m_settings.filePath.c_str());

    m_list = scene.getObjectList();
}

void RayTracerApp::deinit()
{
}

void RayTracerApp::tick(float deltaTime)
{
    (void) deltaTime;
}

raymath::Vector3 colorize(const raylib::Ray &ray, const std::shared_ptr<ObjectList> &list)
{
    raylib::RayHitInfo info;
    std::shared_ptr<IMaterial> currentMaterial{nullptr};

    //check if any ray hit an object 0 and MAXFLOAT are value to stop the calcul if no object is found or an object is too close
    //When an obj is hit, RayHitInfo is Fill and the fct return True
    
    if (list->isHit(ray, 0.001f, std::numeric_limits<float>::max(), info, currentMaterial))
    {
        // if (currentMaterial == nullptr)
            // exit (1);
        auto reflectedRay = currentMaterial->compute(ray, info);
        if (reflectedRay.has_value())
            return reflectedRay->second * colorize(reflectedRay->first, list);
        else
            return raymath::Vector3();
    } else {
        raymath::Vector3 vecteurUnitaire = normalize(ray.getDirection());
        float t = 0.5f * (vecteurUnitaire.y() + 1.0f);
        return (1.0f - t) * raymath::Vector3(1.0, 1.0, 1.0) + t * raymath::Vector3(0.5, 0.7, 1.0);
    }
}

void RayTracerApp::draw()
{
    static const int nx = m_window->getWidth();
    static const int ny = m_window->getHeight();
    static const raymath::Vector3 l(-2, -1, -1);
    static const raymath::Vector3 h(4, 0, 0);
    static const raymath::Vector3 v(0, 3, 0);
    static const raymath::Vector3 o(0, 0, 0);

    static std::random_device rd;
    static std::mt19937 gen(rd());

    m_window->clear();

    BeginDrawing();
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            raymath::Vector3 col;
            //Begin AntiAliasing
            for (int k = 0; k < anti_aliasing; k++) {
                float Vu = (float) (i + std::generate_canonical<double, 10>(gen)) / (float) (nx);
                float Vv = (float) (j + std::generate_canonical<double, 10>(gen)) / (float) (ny);

                //Projection of the ray depending of the size of the screen
                raylib::Ray ray(o, l + Vu * h + Vv * v);
                col += colorize(ray, m_list);
            }
            col /= (float) anti_aliasing;
            // col*=255;
            // std::cout << (int)col.x() << " " << (int)col.y() << " " << (int)col.z() << std::endl;
            //End AntiAliasing
            DrawPixel(i, ny - j, Color{static_cast<unsigned char>(col.x() * 255),
                                       static_cast<unsigned char>(col.y() * 255),
                                       static_cast<unsigned char>(col.z() * 255), 255});
        }
    }
    // throw;
    EndDrawing();
    std::cout << "draw()" << std::endl;
}
