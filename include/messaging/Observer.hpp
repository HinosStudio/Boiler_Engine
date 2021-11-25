#pragma once

class Observable;

class Observer{
public:
    virtual ~Observer() = default;
    virtual void HandleMessage(Observable* subject) = 0;

protected:
    Observer() = default;
};
