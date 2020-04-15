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

    m_camera.position = Vector3{20.0f, 20.0f, 20.0f};
    m_camera.target = Vector3{0.0f, 8.0f, 0.0f};
    m_camera.up = Vector3{0.0f, 1.f, 0.0f};
    m_camera.fovy = 45.0f;
    m_camera.type = CAMERA_PERSPECTIVE;
}

void RayTracerApp::tick(float deltaTime)
{
    constexpr float SPEED = 50.f;

    if (IsKeyDown(KEY_W))
        m_camera.position.z += SPEED * deltaTime;
    if (IsKeyDown(KEY_A))
        m_camera.position.x -= SPEED * deltaTime;
    if (IsKeyDown(KEY_S))
        m_camera.position.z -= SPEED * deltaTime;
    if (IsKeyDown(KEY_D))
        m_camera.position.x += SPEED * deltaTime;
    if (IsKeyDown(KEY_SPACE))
        m_camera.position.y += SPEED * deltaTime;
    if (IsKeyDown(KEY_C))
        m_camera.position.y -= SPEED * deltaTime;
}

void RayTracerApp::draw()
{
    BeginMode3D(m_camera);
    {
        DrawPlane({0, 0, 0}, {100, 100}, DARKGREEN);
        DrawModel(m_model->getRaylibModel(), {0, 0, -1}, 1, WHITE);
    }
    EndMode3D();
}

void RayTracerApp::deinit()
{

}
