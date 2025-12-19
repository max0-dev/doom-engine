#pragma once
#include"extern.h"

class VertexBuffer{
private:
    unsigned int mHandle;
    size_t mWriteOffset;
    size_t mBufferCapacity;
public:
    VertexBuffer() : mWriteOffset(0), mBufferCapacity(0) {
        glGenBuffers(1, &mHandle);
    };
    ~VertexBuffer(){
        glDeleteBuffers(1, &mHandle);
    }
    void BufferData(GLsizeiptr size, const void *data, GLenum usage = GL_STATIC_DRAW){
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
        mBufferCapacity = size;
    }
    void BufferSubData(GLintptr offset, GLsizeiptr size, const void *data){
        Bind();
        glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
        mWriteOffset += size;
    }
    void Bind() const{
        glBindBuffer(GL_ARRAY_BUFFER, mHandle);
    }
    inline size_t GetCapacity() const { return mBufferCapacity; }
    inline size_t GetWriteOffset() const { return mWriteOffset; }
};