/*****************************************************************//**
* File: Hero.cpp
* Author:
*	Leong Yah Xuan
*	Tien Qingian
* Create Date: May 20, 2023
* Update Date: May 21, 2023
* Description: This C++ program is to implement class Hero which inherited from class Object.
*********************************************************************/
#include "Object.h"

void Hero::setHP(int hp) {
	this->hp = hp;
}

// Set level
void Hero::setLevel(int level) {
	this->sLevel = level;
}

// Set exp
void Hero::setExp(int exp) {
	this->sCurrentExp = exp;
}

// Set MaxExp
void Hero::SetMaxExp(int maxexp) {
	this->sMaxExp = maxexp;
}

int Hero::getHP() const {
	return this->hp;
}

// Get level
int Hero::getLevel(void) {
	return this->sLevel;
}

// Get Exp
int Hero::getExp(void) {
	return this->sCurrentExp;
}

// Get Max
int Hero::getMaxExp(void) {
	return this->sMaxExp;
}

// Incrementally move the elements 
void Hero::move(Position delta) {
	// Compute the next position
	Position next = this->sPos + delta;

	if (isPositionValid(next))
		this->sPos = next;
	else {
		std::cout << "Invalid location\n";
	}
}

// Calculate Gain of EXP
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

void Hero::damage(int points) {
	hp = hp - points;
	if (hp < 0)
		hp = 0;
}