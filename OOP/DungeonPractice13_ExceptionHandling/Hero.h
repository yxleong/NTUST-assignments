/*****************************************************************//**
 * File: Hero.h
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement class Hero which inherited from class Object.
*********************************************************************/
#pragma once
#include "Object.h"
#include "MyException.h"

class Hero : public Object {
private:
	int sHp;			// health point
	int	sLevel;			// level
	int	sCurrentExp;	// current experience hero has
	int	sMaxExp;		// level update experience
	int sAttack;		// attack power
public:
	// Default constructor
	Hero(void);
	// Setting constructor
	Hero(Position& pos, int level, int maxExp, int currentExp, int attack, char icon, int hp);

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