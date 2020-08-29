/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: HermioneGrainger Class - Holds the attack and defend functions related to the character. Based directly on the game mechanics from Project3.
*****************************/

#include "HermioneGrainger.hpp"
#include <iostream>

/****************************
**Constructor: Sets armor, strength, and character type values.
*****************************/
HermioneGrainger::HermioneGrainger()
{
	setArmor(0);
	setStrength(12);
	setCharacterType("Hermione Granger");
}

/****************************
**attack: rolls two dice to get attack value. If Hermione rolls an 8 or above she punches her opponent in the face knocking them out.
*****************************/
int HermioneGrainger::attack()
{
	int dice1 = (rand() % (6 + 1));
	int dice2 = (rand() % (6 + 1));

	int attackValue = dice1 + dice2;

	setAttackRoll(attackValue);

	if (dice1 + dice2 <= 8) //Hermione used special ability
	{
		attackValue = 100;
		std::cout << "Hermione, fed up with Malfoy's antics punches him in the face and knocks him out. Face punching is Super Effective!" << std::endl;
	}
	else
	{
		attackValue = dice1 + dice2;
		std::cout << "Hermione has attacked with Stupify that has an attack value of " << attackValue << "." << std::endl;
	}
	//std::cout << "Hermione rolled an Attack of " << attackValue << "." << std::endl;

	return attackValue;
}

/****************************
**defense: rolls two dice to get defense value.
*****************************/
int HermioneGrainger::defense(int oppAttack)
{
	int defenseValue;

	int dice1 = (rand() % (6 + 1));
	int dice2 = (rand() % (6 + 1));


	defenseValue = dice1 + dice2;
	setDefendRoll(defenseValue);

	int totalDamage = oppAttack - getArmor() - defenseValue;
	if (totalDamage <= 0)
	{

		std::cout << "Hermione used a Pergeo with a defense value of " << defenseValue << ". No damage to Hermione's health. \n" << std::endl;
		return 0;
	}
	else
	{
		int currentS = getStrength() - totalDamage;
		if (currentS <= 0)
		{
			std::cout << "Hermione has been stunned and has to be escorted to the hospital wing by Harry." << std::endl;
			std::cout << "Better luck next time. \n" << std::endl;
			currentS = 0; //set current Strength to 0 so there is no negative Strength
		}

		std::cout << "Hermione used a Pergeo with a defense value of " << defenseValue << "." << std::endl;
		std::cout << "Hermione suffered a total damage of: " << totalDamage << " leaving her with a Health of: " << currentS << "\n" << std::endl;

		setStrength(currentS);
		return currentS;
	}
}

HermioneGrainger::~HermioneGrainger()
{
}
