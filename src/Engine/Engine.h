//
// Created by max on 2/20/2025.
//

#ifndef ENGINE_H
#define ENGINE_H

#include "Engine/Renderer.h"

class Engine {
public:
    Engine();
    ~Engine();

    private:
        std::shared_ptr<Renderer> renderer;
        std::shared_ptr<Window> window;
    };



#endif //ENGINE_H
