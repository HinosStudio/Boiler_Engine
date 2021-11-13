#include <exception>
#include <iostream>
#include <SDL_ttf.h>
#include <Rendering/SDLRendererSubsystem.hpp>

SDLRendererSubsystem::SDLRendererSubsystem() :
        _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window *)>{nullptr, SDL_DestroyWindow}},
        _renderer{std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)>{nullptr, SDL_DestroyRenderer}} {

}

void SDLRendererSubsystem::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) throw std::exception{"[SDL] ERROR: Could not initialize Video"};
    _window = std::unique_ptr<SDL_Window, void (*)(SDL_Window *)>{
            SDL_CreateWindow("SDL2 sub renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 620, 480, 0),
            SDL_DestroyWindow};
    _renderer = std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)>{
            SDL_CreateRenderer(_window.get(), 0, 0),
            SDL_DestroyRenderer};
    if (TTF_Init() < 0) throw std::exception("[TTF] ERROR: Could not initialize!");

    /* OPEN GL Initialization
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) throw std::exception("[SDL] ERROR: could not initialize!");

    //TODO: Research context, what is context?
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 420, SDL_WINDOW_OPENGL);
    context = SDL_GL_CreateContext(window);

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if(GLEW_OK != err) throw std::exception(reinterpret_cast<const char *const>(glewGetErrorString(err)));
    */
}

void SDLRendererSubsystem::OnBegin() {
    SDL_SetRenderDrawColor(_renderer.get(), 61, 61, 61, 255);
    SDL_RenderClear(_renderer.get());
}

void SDLRendererSubsystem::OnEnd() {
    SDL_RenderPresent(_renderer.get());
    SDL_Delay(1);

    //OPEN GL BUFFER SWAP
    //SDL_GL_SwapWindow(window);
}

void SDLRendererSubsystem::Shutdown() {
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    TTF_Quit();

    // OPEN GL CLEAN UP
    //SDL_GL_DeleteContext(context);
    //SDL_DestroyWindow(window);
}