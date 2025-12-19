#include "include/DemoLayer.h"
#include<iostream>

#include<Engine.h>

DemoLayer::DemoLayer() : camera(CameraTransform(), 120.0, 15.0), scene(){
    shader = std::make_unique<Shader>("../../res/shaders/vert.vs", "../../res/shaders/frag.fs");

    vao.GetLayout().PushFloat(3);
    vao.GetLayout().PushFloat(3);
    vao.GetLayout().PushFloat(2);

    auto& window = Application::sApplication->GetWindow();

    scene.SetActiveCamera(&camera);
    Renderer::Instance()->SetActiveScene(&scene);

    //sample = std::make_unique<Texture>("../../../res/Textures/tense_cat.jpg");

    scene.mModels.emplace_back("../../res/models/girl/girl.obj");

    Light sun{
        {0, 5, 0},
        {0.2,0.2,0.2},
        {0.3,0.3,0.3},
        {0.4, 0.4, 0.4}
    };

    scene.light = std::move(sun);
}

void DemoLayer::OnUpdate(double dt){
    camera.Look(dt);
    camera.Move(dt);
}

void DemoLayer::OnRender(){
    shader->Use();
    
    auto& window = Application::sApplication->GetWindow();
    glm::mat4 model = glm::rotate(glm::identity<glm::mat4>(), (float)window.GetTime(), glm::vec3(0, 1.0f, 0));
    model = glm::scale(model, glm::vec3(0.1));
    glm::mat4 view = camera.GetView();
    glm::mat4 proj = camera.GetProjection(window.GetSpecs().GetAspect());

    shader->SetUniformMat4("model", model);
    shader->SetUniformMat4("view", view);
    shader->SetUniformMat4("proj", proj);
    
    shader->SetUniformVec3("light.position", scene.light.position);
    shader->SetUniformVec3("light.ambient", scene.light.ambient);
    shader->SetUniformVec3("light.diffuse", scene.light.diffuse);
    shader->SetUniformVec3("light.specular", scene.light.specular);

    shader->SetUniformVec3("cameraPos", scene.GetActiveCamera()->GetCameraTransform().position);

    glActiveTexture(GL_TEXTURE0);
    //sample->Bind();
    shader->SetUniform("texture0", 0);
    vao.Bind();
    scene.Render(vao);
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