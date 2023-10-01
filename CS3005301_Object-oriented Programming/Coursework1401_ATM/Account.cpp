/*****************************************************************//**
 * File: Account.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 30, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement two classes to handle exceptions.
 *********************************************************************/
#include "Account.h"

 /*****************************************************************//**
 * Intent: To construct the class Account.
 * Pre: The variable balance must be well-defined.
 * Post: The function initializes the balance of account to 0.
 *********************************************************************/
Account::Account() : balance(0) {}

/*****************************************************************//**
 * Intent: To construct the class Account by given deposit.
 * Pre: The variable initialDeposit must have a value.
 * Post: The function initializes the balance of account by given deposit.
 * \param initialDeposit
 *********************************************************************/
Account::Account(double initialDeposit) {
	balance = initialDeposit;
}

/*****************************************************************//**
 * Intent: To get the balance of the account.
 * Pre: The variable balance must be well-defined.
 * Post: The function returns the balance of an account.
 * \return
 *********************************************************************/
double Account::getBalance() {
	return balance;
}

/*****************************************************************//**
 * Intent: To add the amount to balance of account.
 * Pre: The variable amount must have a value.
 * Post: The function returns new balance or throws appropriate exceptions if error.
 * \param amount
 * \return
 *********************************************************************/
double Account::deposit(double amount)
{
	if (amount > 0) {
		balance += amount;
	}
	else { // if error
		throw NegativeDeposit(); // error code
	}

	return balance;
}

/*****************************************************************//**
 * Intent: To deduct the amount from balance of account.
 * Pre: The variable amount must have a value.
 * Post: The function returns new balance or throws appropriate exceptions if invalid amount.
 * \param amount
 * \return
 *********************************************************************/
double Account::withdraw(double amount)
{
	// if invalid amount
	if ((amount > balance) || (amount < 0)) {
		throw InsufficientFunds(); // error code
	}
	else { // valid amount
		balance -= amount;
	}

	return balance;
}
