#include <Core/Engine.hpp>

int main(int argc, char* args[]) {
    Engine engine;
    if(Engine::Init()) engine.Run();

    return 0;
}