/*****************************************************************//**
 * File: Weapon.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 27, 2023
 * Update Date: May 27, 2023
 * Description:This C++ program is to implement class Weapon which inherited from class Item.
 *********************************************************************/
#include "Item.h"

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