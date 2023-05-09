/*****************************************************************//**
 * File: Hero.h
 * Author:
 * 	Leong Yah Xuan
 * 	B11015042
 * Create Date: March 28, 2023
 * Update Date: March 28, 2023
 * Description: This C++ program implements some functions of Hero.
 *********************************************************************/

#pragma once
#include <string>
#include "Position.h"
#include "main.h"

 //************************************************************
 // Hero Class, only has requirement part for example
 //************************************************************

class Hero {

private:
	Position	sPos;			// Hero location
	char sIcon = 'H';	// Hero icon
	int			hp;
	int			sLevel = 1;     // Level
	int			sMaxExp;		// Level update experience
	int			sCurrentExp;	// current exp hero has

public:
	// Default constructor
	Hero() {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sLevel = 1;
		this->sCurrentExp = 0;
		this->sMaxExp = 15;
		this->sIcon = 'H';
		this->hp = 100;
	};
	// Setting constructor
	Hero(int x, int y, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100) {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sIcon = icon;
		this->hp = hp;
	};

	// Setting constructor
	Hero(Position& pos, int level = 1, int maxExp = 15, int currentExp = 0, char icon = 'H', int hp = 100) {
		this->sPos = pos;
		this->sLevel = level;
		this->sCurrentExp = currentExp;
		this->sMaxExp = maxExp;
		this->sIcon = icon;
		this->hp = hp;
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Set level
	void setLevel(int level) { this->sLevel = level; }

	// Set exp
	void setExp(int exp) { this->sCurrentExp = exp; }

	// Set MaxExp
	void SetMaxExp(int maxexp) { this->sMaxExp = maxexp; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Get level
	int getLevel(void) { return this->sLevel; }

	// Get Exp
	int getExp(void) { return this->sCurrentExp; }

	// Get Max
	int getMaxExp(void) { return this->sMaxExp; }

	int getHP() const { return this->hp; }

	// Incrementally move the elements 
	void move(int x, int y) {
		// Compute the next position
		Position next;
		next.x = this->sPos.x + x;
		next.y = this->sPos.y + y;

		if (isPositionValid(next))
			this->sPos = next;
		else {
			std::cout << "Invalid location\n";
		}
	}

	/**
	* Intent : To calculate the gain of EXP.
	* Pre : The variable points must have a value and points > 0.
	* Post : The function upgrades Hero by increasing experience through Trigger.
	* \param points
	*/ // Calculate Gain of EXP
	void gainEXP(int points) {
		// Implement Gain of EXP
		/*Please implement your code here*/

		// add one the current Exp of Hero by points
		this->sCurrentExp += points;

		// if the current Exp of Hero >= maximum Exp for level up
		if (this->sCurrentExp >= sMaxExp)
		{
			// increase the level
			sLevel++;

			// deduct the Exp of Hero used for level up
			this->sCurrentExp -= sMaxExp;
		}

		/************************************************************************/
	}

	/**
	* Intent : To calculate the damage done by Creature to Hero.
	* Pre : The variable points must have a value and points > 0.
	* Post : The function deducts blood of Hero when encountering Creature.
	* \param points
	*/
	void damage(int points) {
		// Implement Damage done to Hero
		/*Please implement your code here*/

		// deduct the hp of Hero by points
		this->hp -= points;

		// if the hp of Hero <= 0
		if (this->hp <= 0)
		{
			// output that Hero died
			std::cout << "Hero is died and is being resurrected..." << std::endl;

			// let the hp of Hero back to 100 to avoid negative hp
			this->hp = 100;
		}

		/************************************************************************/
	}
};
