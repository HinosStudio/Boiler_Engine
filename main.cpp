#include <Engine/Core/Engine.hpp>

int main(int argc, char* args[]) {
    Engine engine;
    engine.Initialize();
    if(Engine::Init()) engine.Run();
    engine.Shutdown();

    return 0;
}