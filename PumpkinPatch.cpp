/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: PumpkinPatch Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in this function.
** Takes the number of dead ferrets in your inventory and determines the odds for releasing Buckbeak
*****************************/


#include "PumpkinPatch.hpp"
#include <iostream>
#include "itemsHelper.hpp"


PumpkinPatch::PumpkinPatch()
{
}

void PumpkinPatch::play(People *player, std::vector<std::string> &inventory, int &steps)
{
	if (steps >= 15)
	{
		std::cout << "The Ministry has beaten you to the Pumpkin Patch. You are too late to save Buckbeak." << std::endl;
		player->setStrength(0);
	}
	else
	{
		//int playerChoice;
		int numFerrets = 0;
		bool buckbeak = false;

		std::cout << "You made it to the Pumpkin Patch before the Ministry! To free Buckbeak you must first get him to fallow you. The more Dead Ferrets you have the easier it will be to convince him to move. You approach and bow holding the Ferrets you have collected at your side." << std::endl;
		int size = inventory.size();
		for(int i = 0; i<size; i++)
		{
			if(inventory[i] == "Dead Ferret")
			{
				++numFerrets;
			}
		}
		std::cout << "You have " << numFerrets << " in your inventory \n" << std::endl;
		while(buckbeak != true)
		{
			for (int i = 0; i < size; i++)
			{
				buckbeak = inventory[i] == "Buckbeak";
			}
			switch (numFerrets)
			{
				case 0:
				case 1:
				{
					int chance = (rand() % (6 + 1));
						if (chance == 6)
						{
							std::cout << "Even with your pitiful number of ferrets Buckbeak bows back and allows you to approach. You give him the ferrets and untie his lead from the steak in the ground." << std::endl;
							if(size < 7)
							{
								itemAdd(inventory, "Buckbeak");
								buckbeak = true;
							} else
							{
								itemSwitch(inventory, "Buckbeak");
								buckbeak = true;
							}
						} else
						{
							std::cout << "Buckbeak refuses to acknowledge you and your pitiful number of ferrets, try again." << std::endl;
						}
				}
				break;
				case 2:
				{
					int chance = (rand() % (6 + 2));
					if (chance == 6)
					{
						std::cout << "With your 2 Ferrets Buckbeak bows back and allows you to approach. You give him the ferrets and untie his lead from the steak in the ground." << std::endl;
						if (size < 7)
						{
							itemAdd(inventory, "Buckbeak");
							buckbeak = true;
						}
						else
						{
							itemSwitch(inventory, "Buckbeak");
							buckbeak = true;
						}
					}
					else
					{
						std::cout << "With your 2 Ferrets Buckbeak refuses to acknowledge you, try again." << std::endl;
					}
				}
				break;
				case 3:
				{
					int chance = (rand() % (6 + 3));
					if (chance == 6)
					{
						std::cout << "With your 3 Ferrets Buckbeak bows back and allows you to approach. You give him the ferrets and untie his lead from the steak in the ground." << std::endl;
						if (size < 7)
						{
							itemAdd(inventory, "Buckbeak");
							buckbeak = true;
						}
						else
						{
							itemSwitch(inventory, "Buckbeak");
							buckbeak = true;
						}
					}
					else
					{
						std::cout << "With your 3 Ferrets Buckbeak refuses to acknowledge you, try again." << std::endl;
					}
				}
				break;
				case 4:
				{
					int chance = (rand() % (6 + 4));
					if (chance == 6)
					{
						std::cout << "With your 4 Ferrets Buckbeak bows back and allows you to approach. You give him the ferrets and untie his lead from the steak in the ground." << std::endl;
						if (size < 7)
						{
							itemAdd(inventory, "Buckbeak");
							buckbeak = true;
						}
						else
						{
							itemSwitch(inventory, "Buckbeak");
							buckbeak = true;
						}
					}
					else
					{
						std::cout << "With your 4 Ferrets Buckbeak refuses to acknowledge you, try again." << std::endl;
					}
				}
				break;
				case 5:
				{
					int chance = (rand() % (6 + 5));
					if (chance == 6)
					{
						std::cout << "With your 5 Ferrets Buckbeak bows back and allows you to approach. You give him the ferrets and untie his lead from the steak in the ground." << std::endl;
						if (size < 7)
						{
							itemAdd(inventory, "Buckbeak");
							buckbeak = true;
						}
						else
						{
							itemSwitch(inventory, "Buckbeak");
							buckbeak = true;
						}
					}
					else
					{
						std::cout << "With your 5 Ferrets Buckbeak refuses to acknowledge you, try again." << std::endl;
					}
				}
				break;
				case 6:
				default:
				{
					int chance = 6;
					if (chance == 6)
					{
						std::cout << "With your 6 Ferrets Buckbeak bows back and allows you to approach. You give him the ferrets and untie his lead from the steak in the ground." << std::endl;
						if (size < 7)
						{
							itemAdd(inventory, "Buckbeak");
							buckbeak = true;
						}
						else
						{
							itemSwitch(inventory, "Buckbeak");
							buckbeak = true;
						}
					}
					else
					{
						std::cout << "With your 6 Ferrets Buckbeak refuses to acknowledge you, try again." << std::endl;
					}
				}
				break;
			}
		}
		
	std::cout << "Ok, we've got Buckbeak! Lets head to the Forbidden Forest." << std::endl;

	player->setBuckbeak(true);
	++steps;

	}
	
}


PumpkinPatch::~PumpkinPatch()
{
}
