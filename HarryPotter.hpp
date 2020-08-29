/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: HarryPotter Class - Holds the attack and defend functions related to the character. Based directly on the game mechanics from Project3.
*****************************/

#pragma once
#include "People.hpp"

class HarryPotter :
	public People
{
protected:
	int attack() override;
	int defense(int) override;
public:
	HarryPotter();
	virtual ~HarryPotter();
};

