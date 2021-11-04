#ifndef INCLUDE_FLATGALAXY_DOMAIN_FRECTRENDERER_HPP
#define INCLUDE_FLATGALAXY_DOMAIN_FRECTRENDERER_HPP

#include "Engine/Util/V2.hpp"

#include "Renderer.hpp"

class FRectRenderer : public Renderer{
private:
    V2 _size;

public:
    FRectRenderer(Entity* entity);
    FRectRenderer(Entity* entity, const V2 &size, const SDL_Color &color);

    void Size(const V2 &);

    void render(SDL_Renderer *const renderer) override;
};

#endif //INCLUDE_FLATGALAXY_DOMAIN_FRECTRENDERER_HPP
