#include<Engine/FreeLookCamera.h>
#include<Engine/extern.h>

void FreeLookCamera::Look(double dt){
    Window& window = Application::sApplication->GetWindow();

    double mousex, mousey;
    window.GetMousePos(&mousex, &mousey);

    if(first){
        first = false;
        lastx = mousex;
        lasty = mousey;
    }

    double deltax = mousex - lastx;
    double deltay = mousey - lasty;

    lastx = mousex;
    lasty = mousey;

    mRotZ += deltax * mSens * dt;
    mRotY -= deltay * mSens * dt;
    mRotY = glm::clamp(mRotY, -90.0, 90.0);
    
    double sinz = sin(glm::radians(mRotZ));
    double cosz = cos(glm::radians(mRotZ));

    double siny = sin(glm::radians(mRotY));
    double cosy = cos(glm::radians(mRotY));

    mTransform.front.x = cosz * cosy;
    mTransform.front.y = siny;
    mTransform.front.z = sinz * cosy;
    mTransform.front = glm::normalize(mTransform.front);
}

void FreeLookCamera::Move(double dt){
    Window& window = Application::sApplication->GetWindow();
    if(window.IsKeyDown(GLFW_KEY_W)){
        mTransform.position += mTransform.front * (float)mMoveSpeed * (float)dt;
    }else if(window.IsKeyDown(GLFW_KEY_S)){
        mTransform.position -= mTransform.front * (float)mMoveSpeed * (float)dt;
    }else if(window.IsKeyDown(GLFW_KEY_A)){
        glm::vec3 right = glm::cross(mTransform.front, mTransform.up);
        mTransform.position -= right * (float)mMoveSpeed * (float)dt;
    }else if(window.IsKeyDown(GLFW_KEY_D)){
        glm::vec3 right = glm::cross(mTransform.front, mTransform.up);
        mTransform.position += right * (float)mMoveSpeed * (float)dt;
    }
}