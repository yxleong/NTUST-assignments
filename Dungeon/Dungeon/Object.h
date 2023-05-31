/*****************************************************************//**
 * File: Object.h
 * Author:
 * 	Leong Yah Xuan
 * 	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 31, 2023
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
	int sHp;		// health point

public:
	// Default constructor
	Object(void);

	void setPos(Position pos); // Set position
	void setIcon(char& icon);  // Set icon
	void setHP(int hp);		   // Set hp

	Position getPos(void);	// Get position
	char getIcon(void);		// Get icon
	char getDispIcon(void); // Get display icon
	int getHP() const;		// Get hp
};

#include "Hero.h" // Creature update Hero