#pragma once

#include <SDL.h>
#include <util/Rectangle.hpp>
#include <rendering/Renderer.hpp>

class Debug : Observer {
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

    void HandleMessage(Observable *subject) override;
};