#include "Exercises.h"
#include <iostream>

int * ZeroArray(size_t OutSize)
{
	int * arr = new int[OutSize];
	for (int i = 0; i < OutSize; i++)
	{
		arr[i] = 0;
	}

	int* OutPointer = arr;
	delete[] arr;

	return OutPointer;
}

char* CharSearch(const char TheCharacter, char* CharacterArray, bool CaseSensitive)
{
	int* ArraySize = new int[strlen(CharacterArray)];
	if (CaseSensitive = true)
	{
		for (int i = 0; i < *ArraySize; i++)
		{
			//check possition of character array
			//is TheCharacter
			//return pointer to position in character array of the charcter
			//else return nullptr;
		}
	}
	else
	{
	
	}
	delete[] ArraySize;
	return nullptr;
}