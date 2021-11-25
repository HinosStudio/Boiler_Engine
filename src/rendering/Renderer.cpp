#include <rendering/Renderer.hpp>

Renderer::Renderer(SDL_Renderer *renderer) : _renderer{renderer}, _font{nullptr} {
    if (TTF_Init() < 0) throw std::exception{"could not init TTF"};
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(_renderer);
    TTF_CloseFont(_font);
    TTF_Quit();
}

void Renderer::ClearRenderer() {
    SDL_SetRenderDrawColor(_renderer, 61, 61, 61, 255);
    SDL_RenderClear(_renderer);
}

void Renderer::PresentRenderer() {
    SDL_SetRenderTarget(_renderer, nullptr);
    Notify();
    SDL_RenderPresent(_renderer);
    SDL_Delay(1);
}

void Renderer::SetRenderTarget(const std::unique_ptr<Texture> &texture) {
    SDL_SetRenderTarget(_renderer, texture->GetTexture());
}

void Renderer::ClearRenderTarget() {
    SDL_SetRenderTarget(_renderer, nullptr);
}

std::unique_ptr<Texture> Renderer::GenerateTexture(const int width, const int height) {
    SDL_Texture *SDLtexture = SDL_CreateTexture(_renderer, 0, SDL_TEXTUREACCESS_TARGET, width, height);
    return std::make_unique<Texture>(SDLtexture);
}

void Renderer::DrawTexture(const FRect &rect, const std::unique_ptr<Texture> &texture) const {
    SDL_FRect desR{rect.x, rect.y, rect.w, rect.h};
    SDL_RenderCopyF(_renderer, texture->GetTexture(), nullptr, &desR);
}

void Renderer::DrawRectangle(const FRect &rect, const V4 &color) const {
    SDL_SetRenderDrawColor(_renderer, color[0], color[1], color[2], color[3]);
    SDL_FRect desR{rect.x, rect.y, rect.w, rect.h};
    SDL_RenderFillRectF(_renderer, &desR);
}

void Renderer::OpenFont(const std::string &path) {
    TTF_CloseFont(_font);
    _font = TTF_OpenFont(path.c_str(), 15);
    if (!_font) throw std::exception{"Could not load font"};
}

void Renderer::DrawText(const FRect &rect, const std::string &text, const V4 &color) const {
    SDL_Color sdlColor{(Uint8) color[0], (Uint8) color[1], (Uint8) color[2], (Uint8) color[3]};
    SDL_Surface *surface = TTF_RenderText_Solid(_font, text.c_str(), sdlColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FRect desR{rect.x, rect.y, (float) surface->w, (float) surface->h};
    SDL_RenderCopyF(_renderer, texture, nullptr, &desR);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}