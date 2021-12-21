#include <boiler/events/EventSystem.hpp>
#include <boiler/messaging/Observer.hpp>
#include <SDL.h>
#include <sstream>
#include "boiler/events/Event.hpp"

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

void EventSystem::Notify(Event &event) {
    if (_observers.count(event.GetEventType()) > 0) {
        auto &observers = _observers.at(event.GetEventType());
        for (const auto &item: observers) item->HandleMessage(event);
    }
}

void EventSystem::PollEvents() {
    SDL_Event sdlEvent;
    ShutdownEvent event;
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {

            case SDL_QUIT:
                Notify(event);
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:

                break;

            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:

                break;
        }
    }
}
