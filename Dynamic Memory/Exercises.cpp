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
	if (CaseSensitive = true)
	{
		for (int i = 0; i < strlen(CharacterArray) -1; i++)
		{
			//check possition of character array
			if (CharacterArray[i] == TheCharacter)
			{
				return &CharacterArray[i];
			}
		}
	}
	for (int i = 0; i < strlen(CharacterArray); i++)
	{
		//check possition of character array
		if (CharacterArray[i] == TheCharacter)
		{
			return &CharacterArray[i];
		}
		else if (CharacterArray[i] == TheCharacter + 32)
		{
			return &CharacterArray[i];
		}
		else if (CharacterArray[i] == TheCharacter - 32)
		{
			return &CharacterArray[i];
		}
	}
	return nullptr;
}

void NumberLover()
{
	int UserNumber = -1;
	std::cout << "How Many Numbers Do You Have? \n > ";
	std::cin >> UserNumber;
	int* Numebr = new int(UserNumber);
	int* UserNumbArr = new int[UserNumber];
	for (int i = 0; i < *Numebr; i++)
	{
		std::cout << "What Is Number " << i + 1 << "?\n > ";
		std::cin >> UserNumber;
		UserNumbArr[i] = UserNumber;
	}
	std::cout << "You Inputed: ";
	for (int i = 0; i < UserNumber; i++)
	{
		std::cout << UserNumbArr[i] << ", ";
	}
	
	std::cout <<std::endl;
	delete[] UserNumbArr;
	delete Numebr;
}

// Returns a pointer to a dynamic integer array that is a copy of the provided array
//  - origArray refers to the array to be copied
//  - size refers to the size of the original array to copy
int* DuplicateArray(int* origArray, size_t size)
{	
	int* PointedArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		PointedArr[i] = origArray[i];
	}
	return PointedArr;
}

void IntSubArrCopy(int* InArray, int StartLocal, int EndLocal, int* OutArray)
{
	for (int i = StartLocal; i <= EndLocal; i++)
	{
		OutArray[i - StartLocal] = InArray[i];
	}
}