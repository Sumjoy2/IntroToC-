#include "Player.h"
#include <iostream>
#include <cstdlib>  // for srand
#include <ctime>    // for time

int clamp(int Lowest, int Highest, int InNumber)
{
	if (InNumber < Lowest)
	{
		return Lowest;
	}
	else if (InNumber > Highest)
	{
		return Highest;
	}
	else
	{
		return InNumber;
	}
}

Player::Player()
{

}

Player::Player(std::string UsrName)
{
	Name = UsrName;
}

int Player::TellHealth()
{
	return Health;
}

int Player::TellScore()
{
	return Score;
}

void Player::GainHealth()
{
	Health += HealAmt;
}

void Player::TakeDamage(int DmgDealt)
{
	int Invincable = std::rand() % 10;
	if (Invincable == 0)
	{
		return;
	}
	else
	{
		Health -= clamp(0, 10, (DmgDealt - Defence));
		return;
	}
}

void Player::TurnEffectsPlayer(const char Input, const char Response, Zombie* Opponent)
{
	if (Input == 'a')
	{
		if (Response == 'a')
		{
			Opponent->TakeDamage(AtkOne);
		}
		else
		{
			Opponent->TakeDamage(AtkOne);
		}
	}
}
