//
// Created by igor- on 14.02.2018.
//

#include "baker.h"
using namespace std;

Baker::Baker() {
    cout << "Baker's Constructor was called" << endl;
    _experience=0;
    _satiety = 100;
    _professionalism = 0;
    _counter = 0;
    pies = new Pie[100];
}

Baker::Baker(const Baker &obj) {
    cout << "Baker's Copy Constructor was called" << endl;
    _satiety = obj._satiety;
    _professionalism = obj._professionalism;
    _experience = obj._experience;
    pies = new Pie[100];
    for(int i = 0; i < obj._counter; i++)
        pies[i] = obj.pies[i];
    _counter = obj._counter;
}

void Baker::createPie() {
    int tasty;
    if(_satiety > 50)
        if(_professionalism > 50)
            tasty = 75;
        else tasty = 50;
    else tasty = 25;
    this->pies[this->_counter++].setTaste(tasty);
}

void Baker::givePie(Baker &baker) {
    baker.pies[baker._counter++] = this->pies[--this->_counter];
    this->_satiety-=25;
    if(this->_satiety<0) this->_satiety= 0;
}

void Baker::eatPie() {
    _satiety+=pies[--this->_counter].getTaste();
    if(_satiety>100)_satiety=100;
}

int Baker::getCounter() const {
    return _counter;
}

Baker &Baker::operator=(const Baker &obj) {
    if(this == &obj) return *this;
    _professionalism = obj._professionalism;
    _experience = obj._experience;
    _satiety = obj._satiety;
    return *this;
}

Baker::~Baker() {
    cout << "Baker's Destructor was called" << endl;
    delete[] pies;
}


void  Baker::incExpAndProf(int exp){
    _experience+=exp;
    _professionalism+=exp/10;
}

