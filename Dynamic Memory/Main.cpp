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
	char BaseArray[5] = { 'b', 'c', 'e', 'f', 'D' };
	int IntArr[5] = {1, 2, 3, 4, 5};
	int Outarr[7];
	////Normal Array
	//int Numbers[10] = {};
	//cout << "How many numbers" << endl;
	//cin >> UserNumbers;
	////dynamic array
	//int* DynamicNumbers = new int[UserNumbers];

	//delete[] DynamicNumbers;

	//cin >> UserNumbers;
	//cout << ZeroArray << endl;
	//NumberLover();
	cout <<endl << *CharSearch('d', BaseArray, false);
	//DuplicateArray(IntArr, 5);
	IntSubArrCopy(IntArr, 2, 4, Outarr);
	
	return 0;
}