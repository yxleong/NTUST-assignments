/*****************************************************************//**
 * File : user.cpp
 * Author : Leong Yah Xuan
 * Create Date : May 4, 2023
 * Update Date : May 4, 2023
 * Description : This C++ program explores how the unnamed namespace works.
 *********************************************************************/
#include "user.h"

namespace
{
	/**
	* Intent : To judge if the username is valid.
	* Pre : The variable username must have a value.
	* Post : The function returns true if username contains exactly eight letters.
	*/
	bool isValid()
	{
		// check if username contain 8 characters
		if (username.length() != 8)
		{
			// if not return not valid
			return false;
		}

		// if contain exact eight characters
		for (const char& c : username) // loop all char
		{
			// check if the character is only letter
			if (!isalpha(c))
			{
				// if not return not valid
				return false;
			}
		}

		// return valid if exactly eight letters
		return true;
	}
}

//*************************************************************************************//
namespace Authenticate
{
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}

	string getUserName()
	{
		return username;
	}
}
//*************************************************************************************//