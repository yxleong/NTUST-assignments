/*****************************************************************//**
 * File : BankAccount.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 28, 2023
 * UPDATE Date : March 28, 2023
 * Description : This C++ program defines a class named BankAccount
 *					to simulate bank deposits.
 *********************************************************************/

#include "BankAccount.h"

 // static data member of the class only provides a [declaration]
 // so need to be [defined] outside the class
int BankAccount::total = 0;
// store the total money amount of all accounts in the bank

BankAccount::BankAccount()
{
	// construct a BankAccount where the balance is 0
	balance = 0;
	// store the money amount of the account
}

BankAccount::BankAccount(int input)
{
	// construct a BankAccount where the balance is input
	balance = input;

	// add on the balance of all bank accounts
	total += balance;
}

/**
* Intent : To withdraw money in the bank with the value of output.
* Pre : The variable output must have a value and output > 0.
* Post : The function decreases the values of balance of each account and total balance of accounts.
* \param output
*/
void BankAccount::withdraw(int output)
{
	// deduct the withdraw from balance
	balance -= output;

	// deduct the withdraw from total
	total -= output;
}

/**
* Intent : To save money in the bank with the value of input.
* Pre : The variable input must have a value and input > 0.
* Post : The function increases the values of balance of each account and total balance of accounts.
* \param input
*/
void BankAccount::save(int input)
{
	// add on saving money to balance
	balance += input;

	// add on saving money to total
	total += input;
}

/**
* Intent : To get the current balance of the account.
* Pre : The variable balance must have a value.
* Post : The function returns the current balance of the account.
* \return
*/
int BankAccount::getBalance()
{
	return balance;
}

/**
* Intent : To get the value of the total money amount in the bank.
* Pre : The variable total must have a value.
* Post : The function returns the value of the total money amount in the bank.
* \return
*/
int BankAccount::getAllMoneyInBank()
{
	return BankAccount::total;
}