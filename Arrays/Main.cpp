#include <iostream>
#include <cstdlib>  // for srand
#include <ctime>    // for time
int UserAnswer;

static void FizzBuzz()
{
	//Fizz Buzz
	std::cout << "Fizz Buzz" << std::endl << std::endl;
	for (int i = 0; i <= 30; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			std::cout << "Fizz Buzz" << std::endl;
		}
		else if (i % 3 == 0)
		{
			std::cout << "Fizz " << std::endl;
		}
		else if (i % 5 == 0)
		{
			std::cout << "Buzz " << std::endl;
		}
		else
		{
			std::cout << i << std::endl;
		}
	}
}

static void FibonacciSequence()
{
	//Fibonacci Sequence
	std::cout << std::endl << "Fibonacci Sequence" << std::endl;
	std::cout << "how many digits of the sequence to show" << std::endl;
	std::cin >> UserAnswer;
	float A = 0; float B = 1;
	for (int i = 0; i < UserAnswer; i++)
	{
		float C = A + B;
		A = B;
		B = C;
		std::cout << C << "\t " << i + 1 << std::endl;
	}
}

static void GridGenerator()
{
	//Grid Generator
	std::cout << std::endl << "Grid Generator" << std::endl;
	int UserHeight = 0; int UserWidth = 0;
	std::cout << "how big do you want the grid? \n Enter Number 1" << std::endl;
	std::cin >> UserHeight;
	std::cout << "Enter Number 2" << std::endl;
	std::cin >> UserWidth;
	for (int i = 0; i < UserHeight; i++)
	{
		std::cout << "X";
		for (int i2 = 1; i2 < UserWidth; i2++)
		{
			std::cout << "X";
		}
		std::cout << std::endl;
	}
}

static void FreeNumberInput()
{
	//FreeNumberInput
	std::cout << std::endl << "Free-form Number Input" << std::endl;
	int UserArray[10];
	std::cout << "How many numbers do you want to input? (max of 10)" << std::endl;
	std::cin >> UserAnswer;
	for (int i = 0; i < UserAnswer; i++)
	{
		std::cout << "Input Number " << i + 1 << ": ";
		std::cin >> UserArray[i];
	}
	std::cout << "you entered:";
	for (int i = 0; i < UserAnswer; i++) std::cout << "\t" << UserArray[i];
}

static void GuessingGame()
{
	//Higher or Lower
	std::cout << "Take a guess from 0 to 10" << std::endl;
	std::srand(std::time(nullptr));
	int RandValue = std::rand() % 10;
	int UserGuess = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Guess " << i + 1 << ": ";
		std::cin >> UserGuess;
		if (UserGuess != RandValue)
		{
			if (UserGuess > RandValue) std::cout << "Guess is too high" << std::endl;
			else if (UserGuess < RandValue) std::cout << "Guess is too low" << std::endl;
			continue;
		}
		else std::cout << "You guessed it"; break;
	}
}

int main()
{
	std::cout << "Select a mode: FizzBuzz\t Fibonacci\t GridGenerator\t FreeNumberInput\t GuessingGame" << std::endl << "> ";
	char UserChoice[25] = {};
	std::cin >> UserChoice;

	if (strcmp(UserChoice, "FizzBuzz") == 0) FizzBuzz();
	else if (strcmp(UserChoice, "Fibonacci") == 0) FibonacciSequence();
	else if (strcmp(UserChoice, "GridGenerator") == 0) GridGenerator();
	else if (strcmp(UserChoice, "FreeNumberInput") == 0) FreeNumberInput();
	else if (strcmp(UserChoice, "GuessingGame") == 0) GuessingGame();

	return 0;
}