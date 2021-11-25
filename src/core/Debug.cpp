#include <core/Debug.hpp>
#include<string>
#include <cmath>

Debug::Debug(Renderer* renderer, const FRect &rect) : _renderer{renderer}, _rect{rect}, _fps{}, _lastUpdate {SDL_GetPerformanceCounter()} {
    _renderer->Subscribe(this);
}

Debug::~Debug() noexcept {
    _renderer->Unsubscribe(this);
}

void Debug::Update(){
    _fps = std::round(1.0f / ((SDL_GetPerformanceCounter() - _lastUpdate) / (float)SDL_GetPerformanceFrequency()));
    _lastUpdate = SDL_GetPerformanceCounter();
}

void Debug::Draw(const Renderer &renderer) {
    std::string text {"FPS: "};
    text.append(std::to_string(_fps));
    renderer.DrawRectangle(_rect, {80,80,80,255});
    renderer.DrawText(_rect, text, {10,10,10,255});
}

void Debug::HandleMessage(Observable *subject) {
    if(subject == _renderer) Draw(*_renderer);
}