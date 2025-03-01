//
// Created by max on 2/20/2025.
//

#ifndef ENGINE_H
#define ENGINE_H

#include "Engine/Renderer.h"
#include "common/math.h"

class Engine {
public:
    Engine();
    ~Engine();

    int CreateGameWindow(char* window_name, glm::ivec2 size);
    int RenderGameWindow();
    int CreateRenderer();

    private:
        std::unique_ptr<Renderer> renderer;
        std::unique_ptr<Window> window;
    };



#endif //ENGINE_H
