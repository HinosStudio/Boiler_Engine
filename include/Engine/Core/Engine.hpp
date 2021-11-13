#ifndef BOILER_ENGINE_ENGINE_HPP
#define BOILER_ENGINE_ENGINE_HPP

#include <memory>
#include "../Interfaces/IInputSubsystem.hpp"
#include "../Interfaces/IRenderSubsystem.hpp"
#include "Time.hpp"
#include "Scene.hpp"

class Engine {
private:
    static bool init;
    bool _running;
    Time _time;

    std::unique_ptr<Scene> _scene;

    std::unique_ptr<IInputSubsystem> _input;
    std::unique_ptr<IRenderSubsystem> _renderer;

public:
    Engine();

    static bool Init();

    void Initialize();
    void Run();
    void Shutdown();
};

#endif //BOILER_ENGINE_ENGINE_HPP
