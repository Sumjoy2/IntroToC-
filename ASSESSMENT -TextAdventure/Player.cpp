#include <iostream>
#include "Player.h"
#include "Item.h"
#include "Room.h"
#include "Utils.h"
#include "SageString.h"

using std::cout;
using std::cin;
using std::endl;

Player::Player(float startHealth, int ItemMax, Room& StartRoom)
{
	AmountOfItems = ItemMax;
	curhealth = startHealth;
	Items = new Item[AmountOfItems];
	CurrentRoom = &StartRoom;
};

Player::~Player()
{
	delete[] Items;
};

float Player::HealthReturn()
{
	return curhealth;
};

void Player::ChangeHealth(float InAmount)
{
	curhealth = Clamp(0.0f, health, curhealth + InAmount);
};

void Player::Look()
{
	cout << CurrentRoom->CurrentDesc() << endl;
	cout << "There is: ";
	CurrentRoom->PrintRoomItems();
	cout << endl;
	cout << "Connects to ";
	CurrentRoom->PrintConnections();
	cout << "\nYou feel like you have " << HealthReturn() << "% of your energy" << endl;
}

void Player::CheckInv()
{
	cout << "Your inventory has: " << endl;
	for (int i = 0; i < AmountOfItems; i++)
	{
		if (HeldItemNumb == i+1)
		{
			cout << Items[i].Name << "- " << Items[i].Desc;
			break;
		}
		else
			cout << Items[i].Name << "- " << Items[i].Desc << endl;
	}
}

bool Player::HasItem(Item ItemToLookFor)
{
	for (int i = 0; i < AmountOfItems; i++)
	{
		if (Items[i].Name.Equals(ItemToLookFor.Name))
		{
			return true;
		}
	}
	return false;
}

void Player::ItemAdd(Item NewItem)
{
	bool HasFishSlot = false;
	int SlotNumb = -1;
	//Checking if you have a fish slot
	for (int i = 0; i < HeldItemNumb; i++)
	{
		if (Items[i].Name.ToLower() == "fish slot")
		{
			HasFishSlot = true;
			SlotNumb = i;
		}
	}

	if (HasFishSlot == true && NewItem.Name.ToLower() == "fish")
	{
		Items[SlotNumb] = NewItem;
	}
	else
	{
		Items[HeldItemNumb] = NewItem;
		HeldItemNumb++;
		CurrentRoom->ItemThere = false;
	}
}

void Player::ItemUse(String* NewItem, bool* EndReach)
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
		return;
	}

	if (NewItem->Equals("shadow orb"))
	{
		cout << "The Orb gets absorbed into you" << endl;
		Items[ItemLocal].Name = "Used Orb";
		Items[ItemLocal].Desc = "An empty glass orb";
	}
	else if (NewItem->Equals("mushroom"))
	{
		cout << "You eat the shroom. You feel a lot better" << endl;
		ChangeHealth(150);
		Items[ItemLocal].Name = "Bit Shroom";
		Items[ItemLocal].Desc = "All the edible parts of the mushroom are gone";
	}
	else if (NewItem->Equals("fish"))
	{
		cout << "You eat the Fish. You feel a bit better" << endl;
		ChangeHealth(10);
		Items[ItemLocal].Name = "Fish Slot";
		Items[ItemLocal].Desc = "The fish slot of your inventory now";
	}
	else if (NewItem->Equals("used orb"))
	{
		cout << "After violently shaking the orb... Nothing happens." << endl;
	}
	else if (NewItem->Equals("bit shroom"))
	{
		cout << "You just cant get yourself to eat the last bit." << endl;
	}
	else if (NewItem->Equals("fish slot"))
	{
		cout << "Being unsure how this got here you are unable to tell if it does anything other than hold a fish." << endl;
	}
	else if (NewItem->Equals("worn fishing rod"))
	{
		cout << "good craftmanship but you use the TAKE command to get the fish." << endl;
	}
	else if (NewItem->Equals("nothing"))
	{
		cout << "I dont know how you got this but its pretty impressive you did." << endl;
	}
	else if (NewItem->Equals("boat"))
	{
		bool HasUsedOrb = false;
		//looks for used orb item then sets HasUsedOrb = true
		for (int i = 0; i < HeldItemNumb; i++)
		{
			if (Items[i].Name.ToLower() == "used orb")
			{
				HasUsedOrb = true;
				break;
			}
		}
		//if its true then the game ends
		if (HasUsedOrb == true)
		{
			cout << "The goblins understand you and bring you aboard the ship." << endl;
			cout << "On the ship you are lead to the helm of the ship." << endl;
			cout << "Once at the helm you start to glow a dark purple" << endl;
			cout << "The entire ship reacts to the Shadow Orb that you absorbed." << endl;
			cout << "You see the ship become infused with the purple color you are glowing" << endl;
			cout << "You pass out." << endl;
			cout << "DEMO OVER: " << endl;

			*EndReach = true;
		}
		else
		{
			cout << "The goblins do not react to your presense" << endl;
		}
	}
}

void Player::ChangeRooms(String* NewRoom)
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
}