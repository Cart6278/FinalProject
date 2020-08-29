/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: ForbiddenForest Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in 
**this function. Will direct you to go to the Pumpkin Patch before coming here. There is nothing to search for.
*****************************/


#include "ForbiddenForest.hpp"
#include <iostream>


ForbiddenForest::ForbiddenForest()
{
}

void ForbiddenForest::play(People * player, std::vector<std::string>& inventory, int &steps)
{
	if(player->getBuckbeak()==false)
	{
		std::cout << "You currently do not have Buckbeak with you, return to the Pumpkin Patch to retrieve him." << std::endl;
		++steps;
	}
}


ForbiddenForest::~ForbiddenForest()
{
}
