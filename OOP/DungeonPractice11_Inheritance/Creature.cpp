/*****************************************************************//**
* File: Creature.cpp
* Author:
*	Leong Yah Xuan
*	Tien Qingian
* Create Date: May 20, 2023
* Update Date: May 21, 2023
* Description: This C++ program is to implement class Creature which inherited from class Object.
*********************************************************************/
#include "Creature.h"

void Creature::update(Hero& hero) {
	Position hPos = hero.getPos();

	Position dir;
	if (canSee(this->sPos, hPos, dir)) {
		std::cout << sDispIcon << " has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
		this->sIcon = '!';
	}
	else {
		std::cout << sDispIcon << " didn't find the Hero\n";
		this->sIcon = this->sDispIcon;
	}

	if (!(hPos != sPos)) {
		hero.damage(sPower);
	}
}