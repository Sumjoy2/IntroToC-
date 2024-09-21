#pragma once
#include "SageString.h";

class Player;
class Door;
class Room;

class Item
{
protected:
	Item* UsedItem = nullptr;
public:
	String Name = " ";
	String Desc = " ";

	Item() {};
	Item(String newName, String newDesc);
	virtual void Use() {};
	Item* GiveUsed();
}; 

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/

class Orb : public Item
{
public:
	Orb(String NewName, String NewDesc, Item* AfterUseItem);
	virtual void Use() override;
};
class Food : public Item
{
protected:
	int HealAmount;
public:
	Food(String NewName, String NewDesc, int HowMuchHeal, Item* AfterUseItem);
	void Use(Player* PlayerToAffect);
};
class Tool : public Item
{
public:
	Tool(String NewName, String NewDesc);
	virtual void Use() override;
};
class Door : public Item
{
	bool NeedsKey;
	Item* ExpectedKey;
public:
	Door(String NewName, String NewDesc, bool DoesNeedKey = false, Item* Key = nullptr);
	void Use(Room* NextRoom, Player* ThePlayer) ;
};
class EmptyItem : public Item
{
public:
	EmptyItem(String NewName, String NewDesc);
	virtual void Use() override;
};