# Compute the square root

## Problem Statement

The Babylonian algorithm to compute the square root of a positive number n is as follows:

1. Make a guess at the answer (you can pick n/2 as your initial guess).
2. Compute r = n/guess.
3. Set guess = (guess + r)/2.
4. Go back to step 2 for as many iterations as necessary. The more steps 2 and 3 are repeated, the closer guess will become to the square root of n.

Write a program that inputs a double for n, iterates through the Babylonian algorithm until the guess subtract the previous guess smaller than 0.01, and outputs the answer as a double to two decimal places. Your answer should be accurate even for large values of n.

## Input

A single line containing a double value n.
```
400.5
65189451651.5192165
1894651654984.11318
```
## Output

A single line containing the calculated square root of n as a double value, rounded to two decimal places.
```
20.01
255322.25
1376463.46
```

## Additional Information
* Easy, only basic programming language syntax and structure are needed.
* Solving time: 15 minutes
* Proposer: TWK
