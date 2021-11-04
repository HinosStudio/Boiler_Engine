#include <iostream>
#include "SDLimp/Rendering/Window.hpp"
#include "SDLimp/Extensions/TextRenderer.hpp"

Rect Window::WINDOW_RECT { Rect::Zero };
Rect Window::get_rect() { return WINDOW_RECT; }

//TODO: clean window, remove smart pointers and manage memory
Window::Window(const int width, const int height) :
        _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window *)>{
                SDL_CreateWindow("_window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0),
                SDL_DestroyWindow}},
        _renderer{std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer *)>{
                SDL_CreateRenderer(_window.get(), -1, 0),
                SDL_DestroyRenderer}} {
    WINDOW_RECT = Rect{V2::Zero, V2{static_cast<coord>(width), static_cast<coord>(height)}};
}

void Window::Clear() {
    SDL_SetRenderDrawColor(_renderer.get(), _backgroundColor.r, _backgroundColor.g, _backgroundColor.b,
                           _backgroundColor.a);
    SDL_RenderClear(_renderer.get());
}

void Window::Finalize() {
    SDL_RenderPresent(_renderer.get());
    SDL_Delay(1);
}

void Window::Render(IRenderable *object) {
    object->render(_renderer.get());
}