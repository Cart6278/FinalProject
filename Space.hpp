#pragma once
#include "Room.hpp"

class Space
{
protected:
	Room* top;
	Room* bottom;
	Room* left;
	Room* right;
public:
	Space();
	~Space();
};

