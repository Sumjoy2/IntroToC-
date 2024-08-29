#include "Combatant.h"
#include <iostream>
#include <cstdlib>  // for srand
#include <ctime>    // for time

Combatant::Combatant()
{

}

Combatant::Combatant(std::string UsrName)
{
	Name = UsrName;
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

void Combatant::TurnEffects(const char Input, const char Response, Combatant* Opponent)
{
    if (Input == 'a')
    {
        if (Response == 'a')
        {
			Opponent->TakeDamage(AtkOne);
        }
		else
        {
			Opponent->TakeDamage(AtkOne / Opponent->Defence);
        }
    }
}
