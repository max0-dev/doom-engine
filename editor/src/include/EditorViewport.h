#pragma once

#include<Windowing/Layer.h>
#include<Windowing/Window.h>

#include<extern.h>
#include<Rendering/Rendering_m.h>

#include<EditorContexts.h>

class EditorViewport : public Layer{
private:
    glm::mat4 projection;
    std::unique_ptr<Shader> mPrimitiveShader;
    VertexBuffer mVbo;
    VertexArray mVao;
    Window& mWindow;
    ViewportContext& mContext;
public:
    EditorViewport(ViewportContext& context);
    void OnUpdate(double dt) override;
    void OnRender() override;
    void OnEvent(Event& event);
    void UpdateVbo(glm::vec3 p);
    inline std::tuple<float, float> GetViewportSize() { return std::tuple<float, float>(mContext.mViewportWidth, mContext.mViewportHeight); }

    static EditorViewport* sEditorViewport;
};