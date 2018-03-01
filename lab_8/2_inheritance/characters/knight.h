//
// Created by igor- on 02.02.2018.
//

#ifndef LAB_8_KNIGHT_H
#define LAB_8_KNIGHT_H
#include "hero.h"
#include <iostream>

class Knight: public Hero {
    public:
        Knight();
        int getAttack() const override;
        int skill(int condition) override; //active skill
    private:
};


#endif //LAB_8_KNIGHT_H
