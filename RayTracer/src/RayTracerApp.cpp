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

void RayTracerApp::init()
{
    m_model = std::make_unique<raylib::Model>("Resources/church.obj");
    m_texture = std::make_unique<raylib::Texture>("Resources/church_diffuse.png");

    m_model->attachTexture(m_texture->getRaylibTexture());
}

void RayTracerApp::tick(float deltaTime)
{
    (void) deltaTime;
}

void RayTracerApp::draw()
{
    Camera camera = {};
    camera.position = (Vector3) {20.0f, 20.0f, 20.0f};  // Camera position
    camera.target = (Vector3) {0.0f, 8.0f, 0.0f};       // Camera looking at point
    camera.up = (Vector3) {0.0f, 1.6f, 0.0f};           // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.type = CAMERA_PERSPECTIVE;                   // Camera mode type

    BeginMode3D(camera);
    DrawRectangle(100, 100, 100, 100, RAYWHITE);
    DrawModel(m_model->getRaylibModel(), {0, 0, -1}, 1, WHITE);
    EndMode3D();
}

void RayTracerApp::deinit()
{

}
