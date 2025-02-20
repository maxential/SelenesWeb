//
// Created by max on 2/17/2025.
//

#include <iostream>

#include "game.h"

Game::Game() {
    local_player = std::make_unique<LocalPlayer>();

    total_rooms_explored = 0;
    current_room = 0;
}

int Game::initGameLoop() {
    printf("starting da game\n");
    while (true) {
        // game shit here lol
        if (!canGameContinue()) {
            printf("game over\n");
            return 0;
        }
        current_room++;
        startRoomEncounter();
        printf("room completed\n");
    }

    return true;
}

bool Game::canGameContinue() {
    if (local_player->isDead())
        return false;

    return true;
}

int Game::doCombatChoice(BaseCharacter* target) {
    int choice{0};
    while (choice < CombatChoice::CC_HIT || choice > CombatChoice::CC_END) {
        printf("Choose your choice:\n");
        printf("1: HIT\n");
        printf("2: SLAP\n");
        printf("3: KICK\n");
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    switch (choice) {
        case CombatChoice::CC_HIT: {
            printf("you choose to HIT this MAN\n");
            local_player->Attack(target);
            break;
        }
        case CombatChoice::CC_SLAP: {
            printf("you choose to slappington\n");
            local_player->Attack(target);
            break;
        }
        case CombatChoice::CC_KICK: {
            printf("you choose to kcik\n");
            local_player->Attack(target);
            break;
        }
    }
    printf("returning true");
    return true;
}

// make enemies in here and start turn based fight
int Game::startRoomEncounter() {
    // spawn enemies
    enemies_amount = 1 + current_room;
    std::vector<BaseCharacter*> enemies;
    for (int i = 0; i < enemies_amount; ++i) {
        BaseCharacter* enemy = new BaseCharacter();
        enemies.push_back(enemy);
    }

    // Combat loop
    while (enemies.size() > 0) {
        if (enemies[0]->isDead()) {
            printf("Enemy has died!\n");

            delete enemies[0];
            enemies.erase(enemies.begin());  // Remove the dead enemy from the vector
            continue;
        }

        doCombatChoice(enemies[0]);
    }

    return true;
}

int Game::endRoomEncounter() {
    printf("yo u didn't die :D\n");
    return true;
}

int Game::breakChoice() {
    int choice;
    while (choice < BreakChoice::BC_NONE || choice > BreakChoice::BC_HEAL) {
        printf("Choose your choice:\n");
        printf("1: Pray\n");
        printf("2: Heal\n");
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    switch (choice) {
        case BreakChoice::BC_NONE: {
            printf("you choose to do nothing\n");
            break;
        }
        case BreakChoice::BC_PRAY: {
            printf("you choose to pray\n");
            break;
        }
        case BreakChoice::BC_HEAL: {
            printf("you choose to heal\n");
            break;
        }
    }
    return true;
}

