#pragma once

#include <boiler/events/EventSystem.hpp>
#include <boiler/rendering/RenderingEngine.hpp>
#include <boiler/core/Time.hpp>
#include <boiler/messaging/Observer.hpp>

#include <memory>

class Engine : public Observer {
private:
    static bool init;
    bool _running;
    Time _time;

    std::unique_ptr<EventSystem> _eventSystem;
    std::unique_ptr<RenderingEngine> _renderingEngine;

public:
    Engine();
    ~Engine() override;

    static bool Init();

    void Initialize();
    void Shutdown();

    void Run();

    void HandleMessage(EventType type, void *subject) override;
};