#ifndef HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_PIECES_H
#define HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_PIECES_H


class Pieces {
protected:
    char name;
    int life;
    int damage;
    int maxLimitUsage;
    int count;
public:
    Pieces();
    Pieces(char name);
    virtual void specialAttack() = 0; // to make it abstract class
    virtual int validator(int column);
    char getName() const;
};


#endif //HEROES_OF_THE_BOARD_LEGENDARY_TWO_PLAYER_BOARD_GAME_PIECES_H
