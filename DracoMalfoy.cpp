/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: DracoMalfoy Class - Holds the attack and defend functions related to the character. Based directly on the game mechanics from Project3.
*****************************/

#include "DracoMalfoy.hpp"
#include <iostream>


DracoMalfoy::DracoMalfoy()
{
	setArmor(0);
	setStrength(12);
	setCharacterType("Draco Malfoy");
}
/****************************
**attack: rolls two dice to get attack value.
*****************************/
int DracoMalfoy::attack()
{
	int dice1 = (rand() % (6 + 1));
	int dice2 = (rand() % (6 + 1));

	int attackValue = dice1 + dice2;

	setAttackRoll(attackValue);

	std::cout << "Dracohas attacked with Stupify that has an attack value of " << attackValue << "." << std::endl;

	return attackValue;
}

/****************************
**defense: rolls two dice to get defense value.
*****************************/
int DracoMalfoy::defense(int oppAttack)
{
	int defenseValue;

	int dice1 = (rand() % (6 + 1));
	int dice2 = (rand() % (6 + 1));


	defenseValue = dice1 + dice2;
	setDefendRoll(defenseValue);

	int totalDamage = oppAttack - getArmor() - defenseValue;
	if (totalDamage <= 0)
	{

		std::cout << "Draco used a Pergeo with a defense value of " << defenseValue << ". No damage to Draco's health. \n" << std::endl;
		return 0;
	}
	else
	{
		int currentS = getStrength() - totalDamage;
		if (currentS <= 0)
		{
			std::cout << "Draco has suffered too much damage and has to be escorted to the hospital wing by his goons Crabbe and Goyle." << std::endl;
			std::cout << "His father will hear about this! \n" << std::endl;
			currentS = 0; //set current Strength to 0 so there is no negative Strength
		}

		std::cout << "Draco used a Pergeo with a defense value of " << defenseValue << "." << std::endl;
		std::cout << "Draco suffered a total damage of: " << totalDamage << " leaving him with a Health of: " << currentS << "\n" << std::endl;

		setStrength(currentS);
		return currentS;
	}
}

DracoMalfoy::~DracoMalfoy()
{
}
