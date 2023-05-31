/*****************************************************************//**
 * File: Object.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 31, 2023
 * Description: This C++ program is to implement class Object.
 *********************************************************************/
#include "Object.h"

 /*****************************************************************//**
  * Intent: To construct the class Object.
  * Pre: The variables sPos,sIcon,sDispIcon must be well-defined.
  * Post: The function initializes the variable sPower to be zero.
  *********************************************************************/
Object::Object() :sPos({ 0,0 }), sIcon(0), sDispIcon(0), sHp(0) {}

/*****************************************************************//**
 * Intent: To set the position of the object.
 * Pre: The object pos must have a value.
 * Post: The function sets the position of the object.
 * \param pos
 *********************************************************************/
void Object::setPos(Position pos)
{
	this->sPos = pos;
}

/*****************************************************************//**
 * Intent: To set the icon of the object.
 * Pre: The variable icon must have a value.
 * Post: The function sets the icon of the object.
 * \param icon
 *********************************************************************/
void Object::setIcon(char& icon)
{
	this->sIcon = icon;
}

/*****************************************************************//**
 * Intent: To set the health point of Object.
 * Pre: The variable hp must have a value and hp > 0.
 * Post: The function sets the health point of Object.
 * \param hp
 *********************************************************************/
void Object::setHP(int hp) {
	this->sHp = hp;
}

/*****************************************************************//**
 * Intent: To get the position of the object.
 * Pre: The object sPos must be well-defined.
 * Post: The function returns the position of the object.
 * \return
 *********************************************************************/
Position Object::getPos(void)
{
	return this->sPos;
}

/*****************************************************************//**
 * Intent: To get the icon of the object.
 * Pre: The variable sIcon must be well-defined.
 * Post: The function returns the icon of the object.
 * \return
 *********************************************************************/
char Object::getIcon(void)
{
	return this->sIcon;
}

/*****************************************************************//**
 * Intent: To get the current icon of the object.
 * Pre: The variable sDispIcon must be well-defined.
 * Post: The function returns the current icon of the object.
 * \return
 *********************************************************************/
char Object::getDispIcon(void)
{
	// show in map
	return this->sDispIcon;
}

/*****************************************************************//**
 * Intent: To get the health point of Object.
 * Pre: The variable sHp must be well-defined.
 * Post: The function returns the health point of Object.
 * \return
 *********************************************************************/
int Object::getHP() const {
	return this->sHp;
}