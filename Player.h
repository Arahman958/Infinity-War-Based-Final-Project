#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>

using namespace std;
class Player{
private:
    string name;
    int health;
    int powerLevel;
    int stonesCollected;
    vector<string> inventory;
public:
    Player(string n);
    void showStats();
    void addItem(string item);
    void loseHealth(int amount);
    void gainPower(int amount);
    void heal(int amount);
    void collectStone();

    int getHealth();
    int getPower();
    int getStones();
    string getName();
};
#endif
