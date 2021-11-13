#include <cmath>
#include <Util/V2.hpp>

const V2 V2::Zero {0,0};

V2::V2() : _x{0}, _y{0} {}

V2::V2(const coord x, const coord y) : _x{x}, _y{y} {}

coord V2::X() const {
    return _x;
}

void V2::X(const coord x) {
    _x = x;
}

coord V2::Y() const {
    return _y;
}

void V2::Y(const coord y) {
    _y = y;
}

V2& V2::operator+=(const V2& other) {
    _x += other._x;
    _y += other._y;
    return *this;
}

V2 &V2::operator-=(const V2 &other) {
    _x -= other._x;
    _y -= other._y;
    return *this;
}

coord V2::magnitude() const {
    return std::sqrt((_x * _x) + (_y * _y));
}

V2 V2::normalized() const {
    return *this * (1/magnitude());
}

coord V2::distance(V2 a, V2 b) {
    coord distanceX = a._x - b._x;
    coord distanceY = a._y - b._y;
    return std::sqrt((distanceX * distanceX) + (distanceY * distanceY));
}

coord V2::dot(V2 a, V2 b) {
    return (a._x * b._x) + (a._y * b._y);
}

V2 V2::operator*(const coord &value) const {
    V2 temp;
    temp._x = _x * value;
    temp._y = _y * value;
    return temp;
}

V2 V2::operator/(const coord &value) const {
    V2 temp;
    temp._x = _x / value;
    temp._y = _y / value;
    return temp;
}

V2 operator+(const V2 &a, const V2 &b){
    V2 temp;
    temp._x = a._x + b._x;
    temp._y = a._y + b._y;
    return temp;
}

V2 operator-(const V2 &a, const V2 &b){
    V2 temp;
    temp._x = a._x - b._x;
    temp._y = a._y - b._y;
    return temp;
}

V2 operator*(const V2 &a, const V2 &b){
    V2 temp;
    temp._x = a._x * b._x;
    temp._y = a._y * b._y;
    return temp;
}

V2 operator/(const V2 &a, const V2 &b){
    V2 temp;
    temp._x = a._x / b._x;
    temp._y = a._y / b._y;
    return temp;
}