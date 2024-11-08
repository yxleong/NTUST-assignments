# School Inheritance

## Problem Statement
The `School` class is the base class for all schools. It contains the following member variables and functions:
- `name (string)`: The name of the school.
- `studentAmount (int)`: The number of students currently in the school.
- `studentAmountNextYear (int)`: The projected number of students the school could have next year.
- `admissions(float amount)`: Adds the specified amount to the total student amount this year (if the amount is nonnegative).
- `dropouts(float amount)`: Subtracts the specified amount from the number of students this year (if the amount is nonnegative and less than or equal to the student amount).
- `transfer(float amount, School &toSchool)`: Deducts the specified amount from the student amount of the current school and transfers them to another school.

### PrivateSchool
The `PrivateSchool` class is derived from the `School` class and introduces additional functionality related to dropouts:
- `dropouts(float amount)`: Overrides the `dropouts` function in the base class to track the number of dropouts and deduct a penalty of 100 from the number of students the school can admit next year for **every dropouts** called.

### PublicSchool
The `PublicSchool` class is derived from the `School` class and introduces additional functionality related to growth and penalties:
- `growing_rate (float)`: The growth rate **(=0.05)** for the number of students the school can admit next year.
- `apply_growth()`: Increases the number of students the school can admit next year based on the growth rate.
    > studentAmountNextYear += growing_ rate* studentAmountNextYear
- `dropouts(float amount)`: Overrides the `dropouts` function in the base class to apply penalties when a large number **(>100)** of students leave the school at once.
    - A dropout of such amount induces a loss of **5%** of `studentAmountNextYear`, truncating the decimal places.

If violations occur (Ex. Subtracting more than existing amount), we do not do the operation. 
For all 3 classes create **constructors** (default and with parameters) and **overloaded** << (output) operator, reuse constructors and `operator <<` of the base class in the derived classes.

## Sample Input / Output
### Input
According to the given `main.cpp` in Note.

### Output
Output format will be with `name`, `studentAmount` and `studentAmountNextYear`. Each separate by tab(`\t`).
```
NTUST	12500	12500
NTUT	85000	85000
FJCU	25000	25000
NTUST	12700	12500
NTUST	12500	12500
NTUST	12500	12500
FJCU	26000	25000
FJCU	25950	25000
FJCU	24950	24900
NTUT	86000	85000
NTUT	86000	89250
NTUT	85000	84787
NTUT	85000	84787
NTUT	84000	80547
NTUST	13500	12500
FJCU	24950	24900
NTUST	13500	12500
```

## Note
The main program demonstrates the usage of the classes by creating instances of `School`, `PrivateSchool`, and `PublicSchool`. It performs various operations on these instances, such as admissions, dropouts, transfers, and growth. The program provides output to showcase the state of the schools after each operation.
```cpp
#include <iostream>
#include "School.h"
#include <string>
using namespace std;

int main()
{
    //init 3 different account types
    School ntust("NTUST", 12500);
    PublicSchool ntut("NTUT", 85000);
    PrivateSchool fjcu("FJCU", 25000);

    //state info all 3
    cout<<ntust<<endl;
    cout<<ntut<<endl;
    cout<<fjcu<<endl;

    //test all methods on School
    ntust.admissions(200);
    cout<<ntust<<endl;
    
    ntust.dropouts(200);
    cout<<ntust<<endl;

    ntust.dropouts(100000);
    cout<<ntust<<endl;
    
    //test all methods on PrivateSchool
    fjcu.admissions(1000);
    cout<<fjcu<<endl;    

    fjcu.dropouts(50);
    cout<<fjcu<<endl;

    fjcu.dropouts(1000);
    cout<<fjcu<<endl;
    
    //test all methods on PublicSchool
    ntut.admissions(1000);
    cout<<ntut<<endl;

    ntut.apply_growth();
    cout<< ntut <<endl;

    ntut.dropouts(1000);
    cout<< ntut <<endl;
    
    //Transfer method
    cout << ntut << endl;
    ntut.transfer(1000, ntust);
    cout << ntut << endl;
    cout << ntust << endl;

    fjcu.transfer(30000, ntust);
    cout << fjcu << endl;
    cout << ntust << endl;

    return 0;

}
```


## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 25 minutes
* Contributors: JY
