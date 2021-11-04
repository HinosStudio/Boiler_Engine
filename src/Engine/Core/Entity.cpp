#include <iostream>
#include <algorithm>

#include "Engine/Core/Entity.hpp"
#include "Engine/Core/Extension.hpp"

Entity::Entity() : _name{"gameObject"}, _active{true}, _position{V2::Zero}, _parent{nullptr} {}

std::string Entity::Name() const {
    return _name;
}

void Entity::Name(const std::string &name) {
    this->_name = name;
}

bool Entity::Active() const {
    return _active;
}

void Entity::Active(const bool active) {
    this->_active = active;
}

V2 Entity::Position() const {
    return _position;
}

void Entity::Position(const V2 &position) {
    this->_position = position;
}

Entity* Entity::Parent() const {
    return _parent;
}

void Entity::Parent(Entity *parent) {
    this->_parent = parent;
}

void Entity::add_child(std::unique_ptr<Entity> &child) {
    auto it = std::find_if(_children.begin(), _children.end(), [&child](std::unique_ptr<Entity> &p){return p == child;});
    if(it != _children.end()) return;
    child->Parent(this);
    _children.push_back(std::move(child));
}

void Entity::remove_child(Entity* entity) { }