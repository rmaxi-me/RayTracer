#include "Engine/Window/Window.hpp"
#include <raylib.h>

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
