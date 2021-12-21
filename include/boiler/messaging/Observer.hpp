#pragma once

#include <boiler/events/EventSystem.hpp>

class Observable;

class Observer{
public:
    virtual ~Observer() = default;
    virtual void HandleMessage(Event &event) = 0;

protected:
    Observer() = default;
};
