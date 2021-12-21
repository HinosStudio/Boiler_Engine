#include <boiler/core/Engine.hpp>

// Example Engine initialization

int main(int argc, char* args[]) {
    Engine engine;

    //TODO [SJORS]: between the creation and initialization we can load engine configuration settings

    engine.Initialize();
    if(engine.Init()) engine.Run();

    return 0;
}