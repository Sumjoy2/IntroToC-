#include "rooom.h"
#include <iostream>

using std::cout;
using std::endl;

Rooom::Rooom()
{

}
/*
* Sets up the width and height of the room to be empty
*/
Rooom::Rooom(size_t Width, size_t Height)
{
	/*
	* Sets up the width and height of the room to be empty
	*/;
	WidthSize = Width;
	HeightSize = Height;
}

Rooom::Rooom(size_t Width, size_t Height,const char* RoomName)
{
	/*
	* Gives room a name
	*/
	size_t NameLength = strlen(RoomName);
	//Have space because name is a nullptr
	Name = new char[NameLength + 1];
	//Copies RoomName into name
	strcpy_s(Name, NameLength + 1, RoomName);

	/*
	* Sets up the width and height of the room to be empty
	*/
	WidthSize = Width;
	HeightSize = Height;
}

Rooom::~Rooom()
{
	delete[] Name;
}


void Rooom::Print()
{
	//loops through room height
	for (int h = 0; h < HeightSize - 1; h++)
	{
		//if room height is 0 loops through width and prints all 'x'
		if (h == 0)
		{
			for (int w = 0; w <= WidthSize; w++)
			{
				//if widthsize / 2 == 0 print out the @ and continues the loop
				cout << "X";
			}
		}
		//if room height is max height loops through width and prints all 'x'
		else if (h == HeightSize)
		{
			for (int w = 0; w <= WidthSize; w++)
			{
				cout << "X";
			}
		}
		//goes to the next part of the room
		cout << endl;
		//loops through width
		for (int w = 0; w < WidthSize; w++)
		{
			//if the width is 0 it prints an x wall
			if (w == 0) cout << "X";
			//if width is max it prints an x wall
			else if (w == WidthSize - 1) cout << "X";
			//prints out a space
			else cout << " ";
		}
	}

	//one last next line
	cout << endl;
	//prints out bottom of room
	for (int w = 0; w <= WidthSize; w++)
	{
		cout << "X";
	}
}
