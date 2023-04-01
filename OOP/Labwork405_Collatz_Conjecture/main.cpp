/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 23, 2023
 * UPDATE Date : March 23, 2023
 * Description : This C++ program finds out the cycle length of a number
 *					by using Collatz conjecture.
 *********************************************************************/

#include <iostream>
#include <algorithm>

 /**
 * Intent : To get the cycle length of a given number.
 * Pre : The variable num must have a value and num > 0.
 * Post : The function returns the cycle length of a number.
 * \param num
 * \return
 */
int getCycleLength(int num)
{
	// declare variable which is needed
	int count = 0;

	// If num equals 1, end calculation
	while (num != 1)
	{
		// if num is an even number
		if (num % 2 == 0)
		{
			num /= 2;
		}
		else // if num is an odd number
		{
			num = num * 3 + 1;
		}
		count++;
	}

	return count;
}

int main(void)
{

	// reusable variables, place these variables outside of the loop
	int num1 = 0, num2 = 0;

	// infinite loop until cin meets EOF
	while (std::cin >> num1 >> num2)
	{
		// declare variable which is needed
		int maxCycleLength = 0;

		// find the maximum cycle length that can be produced by any numbers between num1 and num2
		for (int i = std::min(num1, num2); i <= std::max(num1, num2); i++)
		{
			// call function to get the cycle length of a number
			int cycleLength = getCycleLength(i);

			if (cycleLength > maxCycleLength) // if found
			{
				maxCycleLength = cycleLength; // replace it with the new value
			}
		}

		// output the result required
		// +1 to include counting the 1
		std::cout << num1 << " " << num2 << " " << maxCycleLength + 1 << std::endl;
	}

	return 0;
}
