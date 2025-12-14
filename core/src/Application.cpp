#include"Engine/Application.h"

Application::Application(WindowSpecs window_specs){
    mWindow = std::make_unique<Window>(window_specs);
    mShouldClose = false;
}

Application::~Application(){

}

void Application::Run(){
    double last_t = mWindow->GetTime();
    while (true)
    {
        double current_t = mWindow->GetTime(); 
        double delta_t = current_t - last_t;
        last_t = current_t;

        glfwPollEvents();

        for(auto& layer : mLayerStack){
            layer.OnUpdate(delta_t);
            layer.OnRender();
        }

        mWindow->SwapBuffers();
    }
}