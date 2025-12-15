#include<Engine/Application.h>
#include<Engine/Layer.h>
#include<Engine/Window.h>
#include<DemoLayer.h>
#include<Engine/DebugOverlay.h>
int main(){
    WindowSpecs specs { 800, 800, "Doom" };    
    Application entry(specs);
    entry.PushLayer<DemoLayer>();
    entry.PushLayer<DebugOverlay>();
    entry.Run();
}