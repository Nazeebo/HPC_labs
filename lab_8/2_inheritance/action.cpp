//
// Created by igor- on 28.02.2018.
//

#include "action.h"

using namespace std;

Action::Action() {
    char letters[2];
    Hero **players = new Hero *[2];
    for (int i = 0; i < 2; i++) {
        cout << "Player" << i + 1 << " pick your character: type K for Knight, M for Mage or G for Goblin" << endl;
        letters[i] = letterInForClass();

        if (letters[i] == 'K') players[i] = new Knight();
        else if (letters[i] == 'M') players[i] = new Mage();
        else if (letters[i] == 'G') players[i] = new Goblin();
    }
    game = Game(players[0], players[1]);
    cout << "Player1: "; game.getStats(0);
    cout << "Player2: "; game.getStats(1); cout << endl;
}

void Action::turns() {
    char action;
    while (1) {
        for (int i = 0; i < 2; i++) {
            cout << "Player" << i + 1 << " choose your action: type M to move, A to attack or S to use your skill"
                 << endl;
            action = letterInForAction();
            if (action == 'A') game.attack(i);
            else if (action == 'M') game.move(i + 1);
            else if (action == 'S') game.skill(i);
            if (game.isDead(i)) {
                cout << "Player" << 2 - i << " is dead. Player" << i + 1 << " WON" << endl;
                return;
            }
        }
    }

}