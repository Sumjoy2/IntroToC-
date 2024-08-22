#include <iostream>

int main()
{
	float Width = 0;
	float Length = 0;
	float NumberOne = 0;
	float NumberTwo = 0;
	float Points = 0;
	float Total = 0;
	char UserAnswer = ' ';

	std::cout << "Select App Use: A for Rectangle Area, C for Calc, Q for Quiz" << std::endl;
	std::cin >> UserAnswer;

	//Rectanle Area
	if (UserAnswer == 'A')
	{
		std::cout << "Enter Length and Width" << std::endl;
		std::cin >> Length >> Width;
		Total = Width * Length;
		std::cout << "The area is: " << Total;
	}

	//Very Basic Calculator
	else if (UserAnswer == 'C')
	{
		std::cout << "Enter two numbers and a operation" << std::endl;
		std::cin >> NumberOne >> NumberTwo >> UserAnswer;

		if (UserAnswer == '+')
		{
			Total = NumberOne + NumberTwo;
			std::cout << Total << std::endl;
		}
		else if (UserAnswer == '-')
		{
			Total = NumberOne - NumberTwo;
			std::cout << Total << std::endl;
		}
		else if (UserAnswer == '*')
		{
			Total = NumberOne * NumberTwo;
			std::cout << Total << std::endl;
		}
		else if (UserAnswer == '/')
		{
			Total = NumberOne / NumberTwo;
			std::cout << Total << std::endl;
		}
	}

	//Quiz
	else if (UserAnswer == 'Q')
	{
		std::cout << "Welcome to the quiz of totally legit" << std::endl << "Question one: What is roughly PI\n A. 3.14\n B. 3\n C. Pineapples\n D. 4" << std::endl;
		std::cin >> UserAnswer;
		if (UserAnswer == 'A')
		{
			std::cout << "Correct"; 
			Points = Points + 1;
		}
		else std::cout << "False, its 3.14";

		std::cout << Points << std::endl << "Question two: What is the first letter of the alphabet\n A. C\n B. A\n C. D\n D. B" << std::endl;
		if (UserAnswer == 'B')
		{
			std::cout << "Correct";
			Points = Points + 1;
		}
		else std::cout << "False, its A";

		std::cout << Points << std::endl << "Question Three: What is a spikey fruit\n A. Apple\n B. Orange\n C. Pineapple\n D. Strawberry" << std::endl;
		if (UserAnswer == 'B')
		{
			std::cout << "Correct";
			Points = Points + 1;
		}
		else std::cout << "False, its Pineapple";
	}
	return 0;
}