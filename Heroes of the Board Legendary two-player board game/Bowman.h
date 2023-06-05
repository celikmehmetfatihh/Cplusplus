#ifndef HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_BOWMAN_H
#define HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_BOWMAN_H

#include "Ranged.h"

class Bowman : public Ranged{
public:
    Bowman();
    void specialAttack() override;
};


#endif //HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_BOWMAN_H
