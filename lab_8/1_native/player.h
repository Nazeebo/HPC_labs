//
// Created by igor- on 15.02.2018.
//

#ifndef LAB_8_PLAYER_H
#define LAB_8_PLAYER_H
#include "characters/goblin.h"
#include "characters/mage.h"
#include "characters/knight.h"
#include <string>

class Player {
    public:
        Player(std::string character);
        Player();
        int takeDamage(int damage);
        int skill(int condition);
        std::string getCharacter();
        void getStats();
        int getAttack();
        int getHp();
        int getRange();
private:
        Goblin goblin;
        Knight knight;
        Mage mage;
        std::string _character;
};


#endif //LAB_8_PLAYER_H
