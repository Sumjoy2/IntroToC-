#pragma once
#include <string>
#include "Player.h"

class Player;

class Zombie
{
	//cannot be used outside of class
private:
	int Health = 5;
	int AtkOne = 2;

	//usable outside of the class
public:
	Zombie();
	int TellHealth();
	void TakeDamage(int DmgDealt);
	void TurnEffectsZombies(const char Input, const char Response, Player* Opponent);
};