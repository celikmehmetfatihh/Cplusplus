#include "Pieces.h"

#include <iostream>
using namespace std;

Pieces::Pieces() {
    count = 0;
    life = 0;
    damage = 0;
    maxLimitUsage = -1; // -1 stands for undefined
    name = 'U'; //represents Undefined.
}

Pieces::Pieces(char name) {
    if (name == 'B') {
        life = 12;
        damage = 3;
        maxLimitUsage = 0; // 0 stands for unlimited usage
        this->name = name;
    }
    else if (name == 'E') {
        life = 8;
        damage = 6;
        maxLimitUsage = 3;
        this->name = name;
    }
    else if (name == 'M') {
        life = 4;
        damage = 8;
        maxLimitUsage = 2;
        this->name = name;
    }
    else if (name == 'S') {
        life = 6;
        damage = 3;
        maxLimitUsage = 0;
        this->name = name;
    }
    else if (name == 'R') {
        life = 8;
        damage = 6;
        maxLimitUsage = 2;
        this->name = name;
    }
    else if (name == 'W') {
        life = 6;
        damage = 4;
        maxLimitUsage = 0;
        this->name = name;
    }
    else if (name == 'K') {
        life = 10;
        damage = 10;
        maxLimitUsage = 1;
        this->name = name;
    }
    else
        cout << "Please enter a valid piece!" << endl;
}

char Pieces::getName() const {
    return name;
}

int Pieces::validator(int column) {
    return -1;
}

int Pieces::getDamage() const {
    return damage;
}

int Pieces::getLife() const {
    return life;
}

void Pieces::setLife(int life) {
    Pieces::life = life;
}

void Pieces::setDamage(int damage) {
    Pieces::damage = damage;
}

