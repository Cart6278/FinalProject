/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: PumpkinPatch Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in this function.
** Takes the number of dead ferrets in your inventory and determines the odds for releasing Buckbeak
*****************************/

#pragma once
#include "Space.hpp"

class PumpkinPatch :
	public Space
{
public:
	PumpkinPatch();
	void play(People*, std::vector<std::string>&, int&) override;
	virtual ~PumpkinPatch();
};

