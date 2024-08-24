#include <iostream>
#include "LeHeader.h"

using std::cout;
using std::cin;
using std::endl;

void Welcome()
{
	char OutName[255];
	char UserInput[26];
	cout << "Enter Your Name. (I am not a fae and not going to steal it)" << endl;
	cin.getline(OutName, 255);
	cout << endl << "MWAHAHAHAHA I NOW OWN THE NAME " << OutName << endl;
	cout << "now that I own your name what is your favorite color?" << endl;
	cin >> UserInput;
	if (strcmp(UserInput, "Orange") == 0)
	{
		cout << "Orange is a tasteful color" << endl;
	}
	else if (strcmp(UserInput, "Blue") == 0)
	{
		cout << "Blue is my favorite color as well" << endl;
	}
	else if (strcmp(UserInput, "Red") == 0)
	{
		cout << "Red quite an angry color" << endl;
	}
	else
	{
		cout << "I have not heard of that color before, it sounds interesting" << endl;
	}
}

int StringLength()
{
	char UserInput[26];
	int OutLength = 0;
	cin >> UserInput;
	int temp = 0;
	for (int i = 0; i < 26; i++)
	{
		if (int(UserInput[i]) == 0) break;
		temp = i;
	}
	OutLength = temp + 1;
	cout << OutLength;
	return OutLength;
}

void ToCapital()
{
	char UserIput[255];
	cin.getline(UserIput, 255);
	for (int i=0; i < strlen(UserIput); i++)
	{
		if (int(UserIput[i]) == 0)
		{
			break;
		}
		else if (int(UserIput[i]) == 32) continue;
		else if (97 <= int(UserIput[i]) && int(UserIput[i]) <= 122)
		{
			UserIput[i] = UserIput[i] - 32;
		}
	}
	cout << UserIput;
}

void NoSpace()
{
	char UserIput[255];
	cin.getline(UserIput, 255);
	for (int i = 0; i < strlen(UserIput); i++)
	{
		if (int(UserIput[i]) == 0)
		{
			break;
		}
		else if (int(UserIput[i]) == 32)
		{
			UserIput[i] = 7;
		}
	}
	cout << UserIput;
}

void Substring(char Input[], int start, int end, char destination[])
{
	for (int i = start; i <= end; i++)
	{
		destination[i] = Input[i];
		cout << destination[i];
	}
	cout << destination << endl;
}

//char StringReverse(char Numbers[])
//{
//	int Countdown = strlen(Numbers) - 1;
//	for (int i = 0; i != strlen(Numbers) / 2; i++)
//	{
//		char temp = Numbers[i];
//		Numbers[i] = Numbers[Countdown];
//		Numbers[Countdown] = temp;
//		Countdown--;
//	}
//}

//bool Palindrome(char Input[])
//{
//	char TheTester;
//	TheTester = StringReverse(Input);
//	if (strcmp(Input, TheTester) == 0)
//		return true;
//	else return false;
//}