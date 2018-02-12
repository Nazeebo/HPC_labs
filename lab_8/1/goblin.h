//
// Created by igor- on 02.02.2018.
//

#ifndef LAB_8_GOBLIN_H
#define LAB_8_GOBLIN_H


class Goblin {
    public:
        Goblin(int position);
        int getHp();
        int getPosition();
        void setPosition(int position);
        int getAttack();
        int getRange();
        int takeDamage(int damage);
        void move(int way);  //1 - right, 0 - left
        int bomb(); //active skill
        bool isDead();
    private:
        int _hp,_attack,_position,_range,_bombStatus,_maxHp;
};


#endif //LAB_8_GOBLIN_H
