/*****************************************************************//**
 * File: Weapon.h
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 30, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement class Weapon which inherited from class Item.
 *********************************************************************/
#pragma once
#include "Item.h"

class Weapon : public Item {
public:
	// Default constructor
	Weapon(void);
	// Setting constructor
	Weapon(int x, int y);

	// Update attack power of hero
	void update(Hero& hero) const override;
};