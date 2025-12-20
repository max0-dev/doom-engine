#pragma once

#include<extern.h>

class Texture{
private:
    unsigned int mHandle;
public:
    Texture() = default;
    Texture(const char* filepath);
    ~Texture(){
        glDeleteTextures(1, &mHandle);
    }
    void Bind(){
        glBindTexture(GL_TEXTURE_2D, mHandle);
    }
    void SetParameter(GLenum pname, GLint param){
        glTexParameteri(GL_TEXTURE_2D, pname, param);
    }
    inline unsigned int getHandle() const { return mHandle; }
};