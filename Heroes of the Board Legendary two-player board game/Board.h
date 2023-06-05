#ifndef HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_BOARD_H
#define HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_BOARD_H

#include "Pieces.h"

class Board {
private:
    int row;
    int column;
    int health;
    char **board;
    Pieces *pieces[12]; //since board is 4x3, the max piece number can board take is 12.
    int pieceCount; // counts how many current pieces exists in the board.
public:
    Board();
    void displayBoard();
    void addPiece();
    int getHealth() const;
};


#endif //HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_BOARD_H
