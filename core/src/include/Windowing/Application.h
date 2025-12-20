#pragma once
#include"Windowing/Window.h"
#include"Windowing/Overlay.h"
#include"Windowing/Layer.h"
#include<memory>
#include<vector>

class Application{
protected:
    Window mWindow;
    std::vector<std::unique_ptr<Layer>> mLayerStack;
public:
    Application(WindowSpecs window_specs);
    ~Application();
    virtual void Run();
    void Raise(Event& event);
    inline Window& GetWindow() { return mWindow; }
    static Application* sApplication;
    
    template<typename T, typename... Args>
    requires(std::is_base_of_v<Layer, T>)
    void PushLayer(Args&&... args){
        mLayerStack.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }
};