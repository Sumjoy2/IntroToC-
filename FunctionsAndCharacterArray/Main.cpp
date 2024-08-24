#include <iostream>
#include "HeaderTest.h"

using std::cout;
using std::endl;

int main()
{
	const int NumbsSize = 5;
	float numbs[NumbsSize] = { 56, 29, 3, 6, 215 };
	cout << Sum(3.2f, 0.0f, 3.0f) << endl;
	PrintArray(numbs, NumbsSize);
	PairPrinting(4, 3);
	Min(3, 8);
	MinArray(numbs, NumbsSize);
	Max(7, 299);
	MaxArray(numbs, NumbsSize);
	Clamp(15, 200,56);
	cout << FindValue(numbs, NumbsSize, 3, 0) << endl;
	ReverseArray(numbs, NumbsSize);
	cout << endl << Distance(3, 3, 4, 5);

	return 0;
}