#include <iostream>

class Player
{
	int MyID = 0;
	char Name[6];
public:
	Player()
	{
		std::cout << "Player constructed" << std::endl;
	}

	~Player()
	{
		std::cout << "Player Destructed" << std::endl;
	}

	Player(int SpawnID)
	{
		std::cout << "player " << SpawnID << " constructed." << std::endl;
		
		MyID = SpawnID;
	}
};

int main()
{
	Player ThisPlayer;
	Player ParameterPlayer(5);

	Player AllPlayers[10];

	return 0;
}