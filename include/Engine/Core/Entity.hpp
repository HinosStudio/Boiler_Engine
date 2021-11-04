#ifndef FLATGALAXY_ENTITY_HPP
#define FLATGALAXY_ENTITY_HPP

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "Engine/Util/V2.hpp"

class Extension;

class Entity {
private:
    std::string _name;
    bool _active;
    V2 _position;
    Entity* _parent;

    std::vector<std::unique_ptr<Entity>> _children;
    std::vector<Extension*> _extensions; //TODO: to smart pointer

public:
    Entity();
    Entity(const V2 &position);

    std::string Name() const; void Name(const std::string&);
    bool Active() const; void Active(const bool);
    V2 Position() const; void Position(const V2&);
    Entity* Parent() const; void Parent(Entity*);

    void update();

    void add_child(std::unique_ptr<Entity> &entity);
    void remove_child(Entity* entity);

    template<typename T, typename... Targs>
    void add_extension(Targs... args){
        _extensions.push_back(new T{this, args...});
    }

    template<typename T>
    T* get_extension(){
        for(auto & ex : _extensions){
            auto* c = dynamic_cast<T*>(ex);
            if(c) return c;
        }
        return nullptr;
    }

    template<typename T>
    void remove_extension(){
        for(auto & ex : _extensions){
            auto* c = dynamic_cast<T>(ex);
            if(c) {
                delete c;
                return;
            }
        }
    }
};


#endif //FLATGALAXY_ENTITY_HPP
