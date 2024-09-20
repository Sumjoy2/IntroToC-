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

Item Item::GiveUsed()
{
	return *UsedItem;
}

Orb::Orb(String NewName, String NewDesc, Item* AfterUseItem) : Item(NewName, NewDesc)
{
	UsedItem = AfterUseItem;
}

void Orb::Use() 
{
	cout << "The Orbs powers get absorbed into you" << endl;
}

Food::Food(String NewName, String NewDesc, Item* AfterUseItem) : Item(NewName, NewDesc)
{
	UsedItem = AfterUseItem;
}

void Food::Use(int HealAmount, Player *PlayerToAffect)
{
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

void Door::Use(Room NextRoom)
{
	//DO STUFF HERE
}

EmptyItem::EmptyItem(String NewName, String NewDesc) : Item(NewName, NewDesc)
{
}
void EmptyItem::Use()
{

}