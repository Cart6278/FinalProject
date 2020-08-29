/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: Menu Class - Holds the main menu function that calls the Game class function gamePlay(). Also holds the movement menu to move the character around the game.
*****************************/

#pragma once
class Menu
{
public:
	Menu();
	void menuMain();

	int movement();
	~Menu();
};

