/*****************************************************************//**
 * File: Position.h
 * Author:
 * 	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 21, 2023
 * Description: This C++ program is to implement the location in the board.
*********************************************************************/
#pragma once
#include <iostream>

class Position {
public:
	int x, y; // X, y Coordinate
public:
	Position();
	Position(int x, int y);
	Position(const Position& ref);

	// Operator overloading
	Position operator+(const Position& rhs) const;
	Position& operator+=(const Position& rhs);

	Position operator-(const Position& rhs) const;
	Position& operator-=(const Position& rhs);

	Position operator*(int scale) const;

	bool operator==(const Position& rhs) const;
	bool operator!=(const Position& rhs) const;

	friend std::ostream& operator<<(std::ostream& oStream, const Position& pos);
	friend std::istream& operator>>(std::istream& iStream, Position& pos);
};
