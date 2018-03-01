//
// Created by igor- on 18.02.2018.
//

#include "helping_funcs.h"


char letterInForClass() {
    char choice;
    bool flag = false;
    while (1) {
        scanf("%c", &choice);
        if (choice == 'K' || choice == 'M' || choice == 'G')
            flag = true;
        if (flag) break;
    }
    return choice;
}

char letterInForAction() {
    char choice;
    bool flag = false;
    while (1) {
        scanf("%c", &choice);
        if (choice == 'A' || choice == 'S' || choice == 'M')
            flag = true;
        if (flag) break;
    }
    return choice;
}

char letterInForWay() {
    char choice;
    bool flag = false;
    while (1) {
        scanf("%c", &choice);
        if (choice == 'F' || choice == 'B')
            flag = true;
        if (flag) break;
    }
    return choice;
}
