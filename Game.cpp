/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: Game Class - Holds all the functions and values related to Game play.
*****************************/

#include "Game.hpp"
#include <iostream>
#include "charText.hpp"
#include "HarryPotter.hpp"
#include "HermioneGrainger.hpp"
#include "HospitalWing.hpp"
#include "Space.hpp"
#include "Path.hpp"
#include "EntranceHall.hpp"
#include "Courtyard.hpp"
#include "HagridHut.hpp"
#include "PumpkinPatch.hpp"
#include "Menu.hpp"
#include "ForbiddenForest.hpp"

/****************************
**Constructor: Creates spaces and pointers to each upon game creation
*****************************/
Game::Game()
{
	hWing = new HospitalWing;
	hallway = new Path;
	eHall = new EntranceHall;
	courtyard = new Courtyard;
	path = new Path;
	hHut = new HagridHut;	
	pPatch = new PumpkinPatch;
	fForest = new ForbiddenForest;

	hWing->setTop(nullptr);
	hWing->setBottom(hallway);
	hWing->setLeft(nullptr);
	hWing->setRight(nullptr);
	hWing->setName("Hospital Wing");

	hallway->setTop(hWing);
	hallway->setBottom(eHall);
	hallway->setLeft(nullptr);
	hallway->setRight(nullptr);
	hallway->setName("Hallway");

	eHall->setTop(hallway);
	eHall->setBottom(courtyard);
	eHall->setLeft(nullptr);
	eHall->setRight(nullptr);
	eHall->setName("Entrance Hall");

	courtyard->setTop(eHall);
	courtyard->setBottom(path);
	courtyard->setLeft(nullptr);
	courtyard->setRight(nullptr);
	courtyard->setName("Courtyard");

	path->setTop(courtyard);
	path->setBottom(hHut);
	path->setLeft(nullptr);
	path->setRight(nullptr);
	path->setName("Path");

	hHut->setTop(path);
	hHut->setBottom(pPatch);
	hHut->setLeft(nullptr);
	hHut->setRight(fForest);
	hHut->setName("Hagrid's Hut");

	pPatch->setTop(hHut);
	pPatch->setBottom(fForest);
	pPatch->setLeft(nullptr);
	pPatch->setRight(nullptr);
	pPatch->setName("Pumpkin Patch");
	
	fForest->setTop(pPatch);
	fForest->setBottom(nullptr);
	fForest->setLeft(nullptr);
	fForest->setRight(hHut);
	fForest->setName("Forbidden Forest");
}

/****************************
**gamePlay: Contains calls for general game play and character movement between spaces. Calls functions from Spaces, People, and creates a vector named inventory. Keeps track of steps.
*****************************/
void Game::gamePlay()
{
	Menu menu;

	
	int playerChoice;
	int steps = 0;
	std::vector<std::string> inventory;
	gameInfo(); //display general game info
	charInfo(); //display characters to choose from

	std::cout << "Please choose a character to play:" << std::endl;
	std::cin >> playerChoice;
	while (playerChoice < 1 || playerChoice > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
	{
		std::cout << "ERROR - Invalid input! Please choose 1 for Harry or 2 for Hermione: \n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> playerChoice;
	}
	if (playerChoice == 1)
	{
		player = new HarryPotter;
		inventory.emplace_back("Wand");
		inventory.emplace_back("Invisibility Cloak");
		

	}
	if (playerChoice == 2)
	{
		player = new HermioneGrainger;
		inventory.emplace_back("Wand");
		
	}
	
	currLocation = hWing; //set current location
	player->setBuckbeak(false); //set player to not have buckbeak

	while (!player->getBuckbeak() && player->getStrength() != 0 && steps > 15)
	{
		
		bool selectedSpace = false; //set select space to go to next to false
		currLocation->play(player, inventory, steps); //call main gameplay function for current location

		if (player->getStrength() > 0) //do not enter if player is dead
		{
		std::cout <<"\nYou have taken " << steps <<" out of 15 steps so far. \n"<< std::endl;
		int choiceI;
		std::cout << "Do you want to look at your inventory before moving forward? (1=Yes 2=No)" << std::endl;
		std::cin >> choiceI;
		while (choiceI < 1 || choiceI > 2 || std::cin.fail() || std::cin.get() != '\n') //adapted use of cin from: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/ and http://www.cplusplus.com/reference/limits/numeric_limits/ and last answer here: https://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float
		{
			std::cout << "ERROR - Invalid input! Please choose 1 for yes or 2 for no: \n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choiceI;
		}
		switch (choiceI)
		{
		case 1:
			{
				int size = inventory.size();
				for (int i = 0; i < size; i++)
				{
					std::cout << i + 1 << ") " << inventory[i] << std::endl;
				}
				std::cout << "" << std::endl;
			}
			break;
		case 2:
		default:
			break;
		}
		gameMap(currLocation); //display map and current location

			if (currLocation->getTop() != nullptr && selectedSpace == false)
			{
				std::cout << "In front of you is " << currLocation->getTop()->getName() << "." << std::endl;
				switch (menu.movement())
				{
				case 1:
				{
					Space* nextSpace = currLocation->getTop();
					currLocation = nextSpace;
					selectedSpace = true;
				}
				break;
				case 2:
				default:
					break;
				}
			}
			if (currLocation->getBottom() != nullptr && selectedSpace == false)
			{

				std::cout << "Behind you is " << currLocation->getBottom()->getName() << "." << std::endl;
				switch (menu.movement())
				{
				case 1:
				{
					Space* nextSpace = currLocation->getBottom();
					currLocation = nextSpace;
					selectedSpace = true;
				}
				break;
				case 2:
				default:
					break;
				}
			}
			if (currLocation->getLeft() != nullptr && selectedSpace == false)
			{
				std::cout << "To your left is " << currLocation->getLeft()->getName() << "." << std::endl;
				switch (menu.movement())
				{
				case 1:
				{
					Space* nextSpace = currLocation->getLeft();
					currLocation = nextSpace;
					selectedSpace = true;
				}
				break;
				case 2:
				default:
					break;
				}
			}
			if (currLocation->getRight() != nullptr && selectedSpace == false)
			{
				std::cout << "To your right is " << currLocation->getRight()->getName() << "." << std::endl;
				switch (menu.movement())
				{
				case 1:
				{
					Space* nextSpace = currLocation->getRight();
					currLocation = nextSpace;
					selectedSpace = true;
				}
				break;
				case 2:
				default:
					break;
				}
			}
		}
		
	}
	if (player->getStrength() <=0 || steps >= 15)
	{
		std::cout <<"You have unfortunately not made it to the end. Try again another time."<< std::endl;
	} else if (currLocation->getName() == "Forbidden Forest")
	{
		std::cout << "You Won! Buckbeak is free!" << std::endl;
	}
	inventory.clear();
}

/****************************
**Deconstructor: Deletes space pointers and character pointers to each upon game end
*****************************/
Game::~Game()
{
	delete hWing;
	delete hallway;
	delete eHall;
	delete courtyard;
	delete path;
	delete hHut;
	delete pPatch;
	delete fForest;
	delete player;
}
