//
// Created by igor- on 02.02.2018.
//

#ifndef LAB_8_KNIGHT_H
#define LAB_8_KNIGHT_H

class Knight {
    public:
        Knight();
        void getStats();
        int getHp();
        int getArmor();
        int getAttack();
        int getRange();
        int takeDamage(int damage);
        void consume(); //active skill
    private:
        int _hp,_armor,_attack,_range;
};


#endif //LAB_8_KNIGHT_H
