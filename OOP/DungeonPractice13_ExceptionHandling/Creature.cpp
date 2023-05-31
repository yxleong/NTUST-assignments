/*****************************************************************//**
 * File: Creature.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 27, 2023
 * Description: This C++ program is to implement class Creature which inherited from class Object.
 *********************************************************************/
#include "Creature.h"

 /*****************************************************************//**
 * Intent: To construct the class Creature.
 * Pre: The variable sPower must be well-defined.
 * Post: The function initializes the variable sPower to be zero.
 *********************************************************************/
Creature::Creature() :sPower(0) {}

/*****************************************************************//**
 * Intent: To check if the Hero in vision range of Creature.
 * Pre: The object hero must be a valid object.
 * Post: The function updates the health point of Hero when attacked by Creature.
 * \param hero
 *********************************************************************/
void Creature::update(Hero& hero) {
	Position hPos = hero.getPos();

	Position dir;
	if (canSee(this->sPos, hPos, dir, 2.0)) { // -2 ~ 2
		std::cout << this->sIcon << " has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
		this->sDispIcon = '!';
	}
	else {
		std::cout << this->sIcon << " didn't find the Hero\n";
		this->sDispIcon = sIcon;
	}

	if (!(hPos != sPos)) {
		hero.damage(sPower);
	}
}