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
void ZombieLoop(Zombie Zombies[], int ZombieMax, char ZombResponses[], int AliveZombies);
void TurnOutcomes(Zombie Zombie[], Player* Attacker, int ZombieNumber, char UserInput, char Response[]);

/* ToDo:
* make all zombies attack
* finish healing
*  - make limited amount of healing
*  - randomize healing amount ~ 1d4
* finish being able to upgrade attack damage
* make zombies killable
*  - increment score when zombie dies
* implement high scores
* loss condition more explained
* */

int main()
{
#pragma region SetupThings
    std::srand(std::time(nullptr));
    Player Player1 = Player("Player1");
    Zombie Player2[5];

    Player* Attacker = &Player1;

    Zombie* Zombie = &Player2[0];

    char UserInput = '>';
    char Response[5] = { '<','<','<','<','<'};

    int ZombieMax = 5;

    int AliveZombies = ZombieMax;
#pragma endregion

#pragma region BattleLoop
    while(Attacker->TellHealth() != 0 && UserInput != 'q')
    {
        ZombieLoop(Player2, ZombieMax, Response, AliveZombies);
        cout << "Player Health: " << Attacker->TellHealth() << "\nWhat do you want to do?  a is Attack  d is Defend" << endl;
        PlayerInput(UserInput);
        TurnOutcomes(Zombie, Attacker, AliveZombies, UserInput, Response);
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

void ZombieLoop(Zombie Zombies[], int ZombieMax, char ZombResponses[], int AliveZombies)
{
    for (int i = 0; i < ZombieMax; i++)
    {
        cout << "Zombie "<< (AliveZombies +1) - (i + 1) << " Health: " << Zombies[i].TellHealth() << '\t';
        OponentInput(ZombResponses[i]);
        if (Zombies[i].TellDead() == true)
        {
            AliveZombies--;
            //Remove Zombie From Playing Field
            continue;
        }
    }
    cout << endl;
}

void TurnOutcomes(Zombie Zombie[], Player * Attacker, int ZombieNumber, char UserInput, char Response[])
{
    int StartHealth = Attacker->TellHealth();
    for (int i = 0; i < ZombieNumber; i++)
    {
        Attacker->TurnEffectsPlayer(UserInput, Response[i], Zombie);
        Zombie->TurnEffectsZombies(Response[i], UserInput, Attacker);
    }
    cout << "You Took " << StartHealth - Attacker->TellHealth() << " Damage" << endl;
}