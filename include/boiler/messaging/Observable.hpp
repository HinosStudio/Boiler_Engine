#pragma once

#include <boiler/messaging/Observer.hpp>
#include <vector>

class Observable {
private:
    std::vector<Observer *> _observers;
public:
    virtual ~Observable() = default;

    virtual void Subscribe(Observer* observer);
    virtual void Unsubscribe(Observer* observer);
    virtual void Notify(Event &event);

protected:
    Observable() = default;
};
