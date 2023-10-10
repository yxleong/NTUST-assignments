/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 8, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program puts the characters
 *					of the no spaced input messages into a n*n square.
 *********************************************************************/

#include <iostream>
#include <cmath>

int main(void)
{
	// reusable variables, place these variables outside of the loop
	std::string input = "";

	// infinite loop until cin meets EOF
	while (std::cin >> input) // read input as a string
	{
		// declare variables which are needed
		int stringLength = input.length();
		int sqrtLength = ceil(sqrt(stringLength));
		// (stringLength - 1) ^ 2 < message length <= stringLength ^ 2.

		for (int i = 0; i < sqrtLength; i++) // loop until i = sqrtLength
		{
			for (int j = i; j < stringLength; j += sqrtLength) // loop until j = sqrtLength
			{
				// output the element of certain index in string
				// eg: [0]->[0+sqrtLength]->[...]
				std::cout << input[j];
			}

			// output \n, which is
			// eg: [0]->[1]->[2]
			std::cout << std::endl;
		}
	}

	return 0;
}