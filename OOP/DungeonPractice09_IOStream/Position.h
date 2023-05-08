/*****************************************************************//**
 * File: main.cpp
 * Author:
 *	Leong Yah Xuan
 *	B11015042
 * Create Date: May 6, 2023
 * Update Date: May 6, 2023
 * Description: This C++ program demonstrates the implementation of IO Stream.
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
	Position operator+(const Position& rhs) const {
		return Position(x + rhs.x, y + rhs.y);
	}
	Position& operator+=(const Position& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Position operator-(const Position& rhs) const {
		return Position(x - rhs.x, y - rhs.y);
	}
	Position& operator-=(const Position& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	Position operator*(int scale) const {
		return Position(x * scale, y * scale);
	}
	bool operator==(const Position& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator!=(const Position& rhs) const {
		return !(*this == rhs);
	}

	/*Please implement your code here*/

	/*****************************************************************//**
	 * Intent: To allow a Position object to be output to an output stream.
	 * Pre: The object pos must have be valid.
	 * Post: The function returns an output stream containing the string representation of the Position object.
	 * \param os
	 * \param pos
	 * \return
	 *********************************************************************/
	friend std::ostream& operator<<(std::ostream& os, const Position& pos) {
		os << pos.x << " " << pos.y;
		return os;
	}

	/*****************************************************************//**
	 * Intent: To allow a Position object can be input from an input stream.
	 * Pre: The object pos must have be valid.
	 * Post: The function returns an input stream containing the string representation of the Position object.
	 * \param is
	 * \param pos
	 * \return
	 *********************************************************************/
	friend std::istream& operator>>(std::istream& is, Position& pos) {
		is >> pos.x >> pos.y;
		return is;
	}

	/************************************************************************/
};
