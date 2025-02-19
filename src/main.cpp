#include <iostream>
#include "game/BaseCharacter.h"
#include "game/LocalPlayer.h"
#include "game/BossCharacter.h"
#include "game/Game.h"

int main() {
    printf("Hello World\n");
    // BossCharacter* selene = new BossCharacter();
    //
    // selene->getHealth();

    Game* game = new Game();
    game->initGameLoop();

}
