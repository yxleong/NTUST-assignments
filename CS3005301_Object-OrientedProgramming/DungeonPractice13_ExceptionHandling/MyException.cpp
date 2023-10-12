/*****************************************************************//**
 * File: MyException.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 30, 2023
 * Update Date: May 31, 2023
 * Description: This C++ program is to implement class MyException which inherited from standard class std::exception.
 *********************************************************************/
#include "MyException.h"

 /*****************************************************************//**
 * Intent: To construct the class MyException with given message.
 * Pre: The variable errorMsg must have a value.
 * Post: The function sets the given message.
 * \param errorMsg
 *********************************************************************/
MyException::MyException(std::string errorMsg) : message(errorMsg) {}
