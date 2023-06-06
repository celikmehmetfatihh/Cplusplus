#ifndef HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_BOARD_H
#define HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_BOARD_H

#include "Pieces.h"

class Board {
private:
    int health;
    Pieces *board[4][3];
    int pieceCount; // counts how many current pieces exists in the board.
public:
    Board();
    ~Board();
    void displayBoard(Board &b1);
    void addPiece();
    int getHealth() const;
    void attack(Board &b);
};


#endif //HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_BOARD_H
