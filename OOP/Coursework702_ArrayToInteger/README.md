# Array to Integer

## Problem Statement
Write a class named `Atoi` that can convert a given string into an integer. For example, the function should return an integer 1234 with the given string “1234”.

The class `Atoi` has an attribute named `beTran(string)` to store the original string value.

The class Atoi has two constructors:
* `Atoi()`: Construct a class Atoi where beTran is "". 
* `Atoi(string s)`: Construct a class Atoi where beTran is s.

You should also implement the following member functions:
* `SetString(String s)`: Set beTran of this class to s.
* `GetString()`: Return beTran of this class.
* `Length()`: Return the length of beTran.
* `IsDigital()`: Return true if beTran can be transformed into an integer, otherwise return false.
* `StringToInteger()`: Convert beTran to an integer and return.



## Input
A series of strings.
```
05
11
23
-10
-11
8946
1891231
```
```
46506
-096504
56400
00494
```

## Output
For each string, if it can be transformed into an integer, output the following three lines:
* The length of the input string.
* The integer value of the input string.
* The size of the integer data type in bytes.

If the input string cannot be transformed into an integer, output nothing.
```
4
520
4
2
5
4
4
1120
4
2
11
4
4
2320
4
2
23
4
4
-1020
4
2
-10
4
4
-1120
4
2
-11
4
6
894620
4
4
8946
4
9
189123120
4
7
1891231
4
```
```
7
4650620
4
5
46506
4
8
-9650420
4
6
-96504
4
7
5640020
4
5
56400
4
7
49420
4
5
494
4
```

## Note
You should not use the `atoi` function or the `stringstream` class to do the conversion.

The `main()` function in your program will be replaced during the judging process. 
```
int main() {
	string beTrans;

	while (cin >> beTrans) {
		Atoi atoi(beTrans + "20");
		if (atoi.IsDigital()) {
			cout << atoi.Length() << endl;
			cout << atoi.StringToInteger() << endl;
			cout << sizeof(atoi.StringToInteger()) << endl;
		}

		atoi.SetString(beTrans);
		if (atoi.IsDigital()) {
			cout << atoi.Length() << endl;
			cout << atoi.StringToInteger() << endl;
			cout << sizeof(atoi.StringToInteger()) << endl;
		}
	}

	return 0;
}
```

## Additional Information
* Hard, need to use multiple program structures or more complex data types.
* Solving time: 30 minutes
* Contributors: SCY
