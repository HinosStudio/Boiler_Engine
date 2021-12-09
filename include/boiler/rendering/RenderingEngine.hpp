#pragma once

#include <memory>
#include <string>

class Window;
class Renderer;

class RenderingEngine{
private:
    bool _running;

    std::unique_ptr<Window> _window;
    std::unique_ptr<Renderer> _renderer;

public:
    RenderingEngine(const int width, const int height, const std::string &name);
    ~RenderingEngine();

    void ShutDown();

    bool IsRunning() const;

    const std::unique_ptr<Renderer>& GetRenderer() const;

    void OnStartFrame();
    void OnEndFrame();
};
