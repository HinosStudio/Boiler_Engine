#include <boiler/input/InputHandler.hpp>
#include <SDL.h>
#include <iostream>
#include <algorithm>

InputHandler::InputHandler() {
    _keyStates = SDL_GetKeyboardState(&_keyCount);
    _prevKeyStates = new Uint8[_keyCount];
    memcpy_s(_prevKeyStates, _keyCount, _keyStates, _keyCount);
}

InputHandler::~InputHandler() noexcept {
    delete[] _prevKeyStates;
    _prevKeyStates = nullptr;
}

void InputHandler::PreUpdate() {
    _mouseButton = SDL_GetMouseState(&_mouseX, &_mouseY);

    for (auto const&[key, val]: _actionMap) {
        if (std::all_of(val.begin(), val.end(), [&](auto &sc) { return GetKeyPressed(sc); })) {
            InputActionEvent event{key};
            _eventCallback(event);
        }
    }
}

void InputHandler::PostUpdate() {
    memcpy_s(_prevKeyStates, _keyCount, _keyStates, _keyCount);
}

void InputHandler::AddAction(const std::string &name, const std::vector<int>& keyCodes) {
    _actionMap.insert_or_assign(name, keyCodes);
}

bool InputHandler::GetKeyDown(int keyCode) {
    return _keyStates[keyCode];
}

bool InputHandler::GetKeyPressed(int keyCode) {
    return !_prevKeyStates[keyCode] && _keyStates[keyCode];
}

bool InputHandler::GetKeyReleased(int keyCode) {
    return _prevKeyStates[keyCode] && !_keyStates[keyCode];
}

V2 InputHandler::GetMousePosition() {
    return V2{(float)_mouseX, (float)_mouseY};
}