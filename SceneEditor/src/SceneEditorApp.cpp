/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Raygui.hpp"
#include "SceneEditorApp.hpp"

SceneEditorApp::SceneEditorApp(int ac, char **av)
        : Application(ac, av, 1600, 900)
{
}

void SceneEditorApp::init()
{
    GuiLoadStyle("Resources/style.rgs");

    m_window->setClearColor(RAYWHITE);

    m_camera.type = CameraType::CAMERA_PERSPECTIVE;
    m_camera.position = {7.5, 7.5, 7.5};
    m_camera.fovy = 65;
    m_camera.target = {0, 0, 0};
    m_camera.up = {0, 1, 0};
    SetCameraMode(m_camera, CameraMode::CAMERA_ORBITAL);
//    SetCameraMoveControls(KEY_W, KEY_S, KEY_D, KEY_A, KEY_SPACE, KEY_C);
}

void SceneEditorApp::deinit()
{
}

void SceneEditorApp::tick(float)
{
    UpdateCamera(&m_camera);
}

void SceneEditorApp::draw()
{
    BeginMode3D(m_camera);
    {
        BeginShaderMode(GetShaderDefault());
        {
            DrawGrid(100, 1);
            DrawCube({0, 0, 0}, 5, 5, 5, GOLD);
        }
        EndShaderMode();
    }
    EndMode3D();

    GuiButton({100, 100, 100, 25}, "Click here!");
}
