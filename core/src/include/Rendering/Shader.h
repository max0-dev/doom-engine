#pragma once
#include<extern.h>

class Shader{
private:
    unsigned int mHandle;
public:
    Shader(const char* vertexpath, const char* fragmentpath);
    ~Shader();
    void Use();
    void SetUniformMat4(const char* name ,const glm::mat4& value);
    void SetUniform(const char* name, int value);
};