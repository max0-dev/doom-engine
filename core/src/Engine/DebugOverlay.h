#pragma once

#include<Engine/Overlay.h>
#include<Engine/Event.h>

class DebugOverlay : public Overlay{
public:
    void OnUpdate(double dt) override;
    void OnRender() override;
    void OnEvent(Event& event) override;
};