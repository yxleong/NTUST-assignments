# Type Conversion Program

## Overview
This C# console application demonstrates implicit and explicit type conversions. It illustrates how different numeric types can be converted and the potential issues that arise during these conversions.

## Code Description
The program performs the following actions:
1. **Implicit Conversion:** Demonstrates how an `int` can be implicitly converted to a `long`.
2. **Explicit Conversion:** Shows how to explicitly convert an `int` to a `short` and discusses the consequences of such conversions, including potential data loss.
3. **Conversion from Float/Double to Int:** Illustrates how to convert floating-point numbers to integers.
4. **Type Conversion in Arithmetic Calculations:** Demonstrates type conversion during arithmetic operations, showing the difference between integer division and floating-point division.

## Output
When you run the program, you should see:
```
int k = 30000, long l = 30000
short s = 32767
int k = 30000, short s = 30000
int k = 40000, short s = -25536
int i = 1
int num = 100, d = 223.449996948242
f = 3
f = 3.4
```