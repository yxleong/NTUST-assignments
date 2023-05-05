/*****************************************************************//**
 * File : VecNf.h
 * Author : Leong Yah Xuan
 * Create Date : April 29, 2023
 * Update Date : May 3, 2023
 * Description : This C++ program stores a multidimensional vector and implements some simple vector operations.
 *********************************************************************/
#pragma once
#include <iostream>
#include <vector>

class VecNf
{
private:
	std::vector<float> data;
public:
	VecNf(); // Construct a one-dimensional zero vector in default
	VecNf(float* dest, int cnt); // Construct a cnt dimensional vector using the first cnt numbers in dest
	VecNf(const VecNf& rhs); // Construct a new vector from a VecNf

	VecNf operator =(const VecNf& other); // Assign the value from a VecNf to another polynomial
	float& operator [](int index); // Return the value of the certain dimension variable in the vector
	VecNf operator +(const VecNf& rhs); // Implement the addition of two vectors
	VecNf operator -(const VecNf& rhs); // Implement the subtraction of two vectors
	float operator *(const VecNf& rhs); // Implement the Inner product of two vectors
	friend VecNf operator *(float scalar, const VecNf& rhs); // Implement the scalar multiplication of a floating-point number and a vector

	int Size() const;
};
