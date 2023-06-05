#include "Board.h"
#include <iostream>
using namespace std;

#include "Elf.h"
#include "Mage.h"
#include "Ranger.h"
#include "Knight.h"
#include "Bowman.h"
#include "Spearman.h"
#include "Swordsman.h"
#include "Melee.h"

Board::Board() {
    health = 100;
    row= 4;
    column = 3;
    pieceCount = 0;
    board = new char*[row];
    for(int i=0; i<row; i++) {
        board[i] = new char[column];
        for(int j=0; j<column; j++)
            board[i][j] = ' ';
    }
}

void Board::displayBoard() {
    // Print the column number
    cout << "   ";
    for (int j = 0; j < column; j++) {
        cout << j+1 << " ";
    }
    cout << endl;

    for (int i = 0; i < row; i++) {
        // Print the row number
        cout << i+1 << "  ";

        // Print the cells
        for (int j = 0; j < column; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    // Print the health status
    cout << "Health: " << health << endl;
}

void Board::addPiece() {
    if (pieceCount >= 12)
        cout << "The all of your board's cell is full! It's the next player's turn." << endl;
    else {
        int row, column, flag, totalFlag;
        do{
            totalFlag = 1;
            do {
                flag = 1;
                cout << endl << "Enter which row you want to enter a piece: ";
                cin >> row;
                cout << "Enter which column you want to enter a piece: ";
                cin >> column;

                if (row < 0 || row > 4 || column < 0 || column > 3) {
                    cout << "The board is 4x3! Please enter a valid cell! " << endl;
                    flag = 0; // if flag is 0 continue to iterate
                }
                else if (board[row - 1][column - 1] != ' ') {
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
                        Bowman *b1 = new Bowman();
                        pieces[pieceCount] = b1; // Bowman added to the board.
                        if (pieces[pieceCount]->validator(column) == 0) { // column = 3
                            cout << "You cannot add Bowman to column 3 since it is Ranged piece!" << endl;
                            totalFlag = 0; // to ask everything from scratch.
                            delete pieces[pieceCount];
                        }
                        else {
                            pieceCount++;
                            board[row - 1][column - 1] = 'B';
                        }
                    }
                    else if (pieceChoice == 2) {
                        int elfCount = 0;
                        for (int i=0; i<pieceCount; i++) {
                            if (pieces[i]->getName() == 'E')
                                elfCount++;
                        }

                        if (elfCount == 3) {
                            cout << "You already reached the maximum time you can use for Elf. Please enter a different piece!" << endl;
                            pieceChoiceFlag = 0;
                        }
                        else {
                            Elf *e1 = new Elf();
                            pieces[pieceCount] = e1; // Elf added to the board.
                            if (pieces[pieceCount]->validator(column) == 0) { // column = 3
                                cout << "You cannot add Elf to column 3 since it is Ranged piece!" << endl;
                                totalFlag = 0; // to ask everything from scratch.
                                delete pieces[pieceCount];
                            }
                            else {
                                pieceCount++;
                                board[row - 1][column - 1] = 'E';
                            }
                        }
                    }
                    else if (pieceChoice == 3) {
                        int mageCount = 0;
                        for (int i=0; i<pieceCount; i++) {
                            if (pieces[i]->getName() == 'M')
                                mageCount++;
                        }

                        if (mageCount == 2) {
                            cout << "You already reached the maximum time you can use for Mage. Please enter a different piece!" << endl;
                            pieceChoiceFlag = 0;
                        }
                        else {
                            Mage *m1 = new Mage();
                            pieces[pieceCount] = m1; // Mage added to the board.
                            if (pieces[pieceCount]->validator(column) == 0) { // column = 3
                                cout << "You cannot add Mage to column 3 since it is Ranged piece!" << endl;
                                totalFlag = 0; // to ask everything from scratch.
                                delete pieces[pieceCount];
                            }
                            else {
                                pieceCount++;
                                board[row - 1][column - 1] = 'M';
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
                        Spearman *s1 = new Spearman();
                        pieces[pieceCount] = s1; // Spearman added to the board.

                        if (pieces[pieceCount]->validator(column) == 0) { // column = 1
                            cout << "You cannot add Spearman to column 1 since it is Melee piece!" << endl;
                            totalFlag = 0; // to ask everything from scratch.
                            delete pieces[pieceCount];
                        }
                        else {
                            pieceCount++;
                            board[row - 1][column - 1] = 'S';
                        }

                    } else if (pieceChoice == 2) {
                        int rangerCount = 0;
                        for (int i = 0; i < pieceCount; i++) {
                            if (pieces[i]->getName() == 'R')
                                rangerCount++;
                        }

                        if (rangerCount == 2) {
                            cout << "You already reached the maximum time you can use for Ranger. Please enter a different piece!" << endl;
                            pieceChoiceFlag = 0;
                        } else {
                            Ranger *r1 = new Ranger();
                            pieces[pieceCount] = r1; // Ranger added to the board.

                            if (pieces[pieceCount]->validator(column) == 0) { // column = 1
                                cout << "You cannot add Ranger to column 1 since it is Melee piece!" << endl;
                                totalFlag = 0; // to ask everything from scratch.
                                delete pieces[pieceCount];
                            }
                            else {
                                pieceCount++;
                                board[row - 1][column - 1] = 'R';
                            }
                        }
                    } else if (pieceChoice == 3) {
                        Swordsman *w = new Swordsman();
                        pieces[pieceCount] = w; // Swordsman added to the board.

                        if (pieces[pieceCount]->validator(column) == 0) { // column = 1
                            cout << "You cannot add Swordsman to column 1 since it is Melee piece!" << endl;
                            totalFlag = 0; // to ask everything from scratch.
                            delete pieces[pieceCount];
                        }
                        else {
                            pieceCount++;
                            board[row - 1][column - 1] = 'W';
                        }
                    } else if (pieceChoice == 4) {
                        int kinghtCount = 0;
                        for (int i = 0; i < pieceCount; i++) {
                            if (pieces[i]->getName() == 'K')
                                kinghtCount++;
                        }

                        if (kinghtCount == 1) {
                            cout << "You already reached the maximum time you can use for Knight. Please enter a different piece!" << endl;
                            pieceChoiceFlag = 0;
                        } else {
                            Knight *k1 = new Knight();
                            pieces[pieceCount] = k1; // Knight added to the board.

                            if (pieces[pieceCount]->validator(column) == 0) { // column = 1
                                cout << "You cannot add Knight to column 1 since it is Melee piece!" << endl;
                                totalFlag = 0; // to ask everything from scratch.
                                delete pieces[pieceCount];
                            }
                            else {
                                pieceCount++;
                                board[row - 1][column - 1] = 'K';
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
