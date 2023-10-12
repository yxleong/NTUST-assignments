/*****************************************************************//**
 * File : LargeInt.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 12, 2023
 * Update Date : April 15, 2023
 * Description : This C++ program implements the large integer operation.
 *********************************************************************/
#include "LargeInt.h"

 /**
 * Intent : To to initialize the number with a string input.
 * Pre : The variable num must have a value.
 * Post : The function assign the vector of LargeInt by string.
 * \param num
 */
LargeInt::LargeInt(std::string num)
{
	// check if the string is a negative number
	if (num[0] == '-')
	{
		// if yes, mark the negative
		isNegative = true;

		// ignore the negative sign
		num = num.substr(1);
	}
	else
	{
		// mark not negative
		isNegative = false;
	}

	// store the string digit by digit from backward, disascending order for original num
	for (int i = num.length() - 1; i >= 0; i--)
	{
		// store the value converted from char to int
		digits.push_back(num[i] - '0');
	}
}

/**
* Intent : To output the contents of LargeInt to an output stream.
* Pre : The variable num must have a value.
* Post : The function returns a reference to the output stream.
* \param os
* \param num
* \return
*/
std::ostream& operator<<(std::ostream& os, const LargeInt& num)
{
	// if the LargeInt is negative
	if (num.isNegative)
	{
		// output negative sign first
		os << "-";
	}

	// output the num digit by digit from backward, ascending order for original num
	for (int i = num.digits.size() - 1; i >= 0; i--)
	{
		os << num.digits[i];
	}

	// return the output reference
	return os;
}

/**
* Intent : To check if the LargeInt is less than other LargeInt.
* Pre : The variable other must have a value.
* Post : The function returns the boolean value of the comparison of both LargeInt.
* \param other
* \return
*/
bool LargeInt::operator<(const LargeInt& other)const
{
	// if the digits length different
	if (digits.size() != other.digits.size())
	{
		// return true if digits less than the other
		return digits.size() < other.digits.size();
		// otherwise return false
	}
	else // if the digits length are same
	{
		// loop the num digit by digit from backward, ascending order for original num
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			// if the number not same
			if (digits[i] != other.digits[i])
			{
				// if is negative, return true when that digit value more than other's digit £º 8 > 7
				//								since -8 < 7
				return isNegative ? digits[i] > other.digits[i] : digits[i] < other.digits[i];
				// if not negative, return true when that digit value less than other's digit : 8 < 9

			}
		}
	}

	// if digits length are same && all digits value also same
	return false;
}

/**
* Intent : To perform the addition of two LargeInt.
* Pre : The variable other must have a value.
* Post : The function returns the sum of two LargeInt.
* \param other
* \return
*/
LargeInt LargeInt::operator+(const LargeInt& other)const
{
	// declare variables which are needed
	LargeInt result;
	int carry = 0;

	// loop until the max(digits.size(), other.digits.size())
	for (int i = 0; i < digits.size() || i < other.digits.size(); i++)
	{
		// add on carry first
		int sum = carry;

		// add on the digits of LargeInt
		if (i < digits.size())
		{
			sum += digits[i];
		}

		// add on the digits of other LargeInt
		if (i < other.digits.size())
		{
			sum += other.digits[i];
		}

		// store the sum value which less than 10
		result.digits.push_back(sum % 10);

		// sava the value which more than 10 to carry
		carry = sum / 10;
	}

	// if loop all still have carry left
	if (carry)
	{
		// store the carry
		result.digits.push_back(carry);
	}

	// return the total of both LargeInt
	return result;
}

/**
* Intent : To perform the subtraction of two LargeInt.
* Pre : The variable other must have a value.
* Post : The function returns the difference of two LargeInt.
* \param other
* \return
*/
LargeInt LargeInt::operator-(const LargeInt& other)const
{
	// declare variables which are needed
	LargeInt result;
	int borrow = 0;

	// if LargeInt is less than other LargeInt
	if (*this < other)
	{
		// swap their order, and implement the operator-
		result = other - *this;

		// mark the subtraction of them is negative
		result.isNegative = true;

		// return the subtraction of both LargeInt
		return result;
	}

	// loop until the size of bigger LargeInt
	for (int i = 0; i < digits.size(); i++)
	{
		// deduct the previous borrow from digits first
		int diff = digits[i] - borrow;

		// then deduct the other's digits
		if (i < other.digits.size())
		{
			diff -= other.digits[i];
		}

		// if the difference less than 0
		if (diff < 0)
		{
			// borrow from previous digit
			borrow = 1;

			// add on 10 which borrowed
			diff += 10;
		}
		else // if not less than 0
		{
			// no need to borrow
			borrow = 0;
		}

		// store the difference value which > 0 but < 10
		result.digits.push_back(diff);
	}

	// check if the last digit is 0, which means 0 in first when vector be reversed
	while (result.digits.size() > 1 && result.digits.back() == 0)
	{
		// remove the zero to avoid showing in front after reversed
		result.digits.pop_back();
	}

	// return the subtraction of both LargeInt in correct format
	return result;
}

/**
* Intent : To perform the multiplication of two LargeInt.
* Pre : The variable other must have a value.
* Post : The function returns the product of two LargeInt.
* \param other
* \return
*/
LargeInt LargeInt::operator*(const LargeInt& other) const
{
	// declare variable which is needed
	LargeInt result;

	// if the both LargeInt have different sign, then result LargeInt will be negative
	result.isNegative = (isNegative != other.isNegative);

	// assign the size of result LargeInt be the sum of the size of both LargeInt
	result.digits.resize(digits.size() + other.digits.size());

	// loop until the size of the digits vector
	for (int i = 0; i < digits.size(); i++)
	{
		// initialize the carry for every digits
		int carry = 0;

		// loop until the size of the other digits vector
		// or until the carry is greater than 0
		for (int j = 0; j < other.digits.size() || carry > 0; j++)
		{
			// mark the storage place in result LargeInt
			int index = i + j;

			// initialize the product with the current digit of the result LargeInt
			// and add on the carry from the previous multiplication
			int product = result.digits[index] + carry;

			// if still have other's digit
			if (j < other.digits.size())
			{
				// add on product by the multiplication of current digit and all other digits
				product += digits[i] * other.digits[j];
			}

			// store the product value which less than 10
			result.digits[index] = product % 10;

			// store the product value which greater than 10 to carry
			carry = product / 10;
		}
	}

	// check if the last digit is 0, which means 0 in first when vector be reversed
	while (result.digits.size() > 1 && result.digits.back() == 0)
	{
		// remove the zero to avoid showing in front after reversed
		result.digits.pop_back();
	}

	// return the multiplication of both LargeInt in correct format
	return result;
}