#ifndef BOILER_ENGINE_SDLINPUTSUBSYSTEM_HPP
#define BOILER_ENGINE_SDLINPUTSUBSYSTEM_HPP

#include <IInputSubsystem.hpp>

class SDLInputSubsystem : public IInputSubsystem {
private:

public:
    void Initialize() override;
    void Update() override;
    void Shutdown() override;
};

#endif //BOILER_ENGINE_SDLINPUTSUBSYSTEM_HPP
