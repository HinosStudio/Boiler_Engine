#pragma once

#include "v2.hpp"

struct SDL_Rect;

/// \brief Default rectangle implementation
struct Rect {
    coord x, y, w, h;

    Rect();

    Rect(coord x, coord y, coord w, coord h);

    Rect(const V2 &origin, const V2 &width);

    static Rect Zero;

    V2 Origin() const;

    void Origin(const V2 &);

    V2 Extend() const;

    void Extend(const V2 &);

    void MoveTo(const V2 &);

    void MoveBy(const V2 &);

    bool Contains(const V2 &) const;

    explicit operator SDL_Rect() const;
};
