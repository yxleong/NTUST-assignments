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

class Bat : public Creature {
public:
	// Default constructor
	Bat(void) {
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = 'B';
		this->sDispIcon = 'B';
		this->sPower = 10;		// damage 10
	}
};

class Wolf : public Creature {
public:
	// Default constructor
	Wolf(void) {
		this->sPos.x = 2;
		this->sPos.y = 2;
		this->sIcon = 'W';
		this->sDispIcon = 'W';
		this->sPower = 20;		// damage 20
	}

	// Wolves have a keen sense of smell and can detect hero twice in one round
	// first with normal detection and then with sensitive detection
	void update(Hero& hero) override;
};

class Ghost : public Creature {
public:
	// Default constructor
	Ghost(void) {
		this->sPos.x = 3;
		this->sPos.y = 3;
		this->sIcon = 'G';
		this->sDispIcon = 'G';
		this->sPower = 5;		// damage 5
	}
};