#include "SageString.h"
#include <iostream>

String::String()
{
	TheString = new char[StringSize];
	TheString[0] = ' ';
	TheString[1] = 00;
}

//Basic way using string copy built into iostream
//I could end up doing each one individually
String::String(const char* str)
{
	//making sure the string is big enough to hold the null terminating character
	StringSize = strlen(str) + 1;
	TheString = new char[StringSize];
	strcpy_s(TheString, StringSize, str);
}

String::~String()
{
	delete[] TheString;
}

size_t String::Length() const
{
	return size_t(StringSize - 1);
}

void String::WriteString()
{
	for (int i = 0; i < StringSize; i++)
	{
		std::cout << TheString[i];
	}
}

char& String::CharacterAt(size_t Index)
{
	// TODO: insert return statement here
	return TheString[Index];
}
