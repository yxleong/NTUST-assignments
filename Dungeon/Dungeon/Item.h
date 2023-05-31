/*****************************************************************//**
 * File: Item.h
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 27, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement class Item which inherited from class Object.
*********************************************************************/
#pragma once
#include "Object.h"

class Item : public Object {
public:
	int sAward;
public:
	// Default constructor
	Item(void);

	// Get EXP amount
	int getExpAmount() const;

	// Update EXP of hero
	virtual void update(Hero& hero) const;
};