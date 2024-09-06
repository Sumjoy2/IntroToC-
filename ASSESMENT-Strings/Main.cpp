#include "SageString.h"
#include <iostream>

int main()
{
	const String TestString("Pineapples are really good!! ");

	//std::cout << TestString.Length() << std::endl;
	//TestString.WriteString();
	//std::cout << std::endl;
	//TestString.ToUpper();
	//TestString.WriteString(true);
	//std::cout << std::endl;
	//TestString.ToLower();
	//TestString.WriteString(true);
	//std::cout << std::endl;
	
	//With this test case should return 11
	std::cout << TestString.Find("are") << std::endl;

	return 0;
}