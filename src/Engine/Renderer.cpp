//
// Created by max on 2/21/2025.
//

#include "Renderer.h"

#include <complex.h>

#include "InputHandler.h"

Renderer::Renderer(std::unique_ptr<Window> _window)
    : window(std::move(_window))
{

    renderer = SDL_CreateRenderer(window->getSDLWindow(), NULL);
    if (!renderer) {
        SDL_Log("Failed to create renderer with error %s", SDL_GetError());
    }
}

Renderer::~Renderer()
{
    if (renderer) {
        SDL_Log("shutdown");
        ImGui_ImplSDLRenderer3_Shutdown();
        ImGui_ImplSDL3_Shutdown();
        ImGui::DestroyContext();
        SDL_DestroyRenderer(renderer);
    }
}

bool Renderer::quit() {
    quit_flag = true;
}

void Renderer::render(const std::function<void()>& callback)
{
    SDL_Log("starting render loop");

    ImGui::CreateContext();
    ImGui_ImplSDL3_InitForSDLRenderer(
        window->getSDLWindow(),
        renderer
    );
    ImGui_ImplSDLRenderer3_Init(renderer);
    ImGui::GetIO().IniFilename = nullptr;

    SDL_Event event;
    while (!quit_flag)
    {
        while (SDL_PollEvent(&event)) {
            InputHandler::getInstance()->UpdateFromEvent(&event);
            ImGui_ImplSDL3_ProcessEvent(&event);
        }

        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_RenderClear(renderer);

        ImGui::NewFrame();

        callback();

        ImGui::Render();
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }

}

glm::i32vec2 Renderer::getWindowSize() {
    glm::i32vec2 size;
    SDL_GetCurrentRenderOutputSize(renderer, &size.x, &size.y);
    return size;
}