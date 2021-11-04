#include <SDL.h>
#include <exception>
#include <iostream>
#include <SDL_ttf.h>
#include "SDLimp/Rendering/SDLRendererSubsystem.hpp"

SDLRendererSubsystem::SDLRendererSubsystem() {

}

void SDLRendererSubsystem::Initialize() {
    if(SDL_WasInit(SDL_INIT_VIDEO) != 0){
        std::cerr << "[SDL_RENDERING] Warning: Trying to initialize video, but was already init" << std::endl;
        return;
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "[SDL_RENDERING] Error: could not initialize video, " << SDL_GetError() << std::endl;
        return;
    }

    if((TTF_Init()) < 0){
        std::cerr << "[SDL_RENDERING] Error: could not initialize TTF" << TTF_GetError() << std::endl;
        return;
    }

    window = new Window {680,420};
}

void SDLRendererSubsystem::Render() {
    try{
        window->Clear();

        window->Finalize();
    }
    catch (const std::exception &ex){
        std::cerr << "[SDL_RENDERING] Error: " << ex.what() << std::endl;
    }
}

void SDLRendererSubsystem::Shutdown() {
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    TTF_Quit();
}