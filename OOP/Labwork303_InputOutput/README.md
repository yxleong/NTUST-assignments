# Input_Output

## Problem Statement
Given an arbitrary number X (double), a positive integer M, a positive integer N, and a character C, reformat the decimal part of X to N characters and fill the remaining characters with 0's if necessary. If X (including negative and decimal points) is still less than M characters, fill the front with character C to make it exactly M characters long.

### Input
Each line of input represents a group of X, M, N, and C, separated by spaces.
* X: The target number that needs to be formatted.
* M: The total length of the output (including negative sign and decimal point).
* N: The number of reserved digits of the decimal part.
* C: The character to be filled when the length is not enough (less than M digits).
```
3.14159265358979323846 5 2 G
3.14 8 3 X
3 8 0 C
-3 8 5 C
```

### Output
Each line of output is formatted according to the requirements of the problem.
```
G3.14
XXX3.140
CCCCCCC3
-3.00000
```
### Note
* The program continues to ask for input until EOF is reached.
* C may be a space.

## Additional Information
* Medium, multiple programming grammars and structures are required
* Solving time: 30 minutes
* Contributors: 王聖文, 張子樂, 林岳儒
