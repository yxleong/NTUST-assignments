/*****************************************************************//**
 * File: Potion.cpp
* Author:
*	Leong Yah Xuan
*	Tien Qingian
* Create Date: May 27, 2023
* Update Date: May 27, 2023
* Description: This C++ program is to implement class Potion which inherited from class Item.
*********************************************************************/
#include "Item.h"

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