#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <memory>
#include <util/Rect.hpp>
#include "Observable.hpp"
#include "Texture.hpp"

class Renderer : public Observable {
private:
    SDL_Renderer *_renderer;
    TTF_Font *_font;
public:
    Renderer(SDL_Renderer *renderer);

    ~Renderer();

    void OnStartFrame();

    void OnEndFrame();

    void SetRenderTarget(const std::unique_ptr<Texture> &texture);

    void ClearRenderTarget();

    std::unique_ptr<Texture> GenerateTexture(const int width, const int height);

    void DrawTexture(const Rect &rect, const std::unique_ptr<Texture> &texture) const;

    void DrawRectangle(const Rect &rect, const SDL_Color &color) const;

    void OpenFont(const std::string &path);

    void DrawText(const Rect &rect, const std::string &text, const SDL_Color &color) const;
};
