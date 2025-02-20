//
// Created by max on 2/17/2025.
//

#ifndef GAME_H
#define GAME_H
#include "common/common.h"

#include "BossCharacter.h"
#include "LocalPlayer.h"

class Game {
private:
    enum BreakChoice {
        BC_NONE = 0,
        BC_PRAY,
        BC_HEAL,


        BC_END
    };
    enum CombatChoice {
        CC_NONEE = 0,
        CC_HIT,
        CC_SLAP,
        CC_KICK,


        CC_END
    };
    std::unique_ptr<LocalPlayer> local_player;
    int total_rooms_explored;
    int current_room;

    int enemies_amount;

public:
    Game();

    int startRoomEncounter();
    int endRoomEncounter();
    int breakChoice();
    bool canGameContinue();
    int doCombatChoice(BaseCharacter* target);

    int initGameLoop();
};



#endif //GAME_H
