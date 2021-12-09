#ifndef BOILER_ENGINE_ENTITYMANAGER_HPP
#define BOILER_ENGINE_ENTITYMANAGER_HPP

#include <vector>
#include <algorithm>

namespace ECS{
    class EntityManager{
    private:
        std::vector<uint32_t> _entities;

    public:
        EntityManager();

        uint32_t CreateEntity();
        void RemoveEntity(uint32_t entity);
    };
}

#endif //BOILER_ENGINE_ENTITYMANAGER_HPP
