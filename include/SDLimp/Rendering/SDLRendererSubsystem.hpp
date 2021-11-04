#ifndef BOILER_ENGINE_SDLRENDERERSUBSYSTEM_HPP
#define BOILER_ENGINE_SDLRENDERERSUBSYSTEM_HPP

#include "Engine/Rendering/IRenderSubsystem.hpp"
#include "Window.hpp"

class SDLRendererSubsystem : public IRenderSubsystem {
private:
    Window* window;
public:
    SDLRendererSubsystem();

    void Initialize() override;
    void Render() override;
    void Shutdown() override;
};

#endif //BOILER_ENGINE_SDLRENDERERSUBSYSTEM_HPP
