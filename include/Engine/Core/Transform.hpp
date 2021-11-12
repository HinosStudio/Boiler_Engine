#ifndef BOILER_ENGINE_TRANSFORM_HPP
#define BOILER_ENGINE_TRANSFORM_HPP

#include "Engine/Util/V3.hpp"

class Transform{
private:
    V3 _position;
    V3 _rotation;
    V3 _scale;

public:
    Transform();
};

#endif //BOILER_ENGINE_TRANSFORM_HPP
