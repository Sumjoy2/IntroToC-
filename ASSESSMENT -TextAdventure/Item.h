#pragma once

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
	Item GiveUsed();
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
public:
	Food(String NewName, String NewDesc, Item* AfterUseItem);
	void Use(int HealAmount, Player* PlayerToAffect);
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
	void Use(Room NextRoom);
};
class EmptyItem : public Item
{
public:
	EmptyItem(String NewName, String NewDesc);
	virtual void Use() override;
};