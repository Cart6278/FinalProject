/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: ForbiddenForest Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in
**this function. Will direct you to go to the Pumpkin Patch before coming here. There is nothing to search for.
*****************************/


#pragma once
#include "Space.hpp"

class ForbiddenForest :
	public Space
{
public:
	ForbiddenForest();

	void play(People*, std::vector<std::string>&, int&) override;

	virtual ~ForbiddenForest();
};

