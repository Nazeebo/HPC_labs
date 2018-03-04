//
// Created by igor- on 02.02.2018.
//

#include "goblin.h"
#include <iostream>
#include <time.h>

using namespace std;

bool cowardice() {
    srand(time(NULL));
    int dodgeChance = 50;
    return rand() % 100 < dodgeChance;
}

Goblin::Goblin() {
    _hp = 40;
    _maxHp = _hp;
    _attack = 10;
    _range = 1;
    _bombStatus = 0;
}

int Goblin::getHp() {
    return _hp;
}

int Goblin::getAttack() {
    return _attack;
}

int Goblin::getRange() {
    return _range;
}

int Goblin::takeDamage(int damage) {
    if (getHp() < _maxHp * 0.5 && cowardice()){
        std::cout << "MISS" << std::endl;
        return 0;
    }
    else {
        _hp -= damage;
        return damage;
    }
}

int Goblin::bomb() {
    if (_bombStatus == 0) {
        std::cout << "bomb is charging" << std::endl;
        _bombStatus++;
        return 0;
    } else {
        std::cout << "bomb is REAAADY" << std::endl;
        _bombStatus--;
        return 1;
    }
}

void Goblin::getStats() {
    cout << "hp = " << getHp() << endl;
    cout << "attack = " << getAttack() << endl;
}



