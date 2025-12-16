#pragma once

#include<Scene/Camera.h>
#include<extern.h>
#include<Windowing/Application.h>

class FreeLookCamera : public Camera{
private:
    double mSens;
    double mMoveSpeed;
    
    double mRotZ = 0.0;
    double mRotY = 0.0;

    double lastx = 0.0;
    double lasty = 0.0;
    bool first = true;
public:
    FreeLookCamera(CameraTransform transform, double sensitivity, double speed) : mSens(sensitivity), mMoveSpeed(speed), Camera(transform) {}
    void Look(double dt);
    void Move(double dt);
};