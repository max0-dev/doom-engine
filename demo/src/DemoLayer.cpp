#include "include/DemoLayer.h"
#include<Engine/extern.h>
#include<spdlog/spdlog.h>
#include<iostream>

DemoLayer::DemoLayer(){
    shader = std::make_unique<Shader>("../../../res/shaders/vert.vs", "../../../res/shaders/frag.fs");
    float vertices[] = {
        -0.5f, -0.5f, 0, 1, 0, 0,
         0.5f, -0.5f, 0, 0, 1, 0,
         0.5f,  0.5f, 0, 0, 0, 1,
        -0.5f,  0.5f, 0, 0, 0, 1
    };

    unsigned int indices[] = {
        0,1,2, 2,3,0
    };

    vbo.BufferData(sizeof(vertices), vertices, GL_STATIC_DRAW);
    ibo.BufferData(sizeof(indices), indices, GL_STATIC_DRAW);
    
    vao.GetLayout().Push<float>(3);
    vao.GetLayout().Push<float>(3);

    vao.AddBuffer(vbo);
}

void DemoLayer::OnUpdate(double dt){

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Debug Window");

    ImGui::Text("------");
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void DemoLayer::OnRender(){
    shader->Use();
    vao.Bind();
    ibo.Bind();
    glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, NULL);
}

void DemoLayer::OnEvent(Event& event){
    EventDispatcher dispatcher(event);

    dispatcher.Dispatch<KeyDown>([](KeyDown& e){
        spdlog::info(e.ToString());
        return true;
    });
    dispatcher.Dispatch<KeyUp>([](KeyUp& e){
        spdlog::info(e.ToString());
        return true;
    });
    dispatcher.Dispatch<KeyRepeat>([](KeyRepeat& e){
        spdlog::info(e.ToString());
        return true;
    });
}