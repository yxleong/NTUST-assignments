/*****************************************************************//**
 * File: Item.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 27, 2023
 * Update Date: May 27, 2023
 * Description: This C++ program is to implement class Item which inherited from class Object.
*********************************************************************/
#include "Item.h"

/*****************************************************************//**
 * Intent: To construct the class Item.
 * Pre: The variable sAward must be well-defined.
 * Post: The function initializes the variable sAward to be zero.
 *********************************************************************/
Item::Item(void) :sAward(0) {}

/*****************************************************************//**
 * Intent: To get the award amount.
 * Pre: The variable sAward must have a value and sAward > 0.
 * Post: The function returns the award amount of Item.
 * \return
 *********************************************************************/
int Item::getExpAmount() const {
	return this->sAward;
}

/*****************************************************************//**
 * Intent: To update the experience of Hero.
 * Pre: The object hero must be a valid object.
 * Post: The function increases the experience of Hero when reach Trigger.
 * \param hero
 *********************************************************************/
void Item::update(Hero& hero) const {
	if (hero.getPos().x == sPos.x && hero.getPos().y == sPos.y) {
		hero.gainEXP(sAward);
	}
}