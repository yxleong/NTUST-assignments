# Bank Account Password Encryptor

## Description
Given a sequence composed of positive numbers or characters as input, this encryptor will produce an encrypted password.
Construct a red-black tree using the input sequence and combine the information within that red-black tree according to specified rules to generate the encrypted password.

## Input
A sequence composed of n positive numbers x or characters c, separated by spaces.
- 0 < n < 25
- 0 < x < 128
- A < c < z

## Output
A sequence composed of positive numbers and underscores ('_') is constructed in the following order using the elements of a red-black tree:
- All black nodes (positive numbers) using post-order traversal
- All red nodes (positive numbers) using pre-order traversal
- Number of rotations
Each set of elements is separated by underscores.

## Sample Input
```
1 2 3 4 5 6
```
```
8 18 5 15 17 25 40 80
```
```
B r I a N A c C o U n T
```

## Sample Output
```
1352_46_2
```
```
515184017_82580_3
```
```
6684739911411197_65677885110_5
```
