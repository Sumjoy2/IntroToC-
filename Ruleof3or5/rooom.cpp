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

	Data = new char[WidthSize * HeightSize];

	for (int i = 0; i < Height * Width; i++)
	{
		Data[i] = '*';
	}
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
	Data = new char[WidthSize * HeightSize];
	//DEBUG
	for (int i = 0; i < Height * Width; i++)
	{
		Data[i] = '*';
	}
}

Rooom::Rooom(const char* Template)
{

}

//deconstructor
Rooom::~Rooom()
{
	delete[] Name;
	delete[] Data;
}

Rooom::Rooom(const Rooom& Other)
{
	size_t NameLength = strlen(Other.Name);
	Name = new char[NameLength];
	strcpy_s(Name, NameLength + 1, Other.Name);

	Data = new char[strlen(Other.Data)];
	strcpy_s(Data, strlen(Other.Data), Other.Data);
}

Rooom& Rooom::operator=(const Rooom& Other)
{
	// TODO: insert return statement here
	strcpy_s(Name, strlen(Other.Name) + 1, Other.Name);
	strcpy_s(Data, strlen(Other.Data), Other.Data);
	return *this;
}

//Prints room to screen using cout
void Rooom::Print()
{
//#pragma region RoomHeightLoop
//	//loops through room height
//	for (int h = 0; h < HeightSize - 1; h++)
//	{
//		//if room height is 0 loops through width and prints all 'x'
//		if (h == 0)
//		{
//			for (int w = 0; w < WidthSize; w++)
//			{
//				//is the width even or odd
//				if (WidthSize % 2 == 0)
//				{
//					//prints @@ in the middle
//					if (WidthSize / 2 == w || (WidthSize / 2) - 1 == w)
//					{
//						cout << "@";
//					}
//					else cout << "X";
//				}
//				else
//				{
//					//prints 3 @@@ symbols in the middle
//					if (WidthSize / 2 == w || (WidthSize / 2) - 1 == w || (WidthSize / 2) + 1 == w)
//					{
//						cout << "@";
//					}
//					else cout << "X";
//				}
//			}
//		}
//		//SideDoors
//		else if (HeightSize / 2 == h)
//		{
//			cout << endl;
//			for (int w = 0; w < WidthSize; w++)
//			{
//				//if the width is 0 it prints an @ door
//				if (w == 0) cout << "@";
//				//if width is max it prints an x wall
//				else if (w == WidthSize - 1) cout << "@";
//				//prints out a space
//				else cout << " ";
//			}
//		}
//		//goes to the next part of the room
//		else
//		{
//			cout << endl;
//			//loops through width
//			for (int w = 0; w < WidthSize; w++)
//			{
//				//if the width is 0 it prints an x wall
//				if (w == 0) cout << "X";
//				//if width is max it prints an x wall
//				else if (w == WidthSize - 1) cout << "X";
//				//prints out a space
//				else cout << " ";
//			}
//		}
//
//
//	}
//#pragma endregion
//
//#pragma region BottomOfRoom
//	//one last next line
//	cout << endl;
//	//prints out bottom of room
//	for (int w = 0; w < WidthSize; w++)
//	{
//		//is the width even or odd
//		if (WidthSize % 2 == 0)
//		{
//			//prints @@ in the middle
//			if (WidthSize / 2 == w || (WidthSize / 2) - 1 == w)
//			{
//				cout << "@";
//			}
//			else cout << "X";
//		}
//		else
//		{
//			//prints 3 @@@ symbols in the middle
//			if (WidthSize / 2 == w || (WidthSize / 2) - 1 == w || (WidthSize / 2) + 1 == w)
//			{
//				cout << "@";
//			}
//			else cout << "X";
//		}
//	}
//#pragma endregion

	//TerryCode Single Array and if i is end of width
	//Just prints out the data doesnt make data
	size_t Dimension = WidthSize * HeightSize;
	for (size_t i = 0; i < Dimension; i++)
	{
		cout << Data[i];
		if ((i +1) % WidthSize == 0)
		{
			cout << endl;
		}
	}
}
