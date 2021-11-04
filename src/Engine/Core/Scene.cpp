#include "Engine/Core/Scene.hpp"

Scene::Scene() : _active{true} {}

bool Scene::Active() {
    return _active;
}
void Scene::Active(bool active) {
    _active = active;
}

std::vector<std::unique_ptr<Entity>>& Scene::get_entities() {
    return _entities;
}

void Scene::add_entity(std::unique_ptr<Entity>& entity) {
    _entities.push_back(std::move(entity));
}

std::unique_ptr<Entity> & Scene::get_entity_with_name(const std::string &name) {
    auto it = std::find_if(_entities.begin(), _entities.end(), [&name](const std::unique_ptr<Entity> &e){
        return e->Name() == name;
    });

    if(it != _entities.end()) {
        return *it;
    }

    throw std::exception{"could not find _entity with _name"};
}
