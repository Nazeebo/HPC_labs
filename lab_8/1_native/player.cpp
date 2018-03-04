//
// Created by igor- on 15.02.2018.
//

#include "player.h"
#include <iostream>

using namespace std;

Player::Player() {
}

Player::Player(std::string character) {
    _character = character;
    if (_character == "Knight")
        cout << "You picked Knight" << endl;
    else if (_character == "Mage")
        cout << "You picked Mage" << endl;
    else if (_character == "Goblin")
        cout << "You picked Goblin" << endl;
}

int Player::takeDamage(int damage) {
    if (_character == "Knight")
        knight.takeDamage(damage);
    else if (_character == "Mage")
        mage.takeDamage(damage);
    else if (_character == "Goblin")
        goblin.takeDamage(damage);
}

int Player::skill(int condition) {
    if (condition) {
        if (_character == "Knight") {
            knight.consume();
            return 0;
        } else if (_character == "Mage") {
            mage.oneOfEight(1);
            return 0;
        } else if (_character == "Goblin")
            return goblin.bomb();
    } else {
        cout << "You're not close enough to opponent to use skill" << endl;
        if (_character == "Mage") {
            mage.oneOfEight(0);
            cout << "You burned your mana" << endl;
        }
        return 0;
    }
}

std::string Player::getCharacter() {
    return std::string();
}

void Player::getStats() {
    if (_character == "Knight")
        knight.getStats();
    else if (_character == "Mage")
        mage.getStats();
    else if (_character == "Goblin")
        goblin.getStats();
}

int Player::getAttack() {
    if (_character == "Knight")
        return knight.getAttack();
    else if (_character == "Mage")
        return mage.getAttack();
    else if (_character == "Goblin")
        return goblin.getAttack();
}

int Player::getHp() {
    if (_character == "Knight")
        return knight.getHp();
    else if (_character == "Mage")
        return mage.getHp();
    else if (_character == "Goblin")
        return goblin.getHp();
}

int Player::getRange() {
    if (_character == "Knight")
        return knight.getRange();
    else if (_character == "Mage")
        return mage.getRange();
    else if (_character == "Goblin")
        return goblin.getRange();
}




