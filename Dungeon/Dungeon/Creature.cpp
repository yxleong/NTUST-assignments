/*****************************************************************//**
 * File: Creature.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 31, 2023
 * Description: This C++ program is to implement class Creature which inherited from class Object.
 *********************************************************************/
#include "Creature.h"

 /*****************************************************************//**
 * Intent: To construct the class Creature.
 * Pre: The variable sPower must be well-defined.
 * Post: The function initializes the variable sPower to be zero.
 *********************************************************************/
Creature::Creature() : sPower(0) {
	sHp = 100;
}

/*****************************************************************//**
 * Intent: To move Creature if the Hero is in Creature vision range.
 * Pre: The object hPos must be a valid object.
 * Post: The function updates the position of Creature when near with Hero.
 * \param hPos
 *********************************************************************/
void Creature::move(Position hPos)
{
	Position cPos;
	cPos.x = this->sPos.x;
	cPos.y = this->sPos.y;

	// check if the hero is in line of sight
	Position dir = { 0,0 };
	if (canSee(this->sPos, hPos, dir, 2.0))
	{
		// isNegX = 0
		// if (hPos.x - cPos.x) < 0
		// hPos at left of cPos
		bool isNegX = (hPos.x - cPos.x) < 0;

		// isNegY = 0
		// if (hPos.y - cPos.y) < 0
		// hPos at bottom of cPos
		bool isNegY = (hPos.y - cPos.y) < 0;

		// move toward the Hero
		if (isNegX) // if cPos at right
		{
			cPos.x--; // move left to reach hPos
		}
		else // if cPos at left
		{
			cPos.x++; // move right to reach hPos
		}

		if (isNegY) // if cPos at top
		{
			cPos.y--; // move down to reach hPos
		}
		else // if cPos at bottom
		{
			cPos.y++; // move up to reach hPos
		}
	}
	else // if Hero is out of sight
	{
		int direction = rand() % 4;

		// randomly move up, down, left, and right
		switch (direction)
		{
		case 0:
			cPos.y--;
			break;
		case 1:
			cPos.y++;
			break;
		case 2:
			cPos.x--;
			break;
		case 3:
			cPos.x++;
			break;
		default:
			break;
		}
	}

	// check if Creature destination position is valid
	if (isPositionValid(cPos))
	{
		// if yes, move the Creature to destination
		this->sPos.x = cPos.x;
		this->sPos.y = cPos.y;
	}
}

/*****************************************************************//**
 * Intent: To check if the Hero has higher attack power than Creature.
 * Pre: The object hero must be a valid object.
 * Post: The function updates the health point of Creature when attacked by Hero.
 * \param hero
 *********************************************************************/
void Creature::kill(Hero& hero) {

	Position hPos = hero.getPos();

	if (hPos == sPos && hero.getAttack() > sPower) {
		sHp -= hero.getAttack();
		// hero attack creature
	}

	if (sHp <= 0)
	{
		sHp = 0; // avoid negative health point
		this->sDispIcon = 'X'; // mark dead
	}
}

/*****************************************************************//**
 * Intent: To check if the Hero in vision range of Creature.
 * Pre: The object hero must be a valid object.
 * Post: The function updates the health point of Hero when attacked by Creature.
 * \param hero
 *********************************************************************/
void Creature::update(Hero& hero) {
	Position hPos = hero.getPos();

	Position dir;
	if (canSee(this->sPos, hPos, dir, 2.0)) { // -2 ~ 2
		std::cout << this->sIcon << " has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
		this->sDispIcon = '!';
	}
	else {
		std::cout << this->sIcon << " didn't find the Hero\n";
		this->sDispIcon = sIcon;
	}

	if (!(hPos != sPos)) {
		hero.damage(sPower);
	}
}