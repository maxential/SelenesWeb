//
// Created by max on 2/20/2025.
//

#include "Engine.h"

Engine::Engine() {
    window = std::make_shared<Window>();
    renderer = std::make_shared<Renderer>(window);
}
