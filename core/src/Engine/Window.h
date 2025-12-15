#pragma once
#include"extern.h"
#include<spdlog/spdlog.h>
#include<Engine/Event.h>

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
    inline GLFWwindow* GetRawPtr() { return mWindow; }
    inline const WindowSpecs& GetSpecs() const { return mSpecs; }
    std::function<void(Event&)> mEventCallback;
};