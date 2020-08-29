/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: EntranceHall Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in this function.
*****************************/


#include "EntranceHall.hpp"
#include <iostream>
#include "itemsHelper.hpp"


EntranceHall::EntranceHall()
{
}

void EntranceHall::play(People * player, std::vector<std::string>& inventory, int &steps)
{
	std::cout << "You slowly open the door into the Entrance Hall. You both quickly and quietly enter, trying very hard to not slam the door or make the hinges squeak. You both look around and breath a sigh of relief, no one is here." << std::endl;
	int playerChoice;
	int choiceInv;
	int choiceInvB;
	std::cout << "Do you want to search the area for items? (1=Yes 2=No)" << std::endl;
	std::cin >> playerChoice;
	while (playerChoice < 1 || playerChoice > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
	{
		std::cout << "ERROR - Invalid input! 1=Yes, 2=No: \n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> playerChoice;
	}
	if (playerChoice == 1)
	{
		int sizeI = inventory.size();
		std::cout << "You found a small collection of Galleons! Would you like to add it to the inventory? (1=Yes 2=No)" << std::endl;
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
				itemAdd(inventory, "3 Galleons");

			}
			else
			{
				itemSwitch(inventory, "3 Galleons");
				std::cout << "You currently have " << inventory.size() << " items in your bag." << std::endl;
			}
		}
		break;
		case 2:
		default: std::cout << "You have chosen to not add this item to your inventory. You currently have " << inventory.size() << " items in your bag." << std::endl;
			break;
		}
		//int sizeI = inventory.size();
		std::cout << "You also found a Dead Ferret! Would you like to add it to the inventory? (1=Yes 2=No)" << std::endl;
		std::cin >> choiceInvB;
		while (choiceInvB < 1 || choiceInvB > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
		{
			std::cout << "ERROR - Invalid input! Please choose 1 for yes or 2 for no: \n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choiceInvB;
		}
		switch (choiceInvB)
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
			std::cout << "Oh no, Snape just rounded the corner from the dungeons and is coming this way!" << std::endl;

			if (inventory[1] == "Invisibility Cloak")
			{
				std::cout << "Quick Hermione, get under the Cloak." << std::endl;
			}
			else
			{
				if ((rand() % (4 + 1)) == 1)
				{
					std::cout << "Snape (*ehem* Professor Snape) has found you, takes 20 points from Gryffindor (EACH), and takes you to Professor Dumbledoor to determine your fit and just punishment. You've lost." << std::endl;
					player->setStrength(0);
				}
				else
				{
					std::cout << "Quick Harry, through the doorway on your right!" << std::endl;
					std::cout << "Snape passes you by and in a swirl of cloak ascends the stairs to the upper an level of the Castle." << std::endl;
				}
			}

		}

	++steps;
	}	else if (player->getStrength() > 0)
	{
		std::cout << "Ok, lets move on then." << std::endl;
	}
	++steps;
}


EntranceHall::~EntranceHall()
{
}
