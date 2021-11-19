#include <Rendering/Window.hpp>

int Window::width{0};
int Window::height{0};

int Window::GetWidth() {
    return width;
}

int Window::GetHeight() {
    return height;
}

Window::Window(SDL_Window *window) : _window{window} {
    SDL_GetWindowSize(window, &width, &height);
}

Window::~Window() {
    SDL_DestroyWindow(_window);
}

