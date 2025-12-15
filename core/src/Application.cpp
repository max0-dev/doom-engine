#include"Engine/Application.h"
#include<memory>
#include<vector>
#include<ranges>

Application* Application::sApplication = nullptr;

Application::Application(WindowSpecs window_specs) : mWindow(window_specs){
    mWindow.mEventCallback = [this](Event& event){
        Raise(event);
    };
    sApplication = this;
}
void Application::Raise(Event& event){
    for(auto& layer : std::views::reverse(mLayerStack)){
        layer->OnEvent(event);  
    }
}
Application::~Application(){

}
void Application::Run(){
    double last_t = mWindow.GetTime();
    while (!mWindow.ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        double current_t = mWindow.GetTime(); 
        double delta_t = current_t - last_t;
        last_t = current_t;

        glfwPollEvents();

        for(std::unique_ptr<Layer>& layer : mLayerStack){
            if(layer->IsActive()){
                layer->OnUpdate(delta_t);
                layer->OnRender();
            }
        }

        mWindow.SwapBuffers();
    }
    
}