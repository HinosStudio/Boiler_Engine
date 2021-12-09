#include <boiler/rendering/Texture.hpp>

Texture::Texture(SDL_Texture *texture) : _texture{texture} {}

Texture::~Texture() {
    SDL_DestroyTexture(_texture);
}

SDL_Texture *Texture::GetTexture() const {
    return _texture;
}