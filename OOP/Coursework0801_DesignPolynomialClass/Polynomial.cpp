/*****************************************************************//**
 * File: Polynomial.cpp
 * Author: Leong Yah Xuan
 * Create Date: April 23, 2023
 * Update Date: May 21, 2023
 * Description: This C++ program is to handle one-dimensional polynomials.
 *********************************************************************/
#include "Polynomial.h"

 /*****************************************************************//**
 * Intent: To construct an empty Polynomial object.
 * Pre: The variable coefficients must be well-defined.
 * Post: The function initializes the Polynomial object with an empty coefficients vector.
  *********************************************************************/
Polynomial::Polynomial() : coefficients({}) {}

/*****************************************************************//**
 * Intent: To construct a Polynomial object from an array of coefficients.
 * Pre: The variables param,size must have value.
 * Post: The function initializes the Polynomial object with coefficients copied from the array.
 * \param param
 * \param size
 *********************************************************************/
Polynomial::Polynomial(double* param, int size)
{
	coefficients = std::vector<double>(param, param + size);
	// start, last
}

/*****************************************************************//**
 * Intent: To copy constructor for Polynomial objects.
 * Pre: The object poly must be a valid Polynomial object.
 * Post: The function initializes the Polynomial object with the same coefficients as poly.
 * \param poly
 *********************************************************************/
Polynomial::Polynomial(const Polynomial& poly)
{
	coefficients = poly.coefficients;
}

/*****************************************************************//**
 * Intent: To get the size of the Polynomial.
 * Pre: The variable coefficients must be well-defined.
 * Post: The function returns the size of the Polynomial.
 * \return
 *********************************************************************/
int Polynomial::mySize() const
{
	for (int i = coefficients.size() - 1; i >= 0; i--)
	{
		// find the highest non-zero coefficient
		if (coefficients[i] != 0)
		{
			return i + 1;
			// degree + 1 since include 0
		}
	}
	return 0;
}

/*****************************************************************//**
 * Intent: To evaluate the Polynomial for a given variable.
 * Pre: The variable var must have a value and object poly must be a valid Polynomial object.
 * Post: The function returns the result of evaluating the Polynomial at the given variable value.
 * \param poly
 * \param var
 * \return
 *********************************************************************/
double evaluate(const Polynomial& poly, const double& var)
{
	double result = 0;

	for (int i = 0; i < poly.coefficients.size(); i++)
	{
		result += poly.coefficients[i] * pow(var, i);
	}

	return result;
}

/*****************************************************************//**
 * Intent: To assign Polynomial object.
 * Pre: The object other must be a valid Polynomial object.
 * Post: The function returns a reference to this Polynomial object.
 * \param other
 * \return
 *********************************************************************/
Polynomial& Polynomial::operator=(const Polynomial& other)
{
	coefficients = other.coefficients;
	return *this;
}

/*****************************************************************//**
 * Intent: To access the coefficients of the Polynomial object.
 * Pre: The variable index must have a value and radius > 0.
 * Post: The function returns a reference to the coefficient at the given index.
 * \param index
 * \return
 *********************************************************************/
double& Polynomial::operator[](int index)
{
	// to handle exceed index
	while (index > coefficients.size() - 1)
	{
		coefficients.push_back(0);
	}

	return coefficients[index];
}

/*****************************************************************//**
 * Intent: To calculate the addition of two Polynomial objects.
 * Pre: The objects lhs,rhs must be valid Polynomial objects.
 * Post: The function returns the sum of two Polynomial objects.
 * \param lhs
 * \param rhs
 * \return
 *********************************************************************/
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
{
	// calculate the result size
	int degree = std::max(lhs.coefficients.size(), rhs.coefficients.size());

	// declare result polynomial object
	Polynomial result;

	// calculate the result polynomial coefficient by coefficient
	for (int i = 0; i < degree; i++)
	{
		double coeff = 0;

		if (i < lhs.coefficients.size())
		{
			// assign the lhs first
			coeff += lhs.coefficients[i];
		}
		if (i < rhs.coefficients.size())
		{
			// add on by the value of rhs
			coeff += rhs.coefficients[i];
		}

		// add the calculated coefficient of that index to result polynomial
		result.coefficients.push_back(coeff);
	}

	return result;
}

/*****************************************************************//**
 * Intent: To calculate the addition of a Polynomial object and a constant.
 * Pre: The variable constant must have a value and object poly must be valid Polynomial object.
 * Post: The function returns the sum of poly and the constant.
 * \param poly
 * \param constant
 * \return
 *********************************************************************/
Polynomial operator+(const Polynomial& poly, const double& constant)
{
	// assign the poly to result first
	Polynomial result = poly;

	// if poly is NULL
	if (result.coefficients.size() == 0)
	{
		// direct add on the constant value
		result.coefficients.push_back(constant);
	}
	else // if poly have value
	{
		// add with the constant value at constant index (last digit)
		result.coefficients[0] += constant;
	}

	return result;
}

/*****************************************************************//**
 * Intent: To calculate the addition of a constant and a Polynomial object.
 * Pre: The variable constant must have a value and object poly must be valid Polynomial object.
 * Post: The function returns the sum of the constant and poly.
 * \param constant
 * \param poly
 * \return
 *********************************************************************/
Polynomial operator+(const double& constant, const Polynomial& poly)
{
	// assign the poly to result first
	Polynomial result = poly;

	// if poly is NULL
	if (result.coefficients.size() == 0)
	{
		// direct add on the constant value
		result.coefficients.push_back(constant);
	}
	else // if poly have value
	{
		// add with the constant value at constant index (last digit)
		result.coefficients[0] += constant;
	}

	return result;
}

/*****************************************************************//**
 * Intent: To calculate the subtraction of two Polynomial objects.
 * Pre: The objects lhs,rhs must be valid Polynomial objects.
 * Post: The function returns the difference of lhs and rhs.
 * \param lhs
 * \param rhs
 * \return
 *********************************************************************/
Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs)
{
	// calculate the result size
	int degree = std::max(lhs.coefficients.size(), rhs.coefficients.size());

	// declare result polynomial object
	Polynomial result;

	// calculate the result polynomial coefficient by coefficient
	for (int i = 0; i < degree; i++)
	{
		double coeff = 0;

		if (i < lhs.coefficients.size())
		{
			// assign the lhs first
			coeff += lhs.coefficients[i];
		}
		if (i < rhs.coefficients.size())
		{
			// deduct by the value of rhs
			coeff -= rhs.coefficients[i];
		}

		// add the calculated coefficient of that index to result polynomial
		result.coefficients.push_back(coeff);
	}

	return result;
}

/*****************************************************************//**
 * Intent: To calculate the subtraction of a Polynomial object and a constant.
 * Pre: The variable constant must have a value and object poly must be valid Polynomial object.
 * Post: The function returns the difference of poly and the constant.
 * \param poly
 * \param constant
 * \return
 *********************************************************************/
Polynomial operator-(const Polynomial& poly, const double& constant)
{
	// assign the poly to result first
	Polynomial result = poly;

	// if poly is NULL
	if (result.coefficients.size() == 0)
	{
		// direct add on the constant value
		result.coefficients.push_back(-constant);
	}
	else // if poly have value
	{
		// deduct with the constant value at constant index (last digit)
		result.coefficients[0] -= constant;
	}

	return result;
}

/*****************************************************************//**
 * Intent: To calculate the subtraction of a constant and a Polynomial object.
 * Pre: The variable constant must have a value and object poly must be valid Polynomial object.
 * Post: The function returns the difference of the constant and poly.
 * \param constant
 * \param poly
 * \return
 *********************************************************************/
Polynomial operator-(const double& constant, const Polynomial& poly)
{
	// assign the poly to result first
	Polynomial result = poly;

	// convert the sign of coefficients in result
	for (double& coeff : result.coefficients)
	{
		coeff *= -1;
	}

	// if poly is NULL
	if (result.coefficients.size() == 0)
	{
		// direct add on the constant value
		result.coefficients.push_back(constant);
	}
	else // if poly have value
	{
		// add with the constant value at the constant index (last digit)
		result.coefficients[0] += constant;
		// constant - poly
		// constant + (-poly)
	}

	return result;
}

/*****************************************************************//**
* Intent: To calculate the multiplication of two Polynomial objects.
* Pre: The objects lhs,rhs must be valid Polynomial objects.
* Post: The function returns the product of lhs and rhs.
* \param lhs
* \param rhs
* \return
*********************************************************************/
Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs)
{
	// calculate the result size
	int degree = lhs.coefficients.size() + rhs.coefficients.size() - 1;

	// declare result polynomial object with specific size
	Polynomial result;
	result.coefficients = std::vector<double>(degree, 0);

	// calculate the result polynomial coefficient by coefficient
	for (int i = 0; i < lhs.coefficients.size(); i++)
	{
		for (int j = 0; j < rhs.coefficients.size(); j++)
		{
			result[i + j] += lhs.coefficients[i] * rhs.coefficients[j];
		}
	}

	return result;
}

/*****************************************************************//**
 * Intent: To calculate the multiplication of a Polynomial object and a constant.
 * Pre: The variable constant must have a value and object poly must be valid Polynomial object.
 * Post: The function returns the product of poly and the constant.
 * \param poly
 * \param constant
 * \return
 *********************************************************************/
Polynomial operator*(const Polynomial& poly, const double& constant)
{
	// assign the poly to result first
	Polynomial result = poly;

	// multiply all the coefficients in polynomial with constant
	for (double& coeff : result.coefficients)
	{
		coeff *= constant;
	}

	return result;
}

/*****************************************************************//**
 * Intent: To calculate the multiplication of a constant and a Polynomial object.
 * Pre: The variable constant must have a value and object poly must be valid Polynomial object.
 * Post: The function returns the product of constant and poly.
 * \param constant
 * \param poly
 * \return
 *********************************************************************/
Polynomial operator*(const double& constant, const Polynomial& poly)
{
	// assign the poly to result first
	Polynomial result = poly;

	// multiply all the coefficients in polynomial with constant
	for (double& coeff : result.coefficients)
	{
		coeff *= constant;
	}

	return result;
}
