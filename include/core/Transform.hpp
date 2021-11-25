#pragma once

#include <util/V3.hpp>

class Transform{
private:
    V3 _position;
    V3 _rotation;
    V3 _scale;

public:
    Transform();
};
