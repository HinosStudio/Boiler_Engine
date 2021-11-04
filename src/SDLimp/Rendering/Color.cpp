#include "SDLimp/Rendering/Color.hpp"

const std::map<std::string, SDL_Color> Color::colors{
        {"black",  BLACK},
        {"white",  WHITE},
        {"blue",   BLUE},
        {"orange", ORANGE},
        {"grey",   GREY},
        {"brown",  BROWN},
        {"purple", PURPLE},
        {"pink",   PINK}
};

const SDL_Color Color::BLACK{0, 0, 0, 255};
const SDL_Color Color::WHITE{255, 255, 255, 255};
const SDL_Color Color::BLUE{0, 0, 255, 255};
const SDL_Color Color::ORANGE{255, 123, 0, 255};
const SDL_Color Color::GREY{123, 123, 123, 255};
const SDL_Color Color::BROWN{123, 61, 0, 255};
const SDL_Color Color::PURPLE{123, 0, 255, 255};
const SDL_Color Color::PINK{255, 0, 255, 255};

SDL_Color Color::GetColor(const std::string &value) { return colors.at(value); }

std::string Color::GetName(const SDL_Color &color) {
    auto res = std::find_if(colors.begin(), colors.end(), [&](const std::pair<std::string, SDL_Color> &pair) {
        return pair.second == color;
    });

    if (res != colors.end()) return res->first;
    else return "pink";
}

bool operator==(const SDL_Color &a, const SDL_Color &b) {
    return (
            (a.r == b.r) &&
            (a.g == b.g) &&
            (a.b == b.b) &&
            (a.a == b.a)
    );
}