//
// Created by igor- on 15.02.2018.
//

#ifndef LAB_8_GAME_H
#define LAB_8_GAME_H
#include "characters/hero.h"
#include <iostream>
#include "helping_funcs.h"
#include "characters/goblin.h"
#include "characters/mage.h"
#include "characters/knight.h"

class Game {
    public:
        Game(Hero* first, Hero* second);
        Game();
        int getDistance();
        void attack(int numOfAttacker);
        void move(int numOfPlayer);
        void moveBackward(int numOfPlayer, int pos1, int pos2);
        void moveForward(int numOfPlayer, int pos1, int pos2);
        int checkForMove(int numOfPlayer, int pos1, int pos2);
        void skill(int numOfPlayer);
        bool isDead(int numOfAsking);
        void getStats(int numOfPlayer);
    private:
        Hero** players = new Hero*[2];
        int arena[7];
};


#endif //LAB_8_GAME_H
