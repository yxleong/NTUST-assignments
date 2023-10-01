/*****************************************************************//**
 * File: Hero.h
* Author:
*	Leong Yah Xuan
*	Tien Qingian
* Create Date: May 20, 2023
* Update Date: May 27, 2023
* Description: This C++ program is to implement class Hero which inherited from class Object.
*********************************************************************/
#pragma once
#include "Object.h"

class Hero : public Object {
private:
	int sHp;			// health point
	int	sLevel;			// level
	int	sCurrentExp;	// current experience hero has
	int	sMaxExp;		// level update experience
	int sAttack;		// attack power
public:
	// Default constructor
	Hero(void) {
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

	// Setting constructor
	Hero(Position& pos, int level = 1, int maxExp = 15, int currentExp = 0, int attack = 10, char icon = 'H', int hp = 100) {
		this->sPos = pos;
		this->sIcon = icon;
		this->sDispIcon = icon;

		this->sHp = hp;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sAttack = attack;
	}

	void setLevel(int level);	 // Set level
	void setExp(int exp);		 // Set exp
	void setMaxExp(int maxexp);  // Set MaxExp
	void setAttack(int attack);  // Set attack power

	int getLevel(void);			// Get level
	int getExp(void);			// Get Exp
	int getMaxExp(void);		// Get Max
	int getAttack(void);		// Get attack power

	void setHP(int hp);			// Set hp
	int getHP() const;			// Get hp

	// Incrementally move the elements 
	void move(Position delta);

	// Calculate Gain of award
	void gainEXP(int points);
	void gainHP(int heal);
	void gainAttack(int power);

	// Calculate damage from creature
	void damage(int points);
};