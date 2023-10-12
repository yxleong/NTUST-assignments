/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : February 27, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program converts the time format
 *					from(seconds) to(hours: minutes: seconds).
 *********************************************************************/

#include <iostream>

int main(void)
{
	// reusable variable, place this variable outside of the loop
	// 0 <= A <= 2^64-1
	unsigned long long int input = 0;

	// infinite loop until cin meets EOF
	while (std::cin >> input) // read input as an unsigned long long int
	{
		// declare variables which are needed
		unsigned long long int hour = 0, min = 0, second = 0;

		// convertion
		// formula: second / 60 = minute ; minute / 60 = hour;
		hour = input / 3600;
		min = (input % 3600) / 60; // module
		second = input % 60;

		// output with the format x hours y minutes and z seconds
		std::cout << hour << " hours " << min << " minutes and " << second << " seconds" << std::endl;
	}

	return 0;
}
