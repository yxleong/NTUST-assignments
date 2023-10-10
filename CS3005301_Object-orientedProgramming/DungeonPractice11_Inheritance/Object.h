/*****************************************************************//**
* File: Object.h
* Author:
*	Leong Yah Xuan
*	Tien Qingian
* Create Date: May 20, 2023
* Update Date: May 21, 2023
* Description: This C++ program is to implement class Object.
*********************************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Position.h" // Position
#include "main.h"	  // isPositionValid
using namespace std;

class Object {
public:
	Position sPos;
	char sIcon = 0;
	char sDispIcon = 0; // for canSee
public:
	// Set position
	void setPos(Position pos);
	void setPos(int x, int y);

	// Set icon
	void setIcon(char& icon);

	// Get position
	Position getPos(void);

	// Get Icon
	char getIcon(void);
};

class Hero : public Object {
private:
	int	hp;				// health point
	int	sLevel = 1;		// level
	int	sCurrentExp;	// current experience hero has
	int	sMaxExp;		// level update experience
public:
	// Default constructor
	Hero() {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sLevel = 1;
		this->sCurrentExp = 0;
		this->sMaxExp = 15;
		this->sIcon = 'H';
		this->sDispIcon = 'H';
		this->hp = 100;
	}
	// Setting constructor
	Hero(int x, int y, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100) {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sIcon = icon;
		this->sDispIcon = icon;
		this->hp = hp;
	}
	// Setting constructor
	Hero(Position& pos, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100) {
		this->sPos = pos;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sIcon = icon;
		this->sDispIcon = icon;
		this->hp = hp;
	}

	void setHP(int hp);			 // Set hp
	void setLevel(int level);	 // Set level
	void setExp(int exp);		 // Set exp
	void SetMaxExp(int maxexp);  // Set MaxExp

	int getHP() const;		// Get hp
	int getLevel(void);		// Get level
	int getExp(void);		// Get Exp
	int getMaxExp(void);	// Get Max

	// Incrementally move the elements 
	void move(Position delta);

	// Calculate Gain of EXP
	void gainEXP(int points);

	// Calculate damage from creature
	void damage(int points);
};

class Trigger : public Object {
private:
	int sExp;
public:
	// Default constructor
	Trigger() : sExp(10) {
		sIcon = 'T';
		sDispIcon = 'T';
	}

	// Setting constructor
	Trigger(int x, int y) : sExp(10) {
		sPos.x = x;
		sPos.y = y;
		sIcon = 'T';
		sDispIcon = 'T';
	}

	// Copy constructor
	Trigger(const Trigger& ref);

	// Update exp of hero
	void update(Hero& hero) const;

	// Get exp of Trigger
	int getExpAmount() const;
};