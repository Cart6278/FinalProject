#include "Game.hpp"
#include "People.hpp"
#include <iostream>
#include "charText.hpp"


Game::Game()
{
}

void Game::gamePlay()
{
	int playerChoice;

	charInfo(); //display characters to choose from

	std::cout << "Please choose a character to play:" << std::endl;
	std::cin >> playerChoice;
	while (playerChoice < 1 || playerChoice > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
	{
		std::cout << "ERROR - Invalid input! Please choose 1 for Harry or 2 for Hermione: \n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> playerChoice;
	}
	if (playerChoice == 1)
	{
		new HarryPotter();

	}
	if (playerChoice == 2)
	{
		new HermioneGrainger();
	}
}


Game::~Game()
{
}
