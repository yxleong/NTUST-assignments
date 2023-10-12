#pragma once
#include "School.h"

class PublicSchool : public School {
private:
	float growingRate;
public:
	// Constructors
	PublicSchool();
	PublicSchool(std::string, int);
	virtual ~PublicSchool();

	// Function
	void apply_growth(); // increases amount of students able to admit next year
	void dropouts(float amount) override;
};