#include "Ranger.h"

Ranger::Ranger() {
    name = 'R';
    life = 8;
    damage = 6;
    maxLimitUsage = 2;
}

void Ranger::specialAttack() {} // defining this just to make this non-abstract class.
