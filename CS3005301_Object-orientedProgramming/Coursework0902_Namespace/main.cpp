/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : May 4, 2023
 * Update Date : May 4, 2023
 * Description : This C++ program explores how the unnamed namespace works.
 *********************************************************************/
#include "password.h"
#include "user.h"

using namespace Authenticate; // to avoid always mention in code

//*************************************************************************************//
int main()
{
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() <<
		" and your password is: " <<
		getPassword() << endl;
	return 0;
}
//*************************************************************************************//