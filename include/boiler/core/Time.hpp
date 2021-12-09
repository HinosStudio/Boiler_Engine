#pragma once

#include <SDL.h>

class Time {
private:
    static float timeScale;
    static Uint32 lastTick;

public:
    static void SetLastTick();
    static float GetDeltaTime();
    static float GetTimeScale();
    static void SetTimeScale(float value);
};
