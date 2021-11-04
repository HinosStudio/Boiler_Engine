#include "SDLimp/Extensions/Renderer.hpp"
#include "SDLimp/Rendering/Color.hpp"

Renderer::Renderer(Entity* entity) : Extension{entity} {}

SDL_Color Renderer::Color() const {
    return _color;
}

void Renderer::Color(const SDL_Color &color) {
    _color = color;
}