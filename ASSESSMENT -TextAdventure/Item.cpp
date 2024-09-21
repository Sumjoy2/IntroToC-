#include <iostream>
#include "SageString.h"
#include "Item.h"
#include "Player.h"
#include "Room.h"

using std::cout;
using std::endl;
 
Item::Item(String newName, String newDesc)
{
	Name = newName;
	Desc = newDesc;
}

Item* Item::GiveUsed()
{
	return UsedItem;
}

Orb::Orb(String NewName, String NewDesc, Item* AfterUseItem) : Item(NewName, NewDesc)
{
	UsedItem = AfterUseItem;
}

void Orb::Use() 
{
	cout << "The Orbs powers get absorbed into you" << endl;
}

Food::Food(String NewName, String NewDesc, int HowMuchHeal, Item* AfterUseItem) : Item(NewName, NewDesc)
{
	UsedItem = AfterUseItem;
	HealAmount = HowMuchHeal;
}

void Food::Use(Player *PlayerToAffect)
{
	cout << "You eat the " << Name << " you feel better" << endl;
	PlayerToAffect->ChangeHealth(HealAmount);
	Name = UsedItem->Name;
	Desc = UsedItem->Desc;
}

Tool::Tool(String NewName, String NewDesc) : Item(NewName, NewDesc)
{
}

void Tool::Use()
{
	cout << "This Tool is used for the TAKE command to collect respective items" << endl;
}

Door::Door(String NewName, String NewDesc, bool DoesNeedKey, Item* Key) : Item(NewName, NewDesc)
{
	NeedsKey = DoesNeedKey;
	ExpectedKey = Key;
}

void Door::Use(Room* NextRoom, Player* ThePlayer)
{
	//DO STUFF HERE
	if (NeedsKey == true)
	{
		if (ThePlayer->HasItem(ExpectedKey))
		{
			ThePlayer->ChangeRooms(NextRoom->CurrentRoom(), NextRoom);
			return;
		}
		else
		{
			cout << "You dont have the item needed to do that" << endl;
			return;
		}
	}
}

EmptyItem::EmptyItem(String NewName, String NewDesc) : Item(NewName, NewDesc)
{
}
void EmptyItem::Use()
{
}