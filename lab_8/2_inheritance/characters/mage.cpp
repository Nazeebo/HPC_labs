//
// Created by igor- on 02.02.2018.
//

#include "mage.h"


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

Mage::Mage():Hero(20,25,0,2,7) {}

int Mage::takeDamage(int damage) {
    if ( getMp() > 0)
        if (magicShield()) {
            decMp(damage*2);
            if (getMp() < 0) decMp(getMp()); //setMp = 0
            std::cout << "Magic shiled protected Mage, 0 damage taken" << std::endl;
            return 0;
        } else Hero::takeDamage(damage);
}

int Mage::skill(int condition){
        if (condition) {
            if(getMp() > 0){
                decMp(getMp()); //setMp = 0
                int roll = oneOfFour();
                switch (roll) {
                    case 0: {
                        decMp(-getMp()); //mp*=2
                        std::cout << "Your mp, which is zero, was doubled" << std::endl;
                        return 0;
                    }
                    case 1: {
                        decHp(-getHp()); //hp*=2
                        std::cout << "Your hp was doubled" << std::endl;
                        return 0;
                    }
                    case 2: {
                        decHp(getHp()); //hp=0
                        std::cout << "Cost of that cast was your life" << std::endl;
                        return 0;
                    }
                    case 3: {
                        decArmor(-15); //armor=15;
                        std::cout << "You conjured yourself armor" << std::endl;
                        return 0;
                    }
                }
            }
            else std::cout << "You have 0 mana to do anything" << std::endl;
        }

}

