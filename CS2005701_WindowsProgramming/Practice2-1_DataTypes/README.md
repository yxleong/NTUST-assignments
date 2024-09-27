# Data Types Program

## Overview
This C# console application is designed to demonstrate various data types and their usage. The program prints examples of different data types, including integers, floating-point numbers, booleans, characters, and strings. It also shows how to use character literals and Unicode characters.

## Code Description
The code performs the following actions:
1. Displays an integer value.
2. Displays a floating-point value.
3. Shows boolean values.
4. Demonstrates character values, including Unicode characters and type conversions.
5. Prints string values.

## Output
When you run the program, you should see:
```
Integer: 100
Float: 3.14159
Boolean: True and False
Char: A, A, and B
65 is A
A is 65
String: Hello, C#
```
---
# Data Types in C#
Data types define how data is represented and stored in memory, and they determine the size and range of values that can be held.

## Primitive Data Types

- **`short`**:
  - **Size**: 2 bytes
  - **Range**: -32,768 to 32,767

- **`int`**:
  - **Size**: 4 bytes
  - **Range**: -2,147,483,648 to 2,147,483,647

- **`long`**:
  - **Size**: 8 bytes
  - **Range**: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

- **`float`**:
  - **Size**: 4 bytes
  - **Range**: -3.402823E38 to 3.402823E38

- **`double`**:
  - **Size**: 8 bytes
  - **Range**: -1.79769313486232E308 to 1.79769313486232E308

- **`bool`**:
  - **Size**: 2 bytes
  - **Range**: `true` or `false`

- **`char`**:
  - **Size**: 2 bytes
  - **Range**: 0 to 65,535 (Unicode characters)

## Additional Data Types

- **`byte`**:
  - **Size**: 1 byte
  - **Range**: 0 to 255

- **`sbyte`**:
  - **Size**: 1 byte
  - **Range**: -128 to 127

- **`ushort`**:
  - **Size**: 2 bytes
  - **Range**: 0 to 65,535

- **`uint`**:
  - **Size**: 4 bytes
  - **Range**: 0 to 4,294,967,295

- **`ulong`**:
  - **Size**: 8 bytes
  - **Range**: 0 to 18,446,744,073,709,551,615

- **`decimal`**:
  - **Size**: 16 bytes
  - **Range**: Varies, used for precise decimal calculations

- **`string`**:
  - **Size**: Varies
  - **Range**: 0 or more Unicode characters

## Character and String Literals

- **Character literals** are enclosed in single quotes (e.g., `'A'`).
- **String literals** are enclosed in double quotes (e.g., `"Hello, World!"`).
- Unicode characters can be represented using escape sequences (e.g., `'\u0041'` for `'A'`).

## Numeric Representations

- **Decimal (Base 10)**: `0, 1, 2, ..., 9`
- **Binary (Base 2)**: `0, 1, 10, 11, ...`
- **Hexadecimal (Base 16)**: `0, 1, 2, ..., 9, A, B, C, ..., F`
