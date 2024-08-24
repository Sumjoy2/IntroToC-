#include <iostream>
#include "LeHeader.h"

int main()
{
	char Test[255];
	std::cout << "Enter a string: " << std::endl;
	std::cin >> Test;

	//Welcome();
	//ToCapital();
	//StringLength();
	//NoSpace();
	char InputA[] = "It was a very good day!";
	//// Empty c-string to overwrite
	char Dest[255] = "";
	//// Copy a substring of InputA into Dest
	Substring(InputA, 9, 17, Dest);
	//StringReverse(Test);
	//Palindrome(Test);
	

	return 0;
}