/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: Space Class - Holds all the functions and values related to Space. Has a virtual function called play where most game play takes place.
*****************************/

#pragma once
#include "People.hpp"
#include <string>
#include <vector>


class Space
{
protected:
	Space* top;
	Space* bottom;
	Space* left;
	Space* right;
	std::string name;
	bool buckbeak;
	
public:
	Space();

	virtual void play(People*, std::vector<std::string>&, int &) = 0;

	void setTop(Space*);
	void setBottom(Space*);
	void setLeft(Space*);
	void setRight(Space*);
	void setName(std::string);
	void setBuckbeak(int);

	Space* getTop();
	Space* getBottom();
	Space* getLeft();
	Space* getRight();
	bool getBuckbeak();
	std::string getName();

	
	//may not use these

	virtual ~Space();
};

