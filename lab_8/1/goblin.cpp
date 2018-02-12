//
// Created by igor- on 02.02.2018.
//

#include "goblin.h"
#include <iostream>
#include <time.h>

bool cowardice(){
    srand(time(NULL));
    int dodgeChance = 50;
    if(rand()%100 < dodgeChance)
        return true;
    else return false;
}

Goblin::Goblin(int position) {
    _position = position;
}

int Goblin::getHp() {
    return _hp;
}

int Goblin::getPosition() {
    return _position;
}

void Goblin::setPosition(int position) {
    _position = position;
}

int Goblin::getAttack() {
    return _attack;
}

int Goblin::getRange() {
    return _range;
}

int Goblin::takeDamage(int damage) {
    if(getHp() < _maxHp*0.5 && cowardice())
        return 0;
    else{
        _hp-=damage;
        return damage;
    }
}

void Goblin::move(int way) {
    if(way) _position++;
    else _position--;
}

int Goblin::bomb() {
    if(_bombStatus == 0){
        std::cout << "bomb is charging" << std::endl;
        _bombStatus++;
        return 0;
    }
    else {
        std::cout << "bomb is REAAADY" << std::endl;
        _bombStatus--;
        return 1;
    }
}

bool Goblin::isDead() {
    if(getHp() <= 0) return true;
    else return false;
}



