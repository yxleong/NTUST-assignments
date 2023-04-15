/*****************************************************************//**
 * File : Atoi.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 12, 2023
 * Update Date : April 12, 2023
 * Description : This C++ program converts a string into an integer
 *********************************************************************/
#include "Atoi.h"
#include <ctype.h>
#include <iostream>

Atoi::Atoi() // Construct a class Atoi where beTran is ""
{
	beTrans = ""; // initialize beTrans
}

Atoi::Atoi(string s) // Construct a class Atoi where beTran is s
{
	beTrans = s; // assign value of beTrans to s
}

/**
* Intent : To set beTran of this class to s.
* Pre : The variable s must have a value.
* Post : The function sets beTran of this class to s.
* \param s
*/
void Atoi::SetString(string s)
{
	// assign value of beTrans to s
	beTrans = s;
}

/**
* Intent : To return beTran of class Atoi.
* Pre : The variable beTrans must have a value.
* Post : The function returns beTran of class Atoi.
* \return
*/
const string Atoi::GetString()
{
	// return value of beTran
	return beTrans;
}

/**
* Intent : To return the length of beTran.
* Pre : The variable beTran must have a value and length > 0.
* Post : The function returns the length of beTran.
* \return
*/
int Atoi::Length()
{
	// check if input is negative or not
	// if negative, deduct the length of the negative sign
	return (beTrans[0] == '-' ? beTrans.length() - 1 : beTrans.length());
}

/**
* Intent : To check if beTran can be transformed into an integer.
* Pre : The variable beTrans must have a value.
* Post : The function returns the boolean condition if beTran can be transformed into an integer.
* \return
*/
bool Atoi::IsDigital()
{
	// loop through all the character in string beTrans
	for (char c : beTrans)
	{
		// ignore the first negative sign
		if (beTrans[0] == '-')
			continue;

		// check if the character looped is a digit
		if (!isdigit(c))
		{
			// if not, direct jump out the function
			return false;
		}
	}

	// if loop all, digit verified
	return true;
}

/**
* Intent : To convert beTran to an integer.
* Pre : The variable beTran must have a value.
* Post : The function returns the converted beTran.
* \return
*/
int Atoi::StringToInteger()
{
	// declare variable which is needed
	int beTransInt = 0;

	// check if first character is negative sign
	if (isdigit(beTrans[0]))
	{
		// if not, assign the value as int
		beTransInt = beTrans[0] - '0';
	}

	// loop then string from next character
	for (size_t i = 1; i < beTrans.length(); i++)
	{
		// since loop from first digit
		// must multiply 10 to move value left
		beTransInt *= 10;

		// then add the next index value in string
		beTransInt += (beTrans[i] - '0');
	}

	// check if first character is negative sign
	// if yes, the int value will be negative
	return (isdigit(beTrans[0]) ? beTransInt : -beTransInt);
}
