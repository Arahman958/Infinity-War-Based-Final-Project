#include "Player.h"

Player::Player(string n){
    name = n;
    health = 100;
    powerLevel = 20;
    stonesCollected = 0;
}

void Player::showStats(){
    cout << "\n========== PLAYER STATS ==========\n";
    cout << "Hero: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Power Level: " << powerLevel << endl;
    cout << "Infinity Stones: " << stonesCollected << endl;
    cout << "Inventory:\n";

    if(inventory.size() == 0){
        cout << "- Empty\n";
    }

    for(int i = 0; i < inventory.size(); i++){
        cout << "- " << inventory[i] << endl;
    }
    cout << "==================================\n";
}

void Player::addItem(string item){
    inventory.push_back(item);
}

void Player::loseHealth(int amount){
    health -= amount;
    if(health < 0){
        health = 0;
    }
}

void Player::gainPower(int amount){
    powerLevel += amount;
}

void Player::heal(int amount){
    health += amount;
    if(health > 100)
    {
        health = 100;
    }
}

void Player::collectStone(){
    stonesCollected++;
}

int Player::getHealth(){
    return health;
}

int Player::getPower(){
    return powerLevel;
}

int Player::getStones(){
    return stonesCollected;
}

string Player::getName(){
    return name;
}
