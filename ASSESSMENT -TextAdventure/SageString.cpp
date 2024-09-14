#include "SageString.h"
#include <iostream>
#include <cassert>

#pragma region ConstructDeconstruct
String::String()
{
	TheString = new char[StringSize];
	TheString[0] = ' ';
	TheString[1] = '\0';
}

String::String(const char* str)
{
	//making sure the string is big enough to hold the null terminating character
	StringSize = strlen(str) + 1;
	TheString = new char[StringSize];
	strcpy_s(TheString, StringSize, str);
}

String::String(const String& other)
{
	StringSize = other.StringSize;
	TheString = new char[StringSize];
	strcpy_s(TheString, other.StringSize, other.TheString);
}

String::~String()
{
	delete[] TheString;
}
#pragma endregion

size_t String::Length() const
{
	return size_t(StringSize - 1);
}

#pragma region Console Read/Write
void String::WriteToConsole()
{
	for (int i = 0; i < StringSize; i++)
	{
		std::cout << TheString[i];
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

#pragma region CharacterAt
char& String::CharacterAt(size_t Index)
{
	return TheString[Index];
}

const char& String::CharacterAt(size_t Index) const
{
	return TheString[Index];
}
#pragma endregion

bool String::Equals(const String& Other) const
{
	if (strcmp(TheString, Other.TheString) == 0)
		return true;
	return false;
}

#pragma region Appending
String& String::Append(const String& Str)
{
	String TheStringCopy(TheString);
	//gives Temo the lenght of its current String without the null character
	int Temo = Length();
	//Sets the string size to Current size without null and incoming string size with null character
	StringSize = Temo + Str.StringSize;
	//Reset the Current String
	TheString = new char[StringSize];

	//Loops through the old string size and copies the old string over
	for (int i = 0; i < Temo; i++)
	{
		if (TheStringCopy.TheString[i] == '\0')
			break;
		assert(i < StringSize);
		TheString[i] = TheStringCopy.TheString[i];
	}

	//Loops through TheString position + Old string length and copies old string to spots including the null character
	for (int i = 0; i < StringSize - Temo; i++)
	{
		assert(Temo + i < StringSize);
		TheString[Temo + i] = Str.TheString[i];
	}

	return *this; //temp return so program doesnt yell
}

String& String::Prepend(const String& Str)
{
	String TheStringCopy(TheString);
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
	for (int i = 0; i < StringSize - Temo ; i++)
	{
		assert(Temo + i < StringSize);
		TheString[Temo + i] = TheStringCopy.TheString[i];
	}
	return *this; //temp return so program doesnt yell
}
#pragma endregion

const char* String::CStr() const
{
	return TheString;
}

#pragma region Upper/Lower
String String::ToLower() const
{
	//Copies the string into string copy to return
	String TheStringCopy(TheString);
	for (int i = 0; i < StringSize; i++)
	{
		//Check if its null terminating character then leaves loop
		if (TheStringCopy.TheString[i] == '\0')
		{
			break;
		}
		//checks if current position in the string is a space then continues loop from top
		else if (TheStringCopy.TheString[i] == ' ') continue;
		//Checking if current thing in the string is actually a upletter then changes it to lower
		else if (65 <= TheStringCopy.TheString[i] && TheStringCopy.TheString[i] <= 90)
		{
			assert(i < StringSize);
			TheStringCopy.TheString[i] = TheStringCopy.TheString[i] + 32;
		}
	}
	//Returns the now lowercase string copy
	return TheStringCopy.TheString;
}

//Makes all of the letters in the string Capitals
String String::ToUpper() const
{
	//Copies the string into string copy to return
	String TheStringCopy(TheString);

	for (int i = 0; i < StringSize; i++)
	{
		//Check if its null terminating character then leaves loop
		if (TheStringCopy.TheString[i] == '\0')
		{
			break;
		}
		//checks if current position in the string is a space then continues loop from top
		else if (TheStringCopy.TheString[i] == ' ') continue;
		//Checking if current thing in the string is actually a lowletter then changes it to capital
		else if (97 <= TheStringCopy.TheString[i] && TheStringCopy.TheString[i] <= 122)
		{
			TheStringCopy.TheString[i] = TheStringCopy.TheString[i] - 32;
		}
	}

	//Returns the now capital string copy
	return TheStringCopy.TheString;
}
#pragma endregion

#pragma region Find/Replace
int String::Find(const String& Str, size_t StartIndex, bool IsCaseSensitive) const
{
	String TheStringCopy(TheString);
	//String to finds length
	size_t TempLenght = Str.Length();
	
	//checks for if what im finding should not be case sensitive 
	if (!IsCaseSensitive)
	{
		//Makes the External String copy lowercase
		String LoweredExternal = Str.ToLower();
		//makes the string copy lowercase
		String Lower = ToLower();

		//Loops through StringCopy starting at StartIndex up to StringSize minus the null character
		for (int si = StartIndex; si < StringSize - 1; si++)
		{
			int TempCounter = 0;
			//Loops through External String
			for (int ei = 0; ei < TempLenght; ei++)
			{
				if (Lower.TheString[si + ei] == LoweredExternal.TheString[ei])
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
	}

	//Loops through TheString starting at StartIndex up to StringSize minus the null character
	for (int si = StartIndex; si < StringSize - 1; si++)
	{
		int TempCounter = 0;
		//Loops through External String
		for (int ei = 0; ei < TempLenght; ei++)
		{
			if (TheString[si + ei] == Str.TheString[ei])
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

	//returns -1 if the string to find isnt found
	return -1;
}

String& String::Replace(const String& Find, const String& Replace, bool ReplaceAll)
{
	//The Index of what to find
	int FindIndex = this->Find(Find);
	//Returns current version of itself if Find doesnt find anything
	if (FindIndex == -1)
	{
		return *this;
	}

	//The Length of replacement string
	int RTemp = Replace.Length();
	
	//Checks if it should replace it all
	if(ReplaceAll == true)
	{
		while (FindIndex != -1)
		{
			//Checks if replacement is longer than word looking for
			if (RTemp > Find.Length())
			{
				String TheCopy(TheString);
				StringSize += RTemp;
				TheString = new char[StringSize];
				strcpy_s(TheString, StringSize, TheCopy.TheString);
			}
			//Loops through starting from FindIndex up to Replacement string length
			for (int i = 0; i < RTemp; i++)
			{
				TheString[i + FindIndex] = Replace.TheString[i];
			}
			//updates FindIndex
			FindIndex = this->Find(Find, FindIndex + RTemp);
		}
	}
	else
	{
		//Checks if replacement is longer than word looking for
		if (RTemp > Find.Length())
		{
			String TheCopy(TheString);
			StringSize += RTemp;
			TheString = new char[StringSize];
			strcpy_s(TheString, StringSize, TheCopy.TheString);
		}
		//Loops through starting from FindIndex up to Replacement string length
		for (int i = 0; i < RTemp; i++)
		{
			TheString[i + FindIndex] = Replace.TheString[i];
		}
	}
	return *this;
}

String String::Substring(const String& StringToFind)
{
	String TheSub(StringToFind);
	int StartLocal = this->Find(StringToFind);
	if (StartLocal == -1)
	{
		return *this;
	}

	int EndLocal = StringToFind.Length();
	for (int i = StartLocal; i < EndLocal; i++)
	{
		TheSub.TheString[i - StartLocal] = TheString[i];
	}
	return TheSub;
}
#pragma endregion

#pragma region OperatorChanging
String String::operator+(const String& Other) const
{
	String NewClass = {TheString};
	NewClass.Append(Other);
	return NewClass;
}

String& String::operator+=(const String& Other)
{
	this->Append(Other);
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

	return *this;
}

char& String::operator[](size_t Index)
{
	return this->TheString[Index];
}

const char& String::operator[](size_t Index) const
{
	return this->TheString[Index];
}

std::ostream& operator<<(std::ostream& Stream, const String& Str)
{
	return Stream << Str.CStr();

}
#pragma endregion