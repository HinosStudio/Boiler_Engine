#include <boiler/core/Engine.hpp>
#include <string>
#include <sstream>

bool Engine::init{false};

bool Engine::Init() {
    return init;
}

Engine::Engine() : _running{true}, _time{} {
    _eventSystem = std::unique_ptr<EventSystem>{EventSystem::Instance()};
    _renderingEngine = std::make_unique<RenderingEngine>(680, 420, "Boiler Engine");
}

Engine::~Engine() {
    if(init) Shutdown();
    SDL_Quit();
}

void Engine::Initialize() {
    _eventSystem->Subscribe(SHUTDOWN, this);
    init = true;
}

void Engine::Shutdown() {
    _eventSystem->Unsubscribe(SHUTDOWN, this);
    init = false;
}

void Engine::Run() {
    _running = true;
    Time::SetLastTick();

    while (true) {
        _eventSystem->PollEvents();

        if(!_running) break;

        _renderingEngine->OnStartFrame();
        _renderingEngine->OnEndFrame();
    }
}

void Engine::HandleMessage(EventType type, void *subject){
    if(type == SHUTDOWN) _running = false;
}
