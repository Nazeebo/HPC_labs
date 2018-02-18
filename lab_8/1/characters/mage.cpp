//
// Created by igor- on 02.02.2018.
//

#include "mage.h"
#include <time.h>
#include <iostream>

using namespace std;

bool magicShield() {
    srand(time(NULL));
    int shieldChance = 30;
    if (rand() % 100 < shieldChance)
        return true;
    else return false;
}

int oneOfFour() {
    srand(time(NULL));
    return rand() % 4;
}

Mage::Mage() {
    _hp = 20;
    _range = 2;
    _armor = 0;
    _attack = 7;
    _mp = 25;
}

int Mage::getHp() {
    return _hp;
}

int Mage::getArmor() {
    return _armor;
}

int Mage::getMp() {
    return _mp;
}

int Mage::getAttack() {
    return _attack;
}

int Mage::getRange() {
    return _range;
}

int Mage::takeDamage(int damage) {
    if (getMp() > 0)
        if (magicShield()) {
            _mp -= damage * 2;
            if (_mp < 0) _mp = 0;
            std::cout << "Magic shiled protected Mage, 0 damage taken" << std::endl;
            return 0;
        } else {
            _hp -= damage;
            return damage;
        }
}

void Mage::oneOfEight(int condition) {
        if (condition) {
            if(_mp > 0){
                _mp = 0;
                int roll = oneOfFour();
                switch (roll) {
                    case 0: {
                        _mp *= 2;
                        std::cout << "Your mp, which is zero, was doubled" << std::endl;
                        return;
                    }
                    case 1: {
                        _hp *= 2;
                        std::cout << "Your hp was doubled" << std::endl;
                        return;
                    }
                    case 2: {
                        _hp = 0;
                        std::cout << "Cost of that cast was your life" << std::endl;
                        return;
                    }
                    case 3: {
                        _armor = 15;
                        std::cout << "You conjured yourself armor" << std::endl;
                        return;
                    }
                }
            }
            else std::cout << "You have 0 mana to do anything" << std::endl;
        }

}

void Mage::getStats() {
    cout << "hp = " << getHp() << endl;
    cout << "mp = " << getArmor() << endl;
    cout << "attack = " << getAttack() << endl;
}
