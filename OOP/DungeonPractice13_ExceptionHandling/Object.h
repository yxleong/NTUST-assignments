/*****************************************************************//**
 * File: Object.h
 * Author:
 * 	Leong Yah Xuan
 * 	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement class Object to manage Hero, Items, and Creatures.
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
	char sIcon;		// original icon
	char sDispIcon; // current icon
public:
	// Default constructor
	Object(void);

	// Set position
	void setPos(Position pos);

	// Set icon
	void setIcon(char& icon);

	// Get position
	Position getPos(void);

	// Get icon
	char getIcon(void);

	// Get display icon
	char getDispIcon(void);
};

#include "Hero.h" // Creature update Hero
