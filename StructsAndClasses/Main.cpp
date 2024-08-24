#include <iostream>

struct Vector2Int
{
	//make sure to initialize things
	int X = 0;
	int Y = 0;
};

float FindValue(float Numbers[], size_t Count, float Value, int Start)
{
	for (int i = Start; i < Count; i++)
	{
		if (Numbers[i] == Value)
		{
			return i;
		}
	}
	return -1;
}

class Player
{
	//cannot be used outside of class
	int health = 5;
	int score = 0;
	//usable outside of the class
public:
	Vector2Int position;
	char Name[6];

	int TakeDamage(int DMG)
	{
		health -= DMG;
		return health;
	}

	float GetHealth()
	{
		return health;
	}
};
struct HighScoreData
{
	int Score = 0;
	float TimeToComplete = 0.0f;
	Player player;
};

//Add together all times. divide by ArraySize
float AvgTime(HighScoreData ScoreArray[], int ArraySize)
{
	float tempVar = 0;
	for (int i = 0; i < ArraySize; i++)
	{
		tempVar = tempVar + ScoreArray[i].TimeToComplete;
	}
	tempVar = tempVar / ArraySize;
	return tempVar;
}

int AvgScore(HighScoreData ScoreArray[], int ArraySize)
{
	int tempVar = 0;
	for (int i = 0; i < ArraySize; i++)
	{
		tempVar = tempVar + ScoreArray[i].Score;
	}
	tempVar = tempVar / ArraySize;
	return tempVar;

}

HighScoreData HighestScore(HighScoreData ScoreArray[], int ArraySize)
{
	HighScoreData tempVar = { 0, 0};
	for (int i = 0; i < ArraySize; i++)
	{
		if (tempVar.Score < ScoreArray[i].Score)
		{
			tempVar.Score = ScoreArray[i].Score;
			tempVar.player = ScoreArray[i].player;
		}
		else continue;
	}
	return tempVar;
}

void HighCopy(HighScoreData ScoreArray[],HighScoreData WriteArray[], int ArraySize, int TopNumber)
{
	HighScoreData MostRecent = { 0, 0 };
	HighScoreData Previous = { 0, 0 };
	//Loops through how many scores are being put in the new scoreboard
	for (int i = 0; i < TopNumber; i++)
	{
		//loops through checking if Current score is higher than next score
		for (int o = 0; o < ArraySize; o++)
		{
			
			if (ScoreArray[o].Score > MostRecent.Score)
			{
				MostRecent = ScoreArray[o];
				Previous = ScoreArray[i];
			}
		}
		WriteArray[i] = ScoreArray[i];		
		std::cout << MostRecent.Score << std::endl << std::endl;
	}
	std::cout << WriteArray;
}

int main()
{
	Player Players[5];
	strcpy_s(Players[0].Name, 6, "One");
	strcpy_s(Players[1].Name, 6, "Two");
	strcpy_s(Players[2].Name, 6, "Three");
	strcpy_s(Players[3].Name, 6, "Four");
	strcpy_s(Players[4].Name, 6, "Five");
	HighScoreData HighScores[5] = {{50, 1.0f, Players[0]},{100, 50.0f, Players[1]},{150, 3.5f, Players[2]},{200, 3.5f, Players[3]},{250, 3.5f, Players[4]}};
	HighScoreData BlankScores[5];
	
	/*std::cout << AvgTime(HighScores, 5) << std::endl;
	std::cout << AvgScore(HighScores, 5) << std::endl;
	std::cout << HighestScore(HighScores, 5).player.Name << ", " << HighestScore(HighScores, 5).Score << ", " << HighestScore(HighScores, 5).TimeToComplete << std::endl;*/
	HighCopy(HighScores, BlankScores, 5, 3);

	

	return 0;
}



