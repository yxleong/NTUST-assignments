/*****************************************************************//**
 * File: Polynomial.h
 * Author: Leong Yah Xuan
 * Create Date: April 23, 2023
 * Update Date: May 21, 2023
 * Description: This C++ program is to handle one-dimensional polynomials.
 *********************************************************************/
#pragma once
#include <vector>
#include <cmath>

class Polynomial {
private:
	std::vector<double> coefficients;
public:
	Polynomial();
	Polynomial(double* param, int size);
	Polynomial(const Polynomial& poly);

	int mySize() const;
	friend double evaluate(const Polynomial& poly, const double& var);
	// friend to let function access to the private member

	Polynomial& operator=(const Polynomial& other);
	double& operator[](int index);

	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator+(const Polynomial& poly, const double& constant);
	friend Polynomial operator+(const double& constant, const Polynomial& poly);

	friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator-(const Polynomial& poly, const double& constant);
	friend Polynomial operator-(const double& constant, const Polynomial& poly);

	friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator*(const Polynomial& poly, const double& constant);
	friend Polynomial operator*(const double& constant, const Polynomial& poly);
};