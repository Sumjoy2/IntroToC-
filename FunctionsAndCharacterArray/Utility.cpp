#include "HeaderTest.h"
#include <iostream>


float FindValue(float Numbers[], size_t Count, float Value, int Start)
{
	for (int i = Start; i < Count; i++)
	{
		if (Numbers[i] == Value)
		{
			return i;
		}
	}
	return -1;
}

void PrintArray(float Numbers[], size_t Count)
{
	for (int i = 0; i < Count; i++)
	{
		std::cout << Numbers[i] << " ";
	}
}

void PairPrinting(float a, float b)
{
	std::cout << a << ", " << b << std::endl;
}

void ReverseArray(float Numbers[], size_t End)
{
	int Countdown = End - 1;
	for (int i = 0; i != End / 2; i++)
	{
		float temp = Numbers[i];
		Numbers[i] = Numbers[Countdown];
		Numbers[Countdown] = temp;
		Countdown--;
	}
	PrintArray(Numbers, End);
}