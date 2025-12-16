#pragma once

#include "extern.h"

struct CameraTransform{
    glm::vec3 position {0, 0, -5};
    glm::vec3 front {0, 0, 1};
    glm::vec3 up{0, 1, 0};
    float fov = 75.0f;
    float near_plane = 0.1f;
    float far_plane = 100.0f;
};

class Camera{
protected:
    CameraTransform mTransform;
public:
    Camera(CameraTransform transform)
        : mTransform(transform) {}

    inline glm::mat4 GetProjection(float aspect) {
        return glm::perspective(glm::radians(mTransform.fov), aspect, mTransform.near_plane, mTransform.far_plane);
    }

    inline glm::mat4 GetView(){
        return glm::lookAt(mTransform.position, mTransform.position + mTransform.front, mTransform.up);
    }
    inline const CameraTransform& GetCameraTransform() const { return mTransform; }
};