/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: itemsHelper - Holds functions to display game text info and a map that lists the users current location.
*****************************/

#include "charText.hpp"
#include <iostream>
#include "Space.hpp"

/****************************
**charInfo(): Displays information about character choices
*****************************/
void charInfo()
{
	std::cout << "-- THE CHARACTERS -- \n" << std::endl;
	std::cout << "1) Harry Potter \n"
		"Attack: 2d6 \n"
		"Defense: 2d6 \n"
		"Armor: 0 \n"
		"Health: 14 \n"
		"Special Ability/Item: Invisibility Cloak - allows you to sneak by Professors, Ministry Officials, and annoying classmates.\n" << std::endl;

	std::cout << "2) Hermione Granger \n"
		"Attack: 2d6 \n"
		"Defense: 2d6 \n"
		"Armor: 0 \n"
		"Health: 12 \n"
		"Special Ability/Item: Face Punch: When Hermione rolls a die greater than 8 opponent is punched in the face and she wins automatically. They never expect the muggle face punch! \n" << std::endl;
}

/****************************
**gameInfo(): Displays information about how the game runs to the user
*****************************/
void gameInfo()
{
	std::cout <<"The goal of the game is to free Buckbeak the Hippogriff! You must make it to the Pumpkin Patch by Hagrid's Hut before the Ministry of Magic arrives and" << std::endl;
	std::cout << "sends Buckbeak to a tragic and early end. You have 12 steps to make it to Hagrid's Hut. Entering each room is a step, searching a room is an additional step," << std::endl;
	std::cout << "and if you get into a fight with another student a third step is taken. If you are found by a professor or are defeated in combat the game is over! Along your journey from"<<std::endl; 
	std::cout << "the Hospital Wing through Hogwarts and onto the grounds you have the chance to search each area or room for 'Dead Ferrets'." << std::endl;
	std::cout << "If you choose to search a room, you are more likely to be caught by a Professor. Every Dead Ferret you find can be used to convince Buckbeak to fallow you more easily. " << std::endl;
	std::cout << "Not every space will have a Ferret. After retrieving Buckbeak take him to the Forbidden Forest just behind the Pumpkin Patch to complete the game." <<std::endl;
	std::cout << "To move between rooms and areas the game will display the available rooms one by one, you will make your choice when the room you would like to enter appears." << std::endl;
	std::cout << "If you do not choose a room or area to move to you will have a chance to search the room you are in again." << std::endl;
	std::cout << "Good luck, good hunting, and don't get caught!" << std::endl;
}

/****************************
**gameInfo(): Displays information about how the game runs to the user
*****************************/
void gameMap(Space* currSpace)
{
	std::cout << "   ### THE PATH TO BUCKBEAK ###   \n" << std::endl;
	std::cout << "      ---Hospital Wing---         " << std::endl;
	std::cout << "              ||                  " << std::endl;
	std::cout << "    ---Stairwell/Hallway---       " << std::endl;
	std::cout << "              ||                  " << std::endl;
	std::cout << "      ---Entrance Hall---         " << std::endl;
	std::cout << "              ||                  " << std::endl;
	std::cout << "        ---Courtyard---           " << std::endl;
	std::cout << "              ||                  " << std::endl;
	std::cout << "     ---Path to Hagrid's Hut---   " << std::endl;
	std::cout << "              ||                  " << std::endl;
	std::cout << "Hagrid's Hut ======= Pumpkin Patch" << std::endl;
	std::cout << "   ||                    //       " << std::endl;
	std::cout << "     ---Forbidden Forest---       \n" << std::endl;
	std::cout << "  ***Current Location: "<< currSpace->getName() <<"***\n    " << std::endl;

}