/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : February 27, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program computes sphere volume.
 *********************************************************************/

#include <iostream>

int main(void)
{
	// reusable variables, place these variable outside of the loop
	long float radius = 0;

	// infinite loop until cin meets EOF
	while (std::cin >> radius) // read input as a long float
	{
		// declare variables which are needed
		long float volume = 0;
		const long float PI = 3.14159265358979323846;

		// derived value of sphere volume
		// formula: 4/3 * pi * r^3
		volume = 4.0 * PI * radius * radius * radius / 3.0;

		// output the calculated volume,
		// but with only 6 decimal
		printf("%.6f\n", volume);
	}

	return 0;
}