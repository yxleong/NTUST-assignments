/*****************************************************************//**
 * File: Hero.cpp
 * Author:
 *	Leong Yah Xuan
 * 	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 31, 2023
 * Description: This C++ program is to implement class Hero which inherited from class Object.
*********************************************************************/
#include "Hero.h"

/*****************************************************************//**
* Intent: To construct the class Hero.
* Pre: The variables must be well-defined.
* Post: The function initializes the variables of class Hero to specific values.
*********************************************************************/
Hero::Hero(void) {
	this->sPos.x = 0;
	this->sPos.y = 0;
	this->sIcon = 'H';
	this->sDispIcon = 'H';
	this->sHp = 100;

	this->sLevel = 1;
	this->sCurrentExp = 0;
	this->sMaxExp = 15;
	this->sAttack = 10;
}

/*****************************************************************//**
 * Intent: To set the constructor of the class Hero.
 * Pre: The variables must have values.
 * Post: The function initializes the variables of class Hero to given values.
 * \param pos
 * \param level
 * \param maxExp
 * \param currentExp
 * \param attack
 * \param icon
 * \param hp
 * \return
 *********************************************************************/
Hero::Hero(Position& pos, int level = 1, int maxExp = 15, int currentExp = 0, int attack = 10, char icon = 'H', int hp = 100) {
	this->sPos = pos;
	this->sIcon = icon;
	this->sDispIcon = icon;
	this->sHp = hp;

	this->sLevel = level;
	this->sCurrentExp = currentExp;
	this->sMaxExp = maxExp;
	this->sAttack = attack;
}

/*****************************************************************//**
 * Intent: To set the current level of Hero.
 * Pre: The variable level must have a value and level > 0.
 * Post: The function sets the current level of Hero.
 * \param level
 *********************************************************************/
void Hero::setLevel(int level) {
	this->sLevel = level;
}

/*****************************************************************//**
 * Intent: To set the experience of Hero.
 * Pre: The variable exp must have a value and exp > 0.
 * Post: The function sets the experience of Hero.
 * \param exp
 *********************************************************************/
void Hero::setExp(int exp) {
	this->sCurrentExp = exp;
}

/*****************************************************************//**
 * Intent: To set the maximum experience of Hero.
 * Pre: The variable maxexp must have a value and maxexp > 0.
 * Post: The function sets the maximum experience of Hero.
 * \param maxexp
 *********************************************************************/
void Hero::setMaxExp(int maxexp) {
	this->sMaxExp = maxexp;
}

/*****************************************************************//**
 * Intent: To set the attack power of Hero.
 * Pre: The variable power must have a value and power > 0.
 * Post: The function sets the attack power of Hero.
 * \param power
 *********************************************************************/
void Hero::setAttack(int power) {
	this->sAttack = power;
}

/*****************************************************************//**
 * Intent: To get the current level of Hero.
 * Pre: The variable sLevel must be well-defined.
 * Post: The function returns the current level of Hero.
 * \return
 *********************************************************************/
int Hero::getLevel(void) {
	return this->sLevel;
}

/*****************************************************************//**
 * Intent: To get the experience of Hero.
 * Pre: The variable sCurrentExp must be well-defined.
 * Post: The function returns the experience of Hero.
 * \return
 *********************************************************************/
int Hero::getExp(void) {
	return this->sCurrentExp;
}

/*****************************************************************//**
 * Intent: To get the maximum experience of Hero.
 * Pre: The variable sMaxExp must be well-defined.
 * Post: The function returns the maximum experience of Hero.
 * \return
 *********************************************************************/
int Hero::getMaxExp(void) {
	return this->sMaxExp;
}

/*****************************************************************//**
 * Intent: To get the attack power of Hero.
 * Pre: The variable sAttack must be well-defined.
 * Post: The function returns the attack power of Hero.
 * \return
 *********************************************************************/
int Hero::getAttack(void) {
	return this->sAttack;
}

/*****************************************************************//**
 * Intent: To control the movement of Hero.
 * Pre: The object delta must be a valid object.
 * Post: The function moves the Hero incrementally.
 * \param delta
 *********************************************************************/
void Hero::move(Position delta) {
	// Compute the next position
	Position next = this->sPos + delta;

	if (isPositionValid(next)) {
		this->sPos = next;
	}
	else {
		MyException errorMessage("Invalid location\n");
		throw errorMessage;
	}
}

/*****************************************************************//**
 * Intent: To calculate gain of experience of Hero.
 * Pre: The variable points must have a value and points > 0.
 * Post: The function increases the current level of Hero once experience enough.
 * \param points
 *********************************************************************/
void Hero::gainEXP(int points) {
	int number = points;
	while (number > 0) {
		if (sCurrentExp + number >= sMaxExp) { // level up
			number -= (sMaxExp - sCurrentExp);
			sCurrentExp = 0;
			sMaxExp = (int)((float)sMaxExp * 1.2f);
			sLevel++;
		}
		else {
			sCurrentExp += number;
			number = 0;
		}
	}
}

/*****************************************************************//**
 * Intent: To calculate gain of health point of Hero.
 * Pre: The variable heal must have a value and heal > 0.
 * Post: The function increases the health point of Hero gained.
 * \param heal
 *********************************************************************/
void Hero::gainHP(int heal) {
	sHp += heal;

	if (sHp >= 100)
	{
		sHp = 100;
	}
}

/*****************************************************************//**
 * Intent: To calculate gain of attack power of Hero.
 * Pre: The variable power must have a value and power > 0.
 * Post: The function increases the attack power of Hero gained.
 * \param power
 *********************************************************************/
void Hero::gainAttack(int power) {
	sAttack += power;
}

/*****************************************************************//**
 * Intent: To calculate the damage of Hero by Creature.
 * Pre: The variable points must have a value and points > 0.
 * Post: The function decrease the health point of Hero.
 * \param points
 *********************************************************************/
void Hero::damage(int points) {

	// if hero attack power lower than creature attack
	if (sAttack <= points) {
		sHp -= points; // hero be attacked
	}
	else { // if hero attack power higher than creature
		sHp -= points / 2; // hero be attacked by half attack from creature
	}

	// to avoid negative health point
	if (sHp < 0) {
		sHp = 0;
	}
}