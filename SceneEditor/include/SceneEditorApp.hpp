/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "Engine/Application.hpp"

class SceneEditorApp : public Application {
private:
    Camera3D m_camera{};
public:
    SceneEditorApp(int ac, char **av);

    void init() override;
    void deinit() override;
    void tick(float deltaTime) override;
    void draw() override;
};
