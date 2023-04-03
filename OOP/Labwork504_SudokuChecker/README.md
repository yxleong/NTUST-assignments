# Sudoku Checker

## Problem Statement
A Sudoku is a 9x9 grid that is completed when every 3x3 square, row and column consist of the numbers 1-9. For this task, you will be given a completed 9x9 square. Create a function that checks to make sure each 3x3 square contains each number from 1-9 exactly once, and there are no duplicates. Furthermore, each row and each column doesn't contain duplicates with no numbers outside the range 1~9.


### Input
The input consists of 81 integers separated by commas for each line, with input sequence 1~81 corresponding to the position drawn below. Color signifies 3x3 squares for checks.

![](https://i.imgur.com/TjOyg50.png)

### Output
The output should consist of either "True" or "False" depending on whether the Sudoku is valid or not.

## Sample Input/Output

### Input
```
1,2,6,1,5,4,3,9,7
9,6,5,3,2,7,1,4,8
3,4,8,6,8,9,7,5,2
5,9,3,4,6,8,2,7,1
4,7,2,5,1,3,6,8,9
6,1,8,9,7,2,4,3,5
7,8,6,2,3,5,9,1,4
1,5,4,7,9,6,8,2,3
2,3,9,8,4,1,5,6,7

8,2,7,1,5,4,3,9,6
9,6,5,3,2,7,1,4,8
3,4,1,6,8,9,7,5,2
5,9,3,4,6,8,2,7,1
4,7,2,5,1,3,6,8,9
6,1,8,9,7,2,4,3,5
7,8,6,2,3,5,9,1,4
1,5,4,7,9,6,8,2,3
2,3,9,8,4,1,5,6,7
```
```
1,2,6,1,5,4,3,9,7
9,6,5,3,2,7,1,4,8
3,4,8,6,8,9,7,5,2
5,9,3,4,6,8,2,7,1
4,7,2,5,1,3,6,8,9
6,1,8,9,7,2,4,3,5
7,8,6,2,3,5,0,1,4
1,5,4,7,9,6,8,2,3
2,3,9,8,4,7,5,6,1
```

### Output
```
False
True
```
```
False
```

### Note
- continue output until EOF is read
- cin.getline may be needed

## Additional Information
* Easy, only basic programming language syntax and structure are needed.
* Solving time: 20 minutes
* Proposer: Jun-Yu Chen
