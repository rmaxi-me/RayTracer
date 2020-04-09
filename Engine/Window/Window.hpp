#pragma once

#include <raylib.h>

#include <string>
#include "Vector2.hpp"

class Window
{
private:
    Color m_color;
public:
    Window(int widht, int height, const std::string &title, unsigned int configFlag = 0);
    ~Window() = default;

    inline bool isOpen();
    inline void close();
    inline bool isReady();

    inline bool isMinimized();
    inline bool isResized();
    inline void setMinSize(int width, int height);
    inline void setSize(int width, int height);

    inline bool isFullscreen();
    inline void toggleFullscreen();

    inline void unhide();
    inline void hide();
    inline bool isHidden();

    // inline void SetIcon(Image image);
    inline void setTitle(const std::string &title);
    inline void setPosition(int x, int y);

    int getWidth();
    int getHeight();
    maths::Vector_2 getPosition();

    //Drawing related funtions
    //------------------------

    void clear();
    void changeClearColor(Color color);
    inline void startDrawing();
    inline void stopDrawing();
    inline void startMode2D(Camera2D camera);
    inline void stopMode2D();
    inline void startMode3D(Camera3D camera);
    inline void stopMode3D();
    inline void startTextureMode(RenderTexture2D target);
    inline void stopTextureMode();

    //Frame Related functions
    //-----------------------

    inline void setFPS(int fps);
    inline int getFPS();
    inline float getFrameTime();
    inline double getTime();

    //Misc functions
    void setConfigFlags(unsigned int flags) { SetConfigFlags(flags); };
};

// inline functions definition's declared above
//---------------------------------------------

inline bool Window::isOpen()
{
    return !WindowShouldClose();
}

inline void Window::close()
{
    CloseWindow();
}

inline bool Window::isReady()
{
    return IsWindowReady();
}

inline bool Window::isMinimized()
{
    return IsWindowMinimized();
}

inline bool Window::isResized()
{
    IsWindowResized();
}

inline void Window::setMinSize(int width, int height)
{
    SetWindowMinSize(width, height);
}

inline void Window::setSize(int width, int height)
{
    SetWindowSize(width, height);
}

inline bool Window::isFullscreen()
{
    return IsWindowFullscreen();
}

inline void Window::toggleFullscreen()
{
    ToggleFullscreen();
}

inline void Window::unhide()
{
    UnhideWindow();
}

inline void Window::hide()
{
    HideWindow();
}

inline bool Window::isHidden()
{
    IsWindowHidden();
}

// void SetWindowIcon(Image image)

inline void Window::setTitle(const std::string &title)
{
    SetWindowTitle(title.c_str());
}

inline void Window::setPosition(int x, int y)
{
    SetWindowPosition(x, y);
}

inline int Window::getWidth()
{
    return GetScreenWidth();
}

inline int Window::getHeight()
{
    return GetScreenHeight();
}

inline maths::Vector_2 Window::getPosition()
{
    return maths::Vector_2(GetWindowPosition());
}

inline void Window::startDrawing(void)
{
    BeginDrawing();
}

inline void Window::stopDrawing(void)
{
    EndDrawing();
}

inline void Window::startMode2D(Camera2D camera)
{
    BeginMode2D(camera);
}

inline void Window::stopMode2D(void)
{
    EndMode2D();
}

inline void Window::startMode3D(Camera3D camera)
{
    BeginMode3D(camera);
}

inline void Window::stopMode3D(void)
{
    EndMode3D();
}

inline void Window::startTextureMode(RenderTexture2D target)
{
    BeginTextureMode(target);
}

inline void Window::stopTextureMode(void)
{
    EndTextureMode();
}

inline void setFPS(int fps)
{
    SetTargetFPS(fps);
}

inline int getFPS()
{
    return GetFPS();
}

inline float getFrameTime()
{
    return GetFrameTime();
}

inline double getTime()
{
    return GetTime();
}
