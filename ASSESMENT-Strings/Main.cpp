#include "SageString.h"
#include <iostream>

int main()
{
	String TestString("Pineapples are really good. ");

	std::cout << TestString.Length() << std::endl;
	TestString.WriteString();
	std::cout << std::endl;

	return 0;
}