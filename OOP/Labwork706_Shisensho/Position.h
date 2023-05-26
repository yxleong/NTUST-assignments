/*****************************************************************//**
 * File : Position.h
 * Author : Leong Yah Xuan
 * Create Date : April 16, 2023
 * Update Date : April 19, 2023
 * Description : This C++ program implements tile-matching game which named Shisensho.
 *********************************************************************/
#pragma once
#include <iostream>

class Position
{
public:
	// declare two public integer variables
	int xPos; // x-coordinates
	int yPos; // y-coordinates

	Position(int x = 0, int y = 0); // default constructor
	bool isInRange(int) const; // check whether the position is within a specified range

	friend std::istream& operator>>(std::istream&, Position&);
	friend bool operator==(const Position&, const Position&);
	Position operator=(const Position&);
	friend Position operator+(const Position&, const Position&);
};
