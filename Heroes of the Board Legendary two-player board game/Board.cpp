#include "Board.h"
#include <iostream>
#include <limits>
using namespace std;

#include "Elf.h"
#include "Mage.h"
#include "Ranger.h"
#include "Knight.h"
#include "Bowman.h"
#include "Spearman.h"
#include "Swordsman.h"

Board::Board() {
    health = 100;
    int row= 4;
    int column = 3;
    pieceCount = 0;

    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++)
            board[i][j] = nullptr;
    }
}

Board::~Board() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            delete board[i][j];
        }
    }
}

void Board::displayBoard(Board& b1) {
    const int row = 4;
    const int column = 3;

    // Print the column numbers for 'board'
    cout << "  ";
    for (int j = 0; j < column; j++) {
        cout << j + 1 << "     ";
    }

    // Print the column numbers for 'b1.board' in reverse order
    cout << " \t  ";
    for (int j = column; j > 0; j--) {
        cout << j << "     ";
    }
    cout << endl;

    for (int i = 0; i < row; i++) {
        // Print the row number
        cout << char('A' + i) << " ";

        // Print the cells for 'board'
        for (int j = 0; j < column; j++) {
            if (board[i][j] != nullptr && board[i][j]->getLife() != 0) {
                cout << board[i][j]->getName();
                cout << "(" << board[i][j]->getLife() << ")";
            } else {
                cout << "    ";
            }
            cout << " ";
        }

        // Print the row number again for 'b1.board'
        cout << "\t" << char('A' + i) << " ";

        // Print the cells for 'b1.board'
        for (int k = column-1; k >= 0; k--) {
            if (b1.board[i][k] != nullptr && b1.board[i][k]->getLife() != 0) {
                cout << b1.board[i][k]->getName();
                cout << "(" << b1.board[i][k]->getLife() << ")";
            } else {
                cout << "    ";
            }
            cout << " ";
        }
        cout << endl;
    }

    // Print the health status
    cout << "Health: " << health;
    cout << "\t\tHealth: " << b1.health;
    cout << endl << endl;
}




void Board::addPiece() {
    if (pieceCount >= 12)
        cout << "The all of your board's cell is full! It's the next player's turn." << endl;
    else {
        int row, column, flag, totalFlag;
        char myRow;
        do{
            totalFlag = 1;
            do {
                flag = 1;
                cout << endl << "Enter which row you want to enter a piece (A, B, C, D): ";
                cin >> myRow;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Enter which column you want to enter a piece (1, 2, 3): ";
                cin >> column;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (myRow == 'a' || myRow == 'A')
                    row = 1;
                else if (myRow == 'b' || myRow == 'B')
                    row = 2;
                else if (myRow == 'c' || myRow == 'C')
                    row = 3;
                else if (myRow == 'd' || myRow == 'D')
                    row = 4;
                else
                    row = -1;

                if (row < 0 || row > 4 || column < 0 || column > 3) {
                    cout << "The board is 4x3! Please enter a valid cell! " << endl;
                    flag = 0; // if flag is 0 continue to iterate
                }
                else if (board[row - 1][column - 1] != nullptr) {
                    cout << "The cell you entered is full! Please enter a valid cell!" << endl;
                    flag = 0; // if flag is 0 continue to iterate
                }
            } while (!flag);

            int choice, choiceFlag;
            do {
                choiceFlag = 1;
                cout << endl << "What kind of piece you want to add?" << endl;
                cout << "1-) Ranged" << endl;
                cout << "2-) Melee" << endl;
                cout << "Your choice: ";
                cin >> choice;

                if (choice != 1 && choice != 2) {
                    cout << "Please enter a valid choice!" << endl;
                    choiceFlag = 0; // if choiceFlag is 0 continue to iterate
                }
            } while (!choiceFlag);

            if (choice == 1) {
                int pieceChoice, pieceChoiceFlag;
                do {
                    pieceChoiceFlag = 1;
                    cout << endl << "What Ranged piece you want to add? " << endl;
                    cout << "1-) Bowman: life = 12, damage per hit = 3, max round you can use = UNLIMITED" << endl;
                    cout << "2-) Elf: life = 8, damage per hit = 6, max round you can use = 3" << endl;
                    cout << "3-) Mage: life = 4, damage per hit = 8, max round you can use = 2" << endl;
                    cout << "Your choice: ";
                    cin >> pieceChoice;

                    if (pieceChoice != 1 && pieceChoice != 2 && pieceChoice != 3) {
                        cout << "Please enter a valid choice!" << endl;
                        pieceChoiceFlag = 0; // if pieceChoiceFlag is 0 continue to iterate
                    }
                    else if (pieceChoice == 1) {
                        board[row-1][column-1] = new Bowman();
                        if (board[row-1][column-1]->validator(column) == 0) { // column = 3
                            cout << "You cannot add Bowman to column 3 since it is Ranged piece!" << endl;
                            totalFlag = 0; // to ask everything from scratch.
                            delete board[row-1][column-1];
                            board[row-1][column-1] = nullptr;
                        }
                        else
                            pieceCount++;
                    }
                    else if (pieceChoice == 2) {
                        int elfCount = 0;
                        for (int i=0; i<4; i++) {
                            for (int j=0; j<3; j++) {
                                if (board[i][j] == nullptr)
                                    continue;
                                if (board[i][j]->getName() == 'E')
                                    elfCount++;
                            }
                        }

                        if (elfCount == 3) {
                            cout << "You already reached the maximum time you can use for Elf. Please enter a different piece!" << endl;
                            pieceChoiceFlag = 0;
                        }
                        else {
                            board[row-1][column-1] = new Elf(); // Elf added to the board.
                            if (board[row-1][column-1]->validator(column) == 0) { // column = 3
                                cout << "You cannot add Elf to column 3 since it is Ranged piece!" << endl;
                                totalFlag = 0; // to ask everything from scratch.
                                delete board[row-1][column-1];
                                board[row-1][column-1] = nullptr;
                            }
                            else
                                pieceCount++;
                        }
                    }
                    else if (pieceChoice == 3) {
                        int mageCount = 0;
                        for (int i=0; i<4; i++) {
                            for(int j=0; j<3; j++) {
                                if (board[i][j] == nullptr)
                                    continue;
                                if (board[i][j]->getName() == 'M')
                                    mageCount++;
                            }
                        }

                        if (mageCount == 2) {
                            cout << "You already reached the maximum time you can use for Mage. Please enter a different piece!" << endl;
                            pieceChoiceFlag = 0;
                        }
                        else {
                            board[row-1][column-1] = new Mage(); // Mage added to the board.
                            if (board[row-1][column-1]->validator(column) == 0) { // column = 3
                                cout << "You cannot add Mage to column 3 since it is Ranged piece!" << endl;
                                totalFlag = 0; // to ask everything from scratch.
                                delete board[row-1][column-1];
                                board[row-1][column-1] = nullptr;
                            }
                            else {
                                pieceCount++;
                                for (int k = 0; k <4; k++) { // when Mage is played, it should give a +1 life point bonus to all its teammates on the board
                                    for (int l = 0; l < 3; l++) {
                                        if (board[k][l] != nullptr && board[k][l] != board[row-1][column-1]) //board[k][l] != board[row-1][column-1], because it shouldnt give bonus to itself
                                            board[k][l]->setLife(board[k][l]->getLife() + 1);
                                    }
                                }
                            }
                        }
                    }
                } while (!pieceChoiceFlag);

            }
            else if (choice == 2) {
                int pieceChoice, pieceChoiceFlag;
                do {
                    pieceChoiceFlag = 1;
                    cout << endl << "What Melee piece you want to add? " << endl;
                    cout << "1-) Spearman: life = 6, damage per hit = 3, max round you can use = UNLIMITED" << endl;
                    cout << "2-) Ranger: life = 8, damage per hit = 6, max round you can use = 2" << endl;
                    cout << "3-) Swordsman: life = 6, damage per hit = 4, max round you can use = UNLIMITED" << endl;
                    cout << "4-) Knight: life = 10, damage per hit = 10, max round you can use = 1" << endl;
                    cout << "Your choice: ";
                    cin >> pieceChoice;

                    if (pieceChoice != 1 && pieceChoice != 2 && pieceChoice != 3 && pieceChoice != 4) {
                        cout << "Please enter a valid choice!" << endl;
                        pieceChoiceFlag = 0; // if pieceChoiceFlag is 0 continue to iterate
                    } else if (pieceChoice == 1) {
                        board[row-1][column-1] = new Spearman(); // Spearman added to the board.

                        if (board[row-1][column-1]->validator(column) == 0) { // column = 1
                            cout << "You cannot add Spearman to column 1 since it is Melee piece!" << endl;
                            totalFlag = 0; // to ask everything from scratch.
                            delete board[row-1][column-1];
                            board[row-1][column-1] = nullptr;
                        }
                        else
                            pieceCount++;

                    } else if (pieceChoice == 2) {
                        int rangerCount = 0;
                        for (int i = 0; i < 4; i++) {
                            for(int j=0; j<3; j++) {
                                if (board[i][j] == nullptr)
                                    continue;
                                if (board[i][j]->getName() == 'R')
                                    rangerCount++;
                            }
                        }

                        if (rangerCount == 2) {
                            cout << "You already reached the maximum time you can use for Ranger. Please enter a different piece!" << endl;
                            pieceChoiceFlag = 0;
                        } else {
                            board[row-1][column-1] = new Ranger(); // Ranger added to the board.

                            if (board[row-1][column-1]->validator(column) == 0) { // column = 1
                                cout << "You cannot add Ranger to column 1 since it is Melee piece!" << endl;
                                totalFlag = 0; // to ask everything from scratch.
                                delete board[row-1][column-1];
                                board[row-1][column-1] = nullptr;
                            }
                            else
                                pieceCount++;
                        }
                    } else if (pieceChoice == 3) {
                        board[row-1][column-1] = new Swordsman(); // Swordsman added to the board.

                        if (board[row-1][column-1]->validator(column) == 0) { // column = 1
                            cout << "You cannot add Swordsman to column 1 since it is Melee piece!" << endl;
                            totalFlag = 0; // to ask everything from scratch.
                            delete board[row-1][column-1];
                            board[row-1][column-1] = nullptr;
                        }
                        else
                            pieceCount++;
                    } else if (pieceChoice == 4) {
                        int kinghtCount = 0;
                        for (int i = 0; i < 4; i++) {
                            for (int j=0; j<3; j++) {
                                if (board[i][j] == nullptr)
                                    continue;
                                if (board[i][j]->getName() == 'K')
                                    kinghtCount++;
                            }
                        }

                        if (kinghtCount == 1) {
                            cout << "You already reached the maximum time you can use for Knight. Please enter a different piece!" << endl;
                            pieceChoiceFlag = 0;
                        } else {
                            board[row-1][column-1] = new Knight(); // Knight added to the board.

                            if (board[row-1][column-1]->validator(column) == 0) { // column = 1
                                cout << "You cannot add Knight to column 1 since it is Melee piece!" << endl;
                                totalFlag = 0; // to ask everything from scratch.
                                delete board[row-1][column-1];
                                board[row-1][column-1] = nullptr;
                            }
                            else {
                                pieceCount++;
                                for (int k = 0; k <4; k++) { // when  Knight is played, it gives a +1 attack bonus to all its teammates.
                                    for (int l = 0; l < 3; l++) {
                                        if (board[k][l] != nullptr && board[k][l] != board[row-1][column-1]) //board[k][l] != board[row-1][column-1], because it shouldnt give bonus to itself
                                            board[k][l]->setDamage(board[k][l]->getDamage() + 1);
                                    }
                                }
                            }
                        }
                    }
                } while (!pieceChoiceFlag);
            }
        } while (!totalFlag);
    }
}

int Board::getHealth() const {
    return health;
}

void Board::attack(Board &b) {
    int rowPieceFlag = 0;
    for(int i=0; i<4; i++) {
        rowPieceFlag = 0; //for each row's start it is 0, and once the iteration done for the row, if it is still 0, then damage the board
        for(int j=0; j<3; j++) {
            if (board[i][j] != nullptr) {  //if there is a piece in the attacking board
                int damage = board[i][j]->getDamage();
                for (int k = 2; k >= 0; k--) { // iterate over columns of attacked board's column
                    if (b.board[i][k] != nullptr) { //there is a piece at the opposite row
                        rowPieceFlag = 1; // there is a piece, do not damage board
                        int newHealth = b.board[i][k]->getLife() - damage;
                        if (newHealth > 0) // piece continues to live
                            b.board[i][k]->setLife(newHealth);
                        else { // piece dies
                            delete b.board[i][k];
                            b.board[i][k] = nullptr;
                            b.pieceCount--;
                        }
                        break; // exit loop after attacking first piece in column
                    }
                }
                if (rowPieceFlag == 0) // meaning there is no piece in that row, damage the board
                    b.health -= damage;
            }
        }
    }
}


