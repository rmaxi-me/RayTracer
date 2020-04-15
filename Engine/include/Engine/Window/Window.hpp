#pragma once

#include <raylib.h>

#include <string>
#include "Engine/Vector/Vector2.hpp"

namespace raylib {
    class Window {
    private:
        Color m_color;
    public:
        Window(int width, int height, const std::string &title, unsigned int configFlag = 0);
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
        raymath::Vector2 getPosition();

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
        void setConfigFlags(unsigned int flags)
        { SetConfigFlags(flags); };
    };
}

// inline functions definition's declared above
//---------------------------------------------

inline bool raylib::Window::isOpen()
{
    return !WindowShouldClose();
}

inline void raylib::Window::close()
{
    CloseWindow();
}

inline bool raylib::Window::isReady()
{
    return IsWindowReady();
}

inline bool raylib::Window::isMinimized()
{
    return IsWindowMinimized();
}

inline bool raylib::Window::isResized()
{
    return IsWindowResized();
}

inline void raylib::Window::setMinSize(int width, int height)
{
    SetWindowMinSize(width, height);
}

inline void raylib::Window::setSize(int width, int height)
{
    SetWindowSize(width, height);
}

inline bool raylib::Window::isFullscreen()
{
    return IsWindowFullscreen();
}

inline void raylib::Window::toggleFullscreen()
{
    ToggleFullscreen();
}

inline void raylib::Window::unhide()
{
    UnhideWindow();
}

inline void raylib::Window::hide()
{
    HideWindow();
}

inline bool raylib::Window::isHidden()
{
    return IsWindowHidden();
}

// void SetWindowIcon(Image image)

inline void raylib::Window::setTitle(const std::string &title)
{
    SetWindowTitle(title.c_str());
}

inline void raylib::Window::setPosition(int x, int y)
{
    SetWindowPosition(x, y);
}

inline int raylib::Window::getWidth()
{
    return GetScreenWidth();
}

inline int raylib::Window::getHeight()
{
    return GetScreenHeight();
}

inline raymath::Vector2 raylib::Window::getPosition()
{
    return raymath::Vector2(GetWindowPosition());
}

inline void raylib::Window::startDrawing(void)
{
    BeginDrawing();
}

inline void raylib::Window::stopDrawing(void)
{
    EndDrawing();
}

inline void raylib::Window::startMode2D(Camera2D camera)
{
    BeginMode2D(camera);
}

inline void raylib::Window::stopMode2D(void)
{
    EndMode2D();
}

inline void raylib::Window::startMode3D(Camera3D camera)
{
    BeginMode3D(camera);
}

inline void raylib::Window::stopMode3D(void)
{
    EndMode3D();
}

inline void raylib::Window::startTextureMode(RenderTexture2D target)
{
    BeginTextureMode(target);
}

inline void raylib::Window::stopTextureMode(void)
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
