//
// Created by max on 2/16/2025.
//

#include "BaseCharacter.h"

#include <cstdio>

BaseCharacter::BaseCharacter() {
    health = 100;
    max_health = 100;
    attack_damage = 10;
}

BaseCharacter::BaseCharacter(int maxHealth, int attackDamage) {
    health = maxHealth;
    max_health = maxHealth;;
    attack_damage = attackDamage;
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
    target->takeDamage(attack_damage);
    return true;
}
