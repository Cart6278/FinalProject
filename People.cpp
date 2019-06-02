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


People::~People()
{
}
