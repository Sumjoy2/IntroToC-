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
	bool NeedsKey = false;
};

class Room
{
private:
	//the id of the room
	String RoomId = " ";
	//Description of the room
	String RoomDesc = " ";
	//Item in the room
	Item HeldItem;
	Item EmptyItem;

public:
	bool ItemThere = false;
	bool IsWater = false;
	//Default Constructor
	Room()
	{
		RoomId = " ";
		RoomDesc = " ";
		EmptyItem.Name = "Nothing";
		EmptyItem.Desc = "The Empty air";
	};
	//Construct a Room with new Id
	//Room(String NewId);
	//Construct a Room with a new Id and desc. Optionally how many connections the room has
	Room(String NewId, String NewDesc, bool Water = false)
	{
		RoomId = NewId;
		RoomDesc = NewDesc;
		ItemThere = false;
		EmptyItem.Name = "Nothing";
		EmptyItem.Desc = "The Empty air";
		IsWater = Water;
	};
	//Construct a Room with a new Id and desc and an item. Optionally how many connections the room has
	Room(String NewId, String NewDesc, Item NewItem, bool Water = false)
	{
		RoomId = NewId;
		RoomDesc = NewDesc;
		HeldItem = NewItem;
		ItemThere = true;
		EmptyItem.Name = "Nothing";
		EmptyItem.Desc = "The Empty air";
		IsWater = Water;
	};
	~Room()
	{

	};
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
	////Gives the Current rooms name
	//String CurrentRoom();
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
		if (NewItem == "Mysterious Orb")
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
			cout << /*Lore Stuff Here*/ "YOU WIN" << endl;
			EndReach = true;
			//END THE GAME
		}
	};
	//void ChangeRooms(Room *NewRoom);
};

int main()
{
	//Setting up being able to use time
	time_t currTime = std::time(nullptr);
	struct tm timeTM;
	localtime_s(&timeTM, &currTime);   

#pragma region ItemSetup
	Item ORB; ORB.Name = "Mysterious Orb"; ORB.Desc = "A purple orb that glows with a mysterious power";
	Item Shroom; Shroom.Name = "Mushroom"; Shroom.Desc = "A small mushroom which will heal some Health";
	Item FishRod; FishRod.Name = "Worn Fishing Rod"; FishRod.Desc = "A well used fishing rod bait included";
	Item Fish; Fish.Name = "Fish"; Fish.Desc = "A caught fish that will heal some health";
	Item Boat; Boat.Name = "Boat"; Boat.Desc = "A sturdy looking boat crewed by FRIENDLY goblins", true;
#pragma endregion

#pragma region RoomSetup
	Room CaveBack("Back of Cave", "The back of the cave you started in.", ORB);
	Room CaveEntrance("Entrance of Cave", "The entrance to the cave you woke up in.");
	Room Forest("Forest", "A nice lush forest just outside the cave.", Shroom);
	Room Lake("Lake", "A small lake with fish", FishRod, true);
	Room Town("Town", "A quiant little town");
	Room Dock("Dock", "A nice little dock connecting the town to the vast ocean", Boat, true);
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
		//Gets input from the player forever
		Input.ReadFromConsole();
		if (Input.Find("use") != -1)
		{
			cout << "Input what to use" << endl;
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
		else if (Input.Find("Check Inventory") != -1)
		{
			ThePlayer.CheckInv();
		}
	}
#pragma endregion
	return 0;
}