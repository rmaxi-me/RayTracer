#include "Window/Window.hpp"
#include <raylib.h>

Window::Window(int width, int height, const std::string &title, unsigned int configFlag)
        : m_color{}
{
    InitWindow(width, height, title.c_str());
    SetConfigFlags(configFlag);
}

void Window::clear()
{
    ClearBackground(m_color);
}

void Window::changeClearColor(Color color)
{
    m_color = color;
}
