/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: People Class - Holds the main menu functions that relate to the characters in the game. Adapted from Project3-Fantasy Combat. Added a boolean function to determine if the user had 
**collected Buckbeak
*****************************/

#include "People.hpp"



People::People()
{
}

int People::getArmor()
{
	return armor;
}

int People::getStrength()
{
	return strength;
}

int People::getAttackRoll()
{
	return attackRoll;
}

int People::getDefendRoll()
{
	return defendRoll;
}

std::string People::getCharacterType()
{
	return characterType;
}

bool People::getBuckbeak()
{
	return buckbeak;
}

// Space* People::getLocation()
// {
// 	return location;
// }

void People::setAttackRoll(int aR)
{
	attackRoll = aR;
}

void People::setDefendRoll(int dR)
{
	defendRoll = dR;
}

void People::setArmor(int a)
{
	armor = a;
}

void People::setStrength(int s)
{
	strength = s;
}

void People::setCharacterType(std::string cT)
{
	characterType = cT;
}

void People::setBuckbeak(int b)
{
	buckbeak = b;
}

// void People::setLocation(Space* currSpace)
// {
// 	location = currSpace;
// }


People::~People()
{
}
