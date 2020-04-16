#include <iostream>
#include <vector>
#include <limits>

#include "Engine/Window/Window.hpp"
#include "Engine/Vector/Vector3.hpp"
#include "Engine/Ray/Ray.hpp"
#include "Objects/Sphere.hpp"
#include "Objects/ObjectList.hpp"

//void do_work(int)
//{
//    using namespace std::chrono_literals;
//
//    static std::atomic<int> id = 0;
//    int this_id = ++id;
//
//    std::cout << this_id << " starting" << std::endl;
//    std::this_thread::sleep_for(1s);
//    std::cout << this_id << " done" << std::endl;
//}

raymath::Vector3 linearInterpolation(raylib::Ray ray, std::shared_ptr<Object> list)
{
    raylib::RayHitInfo info;

    //check if any ray hit an object 0 and MAXFLOAT are value to stop the calcul if no object is found or an object is too close
    //When an obj is hit, RayHitInfo is Fill and the fct return True
    if (list->isHit(ray, 0.0f, std::numeric_limits<float>::max(), info))
    {
        raymath::Vector3 plop = 0.5f * raymath::Vector3(info.normal.x() + 1, info.normal.y() + 1, info.normal.z() + 1);
        if (plop.z() > 1)
            return raymath::Vector3(plop.x(), plop.y(), 1.0f);
        return plop;
    }
    else
    {
        raymath::Vector3 vecteurUnitaire = normalize(ray.getDirection());
        float t = 0.5 * (vecteurUnitaire.y() + 1.0);
        return (1.0f - t) * raymath::Vector3(1.0, 1.0, 1.0) + t * raymath::Vector3(0.5, 0.7, 1.0);
    }
//     RayTracerApp app(ac, av);

//     app.start();

//    ThreadPool<void, int> tp(&do_work);
//    for (int i = 0; i < 100; ++i) {
//        tp.queueTask(1);
//    }
//    tp.runAndWait();
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    int nx = 800;
    int ny = 600;

    raylib::Window window(nx, ny, "Test");

    window.setClearColor(BLACK);

    raymath::Vector3 l(-2, -1.5, -1);
    raymath::Vector3 h(4, 0, 0);
    raymath::Vector3 v(0, 3, 0);
    raymath::Vector3 o(0, 0, 0);

    std::vector<std::shared_ptr<Object>> obj;
    obj.emplace_back(new Sphere(raymath::Vector3(0, 0, -1), 0.5));

    std::shared_ptr<Object> list = std::make_shared<ObjectList>(ObjectList(obj));

    while (window.isOpen())
    {
        window.clear();
        BeginDrawing();

        for (int j = ny - 1; j >= 0; j--)
        {
            for (int i = 0; i < nx; i++)
            {
                float Vu = (float)i / (float)(nx);
                float Vv = (float)j / (float)(ny);

                //Projection of the ray depending of the size of the screen
                raylib::Ray ray(o, l + Vu * h + Vv * v);

                raymath::Vector3 col = linearInterpolation(ray, list);
                DrawPixel(i, j, Color{static_cast<unsigned char>(col.x() * 255), static_cast<unsigned char>(col.y() * 255), static_cast<unsigned char>(col.z() * 255), 255});
            }
        }
        EndDrawing();
    }
    return 0;
}