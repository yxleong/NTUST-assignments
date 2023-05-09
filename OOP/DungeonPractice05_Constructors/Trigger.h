/*****************************************************************//**
 * File: Trigger.h
 * Author:
 * 	Leong Yah Xuan
 * 	B11015042
 * Create Date: March 28, 2023
 * Update Date: March 28, 2023
 * Description: This C++ program implements class Trigger.
 *********************************************************************/

#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"

 //************************************************************
 // Trigger Class
 //************************************************************

class Trigger {
	// Implement Trigger Class
	/*Please implement your code here*/

private:
	Position	sPos;			// Trigger location
	char sIcon = 'T';	// Trigger icon
	int sExp;     // exp hero can get

public:
	// Default constructor
	Trigger() {
		this->sPos.x = 5;
		this->sPos.y = 5;
		this->sIcon = 'T';
		this->sExp = 10;
	};
	// Setting constructor
	Trigger(int x, int y, int exp = 10) {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sExp = exp;
	};

	/**
	* Intent : To get the position of Trigger.
	* Pre : -
	* Post : The function returns the position of Trigger.
	* \return
	*/ // Get position
	Position getPos(void) { return this->sPos; }

	/**
	* Intent : To get the icon of Trigger.
	* Pre : -
	* Post : The function returns the icon of Trigger.
	* \return
	*/ // Get Icon
	char getIcon(void) { return this->sIcon; }

	/**
	* Intent : To get the exp of Trigger.
	* Pre : -
	* Post : The function returns the exp of Trigger.
	* \return
	*/ // Get Exp
	int getExpAmount(void) { return this->sExp; }

	/**
	* Intent : To update the exp when Hero go through Trigger.
	* Pre : The object hero must have a valid pos.
	* Post : The function call gainEXP to update hero exp.
	* \param hero
	*/
	void update(Hero& hero) {
		// declare the variable needed
		Position hPos = hero.getPos();

		// if Hero go through Trigger
		if (hPos.x == sPos.x && hPos.y == sPos.y) {

			// call function gainEXP in class Hero
			// to add on the hero exp which defined in class Trigger
			hero.gainEXP(sExp);
		}
	}

	/************************************************************************/
};

