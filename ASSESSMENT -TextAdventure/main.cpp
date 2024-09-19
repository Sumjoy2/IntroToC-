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
	Room(String NewName, String NewDesc, bool Water = false)
	{
		RoomName = NewName;
		RoomDesc = NewDesc;
		ItemThere = false;
		EmptyItem.Name = "Nothing";
		EmptyItem.Desc = "The Empty air";
		IsWater = Water;
	};

	//Construct a Room with a new Id and desc and an item. Optionally how many connections the room has
	Room(String NewName, String NewDesc, Item NewItem, Item NewItem2, bool Water = false)
	{
		RoomName = NewName;
		RoomDesc = NewDesc;
		HeldItem = NewItem;
		EmptyItem = NewItem2;
		ItemThere = true;
		IsWater = Water;
	};
	~Room()
	{
		
	};

	/*
	* @brief updates all connected rooms to the inputs
	* @param Pointer to the first new room
	* @param Pointer to the Second new room
	* @param Pointer to the previous room
	*/
	void ConnectedRoomUpdate(Room *NewRoom1, Room *NewRoom2 = nullptr, Room* PrevoiusRoom = nullptr)
	{
		ConnectedRoom = NewRoom1;
		ConnectedRoom2 = NewRoom2;
		PrevRoom = PrevoiusRoom;
	}

	/*
	* @brief prints to the screen the items in the room
	*/
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

	/*
	* @brief returns the item and essentially removes it
	* @return current room item or the empty item if ItemThere is false
	*/
	Item TakeItem()
	{
		if (ItemThere == true)
		{
			ItemThere == false;
			return HeldItem;
		}
		return EmptyItem;
	};

	void PrintConnections()
	{
		if (PrevRoom == nullptr && ConnectedRoom2 == nullptr)
		{
			cout << ConnectedRoom->CurrentRoom() << endl;
		}
		else if (ConnectedRoom2 == nullptr)
		{
			cout << ConnectedRoom->CurrentRoom() << ", ";
			cout << PrevRoom->CurrentRoom() << endl;
		}
		else
		{
			cout << ConnectedRoom->CurrentRoom() << ", ";
			cout << ConnectedRoom2->CurrentRoom() << ", ";
			cout << PrevRoom->CurrentRoom() << endl;
		}
	}

	/*
	* @brief gives the room name
	* @return RoomName
	*/
	String CurrentRoom()
	{
		return RoomName;
	};

	/*
	* @brief gives the rooms ID
	* @return RoomID
	*/
	int CurrentRoomID()
	{
		return RoomId;
	}

	/*
	* @brief gives the rooms description
	* @return RoomDesc
	*/
	String CurrentDesc()
	{
		return RoomDesc;
	}

	Room* ConnRoomOne()
	{
		return ConnectedRoom;
	}
	Room* ConnRoomTwo()
	{
		return ConnectedRoom2;
	}
	Room* ConnRoomPrev()
	{
		return PrevRoom;
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
		cout << "There is: ";
		CurrentRoom->PrintRoomItems();
		cout << endl;
		cout << "Connects to ";
		CurrentRoom->PrintConnections();
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
	void ItemUse(String *NewItem, bool *EndReach)
	{
		int ItemLocal = -1;
		for (int i = 0; i < AmountOfItems; i++)
		{
			if (NewItem->Equals(Items[i].Name.ToLower()))
			{
				ItemLocal = i;
				break;
			}
			else
			{
				continue;
			}		
		}

		if (ItemLocal == -1)
		{
			cout << "you dont have that item" << endl;
		}

		//if (NewItem == "Worn Fishing Rod" && CurrentRoom->IsWater == true)
		//{
		//	//Fish
		//}
		if (NewItem->Equals("shadow orb"))
		{
			cout << "The Orb gets absorbed into you" << endl;
			Items[ItemLocal].Name = "Used Orb";
			Items[ItemLocal].Desc = "An empty glass orb";
		}
		else if (NewItem->Equals("mushroom"))
		{
			cout << "You eat the shroom. You feel a bit better" << endl;
			ChangeHealth(15);
			Items[ItemLocal].Name = "Bit Shroom";
			Items[ItemLocal].Desc = "All the edible parts of the mushroom are gone";
		}
		else if (NewItem->Equals("boat"))
		{
			bool HasUsedOrb = false;
			for (int i = 0; i < HeldItemNumb; i++)
			{
				if (Items[i].Name.ToLower() == "used orb")
				{
					HasUsedOrb = true;
					break;
				}
			}
			if (HasUsedOrb == true)
			{
				cout << /*Lore Stuff Here*/ "DEMO OVER: " << endl;
				*EndReach = true;
			}
			else
			{
				cout << "The goblins do not react to your presense" << endl;
			}
		}
	};

	void ChangeRooms(String* NewRoom)
	{
		if (NewRoom->Equals(CurrentRoom->ConnRoomOne()->CurrentRoom().ToLower()))
		{
			CurrentRoom = CurrentRoom->ConnRoomOne();
		}
		else if (CurrentRoom->ConnRoomTwo() != nullptr && NewRoom->Equals(CurrentRoom->ConnRoomTwo()->CurrentRoom().ToLower()))
		{
			CurrentRoom = CurrentRoom->ConnRoomTwo();
		}
		else if (CurrentRoom->ConnRoomPrev() != nullptr && NewRoom->Equals(CurrentRoom->ConnRoomPrev()->CurrentRoom().ToLower()))
		{
			CurrentRoom = CurrentRoom->ConnRoomPrev();
		}
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
	Room CaveBack("Cave Back", "The back of the cave you started in.", PurpleORB, Nothing);
	Room CaveEntrance("Entrance of Cave", "The entrance to the cave you woke up in.");
	Room Forest("Forest", "A nice lush forest just outside the cave.", Shroom, Nothing);
	Room Lake("Lake", "A small lake with fish", FishRod, Fish, true);
	Room Town("Town", "A quiant little town");
	Room Dock("Dock", "A nice little dock connecting the town to the vast ocean", Boat, Nothing, true);

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
		system("cls");
		String LoweredInput = Input.ToLower();
	#pragma region InputChecking
		if (Input.Find("use") != -1)
		{
			cout << "Input what to use your options are:\n";
			ThePlayer.CheckInv();
			Input.ReadFromConsole();
			LoweredInput = Input.ToLower();
			ThePlayer.ItemUse(&LoweredInput, &GAMEOVER);
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
			cout << "Input where to go. Options are: ";
			ThePlayer.CurrentRoom->PrintConnections();
			Input.ReadFromConsole();
			LoweredInput = Input.ToLower();

			bool TheCheck = false;

			bool ConCheck2 = ThePlayer.CurrentRoom->ConnRoomTwo() == nullptr ? false : true;
			bool ConCheckPrev = ThePlayer.CurrentRoom->ConnRoomPrev() == nullptr ? false : true;

			if (ConCheck2 == false && ConCheckPrev == false)
			{
				TheCheck = (LoweredInput == ThePlayer.CurrentRoom->ConnRoomOne()->CurrentRoom().ToLower() ? true : false);
			}
			else if (ConCheck2 == false)
			{
				TheCheck = LoweredInput == ThePlayer.CurrentRoom->ConnRoomOne()->CurrentRoom().ToLower() ||
					Input == ThePlayer.CurrentRoom->ConnRoomPrev()->CurrentRoom().ToLower() ? true : false;
			}
			else
			{
				TheCheck = LoweredInput == ThePlayer.CurrentRoom->ConnRoomOne()->CurrentRoom().ToLower() ||
					LoweredInput == ThePlayer.CurrentRoom->ConnRoomTwo()->CurrentRoom().ToLower() ||
					LoweredInput == ThePlayer.CurrentRoom->ConnRoomPrev()->CurrentRoom().ToLower() ? true : false;
			}

			if (ThePlayer.CurrentRoom->CurrentRoom() == Input)
			{
				cout << "You are already here. What do you do instead?";
			}
			else if (TheCheck == false)
				cout << "What?" << endl;
			else
			{
				ThePlayer.ChangeRooms(&LoweredInput);
				cout << "You are now at: " << ThePlayer.CurrentRoom->CurrentRoom() << endl;
			}
		}
	#pragma endregion
	}
#pragma endregion

	return 0;
}