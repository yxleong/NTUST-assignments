# Print Standard Format

## Problem Statement
Print out information for N employees in a clean format. Each employee has three attributes: Name, Salary and Bonus.

### Input
The input contains several cases, each of them as described below.
The first line of input contains an integer N (10^6 >= N > 0), which represents the number of employees. Each of the next N lines indicates the information of each employee with three attributes: Name, Salary (between 10^9 ~ 0) and Bonus (between 10^9 ~ 0). Each attribute will be separated by one space.
```
3
Alexandrescu 20000000 99999
Frank 100000 50
Andy 1 1
```
```
4
Andy 100 200
Anna 400 9999
Lipp 200 200
Stan 500 200
```

### Output
For each set of input data (from the previous N to the next N), please make sure the width of each column is the same as the attribute with the longest width in each column. Use the symbol "|" to separate each column and align the content to the right. Note that for numeric attributes (Salary, Bonus), the content should be indented by two additional spaces.
```
Alexandrescu|  20000000|  99999
       Frank|    100000|     50
        Andy|         1|      1
```
```
Andy|  100|   200
Anna|  400|  9999
Lipp|  200|   200
Stan|  500|   200
```

### Note：
* The name attribute does not contain spaces.
* The program should end after reading EOF.

## Additional Information
* Eazy, only basic programming syntax and structure are required.
* Solving time: 10 minutes
* Contributors: 謝宜杭, 林承達, 廖宣瑋
