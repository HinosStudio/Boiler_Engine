#include <boiler/rendering/RenderingEngine.hpp>
#include <sstream>
#include <stdexcept>
#include <SDL.h>
#include <boiler/rendering/Window.hpp>
#include <boiler/rendering/Renderer.hpp>

RenderingEngine::RenderingEngine(const int width, const int height, const std::string &name) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::ostringstream oss;
        oss << "[RENDERING-ENGINE] Could not initialize video, Error " << SDL_GetError();
        throw std::runtime_error{oss.str()};
    }

    SDL_Window* sdlWindow;
    SDL_Renderer* sdlRenderer;
    SDL_CreateWindowAndRenderer(width,height,0,&sdlWindow, &sdlRenderer);
    SDL_SetWindowTitle(sdlWindow, name.c_str());

    _window = std::make_unique<Window>(sdlWindow);
    _renderer = std::make_unique<Renderer>(sdlRenderer);
    _running = true;
}

RenderingEngine::~RenderingEngine() {
    if(_running) ShutDown();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void RenderingEngine::ShutDown() {
    _running = false;
}

bool RenderingEngine::IsRunning() const {
    return _running;
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