#ifndef INCLUDE_FLATGALAXY_DOMAIN_EXTENSION_HPP
#define INCLUDE_FLATGALAXY_DOMAIN_EXTENSION_HPP

#include "Entity.hpp"

class Extension{
protected:
    Entity* const _entity;
    bool _active;

public:
    Extension(Entity* entity);
    //virtual ~Extension() = default; //object needs 1 virtual method to work

    Entity* get_entity() const;

    bool is_active(); void set_active(bool active);

    virtual void awake();
    virtual void update();
};

#endif //INCLUDE_FLATGALAXY_DOMAIN_EXTENSION_HPP
