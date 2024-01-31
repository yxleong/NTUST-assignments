# Tuple

## Problem statement 1
Multiply Adjacent elements (both side) and take sum of right and left side multiplication result.

The original tuple: `(1, 5, 7, 8, 10)`

```
(1*5, 1*5 + 5*7, 7*5 + 7*8, 8*7 + 8*10, 10*8)
```

### Output
```
(5, 40, 91, 136, 80)
```


## Problem statement 2
Check if tuples are same or not?

Two tuples would be same if both tuples have same element at same index.
```
t1 = (1, 2, 3, 0)
t2 = (0, 1, 2, 3)
```

### Output
```
t1 and t2 are not same
```


## Problem statement 3
Join tuples if similar initial element

While working with python tuples, it sometimes is needed to perform concatenation of records from the similarity of initial element.

```
test_list = [(5,6), (5,7), (5,8), (6,10), (7,13)]
```

### Output
```
[(5,6,7,8), (6,10), (7,13)]
```