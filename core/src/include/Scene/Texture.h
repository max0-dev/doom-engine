#pragma once

#include<extern.h>

class Texture{
private:
    unsigned int mHandle;
public:
    Texture(const char* filepath);
    ~Texture(){
        glDeleteTextures(1, &mHandle);
    }
    void Bind(){
        glBindTexture(GL_TEXTURE_2D, mHandle);
    }
};