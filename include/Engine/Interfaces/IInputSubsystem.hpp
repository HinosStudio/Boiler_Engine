#ifndef BOILER_ENGINE_IINPUTSUBSYSTEM_HPP
#define BOILER_ENGINE_IINPUTSUBSYSTEM_HPP

class IInputSubsystem {
public:
    virtual void Initialize() = 0;
    virtual void Update() = 0;
    virtual void Shutdown() = 0;
};

#endif //BOILER_ENGINE_IINPUTSUBSYSTEM_HPP
