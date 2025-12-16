#pragma once

#include<Windowing/Overlay.h>
#include<Event.h>

class DebugOverlay : public Overlay{
public:
    void OnUpdate(double dt) override;
    void OnRender() override;
    void OnEvent(Event& event) override;
};