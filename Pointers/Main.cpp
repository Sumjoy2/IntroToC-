#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int SumofIntArr(int* InputArray, size_t InputSize)
{
	int temp = 0;
	for (int i = 0; i < InputSize; i++)
	{
		temp += InputArray[i];
	}
	return temp;
}

//giving default value means i can ignore it
char* FindInArray(char* ArrayIn, int Size, char CharacterToFind, bool CaseSensitive = false)
{
	char* temp = ArrayIn;
	for (int i = 0; i < Size; i++)
	{
		if (ArrayIn[i] == CharacterToFind)
		{
			*temp = ArrayIn[i];
		}
	}

	if (temp == nullptr) return nullptr;
	return temp;
}

int main()
{
	int NumberArr[] = { 5, 2, 4, 5 };
	int* PointertoNumberA = NumberArr;
	char CharacterArr[6] = { 'a', 'b' , 'c' , 'd' , 'e' ,'f' };


	//prints out memory adress with out the star
	cout << SumofIntArr(NumberArr, 4) << endl;
	cout << FindInArray(CharacterArr, 6, 'c') << endl;

	return 0;
}