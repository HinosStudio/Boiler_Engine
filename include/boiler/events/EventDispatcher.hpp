#pragma once

#include <functional>
#include "Event.hpp"

class EventDispatcher {
private:
    Event &_event;

public:
    EventDispatcher(Event &event) : _event{event}{}

    template<typename T>
    bool Dispatch(std::function<bool(T&)> func) {
        if(_event.GetEventType() == T::GetStaticType()){
            func(*(T*)&_event);
            return true;
        }
        return false;
    }
};