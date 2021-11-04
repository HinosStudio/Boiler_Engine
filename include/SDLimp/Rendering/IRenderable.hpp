#ifndef FLATGALAXY_IRENDERABLE_HPP
#define FLATGALAXY_IRENDERABLE_HPP

#include <SDL.h>

class IRenderable {
public:
    virtual void render(SDL_Renderer* renderer) = 0;
};

#endif //FLATGALAXY_IRENDERABLE_HPP
