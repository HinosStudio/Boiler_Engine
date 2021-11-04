#include "Engine/Core/Extension.hpp"

Extension::Extension(Entity* entity) : _entity {entity}, _active{true} {}

Entity*     Extension::get_entity() const       {return _entity;}
bool        Extension::is_active()              {return _active;}
void        Extension::set_active(bool active)  {this->_active = active;}

void Extension::awake() {}

void Extension::update() {}