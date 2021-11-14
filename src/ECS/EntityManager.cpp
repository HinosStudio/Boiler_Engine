#include <../ECS/EntityManager.hpp>

using namespace ECS;

EntityManager::EntityManager() = default;

uint32_t EntityManager::CreateEntity(){
    uint32_t entity {};
    if(!_entities.empty()) entity = _entities.back() + 1;
    _entities.push_back(entity);
    return entity;
}

void EntityManager::RemoveEntity(uint32_t entity){
    auto it = std::remove(_entities.begin(), _entities.end(), entity);
    _entities.erase(it, _entities.end());
}