//
// Created by igor- on 02.02.2018.
//

#include "knight.h"
#include <iostream>

using namespace std;

Knight::Knight() {
    _hp = 30;
    _range = 1;
    _armor = 10;
    _attack = 7;
}

int Knight::getHp() {
    return _hp;
}

int Knight::getArmor() {
    return _armor;
}

int Knight::getAttack() {
    if (getArmor() > 0) return _attack;
    else return _attack * 2;
}

int Knight::getRange() {
    return _range;
}

int Knight::takeDamage(int damage) {
    if (getArmor() > 0) {
        if (getArmor() > damage) {
            _armor /= 2;
            damage = 0;
        } else {
            damage -= _armor;
            _armor /= 2;
            _hp -= damage;
        }
    } else _hp -= damage;
    return damage;

}

void Knight::consume() {
    int amountToConsume = 5;
    if (getArmor() > amountToConsume) {
        _attack += amountToConsume;
        _armor -= amountToConsume;
    } else {
        amountToConsume = getArmor() - 1;
        _attack += amountToConsume;
        _armor -= amountToConsume;
    }
    cout << "You ate " << amountToConsume << " armor" << endl;
}

void Knight::getStats() {
    cout << "hp = " << getHp() << endl;
    cout << "armor = " << getArmor() << endl;
    cout << "attack = " << getAttack() << endl;
}


