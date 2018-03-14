//
// Created by igor- on 14.02.2018.
//

#ifndef BAKERS_BAKER_H
#define BAKERS_BAKER_H
#include "pie.h"

class Baker {
    public:
        Baker();
        Baker(const Baker &obj);
        void createPie();
        void givePie(Baker &baker);
        void eatPie();
        Baker& operator= (const Baker& obj);
        void incExpAndProf(int exp);

        int getCounter()const ;
        virtual ~Baker();
    private:
        int _professionalism, _experience, _satiety, _counter;
        Pie *pies;
};


#endif //BAKERS_BAKER_H
