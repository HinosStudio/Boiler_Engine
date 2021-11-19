#include<Renderer.hpp>

Renderer::Renderer(SDL_Renderer *renderer) : _renderer{renderer}, _font{nullptr} {
    if (TTF_Init() < 0) throw std::exception{"could not init TTF"};
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(_renderer);
    TTF_CloseFont(_font);
    TTF_Quit();
}

void Renderer::OnStartFrame() {
    SDL_SetRenderDrawColor(_renderer, 61, 61, 61, 255);
    SDL_RenderClear(_renderer);
}

void Renderer::OnEndFrame() {
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

void Renderer::DrawTexture(const Rect &rect, const std::unique_ptr<Texture> &texture) const {
    SDL_FRect desR{rect.x, rect.y, rect.w, rect.h};
    SDL_RenderCopyF(_renderer, texture->GetTexture(), nullptr, &desR);
}

void Renderer::DrawRectangle(const Rect &rect, const SDL_Color &color) const {
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    SDL_FRect desR{rect.x, rect.y, rect.w, rect.h};
    SDL_RenderFillRectF(_renderer, &desR);
}

void Renderer::OpenFont(const std::string &path) {
    TTF_CloseFont(_font);
    _font = TTF_OpenFont(path.c_str(), 15);
    if (!_font) throw std::exception{"Could not load font"};
}

void Renderer::DrawText(const Rect &rect, const std::string &text, const SDL_Color &color) const {
    SDL_Surface *surface = TTF_RenderText_Solid(_font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_FRect desR{rect.x, rect.y, (float) surface->w, (float) surface->h};
    SDL_RenderCopyF(_renderer, texture, nullptr, &desR);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}