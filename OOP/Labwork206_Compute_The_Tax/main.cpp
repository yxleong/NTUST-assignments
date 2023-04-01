/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 9, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program calculates the tax payable of citizens
 *					based on the table given.
 *********************************************************************/

#include <iostream>
#include <iomanip>

int main(void)
{
	// reusable variables, place these variable outside of the loop
	double income = 0;

	// infinite loop until cin meets EOF
	while (std::cin >> income) // read input as a double
	{
		if (income <= 750) // if Not over $750
		{
			// output 1% of income
			std::cout << std::fixed << std::setprecision(2) << income * 0.01 << std::endl;
		}
		else if (income <= 2250)
		{
			// output $7.50 plus 2% of amount over $750
			std::cout << std::fixed << std::setprecision(2) << 7.50 + (income - 750) * 0.02 << std::endl;
		}
		else if (income <= 3750)
		{
			// output $37.50 plus 3% of amount over $2,250
			std::cout << std::fixed << std::setprecision(2) << 37.50 + (income - 2250) * 0.03 << std::endl;
		}
		else if (income <= 5250)
		{
			// output $82.50 plus 4% of amount over $3,750
			std::cout << std::fixed << std::setprecision(2) << 82.50 + (income - 3750) * 0.04 << std::endl;
		}
		else if (income <= 7000)
		{
			// output $142.50 plus 5% of amount over $5,250
			std::cout << std::fixed << std::setprecision(2) << 142.50 + (income - 5250) * 0.05 << std::endl;
		}
		else // output Over $7,000
		{
			// $230.00 plus 6% of amount over $7,000
			std::cout << std::fixed << std::setprecision(2) << 230.00 + (income - 7000) * 0.06 << std::endl;
		}
	}

	return 0;
}