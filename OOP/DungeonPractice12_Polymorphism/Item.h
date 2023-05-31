/*****************************************************************//**
 * File: Item.h
* Author:
*	Leong Yah Xuan
*	Tien Qingian
* Create Date: May 27, 2023
* Update Date: May 27, 2023
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

class Trigger : public Item {
public:
	// Default constructor
	Trigger(void) {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sIcon = 'T';
		this->sDispIcon = 'T';
		this->sAward = 10;		// EXP 10
	}

	// Setting constructor
	Trigger(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = 'T';
		this->sDispIcon = 'T';
		this->sAward = 10;		// EXP 10
	}
};

class Weapon : public Item {
public:
	// Default constructor
	Weapon(void) {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sIcon = ')';
		this->sDispIcon = ')';
		this->sAward = 20;		// attack power 2
	}

	// Setting constructor
	Weapon(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = ')';
		this->sDispIcon = ')';
		this->sAward = 20;		// attack power 2
	}

	// Update attack power of hero
	void update(Hero& hero) const override;
};

class Potion : public Item {
public:
	// Default constructor
	Potion(void) {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sIcon = '&';
		this->sDispIcon = '&';
		this->sAward = 5;		// HP 5
	}

	// Setting constructor
	Potion(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = '&';
		this->sDispIcon = '&';
		this->sAward = 5;
	}

	// Update health point of hero
	void update(Hero& hero) const override;
};
