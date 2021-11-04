#ifndef INCLUDE_FLATGALAXY_DOMAIN_SCENE_HPP
#define INCLUDE_FLATGALAXY_DOMAIN_SCENE_HPP

#include "Entity.hpp"

class Scene {
private:
    bool _active;
    std::vector<std::unique_ptr<Entity>> _entities;

public:
    Scene();

    bool Active(); void Active(bool);

    void add_entity(std::unique_ptr<Entity> &);
    void remove_entity(Entity* entity);

    std::vector<std::unique_ptr<Entity>>& get_entities();

    std::unique_ptr<Entity>& get_entity_with_name(const std::string &);

    template<typename T>
    std::vector<T*> get_components(){
        std::vector<T*> colliders;
        for(const auto & ent : _entities){
            auto* ex = ent->get_extension<T>();
            if(ex) colliders.push_back(ex);
        }
        return colliders;
    }
};

#endif //INCLUDE_FLATGALAXY_DOMAIN_SCENE_HPP
