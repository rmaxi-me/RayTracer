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
#include "Objects/Object.hpp"

class RayTracerApp : public Application {
private:
    std::shared_ptr<Object> m_list{};

    int anti_aliasing = 2;
public:
    RayTracerApp(int ac, char **av);

    void init() override;
    void deinit() override;
    void tick(float deltaTime) override;
    void draw() override;
};
