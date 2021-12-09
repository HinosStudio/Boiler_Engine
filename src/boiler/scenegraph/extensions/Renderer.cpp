#include <Extensions/Renderer.hpp>
#include <boiler/rendering/Color.hpp>

Renderer::Renderer(Entity* entity) : Extension{entity} {}

SDL_Color Renderer::Color() const {
    return _color;
}

void Renderer::Color(const SDL_Color &color) {
    _color = color;
}