# Large Integer Operation

## Problem Statement
You are given two large integers `a` and `b`. Perform the following operations on them: addition, subtraction, and multiplication. Since these numbers are too large to be handled by the usual data types, you need to use large number computation techniques to perform these operations.

Large number computation refers to the process of performing calculations on numbers that are beyond the typical range of numerical values. In computer science and mathematics, integers and floating-point numbers are typically used to represent numbers. However, due to the precision and range limitations in storing and processing numbers in computers, large number computation techniques are required when dealing with very large numbers.

For example, in certain mathematical problems, very large integers may need to be calculated, such as integers with more than 200 digits, while computers can usually only handle integers up to a few thousand digits. Therefore, large number computation techniques utilize special data structures and algorithms to process extremely large data, avoiding loss of numerical precision or range limitations.

In C++, we can store big numbers by using data structures such as arrays, vectors, or strings. Then, we can implement operators for addition, subtraction, multiplication, division, modulo, as well as functions for comparison, input, and output.

Write a program to perform these computations and output the results as integers.

## Input
The input consists of multiple lines, each containing two large integers `a` and `b` separated by a new line character. Note that `a` and `b` can be very large numbers, with more than 200 digits.
```
684206820568913977247831143321345972981675861223241672511715

377717064100214575610627379024516367048953192887369481660644
```

## Output
Output three integers representing the sum, difference, and product of `a` and `b` respectively.
```
1061923884669128552858458522345862340030629054110611154172359

306489756468699401637203764296829605932722668335872190851071

22862032100015531960919852030141400331719662067383470776767987317031264024379854233801628519328864632781420435386761621
```

## Additional Information
* Hard, need to use multiple program structures or more complex data types.
* Solving time: 90 minutes
* Contributors: 陳昕璇 HSIN-HSUAN CHEN
