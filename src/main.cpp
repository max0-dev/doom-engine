#include<spdlog/spdlog.h>
#include<gl/glew.h>
#include<GLFW/glfw3.h>

#include "include/Shader.h"

int main(int, char**){
    GLFWwindow* window;


    if(!glfwInit()){
        spdlog::error("Failed to initialize GLFW");
        return -1;
    }

    window = glfwCreateWindow(800, 800, "Doom", NULL, NULL);

    if(!window){
        spdlog::error("Failed to create a window");
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    glewInit();  

    Shader basic("../../res/shaders/vert.vs", "../../res/shaders/frag.fs");

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}