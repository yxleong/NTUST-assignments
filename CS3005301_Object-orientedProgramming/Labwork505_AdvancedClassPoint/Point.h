/*****************************************************************//**
 * File : Point.h
 * Author : Leong Yah Xuan
 * Create Date : March 30, 2023
 * UPDATE Date : March 31, 2023
 * Description : This C++ program use class Point to store and
 *					manipulate the location of a point in the plane.
 *********************************************************************/
#pragma once

#include <iostream>

 // define a class named Point
 // that might be used to store and manipulate the location of a point in the plane
class Point
{
public:
	float pointX; // X coordinate of the Point
	float pointY; // Y coordinate of the Point

	Point(); // default constructor for the Point
	~Point(); // destructor for the Point

	void Set(float inputX, float inputY); // set the X and Y coordinates of the Point
	void Move(float deltaX, float deltaY); // move the point along the horizontal and vertical directions

	void Rotate(); // rotate the Point by 90 degrees clockwise around the origin.
	void Reflect(); // reflect the Point in the origin.

	const float GetHorizontal(); // get the Y coordinate of the Point
	const float GetVertical(); // get the X coordinate of the Point
};