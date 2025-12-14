#pragma once
#include"extern.h"
#include<spdlog/spdlog.h>

struct WindowSpecs{
    int width;
    int height;
    const char* title;
    bool vsync;
};

class Window{
private:
    GLFWwindow* mWindow;
public:
    Window() = default;
    Window(WindowSpecs specs);
    ~Window();

    void SwapBuffers();
    inline double GetTime() { return glfwGetTime(); }
};