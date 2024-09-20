#pragma once
class Item;
class Food;
class Tool;
class Door;

class Room
{
private:
	//the name of the room
	String RoomName = " ";
	//Description of the room
	String RoomDesc = " ";
	//Item in the room
	Item HeldItem;
	Item EmptyItem;

	Room* ConnectedRoom = nullptr;
	Room* ConnectedRoom2 = nullptr;
	Room* PrevRoom = nullptr;

public:
	bool ItemThere = false;
	bool IsWater = false;

	//Default Constructor
	Room();
	//Construct a Room with a new Id and desc. Optionally how many connections the room has
	Room(String NewName, String NewDesc, bool Water = false);

	//Construct a Room with a new Id and desc and an item. Optionally how many connections the room has
	Room(String NewName, String NewDesc, Item *NewItem, Item *NewItem2, bool Water = false);
	~Room();

	/*
	* @brief updates all connected rooms to the inputs
	* @param Pointer to the first new room
	* @param Pointer to the Second new room
	* @param Pointer to the previous room
	*/
	void ConnectedRoomUpdate(Room* NewRoom1, Room* NewRoom2 = nullptr, Room* PrevoiusRoom = nullptr);

	/*
	* @brief prints to the screen the items in the room
	*/
	void PrintRoomItems();

	/*
	* @brief returns the item and essentially removes it
	* @return current room item or the empty item if ItemThere is false
	*/
	Item TakeItem();

	void PrintConnections();

	/*
	* @brief gives the room name
	* @return RoomName
	*/
	String CurrentRoom();

	/*
	* @brief gives the rooms description
	* @return RoomDesc
	*/
	String CurrentDesc();

	Room* ConnRoomOne();
	Room* ConnRoomTwo();
	Room* ConnRoomPrev();
};