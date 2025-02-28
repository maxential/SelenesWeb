//
// Created by max on 2/20/2025.
//

#include "Engine.h"

Engine::Engine() {
    window = std::make_unique<Window>();
}

int Engine::CreateGameWindow(char *window_name, glm::ivec2 size) {
    SDL_Log("size: x : %d y : %d", size.x, size.y);
    if (!window) {
        SDL_Log("Window is not initialized.");
        return -1;  // Or handle error appropriately
    }

    window->CreateSDLWindow(window_name, size.x, size.y);
    return true;
}

int Engine::RenderGameWindow() {
    renderer = std::make_unique<Renderer>(std::move(window));
    renderer->render([&]() {
        ImGui::Begin("Game Window");
        {

        }
        ImGui::End();
    });
    return true;
}
