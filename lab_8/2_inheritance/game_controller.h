//
// Created by igor- on 28.02.2018.
//

#ifndef INC_2_INHERITANCE_ACTION_H
#define INC_2_INHERITANCE_ACTION_H
#include "players.h"

class Action {
public:
    Action();
    void turns();
private:
    Game game;
    Listener listener;
};

#endif //INC_2_INHERITANCE_ACTION_H
