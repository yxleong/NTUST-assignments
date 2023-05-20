# Design Polynomial Class

## Problem Statement
Please implement a class called `Polynomial` to handle one-dimensional polynomials. This class needs to be able to store the coefficients and implement operations such as **addition**, **subtraction**, **multiplication**, and **assignment**.

An example of a polynomial of a single variable, x, is `x^3 + 3x^2 + 7x + 8`, which can be expressed with a set of coefficients like {8, 7, 3, 1}.

Please design your own data structure to store these polynomials and implement the following methods:

- `Polynomial()`: Construct a zero polynomial.
- `Polynomial(double* param, int size)`: Construct a one-dimensional polynomial based on the given coefficients which have the given size.
- `Polynomial(const Polynomial& poly)`: Copy constructor.

Suppose there were three polynomials: `poly1(3x + 9)`, `poly2(0x^3 + 5x^2 + 6x + 8)`, and `poly()`.

- `int mySize()`: Return the number of terms of the polynomial.
- `double evaluate(const Polynomial& poly, const double& var)`: Return the value of the polynomial after substituting `var` into the variables.

Overload operators to meet the following operational requirements:

- **Assignment**: Assign the value from a polynomial to another polynomial. (define operator `=`)
- Return the coefficient of the certain power variable in the polynomial. (define operator `[]`)
- **Addition**: Implement the addition of two polynomials or a polynomial and a constant number. (define operator `+`)
- **Subtraction**: Implement the subtraction of two polynomials or a polynomial and a constant number. (define operator `-`)
- **Multiplication**: Implement the multiplication of two polynomials or a polynomial and a constant number. (define operator `*`)

## Input
No input.

## Output
```
Polynomial q 
term with degree 0 has coefficient 3
term with degree 1 has coefficient 2
term with degree 2 has coefficient 1
Polynomial c 
term with degree 0 has coefficient 1
term with degree 1 has coefficient 2
term with degree 2 has coefficient 0
term with degree 3 has coefficient 3
value of q(2) is 11
value of p(2) is 11
value of r(2) is 29
value of c(2) is 29
value of (q + c)(2) is 40
value of (q - c)(2) is -18
size of q*c is 6
Polynomial r (= q*c) 
term with degree 0 has coefficient 3
term with degree 1 has coefficient 8
term with degree 2 has coefficient 5
term with degree 3 has coefficient 11
term with degree 4 has coefficient 6
term with degree 5 has coefficient 3
value of (q * c)(2) is 319
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
* Medium, multiple programming grammars and structures are required.
* Solving time: 40 minutes
* Contributors: 謝公耀, 陳俊儒, 廖宣瑋
* Editor : 葉定豪