# Hidden Word

## Description
Given a word W, an array of integers, and an array of characters. Both arrays have the same length, and each integer in the integer array corresponds to a character in the character array at the same index. The word W is composed of the characters in the character array.

Perform insertion sort and selection sort on the integer array, while simultaneously rearranging the character array accordingly.

Throughout the sorting process, it is needed to determine if the characters in the character array are arranged in the same order as the given word W. If this occurs, please identify and print the earliest step at which it happened. If it doesn't happen at all, make that clear in the output.

Lastly, print the rearranged characters in the character array after the sorting is completed.

## Input
- The first line contains a word.
- The second line contains a list of integers separated by space.
- The third line contains a list of characters separated by space.

## Output
- Whether the given word is found during sorting process, and the step at which it was found.
- A word that is the result of rearranging the characters after the sorting is completed.

## Sample Input
```
insertion
55 12 14 90 67 83 1 2 4
s i n r e t i o n
```
```
example
9 25 0 12 2 3 8
l p e m x a e
```
```
qwertyuiop
89 3 1 4 6 15 30 23 11 8
t w q e r y u i o p
```
```
unfound
30 18 0 56 27 2 1
n f d u n o u
```

## Sample Output
```
Word found in insertion sort step 5.
ioninsetr
```
```
Word found in selection sort step 3.
exaelmp
```
```
Word found in insertion sort step 5 and selection sort step 4.
qwerpoyiut
```
```
Word not found.
duofnnu
```
