#include <boiler/core/Time.hpp>

float Time::timeScale {1};
Uint32 Time::lastTick {};

void Time::SetLastTick() {
    lastTick = SDL_GetTicks();
}

float Time::GetDeltaTime() {
    return ((SDL_GetTicks() - lastTick) / 1000.0f) * timeScale;
}

float Time::GetTimeScale() {
    return timeScale;
}

void Time::SetTimeScale(float value) {
    timeScale = value;
    if(timeScale < 0) timeScale = 0;
}