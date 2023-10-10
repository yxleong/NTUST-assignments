/*****************************************************************//**
 * File: File.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 19, 2023
 * Update Date: May 20, 2023
 * Description: This C++ program is to define a class for File that is derived from Document.
 *********************************************************************/
#include "File.h"

 /*****************************************************************//**
 * Intent: To initialize a File object with an empty pathname.
 * Pre: The variable pathname must be well-declared.
 * Post: The function initializes a File object with an empty pathname.
 *********************************************************************/
File::File() : pathname("") {}

/*****************************************************************//**
 * Intent: To initialize a File object with a body and a pathname.
 * Pre: The variables body,pathname must have value.
 * Post: The function initializes a File object with the provided body and pathname.
 * \param body
 * \param pathname
 *********************************************************************/
File::File(const std::string& body, const std::string& pathname) : pathname(pathname)
{
	setText(body);
}

/*****************************************************************//**
 * Intent: To set the pathname of the File object to the provided value.
 * Pre: The variable newPathname must have value.
 * Post: The function updates the pathname of the File object with the provided value.
 * \param newPathname
 *********************************************************************/
void File::setPathname(const std::string& newPathname)
{
	pathname = newPathname;
}

/*****************************************************************//**
 * Intent: To retrieve the pathname of the File object.
 * Pre: The variable pathname must be well-declared.
 * Post: The function returns the current pathname of the File object.
 * \return
 *********************************************************************/
std::string File::getPathname() const
{
	return pathname;
}

/*****************************************************************//**
 * Intent: To assign the values of another File object to the current object.
 * Pre: The object other must be valid.
 * Post: The function returns a reference to the current object.
 * \param other
 * \return
 *********************************************************************/
File& File::operator=(const File& other)
{
	// if same direct return
	if (this != &other) {
		setText(other.getText());
		pathname = other.pathname;
	}

	return *this;
}
