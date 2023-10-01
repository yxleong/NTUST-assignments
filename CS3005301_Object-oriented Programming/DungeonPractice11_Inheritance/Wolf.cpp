/*****************************************************************//**
 * File: Wolf.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 21, 2023
 * Description:This C++ program is to implement class Wolf which inherited from class Creature.
 *********************************************************************/
#include "Creature.h"

 /*****************************************************************//**
* Intent: To detect hero if near to wolf or not.
* Pre: The object hero must be valid.
* Post: The function updates the hero health points when attacked by wolf.
* \param hero
*********************************************************************/
void Wolf::updateWolf(Hero& hero) {
	Position hPos = hero.getPos();

	Position dir;
	if (canSee(this->sPos, hPos, dir)) {
		std::cout << "Wolf has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
		this->sIcon = '!';
	}
	else {
		std::cout << "Wolf didn't find the Hero\n";
		this->sIcon = this->sDispIcon;
	}

	if (hPos == sPos) {
		hero.damage(sPower);
	}
}
