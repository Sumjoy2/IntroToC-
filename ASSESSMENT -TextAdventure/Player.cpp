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
	Items = new Item*[AmountOfItems];
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
			cout << Items[i]->Name << "- " << Items[i]->Desc;
			break;
		}
		else
			cout << Items[i]->Name << "- " << Items[i]->Desc << endl;
	}
}

bool Player::HasItem(Item *ItemToLookFor)
{
	for (int i = 0; i < HeldItemNumb; i++)
	{
		if (Items[i]->Name.Equals(ItemToLookFor->Name))
		{
			return true;
		}
	}
	return false;
}

void Player::ItemAdd(Item *NewItem)
{
	bool HasFishSlot = false;
	int SlotNumb = -1;
	//Checking if you have a fish slot
	for (int i = 0; i < HeldItemNumb; i++)
	{
		if (Items[i]->Name.ToLower() == "fish slot")
		{
			HasFishSlot = true;
			SlotNumb = i;
		}
	}

	if (HasFishSlot == true && NewItem->Name.ToLower() == "fish")
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
		if (NewItem->Equals(Items[i]->Name.ToLower()))
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
	
	Food* FoodPtr = dynamic_cast<Food*>(Items[ItemLocal]);

	if (FoodPtr != nullptr)
	{
		FoodPtr->Use(this);
	}
	else
	{
		Items[ItemLocal]->Use();
		if (Items[ItemLocal]->GiveUsed() != nullptr)
			Items[ItemLocal] = Items[ItemLocal]->GiveUsed();
	}
}

void Player::ChangeRooms(const String& NewRoom)
{
	if (NewRoom.Equals(CurrentRoom->ConnRoomOne()->CurrentRoom().ToLower()))
	{
		CurrentRoom = CurrentRoom->ConnRoomOne();
	}
	else if (CurrentRoom->ConnRoomTwo() != nullptr && NewRoom.Equals(CurrentRoom->ConnRoomTwo()->CurrentRoom().ToLower()))
	{
		CurrentRoom = CurrentRoom->ConnRoomTwo();
	}
	else if (CurrentRoom->ConnRoomPrev() != nullptr && NewRoom.Equals(CurrentRoom->ConnRoomPrev()->CurrentRoom().ToLower()))
	{
		CurrentRoom = CurrentRoom->ConnRoomPrev();
	}
}