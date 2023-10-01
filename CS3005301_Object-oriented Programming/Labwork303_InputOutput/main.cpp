// Name: Leong Yah Xuan
// Date: March 16, 2023
// Last Update: March 21, 2023
// Problem statement: This C++ program reformats a given arbitrary number by following formats.

/*	X: The target number that need to be formed.
	M: The total length of the output. (Including negative sign and decimal point.)
	N: Number of reserved digits of the decimal part.
	C: Letter to be filled when the length is not enough. (less than M digits)
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <math.h>

int main(void)
{
	// reusable variable, place this variable outside of the loop
	double targetNumber = 0;
	int outputLength = 0, numDecimal = 0;
	std::string letterFill = "";

	// infinite loop until cin meets EOF
	while (std::cin >> targetNumber >> outputLength >> numDecimal)
	{
		// ignore the space
		std::cin.ignore();

		// read the letter to be fill, include the space
		std::getline(std::cin, letterFill);

		// declare variables which are needed
		double positiveNumber = abs(targetNumber);
		int integerLength = 0;

		// count the digit numbers by moving the decimal point in visual
		while (positiveNumber >= pow(10, integerLength))
		{
			integerLength++;
		}

		// count on the sign
		if (targetNumber < 0) // if negative
		{
			integerLength += 1; // increase
		}

		if (numDecimal > 0)
		{
			// -1 to deduct the decimal point
			int letterLength = outputLength - integerLength - numDecimal - 1;

			// fill in the character required
			if (letterLength > 0)
			{
				for (int i = 0; i < letterLength; i++) // loop until i = integerLength
				{
					// output letter
					std::cout << letterFill;
				}
			}

			// output formatted number
			std::cout << std::fixed << std::setprecision(numDecimal) << targetNumber - 0.0000000009 << std::endl;
		}
		else // if the no decimal
		{
			int letterLength = outputLength - integerLength;

			// fill in the character required
			if (letterLength > 0)
			{
				for (int i = 0; i < letterLength; i++) // loop until i = integerLength
				{
					// output letter
					std::cout << letterFill;
				}
			}

			int integerX = (int)targetNumber;

			// check if positive
			if (targetNumber >= 0)
			{
				// output formatted number without decimal
				std::cout << std::setprecision(integerLength) << integerX << std::endl;
			}
			else
			{
				// deduct for the negative sign
				integerLength -= 1;

				// output formatted negative number without decimal
				std::cout << std::setprecision(integerLength) << integerX << std::endl;
			}
		}
	}

	return 0;
}