#pragma once

#include <map>
#include <vector>
#include "Event.hpp"

class Observer;

class EventSystem {
private:
    static EventSystem* _instance;
    std::map<EventType, std::vector<Observer*>> _observers;

protected:
    EventSystem();

public:
    ~EventSystem();

    static EventSystem *Instance();

    void Subscribe(EventType, Observer *observer);

    void Unsubscribe(EventType, Observer *observer);

    void Notify(Event &event);

    void PollEvents();
};