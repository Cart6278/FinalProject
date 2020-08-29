/****************************
**Program: Final Project
**Name: Kirsten Carter
**Date: 6/3/2019
**Description: Space Class - Holds all the functions and values related to Space.
*****************************/

#include "Space.hpp"
#include <iostream>


Space::Space()
{
}

void Space::setTop(Space* t)
{
	top = t;
}

void Space::setBottom(Space* b)
{
	bottom = b;
}

void Space::setLeft(Space* l)
{
	left = l;
}

void Space::setRight(Space* r)
{
	right = r;
}

void Space::setName(std::string n)
{
	name = n;
}

void Space::setBuckbeak(int v)
{
	buckbeak = v;
}

Space* Space::getTop()
{
	return top;
}

Space* Space::getBottom()
{
	return bottom;
}

Space* Space::getLeft()
{
	return left;
}

Space* Space::getRight()
{
	return right;
}

bool Space::getBuckbeak()
{
	return buckbeak;
}


std::string Space::getName()
{
	return name;
}


// void Space::play(People* player, std::vector<std::string>, int steps)
// {
// }

Space::~Space()
{
}
