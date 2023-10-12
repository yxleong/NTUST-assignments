# Class Bank Account

## Problem Statement
Define a class named BankAccount to simulate bank deposits.

The class BankAccount has two variables:
* `static total(int)`: store the total money amount of all accounts in the bank.
* `balance(int)`: store the money amount of this account.

The class BankAccount has two constructors:
* `BankAccount()`: construct a BankAccount where the balance is 0.
* `BankAccount(int input)`: construct a BankAccount where the balance is `input`.

You should implement the following functions:
* `void withdraw(int output)`: withdraw money in the bank with the value of `output`.
* `void save(int input)`: save money in the bank with the value of `input`.
* `int getBalance()`: return the current balance of this account.
* `int getAllMoneyInBank()`: return the value of the total money amount in the bank.

### Input
No inputs for this exercise.

### Output
The result of executing your program with the given main function.
```
100
100
0
50
50
```

## Note
main.cpp
```cpp
int main() {
	BankAccount bankAccount1(200), bankAccount2, bankAccount3(-100);
	cout << BankAccount::getAllMoneyInBank() << endl;
	bankAccount1.withdraw(100);
	cout << bankAccount1.getBalance() << endl;
	cout << BankAccount::getAllMoneyInBank() << endl;
	bankAccount2.save(50);
	cout << bankAccount2.getBalance() << endl;
	cout << BankAccount::getAllMoneyInBank() << endl;
	return 0;
}
```

## Additional Information
* Eazy, only basic programming syntax and structure are required.
* Solving time: 10 minutes
* Contributors: 邱韋霖, 鄭永泰, 范茗翔
