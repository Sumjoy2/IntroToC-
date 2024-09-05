#include <iostream>
#include "Exercises.h"

using std::cout;
using std::cin;
using std::endl;

class Player
{
	char* Name = nullptr;

	Player(const char* InputName)
	{
		size_t Length = strlen(InputName);

		//Have space because name is a nullptr
		Name = new char[Length + 1];

		strcpy_s(Name, Length + 1, InputName);
	}

	~Player()
	{
		delete[] Name;
	}
};

int main()
{
	int UserNumbers;

	////Normal Array
	//int Numbers[10] = {};
	//cout << "How many numbers" << endl;
	//cin >> UserNumbers;
	////dynamic array
	//int* DynamicNumbers = new int[UserNumbers];

	//delete[] DynamicNumbers;

	cin >> UserNumbers;
	cout << ZeroArray << endl;
	
	return 0;
}