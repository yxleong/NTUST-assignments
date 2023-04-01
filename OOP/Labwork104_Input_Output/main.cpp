/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : February 27, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program displays the given arbitrary integer
 *					by the following requirements.
 *********************************************************************/

 /* If the number of characters in INPUT(including the negative sign) is less
 than 10 digits, fill in the space at the beginning, so that the number of
 spaces plus the number of characters in INPUT just meets 10 digits. */

#include <iostream>
#include <string>

int main(void)
{
	// reusable variable, place this variable outside of the loop
	std::string number = "";

	// infinite loop until cin meets EOF
	while (std::cin >> number) // read input as a string
	{
		// fill in the space at the beginning
		if (number.length() < 10) // if the original length of number < 10
		{
			// numberOfSpace = 10 - lengthOfNumber
			number = std::string(10 - number.length(), ' ') + number;
		}

		// output the number which is in correct format
		std::cout << number << std::endl;
	}

	return 0;
}