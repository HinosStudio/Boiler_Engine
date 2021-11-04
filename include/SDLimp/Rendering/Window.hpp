#ifndef FLATGALAXY_WINDOW_HPP
#define FLATGALAXY_WINDOW_HPP

#include <SDL.h>
#include <string>
#include <memory>

#include "Engine/Util/Rect.hpp"
#include "Engine/Util/V2.hpp"

#include "SDLimp/Extensions/Renderer.hpp"

class TextRenderer;
class IRenderable;

class Window {
private:
    static Rect WINDOW_RECT;

    SDL_Color _backgroundColor {61, 61, 61, 255};

    std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> _window;
    std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> _renderer;

public:
    static Rect get_rect();

    Window(const int width, const int height);

    void Clear();
    void Finalize();
    void Render(IRenderable*);

    void RenderColor(const SDL_Color&);
    void render_text(const TextRenderer &text, const V2 &position);
    void render_panel(const V2 &pos, const V2 &size, const SDL_Color &color);
};


#endif //FLATGALAXY_WINDOW_HPP
