#pragma once

#include<Windowing/Overlay.h>
#include<EditorContexts.h>

class EditorOverlay : public Overlay{
private:
    ViewportContext& mViewportContext;
public:
    EditorOverlay(ViewportContext& viewportContext);
    void OnUpdate(double dt) override;
    void OnEvent(Event& event) override;
    void OnRender() override;
};