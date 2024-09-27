# Escape Character Program

## Overview
This C# console application demonstrates the use of escape characters in strings and how to represent special characters using their Unicode values.

## Code Description
The program performs the following actions:
1. Initializes character variables using both standard character assignments and Unicode escape sequences.
2. Displays the characters assigned to these variables.
3. Uses escape characters to represent special symbols like single quotes (`'`), backslashes (`\`), and double quotes (`"`).
4. Outputs formatted strings that include these escape characters, both directly and through their Unicode representation.

## Output
When you run the program, you should see:
```
Variable ch1 is character A
Variable ch2 is character A
Variable ch1 becomes character '
Variable ch2 becomes character \
My "C#" program
My "C#" program
```

---
### Escape Characters Table

| Escape Character | Unicode | Description                     |
|------------------|---------|---------------------------------|
| `\b`             | `\u0008`| Backspace                       |
| `\n`             | `\u000A`| Line feed (LF)                 |
| `\r`             | `\u000D`| Carriage return (CR)            |
| `\t`             | `\u0009`| Tab                             |
| `\'`             | `\u0027`| Single quote (`'`)             |
| `\"`             | `\u0022`| Double quote (`"`)             |
| `\\`             | `\u005C`| Backslash (`\`)                |
