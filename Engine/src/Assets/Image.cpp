/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Assets/Image.hpp"

raylib::Image::Image(::Image raylibImage)
        : m_rayImage{raylibImage}
{
}

raylib::Image::Image(const char *filename)
        : m_rayImage{LoadImage(filename)}
{
}

raylib::Image::Image(Color *pixels, int width, int height)
        : m_rayImage{LoadImageEx(pixels, width, height)}
{
}

raylib::Image::Image(const char *filename, int width, int height, PixelFormat format, int headerSize)
        : m_rayImage{LoadImageRaw(filename, width, height, format, headerSize)}
{
}

raylib::Image::~Image()
{
    UnloadImage(m_rayImage);
}

raylib::Image::Image(const raylib::Image &copy)
        : m_rayImage{ImageCopy(copy.m_rayImage)}
{
}

raylib::Image &raylib::Image::operator=(const raylib::Image &copy)
{
    m_rayImage = ImageCopy(copy.m_rayImage);
    return *this;
}

raylib::Image raylib::Image::GenImageColor(int width, int height, Color color)
{
    return raylib::Image(::GenImageColor(width, height, color));
}

raylib::Image raylib::Image::GenImageGradientV(int width, int height, Color top, Color bottom)
{
    return raylib::Image(::GenImageGradientV(width, height, top, bottom));
}

raylib::Image raylib::Image::GenImageGradientH(int width, int height, Color left, Color right)
{
    return raylib::Image(::GenImageGradientH(width, height, left, right));
}

raylib::Image raylib::Image::GenImageGradientRadial(int width, int height, float density, Color inner, Color outer)
{
    return raylib::Image(::GenImageGradientRadial(width, height, density, inner, outer));
}

raylib::Image raylib::Image::GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2)
{
    return raylib::Image(::GenImageChecked(width, height, checksX, checksY, col1, col2));
}

raylib::Image raylib::Image::GenImageWhiteNoise(int width, int height, float factor)
{
    return raylib::Image(::GenImageWhiteNoise(width, height, factor));
}

raylib::Image raylib::Image::GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale)
{
    return raylib::Image(::GenImagePerlinNoise(width, height, offsetX, offsetY, scale));
}

raylib::Image raylib::Image::GenImageCellular(int width, int height, int tileSize)
{
    return raylib::Image(::GenImageCellular(width, height, tileSize));
}

Color *raylib::Image::extractPalette(int maxPaletteSize, int &extractCount)
{
    return ImageExtractPalette(m_rayImage, maxPaletteSize, &extractCount);
}
