# Swap Program

## Overview
This simple C# console application demonstrates how to swap the values of two integer variables using a temporary variable. The program shows the concept of variable access and manipulation in C#.

## Code Description
The code performs the following actions:
1. Initializes two integer variables, `a` and `b`, with values `5` and `10`, respectively.
2. Prints the values of `a` and `b` before swapping.
3. Uses a temporary variable to swap the values of `a` and `b`.
4. Prints the values of `a` and `b` after swapping.

### Swapping Two Variables
Swapping the values of two variables involves using a temporary variable to hold one of the values during the exchange. Here's how it works:
1. Store the value of `a` in a temporary variable `temp`.
2. Assign the value of `b` to `a`.
3. Assign the value stored in `temp` to `b`.

This ensures that the values are correctly exchanged without losing any data.

## Output
When you run the program, you should see the following output:
```
before swapping: a = 5, b = 10
after swapping: a = 10, b = 5
```
