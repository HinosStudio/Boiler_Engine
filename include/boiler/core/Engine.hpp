#pragma once

#include <boiler/events/EventSystem.hpp>
#include <boiler/rendering/RenderingEngine.hpp>
#include <boiler/core/Time.hpp>
#include <boiler/messaging/Observer.hpp>

#include <memory>

class Engine : public Observer {
private:
    bool _init;
    bool _running;
    Time _time;

    EventSystem *_eventSystem;
    std::unique_ptr<RenderingEngine> _renderingEngine;

public:
    Engine();
    ~Engine() override;

    bool Init() const {return _init;}

    /**
     * Runs once at the start to initialize the submodule
     */
    void Initialize();

    /**
     * Runs once at the end shutdown the submodules
     */
    void Shutdown();

    /**
     * Start the simulation loop
     */
    void Run();

    void HandleMessage(Event &event) override;
    bool OnShutdownEvent(ShutdownEvent &event);
};