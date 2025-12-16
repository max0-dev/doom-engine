#include "Rendering/Shader.h"
#include<spdlog/spdlog.h>

#include<fstream>
#include<string>
#include<sstream>

#include"extern.h"

Shader::Shader(const char* vertexpath, const char* fragmentpath){
    std::string sVertex;
    std::string sFragment;
    
    if(std::ifstream file {vertexpath}){
        std::stringstream ss;
        ss << file.rdbuf();
        sVertex = ss.str();
    }
    else{
        spdlog::warn("Couldn't Open File at: " + (std::string)vertexpath);
        return;
    }

    if(std::ifstream file {fragmentpath}){
        std::stringstream ss;
        ss << file.rdbuf();
        sFragment = ss.str();
    }
    else{
        spdlog::warn("Couldn't Open File at: " + (std::string)fragmentpath);
        return;
    }

    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);

    const char* sVertex_c = sVertex.c_str();
    const char* sFragment_c = sFragment.c_str();

    glShaderSource(vertex, 1, &sVertex_c, nullptr);
    glShaderSource(fragment, 1, &sFragment_c, nullptr);

    glCompileShader(vertex);
    glCompileShader(fragment);

    int vSuccess;
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &vSuccess);

    if(!vSuccess){
        int len;
        glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &len);
        std::string info_log(len, '\0');
        glGetShaderInfoLog(vertex, len, &len, &info_log[0]);
        spdlog::warn("Vertex shader compilation error: " + info_log);
        return;
    }

    int fSuccess;
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &fSuccess);
    
    if(!fSuccess){
        int len;
        glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &len);
        std::string info_log(len, '\0');
        glGetShaderInfoLog(fragment, len, &len, &info_log[0]);
        spdlog::warn("Fragment shader compilation error: " + info_log);
        return;
    }

    mHandle = glCreateProgram();
    
    glAttachShader(mHandle, vertex);
    glAttachShader(mHandle, fragment);
    
    glLinkProgram(mHandle);
    glValidateProgram(mHandle);

    int pSuccess;
    glGetProgramiv(mHandle, GL_VALIDATE_STATUS, &pSuccess);
    if(!pSuccess){
        int len;
        glGetProgramiv(mHandle, GL_INFO_LOG_LENGTH, &len);
        std::string info_log(len, '\0');
        glGetProgramInfoLog(mHandle, len, &len, &info_log[0]);
        spdlog::warn("Shader program validation error: " + info_log);
        return;
    }

    //Cleanup

    glDetachShader(mHandle, vertex);
    glDeleteShader(vertex);    
    
    glDetachShader(mHandle, fragment);
    glDeleteShader(fragment);
}

Shader::~Shader(){
    glDeleteProgram(mHandle);
}

void Shader::Use(){
    glUseProgram(mHandle);
}

void Shader::SetUniformMat4(const char* name ,const glm::mat4& value){
    unsigned int loc = glGetUniformLocation(mHandle, name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}
void Shader::SetUniform(const char* name , int value){
    unsigned int loc = glGetUniformLocation(mHandle, name);
    glUniform1i(loc, value);
}