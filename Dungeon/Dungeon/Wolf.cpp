/*****************************************************************//**
 * File: Wolf.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 31, 2023
 * Description:This C++ program is to implement class Wolf which inherited from class Creature.
 *********************************************************************/
#include "Wolf.h"

 /*****************************************************************//**
 * Intent: To construct the class Wolf.
 * Pre: The variables must be well-defined.
 * Post: The function initializes the variables of class Wolf to specific values.
 *********************************************************************/
Wolf::Wolf(void) {
	this->sPos.x = 2;
	this->sPos.y = 2;
	this->sIcon = 'W';
	this->sDispIcon = 'W';

	this->sPower = 20;		// damage 20
}

/*****************************************************************//**
* Intent: To detect hero if near to wolf or not.
* Pre: The object hero must be a valid object.
* Post: The function updates the hero health points when attacked by wolf.
* \param hero
*********************************************************************/
void Wolf::update(Hero& hero) {
	Position hPos = hero.getPos();

	Position dir;
	if (canSee(this->sPos, hPos, dir, 8.0)) { // -8 ~ 8
		std::cout << this->sIcon << " has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
		this->sDispIcon = '!';
	}
	else {
		std::cout << this->sIcon << " didn't find the Hero\n";
		this->sDispIcon = sIcon;
	}

	if (hPos == sPos) {
		hero.damage(sPower);
	}
}
