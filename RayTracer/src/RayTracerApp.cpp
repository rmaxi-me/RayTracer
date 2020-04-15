/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <raylib.h>

#include "RayTracerApp.hpp"

RayTracerApp::RayTracerApp(int ac, char **av)
        : Application(ac, av)
{
}

void RayTracerApp::tick(float deltaTime)
{
    (void) deltaTime;
}

void RayTracerApp::draw()
{
    DrawRectangle(100, 100, 100, 100, RAYWHITE);
}
