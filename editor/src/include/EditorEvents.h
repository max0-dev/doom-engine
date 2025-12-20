#pragma once

#include<Event.h>

class OnViewportResize : public Event{
private:
    float mWidth;
    float mHeight;
public:
    OnViewportResize(float width, float height) : mWidth(width), mHeight(height) {}
    inline std::tuple<float, float> GetDimensions() { return std::tuple<float, float>(mWidth, mHeight); }
};

class OnViewportMove : public Event{
private:
    float mX;
    float mY;
public:
    OnViewportMove(float x, float y) : mX(x), mY(y) {}
    inline glm::vec2 GetPosition() { return glm::vec2(mX, mY); }
};