#pragma once

#include<Windowing/Layer.h>
#include<Windowing/Window.h>

#include<extern.h>
#include<Rendering/Rendering_m.h>

class EditorViewport : public Layer{
private:
    glm::mat4 projection;
    std::unique_ptr<Shader> mPrimitiveShader;
    VertexBuffer mVbo;
    VertexArray mVao;
    Window& mWindow;
public:
    EditorViewport();
    void OnUpdate(double dt) override;
    void OnRender() override;
    void OnEvent(Event& event);
    void UpdateVbo(glm::vec3 p);

    static EditorViewport* sEditorViewport;
};