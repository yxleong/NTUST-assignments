/*****************************************************************//**
 * File: PrivateSchool.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 24, 2023
 * Update Date: May 24, 2023
 * Description: This C++ program creates three types of school and transfers students from each to another one.
 *********************************************************************/
#include "PrivateSchool.h"

 /*****************************************************************//**
  * Intent: To construct the PrivateSchool class with empty value.
  * Pre: The variable dropoutsWave must be well-defined.
  * Post: The function initializes the PrivateSchool class with empty value.
  *********************************************************************/
PrivateSchool::PrivateSchool() : dropoutsWave(0) {}

/*****************************************************************//**
 * Intent: To construct the PrivateSchool class with specified values.
 * Pre: The variables name,amount must have value.
 * Post: The function initializes the School class with specified values.
 * \param name
 * \param amount
 *********************************************************************/
PrivateSchool::PrivateSchool(std::string name, int amount) : School(name, amount), dropoutsWave(0) {}

/*****************************************************************//**
 * Intent: To destruct the PrivateSchool class.
 * Pre: The variable dropoutsWave must be well-defined.
 * Post: The function destructs the PrivateSchool class.
 *********************************************************************/
PrivateSchool::~PrivateSchool() {}

/*****************************************************************//**
 * Intent: To subtract the specified amount to the total student amount for this year.
 * Pre: The variable amount must have a value and 0 < amount < studentAmount.
 * Post: The function decreases 100 from the studentAmountNextYear after the single wave.
 * \param amount
 *********************************************************************/
void PrivateSchool::dropouts(float amount) {
	// only one wave of dropouts are allowed
	if (dropoutsWave == 1) { // After the single wave

		// penalty of 100 is deducted from the amount of students the school is able to admit next year
		studentAmountNextYear -= dropoutsWave * 100; // for every dropouts called
	}

	// if the amount is nonnegative and less than or equal to the student amount
	if (amount >= 0 && amount <= studentAmount) {
		// subtracts the amount from the number of students this year
		studentAmount -= amount;
		// keep track of the times of dropouts
		dropoutsWave++;
	}
	// If violations occur 
		// Subtracting more than existing amount
	// not do the operation
}
