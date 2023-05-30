/*****************************************************************//**
 * File: Template.h
 * Author: Leong Yah Xuan
 * Create Date: May 30, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program calculates the absolute value of the difference between two numeric values by a template-based function.
 *********************************************************************/
#pragma once

template <typename T> // create template function
/*****************************************************************//**
 * Intent: To calculate the absolute value of the difference between two numeric values.
 * Pre: The variable radius must have a value and radius > 0.
 * Post: The function returns the absolute value of the difference between two numeric values.
 * \param a
 * \param b
 * \return
 *********************************************************************/
double absoluteValue(T a, T b)
{
	// let the larger value become the minuend
	return (a > b) ? a - b : b - a;
	// return as a double form
}