#ifndef HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_MELEE_H
#define HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_MELEE_H

#include "Pieces.h"

class Melee : public Pieces {
public:
    int validator(int column) override;
};


#endif //HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_MELEE_H
