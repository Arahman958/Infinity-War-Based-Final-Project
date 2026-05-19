#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameFunctions.h"
#include "Location.h"

using namespace std;

// ASCII art inspired by https://www.asciiart.eu/

void avengersLogo(){
    cout << R"(

      AAAAA
     AA   AA
    AAAAAAAA
    AA    AA
    AA    AA

)";
}

void infinityGauntlet()
{
    cout << R"(

          _______
         / _____ \
        / /     \ \
       | |  O O  | |
       | |   ^   | |
       | | \___/ | |
        \ \_____/ /
         \_______/

)";
}

//Chatgpt helped us write the dialogues like the ones ahead
void intro(){
    avengersLogo();
    cout << "\nEarth has fallen into chaos.\n";
    cout << "Thanos is searching for the Infinity Stones.\n";
    cout << "The Avengers are scattered.\n";
    cout << "You are humanity's final hope.\n";
}

void collectStone(Player &p, string stoneName){
    cout << "\nYou obtained the " << stoneName << "!\n";
    p.collectStone();
    p.gainPower(15);
    p.addItem(stoneName);
}

// Chatgpt helped debug the combat system, I needed help figuring out how to do the damage and health calculations
void randomBattle(Player &p, string enemy){
    int enemyHealth = 50;
    cout << "\nA battle has started against " << enemy << "!\n";
    while(enemyHealth > 0 && p.getHealth() > 0){
        cout << "\n1. Attack";
        cout << "\n2. Heal";
        cout << "\nChoose: ";
        int choice;
        cin >> choice;

        if(choice == 1){
            int damage = rand() % 20 + 10;
            enemyHealth -= damage;
            cout << "You dealt " << damage << " damage!\n";
        }
        else{
            p.heal(10);
            cout << "You healed yourself.\n";
        }
        if(enemyHealth > 0){
            int enemyDamage = rand() % 15 + 5;
            cout << enemy << " hit you for "
                 << enemyDamage << " damage!\n";
            p.loseHealth(enemyDamage);
        }
        cout << "Enemy Health: " << enemyHealth << endl;
        cout << "Your Health: " << p.getHealth() << endl;
    }

    if(p.getHealth() <= 0){
        badEnding(p);
    }
    cout << "\nYou defeated " << enemy << "!\n";
}

void puzzleMiniGame(Player &p){
    cout << "\nYou encounter an ancient puzzle.\n";
    int answer;
    cout << "What is 14 + 16?\n";
    cin >> answer;

    if(answer == 30){
        cout << "Correct!\n";
        p.gainPower(10);
    }
    else
    {
        cout << "Wrong answer.\n";
        p.loseHealth(10);
    }
}

//Chatgpt helped me test and debug the hacking and guessing minigames
void hackingMiniGame(Player &p){
    int code = rand() % 10 + 1;
    int guess;
    cout << "\nHack the enemy system.\n";
    cout << "Guess the security code (1-10): ";
    cin >> guess;

    if(guess == code){
        cout << "Access granted.\n";
        p.gainPower(20);
    }
    else{
        cout << "Access denied.\n";
        p.loseHealth(15);
    }
}

void guessingMiniGame(Player &p){
    int number = rand() % 5 + 1;
    int guess;
    cout << "\nGuess the correct portal number (1-5): ";
    cin >> guess;

    if(guess == number){
        cout << "Correct portal!\n";
        p.gainPower(15);
    }
    else{
        cout << "Wrong portal.\n";
        p.loseHealth(15);
    }
}

void rest(Player &p){
    cout << "\nYou take a short rest.\n";
    p.heal(20);
    cout << "Health restored.\n";
}

//Chatgpt also helped us write the descriptions of each location like Titan and Asgard
void wakanda(Player &p){
    Location wakandaBase(
    "Wakanda",
    "The battlefield is filled with alien armies."
    );
    wakandaBase.displayLocation();
    randomBattle(p, "Outrider");
    collectStone(p, "Mind Stone");
    rest(p);
}

void titan(Player &p){
    Location titanWorld(
    "Titan",
    "A destroyed planet once ruled by Thanos."
    );
    titanWorld.displayLocation();
    puzzleMiniGame(p);
    randomBattle(p, "Black Order Soldier");
    collectStone(p, "Power Stone");
}

void vormir(Player &p){
    Location soulWorld(
    "Vormir",
    "A mysterious planet hidden in darkness."
    );
    soulWorld.displayLocation();
    guessingMiniGame(p);
    collectStone(p, "Soul Stone");
}

void knowhere(Player &p){
    Location knowhereBase(
    "Knowhere",
    "A dangerous mining colony in space."
    );
    knowhereBase.displayLocation();
    hackingMiniGame(p);
    randomBattle(p, "Space Pirate");
    collectStone(p, "Reality Stone");
}

void asgard(Player &p){
    Location asgardRuins(
    "Asgard Ruins",
    "The remains of Thor's homeland."
    );
    asgardRuins.displayLocation();
    randomBattle(p, "Fire Beast");
    collectStone(p, "Space Stone");
}

void quantumRealm(Player &p){
    Location quantum(
    "Quantum Realm",
    "Time and space behave strangely here."
    );
    quantum.displayLocation();
    puzzleMiniGame(p);
    collectStone(p, "Time Stone");
}

//Refined and Debugged using Chatgpt because I was having issues with repeated attacks and calculating the health
void finalBattle(Player &p){
    infinityGauntlet();
    cout << "\nTHE FINAL SHOWDOWN AGAINST THANOS\n";
    int thanosHealth = 150;
    while(thanosHealth > 0 && p.getHealth() > 0){
        cout << "\n1. Attack";
        cout << "\n2. Heal";
        cout << "\n3. View Your Stats";
        cout << "\nChoose: ";
        int choice;
        cin >> choice;

        if(choice == 1){
            int damage = rand() % 30 + p.getPower();
            thanosHealth -= damage;
            cout << "\nYou hit Thanos for "
                 << damage << " damage!\n";
        }
        else if(choice == 2){
            p.heal(15);
            cout << "\nYou healed yourself.\n";
        }
        else{
            p.showStats();
        }

        if(thanosHealth > 0){
            int thanosDamage = rand() % 25 + 10;
            cout << "\nThanos attacks for "
                 << thanosDamage << " damage!\n";
            p.loseHealth(thanosDamage);
        }
             cout << "Thanos Health: "
             << thanosHealth << endl;
    }

    if(p.getHealth() <= 0){
        badEnding(p);
    }
    goodEnding(p);
}

void goodEnding(Player &p){
    cout << "\nYou defeated Thanos.\n";
    cout << "The universe has been restored.\n";
    cout << "The Avengers honor your bravery.\n";
    exit(0);
}

void badEnding(Player &p){
    cout << "\nYou were defeated.\n";
    cout << "Thanos completed the Snap.\n";
    cout << "Half the universe disappeared.\n";
    exit(0);
}

void avengersHQ(Player &p){
    int choice = 0;
    while(choice != 7)
    {
        cout << "\n========== AVENGERS HQ ==========\n";
        cout << "1. Travel to Wakanda\n";
        cout << "2. Travel to Titan\n";
        cout << "3. Travel to Vormir\n";
        cout << "4. Travel to Knowhere\n";
        cout << "5. Travel to Asgard Ruins\n";
        cout << "6. Travel to Quantum Realm\n";
        cout << "7. Fight Thanos\n";
        cout << "8. View Stats\n";
        cout << "=================================\n";

        cin >> choice;
        if(choice == 1){
            wakanda(p);
        }
        else if(choice == 2){
            titan(p);
        }
        else if(choice == 3){
            vormir(p);
        }
        else if(choice == 4){
            knowhere(p);
        }
        else if(choice == 5){
            asgard(p);
        }
        else if(choice == 6){
            quantumRealm(p);
        }
        else if(choice == 7){
            if(p.getStones() >= 6){
                finalBattle(p);
            }
            else{
            cout << "\nYou need all 6 Infinity Stones first.\n";
            }
        }
        else if(choice == 8){
            p.showStats();
        }
        else{
            cout << "Invalid choice\n";
        }
    }
}
