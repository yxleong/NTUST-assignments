/*****************************************************************//**
 * File : main.cpp // HW cancelled
 * Author : Leong Yah Xuan
 * Create Date : April 12, 2023
 * Update Date : April 12, 2023
 * Description : This C++ program represents numbers in seven-segment
 *					by a given string.
 *********************************************************************/
#include <iostream>
#include <string>

int main(void)
{
	// create a fixed format for seven segment
	const std::string sevenSegmentformat[3] = {
		" _     _  _     _  _  _  _  _ ",
		"| |  | _| _||_||_ |_   ||_||_|",
		"|_|  ||_  _|  | _||_|  ||_| _|"
	};

	// reusable variable, place outside of the loop
	std::string inputStr = "";
	bool isFirst = true;

	// infinite loop until cin meets EOF
	while (std::cin >> inputStr) // read input as a string
	{
		// loop three layer of sevenSegmentformat
		for (int i = 0; i < 3; i++)
		{
			// loop all the character of the input string
			for (int j = 0; j < inputStr.length(); j++)
			{
				// check if character of number is a digit
				if (!isdigit(inputStr[j]))
				{
					// ignore the character that is not digit
					continue;
				}
				else // if the character of number is a digit
				{
					// defined current character of number as int
					int number = inputStr[j] - '0';

					// loop the index of the digit in format defined
					// [space]_[space], so total 3 place to move
					for (int k = number * 3; k < (number + 1) * 3; k++)
					{
						// output the certain layer of certain index of format
						std::cout << sevenSegmentformat[i][k];
					}

					// if is the last digit
					if (j == inputStr.length() - 1)
					{
						// after a layer done, enter
						std::cout << std::endl;
					}
					else // if not the last digit in string
					{
						// space to seperate
						std::cout << ' ';
					}
				}
			}
		}
	}

	return 0;
}