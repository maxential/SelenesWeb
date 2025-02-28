//
// Created by max on 2/21/2025.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <memory>
#include <functional>
#include <thread>
#include "Window.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl3.h"
#include "imgui/imgui_impl_sdlrenderer3.h"

class Renderer
{
public:
    Renderer(std::unique_ptr<Window> _window);
    ~Renderer();

    SDL_Renderer* getSDLRenderer() const { return renderer; }
    glm::i32vec2 getWindowSize();
    void render(const std::function<void()>& callback);
    bool quit();
private:
    bool quit_flag;
    std::unique_ptr<Window> window;
    SDL_Renderer* renderer;
    glm::i32vec2 windowSize;
};



#endif //RENDERER_H
