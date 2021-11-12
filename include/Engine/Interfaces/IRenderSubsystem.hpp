#ifndef BOILER_ENGINE_IRENDERSUBSYSTEM_HPP
#define BOILER_ENGINE_IRENDERSUBSYSTEM_HPP

class IRenderSubsystem {
public:
    virtual void Initialize() = 0;
    virtual void OnBegin() = 0;
    virtual void OnEnd() = 0;
    virtual void Shutdown() = 0;
};

#endif //BOILER_ENGINE_IRENDERSUBSYSTEM_HPP