#ifndef BOILER_ENGINE_ENTITYCOMPONENT_HPP
#define BOILER_ENGINE_ENTITYCOMPONENT_HPP

namespace ECS{
    class EntityComponent{
    private:
        uint32_t _id;
    protected:
        EntityComponent(uint32_t id);
    };
}

#endif //BOILER_ENGINE_ENTITYCOMPONENT_HPP
