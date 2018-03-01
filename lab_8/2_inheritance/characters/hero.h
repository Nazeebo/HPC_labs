//
// Created by igor- on 20.02.2018.
//

#ifndef INC_2_INHERITANCE_HERO_H
#define INC_2_INHERITANCE_HERO_H

#include <iostream>

class Hero {
public:
    Hero(int hp, int mp, int armor, int range, int attack);

    Hero();

    virtual int skill(int condition) = 0;

    virtual int takeDamage(int damage);

    virtual ~Hero();

    int getHp() const;
    int getMp() const;
    int getArmor() const;
    int getRange() const;
    void getStats() const;
    virtual int getAttack() const;
protected:
    void decHp(int value);
    void decMp(int value);
    void decArmor(int value);
    void halveArmor();
    void incAttack(int value);
private:
    int _hp, _armor, _mp, _range, _attack;
};


#endif //INC_2_INHERITANCE_HERO_H
