#include <Util/Rect.hpp>

const Rect Rect::Zero{0, 0, 0, 0};

Rect::Rect(coord x, coord y, coord w, coord h) : _x{x}, _y{y}, _w{w}, _h{h} {}

Rect::Rect(const V2 &origin, const V2 &extent) : _x{origin.X()}, _y{origin.Y()}, _w{extent.X()}, _h{extent.Y()} {}

coord Rect::Width() const {
    return _w;
}

void Rect::Width(const coord width) {
    _w = width;
}

coord Rect::Height() const {
    return _h;
}

void Rect::Height(const coord height) {
    _h = height;
}

V2 Rect::Origin() const {
    return V2{_x, _h};
}

void Rect::Origin(const V2 &point) {
    _x = point.X();
    _y = point.Y();
}

V2 Rect::Extend() const {
    return V2{_w, _h};
}

void Rect::Extend(const V2 &point) {
    _w = point.X();
    _h = point.Y();
}

V2 Rect::Center() const {
    return Origin() + (Extend() / 2);
}

bool Rect::Contains(const V2 &point) const {
    return (
            (point.X() >= _x) &&
            (point.X() <= _x + _w) &&
            (point.Y() >= _y) &&
            (point.Y() <= _y + _h)
    );
}