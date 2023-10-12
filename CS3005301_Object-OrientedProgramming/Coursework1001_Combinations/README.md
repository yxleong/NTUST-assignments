# Combinations

## Problem Statement
Please write a **recursive** function to enumerate all combinations of `C(n,r)`.

The function `PrintCombination(int*, int, int)` is for printing all the combination results on the console using recursion.

## Input:
No input is required.

## Output:
```
1 2 3 4
1 2 3 5
1 2 4 5
1 3 4 5
2 3 4 5
```

## Note
main.cpp
```cpp
#define ELEMENTS_FOR_COMBINATION 5	//i.e., C(5,4)
#define DLEMENTS_FOR_CHOICE 4

int main(void)
{
	int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];

	//Get all elements for combination
	for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
		arrayPtr[i] = i + 1;

	PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);

	if (arrayPtr != NULL)
		delete[] arrayPtr;

	return 0;
}
```

## Additional Information
* Eazy, only basic programming syntax and structure are required.
* Solving time: 30 minutes
* Contributors: Wen-Kai, Wang