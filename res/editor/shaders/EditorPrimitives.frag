#version 330 core

out vec4 fragColor;
in float outSelected;

void main(){
    if(outSelected == 0.0){
        fragColor = vec4(1);
    }else{
        fragColor = vec4(0.2,0.2,1,1);
    }
}