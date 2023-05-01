# Prime Number

## Problem Statement
Define a class named `PrimeNumber` that stores a prime number.

* The class `PrimeNumber` has only one variable `value(int)`.
* The class `PrimeNumber` has two constructors:
    * `PrimeNumber()`: construct a `PrimeNumber` where the value is **1**.
    * `PrimeNumber(int _value)`: construct a `PrimeNumber` where the value is `_value`.
* The following function should be implementd:
    * `get()`: return the value of this `PrimeNumber`.
* Overloading all the following operators are required:
    * `++`: return the next larger prime number. 
    * `--`: return the next smaller prime number.
		* If the `PrimeNumber` value equals to 2, `--` operator should return 1.


## Input and Output

### Input
No inputs.

### Output
```
2
2
13
17
```

## Other Notes:
main.cpp
```
int main()
{	
	PrimeNumber p1, p2(13);	
	PrimeNumber a = ++p1;
	PrimeNumber b = p2++;
	cout << a.get() << endl;
	cout << p1.get() << endl;
	cout << b.get() << endl;
	cout << p2.get() << endl;
	system("pause");
	return 0;
}
```

## Additional Information
* Easy, only basic programming language syntax and structure are needed.
* Solving time: 15 minutes
* Contributors: 張子樂，廖宣瑋，謝公耀


