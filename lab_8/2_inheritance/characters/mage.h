//
// Created by igor- on 02.02.2018.
//

#ifndef LAB_8_MAGE_H
#define LAB_8_MAGE_H

#include "mage.h"
#include "hero.h"
#include <iostream>
#include <time.h>

class Mage : public Hero {
    public:
        Mage();
        int takeDamage(int damage) override ;
        int skill(int condition) override; //active skill
    private:
};


#endif //LAB_8_MAGE_H
