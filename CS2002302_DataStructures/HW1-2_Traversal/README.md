# Traversal

## Description
Build a binary search tree according to two lists (infix and prefix/postfix), and print out the new list in the asking traversal way (postfix/prefix) and level order.

## Input
- The first line will be the list in infix order.
- The second line will be the traversal way that the list is ordered now (prefix / postfix).
- The third line will be the list that is in the traversal order (prefix / postfix).
- The forth line will be the new traversal way you should turn the list into (postfix / prefix).
- 
## Output
- The first line should be the new list in the other traversal way.
- The second line should be the new list in level order.

## Sample Input
```
AQBWCRDTEYF
prefix
RWQABCTDYEF
postfix
```
```
AaBbCcDdE
postfix
ABCbaDEdc
prefix
```

## Sample Output
```
ABQCWDEFYTR
RWTQCDYABEF
```
```
caAbBCdDE
cadAbDEBC
```
