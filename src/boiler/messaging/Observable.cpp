#include <boiler/messaging/Observable.hpp>

void Observable::Subscribe(Observer *observer) {
    _observers.push_back(observer);
}

void Observable::Unsubscribe(Observer *observer) {
    _observers.erase(
            std::remove(_observers.begin(), _observers.end(), observer),
            _observers.end()
    );
}

void Observable::Notify(Event &event){
    for(auto o : _observers) o->HandleMessage(event);
}

