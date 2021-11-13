#include <string>
#include <SDL.h>
#include <Core/Engine.hpp>

bool Engine::init {false};
bool Engine::Init() {return init;}

Engine::Engine() : _running{false}, _time{} {

}

void Engine::Initialize() {
    if(SDL_Init(SDL_INIT_EVENTS) < 0) throw std::exception{"[SDL] ERROR: could not initialize Events!"};

    _renderer->Initialize();
    _time.LastTick();
    init = true;
}

void Engine::Run() {
    SDL_Event event;

    while(true) {
        //TODO: handle in eventsystem
        if(SDL_WaitEvent(&event)) {
            if(event.type == SDL_QUIT) break;
        }

        _renderer->OnBegin();
        //TODO: run simulation
        _renderer->OnEnd();
    }
}

void Engine::Shutdown() {
    _renderer->Shutdown();
    SDL_Quit();
}
