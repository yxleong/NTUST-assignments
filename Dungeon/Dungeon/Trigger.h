/*****************************************************************//**
 * File: Trigger.h
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 30, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement class Trigger which inherited from class Item.
 *********************************************************************/
#pragma once
#include "Item.h"

class Trigger : public Item {
public:
	// Default constructor
	Trigger(void);
	// Setting constructor
	Trigger(int x, int y);
};