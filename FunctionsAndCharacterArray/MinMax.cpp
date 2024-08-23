#include <iostream>
#include "HeaderTest.h"

using std::cout;
using std::endl;

float Min(float a, float b)
{
	if (a < b)
	{
		std::cout << a << std::endl; return a;
	}
	else
	{
		std::cout << b << std::endl; return b;
	}
}

float Max(float a, float b)
{
	if (a > b)
	{
		std::cout << a << std::endl; return a;
	}
	else
	{
		std::cout << b << std::endl; return b;
	}
}

void MinArray(float Numbers[], size_t Count)
{
	int Lowest = 900;
	for (int i = 0; i < Count; i++)
	{
		if (Numbers[i] <= Lowest)
		{
			Lowest = Numbers[i];
		}
	}
	std::cout << Lowest << std::endl;
}

void MaxArray(float Numbers[], size_t Count)
{
	int Highest = -1;
	for (int i = 0; i < Count; i++)
	{
		if (Numbers[i] >= Highest)
		{
			Highest = Numbers[i];
		}
	}
	std::cout << Highest << std::endl;
}