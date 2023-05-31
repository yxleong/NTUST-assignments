/*****************************************************************//**
* File: Object.h
* Author:
*	Leong Yah Xuan
*	Tien Qingian
* Create Date: May 20, 2023
* Update Date: May 27, 2023
* Description: This C++ program is to implement class Object.
*********************************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Position.h" // Position
#include "main.h"	  // isPositionValid
using namespace std;

class Object {
public:
	Position sPos;
	char sIcon = 0;
	char sDispIcon = 0; // for canSee
public:
	// Default constructor
	Object(void);

	// Set position
	void setPos(Position pos);

	// Set icon
	void setIcon(char& icon);

	// Get position
	Position getPos(void);

	// Get Icon
	char getIcon(void);
};

#include "Hero.h" // Creature update Hero