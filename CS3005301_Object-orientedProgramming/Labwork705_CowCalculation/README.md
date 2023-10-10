# Cow Calculation

## Problem Statement
A primitive cow culture was discovered by Dr. Bo Vine, an anthropologist. The culture utilized computation tablets with mathematical calculations represented by cow symbols. Dr. Vine needs assistance in verifying his hypothesis about the tablets.

Each tablet consists of six lines. The first two lines represent **cow numbers**, the next three lines represent **operations** on those numbers, and the sixth line represents the result.

**Cow numbers** are sequences of symbols: **V**, **U**, **C**, and **D**. The tablet's first two lines contain 5 symbols each, and the sixth line contains 8 symbols.

To interpret the cow calculations, two numbers, Num1 and Num2, are tracked. Initially, Num1 is equal to the number on the first line of a tablet, and Num2 is equal to the number on the second line. However, Num2 can change as a result of the operations. There are four possible **operations** denoted by the symbols **A**, **R**, **L**, and **N**.

1. Operation **A** adds Num1 and Num2 using an addition table. The first symbol in the result box represents the sum, and the second symbol represents a carry symbol.

   Addition Table:
   
   |   | V | U | C | D |
   |---|---|---|---|---|
   | V | V | U | C | D |
   | U | U | C | D | VU|
   | C | C | D | VU| UU|
   | D | D | VU| UU| CU|

    For example: U `A` V = U and C `A` C = V with a carry of U.

    ①	VUCDV `A` VUCDV = VDUCV
    ![](https://hackmd.io/_uploads/SJrU3-0S3.png)
    ②	DVVCU `A` CVUCU = UUVCVC

2. Operation **R** shifts Num2 one position to the right, losing the rightmost symbol and adding a V to the leftmost position.
    For example, VVCDU would become VVVCD

3. Operation **L** shifts Num2 one position to the left, keeping the leftmost symbol and adding a V to the rightmost position.
    For example, VVCDU would become VVCDUV. 

4. Operation **N** is a null operation with no effect on Num2.

After performing the operations on Num1 and Num2, the final value of Num2 should match the value marked on the sixth line of the tablet. If the final value of Num2 does not have 8 symbols, it is padded with V's on the left.
For example, VDCCC becomes VVVVDCCC

Please help Dr. Vine to verify that the tablets' mathematical operations are consistent with his hypothesis.

## Sample Input / Output

### Input
The input consists of multiple tablets represented by an integer N (**1 <= N <= 10**) on the first line. The subsequent **6 * N** lines describe the tablets, following the format mentioned in the problem statement.
```
5
VVVVU
VVVVU
A
A
A
VVVVVVUV
VVCCV
VVDCC
L
R
A
VVVVUCVC
VVCCV
VVDCC
R
L
A
VVVVUCVV
VVUUU
VVVVU
A
N
N
VVVVVUCU
DDDDD
VVVVU
A
L
L
UVVVVVVV
```

### Output
The output consists of N + 2 lines. The first line should print "**COWCULATIONS OUTPUT**". Then, there should be one line of output for each tablet, stating either "**YES**" (if the tablet follows Dr. Vine's hypothesis) or "**NO**" (if the tablet does not follow Dr. Vine's hypothesis). The final line of output should print "**END OF OUTPUT**".
```
COWCULATIONS OUTPUT
YES
YES
YES
NO
YES
END OF OUTPUT
```


## Note
* Uppercase and lowercase letters are considered different.
* The test data will be read until EOF.

## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 25 minutes
* Contributors: 林承達, 謝宜杭, 廖宣瑋