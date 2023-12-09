
/*****************************************************************
    CS4001301 Programming Languages                   
    
    Programming Assignment #1
    
    Java programming using subtype, subclass, and exception handling
    
    To compile: %> javac Application.java
    
    To execute: %> java Application

******************************************************************/

import java.util.*;

class BankingException extends Exception {
    BankingException () { super(); }
    BankingException (String s) { super(s); }
} 

interface BasicAccount {
    String name();
    double balance();	
}

interface WithdrawableAccount extends BasicAccount {
    double withdraw(double amount) throws BankingException;	
}

interface DepositableAccount extends BasicAccount {
    double deposit(double amount) throws BankingException;	
}

interface InterestableAccount extends BasicAccount {
    double computeInterest() throws BankingException;	
}

interface FullFunctionalAccount extends WithdrawableAccount,
                                        DepositableAccount,
                                        InterestableAccount {
}

public abstract class Account {
	
    // protected variables to store commom attributes for every bank accounts	
    protected String accountName;
    protected double accountBalance;
    protected double accountInterestRate;
    protected Date openDate;
    protected Date lastInterestDate;
    
    // public methods for every bank accounts
    public String name() {
    	return(accountName);	
    }	
    
    public double balance() {
        return(accountBalance);
    }

    // to handle the transaction counting
    abstract double deposit(double amount, Date depositDate) throws BankingException;
    
    public double deposit(double amount) throws BankingException{
        //accountBalance += amount;
        //return(accountBalance);
        Date depositDate = new Date();  // today date
        return(deposit(amount, depositDate));
    } 
    
    abstract double withdraw(double amount, Date withdrawDate) throws BankingException;
    
    public double withdraw(double amount) throws BankingException {
        Date withdrawDate = new Date();
        return(withdraw(amount, withdrawDate));
    }
    
    abstract double computeInterest(Date interestDate) throws BankingException;
    
    public double computeInterest() throws BankingException {
        Date interestDate = new Date();
        return(computeInterest(interestDate));
    }
}

/*
 *  Derived class: CheckingAccount
 *n
 *  Description:
 *      Interest is computed daily; there's no fee for
 *      withdraw; there is a minimum balance of $1000.
 */
                          
class CheckingAccount extends Account implements FullFunctionalAccount {

    CheckingAccount(String s, double firstDeposit) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;	
    }
    
    CheckingAccount(String s, double firstDeposit, Date firstDate) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;	
    }

    public double deposit(double amount, Date depositDate) throws BankingException {
        System.out.println("The deposit amount is " + amount);
        if (amount <= 0) {
            throw new BankingException ("Invalid deposit amount is detected");
        } else {
            accountBalance += amount;	
            return(accountBalance);    
        }   	
    }

    public double withdraw(double amount, Date withdrawDate) throws BankingException {
        System.out.println("The withdrawal amount is " + amount);
        if (amount <= 0) {
            throw new BankingException ("Invalid withdrawal amount is detected");
        } else {
        // minimum balance is 1000, raise exception if violated
            if ((accountBalance  - amount) < 1000) {
                throw new BankingException ("Underfraft from checking account name:" +
                                            accountName);
            } else {
                accountBalance -= amount;	
                return(accountBalance); 	
            }
        }                           	
    }
    
    public double computeInterest (Date interestDate) throws BankingException {
        System.out.println("The last interest date is " + lastInterestDate);
        System.out.println("The interest date is " + interestDate);

        if (interestDate.before(lastInterestDate)) {
            throw new BankingException ("Invalid date to compute interest for account name:" +
                                        accountName);                            	
        }

        int numberOfDays = (int) ((interestDate.getTime() 
                                   - lastInterestDate.getTime())
                                   / 86400000.0);
        System.out.println("Number of days since last interest is " + numberOfDays);
        double interestEarned = (double) numberOfDays / 365.0 *
                                      accountInterestRate * accountBalance;

        // Generally in the lending industry, computed amounts are rounded to the second decimal place
        interestEarned = Math.round(interestEarned * 100.0) / 100.0;

        System.out.println("Interest earned is " + interestEarned); 
        lastInterestDate = interestDate;
        accountBalance += interestEarned;

        // Generally in the lending industry, computed amounts are rounded to the second decimal place
        accountBalance = Math.round(accountBalance * 100.0) / 100.0;

        return(accountBalance);                            
    }  	
}           

/*
 *  Derived class: SavingAccount
 *
 *  Description:
 *      Monthly interest; fee of $1 for every transaction, 
 *      except the first three per month are free; 
 *      no minimum balance.
 */
                          
class SavingAccount extends Account implements FullFunctionalAccount {

    SavingAccount(String s, double firstDeposit) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;	
    }
    
    SavingAccount(String s, double firstDeposit, Date firstDate) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;	
    }	

    // to record every transaction calendar(date & time)
    ArrayList<Calendar> transacRec = new ArrayList<Calendar>();

    // to check if the transaction is the first three times
    private boolean isFirst3transac(Date transacDate, boolean isChecked) {
        int transacCount = 0;

        Calendar transacCalendar = Calendar.getInstance();
        transacCalendar.setTime(transacDate); 

        // count itself first
        transacCount += 1;
        
        // count on if same month with the recorded transaction calendars
        for (int i = 0; i < transacRec.size(); i++) {
            if (transacCalendar.get(Calendar.YEAR) == transacRec.get(i).get(Calendar.YEAR) &&
                transacCalendar.get(Calendar.MONTH) == transacRec.get(i).get(Calendar.MONTH))
                transacCount++;
        }
        
        // if function run twice, mean the valid amount is checked
        if (isChecked) {
            transacRec.add(transacCalendar); 
            System.out.println("Number of transaction per month is " + transacCount);           
        }

        // if function run first time, check if the transaction is the first three times
        if (!isChecked && transacCount <= 3) {
            return true;
        }
        return false;
    }

    public double deposit(double amount, Date depositDate) throws BankingException {
        System.out.println("The deposit amount is " + amount);
        System.out.println("The deposit date is " + depositDate);
        if (amount <= 0) {
            throw new BankingException ("Invalid deposit amount is detected");
        } else {
        // transaction fee for the first three per month are free
            if (isFirst3transac(depositDate, false)) {
                // to get the output of transaction number
                isFirst3transac(depositDate, true);
                accountBalance += amount;
            } else { // fee of $1 for every transaction
                // to get the output of transaction number
                isFirst3transac(depositDate, true);
                System.out.println("A transaction fee of $1 is required for the upcoming deposit");
                accountBalance += (amount - 1);
            }
            return(accountBalance);
        }
    }

    public double withdraw(double amount, Date withdrawDate) throws BankingException {
        System.out.println("The withdrawal amount is " + amount);
        System.out.println("The withdraw date is " + withdrawDate);
        if (amount <= 0) {
            throw new BankingException ("Invalid withdrawal amount is detected");
        } else {
        // transaction fee for the first three per month are free
            if (isFirst3transac(withdrawDate, false)) {
            // no minimum balance, raise exception if over amount            
                if ((accountBalance  - amount) < 0) {
                    throw new BankingException ("Underfraft from saving account name:" +
                                            accountName);
                } else {
                    // to get the output of transaction number
                    isFirst3transac(withdrawDate, true);
                    accountBalance -= amount;	
                    return(accountBalance); 	
                }
            } else { // fee of $1 for every transaction
            // no minimum balance, raise exception if over amount    
                if ((accountBalance  - amount - 1) < 0) {   // include the $1 fee
                    throw new BankingException ("Underfraft from saving account name:" +
                                            accountName);
                } else {
                    // to get the output of transaction number
                    isFirst3transac(withdrawDate, true);
                    System.out.println("A transaction fee of $1 is required for the upcoming withdrawal");
                    accountBalance -= (amount + 1); // include the $1 fee
                    return(accountBalance);
                }
            }
        }
    }

    public double computeInterest (Date interestDate) throws BankingException {
        System.out.println("The last interest date is " + lastInterestDate);
        System.out.println("The interest date is " + interestDate);

        if (interestDate.before(lastInterestDate)) {
            throw new BankingException ("Invalid date to compute interest for account name:" +
                                        accountName);                            	
        }    

        int numberOfDays = (int) ((interestDate.getTime() 
                                   - lastInterestDate.getTime())
                                   / 86400000.0);

        // If an interest period corresponds to a calendar month
        int numberOfMonths = (int) (numberOfDays / 30); // the interest using the 30/360 method

        // change output to month instead of day
        System.out.println("Number of months since last interest is " + numberOfMonths);
        
        // use 12%/12 = 1% as the monthly rate
        double interestEarned = (double) numberOfMonths / 12.0 *
                                      accountInterestRate * accountBalance;

        // Generally in the lending industry, computed amounts are rounded to the second decimal place
        interestEarned = Math.round(interestEarned * 100.0) / 100.0;

        System.out.println("Interest earned is " + interestEarned); 
        lastInterestDate = interestDate;
        accountBalance += interestEarned;

        // Generally in the lending industry, computed amounts are rounded to the second decimal place
        accountBalance = Math.round(accountBalance * 100.0) / 100.0;

        return(accountBalance);                            
    }  	
}           

/*
 *  Derived class: CDAccount
 *
 *  Description:
 *      Monthly interest; fixed amount and duration (e.g., you can open
 *      1 12-month CD for $5000; for the next 12 months you can't deposit
 *      anything and withdrawals cost a  $250 fee); at the end of the 
 *      duration the interest payments stop and you can withdraw w/o fee.
 */
                          
class CDAccount extends Account implements FullFunctionalAccount {

    Calendar maturityCalendar = Calendar.getInstance();

    CDAccount(String s, double firstDeposit, int duration) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;	

        // calculate maturity date using given duration
        maturityCalendar.setTime(openDate);
        maturityCalendar.add(Calendar.MONTH, duration);
    }
    
    CDAccount(String s, double firstDeposit, Date firstDate, int duration) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;	

        // calculate maturity date using given duration
        maturityCalendar.setTime(openDate);
        maturityCalendar.add(Calendar.MONTH, duration);
    }	

    public double deposit(double amount, Date depositDate) throws BankingException { 
        System.out.println("The deposit amount is " + amount);
        if (amount <= 0) {
            throw new BankingException ("Invalid deposit amount is detected");
        } else {
            System.out.println("The deposit date is " + depositDate);
            System.out.println("The maturity date is " + maturityCalendar.getTime());
            if (depositDate.before(maturityCalendar.getTime())) {
                throw new BankingException ("No additional deposits allowed during the term for CD account name:" +
                                                    accountName);
            } else {
                accountBalance += amount;
                return(accountBalance);
            }
        }
    }

    public double withdraw(double amount, Date withdrawDate) throws BankingException {    
        System.out.println("The withdrawal amount is " + amount);
        if (amount <= 0) {
            throw new BankingException ("Invalid withdrawal amount is detected");
        } else {
            System.out.println("The withdrawal date is " + withdrawDate);   
            System.out.println("The maturity date is " + maturityCalendar.getTime());
        // check if stil in duration given
            if (withdrawDate.before(maturityCalendar.getTime())) {
            // no minimum balance, raise exception if over amount
                if ((accountBalance  - amount - 250) < 0) { // withdrawals cost a  $250 fee
                    throw new BankingException ("Underfraft from CD account name:" +
                                                accountName);
                } else {
                    System.out.println("A transaction fee of $250 is required for the upcoming withdrawal");
                    accountBalance -= (amount + 250);	// include the $250 fee
                    return(accountBalance); 	
                }  
            } else {    // at the end of the duration withdraw without fee
            // no minimum balance, raise exception if over amount
                if ((accountBalance  - amount) < 0) {
                    throw new BankingException ("Underfraft from CD account name:" +
                                                accountName);
                } else {
                    accountBalance -= amount;	
                    return(accountBalance); 	
                }
            }                                	
        }
    }
    
    public double computeInterest (Date interestDate) throws BankingException {
        System.out.println("The last interest date is " + lastInterestDate);
        System.out.println("The interest date is " + interestDate);
        System.out.println("The maturity date is " + maturityCalendar.getTime());

        if (interestDate.before(lastInterestDate)) {
            throw new BankingException ("Invalid date to compute interest for account name:" +
                                        accountName);                         	
        } else {
            // at the end of the duration the interest payments stop
            if (interestDate.after(maturityCalendar.getTime())) {
                interestDate = maturityCalendar.getTime();
            }

            int numberOfDays = (int) ((interestDate.getTime() 
                                    - lastInterestDate.getTime())
                                    / 86400000.0);

            // If an interest period corresponds to a calendar month
            int numberOfMonths = (int) (numberOfDays / 30); // the interest using the 30/360 method
            
            // change output to number of month which before the maturity date only
            System.out.println("Number of months since last interest before maturity date is " + numberOfMonths);
           
            // use 12%/12 = 1% as the monthly rate
            double interestEarned = (double) numberOfMonths / 12.0 *
                                        accountInterestRate * accountBalance;

            // Generally in the lending industry, computed amounts are rounded to the second decimal place
            interestEarned = Math.round(interestEarned * 100.0) / 100.0;   

            System.out.println("Interest earned is " + interestEarned);
            lastInterestDate = interestDate;
            accountBalance += interestEarned;

            // Generally in the lending industry, computed amounts are rounded to the second decimal place
            accountBalance = Math.round(accountBalance * 100.0) / 100.0;

            return(accountBalance); 
        }                   
    }  	
}           

/*
 *  Derived class: LoanAccount
 *
 *  Description:
 *      Like a saving account, but the balance is "negative" (you owe
 *      the bank money, so a deposit will reduce the amount of the loan);
 *      you can't withdraw (i.e., loan more money) but of course you can 
 *      deposit (i.e., pay off part of the loan).
 */
                          
class LoanAccount extends Account implements FullFunctionalAccount {

    LoanAccount(String s, double firstDeposit) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = new Date();
        lastInterestDate = openDate;	
    }
    
    LoanAccount(String s, double firstDeposit, Date firstDate) {
        accountName = s;
        accountBalance = firstDeposit;
        accountInterestRate = 0.12;
        openDate = firstDate;
        lastInterestDate = openDate;	
    }	

    public double deposit(double amount, Date depositDate) throws BankingException {
        System.out.println("The deposit amount is " + amount);
        if (amount <= 0 || accountBalance + amount > 0) {   // the balance must be "negative"
            throw new BankingException ("Invalid deposit amount is detected");
        } else {
            accountBalance += amount;
        // check if it is fully paid off
            if (accountBalance == 0) {
                System.out.println("The loan account has been fully paid off");
            }
            return(accountBalance);            
        }
    }
    
    public double withdraw(double amount, Date withdrawDate) throws BankingException {
    // owe the bank money, can't loan more money
        System.out.println("The withdrawal amount is " + amount);
        throw new BankingException ("A withdrawal is not permitted for the loan account name:" +
                                         accountName);
    }
    
    public double computeInterest (Date interestDate) throws BankingException {
        System.out.println("The last interest date is " + lastInterestDate);
        System.out.println("The interest date is " + interestDate);
        
        if (interestDate.before(lastInterestDate)) {
            throw new BankingException ("Invalid date to compute interest for account name:" +
                                        accountName);                            	
        }    

        int numberOfDays = (int) ((interestDate.getTime() 
                                   - lastInterestDate.getTime())
                                   / 86400000.0);

        // If an interest period corresponds to a calendar month
        int numberOfMonths = (int) (numberOfDays / 30); // the interest using the 30/360 method
        
        // change output to month instead of day
        System.out.println("Number of months since last interest is " + numberOfMonths);
        
        // use 12%/12 = 1% as the monthly rate
        double interestEarned = (double) numberOfMonths / 12.0 *
                                      accountInterestRate * accountBalance;

        // Generally in the lending industry, computed amounts are rounded to the second decimal place
        interestEarned = Math.round(interestEarned * 100.0) / 100.0;

        System.out.println("Interest earned is " + interestEarned); 
        lastInterestDate = interestDate;
        accountBalance += interestEarned;

        // Generally in the lending industry, computed amounts are rounded to the second decimal place
        accountBalance = Math.round(accountBalance * 100.0) / 100.0;

        return(accountBalance);                               
    }  	
}           