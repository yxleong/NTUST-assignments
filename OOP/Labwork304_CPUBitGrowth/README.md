# CPU Bit Growth

## Problem Statement
Assume that the maximum integer of a k-bit CPU can process is (2^k) – 1. Every 10 years, k will grow by a multiple of 2. Assume that your company released a 4-bit CPU in 1900, which can store 15 as the largest integer. 

(8-bit will be released in 1910, and 1920 will be 16-bit, and so on.)

There is a given year Y, find the maximum positive integer N where N! is within the CPU calculation range of the current year.

### Input
Each line has a positive integer Y (2200 >= Y >= 1900). The input method is unlimited input until EOF is read.
```
1900
1910
2097
```

### Output
Output N, so that N! is within the CPU calculation range of the current year.
```
3
5
134480
```

### Note
* Test time limit: 5.0 seconds.

## Additional Information
* Medium, multiple programming grammars and structures are required
* Solving time: 25 minutes
* Contributors: 王聖文, 張子樂, 林岳儒
