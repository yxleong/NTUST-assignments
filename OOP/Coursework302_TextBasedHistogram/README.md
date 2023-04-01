# Text-Based Histogram

## Problem Statement
Generate a text-based histogram for a quiz of students. The quiz is graded on a scale from 0 to 5. Please design a program that allows the user to enter the student's grades one by one and count the times of each grade appears. When the input finished, please print the text-based histogram with the format in the "Output" section below. The program should be capable of handling an arbitrary number of student grades.

### Input
The program should take input from a file named *grade.txt*. The file will contain a list of integers separated by spaces or newlines.

### Output
The program should output a two-column table sorted in descending order by the count value. The first column should contain the list of all numbers, and the second column should contain the count of each of them. The output should be written to a file named *grades.Output*.

### Sample Input / Output

Input:
```
3 0 1 3 3 5 5 4 5 4

0 5 0 5 0 4 5 5 4 3 4 5 1 4 1 5 5 1 4 3 5 5 0 1 1 1 1 3 0 1 1 5 4 4 4 2 2 4 1 2 3 2 2 0 2 2 0 4

3 0 4 1 2 1 1 4 2 0 2 0 4 5 2 5 4 3 4 5 2 5 4 4 3 3 1 5 1 0 4 2 0 4 0 3 2 0 3 2 2 3 5 2 0 2 0 3 4 1 4 3 1 0 5 1 4 5 1
```
Output:
```
1 grade(s) of 0
1 grade(s) of 1
0 grade(s) of 2
3 grade(s) of 3
2 grade(s) of 4
3 grade(s) of 5

7 grade(s) of 0
10 grade(s) of 1
7 grade(s) of 2
4 grade(s) of 3
10 grade(s) of 4
10 grade(s) of 5

10 grade(s) of 0
9 grade(s) of 1
11 grade(s) of 2
9 grade(s) of 3
12 grade(s) of 4
8 grade(s) of 5
```

## Additional Information
* Easy, only basic programming language syntax and structure are needed.
* Solving time: 30 minutes
* Contributor: Wen-Kai, Wang
