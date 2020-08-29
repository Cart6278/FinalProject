/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: EntranceHall Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in this function.
*****************************/

#pragma once
#include "Space.hpp"

class EntranceHall :
	public Space
{
public:
	EntranceHall();

	void play(People*, std::vector<std::string>&, int&) override;

	virtual ~EntranceHall();
};

