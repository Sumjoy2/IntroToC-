#include "Player.h"
#include "Zombie.h"
#include <iostream>
#include <cstdlib>  // for srand
#include <ctime>    // for time

using std::cin;
using std::cout;
using std::endl;
using std::string;

//Initialize Functions Existing
void PlayerInput(char& Input);
void OponentInput(char& Resonse);
void ZombieLoop(Zombie Zombies[], int ZombieNumber, char ZombResponses[]);

int main()
{
#pragma region SetupThings
    std::srand(std::time(nullptr));
    Player Player1 = Player("Player1");
    Zombie Player2[5];

    Player* Attacker = &Player1;

    Zombie* Zombie1 = &Player2[0];

    char UserInput = '>';
    char Response[5] = { '<','<','<','<','<', };
#pragma endregion

#pragma region BattleLoop
    while(Attacker->TellHealth() != 0 && UserInput != 'q')
    {
        ZombieLoop(Player2, 5, Response);
        cout << "Player Health: " << Attacker->TellHealth() << "\nWhat do you want to do?  a is Attack  d is Defend" << endl;
        PlayerInput(UserInput);
        Attacker->TurnEffectsPlayer(UserInput, Response[0], Zombie1);
        Zombie1->TurnEffectsZombies(Response[0], UserInput, Attacker);
    }
#pragma endregion
    return 0;
}

void PlayerInput(char& Input)
{
    cin >> Input;
    if (Input == 'a')
    {
        cout << "Normal Attack: " << endl;
    }
    else if (Input == 'd')
    {
        cout << "Defending: " << endl;
    }
    /*else if (Input == 's')
    {
        cout << "Healing: " << endl;
    }*/
    else if (Input == 'q')
    {
        return;
    }
    else
    {
        cout << "Input Not Found: " << endl;
    }
}

void OponentInput(char& Resonse)
{
    int pick = std::rand() % 2;
    if (pick == 0)
    {
        Resonse = 'a';
        cout << "Opponent Attacks" << endl;
    }
    else
    {
        Resonse = 's';
        cout << "Opponent Special Attacks" << endl;
    }
}

void ZombieLoop(Zombie Zombies[], int ZombieNumber, char ZombResponses[])
{
    for (int i = 0; i < ZombieNumber; i++)
    {
        cout << "Zombie "<< i + 1 << " Health: " << Zombies[i].TellHealth() << '\t';
        OponentInput(ZombResponses[i]);
    }
    cout << endl;
}