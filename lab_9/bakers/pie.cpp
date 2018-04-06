//
// Created by igor- on 14.02.2018.
//

#include "pie.h"
using namespace std;

int Pie::count = 0;

string getName(){
    srand(time(NULL));
    int name = rand()%3+1;
    if(name == 1) return "meat";
    else if(name == 2) return "potato";
    else if(name == 3) return "mushrooms and curd";
}

int getTaste(){
    srand(time(NULL));
    return rand()%100+1;
}

Pie Pie::comparePie(const Pie &a, const Pie &b) {
    if(a._taste > b._taste) return a;
    else return b;
}

Pie::Pie() {
    _name = getName();
    _taste = getTaste();
    count++;
    cout << "Pie's Constructor was called" << endl;
}

Pie::Pie(const Pie &obj){
    cout << "Pie's Copy Constructor was called" << endl;
    _name = obj._name;
    _taste = obj._taste;
    count++;
}

Pie::Pie(int taste) {
    _taste = taste;
    _name = getName();
    count++;
    cout << "Pie's Constructor was called" << endl;
}


Pie::Pie(string name, int taste = -1) {
    _name = name;
    if(taste == -1)
        _taste = getTaste();
    else _taste = taste;
    count++;
    cout << "Pie's Constructor was called" << endl;
}

Pie::~Pie() {
    cout << "Pie's Destructor was called" << endl;
}

int Pie::Taste() const {
    return _taste;
}

std::string Pie::getName() const {
    return _name;
}

Pie &Pie::operator=(const Pie &obj) {
    if(this == &obj) return *this;
    _name = obj._name;
    _taste = obj._taste;
    return *this;
}

void Pie::setTaste(int taste) {
    _taste = taste;
}
