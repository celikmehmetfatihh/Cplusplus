#include "Bowman.h"

Bowman::Bowman() {
    name = 'B';
    life = 12;
    damage = 3;
    maxLimitUsage = -1; // represents unlimited
}

void Bowman::specialAttack() {} // defining this just to make this non-abstract class.