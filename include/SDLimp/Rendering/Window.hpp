#ifndef FLATGALAXY_WINDOW_HPP
#define FLATGALAXY_WINDOW_HPP

#include <SDL.h>
#include <memory>

class Window {
private:
    SDL_Color _backgroundColor {61, 61, 61, 255};
    std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;

public:
    Window(const int width, const int height);

    void Close();
};


#endif //FLATGALAXY_WINDOW_HPP
