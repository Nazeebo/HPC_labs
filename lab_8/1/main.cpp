#include <iostream>
#include <cstdio>
#include "knight.h"
#include "mage.h"
#include "goblin.h"
#include <cmath>

using namespace std;

int main() {
    int table[7], player[2];  //in player's cell 1 - knight, 2 - mage, 3 - goblin
    for (int i = 0; i < 2; i++) player[i] = 0;
    for (int i = 0; i < 7; i++) table[i] = 0;

    cout << "The game begins" << endl;
    cout << "Player 1 choose your character, type K to pick a Knight, M to pick a Mage or G to pick a Goblin" << endl;
    char choice;
    while (1) {
        scanf("%c", &choice);
        switch (choice) {
            case 'K' : {
                cout << "You choosed a Knight" << endl;
                player[0] = 1;
                Knight *player1 = new Knight(0);

                cout
                        << "Player 2 choose your character, type K to pick a Knight, M to pick a Mage or G to pick a Goblin"
                        << endl;
                char choice1;
                while (1) {
                    scanf("%c", &choice1);
                    switch (choice1) {
                        case 'K' : {
                            cout << "You choosed a Knight" << endl;
                            player[1] = 1;
                            Knight *player2 = new Knight(6);
                            /*table[0] = 1;
                            table[6] = 1;*/

                            while (1) {
                                cout
                                        << "Player1, what's your action? Type M to move, A to attack, S to use active skill"
                                        << endl;
                                int flag0 = 0;
                                while (1) {
                                    scanf("%c", &choice);
                                    switch (choice) {
                                        case 'M' : {
                                            int movement;
                                            if (player1->getPosition() > 0 &&
                                                player1->getPosition() + 1 < player2->getPosition())
                                                movement = 2;
                                            else if (player1->getPosition() > 0)
                                                movement = -1;
                                            else if (player1->getPosition() + 1 < player2->getPosition())
                                                movement = 1;
                                            else movement = 0;

                                            switch (movement) {
                                                case 2: {
                                                    cout
                                                            << "You can move forward or backward, type F to move forward, B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 1: {
                                                    cout
                                                            << "You can move only forward, type F to move forward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case -1: {
                                                    cout
                                                            << "You can move only backward, type B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 0: {
                                                    cout << "You can't move to any side, your turn is over " << endl;
                                                    break;
                                                }
                                            }
                                            char direction;
                                            int flag = 0;
                                            if (movement)
                                                while (1) {
                                                    scanf("%c", &direction);
                                                    switch (direction) {
                                                        case 'F' : {
                                                            if (movement != -1) {
                                                                player1->move(1);
                                                                cout << "You have moved forward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'B': {
                                                            if (movement != 1) {
                                                                player1->move(0);
                                                                cout << "You have moved backward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'C': {
                                                            cout << "You decided to do not move" << endl;
                                                            flag = 1;
                                                            break;
                                                        }
                                                        /*default: {
                                                            cout << "Wrong input. Try again!" << endl;
                                                            break;
                                                        } */
                                                    }
                                                    if (flag) break;
                                                }
                                            flag0 = 1;
                                            break;
                                        }

                                        case 'A': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if(player1->getRange() >= distance){
                                                cout << "Player1 dealed " << player1->getAttack() << " damage" << endl;
                                                cout << "Player2 took" << player2->takeDamage(player1->getAttack()) << " damage" << endl;
                                            }
                                            else
                                                cout << "You're not close enough to attack" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                        case 'S': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if(player1->getRange() <= distance){
                                                player1->consume();
                                                cout << "You successfuly consumed a part of your armor" << endl;
                                            }
                                            else
                                                cout << "You're not close enough to use skill" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                        /*default: {
                                            cout << "Wrong input. Try again!" << endl;
                                            break;
                                        } */
                                    }
                                    if (flag0) break;
                                }

                                if(player2->isDead()){
                                    cout << "Player2 is dead, Player1 won. Game is over" << endl;
                                    return 0;
                                }

                                cout << "Player2, what's your action? Type M to move, A to attack, S to use active skill" << endl;
                                flag0 = 0;
                                while (1) {
                                    scanf("%c", &choice);
                                    switch (choice) {
                                        case 'M' : {
                                            int movement;
                                            if (player2->getPosition() < 6 &&
                                                player2->getPosition() - 1 > player1->getPosition())
                                                movement = 2;
                                            else if (player2->getPosition() < 6)
                                                movement = -1;
                                            else if (player2->getPosition() - 1 > player1->getPosition())
                                                movement = 1;
                                            else movement = 0;

                                            switch (movement) {
                                                case 2: {
                                                    cout
                                                            << "You can move forward or backward, type F to move forward, B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 1: {
                                                    cout
                                                            << "You can move only forward, type F to move forward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case -1: {
                                                    cout
                                                            << "You can move only backward, type B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 0: {
                                                    cout << "You can't move to any side, your turn is over " << endl;
                                                    break;
                                                }
                                            }
                                            char direction;
                                            int flag = 0;
                                            if (movement)
                                                while (1) {
                                                    scanf("%c", &direction);
                                                    switch (direction) {
                                                        case 'F' : {
                                                            if (movement != -1) {
                                                                player2->move(0);
                                                                cout << "You have moved forward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'B': {
                                                            if (movement != 1) {
                                                                player2->move(1);
                                                                cout << "You have moved backward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'C': {
                                                            cout << "You decided to do not move" << endl;
                                                            flag = 1;
                                                            break;
                                                        }
                                                        /*default: {
                                                            cout << "Wrong input. Try again!" << endl;
                                                            break;
                                                        }*/
                                                    }
                                                    if (flag) break;
                                                }
                                            flag0 = 1;
                                            break;
                                        }

                                        case 'A': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if(player2->getRange() >= distance){
                                                if(player1->getRange() >= distance){
                                                    cout << "Player2 dealed " << player2->getAttack() << " damage" << endl;
                                                    cout << "Player1 took" << player1->takeDamage(player2->getAttack()) << " damage" << endl;
                                                }
                                            }
                                            else
                                                cout << "You're not close enough to attack" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                        case 'S': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if(player2->getRange() <= distance){
                                                player2->consume();
                                                cout << "You successfuly consumed a part of your armor, your attack increased" << endl;
                                            }
                                            else
                                                cout << "You're not close enough to use skill" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                        /*default: {
                                            cout << "Wrong input. Try again!" << endl;
                                            break;
                                        }*/
                                    }
                                    if (flag0) break;
                                }


                                if(player1->isDead()){
                                    cout << "Player1 is dead, Player2 won. Game is over" << endl;
                                    return 0;
                                }
                            }
                        }

                        case 'M': {
                            cout << "You choosed a Mage" << endl;
                            //player[1] = 2;
                            Mage *player2 = new Mage(6);
                            /*table[0] = 1;
                            table[6] = 1;*/

                            while (1) {
                                cout
                                        << "Player1, what's your action? Type M to move, A to attack, S to use active skill"
                                        << endl;
                                int flag0 = 0;
                                while (1) {
                                    scanf("%c", &choice);
                                    switch (choice) {
                                        case 'M' : {
                                            int movement;
                                            if (player1->getPosition() > 0 &&
                                                player1->getPosition() + 1 < player2->getPosition())
                                                movement = 2;
                                            else if (player1->getPosition() > 0)
                                                movement = -1;
                                            else if (player1->getPosition() + 1 < player2->getPosition())
                                                movement = 1;
                                            else movement = 0;

                                            switch (movement) {
                                                case 2: {
                                                    cout
                                                            << "You can move forward or backward, type F to move forward, B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 1: {
                                                    cout
                                                            << "You can move only forward, type F to move forward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case -1: {
                                                    cout
                                                            << "You can move only backward, type B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 0: {
                                                    cout << "You can't move to any side, your turn is over " << endl;
                                                    break;
                                                }
                                            }
                                            char direction;
                                            int flag = 0;
                                            if (movement)
                                                while (1) {
                                                    scanf("%c", &direction);
                                                    switch (direction) {
                                                        case 'F' : {
                                                            if (movement != -1) {
                                                                player1->move(1);
                                                                cout << "You have moved forward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'B': {
                                                            if (movement != 1) {
                                                                player1->move(0);
                                                                cout << "You have moved backward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'C': {
                                                            cout << "You decided to do not move" << endl;
                                                            flag = 1;
                                                            break;
                                                        }
                                                            /*default: {
                                                                cout << "Wrong input. Try again!" << endl;
                                                                break;
                                                            } */
                                                    }
                                                    if (flag) break;
                                                }
                                            flag0 = 1;
                                            break;
                                        }

                                        case 'A': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if (player1->getRange() >= distance) {
                                                cout << "Player1 dealed " << player1->getAttack() << " damage" << endl;
                                                cout << "Player2 took " << player2->takeDamage(player1->getAttack()) << " damage" << endl;
                                            } else
                                                cout << "You're not close enough to attack" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                        case 'S': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if (player1->getRange() <= distance) {
                                                player1->consume();
                                                cout << "You successfuly consumed a part of your armor" << endl;
                                            } else
                                                cout << "You're not close enough to use skill" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                            /*default: {
                                                cout << "Wrong input. Try again!" << endl;
                                                break;
                                            } */
                                    }
                                    if (flag0) break;
                                }


                                cout
                                        << "Player2, what's your action? Type M to move, A to attack, S to use active skill"
                                        << endl;
                                flag0 = 0;
                                while (1) {
                                    scanf("%c", &choice);
                                    switch (choice) {
                                        case 'M' : {
                                            int movement;
                                            if (player2->getPosition() < 6 &&
                                                player2->getPosition() - 1 > player1->getPosition())
                                                movement = 2;
                                            else if (player2->getPosition() < 6)
                                                movement = -1;
                                            else if (player2->getPosition() - 1 > player1->getPosition())
                                                movement = 1;
                                            else movement = 0;

                                            switch (movement) {
                                                case 2: {
                                                    cout
                                                            << "You can move forward or backward, type F to move forward, B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 1: {
                                                    cout
                                                            << "You can move only forward, type F to move forward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case -1: {
                                                    cout
                                                            << "You can move only backward, type B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 0: {
                                                    cout << "You can't move to any side, your turn is over " << endl;
                                                    break;
                                                }
                                            }
                                            char direction;
                                            int flag = 0;
                                            if (movement)
                                                while (1) {
                                                    scanf("%c", &direction);
                                                    switch (direction) {
                                                        case 'F' : {
                                                            if (movement != -1) {
                                                                player2->move(0);
                                                                cout << "You have moved forward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'B': {
                                                            if (movement != 1) {
                                                                player2->move(1);
                                                                cout << "You have moved backward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'C': {
                                                            cout << "You decided to do not move" << endl;
                                                            flag = 1;
                                                            break;
                                                        }
                                                            /*default: {
                                                                cout << "Wrong input. Try again!" << endl;
                                                                break;
                                                            }*/
                                                    }
                                                    if (flag) break;
                                                }
                                            flag0 = 1;
                                            break;
                                        }

                                        case 'A': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if(player2->getRange() >= distance){
                                                cout << "Player2 dealed " << player2->getAttack() << " damage" << endl;
                                                cout << "Player1 took" << player1->takeDamage(player2->getAttack()) << " damage" << endl;
                                            }
                                            else
                                                cout << "You're not close enough to attack" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                        case 'S': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if(player2->getRange() <= distance){
                                                player2->oneOfEight(1);
                                            }
                                            else{
                                                cout << "You're not close enough to use skill" << endl;
                                                player2->oneOfEight(0);
                                            }
                                            flag0 = 1;
                                            break;
                                        }
                                            /*default: {
                                                cout << "Wrong input. Try again!" << endl;
                                                break;
                                            }*/
                                    }
                                    if (flag0) break;
                                }

                                if (player2->isDead()) {
                                    cout << "Player2 is dead, Player1 won. Game is over" << endl;
                                    return 0;
                                }
                                else
                                if(player1->isDead()){
                                    cout << "Player1 is dead, Player2 won. Game is over" << endl;
                                    return 0;
                                }
                            }
                        }
                        case 'G': {
                            cout << "You choosed a Goblin" << endl;
                            //player[1] = 3;
                            Goblin *player2 = new Goblin(6);
                            /*table[0] = 1;
                            table[6] = 1;*/

                            while (1) {
                                cout
                                        << "Player1, what's your action? Type M to move, A to attack, S to use active skill"
                                        << endl;
                                int flag0 = 0;
                                while (1) {
                                    scanf("%c", &choice);
                                    switch (choice) {
                                        case 'M' : {
                                            int movement;
                                            if (player1->getPosition() > 0 &&
                                                player1->getPosition() + 1 < player2->getPosition())
                                                movement = 2;
                                            else if (player1->getPosition() > 0)
                                                movement = -1;
                                            else if (player1->getPosition() + 1 < player2->getPosition())
                                                movement = 1;
                                            else movement = 0;

                                            switch (movement) {
                                                case 2: {
                                                    cout
                                                            << "You can move forward or backward, type F to move forward, B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 1: {
                                                    cout
                                                            << "You can move only forward, type F to move forward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case -1: {
                                                    cout
                                                            << "You can move only backward, type B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 0: {
                                                    cout << "You can't move to any side, your turn is over " << endl;
                                                    break;
                                                }
                                            }
                                            char direction;
                                            int flag = 0;
                                            if (movement)
                                                while (1) {
                                                    scanf("%c", &direction);
                                                    switch (direction) {
                                                        case 'F' : {
                                                            if (movement != -1) {
                                                                player1->move(1);
                                                                cout << "You have moved forward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'B': {
                                                            if (movement != 1) {
                                                                player1->move(0);
                                                                cout << "You have moved backward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'C': {
                                                            cout << "You decided to do not move" << endl;
                                                            flag = 1;
                                                            break;
                                                        }
                                                            /*default: {
                                                                cout << "Wrong input. Try again!" << endl;
                                                                break;
                                                            } */
                                                    }
                                                    if (flag) break;
                                                }
                                            flag0 = 1;
                                            break;
                                        }

                                        case 'A': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if (player1->getRange() >= distance) {
                                                cout << "Player1 dealed " << player1->getAttack() << " damage" << endl;
                                                cout << "Player2 took " << player2->takeDamage(player1->getAttack()) << " damage" << endl;
                                            } else
                                                cout << "You're not close enough to attack" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                        case 'S': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if (player1->getRange() <= distance) {
                                                player1->consume();
                                                cout << "You successfuly consumed a part of your armor" << endl;
                                            } else
                                                cout << "You're not close enough to use skill" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                            /*default: {
                                                cout << "Wrong input. Try again!" << endl;
                                                break;
                                            } */
                                    }
                                    if (flag0) break;
                                }

                                if (player2->isDead()) {
                                    cout << "Player2 is dead, Player1 won. Game is over" << endl;
                                    return 0;
                                }

                                cout
                                        << "Player2, what's your action? Type M to move, A to attack, S to use active skill"
                                        << endl;
                                flag0 = 0;
                                while (1) {
                                    scanf("%c", &choice);
                                    switch (choice) {
                                        case 'M' : {
                                            int movement;
                                            if (player2->getPosition() < 6 &&
                                                player2->getPosition() - 1 > player1->getPosition())
                                                movement = 2;
                                            else if (player2->getPosition() < 6)
                                                movement = -1;
                                            else if (player2->getPosition() - 1 > player1->getPosition())
                                                movement = 1;
                                            else movement = 0;

                                            switch (movement) {
                                                case 2: {
                                                    cout
                                                            << "You can move forward or backward, type F to move forward, B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 1: {
                                                    cout
                                                            << "You can move only forward, type F to move forward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case -1: {
                                                    cout
                                                            << "You can move only backward, type B to move backward or C to cancel and end your turn"
                                                            << endl;
                                                    break;
                                                }
                                                case 0: {
                                                    cout << "You can't move to any side, your turn is over " << endl;
                                                    break;
                                                }
                                            }
                                            char direction;
                                            int flag = 0;
                                            if (movement)
                                                while (1) {
                                                    scanf("%c", &direction);
                                                    switch (direction) {
                                                        case 'F' : {
                                                            if (movement != -1) {
                                                                player2->move(0);
                                                                cout << "You have moved forward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'B': {
                                                            if (movement != 1) {
                                                                player2->move(1);
                                                                cout << "You have moved backward" << endl;
                                                            }
                                                            flag = 1;
                                                            break;
                                                        }
                                                        case 'C': {
                                                            cout << "You decided to do not move" << endl;
                                                            flag = 1;
                                                            break;
                                                        }
                                                            /*default: {
                                                                cout << "Wrong input. Try again!" << endl;
                                                                break;
                                                            }*/
                                                    }
                                                    if (flag) break;
                                                }
                                            flag0 = 1;
                                            break;
                                        }

                                        case 'A': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if(player2->getRange() >= distance){
                                                cout << "Player2 dealed " << player2->getAttack() << " damage" << endl;
                                                cout << "Player1 took" << player1->takeDamage(player2->getAttack()) << " damage" << endl;
                                            }
                                            else
                                                cout << "You're not close enough to attack" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                        case 'S': {
                                            int distance = abs(player1->getPosition() - player2->getPosition());
                                            if(player2->getRange() <= distance){
                                                if(player2->bomb() ){
                                                    cout << "cause bomb explosion Player1 took " << player1->takeDamage(player1->getHp()-1) << " damage" << endl;
                                                    cout << "cause bomb explosion Player2 took " << player2->takeDamage(player2->getHp()-1) << " damage" << endl;
                                                }
                                            }
                                            else
                                                cout << "You're not close enough to use skill" << endl;
                                            flag0 = 1;
                                            break;
                                        }
                                            /*default: {
                                                cout << "Wrong input. Try again!" << endl;
                                                break;
                                            }*/
                                    }
                                    if (flag0) break;
                                }

                                if (player2->isDead()) {
                                    cout << "Player2 is dead, Player1 won. Game is over" << endl;
                                    return 0;
                                }
                                else
                                if(player1->isDead()){
                                    cout << "Player1 is dead, Player2 won. Game is over" << endl;
                                    return 0;
                                }

                            }

                            break;
                        }
                        /*default: {
                            cout << "Wrong input. Try again!" << endl;
                            break;
                        } */
                    }
                    if (player[1]) break;
                }

                break;
            }
            case 'M': {
                cout << "You choosed a Mage" << endl;
                player[0] = 2;
                Mage *player1 = new Mage(0);

                cout
                        << "Player 2 choose your character, type K to pick a Knight, M to pick a Mage or G to pick a Goblin"
                        << endl;
                while (1) {
                    scanf("%c", &choice);
                    switch (choice) {
                        case 'K' : {
                            cout << "You choosed a Knight" << endl;
                            player[1] = 1;
                            Knight *player2 = new Knight(6);
                            break;
                        }
                        case 'M': {
                            cout << "You choosed a Mage" << endl;
                            player[1] = 2;
                            Mage *player2 = new Mage(6);
                            break;
                        }
                        case 'G': {
                            cout << "You choosed a Goblin" << endl;
                            player[1] = 3;
                            Goblin *player2 = new Goblin(6);
                            break;
                        }
                        default: {
                            cout << "Wrong input. Try again!" << endl;
                            break;
                        }
                    }
                    if (player[1]) break;
                }

                break;
            }
            case 'G': {
                cout << "You choosed a Goblin" << endl;
                player[0] = 3;
                Goblin *player2 = new Goblin(0);

                cout
                        << "Player 2 choose your character, type K to pick a Knight, M to pick a Mage or G to pick a Goblin"
                        << endl;
                while (1) {
                    scanf("%c", &choice);
                    switch (choice) {
                        case 'K' : {
                            cout << "You choosed a Knight" << endl;
                            player[1] = 1;
                            Knight *player2 = new Knight(6);
                            break;
                        }
                        case 'M': {
                            cout << "You choosed a Mage" << endl;
                            player[1] = 2;
                            Mage *player2 = new Mage(6);
                            break;
                        }
                        case 'G': {
                            cout << "You choosed a Goblin" << endl;
                            player[1] = 3;
                            Goblin *player2 = new Goblin(6);
                            break;
                        }
                        default: {
                            cout << "Wrong input. Try again!" << endl;
                            break;
                        }
                    }
                    if (player[1]) break;
                }

                break;
            }
            default: {
                cout << "Wrong input. Try again!" << endl;
                break;
            }
        }
        if (player[0]) break;
    }

    return 0;
}
