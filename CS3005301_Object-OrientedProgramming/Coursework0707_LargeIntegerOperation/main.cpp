/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 12, 2023
 * Update Date : April 15, 2023
 * Description : This C++ program implements the large integer operation.
 *********************************************************************/
#include "LargeInt.h"

int main(void)
{
	// reusable variable, place outside of the loop
	std::string strA = "", strB = "";

	// infinite loop until cin meets EOF
	while (std::cin >> strA >> strB)
	{
		// define the string to LargeInt
		LargeInt numA(strA);
		LargeInt numB(strB);

		// output the results
		std::cout << numA + numB << std::endl; // addition
		std::cout << numA - numB << std::endl; // subtraction
		std::cout << numA * numB << std::endl; // multiplication
	}

	return 0;
}
