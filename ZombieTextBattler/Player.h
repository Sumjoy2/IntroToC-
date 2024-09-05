#pragma once
#include <string>
#include "Zombie.h"

class Zombie;

class Player
{
	//cannot be used outside of class
private:
	std::string Name;
	int Health = 25;
	int AtkOne = 2;
	int Score = 1;
	int HealAmt = 2;

	//usable outside of the class
public:
	int Defence = 1;

	Player();
	Player(std::string UsrName);
	int TellScore();
	int TellHealth();
	void TakeDamage(int DmgDealt);
	void GainHealth();	
	//int GainATK();	
	void TurnEffectsPlayer(const char Input, const char Response, Zombie* Opponent);
};