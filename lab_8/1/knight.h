//
// Created by igor- on 02.02.2018.
//

#ifndef LAB_8_KNIGHT_H
#define LAB_8_KNIGHT_H


class Knight {
    public:
        Knight(int position);
        int getHp();
        int getArmor();
        int getPosition();
        void setPosition(int position);
        int getAttack();
        int getRange();
        int takeDamage(int damage);
        void move(int way);
        void consume(); //active skill
        bool isDead();
    private:
        int _hp,_armor,_attack,_position,_range;
};


#endif //LAB_8_KNIGHT_H
