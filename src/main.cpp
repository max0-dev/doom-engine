#include<spdlog/spdlog.h>
#include<gl/glew.h>
#include<GLFW/glfw3.h>

#include "include/Shader.h"

void GLAPIENTRY MessageCallback(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{
    std::string src;
    switch (source) {
    case GL_DEBUG_SOURCE_API:             src = "API"; break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   src = "Window System"; break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER: src = "Shader Compiler"; break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:     src = "Third Party"; break;
    case GL_DEBUG_SOURCE_APPLICATION:     src = "Application"; break;
    default:                              src = "Other"; break;
    }

    std::string tp;
    switch (type) {
    case GL_DEBUG_TYPE_ERROR:               tp = "Error"; break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: tp = "Deprecated"; break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  tp = "Undefined Behavior"; break;
    case GL_DEBUG_TYPE_PORTABILITY:         tp = "Portability"; break;
    case GL_DEBUG_TYPE_PERFORMANCE:         tp = "Performance"; break;
    case GL_DEBUG_TYPE_OTHER:               tp = "Other"; break;
    default:                                tp = "Unknown"; break;
    }

    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:
        spdlog::error(message);
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        spdlog::warn(message);
        break;
    case GL_DEBUG_SEVERITY_LOW:
        spdlog::info(message);
        break;
    default:
        break;
    }
}

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

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

    glfwMakeContextCurrent(window);
    
    

    glewInit();  
    
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);
    
    Shader basic("../../res/shaders/vert.vs", "../../res/shaders/frag.fs");

    float vertices[] = {
        -0.5f, -0.5f, 0,
         0.5f, -0.5f, 0,
         0,     0.5f, 0,
    };

    unsigned int vbo;

    unsigned int vao;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 3, (void*)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        basic.Use();
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);    

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}