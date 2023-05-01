/*****************************************************************//**
 * File : Complex.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 27, 2023
 * Update Date : May 1, 2023
 * Description : This C++ program implements complex numbers calculation.
 *********************************************************************/
#include <algorithm>
#include <string>
#include <sstream>

#include "Complex.h"

 /**
 * Intent : To construct a complex number where both realValue and imaginaryValue are 0.
 * Pre : The variable realValue,imaginaryValue must be well-declared.
 * Post : The function returns a complex number where both realValue and imaginaryValue are 0.
 */
Complex::Complex() :realValue(0), imaginaryValue(0) {}

/**
* Intent : To construct a complex number where the realValue is r and the imaginaryValue is 0.
* Pre : The variable r must have a value.
* Post : The function returns a complex number where the realValue is r and the imaginaryValue is 0.
* \param r
*/
Complex::Complex(double r) : realValue(r), imaginaryValue(0) {}

/**
* Intent : To construct a complex number where the realValue is r and the imaginaryValue is i.
* Pre : The variable r,i must have a value.
* Post : The function returns a complex number where the realValue is r and the imaginaryValue is i.
* \param r
* \param i
*/
Complex::Complex(double r, double i) : realValue(r), imaginaryValue(i) {}

/**
* Intent : To get the realValue of a complex number.
* Pre : The variable realValue must have a value.
* Post : The function returns the realValue of a complex number.
* \return
*/
double Complex::real()
{
	return realValue;
}

/**
* Intent : To get the imaginaryValue of a complex number.
* Pre : The variable imaginaryValue must have a value.
* Post : The function returns the imaginaryValue of a complex number.
* \return
*/
double Complex::imag()
{
	return imaginaryValue;
}

/**
* Intent : To get the Euclidean norm of a complex number.
* Pre : The variable realValue,imaginaryValue must have a value.
* Post : The function returns the Euclidean norm of a complex number.
* \return
*/
double Complex::norm()
{
	// ¡Ì(realValue^2  + imaginaryValue^2)
	return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
}

/**
* Intent : To add another complex number c.
* Pre : The object c must have valid realValue,imaginaryValue.
* Post : The function returns the sum result.
* \param c
* \return
*/
Complex Complex::operator+(Complex c)
{
	// declare a new object result and construct with the added value
	Complex result(realValue + c.realValue, imaginaryValue + c.imaginaryValue);

	// return the calculation result
	return result;
}

/**
* Intent : To minus another complex number c.
* Pre : The object c must have valid realValue,imaginaryValue.
* Post : The function returns the subtraction result.
* \param c
* \return
*/
Complex Complex::operator-(Complex c)
{
	// declare a new object result and construct with the subtracted value
	Complex result(realValue - c.realValue, imaginaryValue - c.imaginaryValue);

	// return the calculation result
	return result;
}

/**
* Intent : To multiply with another complex number c.
* Pre : The object c must have valid realValue,imaginaryValue.
* Post : The function returns the multiplication result.
* \param c
* \return
*/
Complex Complex::operator*(Complex c)
{
	// Formula:
	// (a + b_i)(c + d_i) = a*c + a*d_i + c*b_i + b_i*d_i
	// = (ac - bd) + (ad + bc)_i

	// declare a new object result and construct with the multiplied value
	Complex result(
		realValue * c.realValue - imaginaryValue * c.imaginaryValue,
		realValue * c.imaginaryValue + imaginaryValue * c.realValue
	);

	// return the calculation result
	return result;
}

/**
* Intent : To divide with another complex number c.
* Pre : The object c must have valid realValue,imaginaryValue.
* Post : The function returns the division result.
* \param c
* \return
*/
Complex Complex::operator/(Complex c)
{
	// Formula:
	// (ac + bd) + (bc-ad)_i
	// ----------------------
	//      (c^2 + d^2)

	// declare a variable for c^2 + d^2
	double denominator = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);

	// declare a new object result and construct with the divided value
	Complex result(
		(realValue * c.realValue + imaginaryValue * c.imaginaryValue) / denominator,
		(imaginaryValue * c.realValue - realValue * c.imaginaryValue) / denominator
	);

	// return the calculation result
	return result;
}

/**
* Intent : To add a double type number.
* Pre : The variable d must have a value and object c must have valid realValue,imaginaryValue.
* Post : The function returns the sum result.
* \param d
* \param c
* \return
*/
Complex operator+(double d, Complex c)
{
	// declare a new object result and construct with the added value
	Complex result(c.realValue + d, c.imaginaryValue);

	// return the calculation result
	return result;
}

/**
* Intent : To minus a double type number.
* Pre : The variable d must have a value and object c must have valid realValue,imaginaryValue.
* Post : The function returns the subtraction result.
* \param d
* \param c
* \return
*/
Complex operator-(double d, Complex c)
{
	// declare a new object result and construct with the subtracted value
	Complex result(d - c.realValue, -c.imaginaryValue);

	// return the calculation result
	return result;
}

/**
* Intent : To multiply with a double type number.
* Pre : The variable d must have a value and object c must have valid realValue,imaginaryValue.
* Post : The function returns the multiplication result.
* \param d
* \param c
* \return
*/
Complex operator*(double d, Complex c)
{
	// declare a new object result and construct with the multiplied value
	Complex result(c.realValue * d, c.imaginaryValue * d);

	// return the calculation result
	return result;
}

/**
* Intent : To divide a double type number.
* Pre : The variable d must have a value and object c must have valid realValue,imaginaryValue.
* Post : The function returns the division result.
* \param d
* \param c
* \return
*/
Complex operator/(double d, Complex c)
{
	// Formula:
	// (ac + bd) + (bc-ad)_i
	// ----------------------
	//      (c^2 + d^2)

	// declare a variable for c^2 + d^2
	double denominator = pow(c.realValue, 2) + pow(c.imaginaryValue, 2);

	// declare a new object result and construct with the divided value
	Complex result( // let d as d + 0*i
		(d * c.realValue + 0 * c.imaginaryValue) / denominator,
		(0 * c.realValue - d * c.imaginaryValue) / denominator
	);

	// return the calculation result
	return result;
}

/**
* Intent : To judge if the real and imaginary parts of two complex numbers are equal.
* Pre : The objects c1,c2 must have valid realValue,imaginaryValue.
* Post : The function returns the boolean value which indicates if two complex numbers are equal.
* \param c1
* \param c2
* \return
*/
bool operator==(Complex c1, Complex c2)
{
	// if the real and imaginary parts of two complex numbers are equal, return true
	return c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue;
	// else return false
}

/**
* Intent : To send complex numbers to the output stream.
* Pre : The object c must have valid realValue,imaginaryValue.
* Post : The function returns the complex numbers.
* \param strm
* \param c
* \return
*/
ostream& operator<<(ostream& strm, const Complex& c)
{
	// Format: realValue + imaginaryValue*i
	strm << c.realValue << " + " << c.imaginaryValue << "*i";
	return strm;
}

/**
* Intent : To get the value of a complex number from the input stream.
* Pre : The object c must have valid realValue,imaginaryValue.
* Post : The function returns the value of a complex number from the input stream.
* \param strm
* \param c
* \return
*/
istream& operator>>(istream& strm, Complex& c)
{
	// Format: x = realValue + imaginaryValue*i
	char pass = 0;
	std::string line = "";

	// read the input line by line
	std::getline(strm, line);

	// using string stream to read the line
	std::istringstream iss(line);

	// pass to ignore 'x' and '=' and '+'
	iss >> pass >> pass >> c.realValue >> pass >> c.imaginaryValue;

	return strm;
	// to allow for chaining of input operations
	// std::cin >> c1 >> c2
}
