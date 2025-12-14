#include"Engine/Window.h"
#include"Engine/extern.h"

Window::Window(WindowSpecs specs){
    if(!glfwInit()){
        spdlog::error("Failed to initialize GLFW");
        return;
    }

    mWindow = glfwCreateWindow(specs.width, specs.height, specs.title, NULL, NULL);

    if(!mWindow){
        spdlog::error("Failed to create a window");
        glfwTerminate();
    }

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

    glfwMakeContextCurrent(mWindow);

    glewInit();  
    
    //glEnable(GL_DEBUG_OUTPUT);
    //glDebugMessageCallback(MessageCallback, 0);
}

Window::~Window(){
    glfwTerminate();
}

void Window::SwapBuffers(){
    glfwSwapBuffers(mWindow);
}