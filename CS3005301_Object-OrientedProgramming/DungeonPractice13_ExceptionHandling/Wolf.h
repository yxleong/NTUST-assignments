/*****************************************************************//**
 * File: Wolf.h
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 30, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement class Wolf which inherited from class Creature.
 *********************************************************************/
#pragma once
#include "Creature.h"

class Wolf : public Creature {
public:
	// Default constructor
	Wolf(void);

	// Wolves have a keen sense of smell and can detect hero twice in one round
	// first with normal detection and then with sensitive detection
	void update(Hero& hero) override;
};
