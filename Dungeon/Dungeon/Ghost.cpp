/*****************************************************************//**
 * File: Ghost.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 30, 2023
 * Update Date: May 31, 2023
 * Description: This C++ program is to implement class Ghost which inherited from class Creature.
 *********************************************************************/
#include "Ghost.h"

 /*****************************************************************//**
 * Intent: To construct the class Ghost.
 * Pre: The variables must be well-defined.
 * Post: The function initializes the variables of class Ghost to specific values.
 *********************************************************************/
Ghost::Ghost(void) {
	this->sPos.x = 3;
	this->sPos.y = 3;
	this->sIcon = 'G';
	this->sDispIcon = 'G';

	this->sPower = 5;		// damage 5
}