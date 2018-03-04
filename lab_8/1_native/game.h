//
// Created by igor- on 15.02.2018.
//

#ifndef LAB_8_GAME_H
#define LAB_8_GAME_H
#include "player.h"

class Game {
    public:
        Game(std::string first,std::string second);
        int getDistance();
        void attack(int numOfAttacker);
        void move(int numOfPlayer);
        void moveBackward(int numOfPlayer, int pos1, int pos2);
        void moveForward(int numOfPlayer, int pos1, int pos2);
        int checkForMove(int numOfPlayer, int pos1, int pos2);
        void skill(int numOfPlayer);
        bool isDead(int numOfPlayer);
        void getStats(int numOfPlayer);
    private:
        Player player1,player2;
        int arena[7];
};


#endif //LAB_8_GAME_H
