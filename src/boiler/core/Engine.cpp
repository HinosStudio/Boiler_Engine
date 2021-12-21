#include <boiler/core/Engine.hpp>
#include <boiler/events/EventDispatcher.hpp>

Engine::Engine() : _running{true}, _time{} {
    _eventSystem = EventSystem::Instance();
    _renderingEngine = std::make_unique<RenderingEngine>(680, 420, "Boiler Engine");
}

Engine::~Engine() {
    if(_init) Shutdown();
    SDL_Quit();
}

void Engine::Initialize() {
    _eventSystem->Subscribe(SHUTDOWN, this);
    _init = true;
}

void Engine::Shutdown() {
    _eventSystem->Unsubscribe(SHUTDOWN, this);
    _init = false;
}

void Engine::Run() {
    Time::SetLastTick();

    while (true) {
        _eventSystem->PollEvents();

        if(!_running) break;

        _renderingEngine->OnStartFrame();
        _renderingEngine->OnEndFrame();
    }
}

void Engine::HandleMessage(Event &event){
    EventDispatcher dispatcher{event};
    dispatcher.Dispatch<ShutdownEvent>(std::bind(&Engine::OnShutdownEvent, this, std::placeholders::_1));
}

bool Engine::OnShutdownEvent(ShutdownEvent &event) {
    _running = false;
    return true;
}
