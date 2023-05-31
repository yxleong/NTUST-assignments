/*****************************************************************//**
 * File: MyException.h
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 30, 2023
 * Update Date: May 31, 2023
 * Description: This C++ program is to implement class MyException which inherited from standard class std::exception.
 *********************************************************************/
#pragma once
#include <exception>
#include <string>

class MyException :public std::exception {
public:
	std::string message;
public:
	MyException(std::string);
};
