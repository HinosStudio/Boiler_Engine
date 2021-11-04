#ifndef FLATGALAXY_TEXTRENDERING_HPP
#define FLATGALAXY_TEXTRENDERING_HPP

#include <string>
#include <memory>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Engine/Util/V2.hpp"

#include "Renderer.hpp"

//TODO: move into _window
void init_TTF();
void clean_TTF();

class TextRenderer : public Renderer {
private:
    std::string _text;
    V2 _anchor;

public:
    TextRenderer(Entity* entity);
    TextRenderer(Entity* entity, const V2 &anchor, const std::string &text, const SDL_Color &color);

    void Text(const std::string &text);

    V2 Anchor() const; void Anchor(const V2 &anchor);

    void render(SDL_Renderer *const renderer) override;
};

#endif //FLATGALAXY_TEXTRENDERING_HPP
