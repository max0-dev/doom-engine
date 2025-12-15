#pragma once
#include"Window.h"
#include"Layer.h"
#include<memory>
#include<vector>

class Application{
private:
    Window mWindow;
    std::vector<std::unique_ptr<Layer>> mLayerStack;
public:
    Application(WindowSpecs window_specs);
    ~Application();
    void Run();
    void Raise(Event& event);
    inline Window& GetWindow() { return mWindow; }
    static Application* sApplication;
    
    template<typename T>
    requires(std::is_base_of_v<Layer, T>)
    void PushLayer(){
        mLayerStack.push_back(std::make_unique<T>());
    }
};