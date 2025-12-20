#pragma once

#include<Scene/Texture.h>

class FrameBuffer{
private:
    unsigned int mFbo;
    unsigned int mRbo;
    unsigned int  mTexture;
public:
    FrameBuffer(float width, float height);
    ~FrameBuffer();
    void Resize(float width, float height);
    inline unsigned int GetTexture() { return mTexture; }
    void Bind();
    void Unbind();
};