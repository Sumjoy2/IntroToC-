#include "Utils.h"

#pragma region Clamp
int Clamp(int Lowest, int Highest, int InNumber)
{
	if (InNumber < Lowest)
		return Lowest;
	else if (InNumber > Highest)
		return Highest;
	return InNumber;
}

float Clamp(float Lowest, float Highest, float InNumber)
{
	if (InNumber < Lowest)
		return Lowest;
	else if (InNumber > Highest)
		return Highest;
	else
		return InNumber;
}
#pragma endregion