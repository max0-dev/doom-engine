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
    glfwWindowHint(GL_MAJOR_VERSION, 3);
    glfwWindowHint(GL_MINOR_VERSION, 3);

    glfwMakeContextCurrent(mWindow);

    glewInit();  
    
    //glEnable(GL_DEBUG_OUTPUT);
    //glDebugMessageCallback(MessageCallback, 0);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(mWindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

Window::~Window(){
    glfwTerminate();
}

void Window::SwapBuffers(){
    glfwSwapBuffers(mWindow);
}