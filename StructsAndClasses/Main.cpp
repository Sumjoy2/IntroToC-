#include <iostream>
#include <cstdlib>  // for srand
#include <ctime>    // for time

struct Vector2Int
{
	//make sure to initialize things
	int X = 0;
	int Y = 0;
};

//int FindValue(float Numbers[], size_t Count, float Value, int Start)
//{
//	for (int i = Start; i < Count; i++)
//	{
//		if (Numbers[i] == Value)
//		{
//			return i;
//		}
//	}
//	return -1;
//}

class Player
{
	//cannot be used outside of class
private:
	int Health = 5;
	int Score = 0;
	int Defence = 0;
	int Speed = 0;

	//usable outside of the class
public:
	Vector2Int position;
	char Name[6] = " ";

	Player() {}

	Player(const char NewName[])
	{
		strcpy_s(Name, NewName);
	}

	int TakeDamage(int DmgDealt)
	{
		int Invincable = std::rand() % 10;
		if (Invincable == 0)
		{
			return Health;
		}
		else
		{
			Health -= (DmgDealt - Defence);
			return Health;
		}
	}

	int GetHealth()
	{
		return Health;
	}

	int GetScore()
	{
		return Score;
	}

	int UpdateScore(int ScoreUpAmount)
	{
		Score += ScoreUpAmount;
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
	//int Temp = 0;

	//for (int i = 0; i < ArraySize; i++)
	//{
	//	Temp = i;
	//}

	//for (int k = 0; k < ArraySize; k++)
	//{
	//	std::cout <<"Temp - k: " << Temp - k << std::endl;
	//	std::cout <<"Score being compared: " << ScoreArray[k].Score << std::endl;
	//	for (int o = 0; o < TopNumber; o++)
	//	{
	//		//std::cout << "Temp - o: " << (Temp - 2) - o << std::endl;
	//		if (ScoreArray[k].Score > WriteArray[Temp - o].Score)
	//		{
	//			WriteArray[(Temp) - o] = ScoreArray[k];
	//		}
	//		std::cout << WriteArray[o].Score << std::endl;
	//	}
	//}

	/*Check for biggest number then next biggest till you have TopNumber*/
	for (int i = 0; i < TopNumber; i++)
	{
		if (ScoreArray[i].Score > WriteArray[i].Score)
		{
			WriteArray[i] = ScoreArray[i];
		}
	}

	std::cout << WriteArray;
}

int main()
{
	std::srand(std::time(nullptr));

	Player Players[5];
	strcpy_s(Players[0].Name, "One"); strcpy_s(Players[1].Name, "Two"); strcpy_s(Players[2].Name, "Three"); strcpy_s(Players[3].Name, "Four"); strcpy_s(Players[4].Name, "Five");
	HighScoreData HighScores[5] = {{50, 1.0f, Players[0]},{100, 50.0f, Players[1]},{150, 3.5f, Players[2]},{200, 3.5f, Players[3]},{250, 3.5f, Players[4]}};
	HighScoreData BlankScores[5];

	/*for (int i = 0; i < 10; i++)
	{
		Players[0].TakeDamage(1);
		std::cout << Players[0].GetHealth();
	}
	std::cout << AvgTime(HighScores, 5) << std::endl;
	std::cout << AvgScore(HighScores, 5) << std::endl;
	std::cout << HighestScore(HighScores, 5).player.Name << ", " << HighestScore(HighScores, 5).Score << ", " << HighestScore(HighScores, 5).TimeToComplete << std::endl;*/
	
	HighCopy(HighScores, BlankScores, 5, 5);

	//std::cout << std::endl << BlankScores[0].Score;

	return 0;
}



