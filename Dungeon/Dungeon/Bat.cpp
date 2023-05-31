/*****************************************************************//**
 * File: Bat.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 30, 2023
 * Update Date: May 31, 2023
 * Description: This C++ program is to implement class Bat which inherited from class Creature.
 *********************************************************************/
#include "Bat.h"

 /*****************************************************************//**
 * Intent: To construct the class Bat.
 * Pre: The variables must be well-defined.
 * Post: The function initializes the variables of class Bat to specific values.
 *********************************************************************/
Bat::Bat(void) {
	this->sPos.x = 1;
	this->sPos.y = 1;
	this->sIcon = 'B';
	this->sDispIcon = 'B';

	this->sPower = 10;		// damage 10
}
