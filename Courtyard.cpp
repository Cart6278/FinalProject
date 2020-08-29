/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: Courtyard Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in this function.
**creates a new People pointer for the combat that can happen
*****************************/


#include "Courtyard.hpp"
#include <iostream>
#include "DracoMalfoy.hpp"
#include "itemsHelper.hpp"


Courtyard::Courtyard()
{
}

void Courtyard::play(People * player, std::vector<std::string>& inventory, int &steps)
{
	People* draco = new DracoMalfoy;
	int playerChoice;

	std::cout << "You slowly open the main doors and see Malfoy and his Twiddle-dee and Twiddle-dum like henchmen Crabbe and Goyle at the other end of the Courtyard laughing and pointing towards Hagrid's Hut. Be careful, one missplaced step and they may confront you." << std::endl;

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
		int sizeI = inventory.size();
		int choiceInv;
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
		if (inventory[1] == "Invisibility Cloak")
		{
			std::cout << "Look, it's Malfoy and his goons, quick get under the Cloak Hermione!" << std::endl;
		}
		else
		{
			// Combat is adapted from Project3-Fantasy Combat

			std::cout << "Malfoy has spotted you." << std::endl;
			std::cout << "Malfoy: 'Why look, it's Potter and the Know-It-All. Come to watch the Ministry as they rid the world of that stupid bird?'" << std::endl;
			std::cout << player->getCharacterType() <<": 'Speaking of a dumb bird.' "<<  std::endl;
			std::cout << "Malfoy: 'You'll pay for that!' Malfoy draws his wand." << std::endl;

			int startHPA = player->getStrength(); //health points of attacker
			int startHPD = draco->getStrength(); //health points of defender
			//int round = 1;
			//display stats (Each Round Info Displayed 1. Attacker Type, Armor, Strength 2. Defender Type, Armor, Strength)
			while (startHPA > 0 && startHPD > 0)
			{

				int p1Attack;
				int p2Attack;
				std::cout << player->getCharacterType() <<" attacks!" << std::endl;
				p1Attack = player->attack();
				//std::cout << "Malfoy defends!" << std::endl;
				draco->defense(p1Attack); //pass attack value to defense

				if (draco->getStrength() > 0)
				{
					std::cout << "Malfoy counter attacks!" << std::endl;
					p2Attack = draco->attack();
					std::cout << player->getCharacterType()<<" defends the counter attack!" << std::endl;
					player->defense(p2Attack);
				}
				else if (draco->getStrength() <= 0)
				{
					std::cout << "Malfoy has been stunned, there will be no counter attack as Crabbe and Goyle have to drag him to the Hospital Wing." << std::endl;
				}
				startHPA = player->getStrength();
				startHPD = draco->getStrength();
			}
			++steps;
		}
		
		++steps;
	}
	else if (player->getStrength() < 0)
	{
		std::cout << "Ok, lets move on then." << std::endl;
	}

	++steps;
	delete draco;
}


Courtyard::~Courtyard()
{
}
