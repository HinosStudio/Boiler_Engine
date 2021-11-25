#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <memory>
#include <util/Rectangle.hpp>
#include "messaging/Observable.hpp"
#include "Texture.hpp"

class Renderer : public Observable {
private:
    SDL_Renderer *_renderer;
    TTF_Font *_font;
public:
    Renderer(SDL_Renderer *renderer);

    ~Renderer();

    void ClearRenderer();

    void PresentRenderer();

    void SetRenderTarget(const std::unique_ptr<Texture> &texture);

    void ClearRenderTarget();

    std::unique_ptr<Texture> GenerateTexture(const int width, const int height);

    void DrawTexture(const FRect &rect, const std::unique_ptr<Texture> &texture) const;

    void DrawRectangle(const FRect &rect, const V4 &color) const;

    void OpenFont(const std::string &path);

    void DrawText(const FRect &rect, const std::string &text, const V4 &color) const;
};
