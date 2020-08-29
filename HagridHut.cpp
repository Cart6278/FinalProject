/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: HagridHut Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in this function.
*****************************/


#include "HagridHut.hpp"
#include <iostream>
#include "itemsHelper.hpp"


HagridHut::HagridHut()
{
}

void HagridHut::play(People * player, std::vector<std::string>& inventory, int &steps)
{
	std::cout << "After making it down the path you arrive at Hagrid's Hut where you can hear some not so quiet sobbing drifting out the open window. The Pumpkin Patch is directly to your right where you can see Buckbeak is tied up and napping in the evening Scottish sun." << std::endl;

	int playerChoice;
	std::cout << "Do you want to search the area for items? (1=Yes 2=No)" << std::endl;
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
		int choiceInv;
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
		int choiceInvA;
		std::cout << "It's a rock... No, wait, it's one of Hagrid's Rock Cookies. Would you like to add it to the inventory? (1=Yes 2=No)" << std::endl;
		std::cin >> choiceInvA;
		while (choiceInvA < 1 || choiceInvA > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
		{
			std::cout << "ERROR - Invalid input! Please choose 1 for yes or 2 for no: \n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choiceInvA;
		}
		switch (choiceInvA)
		{
		case 1:
		{
			if (sizeI < 7)
			{
				itemAdd(inventory, "Rock Cookie");

			}
			else
			{
				itemSwitch(inventory, "Rock Cookie");
				std::cout << "You currently have " << inventory.size() << " items in your bag." << std::endl;
			}
		}
		break;
		case 2:
		default: std::cout << "You have chosen to not add this item to your inventory. You currently have " << inventory.size() << " items in your bag." << std::endl;
			break;
		}
		int choiceInvB;
		std::cout << "It's another dead ferret, what luck! Would you like to add it to the inventory? (1=Yes 2=No)" << std::endl;
		std::cin >> choiceInvB;
		while (choiceInvB < 1 || choiceInvB > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
		{
			std::cout << "ERROR - Invalid input! Please choose 1 for yes or 2 for no: \n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choiceInvA;
		}
		switch (choiceInvA)
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
			std::cout << "Oh no, Professor Dumbledoor and The Ministry officials are making their way towards the Hut!" << std::endl;

			if (inventory[1] == "Invisibility Cloak")
			{
				std::cout << "Quick Hermione, get under the Cloak." << std::endl;
			}
			else
			{
				if ((rand() % (4 + 1)) == 1)
				{
					std::cout << "Professor Dumbledoor finds you and thanks you for wanting to comfort Hagrid during this difficult time but you must return to the Castle. You've lost." << std::endl;
					player->setStrength(0);
				}
				else
				{
					std::cout << "Quick Harry, behind the stone wall!" << std::endl;
				}
			}

		}
		++steps;
	}
	else if (player->getStrength() < 0)
	{
		std::cout << "Ok, lets move on then." << std::endl;
	}

	++steps;
}


HagridHut::~HagridHut()
{
}
