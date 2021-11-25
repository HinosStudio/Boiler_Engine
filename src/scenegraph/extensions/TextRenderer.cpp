#include <iostream>
#include <rendering/Color.hpp>
#include <Extensions/TextRenderer.hpp>

constexpr char* FONT_PATH {"../resources/arial.ttf"};

TTF_Font *font;

void init_TTF(){
    if(TTF_Init() < 0) std::cerr << "couldnt initialize TTF" << std::endl;

    font = TTF_OpenFont(FONT_PATH, 12);
    if(!font) std::cerr << "couldn't find font at:" << FONT_PATH << std::endl;
}

void clean_TTF(){
    TTF_CloseFont(font);
    TTF_Quit();
}

TextRenderer::TextRenderer(Entity *entity) : Renderer{entity} {}

TextRenderer::TextRenderer(Entity* entity, const V2 &anchor, const std::string &text, const SDL_Color &color) : Renderer{entity}, _anchor{anchor}, _text{text} {
    Color(color);
}

void TextRenderer::render(SDL_Renderer *const renderer) {
    auto position = _entity->Position();
    auto text_surface = std::unique_ptr<SDL_Surface, void(*)(SDL_Surface*)>(
            TTF_RenderText_Solid(font, _text.c_str(), _color),
            SDL_FreeSurface);
    auto text_texture = std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> {
            SDL_CreateTextureFromSurface(renderer, text_surface.get()),
            SDL_DestroyTexture };

    if(!text_texture) std::cerr << "failed to create texture" << std::endl;

    SDL_Rect dest;
    dest.w = text_surface->w;
    dest.h = text_surface->h;
    dest.x = position.X() - (_anchor.X() * text_surface->w);
    dest.y = position.Y() + (_anchor.Y() * text_surface->h);

    SDL_RenderCopy(renderer, text_texture.get(), nullptr, &dest);
}

V2 TextRenderer::Anchor() const {
    return _anchor;
}

void TextRenderer::Anchor(const V2 &anchor) {
    _anchor = anchor;
}

void TextRenderer::Text(const std::string &text) {
    _text = text;
}