//
// Created by max on 2/16/2025.
//

#include "BaseCharacter.h"

#include <cstdio>

BaseCharacter::BaseCharacter() {
    health = 100;
    maxHealth = 100;
    attackDamage = 10;
}

int BaseCharacter::getHealth() {
    printf("health = %d\n", health);
    return health;
}
bool BaseCharacter::isDead() {
    return health <= 0;
}
// Return: Remaining health of target
int BaseCharacter::takeDamage(int amount) {
    printf("Current health %d Taking damage : %d\n",health, amount);
    health = health - amount;
    if (this->isDead()) {
        return -1;
    }
    return health;
}
bool BaseCharacter::Attack(BaseCharacter* target) {
    if (target->isDead()) {
        return false;
    }
    target->takeDamage(attackDamage);
    return true;
}
