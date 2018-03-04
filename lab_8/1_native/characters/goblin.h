//
// Created by igor- on 02.02.2018.
//

#ifndef LAB_8_GOBLIN_H
#define LAB_8_GOBLIN_H


class Goblin {
    public:
        Goblin();
        void getStats();
        int getHp();
        int getAttack();
        int getRange();
        int takeDamage(int damage);
        int bomb(); //active skill
    private:
        int _hp,_attack,_range,_bombStatus,_maxHp;
};


#endif //LAB_8_GOBLIN_H
