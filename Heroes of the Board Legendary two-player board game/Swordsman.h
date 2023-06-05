#ifndef HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_SWORDSMAN_H
#define HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_SWORDSMAN_H

#include "Melee.h"

class Swordsman : public Melee{
public:
    Swordsman();
    void specialAttack() override;
};


#endif //HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_SWORDSMAN_H
