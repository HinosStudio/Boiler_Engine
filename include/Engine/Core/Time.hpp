#pragma once

#include <SDL.h>

class Time {
private:
    static float time_scale;
    static Uint32 last_tick;

public:
    static void set_last_tick();
    static float get_delta_time();
    static float get_time_scale();
    static void set_time_scale(float value);
};
