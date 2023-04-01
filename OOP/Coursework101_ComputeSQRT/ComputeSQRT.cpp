/*****************************************************************//**
 * File : ComputeSQRT.cpp
 * Author : Leong Yah Xuan
 * Create Date : February 27, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program computes the square root
 * 					by using Babylonian algorithm.
 *********************************************************************/

#include <iostream>
#include <iomanip>

 /**
 * Intent : To calculate the square root of a postive number by Babylonian algorithm.
 * Pre : The variable postiveNumber must have a value and postiveNumber > 0.
 * Post : The function returns the square root of a postive number.
 * \param postiveNumber
 * \return
 */
double getSquareRoot(double postiveNumber)
{
	// declare variables which are needed
	double guessing = 0, guessed = 0;;

	// pick n/2 as initial guess
	guessing = postiveNumber / 2;

	// Babylonian algorithm
	do {
		// compute r = n / guess 
		double root = postiveNumber / guessing;

		// guess= (guess + r) / 2
		guessed = guessing; // previous guess
		guessing = (guessing + root) / 2;

	} while (abs(guessing - guessed) >= 0.01);
	// iterates until the guess subtract the previous guess smaller than 0.01

	return guessing;
}

int main(void)
{
	// reusable variable, place this variable outside of the loop
	double postiveNumberInput = 0;

	// infinite loop until cin meets EOF
	while (std::cin >> postiveNumberInput) // read input as a double
	{
		// outputs the answer to two decimal places
		std::cout << std::fixed << std::setprecision(2) << getSquareRoot(postiveNumberInput) << std::endl;
	}

	return 0;
}