#version 330 core

out vec4 FragColor;

in vec2 outUv;
in vec3 outNormal;
in vec3 fragPos;

uniform sampler2D texture0;

struct Light{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;
uniform vec3 cameraPos;

void main(){
    //FragColor = texture(texture0, outUv);
    vec3 norm = normalize(outNormal);
    vec3 lightDir = normalize(light.position - fragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * light.diffuse;
    
    vec3 reflectDir = reflect(-lightDir, norm);
    vec3 viewDir = normalize(cameraPos - fragPos);

    float spec = pow(max(dot(reflectDir, viewDir), 0.0), 32);
    vec3 specular = spec * light.specular;

    FragColor = vec4(light.ambient + diffuse + specular, 1);
}