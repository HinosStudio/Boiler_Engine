#pragma once

#include <SDL.h>
#include <util/Rect.hpp>
#include "Renderer.hpp"

class Debug : Observer {
private:
    Rect _rect;
    float _fps;
    Uint64 _lastUpdate;

    Renderer *_renderer;

public:
    Debug(Renderer *renderer, const Rect &rect);

    ~Debug() override;

    void Update();

    void Draw(const Renderer &renderer);

    void HandleMessage(Observable *subject) override;
};