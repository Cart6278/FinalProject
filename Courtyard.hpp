/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: Courtyard Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in this function.
**creates a new People pointer for the combat that can happen
*****************************/

#pragma once
#include "Space.hpp"

class Courtyard :
	public Space
{
public:
	Courtyard();
	void play(People*, std::vector<std::string>&, int&) override;
	~Courtyard();
};

