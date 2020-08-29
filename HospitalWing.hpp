/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: HospitalWing Class - Holds play function. Takes a pointer to the player, a reference to the vector named Inventory, and a reference to Steps. Inventory and Steps can be altered in this function.
**Begins the game, displays the starting inventory and character.
*****************************/

#pragma once
#include "Space.hpp"

class HospitalWing :
	public Space
{
public:
	HospitalWing();

	void play(People*, std::vector<std::string>&, int&) override;

	~HospitalWing();
};

