#pragma once

#include <map>
#include <vector>

class Observer;

enum EventType {
    EMPTY,
    SHUTDOWN,
    KEY_EVENT,
    MOUSE_EVENT
};

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

    void Notify(EventType, void *payload);

    void PollEvents();
};