/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: Path Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in this function.
*****************************/

#include "Path.hpp"
#include "itemsHelper.hpp"
#include <iostream>


Path::Path()
{
}

void Path::play(People * player, std::vector<std::string>& inventory, int &steps)
{
	std::cout << "You peak around the corner and see that the coast is clear, for the moment. You both quickly and quietly enter the area." << std::endl;
	int playerChoice;
	int choiceInv;
	std::cout << "Do you want to search the area for items? (1=Yes 2=No)" << std::endl;
	std::cin >> playerChoice;
	while (playerChoice < 1 || playerChoice > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
	{
		std::cout << "ERROR - Invalid input! Please choose 1 for yes or 2 for no: \n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> playerChoice;
	}
	if (playerChoice == 1)
	{
		int sizeI = inventory.size();
		std::cout << "You found a dead ferret! Would you like to add it to the inventory? (1=Yes 2=No)" << std::endl;
		std::cin >> choiceInv;
		while (choiceInv < 1 || choiceInv > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
		{
			std::cout << "ERROR - Invalid input! Please choose 1 for yes or 2 for no: \n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choiceInv;
		}
		switch (choiceInv)
		{
		case 1:
			{
				if (sizeI < 7)
				{
					itemAdd(inventory, "Dead Ferret");

				}
				else
				{
					itemSwitch(inventory, "Dead Ferret");
					std::cout << "You currently have " << inventory.size() << " items in your bag." << std::endl;
				}
			}
		break;
		case 2:
		default: std::cout << "You have chosen to not add this item to your inventory. You currently have " << inventory.size() << " items in your bag." << std::endl;
			break;
		}
		
		if ((rand() % (6 + 1)) > 3)
		{
			std::cout << "You trip over a stair, you remain unhurt but you let out a loud yelp and a choice swear word or two on your way down. You look behind you and see Mrs. Norris, Filch's cat glaring form above. Filch cannot be far behind.\n" << std::endl;
			if (inventory[1] == "Invisibility Cloak")
			{
				std::cout << "Filtch is coming! Quick Hermione, get under the Cloak." << std::endl;
			} else
			{
				if ((rand() % (4 + 1)) ==1)
				{
					std::cout << "Filtch found you and takes you to Professor McGonagall, you've lost" << std::endl;
					player->setStrength(0);
				} else
				{
					std::cout << "Filtch is coming! Quick Harry, behind the statue!" << std::endl;
				}
			}

		}
		++steps;
	} else if (player->getStrength() < 0)
	{
		std::cout << "Ok, lets move on then." << std::endl;
	}
	
	++steps;

}


Path::~Path()
{
}
