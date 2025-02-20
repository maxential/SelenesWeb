#include <iostream>
#include "game/BaseCharacter.h"
#include "game/LocalPlayer.h"
#include "game/BossCharacter.h"
#include "game/Game.h"

int main() {
    Game* game = new Game();
    game->initGameLoop();

}
