#include<Engine.h>
#include<DemoLayer.h>

int main(){
    WindowSpecs specs { 800, 800, "Doom" };    
    Application entry(specs);
    entry.PushLayer<DemoLayer>();
    entry.PushLayer<DebugOverlay>();
    entry.Run();
}