/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 14, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program reads-in an integer n
 *					and outputs string "Hello World!" for n times.
 *********************************************************************/

#include <iostream>

int main(void)
{
	// reusable variable, place this variable outside of the loop
	int nTimes = 0;

	// infinite loop until cin meets EOF
	while (std::cin >> nTimes) // read input as a int
	{
		for (int i = 0; i < nTimes; i++) // loop until i = nTimes
		{
			// output n times "Hello World"
			std::cout << "Hello World!" << std::endl;
		}
	}

	return 0;
}