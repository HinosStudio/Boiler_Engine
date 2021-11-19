#include <cmath>
#include <util/V2.hpp>

const V2 V2::Zero{0, 0};
const V2 V2::One{1, 1};
const V2 V2::Right{1, 0};
const V2 V2::Up{0, 1};

V2::V2() : x{0}, y{0} {}

V2::V2(const coord x, const coord y) : x{x}, y{y} {}

V2 &V2::operator+=(const V2 &other) {
    x += other.x;
    y += other.y;
    return *this;
}

V2 &V2::operator-=(const V2 &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

coord V2::magnitude() const {
    return std::sqrt((x * x) + (y * y));
}

V2 &V2::ClampMagnitude(const coord low, const coord high) {
    x = x < low ? low : x;
    x = x > high ? high : x;
    y = y < low ? low : y;
    y = y > high ? high : y;
    return *this;
}

V2 V2::normalized() const {
    return *this * (1 / magnitude());
}

coord V2::distance(V2 a, V2 b) {
    coord distanceX = a.x - b.x;
    coord distanceY = a.y - b.y;
    return std::sqrt((distanceX * distanceX) + (distanceY * distanceY));
}

coord V2::dot(V2 a, V2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

V2 V2::operator*(const coord &value) const {
    V2 temp;
    temp.x = x * value;
    temp.y = y * value;
    return temp;
}

V2 V2::operator/(const coord &value) const {
    V2 temp;
    temp.x = x / value;
    temp.y = y / value;
    return temp;
}

V2 operator+(const V2 &a, const V2 &b) {
    V2 temp;
    temp.x = a.x + b.x;
    temp.y = a.y + b.y;
    return temp;
}

V2 operator-(const V2 &a, const V2 &b) {
    V2 temp;
    temp.x = a.x - b.x;
    temp.y = a.y - b.y;
    return temp;
}

V2 operator*(const V2 &a, const V2 &b) {
    V2 temp;
    temp.x = a.x * b.x;
    temp.y = a.y * b.y;
    return temp;
}

V2 operator/(const V2 &a, const V2 &b) {
    V2 temp;
    temp.x = a.x / b.x;
    temp.y = a.y / b.y;
    return temp;
}