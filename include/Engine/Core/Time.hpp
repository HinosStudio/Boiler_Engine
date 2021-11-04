#ifndef FLATGALAXY_TIME_HPP
#define FLATGALAXY_TIME_HPP

#include <chrono>

class Time {
private:
    static float time_scale;
    static std::chrono::time_point<std::chrono::steady_clock> _lastTick;

public:

    void LastTick();
    static float DeltaTime();
    static float TimeScale(); static void TimeScale(float value);
};

#endif //FLATGALAXY_TIME_HPP
