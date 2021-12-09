#pragma once

#include <boiler/events/EventSystem.hpp>

class Observable;

class Observer{
public:
    virtual ~Observer() = default;
    virtual void HandleMessage(EventType type, void* subject) = 0;

protected:
    Observer() = default;
};
