# Design Month Class

## Problem Statement
Define a class named `Month` to display the formatted month.

The **abbreviation** of a month in this exercise is the first three letters of the name with initial capitalization.

This class has only one variable `month(int)` for use as storing the current month.
This class has three constructors:
- `Month()`: Construct a Month class that defaults to January.
- `Month(char first, char second, char third)`: Use the given abbreviation to construct the Month class, the parameters represent each letter of the abbreviation.
- `Month(int monthInt)`: Construct a Month class with the value of `monthInt`. If the given value is invalid, please set the month to January.

Implement the following member functions:
- `void inputInt()`: Read an int `x`, and modify the current month to `x`. If `x` is invalid (`x < 1` or `x > 12`), please set the month value to 1.
- `void inputStr()`: Read three letters `a`, `b`, and `c`. These letters represent each letter of the abbreviation of a month. Modify the letters to the corresponding month value. If the input is invalid, set the month value to 1.
- `void outputInt()`: Print the month value.
- `void outputStr()`: Print the abbreviation of the month.
- `void nextMonth()`: Increment month value.

## Input
The main function will receive a series of integers or strings corresponding to the main method.

## Output
The output will print some variable values corresponding to the main method.

## Sample Input/Output

### Input
```
5
J
u
n
```

### Output
```
Month1 = 1 Jan
Month2 = 2 Feb
Month3 = 3 Mar
Month4 = 4 Apr
Month5 = 5 May
Month6 = 6 Jun
```

## Note
### main.cpp
```cpp
#include <iostream>
#include "Month.h"

int main() {
    Month month1, month2(2), month3('M', 'a', 'r'), month4, month5, month6;
    month4 = month3.nextMonth();
    month5.inputInt();
    month6.inputStr();

    std::cout << "Month1 = ";
    month1.outputInt();
    std::cout << ' ';
    month1.outputStr();
    std::cout << std::endl;

    std::cout << "Month2 = ";
    month2.outputInt();
    std::cout << ' ';
    month2.outputStr();
    std::cout << std::endl;

    std::cout << "Month3 = ";
    month3.outputInt();
    std::cout << ' ';
    month3.outputStr();
    std::cout << std::endl;

    std::cout << "Month4 = ";
    month4.outputInt();
    std::cout << ' ';
    month4.outputStr();
    std::cout << std::endl;

    std::cout << "Month5 = ";
    month5.outputInt();
    std::cout << ' ';
    month5.outputStr();
    std::cout << std::endl;

    std::cout << "Month6 = ";
    month6.outputInt();
    std::cout << ' ';
    month6.outputStr();
    std::cout << std::endl;

    return 0;
}
```

## Additional Information
* Eazy, only basic programming syntax and structure are required.
* Solving time: 30 minutes
* Contributors: 陳俊儒, 林承達, 廖宣瑋
