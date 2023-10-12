# Matrix Multiplication

## Problem Statement
Please write a program to calculate matrix multiplication. 

The multiplication rule of the matrix is as follows: given two matrices A and B, the number of columns of matrix A must be equal to the number of rows of matrix B.

## Input
1. The first line is the size of matrices A and B in row major order.
2. The second line is the elements of matrix A.
3. The third line is the elements of matrix B.
```
3 2 2 3
1 2 3 4 5 6
6 5 4 3 2 1
```

## Output
Output the matrix obtained by multiplying matrices A and B. If A and B cannot be multiplied, please print "**Matrix multiplication failed.**"
```
12 9 6
30 23 16
48 37 26
```

## Note
main.cpp
```cpp
int main()
{
	Polynomial empty;
	double one[] = { 1 };
	Polynomial One(one, 1);
	double quad[] = { 3, 2, 1 };
	double cubic[] = { 1, 2, 0, 3 };
	Polynomial q(quad, 3); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
	Polynomial p = q;  // test copy constructor
	Polynomial r;
	r = q;             //test operator=
	r = c;

	cout << "Polynomial q " << endl;
	for (int i = 0; i < 3; i++)
		cout << "term with degree " << i << " has coefficient " << q[i] << endl;

	cout << "Polynomial c " << endl;
	for (int i = 0; i < 4; i++)
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;

	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;

	r = q + c;
	cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;

	r = q - c;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;

	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;
	cout << "Polynomial r (= q*c) " << endl;

	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
	return 0;
}
```

## Additional Information
* Easy, only basic programming syntax and structure are required.
* Solving time: 20 minutes
* Contributors: 林宇恩, 溫勇威, 鍾賢廣