//
// Created by igor- on 02.02.2018.
//

#ifndef LAB_8_GOBLIN_H
#define LAB_8_GOBLIN_H
#include "hero.h"

class Goblin: public Hero {
    public:
        Goblin();
        int takeDamage(int damage) override;
        int skill(int condition) override; //active skill
    private:
        int _bombStatus,_maxHp;
};


#endif //LAB_8_GOBLIN_H
