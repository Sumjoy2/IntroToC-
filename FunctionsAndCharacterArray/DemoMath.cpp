#include "HeaderTest.h"
#include <iostream>
#include <cmath>

float Clamp(float Lowest, float Highest, float Number)
{
	if (Number < Lowest)
	{
		std::cout << Lowest << std::endl; return Lowest;
	}
	else if (Number > Highest)
	{
		std::cout << Highest << std::endl; return Highest;
	}
	else std::cout << Number << std::endl; return Number;
}

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

//adds 2 floats
float Sum(float a, float b)
{
	return a + b;
}

float Sum(float a, float b, float c)
{
	return a + b + c;
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

float Distance(float x1, float y1, float x2, float y2)
{
	float tempX = x1 - x2;
	float tempY = y1 - y2;
	return abs(sqrt((tempX * tempX) + (tempY * tempY)));
}