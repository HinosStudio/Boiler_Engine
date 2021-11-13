#include <Engine/Core/Engine.hpp>
#include <SDLimp/Rendering/SDLRendererSubsystem.hpp>

int main(int argc, char* args[]) {
    std::unique_ptr<IRenderSubsystem> renderer = std::make_unique<SDLRendererSubsystem>();
    Engine engine{std::move(renderer)};
    engine.Initialize();
    if(Engine::Init()) engine.Run();
    engine.Shutdown();

    return 0;
}