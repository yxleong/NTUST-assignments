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

---
# `string.Format()` Format Summary

## Standard Numeric Formats
| Format | Description           | Example                  |
|--------|-----------------------|--------------------------|
| C      | Currency              | `{0:C}` → NT$1,234.57   |
| D      | Decimal               | `{0:D}` → 1234          |
| E      | Scientific            | `{0:E}` → 1.234000E+003 |
| F      | Fixed-point           | `{0:F}` → 1234.46       |
| G      | General               | `{0:G}` → 1234.57       |
| N      | Number                | `{0:N}` → 120,000.00    |
| P      | Percentage            | `{0:P}` → 25.00%        |
| R      | Round-trip            | `{0:R}` → 0.25          |
| X      | Hexadecimal           | `{0:X}` → 7B            |

## Custom Numeric Formats
| Format  | Description               | Example                |
|---------|---------------------------|------------------------|
| 0       | Zero placeholders          | `{0:000.000}` → 012.300 |
| #       | Digit placeholders         | `{0:###.###}` → 12.3    |
| .       | Decimal point              | `{0:0.0}` → 12.3        |
| ,       | Thousand separator         | `{0:0,0}` → 1,200       |
| %       | Percentage                 | `{0:0%}` → 25%          |
| e       | Scientific notation        | `{0:0e+0}` → 1e+2       |
| \\      | Escape character           | `{0:00\n0}` → 12 3     |

## Standard DateTime Formats
| Format | Description               | Example                        |
|--------|---------------------------|--------------------------------|
| d      | Short date                | `{0:d}` → 2012/3/11           |
| D      | Long date                 | `{0:D}` → 2012年3月11日        |
| f      | Full date/time            | `{0:f}` → 2012年3月11日 下午 01:02 |
| g      | General sortable date/time | `{0:g}` → 2012/3/11 下午 01:02 |
| t      | Short time                | `{0:t}` → 下午 01:02          |

## Custom DateTime Formats
| Format | Description               | Example                |
|--------|---------------------------|------------------------|
| dd     | Day                       | `{0:dd}` → 11          |
| ddd    | Abbreviated day           | `{0:ddd}` → Sun        |
| MMM    | Month abbreviation         | `{0:MMM}` → 三月      |
| yyyy   | Year                      | `{0:yyyy}` → 2012      |

## String Formats
**Example:**
```csharp
String.Format("This is a {0}, not a {1}", "book", "pencil");
// Output: This is a book, not a pencil.
