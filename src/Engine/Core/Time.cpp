#include "Engine/Core/Time.hpp"

float Time::time_scale {1};
std::chrono::time_point<std::chrono::steady_clock> Time::_lastTick;

void Time::LastTick() {
    _lastTick = std::chrono::high_resolution_clock::now();
}

float Time::DeltaTime() {
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now - _lastTick).count() * 0.001f; //((SDL_GetTicks() - last_tick) / 1000.0f) * time_scale;
}

float Time::TimeScale() {
    return time_scale;
}

void Time::TimeScale(float value) {
    time_scale = value;
    if(time_scale < 0) time_scale = 0;
}