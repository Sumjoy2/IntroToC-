#include "SageString.h"
#include <cassert>
#include <fstream>
#include <ctime>
#include <sstream>

using std::ofstream;
using std::cout;
using std::endl;

int main()
{
	time_t currTime = std::time(nullptr);
	struct tm timeTM;
	localtime_s(&timeTM, &currTime);

	ofstream TestFile;
	String EmptyString;
	String TestString("Pineapples are really are good!!");
	String TestString2("WHOOOOO ");
	size_t TestLength = TestString.Length();

	std::stringstream StreamTest;
	StreamTest << "WHOOOOO ";
	String TestStringStream = StreamTest.str().c_str();

	TestFile.open("TestResults.txt", std::ios::app | std::ios::out);

	if (TestFile.is_open() == false)
	{
		cout << "File not found" << endl;
		return -1;
	}

	TestFile << endl << "String Tests\t" << timeTM.tm_year + 1900 << '-' << timeTM.tm_mon + 1 << '-' << timeTM.tm_mday << ' ' << timeTM.tm_hour << ':';
	if (timeTM.tm_min < 10)
		TestFile << '0' << timeTM.tm_min << endl;
	
	TestFile << timeTM.tm_min << endl;

	if (TestStringStream == TestString2.CStr())
		TestFile << "Ostream: Success" << endl;
	else 
		TestFile << "Ostream: Fail" << endl;
	if (TestString.Length() > 0)
		TestFile << "Length: Success" << endl;
	TestString.Prepend(TestString2);
	if (TestLength < TestString.Length())
		TestFile << "Prepend: Success" << endl;
	TestString.Append(TestString2);
	if (TestLength < TestString.Length())
		TestFile << "Append: Success" << endl;
	String LowString = TestString.ToLower();
	if (TestString != LowString)
		TestFile << "ToLower: Success" << endl;
	String UpString = TestString.ToUpper();
	if (TestString != UpString)
		TestFile << "ToUpper: Success" << endl;
	if (TestString.Equals(TestString.CStr()))
		TestFile << "EqualsFunc: Success" << endl
		<< "Cstr: Success" << endl;
	String ConsoleString;
	ConsoleString.ReadFromConsole();
	ConsoleString.WriteToConsole();
	if (ConsoleString != EmptyString)
		TestFile << "ReadFromConsole: Success" << endl
		<< "WriteToConsole: Success" << endl;
	if (TestString.CharacterAt(0) == 'P')
		TestFile << "CharacterAt: Success" << endl;
	if (TestString.Find("are") == 11)
		TestFile << "Find: Success" << endl;
	TestString.Replace("and", "nah", true);
	if (TestString.Find("are") == -1)
		TestFile << "Replace: Success" << endl;
	String TestString3 = TestString + TestString2;
	size_t ThreeLength = TestString3.Length();
	if (ThreeLength < TestString.Length())
		TestFile << "Equals: Success" << endl
		<< "Addition: Success" << endl;
	if (TestString3 == TestString + TestString2)
		TestFile << "EqualEqual: Success" << endl;
	ThreeLength = TestString3.Length();
	TestString3 += TestString2;
	if (ThreeLength < TestString.Length())
		TestFile << "AdditionEqual: Success" << endl;
	if (TestString != TestString2)
		TestFile << "NotEqual: Success" << endl;
	String SubString = TestString.Substring("Really");
	if (SubString == "Really")
		TestFile << "Substring: Success" << endl;
	else
		TestFile << "Substring: Fail" << endl;

	TestFile.close();
	return 0;
}