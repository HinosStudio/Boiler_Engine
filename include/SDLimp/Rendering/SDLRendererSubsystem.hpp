#ifndef BOILER_ENGINE_SDLRENDERERSUBSYSTEM_HPP
#define BOILER_ENGINE_SDLRENDERERSUBSYSTEM_HPP

#include <IRenderSubsystem.hpp>
#include <Rendering/Window.hpp>

class SDLRendererSubsystem : public IRenderSubsystem {
private:
    std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;
    std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer;

public:
    SDLRendererSubsystem();

    void Initialize() override;
    void OnBegin() override;
    void OnEnd() override;
    void Shutdown() override;
};

#endif //BOILER_ENGINE_SDLRENDERERSUBSYSTEM_HPP
