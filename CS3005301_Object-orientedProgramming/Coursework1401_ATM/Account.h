/*****************************************************************//**
 * File: Account.h
 * Author: Leong Yah Xuan
 * Create Date: May 30, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement two classes to handle exceptions.
 *********************************************************************/
#pragma once
#include "InsufficientFunds.h"
#include "NegativeDeposit.h"

class Account
{
private:
	double balance;
public:
	// Constructor
	Account();
	Account(double initialDeposit);

	double getBalance();

	// return new balance or throw appropriate exceptions if error 
	double deposit(double amount);

	// return new balance or throw appropriate exceptions if invalid amount 
	double withdraw(double amount);
};
