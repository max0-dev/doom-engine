#pragma once

#include<Windowing/Overlay.h>
#include<EditorContext.h>

class EditorOverlay : public Overlay{
private:
    EditorContext& mContext;
public:
    EditorOverlay(EditorContext& context);
    void OnUpdate(double dt) override;
    void OnEvent(Event& event) override;
    void OnRender() override;
};