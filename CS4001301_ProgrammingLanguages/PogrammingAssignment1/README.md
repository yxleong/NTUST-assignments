Banking System
=====================================================================

Design and implement a simple simulation of a banking system in Java.

Problem description
-------------------

All bank accounts can perform the following basic operations:

- `deposit`: Deposit money into the account.

- `withdraw`: withdraw money from the account.

- `name`: Return the account's name.

- `balance`: Return the account's balance.

- `compute_interest`: Compute the interest accrues since the last time it was computed, and add it to the account balance.
  
There are 4 different kinds of accounts:

- `Checking`: interest is computed daily; there's no fee for withdrawals; there is a minimum balance of $1000.
  
- `Saving`: monthly interest; fee of $1 for every transaction, except the first three per month are free; no minimum balance.
  
- `CD`: monthly interest; fixed amount and duration (e.g., can open 1 12-month CD for $5000; for the next 12 months can't deposit anything and withdrawals cost a  $250 fee); at the end of the duration the interest payments stop and can withdraw w/o fee.
  
- `Loan`: like a saving account, but the balance is "negative" (owe the bank money, so a deposit will reduce the amount of the loan); can't withdraw (i.e., loan more money) but of course can deposit (i.e., pay off part of the loan).
  
Assume that the interest rate of an account is determined when it is created, and that it will not change. Use a simple interest calculation that ignores compounding; e.g., if an account has 12% yearly interest can use 12%/12 = 1% as the monthly rate and
12%/365 as the daily rate even though this is incorrect (of course).

If a method encounters an error condition (such as trying to withdraw too much money from an account) it should use an exception to signal the error to the caller.

Also write a simple test program that creates at lease one account of each type and uses each method at least once. The test should also exercise the error cases.
