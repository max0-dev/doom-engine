#include<Engine/Application.h>
#include<Engine/Layer.h>
#include<Engine/Window.h>

int main(){
    WindowSpecs specs { 800, 800, "Doom" };    
    Application entry(specs);
    entry.Run();
}