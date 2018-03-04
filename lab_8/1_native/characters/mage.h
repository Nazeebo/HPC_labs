//
// Created by igor- on 02.02.2018.
//

#ifndef LAB_8_MAGE_H
#define LAB_8_MAGE_H


class Mage {
    public:
        Mage();
        void getStats();
        int getHp();
        int getArmor();
        int getMp();
        int getAttack();
        int getRange();
        int takeDamage(int damage);
        void oneOfEight(int condition); //active skill
    private:
        int _hp,_mp,_armor,_attack,_range;
};


#endif //LAB_8_MAGE_H
