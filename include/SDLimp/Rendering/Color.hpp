#ifndef FLATGALAXY_COLOR_HPP
#define FLATGALAXY_COLOR_HPP

#include <SDL.h>
#include <string>
#include <map>

bool operator==(const SDL_Color& a, const SDL_Color& b);

class Color {
private:
    static const std::map<std::string, SDL_Color> colors;

public:
    static const SDL_Color BLACK;
    static const SDL_Color WHITE;
    static const SDL_Color BLUE;
    static const SDL_Color ORANGE;
    static const SDL_Color GREY;
    static const SDL_Color BROWN;
    static const SDL_Color PURPLE;
    static const SDL_Color PINK;

    static SDL_Color GetColor(const std::string &value);
    static std::string GetName(const SDL_Color &color);

};


#endif //FLATGALAXY_COLOR_HPP
