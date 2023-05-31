/*****************************************************************//**
 * File: Potion.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 27, 2023
 * Update Date: May 31, 2023
 * Description: This C++ program is to implement class Potion which inherited from class Item.
 *********************************************************************/
#include "Potion.h"

 /*****************************************************************//**
 * Intent: To construct the class Potion.
 * Pre: The variables must be well-defined.
 * Post: The function initializes the variables of class Potion to specific values.
 *********************************************************************/
Potion::Potion(void) {
	this->sPos.x = 0;
	this->sPos.y = 0;
	this->sIcon = '&';
	this->sDispIcon = '&';

	this->sAward = 5;		// HP 5
}

/*****************************************************************//**
 * Intent: To set the constructor of the class Potion.
 * Pre: The variables x,y must have values.
 * Post: The function initializes the variables of class Potion.
 * \param x
 * \param y
 *********************************************************************/
Potion::Potion(int x, int y) {
	this->sPos.x = x;
	this->sPos.y = y;
	this->sIcon = '&';
	this->sDispIcon = '&';

	this->sAward = 5;
}

/*****************************************************************//**
 * Intent: To update the health point of Hero.
 * Pre: The object hero must be a valid object.
 * Post: The function increases the health point of Hero when got the potion.
 * \param hero
 *********************************************************************/
void Potion::update(Hero& hero) const {
	if (hero.getPos().x == sPos.x && hero.getPos().y == sPos.y) {
		hero.gainHP(sAward);
	}
}