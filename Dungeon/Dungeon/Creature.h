/*****************************************************************//**
 * File: Creature.h
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 31, 2023
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

	// Creature move according to whether it saw the Hero or not
	void move(Position hPos);

	// Update damage from hero
	void kill(Hero& hero);

	// Update damage to hero
	virtual void update(Hero& hero); // to avoid additional detection
};