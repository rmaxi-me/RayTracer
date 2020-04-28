/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Window/Window.hpp"

raylib::Window::Window(int width, int height, const std::string &title, unsigned int configFlag)
        : m_color{}
{
    InitWindow(width, height, title.c_str());
    SetConfigFlags(configFlag);
}

void raylib::Window::clear()
{
    ClearBackground(m_color);
}

void raylib::Window::setClearColor(Color color)
{
    m_color = color;
}
