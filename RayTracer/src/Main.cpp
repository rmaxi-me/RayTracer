/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "RayTracerApp.hpp"
#include "Engine/ThreadPool.hpp"

void do_work(int)
{
    using namespace std::chrono_literals;

    static std::atomic<int> id = 0;
    int this_id = ++id;

    std::cout << this_id << " starting" << std::endl;
    std::this_thread::sleep_for(1s);
    std::cout << this_id << " done" << std::endl;
}

int main(int ac, char **av)
{
    RayTracerApp app(ac, av);

//    app.start();

    ThreadPool<void, int> tp(&do_work);

    for (int i = 0; i < 1000; ++i) {
        tp.queueTask(1);
    }

    tp.run();
}
