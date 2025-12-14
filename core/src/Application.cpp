#include"Engine/Application.h"
#include<memory>
#include<vector>

Application::Application(WindowSpecs window_specs) : mWindow(window_specs){

    
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
            layer->OnUpdate(delta_t);
            layer->OnRender();
        }

        mWindow.SwapBuffers();
    }
}