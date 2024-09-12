#include "SageString.h"
#include <cassert>
//#include <iostream>

int main()
{
	String TestString("Pineapples are really are good!!");
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

	TestString.Replace("are", "HAHA", true);
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
	String TestString3 = TestString + TestString2;


	std::cout << TestString;

	return 0;
}