#pragma once

class Combatant
{
	//cannot be used outside of class
private:
	char Name[6] = " ";
	int Health = 5;
	int Defence = 1;
	int AtkOne = 5;
	int AtkTwo = 10;

	//usable outside of the class
public
	void NameUpdate(char NewName[]);
	int TakeDamage(int DmgDealt);
	int GetHealth();
};

