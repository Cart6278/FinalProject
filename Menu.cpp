#include "Menu.hpp"
#include <iostream>
#include <string>
#include "Game.hpp"
#include "People.hpp"


Menu::Menu()
{
}

void Menu::menuMain()
{
	Game g1;
	int choice = 0;

	while (choice != 2)
	{
		std::cout << "-- Welcome to The Final Project - Harry Potter and the Escape of Buckbeak! --" << std::endl;
		std::cout << "Menu: " << std::endl;
		std::cout << "1) Enter Game" << std::endl;
		std::cout << "2) Exit" << std::endl;
		std::cin >> choice;
		while (choice < 1 || choice > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
		{
			std::cout << "ERROR - Invalid input! Please choose 1 to enter the game or 3 to exit: \n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choice;
		}

		switch (choice)
		{
		case 1:
		{

			//call function to find buffer
			g1.gamePlay();

		}
		break;
		case 2:

		default: return;
			break;
		}
	}
}

Menu::~Menu()
{
}
