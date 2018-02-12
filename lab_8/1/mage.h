//
// Created by igor- on 02.02.2018.
//

#ifndef LAB_8_MAGE_H
#define LAB_8_MAGE_H


class Mage {
    public:
        Mage(int position);
        int getHp();
        int getArmor();
        int getMp();
        int getPosition();
        void setPosition(int position);
        int getAttack();
        int getRange();
        int takeDamage(int damage);
        void move(int way);
        void oneOfEight(int condition);
        bool isDead(); //active skill
    private:
        int _hp,_mp,_armor,_attack,_range,_position;
};


#endif //LAB_8_MAGE_H
