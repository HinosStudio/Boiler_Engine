#include <Engine/Core/Engine.hpp>
#include <SDLimp/Input/SDLInputSubsystem.hpp>
#include "SDLimp/Rendering/SDLRendererSubsystem.hpp"

int main(int argc, char* args[]) {
    std::unique_ptr<IInputSubsystem> input = std::make_unique<SDLInputSubsystem>();
    std::unique_ptr<IRenderSubsystem> renderer = std::make_unique<SDLRendererSubsystem>();
    auto engine = std::make_unique<Engine>(input, renderer);

    engine->Initialize();
    if(Engine::Init()) engine->Run();
    engine->Shutdown();

    return 0;
}