//
// Created by igor- on 15.02.2018.
//

#include "game.h"
#include <iostream>
#include "helping_funcs.h"

using namespace std;

Game::Game(string first, string second) {
    arena[0] = 1;
    arena[6] = 2;
    player1 = Player(first);
    player2 = Player(second);
}

int Game::getDistance() {
    int player1, player2;
    for (int i = 0; i < 7; i++) {
        if (arena[i] == 1) player1 = i;
        if (arena[i] == 2) player2 = i;
    }
    return abs(player2 - player1);
}

void Game::attack(int numOfAttacker) {
    int distance = getDistance();
    if (numOfAttacker == 1 && distance <= player1.getRange())
        cout << "Player2 took " << player2.takeDamage(player1.getAttack()) << " damage. " << player2.getHp() - player2.takeDamage(player1.getAttack()) << " left" <<endl;
    else if (numOfAttacker == 2 && distance <= player2.getRange())
        cout << "Player1 took " << player1.takeDamage(player2.getAttack()) << " damage. " << player1.getHp() - player1.takeDamage(player2.getAttack()) << " left" <<endl;
    else cout << "You're not close enough to attack" << endl;
}

void Game::skill(int numOfPlayer) {
    int distance = getDistance();
    int condition;
    if (numOfPlayer == 1 && distance <= player1.getRange()) condition = 1;
    else if (numOfPlayer == 2 && distance <= player2.getRange()) condition = 1;
    else condition = 0;
    if (numOfPlayer == 1) {
        if (player1.skill(condition)) {
            cout << "Because of bomb explosion player1 took "
                 << player1.takeDamage(player1.getHp() - 1) << " damage. " << player1.getHp() - player1.takeDamage(player2.getAttack()) << " left" <<endl;
            cout << "Because of bomb explosion player2 took "
                 << player2.takeDamage(player2.getHp() - 1) << " damage. " << player2.getHp() - player2.takeDamage(player1.getAttack()) << " left" <<endl;
        }
    } else if (numOfPlayer == 2)
        if (player2.skill(condition)) {
            cout << "Because of bomb explosion player1 took "
                 << player1.takeDamage(player1.getHp() - 1) << " damage. " << player1.getHp() - player1.takeDamage(player2.getAttack()) << " left" <<endl;
            cout << "Because of bomb explosion player2 took "
                 << player2.takeDamage(player2.getHp() - 1) << " damage. " << player2.getHp() - player2.takeDamage(player1.getAttack()) << " left" <<endl;
        }
}

bool Game::isDead(int numOfPlayer) {
    if (numOfPlayer == 1 && player1.getHp() <= 0)
        return true;
    else if (numOfPlayer == 2 && player2.getHp() <= 0)
        return true;
    else return false;
}

void Game::getStats(int numOfPlayer) {
    if (numOfPlayer == 1)
        player1.getStats();
    else if (numOfPlayer == 2)
        player2.getStats();
}

void Game::move(int numOfPlayer) {
    int pos1, pos2;
    for (int i = 0; i < 7; i++) {
        if (arena[i] == 1) pos1 = i;
        if (arena[i] == 2) pos2 = i;
    }
    int possibility = checkForMove(numOfPlayer, pos1, pos2);
    char direction;
    switch (possibility) {
        case 2: {
            cout << "You can move forward or backward, type F or B to clarify direction" << endl;
            direction = letterInForWay();
            if (direction == 'F') moveForward(numOfPlayer, pos1, pos2);
            else if (direction == 'B') moveBackward(numOfPlayer, pos1, pos2);
            break;
        }
        case 1: {
            cout << "You can move only forward so you do" << endl;
            moveForward(numOfPlayer, pos1, pos2);
            break;
        }
        case -1: {
            cout << "You can move only backward so you do" << endl;
            moveBackward(numOfPlayer, pos1, pos2);
            break;
        }
        case 0: {
            cout << "You can't move to any side, your turn is over " << endl;
            break;
        }
    }
}

void Game::moveBackward(int numOfPlayer, int pos1, int pos2) {
    if (numOfPlayer == 1) {
        arena[pos1] = 0;
        arena[pos1 - 1] = 1;
    } else if (numOfPlayer == 2) {
        arena[pos2] = 0;
        arena[pos2 + 1] = 2;
    }
}

void Game::moveForward(int numOfPlayer, int pos1, int pos2) {
    if (numOfPlayer == 1) {
        arena[pos1] = 0;
        arena[pos1 + 1] = 1;
    } else if (numOfPlayer == 2) {
        arena[pos2] = 0;
        arena[pos2 - 1] = 2;
    }
}

int Game::checkForMove(int numOfPlayer, int pos1, int pos2) {
    int possibility;
    int distance = abs(pos2 - pos1);
    if (numOfPlayer == 1) {
        if (pos1 > 0 && distance > 1)
            possibility = 2;
        else if (pos1 > 0)
            possibility = -1;
        else if (distance > 1)
            possibility = 1;
        else possibility = 0;
    } else if (numOfPlayer == 2) {
        if (pos2 < 6 && distance > 1)
            possibility = 2;
        else if (pos2 < 6)
            possibility = -1;
        else if (distance > 1)
            possibility = 1;
        else possibility = 0;
    }
    return possibility;
}



