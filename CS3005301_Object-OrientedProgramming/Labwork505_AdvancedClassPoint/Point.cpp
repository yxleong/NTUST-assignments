/*****************************************************************//**
 * File : Point.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 30, 2023
 * UPDATE Date : March 31, 2023
 * Description : This C++ program use class Point to store and
 *					manipulate the location of a point in the plane.
 *********************************************************************/
#include "Point.h"

Point::Point()
{
	// data must be an array of float in size 2
	// initialized by zero
	pointX = 0;
	pointY = 0;
}

// A destructor used to release memory
// before the instance of class destroyed
// Avoiding memory leak!
Point::~Point()
{
}

/**
* Intent : To set the private data after an object of this class is created.
* Pre : The variables inputX,inputY must have a value.
* Post : The function sets the point with the given coordinates.
* \param inputX
* \param inputY
*/
void Point::Set(float inputX, float inputY)
{
	// assign the value
	pointX = inputX;
	pointY = inputY;
}

/**
* Intent : To move the point along the horizontal and vertical directions specified by the first and second arguments.
* Pre : The variables deltaX,deltaX must have a value.
* Post : The function adjusts the coordinates with the given movement.
* \param deltaX
* \param deltaY
*/
void Point::Move(float deltaX, float deltaY)
{
	// do the increment
	pointX += deltaX;
	pointY += deltaY;
}

/**
* Intent : To rotate the point by 90 degrees clockwise around the origin.
* Pre : -
* Post : The function exchanges the coordinates of the point.
*/
void Point::Rotate()
{
	// save x-coordinate to avoid value be covered
	float temp = pointX;

	pointX = pointY;
	pointY = (-temp == 0) ? 0 : -temp; // check if the pointX is 0
	// if yes, then no need have the negative sign
}

/**
* Intent : To reflect point in the origin.
* Pre : -
* Post : The function adjusts the coordinates by positive and negative conversion.
*/
void Point::Reflect()
{
	// check if the coordinate is 0
	// if yes, then remove the negative sign for 0
	pointX = (pointX == 0) ? 0 : -pointX;
	pointY = (pointY == 0) ? 0 : -pointY;
}

/**
* Intent : To retrieve the current x-coordinate of the point.
* Pre : The variable pointX must have a value.
* Post : The function returns the current x-coordinate of the point.
* \return
*/
const float Point::GetHorizontal()
{
	return pointX;
}

/**
* Intent : To retrieve the current y-coordinate of the point.
* Pre : The variable pointY must have a value.
* Post : The function returns the current y-coordinate of the point.
* \return
*/
const float Point::GetVertical()
{
	return pointY;
}