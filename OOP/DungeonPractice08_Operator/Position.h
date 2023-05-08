/*****************************************************************//**
 * File: Position.h
 * Author:
 *	Leong Yah Xuan
 *	B11015042
 * Create Date: April 25, 2023
 * Update Date: April 25, 2023
 * Description: This C++ program implements operator overloading for element position.
 *********************************************************************/

#pragma once
 //************************************************************
 // The location in the board
 //************************************************************
class Position {
public:
	int x, y; // X, y Coordinate

	Position() : x(0), y(0) {}
	Position(int x, int y) : x(x), y(y) {}
	Position(const Position& ref) { *this = ref; }

	// Operator overloading
	/*Please implement your code here*/

	/**
	* Intent : To calculate the addition of two Position.
	* Pre : The object pos must have valid x,y values.
	* Post : The function returns the sum of the x,y values of two Position.
	* \param pos
	* \return
	*/
	const Position operator +(const Position& pos) const
	{
		// assign current position
		Position result = *this;

		// calculate for new position after movement
		result.x += pos.x;
		result.y += pos.y;

		// return a new position
		return result;
	}

	/**
	* Intent : To add current Position by another Position pos.
	* Pre : The object pos must have valid x,y values.
	* Post : The function returns the current Position after the summation.
	* \param pos
	* \return
	*/
	const Position operator +=(const Position& pos)
	{
		// move current position based on movement given
		this->x += pos.x;
		this->y += pos.y;

		// return current position after movement
		return *this;
	}

	/**
	* Intent : To calculate the difference of two Position.
	* Pre : The object pos must have valid x,y values.
	* Post : The function returns the subtraction of the x,y values of two Position.
	* \param pos
	* \return
	*/
	const Position operator -(const Position& pos) const
	{
		// assign current position
		Position result = *this;

		// calculate for new position after movement
		result.x -= pos.x;
		result.y -= pos.y;

		// return a new position
		return result;
	}

	/**
	* Intent : To deduct current Position by another Position pos.
	* Pre : The object pos must have valid x,y values.
	* Post : The function returns the current Position after the subtraction.
	* \param pos
	* \return
	*/
	const Position operator -=(const Position& pos)
	{
		// move current position based on movement given
		this->x -= pos.x;
		this->y -= pos.y;

		// return current position after movement
		return *this;
	}

	/**
	* Intent : To calculate the multiplication of a Position with a constant.
	* Pre : The value constant must have a value.
	* Post : The function returns the Position with x,y values multiple with constant each.
	* \param pos
	* \return
	*/
	const Position operator *(int constant) const
	{
		// assign current position
		Position result = *this;

		// calculate for new position after movement
		result.x *= constant;
		result.y *= constant;

		// return a new position
		return result;
	}

	/**
	* Intent : To compares whether two Position objects are equal.
	* Pre : The object pos must have valid x,y values.
	* Post : The function returns the boolean value of two Position objects equality.
	* \param pos
	* \return
	*/
	bool operator ==(const Position& pos) const // const at the end : does not modify the current object
	{
		// if x-coordinate and y coordinate of both position are same, return true
		return (this->x == pos.x && this->y == pos.y);
	}

	/**
	* Intent : To compares whether two Position objects are not equal.
	* Pre : The object pos must have valid x,y values.
	* Post : The function returns the boolean value of two Position objects inequality.
	* \param pos
	* \return
	*/
	bool operator !=(const Position& pos) const
	{
		// if x-coordinate and y-coordinate of both position are not same, return true
		return !(*this == pos);
	}

	/************************************************************************/
};
