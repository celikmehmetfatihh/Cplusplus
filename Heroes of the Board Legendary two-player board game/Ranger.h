#ifndef HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_RANGER_H
#define HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_RANGER_H

#include "Melee.h"

class Ranger : public Melee{
public:
    Ranger();
    void specialAttack() override;
};


#endif //HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_RANGER_H
