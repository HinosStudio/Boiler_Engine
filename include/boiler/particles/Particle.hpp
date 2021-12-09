#pragma once

class Particle{
private:
    float _life;
    V2 _position;
    V2 _velocity;

    Particle *_next;

public:
    Particle();

    void Update();
    void Draw();
};
