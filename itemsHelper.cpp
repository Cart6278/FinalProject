/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: itemsHelper - Holds all the functions and values related to Space. Has a virtual function called play where most game play takes place.
*****************************/

#include "itemsHelper.hpp"
#include "Game.hpp"
#include <iostream>


/****************************
**Switches an item in the vector for the passed string
*****************************/
void itemSwitch(std::vector<std::string>& inventory, std::string item)
{
	int choice;
	int choiceSwap;
	int size = inventory.size();
	std::cout << "You have too many items in your inventory, do you wish to remove one and replace it with a "<<item<<"?" << std::endl;
	std::cin >> choice;
	while (choice < 1 || choice > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
	{
		std::cout << "ERROR - Invalid input! Please choose 1 for yes or 2 for no: \n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> choice;
	}
	switch (choice)
	{
		case 1:
			{
				std::cout << "\n== CURRENT INVENTORY ==" << std::endl;
				for(int i = 0; i < size; i++)
				{
					std::cout << i + 1 << ") " << inventory[i] << std::endl;
				}
				std::cout << "Please choose an item to remove (your wand in position 1 must stay in inventory):" << std::endl;
				std::cin >> choiceSwap;
				while (choiceSwap < 2 || choiceSwap > size +1 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
					{
						std::cout << "ERROR - Invalid input! Please choose a valid number between 2 and "<< size<<": \n";
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> choice;
					}
				inventory[choiceSwap-1] = item;

				std::cout << "\n== CURRENT INVENTORY ==" << std::endl;
				for (int i = 0; i < size; i++)
				{
					std::cout << i + 1 << ") " << inventory[i] << std::endl;
				}
			}
		break;
		case 2: 
		default: std::cout << "Ok, we'll leave inventory as is." << std::endl;
		break;
	}
}

/****************************
**Adds an item in the vector for the passed string
*****************************/
void itemAdd(std::vector<std::string>& inventory, std::string item)
{
	inventory.emplace_back(item);
	std::cout << "You currently have " << inventory.size() << " items in your bag." << std::endl;
}
