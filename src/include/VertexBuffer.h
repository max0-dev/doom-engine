#pragma once
#include<gl/glew.h>

class VertexBuffer{
private:
    unsigned int mHandle;
public:
    VertexBuffer() {
        glGenBuffers(1, &mHandle);
    };
    ~VertexBuffer(){
        glDeleteBuffers(1, &mHandle);
    }
    void BufferData(GLsizeiptr size, const void *data, GLenum usage){
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }
    void Bind() const{
        glBindBuffer(GL_ARRAY_BUFFER, mHandle);
    }
};