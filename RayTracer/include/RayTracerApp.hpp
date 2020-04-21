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
#include "Objects/ObjectList.hpp"

class RayTracerApp : public Application {
public:
    static constexpr int m_anti_aliasing = 16;

    struct Pixel {
        int x;
        int y;
        raymath::Vector3 color;
    };

    struct FrameBuffer {
        int width;
        int height;
        std::vector<Pixel> pixels{};

        inline Pixel &operator[](const std::size_t &index)
        {
            return pixels[index];
        }

        inline const Pixel &operator[](const std::size_t &index) const
        {
            return pixels[index];
        }
    };

private:
    std::shared_ptr<ObjectList> m_list{};
    FrameBuffer m_frameBuffer{};

    void computePixelColor(Pixel &pixel);
    void computePixelRange(std::vector<Pixel> &pixels, size_t begin, size_t end);
public:
    RayTracerApp(int ac, char **av);

    void init() override;
    void deinit() override;
    void tick(float deltaTime) override;
    void draw() override;
};
