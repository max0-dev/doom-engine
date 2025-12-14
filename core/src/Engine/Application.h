#pragma once
#include"Window.h"
#include"Layer.h"
class Application{
private:
    std::unique_ptr<Window> mWindow;
    std::vector<Layer> mLayerStack;
    bool mShouldClose;
public:
    Application(WindowSpecs window_specs);
    ~Application();
    void Run();
};