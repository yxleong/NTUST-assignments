# debug

## Problem 1
#### Wrong
```
print("The sum of {nums} is:", sum_list(nums))
```
#### Correct
```
print(f"The sum of {nums} is:", sum_list(nums))
```
### Reason
It is needed to format the string if want to insert a variable.

## Problem 2
![Vcpp2010DebugToolbar](https://github.com/yxleong/NTUST-assignments/assets/95266740/5bbcfbf5-2951-4eeb-860c-cf7ef6b82b16)
### Reason
Try to use debug button.

## Problem 3
#### Wrong
```
multiplier_list = [1, 2, "3"]
```
#### Correct
```
multiplier_list = [1, 2, 3]
```
### Reason
A string is not acceptable as index of list

