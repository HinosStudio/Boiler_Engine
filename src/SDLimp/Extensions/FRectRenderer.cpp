#include "SDLimp/Extensions/FRectRenderer.hpp"

FRectRenderer::FRectRenderer(Entity * entity) : Renderer{entity}, _size{} {}

FRectRenderer::FRectRenderer(Entity *entity, const V2 &size, const SDL_Color &color) : Renderer{entity}, _size{size} {
    Color(color);
}

void FRectRenderer::Size(const V2 &size) {
    this->_size = size;
}

void FRectRenderer::render(SDL_Renderer *const renderer) {
    //TODO: move to facade
    auto pos = _entity->Position();
    SDL_FRect rect {pos.X(), pos.Y(), _size.X(), _size.Y()};
    SDL_SetRenderDrawColor(renderer, _color.r, _color.g, _color.b, _color.a);
    SDL_RenderFillRectF(renderer, &rect);
}