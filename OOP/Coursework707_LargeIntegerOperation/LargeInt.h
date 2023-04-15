/*****************************************************************//**
 * File : LargeInt.h
 * Author : Leong Yah Xuan
 * Create Date : April 12, 2023
 * Update Date : April 15, 2023
 * Description : This C++ program implements the large integer operation.
 *********************************************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>

class LargeInt
{
private:
	std::vector<int> digits; // to store the digits of the number
	bool isNegative; // to indicate if the number is negative

public:
	// default constructor
	LargeInt() : digits{ }, isNegative{ false }{}; // initialize the empty vector and false flag

	// constructor
	LargeInt(std::string input); // to initialize the number with a string input

	// overloaded output stream operator
	friend std::ostream& operator<<(std::ostream& os, const LargeInt& num); // to print the LargeInt

	// overloaded less than operator
	bool operator<(const LargeInt& other) const; // to compare two LargeInt

	// overloaded addition operator
	LargeInt operator+(const LargeInt& other)const; // to add two LargeInt

	// overloaded subtraction operator
	LargeInt operator-(const LargeInt& other)const; // to subtract two LargeInt

	// overloaded multiplication operator
	LargeInt operator*(const LargeInt& other)const; // to multiply two LargeInt
};