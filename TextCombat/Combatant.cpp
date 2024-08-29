#include "Combatant.h"
#include <iostream>
#include <cstdlib>  // for srand
#include <ctime>    // for time

void Combatant::NameUpdate(char NewName[])
{
	for (int i = 0; i < strlen(NewName); i++)
	{
		Name[i] = NewName[i];
	}
}
	

int Combatant::TakeDamage(int DmgDealt)
	{
		int Invincable = std::rand() % 10;
		if (Invincable == 0)
		{
			return Health;
		}
		else
		{
			Health -= (DmgDealt - Defence);
			return Health;
		}
	}

int Combatant::GetHealth()
	{
		return Health;
	}
