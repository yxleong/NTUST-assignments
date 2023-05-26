/*****************************************************************//**
 * File: PublicSchool.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 24, 2023
 * Update Date: May 24, 2023
 * Description: This C++ program creates three types of school and transfers students from each to another one.
 *********************************************************************/
#include "PublicSchool.h"

 /*****************************************************************//**
  * Intent: To construct the PublicSchool class with specified value.
  * Pre: The variable growingRate must be well-defined.
  * Post: The function initializes the PublicSchool class with specified value.
  *********************************************************************/
PublicSchool::PublicSchool() : growingRate(0.05) {}

/*****************************************************************//**
 * Intent: To construct the PublicSchool class with specified values.
 * Pre: The variables name,amount must have value.
 * Post: The function initializes the School class with specified values.
 * \param name
 * \param amount
 *********************************************************************/
PublicSchool::PublicSchool(std::string name, int amount) : School(name, amount), growingRate(0.05) {}

/*****************************************************************//**
 * Intent: To destruct the PublicSchool class.
 * Pre: The variable growingRate must be well-defined.
 * Post: The function destructs the PublicSchool class.
 *********************************************************************/
PublicSchool::~PublicSchool() {}

/*****************************************************************//**
 * Intent: To increase amount of students able to admit next year.
 * Pre: The variable studentAmountNextYear,growingRate must be well-defined.
 * Post: The function increases amount of students able to admit next year.
 *********************************************************************/
void PublicSchool::apply_growth() {
	studentAmountNextYear += growingRate * studentAmountNextYear;
}

/*****************************************************************//**
 * Intent: To calculate the volume of a sphere with a given radius.
 * Pre: The variable radius must have a value and radius > 0.
 * Post: The function returns the volume of a sphere.
 * \param amount
 *********************************************************************/
void PublicSchool::dropouts(float amount) {
	// if the amount is nonnegative and less than or equal to the student amount
	if (amount >= 0 && amount <= studentAmount) {
		// subtracts the amount from the number of students this year
		studentAmount -= amount;

		// incur penalties when large amount of students(>100) leave the school at once
		if (amount > 100) {
			// a loss of 5% of studentAmountNextYear
			int left = studentAmountNextYear * 0.95; // truncating the decimal places
			studentAmountNextYear = left;
		}
	}
	// If violations occur 
		// Subtracting more than existing amount
	// not do the operation
}
