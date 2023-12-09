
/*****************************************************************
    CS4001301 Programming Languages                   
    
    Programming Assignment #1
    
    Java programming using subtype, subclass, and exception handling
    
    To compile: %> javac Application.java
    
    To execute: %> java Application

******************************************************************/

import java.util.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;

public class Application {
	
    public static void main( String args []) throws BankingException {
        /*
        Account a;
        Date d;
        double ret;
        
        a = new CheckingAccount("John Smith", 1500.0);
        
        try {
            ret = a.withdraw(100.00);
            System.out.println ("Account <" + a.name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, a.balance());	
        }
        
        a = new CheckingAccount("John Smith", 1500.0);
        
        try {
            ret = a.withdraw(600.00);
            System.out.println ("Account <" + a.name() + "> now has $" + ret + " balance\n");
        } catch (Exception e) {
            stdExceptionPrinting(e, a.balance());	
        }
        */

        /* put your own tests here ....... */
        /* if your implementaion is correct, you can do the following with polymorphic array accountList
            public Account[] accountList;
            
            accountList = new Account[4];
            
            // buid 4 different accounts in the same array
            accountList[0] = new CheckingAccount("John Smith", 1500.0);
            accountList[1] = new SavingAccount("William Hurt", 1200.0);
            accountList[2] = new CDAccount("Woody Allison", 1000.0);
            accountList[3] = new LoanAccount("Judi Foster", -1500.0);
            
            // compute interest for all accounts
            for (int count = 0; count < accountList.length; count++) {
                double newBalance = accountList[count].computeInterest();
                System.out.println ("Account <" + a.name() + "> now has $" + newBalance + " balance\n");
            }
        */
    
        Account[] accountList;
        
        accountList = new Account[4];

        Date openDate = parseDate("2023/06/01");
        Date halfYearDate = parseDate("2023/12/01");
        Date nextMonthDate = parseDate("2023/07/01");
        Date beforeLastInterestDate = parseDate("2023/11/01");
        Date afterMaturityDate = parseDate("2024/12/01");

        Date currentDate = new Date();
        long oneDayInMillis = 1000L * 60 * 60 * 24;
        Date tomorrowDate = new Date(currentDate.getTime() + oneDayInMillis);

        int duration = 12;  // 12-month
        
        // buid 4 different accounts in the same array
        accountList[0] = new CheckingAccount("John Smith", 1500.0, openDate);
        accountList[1] = new SavingAccount("William Hurt", 1200.0, openDate);
        accountList[2] = new CDAccount("Woody Allison", 5000.0, openDate, duration);
        accountList[3] = new LoanAccount("Judi Foster", -1500.0, openDate);
        
        for (int count = 0; count < accountList.length; count++) {
            // show initial balance
            System.out.println ("Account <" + accountList[count].name() + "> was opened on " + accountList[count].openDate);
            double newBalance = accountList[count].balance();
            System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");

            try { // withdraw zero money
                newBalance = accountList[count].withdraw(0.00);
                System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
            } catch (Exception e) {
                stdExceptionPrinting(e, accountList[count].balance());	
            }
            
            try { // withdraw possible money 1st
                newBalance = accountList[count].withdraw(100.00);
                System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
            } catch (Exception e) {
                stdExceptionPrinting(e, accountList[count].balance());	
            }

            // mot for loan account
            if (count != 3) {
                try { // withdraw possible money 2nd
                    newBalance = accountList[count].withdraw(200.00);
                    System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                } catch (Exception e) {
                    stdExceptionPrinting(e, accountList[count].balance());	
                }
                
                try { // withdraw possible money 3rd
                    newBalance = accountList[count].withdraw(100.00);                
                    System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                } catch (Exception e) {
                    stdExceptionPrinting(e, accountList[count].balance());	
                }
                
                try { // withdraw possible money 4th
                    newBalance = accountList[count].withdraw(100.00);                
                    System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                } catch (Exception e) {
                    stdExceptionPrinting(e, accountList[count].balance());	
                }
                
                try { // withdraw more money over minimum balance of checking account // same month withdrawal for saving account
                    newBalance = accountList[count].withdraw(300.00, tomorrowDate);                
                    System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                } catch (Exception e) {
                    stdExceptionPrinting(e, accountList[count].balance());	
                }

                // not for checking account
                if (count != 0) {
                    try { // withdraw money over balance without consideration transaction fees
                        newBalance = accountList[count].withdraw(398.00);                
                        System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                    } catch (Exception e) {
                        stdExceptionPrinting(e, accountList[count].balance());	
                    }

                    try { // withdraw money with no minimum balance
                        newBalance = accountList[count].withdraw(397.00);                
                        System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                    } catch (Exception e) {
                        stdExceptionPrinting(e, accountList[count].balance());	
                    }
                }

                // for only CD account
                if (count == 2) {
                    try { // withdraw money after maturity date
                        newBalance = accountList[count].withdraw(1400.00, afterMaturityDate);                
                        System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                    } catch (Exception e) {
                        stdExceptionPrinting(e, accountList[count].balance());	
                    }
                    
                    try { // withdraw money over balance
                        newBalance = accountList[count].withdraw(255.00);                
                        System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                    } catch (Exception e) {
                        stdExceptionPrinting(e, accountList[count].balance());	
                    }

                    try { // withdraw money with no minimum balance
                        newBalance = accountList[count].withdraw(5.00);                
                        System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                    } catch (Exception e) {
                        stdExceptionPrinting(e, accountList[count].balance());	
                    }
                }
            }

            try { // deposit zero money
                newBalance = accountList[count].deposit(0.00);
                System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
            } catch (Exception e) {
                stdExceptionPrinting(e, accountList[count].balance());	
            }
            
            try { // deposit money
                newBalance = accountList[count].deposit(700.00);                
                System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
            } catch (Exception e) {
                stdExceptionPrinting(e, accountList[count].balance());	
            }

            try { // deposit money next month
                newBalance = accountList[count].deposit(6700.00, nextMonthDate);
                System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
            } catch (Exception e) {
                stdExceptionPrinting(e, accountList[count].balance());	
            }

            // not for saving account
            if (count != 1) {
                try { // deposit after maturity date for CD account // paid off money for loan account
                    newBalance = accountList[count].deposit(300.00, afterMaturityDate);
                    System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                } catch (Exception e) {
                    stdExceptionPrinting(e, accountList[count].balance());	
                }
            }

            try { // compute interest for all accounts
                newBalance = accountList[count].computeInterest(halfYearDate);
                System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
            } catch (Exception e) {
                stdExceptionPrinting(e, accountList[count].balance());	
            }

            try { // compute invalid interest for all accounts
                newBalance = accountList[count].computeInterest(beforeLastInterestDate);
                System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
            } catch (Exception e) {
                stdExceptionPrinting(e, accountList[count].balance());	
            }

            // for CD account only
            if (count == 2) {
                try { // compute interest for CD account after afterMaturityDate
                    newBalance = accountList[count].computeInterest(afterMaturityDate);
                    System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                } catch (Exception e) {
                    stdExceptionPrinting(e, accountList[count].balance());	
                }
            }
            
            // for loan account only
            if (count == 3) {
                try { // fully paid off for loan account
                    newBalance = accountList[count].deposit(530.00);
                    System.out.println ("Account <" + accountList[count].name() + "> now has $" + newBalance + " balance\n");
                } catch (Exception e) {
                    stdExceptionPrinting(e, accountList[count].balance());	
                }
            }

            System.out.println("----------------------------------------------------------------------------");
        }        
    }

    static Date parseDate(String dateStr) {
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy/MM/dd");
        try {
            return formatter.parse(dateStr);
        } catch (ParseException e) {
            System.out.println("Date parsing error: " + e.getMessage());
            return null;
        }
    }

    static void stdExceptionPrinting(Exception e, double balance) {
        System.out.println("EXCEPTION: Banking system throws a " + e.getClass() +
                        " with message: \n\t" +
                        "MESSAGE: " + e.getMessage());
        System.out.println("\tAccount balance remains $" + balance + "\n");
    }
}          