//
// Created by max on 2/16/2025.
//

#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "common/common.h"


class BaseCharacter {
protected:
    int health;
    int maxHealth;

    int attackDamage;
public:
    BaseCharacter();

    int getHealth();
    bool isDead();
    int takeDamage(int amount);
    bool Attack(BaseCharacter* target);
};



#endif //BASECHARACTER_H
