/*****************************************************************//**
 * File : Complex.h
 * Author : Leong Yah Xuan
 * Create Date : April 27, 2023
 * Update Date : May 1, 2023
 * Description : This C++ program implements complex numbers calculation.
 *********************************************************************/
#include <iostream>

using namespace std;

class Complex
{
public:
	double realValue, imaginaryValue;

	Complex();
	//~Complex();
	Complex(double r);
	//~Complex(double r);
	Complex(double r, double i);
	//~Complex(double r, double i);
	double real();
	double imag();
	double norm();
	friend double real(Complex c);
	friend double imag(Complex c);
	friend double norm(Complex c);
	Complex operator+(Complex c);
	Complex operator-(Complex c);
	Complex operator*(Complex c);
	Complex operator/(Complex c);
	friend Complex operator+(double d, Complex c);
	friend Complex operator-(double d, Complex c);
	friend Complex operator*(double d, Complex c);
	friend Complex operator/(double d, Complex c);
	friend bool operator==(Complex c1, Complex c2);
	friend ostream& operator<<(ostream& strm, const Complex& c);
	friend istream& operator>>(istream& strm, Complex& c);
};

/**
* Intent : To get the realValue of a complex number 'c'.
* Pre : The object 'c' must have valid realValue,imaginaryValue.
* Post : The function returns the realValue of a complex number 'c'.
* \param c
* \return
*/
inline double real(Complex c)
{
	// inline: replace calls to the function with the actual code of the function itself
	// is to reduce the overhead of function calls
	return c.realValue;
}

/**
* Intent : To get the imaginaryValue of a complex number 'c'.
* Pre : The object 'c' must have valid realValue,imaginaryValue.
* Post : The function returns the imaginaryValue of a complex number 'c'.
* \param c
* \return
*/
inline double imag(Complex c)
{
	return c.imaginaryValue;
}

/**
* Intent : To get the Euclidean norm of a complex number 'c'.
* Pre : The object 'c' must have valid realValue,imaginaryValue.
* Post : The function returns the Euclidean norm of a complex number 'c'.
* \param c
* \return
*/
inline double norm(Complex c)
{
	return sqrt(pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
}