#pragma once

#include <memory>

class Window;
class Renderer;

class RenderingEngine{
private:
    std::unique_ptr<Window> _window;
    std::unique_ptr<Renderer> _renderer;

public:
    RenderingEngine();
    ~RenderingEngine();

    const std::unique_ptr<Renderer>& GetRenderer() const;

    void OnStartFrame();
    void OnEndFrame();
};
