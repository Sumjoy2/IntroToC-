#include <iostream>
#include "SageString.h"
#include "Item.h"
#include "Room.h"

using std::cout;
using std::cin;
using std::endl;

Room::Room()
{
	RoomName = " ";
	RoomDesc = " ";
	EmptyItem = nullptr;
	HeldItem = nullptr;
}

Room::Room(String NewName, String NewDesc, bool Water)
{
	RoomName = NewName;
	RoomDesc = NewDesc;
	ItemThere = false;
	EmptyItem = nullptr;
	HeldItem = nullptr;
	IsWater = Water;
}

Room::Room(String NewName, String NewDesc, Item* NewItem, Item* NewItem2, bool Water)
{
	RoomName = NewName;
	RoomDesc = NewDesc;
	HeldItem = NewItem;
	EmptyItem = NewItem2;
	ItemThere = true;
	IsWater = Water;
}

Room::~Room()
{

}

void Room::ConnectedRoomUpdate(Room* NewRoom1, Room* NewRoom2, Room* PrevoiusRoom)
{
	ConnectedRoom = NewRoom1;
	ConnectedRoom2 = NewRoom2;
	PrevRoom = PrevoiusRoom;
}

void Room::PrintRoomItems()
{
	if (ItemThere == false)
	{
		cout << EmptyItem->Name;
	}
	else if (EmptyItem->Name == "Nothing" && ItemThere == true)
	{
		cout << HeldItem->Name;
	}
	else
	{
		cout << HeldItem->Name << ", " << EmptyItem->Name;
	}
}

Item* Room::ReturnItem1()
{
	return HeldItem;
}
Item* Room::ReturnItem2()
{
	return EmptyItem;
}

Item* Room::TakeItem()
{
	Door* Doorptr = dynamic_cast<Door*>(HeldItem);
	if (Doorptr == nullptr)
	{
		if (ItemThere == true)
		{
			return HeldItem;
		}
		return EmptyItem;
	}
	return EmptyItem;
}

void Room::PrintConnections()
{
	if (PrevRoom == nullptr && ConnectedRoom2 == nullptr)
	{
		cout << ConnectedRoom->CurrentRoom();
	}
	else if (ConnectedRoom2 == nullptr)
	{
		cout << ConnectedRoom->CurrentRoom() << ", ";
		cout << PrevRoom->CurrentRoom();
	}
	else
	{
		cout << ConnectedRoom->CurrentRoom() << ", ";
		cout << ConnectedRoom2->CurrentRoom() << ", ";
		cout << PrevRoom->CurrentRoom();
	}
}

String Room::CurrentRoom()
{
	return RoomName;
}
String Room::CurrentDesc()
{
	return RoomDesc;
}

Room* Room::ConnRoomOne()
{
	return ConnectedRoom;
}

Room* Room::ConnRoomTwo()
{
	return ConnectedRoom2;
}

Room* Room::ConnRoomPrev()
{
	return PrevRoom;
}