/*****************************************************************//**
 * File : Fraction.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 21, 2023
 * UPDATE Date : March 21, 2023
 * Description : This C++ program defines a class for a type called Fraction.
 *********************************************************************/

#include "Fraction.h"

 /**
 * Intent : To set the value of a numerator with a given input.
 * Pre : The variable nu must have a value.
 * Post : The function assigns the value of nu to numerator.
 * \param nu
 */
void Fraction::setNumerator(int nu)
{
	numerator = nu; // assign value
}

/**
 * Intent : To set the value of a denominator with a given input.
 * Pre : The variable de must have a value.
 * Post : The function assigns the value of de to denominator.
* \param de
*/
void Fraction::setDenominator(int de)
{
	denominator = de; // assign value
}

/**
* Intent : To calculate the fraction of given numerator and denominator.
* Pre : The variables numerator and denominator must have a value.
* Post : The function outputs the fraction in decimal form.
*/
void Fraction::getDouble()
{
	if (numerator == 0) // if numerator is 0
	{
		// direct output 0
		std::cout << 0 << std::endl;

		// jump out this function
		return;
	}
	else
	{
		// declare variables which are needed
		double result = 0;
		int resultInt = 0;

		// calculate the fraction in certain form
		result = (double)numerator / denominator;
		resultInt = (int)result;

		if (result == resultInt) // if result is in int form
		{
			// output the result without decimal
			std::cout << resultInt << std::endl;
		}
		else // if result have decimal
		{
			// output the result with 6 decimal
			std::cout << std::fixed << std::setprecision(6) << result << std::endl;
		}
	}
}

/**
* Intent : To get the fraction in reduced form.
* Pre : The variables numerator and denominator must have a value.
* Post : The function outputs the fraction in decimal form.
*/
void Fraction::outputReducedFraction()
{
	if (numerator == 0) // if numerator is 0
	{
		// direct output 0
		std::cout << 0 << std::endl;

		// jump out this function
		return;
	}
	else
	{
		// declare variables which are needed
		int gcd = 0, num = 1;
		int reduceNumerator = 0, reduceDenominator = 0;

		// calculate the greatest common division of numerator and denominator
		while (num <= numerator && num <= denominator) // loop until num > numerator/denominator
		{
			// if numerator/denominator able to be divide without mod
			if (numerator % num == 0 && denominator % num == 0)
			{
				gcd = num; // that num will be gcd
			}

			num++; // increase to find the greatest one
		}

		// reduce the numerator and denominator by gcd
		reduceNumerator = numerator / gcd;
		reduceDenominator = denominator / gcd;

		// check if reduceDenominator if 1
		if (reduceDenominator == 1) // if yes
		{
			// output fraction without reduceDenominator
			std::cout << reduceNumerator << std::endl;
		}
		else
		{
			// output the reduced fraction
			std::cout << reduceNumerator << "/" << reduceDenominator << std::endl;
		}
	}
}