#ifndef BOILER_ENGINE_V3_HPP
#define BOILER_ENGINE_V3_HPP

using coord = float;

class V3 {
private:
    coord _x;
    coord _y;
    coord _z;

public:
    V3();
    V3(const coord x, const coord y, const coord z);

};

#endif //BOILER_ENGINE_V3_HPP
