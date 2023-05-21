/*****************************************************************//**
 * File: Object.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 21, 2023
 * Description: This C++ program is to implement class Object.
 *********************************************************************/
#include "Object.h"

 // Set position
void Object::setPos(Position pos)
{
	this->sPos = pos;
}
void Object::setPos(int x, int y)
{
	this->sPos = Position(x, y);
}

// Set icon
void Object::setIcon(char& icon)
{
	this->sIcon = icon;
}

// Get position
Position Object::getPos(void)
{
	return this->sPos;
}

// Get Icon
char Object::getIcon(void)
{
	return this->sIcon;
}
