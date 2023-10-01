/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 9, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program adds large numbers
 *					not using long long, long long int, or _m128, etc.
 *********************************************************************/

#include <iostream>
#include <string>
#include <stdbool.h>
#include <ctype.h>

struct BigInt
{
	// declare variable which is needed
	std::string digits = "";
};

/**
* Intent : To calculate the sum of two BigInt.
* Pre : The variables lhs and rhs must be numA value and both > 0.
* Post : The function returns the sum of two BigInt.
* \param lhs
* \param rhs
* \return
*/
BigInt Add(const BigInt& lhs, const BigInt& rhs)
{
	// declare variables which are needed
	BigInt sum;
	BigInt lhsTemp, rhsTemp;
	int length = 0, carry = 0;

	// for adjust the const BigInt
	lhsTemp.digits = lhs.digits;
	rhsTemp.digits = rhs.digits;

	// initialize to lhs first
	length = lhsTemp.digits.length();

	// insert zero in front of the BigInt which length is smaller
	if (rhsTemp.digits.length() > length)
	{
		// adjust length to rhs if length of lhs < rhs
		length = rhsTemp.digits.length();

		// string& insert (size_t pos, size_t pair, char c);
		lhsTemp.digits.insert(0, length - lhsTemp.digits.length(), '0');
	}
	else
	{
		rhsTemp.digits.insert(0, length - rhsTemp.digits.length(), '0');
	}

	// calculate the sum of two BigInt from last digit
	for (int i = length; i >= 0; i--) // loop until i = 0
	{
		// declare variables which are needed
		int digitAdding = 0;

		digitAdding = (lhsTemp.digits[i] - '0') + (rhsTemp.digits[i] - '0') + carry;
		// string - '0' = int

		if (digitAdding >= 10) // if digit >= 10
		{
			carry = 1; // need to have carry
			digitAdding -= 10; // and digit have to - 10
		}
		else // if digit < 10
		{
			carry = 0; // no need carry
		}

		// insert digit always at index 0
		// the digits inserted will be push back
		sum.digits.insert(0, 1, digitAdding + '0');
		// int + '0' = string
	}

	if (carry == 1) // if after digit sum up all, still have carry
	{
		// insert one more 1 at index 0
		sum.digits.insert(0, 1, '1');
	}

	// remove last index '\0' which come from string
	sum.digits.erase(sum.digits.length() - 1);

	return sum;
}

int main(void)
{
	// reusable variables, place these variable outside of the loop
	BigInt numA, numB;
	int pair = 0;

	// get how mant pair of BigInt need to be added up
	std::cin >> pair; // read input as a int

	for (int i = 0; i < pair; i++) // loop until i = pair
	{
		// declare variable which is needed
		bool isValid = true;

		// read input as a string
		std::cin >> numA.digits >> numB.digits;

		// check if whole numA is digit
		for (int i = 0; i < numA.digits.length(); i++) // loop until i = length of numA
		{
			// if one of the digit of numA is not numeric
			if (!isdigit(numA.digits[i]))
			{
				isValid = false; // turn to false
			}
		}

		// check if whole numB is digit
		for (int i = 0; i < numB.digits.length(); i++) // loop until i = length of numB
		{
			// if one of the digit of numB is not numeric
			if (!isdigit(numB.digits[i]))
			{
				isValid = false; // turn to false 
			}
		}

		// check if both inputs are numeric
		if (isValid)
		{
			// call function
			BigInt result = Add(numA, numB);

			// output the result
			std::cout << result.digits << std::endl;
		}
		else // if not all digtis of inputs are numeric
		{
			// output the Invalid message
			std::cout << "Not a valid number, please try again." << std::endl;
		}
	}

	return 0;
}
