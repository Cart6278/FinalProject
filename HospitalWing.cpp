/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: HospitalWing Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in this function.
**Begins the game, displays the starting inventory and character.
*****************************/


#include "HospitalWing.hpp"
#include <iostream>


HospitalWing::HospitalWing()
{

}

void HospitalWing::play(People* player, std::vector<std::string>& inventory, int &steps)
{

	std::cout << "Dumbledoor Enters: 'You, my dears, have a chance to write at least one wrong this evening. Three turns should do it Ms. Granger, and remember \n, you have 15 steps to reach the Pumpkin Patch. Don't forget to search for dead ferrets, \n they will help you to free Buckbeak and take him to the Forbidden Forest. But remember, searching a room costs one step. If you search a room and then get into a fight with a student that costs an additional step.\n If you are caught by a teacher or the Ministry arrives at the Pumpkin Patch before you do, you have failed... Three turns should do it Ms. Granger.'" << std::endl;
	std::cout << "As Dumbledoor exits you, " << player->getCharacterType() << ", look at your bag and see you have:" << std::endl;
	
	int size = inventory.size();
	
	for(int i=0; i < size; i++)
	{
		std::cout << i+1 <<") " << inventory[i] << std::endl;
	}
	std::cout << "\nLeaving you with only " << 7-inventory.size() << " spaces for other items:" << std::endl;
	std::cout<<std::endl;
	steps++;

}


HospitalWing::~HospitalWing()
{
}
