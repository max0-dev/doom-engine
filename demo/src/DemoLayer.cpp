#include "include/DemoLayer.h"
#include<Engine/extern.h>

DemoLayer::DemoLayer(){
    shader = std::make_unique<Shader>("../../../res/shaders/vert.vs", "../../../res/shaders/frag.fs");
    float vertices[] = {
        -0.5f, -0.5f, 0, 1, 0, 0,
         0.5f, -0.5f, 0, 0, 1, 0,
         0,     0.5f, 0, 0, 0, 1
    };

    vbo.BufferData(sizeof(vertices), vertices, GL_STATIC_DRAW);

    vao.GetLayout().Push<float>(3);
    vao.GetLayout().Push<float>(3);

    vao.AddBuffer(vbo);
}

void DemoLayer::OnUpdate(double dt){

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Debug Window");

    ImGui::Text("Suck My Cock");
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void DemoLayer::OnRender(){
    shader->Use();
    vao.Bind();

    glDrawArrays(GL_TRIANGLES, 0, 3);
}