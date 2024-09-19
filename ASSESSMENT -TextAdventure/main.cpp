#include <iostream>
#include <fstream>
#include <ctime>
#include "Utils.h"
#include "SageString.h"

using std::cout;
using std::cin;
using std::endl;

struct Item
{
public:
	String Name = " ";
	String Desc = " ";
}; bool NeedsKey = false;

class Room
{
private: 
	//the name of the room
	String RoomName = " ";
	//the ID of the room
	int RoomId = -1;
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
	Room()
	{
		RoomName = " ";
		RoomDesc = " ";
		EmptyItem.Name = "Nothing";
		EmptyItem.Desc = "The Empty air";
	};
	//Construct a Room with new Id
	//Room(String NewId);
	//Construct a Room with a new Id and desc. Optionally how many connections the room has
	Room(String NewName,int NewId, String NewDesc, bool Water = false)
	{
		RoomName = NewName;
		RoomDesc = NewDesc;
		RoomId = NewId;
		ItemThere = false;
		EmptyItem.Name = "Nothing";
		EmptyItem.Desc = "The Empty air";
		IsWater = Water;
	};

	//Construct a Room with a new Id and desc and an item. Optionally how many connections the room has
	Room(String NewName, int NewId, String NewDesc, Item NewItem, Item NewItem2, bool Water = false)
	{
		RoomName = NewName;
		RoomDesc = NewDesc;
		RoomId = NewId;
		HeldItem = NewItem;
		EmptyItem = NewItem2;
		ItemThere = true;
		IsWater = Water;
	};
	~Room()
	{
		
	};

	void PrintRoomItems()
	{
		if (ItemThere == false)
		{
			cout << EmptyItem.Name;
		}
		else if (EmptyItem.Name == "Nothing" && ItemThere == true)
		{
			cout << HeldItem.Name;
		}
		else
		{
			cout << HeldItem.Name << ", " << EmptyItem.Name;
		}
	}

	Item TakeItem()
	{
		if (ItemThere == true)
			return HeldItem;
		return EmptyItem;
	};

	void ItemUpdate(Item NewItem)
	{
		HeldItem = NewItem;
	};

	void ConnectedRoomUpdate(Room *NewRoom1)
	{
		ConnectedRoom = NewRoom1;
	}
	void ConnectedRoomUpdate(Room *NewRoom1, Room *NewRoom2, Room* PrevoiusRoom = nullptr)
	{
		ConnectedRoom = NewRoom1;
		ConnectedRoom2 = NewRoom2;
		PrevRoom = PrevoiusRoom;
	}

	//Gives the Current rooms name
	String CurrentRoom()
	{
		return RoomName;
	};

	//Gives the Current Rooms ID
	int CurrentRoomID()
	{
		return RoomId;
	}

	//Gives the current rooms description
	String CurrentDesc()
	{
		return RoomDesc;
	}
};

class Player
{
private:
	float health = 100.0f;
	float curhealth = 0.0f;
	Item* Items = nullptr;
	int AmountOfItems = 0;
	int HeldItemNumb = 0;
public:
	Room* CurrentRoom;

	Player();
	Player(float startHealth, int ItemMax, Room &StartRoom)
	{
		AmountOfItems = ItemMax;
		curhealth = startHealth;
		Items = new Item[AmountOfItems];
		CurrentRoom = &StartRoom;
	};
	~Player()
	{
		delete[] Items;
		//delete CurrentRoom;
	};
	float HealthReturn()
	{
		return curhealth;
	};
	//Negative will reduce health
	void ChangeHealth(float InAmount)
	{
		Clamp(0.0f, health, curhealth += InAmount);
	};

	void Look()
	{
		cout << CurrentRoom->CurrentDesc() << endl;
		CurrentRoom->PrintRoomItems();
		cout << endl;
		cout << "connects to ";

	}

	//Outputs what is currently in the players invintory
	void CheckInv()
	{
		for (int i = 0; i < AmountOfItems; i++)
		{
			if (HeldItemNumb == i)
			{
				cout << Items[i].Name << ": " << Items[i].Desc;
				break;
			}
			else
				cout << Items[i].Name << ": " << Items[i].Desc << ", ";
		}
		cout << endl;
	};

	//Adds an item to the players inventory
	void ItemAdd(Item NewItem)
	{
		if (HeldItemNumb >= AmountOfItems)
		{
			cout << "Inventory Full" << endl;
		}
		else
		{
			CurrentRoom->ItemThere = false;
			Items[HeldItemNumb] = NewItem;
			HeldItemNumb++;
		}
	};
	//Uses item that is in players inventory
	void ItemUse(String NewItem, bool &EndReach)
	{
		int ItemLocal = 0;
		for (int i = 0; i < AmountOfItems; i++)
		{
			if (NewItem == Items[i].Name)
			{
				ItemLocal = i;
				break;
			}
			else
			{
				cout << "you dont have that item" << endl;
				return;
			}
				
		}
		//if (NewItem == "Worn Fishing Rod" && CurrentRoom->IsWater == true)
		//{
		//	//Fish
		//}
		if (NewItem == "Shadow Orb")
		{
			cout << "The Orb gets absorbed into you" << endl;
			Items[ItemLocal].Name = "Used Orb";
			Items[ItemLocal].Desc = "An empty glass orb";
		}
		else if (NewItem == "Mushroom")
		{
			cout << "You eat the shroom. You feel a bit better" << endl;
			ChangeHealth(15);
			Items[ItemLocal].Name = "Bit Shroom";
			Items[ItemLocal].Desc = "All the edible parts of the mushroom are gone";
		}
		else if (NewItem == "Boat")
		{
			bool HasUsedOrb = false;
			for (int i = 0; i < HeldItemNumb; i++)
			{
				if (Items[i].Name == "Used Orb")
				{
					HasUsedOrb = true;
				}
			}
			if (HasUsedOrb == true)
			{
				cout << /*Lore Stuff Here*/ "DEMO OVER: " << endl;
				EndReach = true;
				//END THE GAME
			}
			else
			{
				cout << "The goblins do not react to your presense" << endl;
			}
		}
	};

	void ChangeRooms(Room* NewRoom)
	{
		cout << "You move to " << NewRoom << endl;
		CurrentRoom = NewRoom;
	};
};

int main()
{
	//Setting up being able to use time
	time_t currTime = std::time(nullptr);
	struct tm timeTM;
	localtime_s(&timeTM, &currTime);   

#pragma region ItemSetup
	Item PurpleORB; PurpleORB.Name = "Shadow Orb"; PurpleORB.Desc = "A purple orb that glows with a mysterious power";
	Item Shroom; Shroom.Name = "Mushroom"; Shroom.Desc = "A small mushroom which will heal some Health";
	Item FishRod; FishRod.Name = "Worn Fishing Rod"; FishRod.Desc = "A well used fishing rod bait included";
	Item Fish; Fish.Name = "Fish"; Fish.Desc = "A caught fish that will heal some health";
	Item Boat; Boat.Name = "Boat"; Boat.Desc = "A sturdy looking boat crewed by FRIENDLY goblins", true;
	Item Nothing; Nothing.Name = "Nothing"; Nothing.Desc = "A grasp of Nothing";
#pragma endregion

#pragma region RoomSetup
	Room CaveBack("Back of Cave", 0, "The back of the cave you started in.", PurpleORB, Nothing);
	Room CaveEntrance("Entrance of Cave", 1, "The entrance to the cave you woke up in.");
	Room Forest("Forest", 2, "A nice lush forest just outside the cave.", Shroom, Nothing);
	Room Lake("Lake", 3, "A small lake with fish", FishRod, Fish, true);
	Room Town("Town", 4, "A quiant little town");
	Room Dock("Dock", 5, "A nice little dock connecting the town to the vast ocean", Boat, Nothing, true);

	CaveBack.ConnectedRoomUpdate(&CaveEntrance);
	CaveEntrance.ConnectedRoomUpdate(&Forest, nullptr, &CaveBack);
	Forest.ConnectedRoomUpdate(&Lake, &Town, &CaveEntrance);
	Lake.ConnectedRoomUpdate(&Forest);
	Town.ConnectedRoomUpdate(&Dock, nullptr, &Forest);
	Dock.ConnectedRoomUpdate(&Town);
#pragma endregion

	//Sets ThePlayers health to 25 and 10 item slots and starting room the back of the cave
	Player ThePlayer(25.0f, 10, CaveBack);
	String Input;
	bool GAMEOVER = false;

	cout << "its " << timeTM.tm_hour << ":";
	if (timeTM.tm_min < 10)
		cout << "0" << timeTM.tm_min << endl;
	else
		cout << timeTM.tm_min << endl;

	/*
	* More Intro Stuff goes here. lots of couts i would guess
	*/

#pragma region GameLoop
	while (Input.ToLower() != "quit" && GAMEOVER == false)
	{
		cout << "use - use an item, take - take the rooms item, check - check inventory, Move - Move to next room";
		//Gets input from the player forever
		Input.ReadFromConsole();
		if (Input.Find("use") != -1)
		{
			cout << "Input what to use";
			Input.ReadFromConsole();
			ThePlayer.ItemUse(Input, GAMEOVER);
		}
		else if (Input.Find("Take") != -1)
		{
			if (ThePlayer.CurrentRoom->ItemThere)
			{
				cout << "You Take: " << ThePlayer.CurrentRoom->TakeItem().Name << endl;
				ThePlayer.ItemAdd(ThePlayer.CurrentRoom->TakeItem());
			}
			//else if (ThePlayer.CurrentRoom->TakeItem().Name == Fish.Name)
			//{
			//	cout << "You Grab at: " << ThePlayer.CurrentRoom->TakeItem().Name;
			//}
		}
		else if (Input.Find("Check") != -1)
		{
			ThePlayer.CheckInv();
		}
		else if (Input.Find("look") != -1)
		{
			ThePlayer.Look();
		}
		else if (Input.Find("Move") != -1)
		{
			cout << "Input where to go";
			Input.ReadFromConsole();
			if (ThePlayer.CurrentRoom->CurrentRoom() == Input)
			{
				cout << "You are already here. What do you do instead";
			}
		}
	}
#pragma endregion

	return 0;
}