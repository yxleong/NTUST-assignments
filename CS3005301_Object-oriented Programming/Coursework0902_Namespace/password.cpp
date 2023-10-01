/*****************************************************************//**
 * File : password.cpp
 * Author : Leong Yah Xuan
 * Create Date : May 4, 2023
 * Update Date : May 4, 2023
 * Description : This C++ program explores how the unnamed namespace works.
 *********************************************************************/
#include "password.h"

namespace
{
	/**
	* Intent : To judge if the password is valid.
	* Pre : The variable password must have a value.
	* Post : The function returns true if the password has at least 8 characters including at least one non-letter.
	*/
	bool isValid()
	{
		// check if password has at least 8 characters 
		if (password.length() >= 8)
		{
			// if yes, loop all the characters
			for (const char& c : password)
			{
				// check if has at least one non-letter
				if (!isalpha(c))
				{
					// if found then return valid
					return true;
				}
			}
		}

		// if less than 8 character or all letter then return not valid
		return false;
	}
}

//*************************************************************************************//
namespace Authenticate
{
	void inputPassword()
	{
		do
		{
			cout << "Enter your password (at least 8 characters " <<
				"and at least one non-letter)" << endl;
			cin >> password;
		} while (!isValid());
	}

	string getPassword()
	{
		return password;
	}
}
//*************************************************************************************//