#pragma once

class Emitter{
private:
    //The position we are spawning the particle at
    V2 _position;

    //The pool we are taking a particle from
    ParticlePool pool;

    //Data of the particle we are spawning
    Particle particle;

public:
    Emitter();

    void Spawn();
};