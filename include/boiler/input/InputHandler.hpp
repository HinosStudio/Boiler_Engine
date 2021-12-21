#pragma once

#include <utility>
#include <vector>
#include <SDL.h>
#include <boiler/messaging/Observer.hpp>
#include <string>
#include <functional>
#include "boiler/util/Vector.hpp"

class InputActionEvent : public Event {
private:
    std::string _action;
public:
    InputActionEvent(std::string action) : _action{std::move(action)}{}

    std::string GetAction() const {return _action;}

    static EventType GetStaticType(){return INPUT_ACTION_EVENT;}
    EventType GetEventType() const override{return INPUT_ACTION_EVENT;}
};

class InputHandler {
private:
    int _keyCount;
    const Uint8 *_keyStates;
    Uint8 *_prevKeyStates;

    int _mouseY, _mouseX;
    Uint8 _mouseButton;

    std::map<std::string, std::vector<int>> _actionMap;

    std::function<void(Event&)> _eventCallback;

public:
    InputHandler();
    ~InputHandler();

    void PreUpdate();
    void PostUpdate();

    void AddAction(const std::string &name, const std::vector<int>& keyCodes);

    void SetEventCallback(std::function<void(Event&)> func) {_eventCallback = std::move(func);}

    bool GetKeyDown(int keyCode);
    bool GetKeyPressed(int keyCode);
    bool GetKeyReleased(int keyCode);

    V2 GetMousePosition();
};