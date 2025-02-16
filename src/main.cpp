#include <iostream>
#include "game/BaseCharacter.h"
#include "game/LocalPlayer.h"
#include "game/BossCharacter.h"

int main() {
    printf("Hello World\n");
    LocalPlayer* localPlayer = new LocalPlayer();
    BossCharacter* selene = new BossCharacter();
    localPlayer->Attack(selene);
    selene->getHealth();
}
