#pragma once

#include <SDL.h>
#include <boiler/messaging/Observer.hpp>
#include <boiler/util/Rectangle.hpp>
#include <boiler/rendering/Renderer.hpp>

class Debug : public Observer {
private:
    FRect _rect;
    float _fps;
    Uint64 _lastUpdate;

    Renderer *_renderer;

public:
    Debug(Renderer *renderer, const FRect &rect);

    ~Debug() override;

    void Update();

    void Draw(const Renderer &renderer);

    void HandleMessage(EventType type, void *subject) override;
};