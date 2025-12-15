#pragma once
#include<Engine/extern.h>

class IndexBuffer{
private:
    unsigned int mHandle;
    unsigned int mCount;
public:
    IndexBuffer() : mCount(0){
        glGenBuffers(1, &mHandle);
    }
    ~IndexBuffer(){
        glDeleteBuffers(1, &mHandle);
    }
    void BufferData(GLsizeiptr size, const void *data, GLenum usage){
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
        mCount = size/sizeof(unsigned int);
    }
    void Bind() const{
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mHandle);
    }
    inline unsigned int GetCount() const { return mCount; }
};
