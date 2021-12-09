#pragma once

class ParticlePool {
private:
    unsigned int _poolSize {0};
    Particle* _firstAvailable;
    Particle* _particleArray{nullptr};

public:
    ParticlePool();
    virtual ~ParticlePool();

    void Generate(const V2 &position, const V2 &velocity);
    void Update();
};
