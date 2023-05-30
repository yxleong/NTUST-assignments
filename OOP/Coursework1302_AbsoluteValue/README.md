# Absolute Value

## Problem Statement
Please write a template-based function that calculates and returns the absolute value of the difference between two numeric values. The function is implemented in **Template.h** and can operate with any numeric data type, including `float`, `int`, `double`, and `char`.

### Input
No input.

### Output
```
Absolute value of 10 - 20 is 10
Absolute value of 5.5 - 3.1 is 2.4
Absolute value of A - C is 2
```

## Note
main.cpp
```cpp
#include "Template.h"
#include <iostream>
using namespace std;

int main()
{
	int i1, i2;
	double d1, d2;
	char c1, c2;
	i1 = 10; i2 = 20;
	cout << "Absolute value of 10 - 20 is " << absoluteValue(i1, i2) << endl;

	d1 = 5.5; d2 = 3.1;
	cout << "Absolute value of 5.5 - 3.1 is " << absoluteValue(d1, d2) << endl;

	c1 = 'A', c2 = 'C';
	cout << "Absolute value of A - C is " << absoluteValue(c1, c2) << endl;
	return 0;
}
```

## Additional Information
* Easy, only basic programming syntax and structure are required.
* Solving time: 10 minutes
* Contributors: 謝公耀, 張子樂, 林岳儒