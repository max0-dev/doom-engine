#include<Rendering/Renderer.h>

Renderer* Renderer::sInstance = nullptr;

Renderer* Renderer::Instance(){
    if(sInstance == nullptr){
        sInstance = new Renderer(); 
    }
    return sInstance;
}