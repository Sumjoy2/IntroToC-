#include "SageString.h"
#include <iostream>

#pragma region ConstructDeconstruct
String::String()
{
	TheString = new char[StringSize];
	StringCopy = new char[StringSize];
	TheString[0] = ' ';
	TheString[1] = 00;
	strcpy_s(StringCopy, StringSize, TheString);
}

//Basic way using string copy built into iostream
//I could end up doing each one individually
String::String(const char* str)
{
	//making sure the string is big enough to hold the null terminating character
	StringSize = strlen(str) + 1;
	TheString = new char[StringSize];
	StringCopy = new char[StringSize];
	strcpy_s(TheString, StringSize, str);
	strcpy_s(StringCopy, StringSize, TheString);
}

String::String(const String& other)
{
	StringSize = other.StringSize;
	TheString = new char[StringSize];
	StringCopy = new char[StringSize];
	strcpy_s(TheString, other.StringSize, other.TheString);
	strcpy_s(StringCopy, other.StringSize, other.StringCopy);
}

String::~String()
{
	delete[] TheString;
	delete[] StringCopy;
}
#pragma endregion

size_t String::Length() const
{
	return size_t(StringSize - 1);
}

#pragma region Console Read/Write
void String::WriteString(bool IsCopy)
{
	for (int i = 0; i < StringSize; i++)
	{
		if (IsCopy == true)
		{
			std::cout << StringCopy[i];
		}
		else
		{
			std::cout << TheString[i];
		}
	}
}

void String::ReadFromConsole()
{
	std::cout << "Please input a string\n > ";
	char UserInput[255] = {};
	std::cin.getline(UserInput, 255);
	StringSize = strlen(UserInput) + 1;

	TheString = new char[StringSize];

	for (int i = 0; i < StringSize; i++)
	{
		TheString[i] = UserInput[i];
	}
}
#pragma endregion

char& String::CharacterAt(size_t Index)
{
	return TheString[Index];
}

const char& String::CharacterAt(size_t Index) const
{
	return TheString[Index];
}

bool String::Equals(const String& Other) const
{
	if (strcmp(TheString, Other.TheString) == 0)
		return true;
	return false;
}

#pragma region Appending
String& String::Append(const String& Str)
{
	//gives Temo the lenght of its current String without the null character
	int Temo = Length();
	//Sets the string size to Current size without null and incoming string size with null character
	StringSize = Temo + Str.StringSize;
	//Reset the Current String
	TheString = new char[StringSize];

	//Loops through the old string size and copies the old string over
	for (int i = 0; i < Temo; i++)
	{
		if (StringCopy[i] == '\0') 
			break;
		TheString[i] = StringCopy[i];
	}

	//Loops through TheString position + Old string length and copies old string to spots including the null character
	for (int i = 0; i < StringSize; i++)
	{
		TheString[Temo + i] = Str.TheString[i];
	}

	return *this; //temp return so program doesnt yell
}


String& String::Prepend(const String& Str)
{
	//gives Temo the lenght of its Input String without the null character
	int Temo = Str.Length();
	//Sets the string size to Input String size without null and Current string size with null character
	StringSize = Temo + StringSize;
	//Reset the Current String
	TheString = new char[StringSize];

	//Loops through the Input string size and copies Input string over to TheString
	for (int i = 0; i < Temo; i++)
	{
		TheString[i] = Str.TheString[i];
	}

	//Loops through TheString position + Input string length and copies old string to spots including the null character
	for (int i = 0; i < StringSize; i++)
	{
		TheString[Temo + i] = StringCopy[i];
	}

	return *this; //temp return so program doesnt yell
}
#pragma endregion

#pragma region UpperLower
String String::ToLower() const
{
	//Copies the string into string copy to return
	strcpy_s(StringCopy, StringSize, TheString);
	for (int i = 0; i < StringSize; i++)
	{
		//Check if its null terminating character then leaves loop
		if (StringCopy[i] == '\0')
		{
			break;
		}
		//checks if current position in the string is a space then continues loop from top
		else if (StringCopy[i] == ' ') continue;
		//Checking if current thing in the string is actually a upletter then changes it to lower
		else if (65 <= StringCopy[i] && StringCopy[i] <= 90)
		{
			StringCopy[i] = StringCopy[i] + 32;
		}
	}
	//Returns the now lowercase string copy
	return StringCopy;
}

//Makes all of the letters in the string Capitals
String String::ToUpper() const
{
	//Copies the string into string copy to return
	strcpy_s(StringCopy, StringSize, TheString);

	for (int i = 0; i < StringSize; i++)
	{
		//Check if its null terminating character then leaves loop
		if (StringCopy[i] == '\0')
		{
			break;
		}
		//checks if current position in the string is a space then continues loop from top
		else if (StringCopy[i] == ' ') continue;
		//Checking if current thing in the string is actually a lowletter then changes it to capital
		else if (97 <= StringCopy[i] && StringCopy[i] <= 122)
		{
			StringCopy[i] = StringCopy[i] - 32;
		}
	}

	//Returns the now capital string copy
	return StringCopy;
}
#pragma endregion

//TODO FIX THIS. It is something to do with needing to set temp counter to 0
int String::Find(const String& Str, size_t StartIndex, bool IsCaseSensitive) const
{
	size_t TempLenght = Str.Length();
	int TempCounter = 0;
	//Loops through TheString starting at StartIndex
	if (!IsCaseSensitive)
	{
		//Makes the External String copy lowercase
		Str.ToLower();
		//makes the string copy lowercase
		ToLower();
	}

	for (int si = StartIndex; si < StringSize - 1; si++)
	{
		if (StringCopy[si] == '\0') break;
		//Loops through External String
		for (int ei = 0; ei < TempLenght; ei++)
		{
			if (StringCopy[si] == Str.StringCopy[ei])
			{
				TempCounter++;
			}
		}
		//does temp counter number equal the length of External String
		if (TempCounter == TempLenght)
		{
			return si;
		}
	}

	return -1;
}

#pragma region OperatorChanging
String String::operator+(const String& Other) const
{
	String NewClass = {TheString};
	NewClass.Append(Other);
	return String();
}

String& String::operator+=(const String& Other)
{
	//gives Temo the lenght of its current String without the null character
	int Temo = Length();
	//Sets the string size to Current size without null and incoming string size with null character
	StringSize = Temo + Other.StringSize;
	//Reset the Current String
	TheString = new char[StringSize];

	//Loops through the old string size and copies the old string over
	for (int i = 0; i < Temo; i++)
	{
		if (StringCopy[i] == '\0')
			break;
		TheString[i] = StringCopy[i];
	}

	//Loops through TheString position + Old string length and copies old string to spots including the null character
	for (int i = 0; i < StringSize; i++)
	{
		TheString[Temo + i] = Other.TheString[i];
	}
	
	return *this;
}

bool String::operator==(const String& Other) const
{
	if (strcmp(TheString, Other.TheString) == 0)
	{
		return true;
	}
	return false;
}

bool String::operator!=(const String& Other) const
{
	if (strcmp(TheString, Other.TheString) != 0)
	{
		return true;
	}
	return false;
}

String& String::operator=(const String& Str)
{
	//Sets the String size to the Input string length + 1 for the null character
	StringSize = Str.Length() +1;
	//Reset the Current String
	TheString = new char[StringSize];

	for (int i = 0; i < StringSize; i++)
	{
		TheString[i] = Str.TheString[i];
	}

	strcpy_s(StringCopy, StringSize, TheString);
	return *this;
}

char& String::operator[](size_t Index)
{
	// TODO: insert return statement here
	return this->TheString[Index];
}

const char& String::operator[](size_t Index) const
{
	// TODO: insert return statement here
	return this->TheString[Index];
}

#pragma endregion