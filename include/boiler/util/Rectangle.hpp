#pragma once

#include "Vector.hpp"

/// \brief Default rectangle implementation
template<typename T = int>
struct Rectangle {
    T x, y, w, h;

    Rectangle() : x{0}, y{0}, w{0}, h{0} {
    }

    Rectangle(T x, T y, T w, T h) : x{x}, y{y}, w{w}, h{h} {
    }

    Rectangle(const V2 &origin, const V2 &extend) : x{origin[0]}, y{origin[1]}, w{extend[0]},
                                                    h{extend[1]} {
    }

    static Rectangle Zero;

    V2 Origin() const {
        return V2{x, y};
    }

    void Origin(const V2 &point) {
        x = point[0];
        y = point[1];
    }

    V2 Extend() const {
        return V2{w, h};
    }

    void Extend(const V2 &point) {
        w = point[0];
        h = point[1];
    }

    V2 Center() const {
        auto res = Origin() + (Extend() * 0.5f);
        return res;
    }

    void MoveTo(const V2 &point) {
        x = point[0];
        y = point[1];
    }

    void MoveBy(const V2 &vector) {
        x += vector[0];
        y += vector[1];
    }

    bool Contains(const V2 &point) const {
        return (point[0] > x) && (point[1] > y) && (point[0] < (x + w)) &&
               (point[1] < (y + h));
    }
};

using FRect = Rectangle<float>;
using Rect = Rectangle<int>;