#include "Spearman.h"

Spearman::Spearman() {
    name = 'S';
    life = 6;
    damage = 3;
    maxLimitUsage = -1; // represents unlimited
}

void Spearman::specialAttack() {} // defining this just to make this non-abstract class.