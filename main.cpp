#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Player.h"
#include "GameFunctions.h"

using namespace std;

int main(){
    srand(time(0));

    string playerName;
    cout << "Enter your hero name: ";
    getline(cin, playerName);
    Player hero(playerName);
    intro();
    avengersHQ(hero);
    return 0;
}
