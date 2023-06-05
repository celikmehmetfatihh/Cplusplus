#include "Elf.h"

Elf::Elf() {
    name = 'E';
    life = 8;
    damage = 6;
    maxLimitUsage = 3;
}

void Elf::specialAttack() {} // defining this just to make this non-abstract class.
