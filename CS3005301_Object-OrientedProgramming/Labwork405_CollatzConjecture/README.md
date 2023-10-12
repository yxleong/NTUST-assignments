# Collatz Conjecture

## Problem Statement
Collatz conjecture, which also known as 3N+1 conjecture, is a conjecture in mathematics that concerns a sequence defined as follows:

![](https://i.imgur.com/gSgrtRl.png)

All the positive numbers that are smaller than 1,000,000 will eventually equal 1 by using this method. You need to find out the cycle length of a number (**including the number itself**).

For example, if 22 is inputted, the result will be: `22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1` (16 numbers).
Hence the cycle length of 22 is 16.

### Input
Enter a pair of positive integers i and j that are both smaller than 1,000,000, separated by a space. This program allows multiple tests. Users can enter until EOF is reached.
```
1 10
200 100
201 210
900 1000
```
### Output
Find the maximum cycle length that can be produced by any numbers between i and j (including i and j). Print i, j and the maximum cycle length, separated by spaces.
```
1 10 20
200 100 125
201 210 89
900 1000 174
```

## Additional Information
* Eazy, only basic programming syntax and structure are required.
* Solving time: 10 minutes
* Contributors: 溫勇威, 陳靖升, 鍾賢廣
