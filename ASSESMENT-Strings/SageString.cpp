#include "SageString.h"
#include <iostream>

String::String()
{
	TheString = new char[StringSize];
	StringCopy = new char[StringSize];
	TheString[0] = ' ';
	TheString[1] = 00;
	strcpy_s(StringCopy, StringSize, StringCopy);
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

size_t String::Length() const
{
	return size_t(StringSize - 1);
}

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

String& String::Append(const String& Str)
{
	// TODO: insert return statement here
	StringSize = StringSize + (Str.StringSize - 1);
	TheString = new char[StringSize];
	/*TheString = */
	return *this;
}


//Makes all of the letters in the string lowercase
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

bool String::operator==(const String& Other) const
{
	if (strcmp(TheString, Other.TheString))
	{
		return true;
	}
	return false;
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
