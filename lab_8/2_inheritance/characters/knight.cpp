//
// Created by igor- on 02.02.2018.
//

#include "knight.h"


using namespace std;

Knight::Knight():Hero(30,0,10,1,7) {
}

int Knight::getAttack() const {
    if (getArmor() > 0) return Hero::getAttack();
    else return Hero::getAttack() * 2;
}

int Knight::skill(int condition){
    int amountToConsume = 5;
    if (getArmor() > amountToConsume) {
        incAttack(amountToConsume);
        decArmor(amountToConsume);
    } else {
        amountToConsume = getArmor() - 1;
        incAttack(amountToConsume);
        decArmor(amountToConsume);
    }
    cout << "You ate " << amountToConsume << " armor" << endl;

    return 0;
}

