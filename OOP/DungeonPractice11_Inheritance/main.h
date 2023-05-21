/*****************************************************************//**
* File: main.h
* Author:
*	Leong Yah Xuan
*	Tien Qingian
* Create Date: May 20, 2023
* Update Date: May 21, 2023
* Description: This C++ program is to implement some functions for the objects.
*********************************************************************/
#include <iostream>
#include <math.h>		// pow() and sqrt()
#include <ctime>		// for time loop function
#include <conio.h>		// _getch() <= to read input without enter "ENTER" key
#include <algorithm>	// for max and min function
#include "Position.h"

// Check whether the location is a valid one i.e. not a wall
bool isPositionValid(Position& loc);

// clip algroithm
float clip(float n, float minimun, float maximum);

// Check whether two position is close enough
// Use call-by-reference to return the calculated direction
bool canSee(Position cPos, Position hPos, Position& pos2);