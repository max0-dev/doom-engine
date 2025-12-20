#pragma once

#include<Windowing/Overlay.h>

class EditorOverlay : public Overlay{
public:
    EditorOverlay();
    void OnUpdate(double dt) override;
    void OnEvent(Event& event) override;
    void OnRender() override;
};