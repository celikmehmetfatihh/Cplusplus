#include <iostream>
#include <cstdlib> // for rand function
using namespace std;

#include "Board.h"

class Game{
private:
    Board *b1 = new Board();
    Board *b2 = new Board();
public:
    Board *getB1() const {return b1;}
    Board *getB2() const {return b2;}
};

int main() {
    srand(time(0)); // Seed the random number generator with the current time to get different values in each execution
    Game g;
    cout << "Welcome to Heroes of the Board: Legendary two-player board game!" << endl << endl;
    int turn = rand() % 2 + 1; // if turn is 1, player 1 starts, if turn is 2 player 2 starts the game.
    if (turn == 1)
        cout << "Player 1 starts the game!" << endl;
    else
        cout << "Player 2 starts the game!" << endl;

    int finishFlag;
    do {
        finishFlag = 1;

        if (turn == 1) {
            cout << "-----Player 1's turn-----" << endl;
             g.getB1()->addPiece();
             cout << "-----Player 1's board-----" << endl;
            g.getB1()->displayBoard();

            cout << "-----Player 2's turn-----" << endl;
            g.getB2()->addPiece();
            cout << "-----Player 2's board-----" << endl;
            g.getB2()->displayBoard();

        }
        else { // turn == 2
            cout << "-----Player 2's turn-----" << endl;
            g.getB2()->addPiece();
            cout << "-----Player 2's board-----" << endl;
            g.getB2()->displayBoard();

            cout << "-----Player 1's turn-----" << endl;
            g.getB1()->addPiece();
            cout << "-----Player 1's board-----" << endl;
            g.getB1()->displayBoard();
        }

        if (g.getB1()->getHealth() > 0 && g.getB2()->getHealth() > 0)
            finishFlag = 0;

    }while (!finishFlag);

    return 0;
}
