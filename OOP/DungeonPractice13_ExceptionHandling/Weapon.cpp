/*****************************************************************//**
 * File: Weapon.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 27, 2023
 * Update Date: May 30, 2023
 * Description:This C++ program is to implement class Weapon which inherited from class Item.
 *********************************************************************/
#include "Weapon.h"

 /*****************************************************************//**
 * Intent: To construct the class Weapon.
 * Pre: The variables must be well-defined.
 * Post: The function initializes the variables of class Weapon to specific values.
 *********************************************************************/
Weapon::Weapon(void) {
	this->sPos.x = 0;
	this->sPos.y = 0;
	this->sIcon = ')';
	this->sDispIcon = ')';
	this->sAward = 20;		// attack power 2
}

/*****************************************************************//**
 * Intent: To set the constructor of the class Weapon.
 * Pre: The variables x,y must have values.
 * Post: The function initializes the variables of class Weapon.
 * \param x
 * \param y
 *********************************************************************/
Weapon::Weapon(int x, int y) {
	this->sPos.x = x;
	this->sPos.y = y;
	this->sIcon = ')';
	this->sDispIcon = ')';
	this->sAward = 20;		// attack power 2
}

/*****************************************************************//**
 * Intent: To update the attack power of Hero.
 * Pre: The object hero must be a valid object.
 * Post: The function increases the attack power of Hero when got the weapon.
 * \param hero
 *********************************************************************/
void Weapon::update(Hero& hero) const {
	if (hero.getPos().x == sPos.x && hero.getPos().y == sPos.y) {
		hero.gainAttack(sAward);
	}
}