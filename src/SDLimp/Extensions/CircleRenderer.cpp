#include "SDLimp/Extensions/CircleRenderer.hpp"

CircleRenderer::CircleRenderer(Entity *entity) : Renderer{entity} {}

CircleRenderer::CircleRenderer(Entity *entity, const float radius, const SDL_Color &color) : Renderer{entity},
                                                                                             _radius{radius} {
    Color(color);
}

float CircleRenderer::Radius() const {
    return _radius;
}

void CircleRenderer::Radius(const float radius) {
    this->_radius = radius;
}

void CircleRenderer::render(SDL_Renderer *const renderer) {
    //TODO: move to facade and clean floating point
    SDL_SetRenderDrawColor(renderer, _color.r, _color.g, _color.b, _color.a);

    int renderWidth, renderHeight;
    SDL_GetRendererOutputSize(renderer, &renderWidth, &renderHeight);

    auto position = _entity->Position();
    int left = position.X() - _radius;
    int top = position.Y() - _radius;
    int right = position.X() + _radius;
    int bottom = position.Y() + _radius;

    for (int x = left; x <= right; x++) {
        for (int y = top; y <= bottom; y++) {
            int circleVolume =
                    (x - position.X()) * (x - position.X()) + (y - position.Y()) * (y - position.Y()) -
                    _radius * _radius;
            if (circleVolume <= 0) SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}