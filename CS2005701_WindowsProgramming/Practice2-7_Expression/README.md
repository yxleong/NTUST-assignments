# Expression Demo Program

## Overview
This C# console application demonstrates the use of various operators, including increment, assignment, relational, and logical operators. It provides clear examples and outputs the results of each operation to the console.

## Code Description
The `ExpressionDemo` program demonstrates the following key concepts in C#:
1. **Increment Operators**:
   - **Post-increment (`x++`)**: The value of `x` is assigned to `y`, and then `x` is incremented.
   - **Pre-increment (`++x`)**: `x` is incremented first, and then its new value is assigned to `y`.
2. **Assignment Operators**:
   - Demonstrates the use of the compound assignment operator (`+=`), which adds a value to the variable and assigns the result back to it.
   - Shows string concatenation using the `+=` operator.
3. **Relational Operators**:
   - Compares two integers (`a` and `b`) using operators like `==` (equal to), `>=` (greater than or equal to), and `<=` (less than or equal to).
   - Evaluates boolean expressions and prints the result.
4. **Logical Operators**:
   - Demonstrates the use of logical operators such as NOT (`!`), AND (`&&`), and OR (`||`) to evaluate complex boolean expressions.

## Output
When you run the program, you should see:
```
---increment operator---
x = 10; y = x++; ---> x = 11, y = 10
x = 10; y = ++x; ---> x = 11, y = 11
---assignment operator---
a = 10; a += 10; ---> a = 20
s = "2 * 2 = 4;"; s += "3 * 3 = 9"; ---> s = "2 * 2 = 4; 3 * 3 = 9"
---relational operator---
a = 16, b = 13; a == b ---> False
a = 16, b = 13; a >= b ---> True
bool flag = a <= (b + 2); flag ---> False
---logical operator---
!(20 > 10) ---> False
20 > 10 && 15 <= 12 ---> False
20 > 10 || 15 <= 12 ---> True
```
