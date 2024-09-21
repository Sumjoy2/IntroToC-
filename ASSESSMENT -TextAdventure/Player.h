#pragma once

class Room;
class String;
class Item;

class Player
{
private:
	float health = 100.0f;
	float curhealth = 0.0f;
	Item** Items = nullptr;
	int AmountOfItems = 0;
	int HeldItemNumb = 0;
public:
	Room* CurrentRoom = nullptr;

	Player();
	Player(float startHealth, int ItemMax, Room& StartRoom);
	
	~Player();

	float HealthReturn();
	
	//Negative will reduce health
	void ChangeHealth(float InAmount);

	void Look();

	//Outputs what is currently in the players invintory
	void CheckInv();

	bool HasItem(Item* ItemToLookFor);

	//Adds an item to the players inventory
	void ItemAdd(Item* NewItem);
	//Uses item that is in players inventory
	void ItemUse(String* NewItem);

	/*
	* @brief Updates the CurrentRoom
	* @param A pointer to a string
	* @details Checks the string and if its equal to a connecting room name
	*/
	void ChangeRooms(const String& NewRoom, Room* TheEndRoom = nullptr);
};