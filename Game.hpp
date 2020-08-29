/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: Game Class - Holds all the functions and values related to Game play.
*****************************/

#pragma once
#include "Space.hpp"
#include "People.hpp"

class Game
{
protected:
	People* player;
	Space* hWing;
	Space* hallway;
	Space* eHall;
	Space* courtyard;
	Space* path;
	Space* hHut;
	Space* pPatch;
	Space* fForest;

	Space* currLocation;
public:
	Game();
	void gamePlay();
	~Game();
};

