/*****************************************************************//**
 * File: Creature.h
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 27, 2023
 * Description: This C++ program is to implement class Creature which inherited from class Object.
*********************************************************************/
#pragma once
#include "Object.h"

class Creature : public Object {
public:
	int sPower;
public:
	// Default constructor
	Creature(void);

	// Update damage to hero
	virtual void update(Hero& hero); // to avoid additional detection
};