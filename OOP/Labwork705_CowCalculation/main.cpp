/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 16, 2023
 * Update Date : April 19, 2023
 * Description : This C++ program implements cow calculation.
 *********************************************************************/
#include <iostream>
#include <string>

 /**
 * Intent : To convert string symbol to integer marks.
 * Pre : The variable symbol must have a value.
 * Post : The function returns the volume of a sphere.
 * \param symbol
 * \return
 */
int strToInt(std::string symbol)
{
	int mark = 0;

	// loop through each character in the string
	for (auto c : symbol)
	{
		mark *= 4; // since base-4 calculation

		if (c == 'U')
		{
			mark += 1;
		}
		else if (c == 'C')
		{
			mark += 2;
		}
		else if (c == 'D')
		{
			mark += 3;
		}
		else
		{
			continue;
		}
	}

	return mark;
}

int main(void)
{
	std::cout << "COWCULATIONS OUTPUT" << std::endl;

	// reusable variable, place outside of the loop
	int tablets = 0;

	// read the the number of tablets represented
	std::cin >> tablets;

	for (; tablets > 0; tablets--)
	{
		// declare variables which are needed
		std::string cowNumberStr1 = "", cowNumberStr2 = "", result = "";
		int num1 = 0, num2 = 0;

		// read the first two lines
		std::cin >> cowNumberStr1 >> cowNumberStr2;

		// convert the string to int
		num1 = strToInt(cowNumberStr1);
		num2 = strToInt(cowNumberStr2);

		// read the next three lines
		for (int i = 0; i < 3; i++)
		{
			char operation = 0;

			// read the operation character
			std::cin >> operation;

			if (operation == 'A')
			{
				num2 += num1; // addition
			}
			else if (operation == 'R')
			{
				num2 >>= 2; // shifted right one position
			}
			else if (operation == 'L')
			{
				num2 <<= 2; // shifted left one position
			}
			else // ohter or 'N' null operation which no effect
			{
				continue;
			}
		}

		// read the last line
		std::cin >> result;

		// check if the output of tablet follows Dr. Vine's hypothesis
		if (strToInt(result) == num2)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}

	std::cout << "END OF OUTPUT" << std::endl;

	return 0;
}