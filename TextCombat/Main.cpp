#include <iostream>
#include "Combatant.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Combatant Player1;
    char UserInput = '>';
    while (UserInput != 'q')
    {
        cin >> UserInput;
        if (UserInput == 'a')
        {
            cout << "Normal Attack: " << endl;
        }
        else if (UserInput == 's')
        {
            cout << "Special Attack: " << endl;
        }
        else
        {
            cout << "Input Not Found: " << endl;
        }
    }

    return 0;
}