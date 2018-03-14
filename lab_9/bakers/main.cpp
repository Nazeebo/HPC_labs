#include <iostream>
#include "baker.h"

using namespace std;

enum class ActionType {
    Bake=0, Eat, Give
};

ActionType getActionType(){
    srand(time(NULL));
    int action = rand()%3+1;
    if(action == 1) return ActionType::Bake;
    if(action == 2) return ActionType::Eat;
    if(action == 3) return ActionType::Give;
}

int bake(Baker baker1, Baker baker2){  //training of bakers
    int limit = 30;
    ActionType bake1, bake2;
    for(int i = 0; i < 25; i++){
        bake1 = getActionType();

        if(bake1 == ActionType::Bake) baker1.createPie();
        else if(bake1 == ActionType::Eat) baker1.eatPie();
        else if(bake1 == ActionType::Give) baker1.givePie(baker2);

        bake2 = getActionType();

        if(bake2 == ActionType::Bake) baker2.createPie();
        else if(bake2 == ActionType::Eat) baker2.eatPie();
        else if(bake2 == ActionType::Give) baker2.givePie(baker1);

        if(baker1.getCounter() + baker2.getCounter() >= limit) return 200;
    }
    return 200*(baker1.getCounter() + baker2.getCounter())/30;
}

int main() {
    Baker baker1,baker2;
    int wins = 0,exp;

    while(wins < 15){
        for(int i = 0; i < 10; i++){
            baker1.createPie();
            baker2.createPie();
        }
        exp = bake(baker1,baker2);
        if(exp == 200) wins++;
        baker1.incExpAndProf(exp/2);
        baker2.incExpAndProf(exp/2);
        for(int i = 0; i < 10; i++){
            baker1.eatPie();
            baker2.eatPie();
        }
    }
    return 0;
}