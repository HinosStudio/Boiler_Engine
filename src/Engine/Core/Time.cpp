#include <Time.hpp>

float Time::time_scale {1};
Uint32 Time::last_tick {};

void Time::set_last_tick() {
    last_tick = SDL_GetTicks();
}

float Time::get_delta_time() {
    return ((SDL_GetTicks() - last_tick) / 1000.0f) * time_scale;
}

float Time::get_time_scale() {
    return time_scale;
}

void Time::set_time_scale(float value) {
    time_scale = value;
    if(time_scale < 0) time_scale = 0;
}