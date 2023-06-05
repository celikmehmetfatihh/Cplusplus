#include "Swordsman.h"

Swordsman::Swordsman() {
    name = 'W';
    life = 6;
    damage = 4;
    maxLimitUsage = -1; // represents unlimited
}

void Swordsman::specialAttack() {} // defining this just to make this non-abstract class.
