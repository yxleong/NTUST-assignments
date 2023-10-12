# Memory Simulator

## Problem Statement
Please write a program to simulate the process of writing and reading memory data.

- For a given memory capacity N (in bytes), the memory address ranges from 0 to N-1.

- There are four data types
    - char (1 byte)
    - short (2 bytes)
    - int (4 bytes)
    - String (ending with '\0' or until the end of the memory if '\0' is not found)

- There are two types of instructions:
  - `Set <position> <type> <value>`
      - Write the given value into memory starting from the given position.
      - Allocate memory space according to the given type.
      - If the size of the value exceeds the size of the type, the excess part will be ignored.
      - If there is an overflow (position + type size > N), output "**Violation Access.**"
  - `Get <position> <type>`
      - Print the value of the given type from memory starting at the given position.

Output "**Violation Access**" if the given position is illegal.

## Input
* The first line contains an integer N representing the size of the memory.
* The second line contains an integer n representing the number of commands.
* The next n lines contain the Get/Set operations on the memory.
```
1000
6
Set 0 String H   i
Set 1 int 3158064
Set 4 short 13878
Set 6 char 0
Get 0 String
Get 1000 int
```

## Output
Output the result according to the commands.
```
H00066
Violation Access.
```

## Note
* The input is guaranteed to follow the command format.
* The data type of the number is stored in little-endian.

## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 45 minutes
* Contributors: 林鼎傑, 宇恩, 鍾賢廣