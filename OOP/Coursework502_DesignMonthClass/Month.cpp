/*****************************************************************//**
 * File : Month.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 28, 2023
 * UPDATE Date : March 28, 2023
 * Description : This C++ program defines a class named Month
 *					to display the formatted month.
 *********************************************************************/
#include "Month.h"
#include <string>
#include <iostream>

 // Declare the abbreviation of a month as
 // the first three letters of the name with initial capitalization
const std::string monthAbbRef[13] = { "", "Jan", "Feb", "Mar", "Apr", "May",
									"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

Month::Month()
{
	// construct a Month class that defaults to January.
	month = 1;
}

// Use the given abbreviation to construct the Month class
// the parameters represent each letter of the abbreviation
Month::Month(char first, char second, char third)
{
	// declare variables which are needed
	std::string monthAbb = "";
	bool isValid = false;
	int index = 0;

	// combine the char into a string
	monthAbb = first;
	monthAbb += second;
	monthAbb += third;

	// check if monthAbb is valid in monthAbbRef
	for (int i = 0; i < 13; i++)
	{
		if (monthAbb == monthAbbRef[i])
		{
			isValid = true; // if yes
			index = i; // record the found index
			break; // break the for loop
		}
	}

	if (isValid)
	{
		month = index;
	}
	else // if the value is invalid
	{
		// set the month to January
		month = 1;
	}
}

Month::Month(int monthInt)
{
	// if the given value is invalid
	if (monthInt < 1 || monthInt > 12)
	{
		// set the month to January
		month = 1;
	}
	else
	{
		// Construct a Month class with the value of  ¡°monthInt¡±
		month = monthInt;
	}
}

Month::~Month()
{
}

/**
* Intent : To modify the current month to inputX.
* Pre : If inputX is invalid (inputX < 1 or inputX > 12), set the month value to 1
* Post : The function modifies the current month to inputX.
*/
void Month::inputInt()
{
	// declare variables which are needed
	int inputX = 0;

	// Read an int x
	std::cin >> inputX;

	// If x is invalid
	if (inputX < 1 || inputX > 12)
	{
		// set the month value to 1
		month = 1;
	}
	else
	{
		// modify the current month to x
		month = inputX;
	}
}

/**
* Intent : To modify the letters to the corresponding month value.
* Pre : If the input is invalid, set the month value to 1.
* Post : The function modifies the letters to the corresponding month value.
*/
void Month::inputStr()
{
	// declare variables which are needed
	char first = 0, second = 0, third = 0;
	std::string monthAbb = "";
	bool isValid = false;
	int index = 0;

	// Read three letters which represent each letter of the abbreviation of a month
	std::cin >> first >> second >> third;

	// combine the char into a string
	monthAbb = first;
	monthAbb += second;
	monthAbb += third;

	// Modify the letters to the corresponding month value
	// check if monthAbb is valid in monthAbbRef
	for (int i = 0; i < 13; i++)
	{
		if (monthAbb == monthAbbRef[i])
		{
			isValid = true; // if yes
			index = i; // record the found index
			break; // break the for loop
		}
	}

	if (isValid)
	{
		// Modify the letters to the corresponding month value
		month = index;
	}
	else // if the value is invalid
	{
		// set the month to January
		month = 1;
	}
}

/**
* Intent : To print the month value.
* Pre : The variable month must have a value and 1 <= month <= 12.
* Post : The function prints the month value.
*/
void Month::outputInt()
{
	// Print the month value
	std::cout << month;
}

/**
* Intent : To print the abbreviation of the month.
* Pre : The variable month must have a value and 1 <= month <= 12
* Post : The function prints the abbreviation of the month.
*/
void Month::outputStr()
{
	// Print the abbreviation of the month
	std::cout << monthAbbRef[month];
}

// Increment month value
Month Month::nextMonth()
{
	// declare variable which is needed
	Month nextMon;

	// assign month of next month as
	// current month + 1
	nextMon.month = month + 1;

	// if the value is invalid
	if (nextMon.month > 12)
	{
		// set the month to January
		nextMon.month = 1;
	}

	return nextMon;
}
