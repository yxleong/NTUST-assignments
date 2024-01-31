# List

## Problem statement 1
Write a program to add item 7000 after 6000 in the following Python List:
```
list1 = [10, 20, [300, 400, [5000, 6000], 500], 30, 40]
```

### Output
```
[10, 20, [300, 400, [5000, 6000, 7000], 500], 30, 40]
```

## Problem statement 2
Suppose you are given a list of candy and another list of the same size representing no items of respective candy.
```
candy_list = ['Jelly Belly', 'Kit Kat', 'Double Bubble', 'Milky Way', 'Three Musketeers']
```
```
no_of_items = [10, 20, 34, 74, 32]
```
### Output
```
Jelly Belly-10
Kit Kat-20
Double Bubble-34
Milky Way-74
Three Musketeers-32
```

## Problem statement 3
Write a program to print a list after performing a running sum on it.
```
list1 = [1, 2, 3, 4, 5, 6]
```
### Output
```
[1, 3, 6, 10, 15, 21]
```

## Problem statement 4
Given a list of integers, make a list by running through elements of the list by adding all elements greater and itself.
```
[2, 4, 6, 10, 1]
```
### Output
- For 1st element 2 ->> these are greater (4+6+10) values and 2 itself so on adding becomes 22
- For 2nd element 4 ->> greater elements are (6,10) and 4 itself, so on adding 20
- likewise for all other elements
```
[22, 20, 10, 16, 23]
```
