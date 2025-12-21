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
    inline glm::vec2 GetPosition() const { return glm::vec2(mX, mY); }
};

class OnPointAdded : public Event{
private:
    glm::vec3 mPoint;
public:
    OnPointAdded(glm::vec3 point) : mPoint(point) {}
    inline const glm::vec3& GetPoint() const { return mPoint; } 
};

class OnSelected : public Event{
public:
    OnSelected() = default;
};