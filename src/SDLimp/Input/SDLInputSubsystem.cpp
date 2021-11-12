#include <SDL.h>
#include <iostream>

#include "Input/SDLInputSubsystem.hpp"

void SDLInputSubsystem::Initialize() {
    if(SDL_Init(SDL_INIT_EVENTS) < 0){
        std::cerr << "[SDL INPUT] Error: Could not initialize Input" << std::endl;
        return;
    }
}

void SDLInputSubsystem::Update() {
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        //TODO: Handle events
    }
}

void SDLInputSubsystem::Shutdown() {
    SDL_QuitSubSystem(SDL_INIT_EVENTS);
}