// Room.h
#pragma once

class Rooom
{
private:
	// TODO for YOU: How can we store the level?

	char* Name = nullptr;
	size_t WidthSize = 0;
	size_t HeightSize = 0;

public:
	// Default constructor
	Rooom();
	// Should set up the entire room to be empty
	Rooom(size_t Width, size_t Height);
	// Should set up the entire room to be empty and gives room a name
	Rooom(size_t Width, size_t Height, const char* RoomName);
	// Parameterized constructor
	// Should build a room by copying the data from this array
	Rooom(const char* Template);
	// Destrutor
	// Should clean up the data allocated dynamically
	~Rooom();

	void Print();

	// TODO for YOU: What functions should the Room provide to access parts
	// of the room?
};