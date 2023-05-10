/*****************************************************************//**
 * File : PrimeNumber.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 27, 2023
 * Update Date : May 1, 2023
 * Description : This C++ program stores a prime number.
 *********************************************************************/
#include "PrimeNumber.h"

 /**
 * Intent : To get the value of this PrimeNumber.
 * Pre : The variable value must be a prime.
 * Post : The function returns the value of this PrimeNumber.
 * \return
 */
int PrimeNumber::get()
{
	// return the value of this PrimeNumber
	return value;
}

/**
* Intent : To construct a PrimeNumber where the value is 1.
* Pre : The variable value must be well-defined.
* Post : The function returns the value of PrimeNumber, which is 1.
*/
PrimeNumber::PrimeNumber()
{
	// construct a PrimeNumber where the value is 1
	value = 1;
}

/**
* Intent : To construct a PrimeNumber where the value is _value.
* Pre : The variable _value must have a value and _value is a prime.
* Post : The function returns the value of PrimeNumber, which is _value.
* \param _value
*/
PrimeNumber::PrimeNumber(int _value)
{
	// construct a PrimeNumber where the value is _value
	value = _value;
}

/**
* Intent : To check if the value of a PrimeNumber is a prime.
* Pre : The variable value must have a value.
* Post : The function returns the boolean value which indicates if a PrimeNumber is a prime.
* \param value
* \return
*/
bool isPrime(int value)
{
	for (int num = 2; num * num <= value; num++)
	{
		if (value % num == 0)
		{
			//  once found any number for division has no remainder
			return false; // not a prime
		}
	}

	// if loop all except itself and 1, all got remainder
	return true; // is a prime
}

/**
* Intent : To get the next larger prime number.
* Pre : The variable value must have a valid value.
* Post : The function returns the next larger prime number.
* \return
*/
PrimeNumber& PrimeNumber::operator++() // prefix: ++p
{
	do // value = 13 -> 14 -> 15 -> 16
	{
		value++; // then value = 13 -> 14 -> 15 -> 16 first then +1
	} while (!isPrime(value)); // check isPrime 14 -> 15 -> 16 -> 17 => yes
	// stop loop when the next larger prime number is found

	return *this; // value incremented by 1
	// modify and return a reference to the object PrimeNumber
}

/**
* Intent : To get the next larger prime number.
* Pre : The variable of int must be a valid value 1.
* Post : The function returns the next larger prime number.
* \param
* \return
*/
PrimeNumber PrimeNumber::operator++(int) // postfix: p++
{
	// copy current object PrimeNumber by constructor
	PrimeNumber result(*this); // value of the current PrimeNumber before it is incremented

	// increments the value of the current PrimeNumber to the next larger prime number
	++(*this); // call prefix function

	// return the original value => before the current PrimeNumber was incremented
	return result;
}

/**
* Intent : To get the next smaller prime number.
* Pre : The variable value must have a valid value.
* Post : The function returns the next smaller prime number.
* \return
*/
PrimeNumber& PrimeNumber::operator--() // prefix: --p
{
	do // value = 13 -> 12 -> 11 -> 10
	{
		value--; // then value = 13 -> 12 -> 11 -> 10 first then -1
	} while (value > 2 && !isPrime(value)); // check isPrime 14 -> 13 -> 12 -> 11 => yes
	// stop loop when the next smaller prime number is found

	return *this; // value decremented by 1
	// modify and return a reference to the object PrimeNumber
}

/**
* Intent : To get the next smaller prime number.
* Pre : The variable of int must be a valid value 1.
* Post : The function returns the next smaller prime number.
* \param
* \return
*/
PrimeNumber PrimeNumber::operator--(int) // postfix: p--
{
	// copy current object PrimeNumber by constructor
	PrimeNumber result(*this); // value of the current PrimeNumber before it is decremented

	// decrements the value of the current PrimeNumber to the next smaller prime number
	--(*this); // call prefix function

	// return the original value => before the current PrimeNumber was decremented
	return result;
}