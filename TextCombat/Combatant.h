#pragma once
#include <string>

class Combatant
{
	//cannot be used outside of class
private:
	std::string Name;
	int Health = 5;
	int Defence = 1;
	int AtkOne = 2;
	int AtkTwo = 3;

	//usable outside of the class
public:
	Combatant();
	Combatant(std::string UsrName);
	int TakeDamage(int DmgDealt);
	int GetHealth();
	void TurnEffects(const char Input, const char Response, Combatant* Opponent);
};

