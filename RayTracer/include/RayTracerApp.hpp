/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <memory>

#include "Engine/Application.hpp"
#include "Engine/Assets/Model.hpp"
#include "Engine/Assets/Texture.hpp"

class RayTracerApp : public Application {
private:
    std::unique_ptr<raylib::Model> m_model{nullptr};
    std::unique_ptr<raylib::Texture> m_texture{nullptr};

    Camera m_camera{};
public:
    RayTracerApp(int ac, char **av);

    void init() override;
    void deinit() override;

    void tick(float deltaTime) override;
    void draw() override;
};
