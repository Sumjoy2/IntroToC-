#include <iostream>
#include <fstream>
#include <ctime>
#include "SageString.h"
#include "Item.h"
#include "Room.h"
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	//Setting up being able to use time
#pragma region TimeSetup
	time_t currTime = std::time(nullptr);
	struct tm timeTM;
	localtime_s(&timeTM, &currTime);   
#pragma endregion

	//Initializes items, gives items their name & their description
#pragma region ItemSetup
	Item PurpleORB; PurpleORB.Name = "Shadow Orb"; PurpleORB.Desc = "A purple orb that glows with a mysterious power";
	Item Shroom; Shroom.Name = "Mushroom"; Shroom.Desc = "A small mushroom which will heal some Health";
	Item FishRod; FishRod.Name = "Worn Fishing Rod"; FishRod.Desc = "A well used fishing rod bait included";
	Item Fish; Fish.Name = "Fish"; Fish.Desc = "A caught fish that will heal some health";
	Item Boat; Boat.Name = "Boat"; Boat.Desc = "A sturdy looking boat crewed by FRIENDLY goblins", true;
	Item Nothing; Nothing.Name = "Nothing"; Nothing.Desc = "A grasp of Nothing";
#pragma endregion

#pragma region RoomSetup
	//initializes all rooms
	Room CaveBack("Cave Back", "The back of a dingy slightly damp cave with what roughtly looks like a pedestal.", PurpleORB, Nothing);
	Room CaveEntrance("Cave Entrance", "The entrance to the cave you woke up in.");
	Room Forest("Forest", "A nice lush forest just outside the cave.", Shroom, Nothing);
	Room Lake("Lake", "A small lake with fish", FishRod, Fish, true);
	Room Town("Town", "A quiant little town");
	Room Dock("Dock", "A nice little dock connecting the town to the vast ocean", Boat, Fish, true);

	//Sets up the connected rooms
	CaveBack.ConnectedRoomUpdate(&CaveEntrance);
	CaveEntrance.ConnectedRoomUpdate(&Forest, nullptr, &CaveBack);
	Forest.ConnectedRoomUpdate(&Lake, &Town, &CaveEntrance);
	Lake.ConnectedRoomUpdate(&Forest);
	Town.ConnectedRoomUpdate(&Dock, nullptr, &Forest);
	Dock.ConnectedRoomUpdate(&Town);
#pragma endregion

#pragma region GeneralSetup
	//Sets ThePlayers health to 25 and 10 item slots and starting room the back of the cave
	Player ThePlayer(25.0f, 10, CaveBack);
	String Input;
	bool GAMEOVER = false;
#pragma endregion

#pragma region Intro
	cout << "You have a rough awakening much like you fell onto the floor.\n";
	cout << "After taking a look around you see: " << ThePlayer.CurrentRoom->CurrentDesc();
	cout << "\nChecking the time you notice its " << timeTM.tm_hour << ":";
	//0 padding
	if (timeTM.tm_min < 10)
		cout << "0" << timeTM.tm_min << endl;
	else
		cout << timeTM.tm_min << endl;
	cout << "As you are looking at the time you realize how bruised and battered you are." << endl;
	cout << "You cant remember how you got here" << endl;
#pragma endregion

#pragma region GameLoop
	while (Input.ToLower() != "quit" && GAMEOVER == false)
	{
		cout << "What do you do?" << endl;
		cout << "look - look around the current room, use - use an item, take - take the rooms item, check - check inventory, Move - Move to next room, Quit - quits the game";
		//Gets input from the player until game end
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
			else if (ThePlayer.CurrentRoom->TakeItem().Name == Fish.Name && ThePlayer.HasItem(FishRod))
			{
				if (ThePlayer.HasItem(Fish) == false)
				{
					cout << "You Grab at: " << ThePlayer.CurrentRoom->TakeItem().Name << endl;
					ThePlayer.ItemAdd(ThePlayer.CurrentRoom->TakeItem());
				}
				else
					cout << "You already have that item" <<endl;
			}
			else
			{
				cout << "you do not have the items to grab that" << endl;
			}
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

			//The check being used to see if input is equal to an adjacent room
			bool TheCheck = false;

			//checks if current room has a 2nd connection
			bool ConCheck2 = ThePlayer.CurrentRoom->ConnRoomTwo() == nullptr ? false : true;
			//checks if current room has a previous connection
			bool ConCheckPrev = ThePlayer.CurrentRoom->ConnRoomPrev() == nullptr ? false : true;

			//checks for extra connecting rooms
			if (ConCheck2 == false && ConCheckPrev == false)
			{
				//sets TheCheck = if input equals current room connection 1 
				TheCheck = (LoweredInput == ThePlayer.CurrentRoom->ConnRoomOne()->CurrentRoom().ToLower() ? true : false);
			}
			else if (ConCheck2 == false)
			{
				//sets TheCheck = if input equals current room connection 1
				TheCheck = LoweredInput == ThePlayer.CurrentRoom->ConnRoomOne()->CurrentRoom().ToLower() ||
					//or if input equals current room connection previous
					Input == ThePlayer.CurrentRoom->ConnRoomPrev()->CurrentRoom().ToLower() ? true : false;
			}
			else
			{
				//sets TheCheck = if input equals current room connection 1
				TheCheck = LoweredInput == ThePlayer.CurrentRoom->ConnRoomOne()->CurrentRoom().ToLower() ||
					//or if input equals current room connection 2
					LoweredInput == ThePlayer.CurrentRoom->ConnRoomTwo()->CurrentRoom().ToLower() ||
					//or if input equals current room connection previous
					LoweredInput == ThePlayer.CurrentRoom->ConnRoomPrev()->CurrentRoom().ToLower() ? true : false;
			}

			//checks if input is equal to current room
			if (ThePlayer.CurrentRoom->CurrentRoom() == Input)
			{
				cout << "You are already here. What do you do instead?";
			}
			//if the check(s) above fail
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