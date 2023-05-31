/*****************************************************************//**
 * File: Potion.h
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 30, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement class Potion which inherited from class Creature.
 *********************************************************************/
#pragma once
#include "Item.h"

class Potion : public Item {
public:
	// Default constructor
	Potion(void);
	// Setting constructor
	Potion(int x, int y);

	// Update health point of hero
	void update(Hero& hero) const override;
};

