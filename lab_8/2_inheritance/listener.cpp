//
// Created by igor- on 18.02.2018.
//

#include "listener.h"


char Listener::letterInForClass() {
    char choice;
    while (1) {
        scanf("%c", &choice);
        if (choice == 'K' || choice == 'M' || choice == 'G')
            break;
        else std::cout << "Wrong input, try again" << std::endl;
    }
    return choice;
}

char Listener::letterInForAction() {
    char choice;
    while (1) {
        scanf("%c", &choice);
        if (choice == 'A' || choice == 'S' || choice == 'M')
            break;
        else std::cout << "Wrong input, try again" << std::endl;
    }
    return choice;
}

char Listener::letterInForWay() {
    char choice;
    while (1) {
        scanf("%c", &choice);
        if (choice == 'F' || choice == 'B')
            break;
        else std::cout << "Wrong input, try again" << std::endl;
    }
    return choice;
}
