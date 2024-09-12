#include "SageString.h"
#include <iostream>

int main()
{
	String TestString("Pineapples are really good!! ");
	String TestString2("WHOOOOO ");

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
	int test = TestString.Find("are");

	//TestString + TestString2;

	//TestString.Append(TestString2);
	//TestString.Prepend(TestString2);
	//TestString.WriteString();
	//std::cout << std::endl;

	//TheTestCase
	//TestString.CStr << std::endl;
	// 
	//TestString.ReadFromConsole();
	//TestString.WriteString(); 
	//TestString = TestString2;
	//TestString.WriteString(); 
	
	return 0;
}