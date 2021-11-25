#ifndef BOILER_ENGINE_ENGINE_HPP
#define BOILER_ENGINE_ENGINE_HPP

#include <memory>
#include <core/Time.hpp>
#include <rendering/RenderingEngine.hpp>

class Engine {
private:
    static bool init;
    bool _running;
    Time _time;

    RenderingEngine _renderEngine;

public:
    Engine();
    ~Engine();

    static bool Init();

    //void Initialize();
    //void Shutdown();
    void Run();
};

#endif //BOILER_ENGINE_ENGINE_HPP
