#ifndef INCLUDE_FLATGALAXY_DOMAIN_RECT_HPP
#define INCLUDE_FLATGALAXY_DOMAIN_RECT_HPP

#include "V2.hpp"

class Rect {
private:
    coord _x;
    coord _y;
    coord _w;
    coord _h;

public:
    static const Rect Zero;

    Rect(coord x, coord y, coord w, coord h);
    Rect(const V2 &, const V2 &);

    coord Width() const; void Width(const coord);
    coord Height() const; void Height(const coord);

    V2 Origin() const; void Origin(const V2 &);
    V2 Extend() const; void Extend(const V2 &);

    V2 Center() const;

    bool Contains(const V2 &) const;
};


#endif //INCLUDE_FLATGALAXY_DOMAIN_RECT_HPP
