#ifndef HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_SPEARMAN_H
#define HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_SPEARMAN_H

#include "Melee.h"

class Spearman : public Melee{
public:
    Spearman();
    void specialAttack() override;
};


#endif //HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_SPEARMAN_H
