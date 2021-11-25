#ifndef BOILER_ENGINE_TRANSFORM_HPP
#define BOILER_ENGINE_TRANSFORM_HPP

#include "EntityComponent.hpp"

struct Transform : public ECS::EntityComponent {
    V3 position;
    V3 rotation;
    V3 scale;

    Transform(uint32_t id);
};

#endif //BOILER_ENGINE_TRANSFORM_HPP
