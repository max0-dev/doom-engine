#pragma once

class Layer{
public:
    virtual void OnUpdate(double dt) = 0;
    virtual void OnRender() = 0;
};