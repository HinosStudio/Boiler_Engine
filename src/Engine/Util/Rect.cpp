#include <Util/Rect.hpp>

Rect Rect::Zero{0, 0, 0, 0};

Rect::Rect() : x{0}, y{0}, w{0}, h{0} {
}

Rect::Rect(coord x, coord y, coord w, coord h) : x{x}, y{y}, w{w}, h{h} {
}

Rect::Rect(const V2& origin, const V2& extend)
    : x{origin.x}, y{origin.y}, w{extend.x}, h{extend.y} {
}

V2 Rect::Origin() const {
    return V2{x, y};
}

void Rect::Origin(const V2& point) {
    x = point.x;
    y = point.y;
}

V2 Rect::Extend() const {
    return V2{w, h};
}

void Rect::Extend(const V2& size) {
    w = size.x;
    h = size.y;
}

void Rect::MoveTo(const V2& point) {
    x = point.x;
    y = point.y;
}

void Rect::MoveBy(const V2& translation) {
    x += translation.x;
    y += translation.y;
}

bool Rect::Contains(const V2& point) const {
    return (point.x > x) && (point.y > y) && (point.x < (x + w)) && (point.y < (y + h));
}