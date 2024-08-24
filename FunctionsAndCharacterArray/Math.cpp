#include <iostream>
#include "HeaderTest.h"
#include <cmath>

using std::cout;
using std::endl;


//adds 2 floats
float Sum(float a, float b)
{
	return a + b;
}

float Sum(float a, float b, float c)
{
	return a + b + c;
}

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

int Min(int a, int b)
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

double Min(double a, int b)
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


//Pythagorean Theorem C^2 = A^2 + B^2. Needs Square root to get rid of the power of 2
float Distance(float x1, float y1, float x2, float y2)
{
	float tempX = x2 - x1;
	float tempY = y2 - y1;
	return abs(sqrt((tempX * tempX) + (tempY * tempY)));
}