#pragma once
#include <string>

class People
{
protected:
	int armor;
	int strength;
	int attackRoll;
	int defendRoll;
	std::string characterType;

public:
	People();

	virtual int attack() = 0;
	virtual int defense(int) = 0;

	int getArmor();
	int getStrength();
	int getAttackRoll();
	int getDefendRoll();
	std::string getCharacterType();

	void setAttackRoll(int);
	void setDefendRoll(int);
	void setArmor(int);
	void setStrength(int);
	void setCharacterType(std::string);

	~People();
};

