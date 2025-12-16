#pragma once
#include"extern.h"
#include<spdlog/spdlog.h>
#include<Event.h>

struct WindowSpecs{
    int width;
    int height;
    const char* title;
    bool vsync;
    float GetAspect() const{
        return (float)width/(float)height;
    }
};

class Window{
private:
    GLFWwindow* mWindow;
    WindowSpecs mSpecs;
public:
    Window() = default;
    Window(WindowSpecs specs);
    ~Window();

    void SwapBuffers();
    inline double GetTime() { return glfwGetTime(); }
    inline bool ShouldClose() { return glfwWindowShouldClose(mWindow); }
    inline void GetMousePos(double* xpos, double* ypos) { return glfwGetCursorPos(mWindow, xpos, ypos); }
    inline bool IsKeyDown(int key) { return glfwGetKey(mWindow, key) == GLFW_PRESS ? true : false; }
    inline GLFWwindow* GetRawPtr() { return mWindow; }
    inline WindowSpecs& GetSpecs() { return mSpecs; }
    std::function<void(Event&)> mEventCallback;
};