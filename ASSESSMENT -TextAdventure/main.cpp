#include <iostream>
#include <fstream>
#include <ctime>


int main()
{
	//Setting up being able to use time
	time_t currTime = std::time(nullptr);
	struct tm timeTM;
	localtime_s(&timeTM, &currTime);

}