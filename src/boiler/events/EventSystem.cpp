#include <boiler/events/EventSystem.hpp>
#include <boiler/messaging/Observer.hpp>
#include <SDL.h>
#include <sstream>

EventSystem *EventSystem::_instance{nullptr};

EventSystem *EventSystem::Instance() {
    if (!_instance)
        _instance = new EventSystem;
    return _instance;
}

EventSystem::EventSystem() {
    if (SDL_Init(SDL_INIT_EVENTS) < 0) {
        std::ostringstream oss;
        oss << "[EVENT-SYSTEM] Could not initialize events, Error " << SDL_GetError();
        throw std::runtime_error{oss.str()};
    }
}

EventSystem::~EventSystem() {
    SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

void EventSystem::Subscribe(EventType eventType, Observer *observer) {
    _observers.try_emplace(eventType);
    _observers.at(eventType).push_back(observer);
}

void EventSystem::Unsubscribe(EventType eventType, Observer *observer) {
    if (_observers.count(eventType) > 0) {
        auto &observers = _observers.at(eventType);
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
}

void EventSystem::Notify(EventType eventType, void *payload) {
    if (_observers.count(eventType) > 0) {
        auto &observers = _observers.at(eventType);
        for (const auto &item: observers) item->HandleMessage(eventType, payload);
    }
}

void EventSystem::PollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {

            case SDL_QUIT:
                Notify(SHUTDOWN, nullptr);
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                Notify(KEY_EVENT, nullptr);
                break;

            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                Notify(MOUSE_EVENT, nullptr);
                break;
        }
    }
}
