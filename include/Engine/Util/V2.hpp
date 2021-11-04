#ifndef FLATGALAXY_VECTOR2_HPP
#define FLATGALAXY_VECTOR2_HPP

using coord = float;

class V2 {
private:
    coord _x;
    coord _y;

public:
    static const V2 Zero;

    V2();
    V2(coord x, coord y);

    coord X() const; void X(const coord);
    coord Y() const; void Y(const coord);

    V2 operator*(const coord &other) const;
    V2 operator/(const coord &other) const;

    V2& operator+=(const V2& other);
    V2& operator-=(const V2& other);

    friend V2 operator+(const V2 &a, const V2 &b);
    friend V2 operator-(const V2 &a, const V2 &b);
    friend V2 operator*(const V2 &a, const V2 &b);
    friend V2 operator/(const V2 &a, const V2 &b);

    coord magnitude() const;
    V2 normalized() const;

    static coord distance(V2 a, V2 b);
    static V2 cross(V2 a, V2 b);
    static coord dot(V2 a, V2 b);
    static V2 project(V2 vector, V2 normal);
    static V2 reflect(V2 vector, V2 normal);
};

#endif //FLATGALAXY_VECTOR2_HPP
