#include <string>
#include <SDL.h>
#include <core/Engine.hpp>
#include <sstream>

bool Engine::init{false};

bool Engine::Init() {
    return init;
}

Engine::Engine() : _running{true}, _time{}, _renderEngine{} {
    if (SDL_Init(SDL_INIT_EVENTS) < 0) {
        std::ostringstream oss;
        oss << "[BOILER-ENGINE] could not initialize Events! Error " << SDL_GetError();
        throw std::runtime_error{oss.str()};
    };

    init = true;
}

Engine::~Engine() {
    SDL_Quit();
}

void Engine::Run() {
    Time::SetLastTick();

    SDL_Event event;

    while (_running) {
        //TODO: handle in eventsystem
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                _running = false;
                break;
            }
        }

        _renderEngine.OnStartFrame();
        _renderEngine.OnEndFrame();
    }
}
