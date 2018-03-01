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

Goblin::Goblin(): Hero(30,0,0,1,7){
    _bombStatus = 0;
    _maxHp = 30;
};

int Goblin::takeDamage(int damage) {
    if (getHp() < _maxHp * 0.5 && cowardice()){
        std::cout << "MISS" << std::endl;
        return 0;
    }
    else {
        decHp(damage);
        return damage;
    }
}

int Goblin::skill(int condition){
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





