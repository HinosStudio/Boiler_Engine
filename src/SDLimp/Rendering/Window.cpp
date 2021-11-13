#include <Rendering/Window.hpp>

Window::Window(const int width, const int height) :
        _window{std::unique_ptr<SDL_Window, void (*)(SDL_Window *)>{
                SDL_CreateWindow("Boiler Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0),
                SDL_DestroyWindow}} {
}

void Window::Close() {

}