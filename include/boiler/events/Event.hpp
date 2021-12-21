#pragma once

enum EventType{
    SHUTDOWN,
    KEY_PRESSED, KEY_RELEASED, KEY_EVENT,
    MOUSE_EVENT,
    INPUT_ACTION_EVENT,
    RENDER_EVENT
};

enum EventCategory{

};

class Event {
private:
    bool _handled{false};
public:
    Event() = default;
    virtual ~Event() = default;

    virtual EventType GetEventType() const = 0;
};

class ShutdownEvent : public Event {
public:
    ShutdownEvent() = default;

    static EventType GetStaticType() {return SHUTDOWN;}

    EventType GetEventType() const override {return SHUTDOWN;}
};

class KeyEvent : public Event{
private:
    int _keyCode;

public:
    KeyEvent(int keyCode);
};

class KeyPressedEvent : public KeyEvent {
public:
    KeyPressedEvent(int keyCode) : KeyEvent{keyCode} {}

    static EventType GetStaticType() {return KEY_PRESSED;}

    EventType GetEventType() const override {return KEY_PRESSED;}
};

class KeyReleasedEvent : public KeyEvent {
public:
    KeyReleasedEvent(int keyCode) : KeyEvent{keyCode} {}

    static EventType GetStaticType() {return KEY_RELEASED;}

    EventType GetEventType() const override {return KEY_RELEASED;}
};