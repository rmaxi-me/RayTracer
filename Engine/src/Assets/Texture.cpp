/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Assets/Texture.hpp"

raylib::Texture::Texture(::Texture texture)
        : m_raylibTexture{texture}
{

}

raylib::Texture::Texture(const char *filename)
        : m_raylibTexture{LoadTexture(filename)}
{
}

raylib::Texture::Texture(const raylib::Image &image)
        : m_raylibTexture{LoadTextureFromImage(image.getRaylibImage())}
{
}

raylib::Texture::~Texture()
{
    UnloadTexture(m_raylibTexture);
}

raylib::RenderTexture::RenderTexture(int width, int height)
        : m_raylibRenderTexture{LoadRenderTexture(width, height)}
{
}

raylib::RenderTexture::~RenderTexture()
{
    UnloadRenderTexture(m_raylibRenderTexture);
}
