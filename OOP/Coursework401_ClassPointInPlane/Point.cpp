/*****************************************************************//**
 * File : Point.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 21, 2023
 * UPDATE Date : March 21, 2023
 * Description : This C++ program implements a class named Point
 *					to store and manipulate the position
 *					of the point on the screen.
 *********************************************************************/

#include "Point.h"

 /**
 * Intent : To reset the coordinate position of the point by the given the vertical and horizontal.
 * Pre : The variables vertical,horizontal must have a value.
 * Post : The function assigns the position of the point.
 * \param vertical
 * \param horizontal
 */
void Point::Set(int vertical, int horizontal)
{
	// assign the vertical and horizontal value
	this->vertical = vertical;
	this->horizontal = horizontal;
}

/**
* Intent : To move the current point x pixels on the x-axis and y pixels on the y-axis.
* Pre : The variables x,y must have a value.
* Post : The function assign the position of the point moved.
* \param x
* \param y
*/
void Point::Move(int x, int y)
{
	// assign the vertical and horizontal value according to the given movement
	this->vertical += x;
	this->horizontal += y;
}

/**
* Intent : To rotate the point 90 degrees clockwise from the origin.
* Pre : The variable vertical,horizontal must have a value.
* Post : The function assign the position of the point rotated.
*/
void Point::Rotate()
{
	// declare the variable to avoid cover the value
	int temp = this->vertical;

	// do the swaping to change the position of vertical and horizontal
	this->vertical = this->horizontal; // v2h: rotate 180 degree
	this->horizontal = -temp; // -: rotate 90 degree down(cloclwise)
}
