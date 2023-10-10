/*****************************************************************//**
 * File : Position.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 16, 2023
 * Update Date : April 19, 2023
 * Description : This C++ program implements tile-matching game which named Shisensho.
 *********************************************************************/
#include "Position.h"

 /**
 * Intent : To assign the coordinates of a position.
 * Pre : The variables x,y must have a value and x,y > 0.
 * Post : The function assigns the coordinates of a position.
 * \param x
 * \param y
 */
Position::Position(int x, int y)
{
	this->xPos = x;
	this->yPos = y;
}

/**
* Intent : To check whether the position is in range.
* Pre : The variable size must have a value and size > 0.
* Post : The function returns the boolean value which indicates whether the position is in range.
* \param size
* \return
*/
bool Position::isInRange(int size) const
{
	if (xPos < 0 || xPos >= size)
	{
		return false;
	}

	if (yPos < 0 || yPos >= size)
	{
		return false;
	}

	return true;
}

/**
* Intent : To read a Position from an input stream.
* Pre : The input stream must be in a good state and formatted correctly.
* Post : The function updates the Position object with the x and y coordinates read from the input stream.
* \param is
* \param pos
* \return
*/
std::istream& operator>>(std::istream& is, Position& pos)
{
	is >> pos.xPos >> pos.yPos;

	pos.xPos++;
	pos.yPos++;

	return is;
}

/**
* Intent : To overload the equality operator to compare two Position objects.
* Pre : The variables pos1,pos2 must be valid Position objects.
* Post : The function returns the boolean value which indicates whether pos1,pos2 have the same x,y values.
* \param pos1
* \param pos2
* \return
*/
bool operator==(const Position& pos1, const Position& pos2)
{
	if (pos1.xPos == pos2.xPos && pos1.yPos == pos2.yPos)
	{
		return true;
	}

	return false;
}

/**
* Intent : To assign a position to another position.
* Pre : The variable pos must be a valid Position object.
* Post : The function returns the reference to the modified Position object.
* \param pos
* \return
*/
Position Position::operator=(const Position& pos)
{
	return Position(pos.xPos, pos.yPos);
}

/**
* Intent : To add two Position objects.
* Pre : The variables pos1,pos2 must be valid Position objects.
* Post : The function returns the sum of the two Position objects as a new Position object.
* \param pos1
* \param pos2
* \return
*/
Position operator+(const Position& pos1, const Position& pos2)
{
	return Position(pos1.xPos + pos2.xPos, pos1.yPos + pos2.yPos);
}