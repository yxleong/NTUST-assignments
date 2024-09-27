# Division Demo Program

## Overview
This C# console application demonstrates basic division operations and various methods to format the output to two decimal places. Users can input two integers, and the program will calculate and display their division result.

## Code Description
The program performs the following actions:
1. Prompts the user to input two integers (`Num1` and `Num2`).
2. Calculates the division of the two integers, ensuring that the result is a double to maintain precision.
3. Displays the result in several formatted ways to show precision to two decimal places.

### Formatting Methods
The program utilizes different methods to format the output:
- **Method 1:** Using composite formatting with `{0:0.00}`.
- **Method 2:** Using the `ToString("F2")` method.
- **Method 3:** Using `ToString("0.00")` method.
- **Method 4:** Using `string.Format("{0:0.00}", result)`.

### Sample Input
```
100
3
```

### Sample Output
```
Num1: 100
Num2: 3
100 / 3 = 33.3333333333333
100 / 3 = 33.33
100 / 3 = 33.33
100 / 3 = 33.33
100 / 3 = 33.33
```
