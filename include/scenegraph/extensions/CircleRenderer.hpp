#ifndef INCLUDE_FLATGALAXY_DOMAIN_CIRCLERENDERER_HPP
#define INCLUDE_FLATGALAXY_DOMAIN_CIRCLERENDERER_HPP

#include "Renderer.hpp"

class CircleRenderer : public Renderer {
private:
    float _radius;

public:
    CircleRenderer(Entity* entity);
    CircleRenderer(Entity* entity, const float radius, const SDL_Color &color);

    float Radius() const; void Radius(const float);

    void render(SDL_Renderer* const renderer) override;
};

#endif //INCLUDE_FLATGALAXY_DOMAIN_CIRCLERENDERER_HPP
