#include <iostream>
#include <cstdlib>  // for srand
#include <ctime>    // for time
#include "Combatant.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void PlayerInput(char &Input)
{
    cin >> Input;
    if (Input == 'a')
    {
        cout << "Normal Attack: " << endl;
    }
    else if (Input == 's')
    {
        cout << "Special Attack: " << endl;
    }
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
    int Invincable = std::rand() % 2;
    if (Invincable == 0)
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

int main()
{
    std::srand(std::time(nullptr));
    Combatant Player1 = Combatant("Player1"); 
    Combatant Player2 = Combatant("Player2"); 

    Combatant* Attacker = &Player1;
    Combatant* Defender = &Player2;

    char UserInput = '>';
    char Response = '<';
   
    cout <<"Base Check " << Defender->GetHealth();

    while (Attacker->GetHealth() != 0 && Defender->GetHealth() != 0)
    {
        PlayerInput(UserInput);
        OponentInput(Response);
        Attacker->TurnEffects(UserInput, Response, Defender);
        Defender->TurnEffects(Response, UserInput, Attacker);

        cout << "Player 1 Health " << Attacker->GetHealth() << endl;
        cout << "Player 2 Health " << Defender->GetHealth()  << endl;
    }
    return 0;
}