/*****************************************************************//**
 * File: Trigger.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 21, 2023
 * Description: This C++ program is to implement class Trigger which inherited from class Object.
 *********************************************************************/
#include "Object.h"

Trigger::Trigger(const Trigger& ref) {
	*this = ref;
}

void Trigger::update(Hero& hero) const {
	if (hero.getPos().x == sPos.x && hero.getPos().y == sPos.y) {
		hero.gainEXP(sExp);
	}
}

int Trigger::getExpAmount() const {
	return this->sExp;
}
