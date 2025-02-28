#include <iostream>
#include "game/BaseCharacter.h"
#include "game/LocalPlayer.h"
#include "game/BossCharacter.h"
#include "game/Game.h"
#include "SDL3/SDL.h"
#include <thread>

#include "Engine/Engine.h"

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        SDL_Log("sdl failed to initialize with error %s", SDL_GetError());
        return -1;
    }
    SDL_Log("initialized successfully");
    printf("hi teams\n");
    SDL_Delay(1500);
    std::shared_ptr<Window> windowz  = std::make_shared<Window>();
    windowz->CreateSDLWindow("vagina", 640,480 );
    glm::ivec2 window_size = { 640,480 };
    Engine* engine = new Engine();
    engine->CreateGameWindow("vagina", window_size);

     engine->RenderGameWindow();
    // Game* game = new Game();
    // game->initGameLoop();
}
