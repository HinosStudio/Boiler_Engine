#ifndef BOILER_ENGINE_ENGINE_HPP
#define BOILER_ENGINE_ENGINE_HPP

#include <memory>
#include <Engine/Input/IInputSubsystem.hpp>

#include "Engine/Rendering/IRenderSubsystem.hpp"
#include "Engine/Core/Time.hpp"

class Engine {
private:
    static bool init;
    bool _running;
    Time _time;

    std::unique_ptr<IInputSubsystem> _input;
    std::unique_ptr<IRenderSubsystem> _renderer;

public:
    Engine(std::unique_ptr<IInputSubsystem>& input, std::unique_ptr<IRenderSubsystem>& renderer);

    static bool Init();

    void Initialize();
    void Run();
    void Shutdown();
};

#endif //BOILER_ENGINE_ENGINE_HPP
