/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: People Class - Holds the main menu functions that relate to the characters in the game. Adapted from Project3-Fantasy Combat. Added a boolean function to determine if the user had
**collected Buckbeak
*****************************/

#pragma once
#include <string>
//#include "Space.hpp"

class People
{
protected:
	int armor;
	int strength;
	int attackRoll;
	int defendRoll;
	std::string characterType;
	bool buckbeak;

public:
	People();

	virtual int attack() = 0;
	virtual int defense(int) = 0;

	int getArmor();
	int getStrength();
	int getAttackRoll();
	int getDefendRoll();
	std::string getCharacterType();
	bool getBuckbeak();
	

	void setAttackRoll(int);
	void setDefendRoll(int);
	void setArmor(int);
	void setStrength(int);
	void setCharacterType(std::string);
	void setBuckbeak(int);

	virtual ~People();
};

