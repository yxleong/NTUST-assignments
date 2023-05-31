/*****************************************************************//**
 * File: Trigger.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 30, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement class Trigger which inherited from class Item.
 *********************************************************************/
#include "Trigger.h"

 /*****************************************************************//**
 * Intent: To construct the class Trigger.
 * Pre: The variables must be well-defined.
 * Post: The function initializes the variables of class Trigger to specific values.
 *********************************************************************/
Trigger::Trigger(void) {
	this->sPos.x = 0;
	this->sPos.y = 0;
	this->sIcon = 'T';
	this->sDispIcon = 'T';
	this->sAward = 10;		// EXP 10
}

/*****************************************************************//**
 * Intent: To set the constructor of the class Trigger.
 * Pre: The variables x,y must have values.
 * Post: The function initializes the variables of class Trigger.
 * \param x
 * \param y
 *********************************************************************/
Trigger::Trigger(int x, int y) {
	this->sPos.x = x;
	this->sPos.y = y;
	this->sIcon = 'T';
	this->sDispIcon = 'T';
	this->sAward = 10;		// EXP 10
}
