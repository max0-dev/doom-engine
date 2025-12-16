#include"Windowing/Window.h"
#include"extern.h"

Window::Window(WindowSpecs specs) : mSpecs(specs){
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
    glfwWindowHint(GL_MAJOR_VERSION, 3);
    glfwWindowHint(GL_MINOR_VERSION, 3);

    glfwMakeContextCurrent(mWindow);

    glfwSwapInterval(specs.vsync ? 1 : 0);

    glewInit();  
    
    //glEnable(GL_DEBUG_OUTPUT);
    //glDebugMessageCallback(MessageCallback, 0);

    glfwSetWindowUserPointer(mWindow, this);

    glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* handle, int button, int action, int mods){
        Window* window = (Window*)glfwGetWindowUserPointer(handle);

        if(action == GLFW_PRESS){
            MouseButtonDown event(button);
            window->mEventCallback(event);
        }
        else if(action == GLFW_RELEASE){
            MouseButtonUp event(button);
            window->mEventCallback(event);
        }
        
    });

    glfwSetKeyCallback(mWindow, [](GLFWwindow* handle, int key, int scancode, int action, int mods){
        Window* window = (Window*)glfwGetWindowUserPointer(handle);

        if(action == GLFW_PRESS){
            KeyDown event(key);
            window->mEventCallback(event);
        }
        else if(action == GLFW_RELEASE){
            KeyUp event(key);
            window->mEventCallback(event);
        }
        else if(action == GLFW_REPEAT){
            KeyRepeat event(key);
            window->mEventCallback(event);
        }
    });

    glfwSetFramebufferSizeCallback(mWindow, [](GLFWwindow* handle, int width, int height){
        Window* window = (Window*)glfwGetWindowUserPointer(handle);

        WindowResize event(width, height);
        window->mEventCallback(event);

        glViewport(0, 0, width, height);
        window->GetSpecs().width = width;
        window->GetSpecs().height = height;
    });
}

Window::~Window(){
    glfwTerminate();
}

void Window::SwapBuffers(){
    glfwSwapBuffers(mWindow);
}