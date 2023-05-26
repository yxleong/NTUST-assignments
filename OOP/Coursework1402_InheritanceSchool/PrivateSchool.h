#pragma once
#include "School.h"

// create a PublicSchool class derived from School
class PrivateSchool : public School {
private:
	int dropoutsWave; // keep track of the times of dropouts
public:
	// Constructors
	PrivateSchool();
	PrivateSchool(std::string, int);
	virtual ~PrivateSchool();

	// Function
	void dropouts(float amount) override;
};