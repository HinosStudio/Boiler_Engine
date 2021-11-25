#include <rendering/RenderingEngine.hpp>
#include <sstream>
#include <stdexcept>
#include <SDL.h>
#include <rendering/Window.hpp>
#include <rendering/Renderer.hpp>

RenderingEngine::RenderingEngine() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::ostringstream oss;
        oss << "[RENDERING-ENGINE] Could not initialize video, Error " << SDL_GetError();
        throw std::runtime_error{oss.str()};
    }

    SDL_Window* sdlWindow;
    SDL_Renderer* sdlRenderer;
    SDL_CreateWindowAndRenderer(680,420,0,&sdlWindow, &sdlRenderer);
    SDL_SetWindowTitle(sdlWindow, "Boiler Engine");

    _window = std::make_unique<Window>(sdlWindow);
    _renderer = std::make_unique<Renderer>(sdlRenderer);
}

RenderingEngine::~RenderingEngine() {
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

const std::unique_ptr<Renderer> &RenderingEngine::GetRenderer() const {
    return _renderer;
}

void RenderingEngine::OnStartFrame() {
    _renderer->ClearRenderer();
}

void RenderingEngine::OnEndFrame() {
    _renderer->PresentRenderer();
}