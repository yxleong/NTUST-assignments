/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 16, 2023
 * UPDATE Date : March 21, 2023
 * Description : This C++ program calculates the maximum positive integer N
						where N! is within the CPU calculation range
						of the current year by a given year Y.
 *********************************************************************/

#include <iostream>
#include <math.h>

int main(void)
{
	// reusable variable, place this variable outside of the loop
	int year = 0;

	// infinite loop until cin meets EOF
	while (std::cin >> year) // read input as a int
	{
		// declare variables which are needed
		int kGrowth = 0, maxPositiveInteger = 0;
		double calculationRange = 0, integerProcess = 0;

		// Every 10 years[/10], k will grow by a multiple of 2.
		// Assume that your company released a 4 - bit CPU in 1900[-1900]
		kGrowth = (year - 1900) / 10;

		// Assume that your company released a 4[k=4] - bit CPU in 1900
		// maximum integer of a k - bit CPU can process is(2 ^ k) ¨C 1
		// log(k) = log(2^k - 1) = log(2^k) = k * log(2)
		calculationRange = 4 * log(2);

		for (int i = 0; i < kGrowth; i++) // loop until i = kGrowth
		{
			// Every 10 years, k will grow by a multiple of 2[*2]
			// so as the calculation range
			calculationRange *= 2;
		}

		while (integerProcess < calculationRange) // loop until integerProcess = calculationRange
		{
			// N increase
			maxPositiveInteger += 1;

			// log(N!) = log(1) + log(2) + log(3) + ... + log(N)
			integerProcess += log(maxPositiveInteger);
		}

		// deduct 1 to let the integer within calculation range
		std::cout << maxPositiveInteger - 1 << std::endl;
	}

	return 0;
}