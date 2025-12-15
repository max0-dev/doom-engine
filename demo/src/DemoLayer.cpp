#include "include/DemoLayer.h"
#include<Engine/extern.h>
#include<spdlog/spdlog.h>
#include<Engine/Application.h>
#include<Engine/Scene.h>
#include<Engine/Renderer.h>
#include<iostream>

DemoLayer::DemoLayer() : camera(CameraTransform(), 120.0, 15.0){
    shader = std::make_unique<Shader>("../../../res/shaders/vert.vs", "../../../res/shaders/frag.fs");
    float vertices[] = {
        -5, -5, 0, 1, 0, 0,
         5, -5, 0, 0, 1, 0,
         5,  5, 0, 0, 0, 1,
        -5,  5, 0, 0, 0, 1
    };

    unsigned int indices[] = {
        0,1,2, 2,3,0
    };

    vbo.BufferData(sizeof(vertices), vertices, GL_STATIC_DRAW);
    ibo.BufferData(sizeof(indices), indices, GL_STATIC_DRAW);
    
    vao.GetLayout().Push<float>(3);
    vao.GetLayout().Push<float>(3);

    vao.AddBuffer(vbo);
    auto& window = Application::sApplication->GetWindow();

    Scene* scene = new Scene();
    scene->SetActiveCamera(&camera);
    Renderer::Instance()->SetActiveScene(scene);
}

void DemoLayer::OnUpdate(double dt){
    camera.Look(dt);
    camera.Move(dt);
}

void DemoLayer::OnRender(){
    shader->Use();
    
    auto& window = Application::sApplication->GetWindow();
    glm::mat4 model = glm::rotate(glm::identity<glm::mat4>(), (float)window.GetTime(), glm::vec3(0, 1.0f, 0));
    glm::mat4 view = camera.GetView();
    glm::mat4 proj = camera.GetProjection(window.GetSpecs().GetAspect());

    shader->SetUniformMat4("model", model);
    shader->SetUniformMat4("view", view);
    shader->SetUniformMat4("proj", proj);
   
    vao.Bind();
    ibo.Bind();
    glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, NULL);
}

void DemoLayer::OnEvent(Event& event){
    EventDispatcher dispatcher(event);
    static bool focused = false;
    dispatcher.Dispatch<KeyDown>([](KeyDown& e){
        auto window = Application::sApplication->GetWindow().GetRawPtr();
        if(e.GetKey() == GLFW_KEY_F){
            focused = !focused;
            glfwSetInputMode(window, GLFW_CURSOR, focused ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
        }else if(e.GetKey() == GLFW_KEY_ESCAPE){
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
        return true;
    });
}