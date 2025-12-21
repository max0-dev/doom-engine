#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in float aSelected;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out float outSelected;

void main(){
    gl_Position = proj * vec4(aPos, 1);
    outSelected = aSelected;
}