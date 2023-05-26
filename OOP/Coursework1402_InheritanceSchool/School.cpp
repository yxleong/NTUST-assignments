/*****************************************************************//**
 * File: School.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 24, 2023
 * Update Date: May 25, 2023
 * Description: This C++ program creates three types of school and transfers students from each to another one.
 *********************************************************************/
#include "School.h"

 /*****************************************************************//**
  * Intent: To construct the School class with empty value.
  * Pre: The variables schoolName,studentAmount,studentAmountNextYear must be well-defined.
  * Post: The function initializes the School class with empty value.
  *********************************************************************/
School::School() :schoolName(""), studentAmount(0), studentAmountNextYear(0) {}

/*****************************************************************//**
 * Intent: To construct the School class with specified values.
 * Pre: The variables name,amount must have value.
 * Post: The function initializes the School class with specified values.
 * \param name
 * \param amount
 *********************************************************************/
School::School(std::string name, int amount) : schoolName(name), studentAmount(amount) {
	// same as the student amount this year
	studentAmountNextYear = amount;
}

/*****************************************************************//**
 * Intent: To destruct the School class.
 * Pre: The variables schoolName,studentAmount,studentAmountNextYear must be well-defined.
 * Post: The function destructs the School class.
 *********************************************************************/
School::~School() {}

/*****************************************************************//**
 * Intent: To add the specified amount to the total student amount for this year.
 * Pre: The variable amount must have a value and amount > 0.
 * Post: The function increases the amount to the student amount for this year.
 * \param amount
 *********************************************************************/
void School::admissions(float amount) {
	// if the amount is nonnegative
	if (amount >= 0) {
		// adds the amount to the total student amount this year 
		studentAmount += amount;
	}
}

/*****************************************************************//**
 * Intent: To subtract the specified amount to the total student amount for this year.
 * Pre: The variable amount must have a value and 0 < amount < studentAmount.
 * Post: The function decreases the amount to the student amount for this year.
 * \param amount
 *********************************************************************/
void School::dropouts(float amount) {
	// if the amount is nonnegative and less than or equal to the student amount
	if (amount >= 0 && amount <= studentAmount) {
		// subtracts the amount from the number of students this year
		studentAmount -= amount;
	}
	// If violations occur 
		// Subtracting more than existing amount
	// not do the operation
}

/*****************************************************************//**
 * Intent: To transfers the specified amount of students from the current school to another school.
 * Pre: The variables amount,toSchool must have a value and 0 < amount < studentAmount.
 * Post: The function subtracts the amount from the current school and adds it to the toSchool.
 * \param amount
 * \param toSchool
 *********************************************************************/
void School::transfer(float amount, School& toSchool) {
	if (amount >= 0 && amount <= studentAmount) {
		// deducts from the student amount of current
		dropouts(amount);
		// transfers them to another school
		toSchool.admissions(amount);
	}
	// If violations occur 
		// Subtracting more than existing amount
	// not do the operation
}


/*****************************************************************//**
 * Intent: To implement overloaded output operator for the School class.
 * Pre: The objects os,school must be valid.
 * Post: The function returns the modified output stream object.
 * \param os
 * \param school
 * \return
 *********************************************************************/
std::ostream& operator<<(std::ostream& os, const School& school) {
	// Output format will be with name, studentAmount and studentAmountNextYear.
	// Each separate by tab(¡®\t¡¯).
	os << school.schoolName << "\t" << school.studentAmount << "\t" << school.studentAmountNextYear;
	return os;
}