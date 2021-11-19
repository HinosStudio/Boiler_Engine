#pragma once

#include <SDL.h>

class Window{
private:
    static int width, height;
    SDL_Window *_window;

public:
    static int GetWidth();
    static int GetHeight();

    Window(SDL_Window *window);
    ~Window();
};
