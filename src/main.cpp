#include <iostream>
#include "game/BaseCharacter.h"
#include "game/LocalPlayer.h"
#include "game/BossCharacter.h"
#include "game/Game.h"
#include "SDL3/SDL.h"
#include <thread>
int main() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        SDL_Log("sdl failed to initialize with error %s", SDL_GetError());
        return -1;
    }
    SDL_Log("initialized successfully");
    SDL_Delay(1500);
    Game* game = new Game();
    game->initGameLoop();
}
