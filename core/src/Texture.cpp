#include<Scene/Texture.h>

#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>

Texture::Texture(const char* filepath){
    glGenTextures(1, &mHandle);
    Bind();

    stbi_set_flip_vertically_on_load(1);
    int width, height, channels;
    unsigned char* img_data = stbi_load(filepath, &width, &height, &channels, 0);

    if(img_data){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img_data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        spdlog::warn("Failed loading texture invalid filepath");
    }

    stbi_image_free(img_data);
}