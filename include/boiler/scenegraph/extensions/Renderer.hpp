#ifndef INCLUDE_FLATGALAXY_DOMAIN_RENDERER_HPP
#define INCLUDE_FLATGALAXY_DOMAIN_RENDERER_HPP

#include <SDL.h>

#include <Extension.hpp>
#include "sdlimp/Rendering/IRenderable.hpp"

class Renderer : public Extension, public IRenderable {
protected:
    SDL_Color _color;

public:
    Renderer(Entity* entity);

    SDL_Color Color() const; void Color(const SDL_Color &);

    void render(SDL_Renderer* renderer) override = 0;
};

#endif //INCLUDE_FLATGALAXY_DOMAIN_RENDERER_HPP
