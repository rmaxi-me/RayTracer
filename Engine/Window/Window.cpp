#include "Window.hpp"
#include <raylib.h>

Window::Window(int widht, int height, const std::string &title, unsigned int configFlag)
{
    InitWindow(widht, height, title.c_str());
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
