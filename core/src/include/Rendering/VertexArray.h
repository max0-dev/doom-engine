#pragma once
#include"extern.h"
#include<vector>
#include"VertexBuffer.h"

struct LayoutElement{
    unsigned int type;
    unsigned int count;
    bool normalized;
};

class VertexArrayLayout{
private:
    std::vector<LayoutElement> mElements;
    unsigned int mStride;
public:
    VertexArrayLayout() : mStride(0) {}

    void PushFloat(unsigned int count){
        mElements.push_back({GL_FLOAT, count, false});
        mStride += sizeof(float) * count;
    }

    inline const std::vector<LayoutElement>& GetElements() const { return mElements; }
    inline unsigned int GetStride() const { return mStride; }

    static unsigned int GetSizeOfType(GLenum type){
        switch (type)
        {
        case GL_FLOAT: return sizeof(GLfloat);
        default:       break;
        }
    }
};


class VertexArray{
private:
    unsigned int mHandle;
    VertexArrayLayout mLayout;    
public:
    VertexArray(){
        glGenVertexArrays(1, &mHandle);
    }
    ~VertexArray(){
        glDeleteVertexArrays(1, &mHandle);
    }
    void Bind(){
        glBindVertexArray(mHandle);
    }
    void AddBuffer(const VertexBuffer& vbo){
        Bind();
        vbo.Bind();

        const auto& layout_elements = mLayout.GetElements();

        unsigned int offset = 0;
        for(int i = 0; i < layout_elements.size(); i++){
            const auto& element = layout_elements[i];
            glVertexAttribPointer(i, element.count, element.type, element.normalized, mLayout.GetStride(), (void*)offset);
            glEnableVertexAttribArray(i);
            offset += VertexArrayLayout::GetSizeOfType(element.type) * element.count;
        }
    }
    inline VertexArrayLayout& GetLayout() { return mLayout; }
};