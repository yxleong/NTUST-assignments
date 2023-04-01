/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 23, 2023
 * UPDATE Date : March 23, 2023
 * Description : This C++ program use the recursive function
 *					to find the greatest common divisor
 *					of two positive integers.
 *********************************************************************/

#include <iostream>

 /**
 * Intent : To calculate the greatest common divisor with two given positive integers.
 * Pre : The variables num1,num2 must have a value and num1,num2 > 0.
 * Post : The function returns the greatest common divisor of two positive integers.
 * \param num1
 * \param num2
 * \return
 */
int findGreatestCommonDivisor(int num1, int num2)
{
	// check if num2 is zero
	if (num2 != 0)
	{
		// if not, save the last num2 to first parameter
		// let the second parameter calculate is num2 is the greatest common divisor for num1
		return findGreatestCommonDivisor(num2, num1 % num2);
	}
	else
	{
		// if yes, the last (num1 % num2) is 0
		// means find the last (num2) is a greatest common divisor for (num1)
		// also a greatest common divisor for (num2) itself
		// so direct return last (num2), which is current (num1)
		return num1;
	}
}

int main(void)
{
	// reusable variable, place this variable outside of the loop
	int input1 = 0, input2 = 0;

	// infinite loop until cin meets EOF
	while (std::cin >> input1 >> input2) // read input as int
	{
		// call the function
		// output the greatest common divisor of two positive integers
		std::cout << findGreatestCommonDivisor(input1, input2) << std::endl;
	}

	return 0;
}
