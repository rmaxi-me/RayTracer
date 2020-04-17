/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "RayTracerApp.hpp"

int main(int ac, char **av)
{
    RayTracerApp app(ac, av);

    app.start();
    return 0;
}
