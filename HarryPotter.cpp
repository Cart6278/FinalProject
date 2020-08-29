/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: HarryPotter Class - Holds the attack and defend functions related to the character. Based directly on the game mechanics from Project3.
*****************************/


#include "HarryPotter.hpp"
#include <iostream>


HarryPotter::HarryPotter()
{
	setArmor(0);
	setStrength(14);
	setCharacterType("Harry Potter");
}

/****************************
**attack: rolls two dice to get attack value.
*****************************/
int HarryPotter::attack()
{
	int dice1 = (rand() % (6 + 1));
	int dice2 = (rand() % (6 + 1));

	int attackValue = dice1 + dice2;

	setAttackRoll(attackValue);

	std::cout << "Harry has attacked with Stupify that has an attack value of " << attackValue << "." << std::endl;

	return attackValue;
}

/****************************
**defense: rolls two dice to get defense value.
*****************************/
int HarryPotter::defense(int oppAttack)
{
	int defenseValue;

	int dice1 = (rand() % (6 + 1));
	int dice2 = (rand() % (6 + 1));


	defenseValue = dice1 + dice2;
	setDefendRoll(defenseValue);

	int totalDamage = oppAttack - getArmor() - defenseValue;
	if (totalDamage <= 0)
	{

		std::cout << "Harry used a Pergeo with a defense value of " << defenseValue << ". No damage to Harry's health. \n" << std::endl;
		return 0;
	}
	else
	{
		int currentS = getStrength() - totalDamage;
		if (currentS <= 0)
		{
			std::cout << "Harry has has been stunned and must to be escorted to the hospital wing by Hermione." << std::endl;
			std::cout << "Better luck next time. \n" << std::endl;
			currentS = 0; //set current Strength to 0 so there is no negative Strength
		}

		std::cout << "Harry used a Pergeo with a defense value of " << defenseValue << "." << std::endl;
		std::cout << "Harry suffered a total damage of: " << totalDamage << " leaving him with a Health of: " << currentS << "\n" << std::endl;

		setStrength(currentS);
		return currentS;
	}
}

HarryPotter::~HarryPotter()
{
}
