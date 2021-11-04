#include <iostream>
#include "Engine/Core/Engine.hpp"

bool Engine::init {false};
bool Engine::Init() {return init;}


Engine::Engine(std::unique_ptr<IInputSubsystem>& input, std::unique_ptr<IRenderSubsystem>& renderer) : _running{false}, _time{}, _input{std::move(input)}, _renderer{std::move(renderer)} {

};

void Engine::Initialize() {
    //TODO: initialize subsystems
    _input->Initialize();
    _renderer->Initialize();

    _time.LastTick();
    init = true;
}

void Engine::Run() {
    _running = true;
    while(_running) {
        _input->Update();
        //TODO: update physics
        //TODO: update Logic
        std::cout << "DeltaTime: " << _time.DeltaTime() << '\n';
        _time.LastTick();
        _renderer->Render();
    }
}

void Engine::Shutdown() {
    //TODO: Clean up subsystems
    _renderer->Shutdown();
    _input->Shutdown();
}
