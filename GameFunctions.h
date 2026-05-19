#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#include "Player.h"

void intro();
void avengersLogo();
void infinityGauntlet();

void avengersHQ(Player &p);
void wakanda(Player &p);
void titan(Player &p);
void vormir(Player &p);
void knowhere(Player &p);
void asgard(Player &p);
void quantumRealm(Player &p);

void randomBattle(Player &p, string enemy);
void puzzleMiniGame(Player &p);
void hackingMiniGame(Player &p);
void guessingMiniGame(Player &p);

void collectStone(Player &p, string stoneName);
void finalBattle(Player &p);

void goodEnding(Player &p);
void badEnding(Player &p);

void rest(Player &p);

#endif
