/*****************************************************************//**
 * File : password.h
 * Author : Leong Yah Xuan
 * Create Date : May 4, 2023
 * Update Date : May 4, 2023
 * Description : This C++ program explores how the unnamed namespace works.
 *********************************************************************/
#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace // create an unnamed namespace
{
	// define password variable
	string password = "";

	// define the isValid() function
	bool isValid();
}

// define the namespace given
namespace Authenticate
{
	void inputPassword();
	string getPassword();
}
