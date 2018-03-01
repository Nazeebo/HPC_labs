//
// Created by igor- on 20.02.2018.
//

#include "hero.h"


Hero::Hero(int hp, int mp, int armor, int range, int attack) {
    _hp = hp;
    _mp = mp;
    _armor = armor;
    _range = range;
    _attack = attack;
}

Hero::Hero() {}

void Hero::decHp(int value) {
    _hp-=value;
}

void Hero::decMp(int value) {
    _mp-=value;
}

int Hero::getHp() const {
    if(_hp > 0) return _hp;
    else return 0;
}

int Hero::getMp() const {
    return _mp;
}

int Hero::getArmor() const {
    return _armor;
}

int Hero::getRange() const {
    return _range;
}

void Hero::getStats() const {
    std::cout << "HP = " << getHp() << ", MP = " << getMp() << ", armor = " << getArmor() << std::endl;
}

Hero::~Hero() {}

int Hero::getAttack() const {
    return _attack;
}

void Hero::halveArmor() {
    _armor/=2;
}

void Hero::incAttack(int value) {
    _attack+=value;
}

void Hero::decArmor(int value) {
    _armor-=value;
}

int Hero::takeDamage(int damage) {
    if (getArmor() > 0) {
        if (getArmor() > damage) {
            halveArmor();
            damage = 0;
        } else {
            damage -= getArmor();
            halveArmor();
            decHp(damage);
        }
    } else decHp(damage);
    return damage;
}


