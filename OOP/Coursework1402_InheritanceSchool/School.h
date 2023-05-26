/*****************************************************************//**
 * File: School.h
 * Author: Leong Yah Xuan
 * Create Date: May 24, 2023
 * Update Date: May 25, 2023
 * Description: This C++ program creates three types of school and transfers students from each to another one.
 *********************************************************************/
#pragma once
#include <string>
#include <iostream>

 // Create a base class called School
class School {
protected:
	std::string schoolName;			// the name of the school
	float studentAmount;			// the student amount of the school currently
	float studentAmountNextYear;	// the number of students could have next year
public:
	// Constructors
	School();
	School(std::string, int);
	virtual ~School();

	// Functions
	void admissions(float amount);					// adds the amount
	virtual void dropouts(float amount);			// subtracts the amount
	void transfer(float amount, School& toSchool);	// deducts from.. and transfers to..

	// Operator
	friend std::ostream& operator<<(std::ostream& os, const School& school);
};

#include "PrivateSchool.h"
#include "PublicSchool.h"