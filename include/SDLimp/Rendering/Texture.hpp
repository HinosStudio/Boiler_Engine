#pragma once

#include <SDL.h>

class Renderer;

class Texture {
private:
    SDL_Texture *_texture;

public:
    Texture(SDL_Texture *texture);

    ~Texture();

public:
    friend class Renderer;

    SDL_Texture *GetTexture() const;
};
