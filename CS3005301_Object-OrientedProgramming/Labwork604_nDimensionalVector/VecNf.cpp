/*****************************************************************//**
 * File : VecNf.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 29, 2023
 * Update Date : May 3, 2023
 * Description : This C++ program stores a multidimensional vector and implements some simple vector operations.
 *********************************************************************/
#include "VecNf.h"

 /**
 * Intent : To construct a one-dimensional zero vector in default.
 * Pre : The variable data must be well defined.
 * Post : The function assigns 0 to data.
 */
VecNf::VecNf()
{
	data = { 0.0f };
}

/**
* Intent : To construct a cnt dimensional vector using the first cnt numbers in dest
* Pre : The variables dest,cnt must have a value.
* Post : The function assigns a float array data to float vector data.
* \param dest
* \param cnt
*/
VecNf::VecNf(float* dest, int cnt)
{
	// loop until the count number of dest
	for (int i = 0; i < cnt; i++)
	{
		// insert the element of float array to data vector
		data.push_back(dest[i]);
	}
}

/**
* Intent : To construct a new vector from a VecNf.
* Pre : The object rhs must have a value.
* Post : The function assigns the rhs data to data vector.
* \param rhs
*/
VecNf::VecNf(const VecNf& rhs)
{
	data = rhs.data;
}

/**
* Intent : To assign the rhs data to data vector.
* Pre : The object rhs must have a value.
* Post : The function assigns the rhs data to data vector.
* \param rhs
* \return
*/
VecNf VecNf::operator =(const VecNf& rhs)
{
	// print " ASSIGNMENT!!! " each time calling "="
	std::cout << "ASSIGNMENT!!!" << std::endl;

	// assigns the rhs data to data vector
	data = rhs.data;

	// return the reference to the VecNf
	return *this;
}

/**
* Intent : To return the value of the certain dimension variable in the vector.
* Pre : The variable index must have a value and index > 0.
* Post : The function returns the value of the certain dimension variable in the vector.
* \param index
* \return
*/
float& VecNf::operator [](int index)
{
	return data[index];
}

/**
* Intent : To check if the dimensional of two VecNf are same.
* Pre : The variables count1,count2 must have a value and count1,count2 > 0.
* Post : The function returns the boolean value which indicates if two VecNf have same dimensional.
* \param count1
* \param count2
* \return
*/
bool isEqual(int count1, int count2)
{
	if (count1 != count2)
	{
		std::cout << "dimensions inconsistent" << std::endl;
		return false;
	}
	return true;
}

/**
* Intent : To implement the addition of two vectors.
* Pre : The object rhs must have a value.
* Post : The function returns the sum of two vectors.
* \param rhs
* \return
*/
VecNf VecNf::operator +(const VecNf& rhs)
{
	// check if two VecNf have the same dimensional
	if (isEqual(data.size(), rhs.data.size()))
	{
		VecNf result(*this); // firstly assign the data of vector

		for (int i = 0; i < data.size(); i++)
		{
			// add the corresponding element of data with rhs data
			result.data[i] += rhs.data[i];
		}

		return result;
	}
	else // if two VecNf have different dimensional
	{
		// print "dimensions inconsistent" and return 0
		VecNf result({ 0 }, 1);

		return result;
	}
}

/**
* Intent : To implement the subtraction of two vectors.
* Pre : The object rhs must have a value.
* Post : The function returns the deduction of two vectors.
* \param rhs
* \return
*/
VecNf VecNf::operator -(const VecNf& rhs)
{
	// check if two VecNf have the same dimensional
	if (isEqual(data.size(), rhs.data.size()))
	{
		VecNf result(*this); // firstly assign the data of vector

		for (int i = 0; i < data.size(); i++)
		{
			// subtract the corresponding element of data with rhs data
			result.data[i] -= rhs.data[i];
		}

		return result;
	}
	else // if two VecNf have different dimensional
	{
		// print "dimensions inconsistent" and return 0
		VecNf result({ 0 }, 1);

		return result;
	}
}

/**
* Intent : To implement the inner product of two vectors.
* Pre : The object rhs must have a value.
* Post : The function returns the inner product of two vectors.
* \param rhs
* \return
*/
float VecNf::operator *(const VecNf& rhs)
{
	float result = 0; // if two VecNf have different dimensional
	// will print "dimensions inconsistent" and return 0

	// check if two VecNf have the same dimensional
	if (isEqual(data.size(), rhs.data.size()))
	{
		for (int i = 0; i < data.size(); i++)
		{
			// sum up after multiply the corresponding element of data with rhs data each
			result += data[i] * rhs.data[i];
		}
	}

	return result;
}

/**
* Intent : To implement the scalar multiplication of a floating-point number and a vector.
* Pre : The variable scalar must have a value and scalar > 0.
* Post : The function returns the scalar multiplication of a floating-point number and a vector.
* \param scalar
* \param rhs
* \return
*/
VecNf operator *(float scalar, const VecNf& rhs)
{
	// firstly assign the data of rhs
	VecNf result(rhs);

	for (int i = 0; i < rhs.data.size(); i++)
	{
		// multiply the each data with scalar
		result.data[i] *= scalar;
	}

	return result;
}

/**
* Intent : To get the size of the data vector.
* Pre : The variable data must have a value.
* Post : The function returns the size of a multidimensional vector.
* \return
*/
int VecNf::Size() const
{
	return data.size();
}