//
// Created by igor- on 14.02.2018.
//

#ifndef BAKERS_PIE_H
#define BAKERS_PIE_H
#include <string>
#include <ctime>
#include <iostream>


class Pie {
    public:
        Pie();
        Pie(int taste);
        Pie(std::string name);
        Pie(std::string name, int taste);
        Pie(const Pie &obj);

        static int count;
        static Pie comparePie(const Pie &a, const Pie &b);

        void setTaste(int taste);
        int getTaste()const ;
        std::string getName()const;

        Pie& operator= (const Pie& obj);
        virtual ~Pie();

private:
        std::string _name;
        int _taste;
};


#endif //BAKERS_PIE_H
