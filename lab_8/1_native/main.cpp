#include <iostream>
#include <cstdio>
#include <cmath>
#include "game.h"
#include "helping_funcs.h"

using namespace std;

int main() {
    cout << "The game begins" << endl;
    cout << "Player 1 choose your character, type K to pick a Knight, M to pick a Mage or G to pick a Goblin" << endl;
    char player1 = letterInForClass();
    cout << "Player 2 choose your character, type K to pick a Knight, M to pick a Mage or G to pick a Goblin" << endl;
    char player2 = letterInForClass();
    string first = letterConvert(player1);
    string second = letterConvert(player2);
    Game game(first, second);
    cout << "Your characters are entering arena and battle begins!" << endl;
    int playersTurn = 1;
    while (1) {
        cout << "Player" << playersTurn << ", what's your action? Type M to move, A to attack, S to use active skill"
             << endl;
        char choice = letterInForAction();
        switch (choice) {
            case 'A': {
                game.attack(playersTurn);
                break;
            }
            case 'S': {
                game.skill(playersTurn);
                break;
            }
            case 'M': {
                game.move(playersTurn);
                break;
            }
        }
        if (game.isDead(1)) {
            cout << "Player1 is dead, Player2 is WINNER" << endl;
            return 0;
        }
        else if (game.isDead(2)) {
            cout << "Player2 is dead, Player1 is WINNER" << endl;
            return 0;
        }

        if (playersTurn == 1) playersTurn = 2;
        else playersTurn = 1;
    }
}
