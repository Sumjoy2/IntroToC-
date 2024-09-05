#include "Zombie.h"
#include <iostream>
#include <cstdlib>  // for srand
#include <ctime>    // for time

Zombie::Zombie()
{

}

int Zombie::TellHealth()
{
	return Health;
}

bool Zombie::TellDead()
{
	return IsDead;
}

void Zombie::TakeDamage(int DmgDealt)
{
	int Invincable = std::rand() % 10;
	if (Invincable == 0)
	{
		return;
	}
	else
	{
		Health -= DmgDealt;
		return;
	}
}

void Zombie::TurnEffectsZombies(const char Input, const char Response, Player* Opponent)
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

	if (Health <= 0)
	{
		IsDead = true;
	}
}
