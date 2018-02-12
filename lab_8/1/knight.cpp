//
// Created by igor- on 02.02.2018.
//

#include "knight.h"
#include <iostream>

Knight::Knight(int position) {
    _position = position;
    _hp=30;
    _range=1;
    _armor=10;
    _attack=7;
}

int Knight::getHp() {
    return _hp;
}

int Knight::getArmor() {
    return _armor;
}

int Knight::getPosition() {
    return _position;
}

void Knight::setPosition(int position) {
    _position = position;
}

int Knight::getAttack() {
    if(getArmor() > 0) return _attack;
    else return _attack*2;
}

int Knight::getRange() {
    return _range;
}

int Knight::takeDamage(int damage) {
    if(getArmor() > 0){
        if(getArmor() > damage) {
            _armor/=2;
            damage = 0;
        }
        else{
            damage-=_armor;
            _armor/=2;
            _hp-=damage;
        }
    } else _hp-=damage;
    return damage;

}

void Knight::move(int way) {  //1 - right, 0 - left
    if(way) _position++;
    else _position--;
}

void Knight::consume() {
    int amountToConsume=5;
    if(getArmor() > amountToConsume){
        _attack +=amountToConsume;
        _armor -=amountToConsume;
    }
    else{
        amountToConsume = getArmor()-1;
        _attack +=amountToConsume;
        _armor -=amountToConsume;
    }
    std::cout << "You ate " << amountToConsume << " armor" << std::endl;
}

bool Knight::isDead() {
    if(getHp() <= 0) return true;
    else return false;
}


