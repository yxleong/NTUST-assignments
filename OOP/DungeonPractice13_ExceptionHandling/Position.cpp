/*****************************************************************//**
 * File: Position.cpp
* Author:
*	Leong Yah Xuan
*	Tien Qingian
* Create Date: May 20, 2023
* Update Date: May 21, 2023
* Description: This C++ program is to implement the location in the board.
*********************************************************************/
#include "Position.h"

Position::Position() : x(0), y(0) {}

Position::Position(int x, int y) : x(x), y(y) {}

Position::Position(const Position& ref) {
	*this = ref;
}

Position Position::operator+(const Position& rhs) const {
	return Position(x + rhs.x, y + rhs.y);
}

Position& Position::operator+=(const Position& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Position Position::operator-(const Position& rhs) const {
	return Position(x - rhs.x, y - rhs.y);
}

Position& Position::operator-=(const Position& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Position Position::operator*(int scale) const {
	return Position(x * scale, y * scale);
}

bool Position::operator==(const Position& rhs) const {
	return x == rhs.x && y == rhs.y;
}

bool Position::operator!=(const Position& rhs) const {
	return !(*this == rhs);
}

/*****************************************************************//**
* Intent: To allow a Position object to be output to an output stream.
* Pre: The object pos must be valid.
* Post: The function returns an output stream containing the string representation of the Position object.
* \param oStream
* \param pos
* \return
*********************************************************************/
std::ostream& operator<<(std::ostream& oStream, const Position& pos) {
	return oStream << pos.x << " " << pos.y;
}

/*****************************************************************//**
* Intent: To allow a Position object can be input from an input stream.
* Pre: The object pos must be valid.
* Post: The function returns an input stream containing the string representation of the Position object.
* \param iStream
* \param pos
* \return
*********************************************************************/
std::istream& operator>>(std::istream& iStream, Position& pos) {
	return iStream >> pos.x >> pos.y;
}
